/*
 * Copyright (C) 2014-2015 Santas EG srl. All Rights Reserved.
 */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/* DATE       | AUTHOR       | COMMENT
 * -----------|--------------|------------------------------------------
 * 2015/01/23 | Davide Rizzi | Started
 */
  
#include <linux/clk.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/pinctrl/consumer.h>
#include <linux/regulator/consumer.h>
#include <media/v4l2-chip-ident.h>

#include <linux/mipi_csi2.h>
#include "v4l2-int-device.h"
#include "mxc_v4l2_capture.h"

#if 1
#include <linux/of_platform.h>
#include <linux/dma-mapping.h>
#include <linux/miscdevice.h>
#include <linux/interrupt.h>
#include <linux/dmaengine.h>
#include <linux/seq_file.h>
#include <linux/highmem.h>
#include <linux/debugfs.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/poll.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/kref.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/clk.h>
#include <linux/io.h>
#include <linux/of_device.h>
#include <linux/sysfs.h>
#include <linux/stat.h>
#endif

#define DRIVER_NAME "sanitas_mxc_v4l2_mipi"
#define DEFAULT_FPS 30

static const char* decodeFourCC(int fourcc) {
	switch(fourcc) {
		case V4L2_PIX_FMT_UYVY:   return "UYVY"; break;
		case V4L2_PIX_FMT_YUYV:   return "YUYV"; break;
		case V4L2_PIX_FMT_RGB565: return "RGBP"; break;
		case V4L2_PIX_FMT_Y16:    return "Y16 "; break;
		case V4L2_PIX_FMT_GREY:   return "GRAY"; break;
		default: return "----";
	}
}

struct sanitas_mxc_v4l2_mipi_data
{
	struct device *dev;
	struct v4l2_int_device *v4l2_int_device;
	struct sensor_data sensor;

	spinlock_t lock;
};

/* list of supported image formats */
static const struct v4l2_fmtdesc sanitas_mxc_v4l2_mipi_formats[] = {
	{
		.description = "YUYV (YUV 4:2:2), packed",
		.pixelformat = V4L2_PIX_FMT_YUYV,
	},
	{
		.description = "UYVY (YUV 4:2:2), packed",
		.pixelformat = V4L2_PIX_FMT_UYVY,
	},{
		.description = "Grayscale, 16bpp",
		.pixelformat = V4L2_PIX_FMT_Y16,
	},
	{
		.description = "RGB, 565",
		.pixelformat = V4L2_PIX_FMT_RGB565,
	},
	{
		.description = "Grayscale, 8bpp",
		.pixelformat = V4L2_PIX_FMT_GREY,
	},
};

#define SANITAS_MXC_V4L2_MIPI_NUM_CAPTURE_FORMATS	ARRAY_SIZE(sanitas_mxc_v4l2_mipi_formats)

static int sanitas_mxc_v4l2_mipi_configure(struct v4l2_int_device *s)
{
	struct sensor_data *sensor = s->priv;
	struct platform_device* pdev = sensor->platform_data;
	struct v4l2_pix_format *pix = &sensor->pix;
	struct v4l2_fract *fper = &sensor->streamcap.timeperframe;

	void *mipi_csi2_info;
	u32 mipi_reg;

	mipi_csi2_info = mipi_csi2_get_info();

	if (!mipi_csi2_info) {
		dev_err(&pdev->dev, "fail to get mipi_csi2_info\n");
		return -1;
	}

	if (!mipi_csi2_get_status(mipi_csi2_info))
		mipi_csi2_enable(mipi_csi2_info);

	if (!mipi_csi2_get_status(mipi_csi2_info)) {
		dev_err(&pdev->dev, "can not enable mipi csi2 driver\n");
		return -1;
	}

	mipi_csi2_set_lanes(mipi_csi2_info);

	/*Only reset MIPI CSI2 HW at sensor initialize*/
	mipi_csi2_reset(mipi_csi2_info);

	if (sensor->pix.pixelformat == V4L2_PIX_FMT_UYVY)
		mipi_csi2_set_datatype(mipi_csi2_info, MIPI_DT_YUV422);
	else if (sensor->pix.pixelformat == V4L2_PIX_FMT_YUYV)
		mipi_csi2_set_datatype(mipi_csi2_info, MIPI_DT_YUV422);
	else if (sensor->pix.pixelformat == V4L2_PIX_FMT_RGB565)
		mipi_csi2_set_datatype(mipi_csi2_info, MIPI_DT_RGB565);
	else if (sensor->pix.pixelformat == V4L2_PIX_FMT_GREY)
		mipi_csi2_set_datatype(mipi_csi2_info, MIPI_DT_RAW8);
	else if (sensor->pix.pixelformat == V4L2_PIX_FMT_Y16)
		mipi_csi2_set_datatype(mipi_csi2_info, MIPI_DT_YUV422); // DAVIDE: Occhio! MIPI_DT_RAW10
	else
		dev_err(&pdev->dev, "currently this sensor format can not be supported\n");

	dev_info(&pdev->dev, "MIPI DataType: %02X\n", mipi_csi2_get_datatype(mipi_csi2_info));

	if (mipi_csi2_info) {
		unsigned int i;

		i = 0;

		/* wait for mipi sensor ready */
		mipi_reg = mipi_csi2_dphy_status(mipi_csi2_info);
		while ((mipi_reg == 0x200) && (i < 10)) {
			mipi_reg = mipi_csi2_dphy_status(mipi_csi2_info);
			i++;
			msleep(10);
		}

		if (i >= 10) {
			dev_err(&pdev->dev, "mipi csi2 can not receive sensor clk. HOLY CRAP!\n");
			return -1;
		}

		i = 0;

		/* wait for mipi stable */
		mipi_reg = mipi_csi2_get_error1(mipi_csi2_info);
		while ((mipi_reg != 0x0) && (i < 10)) {
			mipi_reg = mipi_csi2_get_error1(mipi_csi2_info);
			i++;
			msleep(10);
		}

		if (i >= 10) {
			dev_err(&pdev->dev, "mipi csi2 can not reveive data correctly\n");
			return -1;
		}
	}

	return 0;
}

/* --------------- IOCTL functions from v4l2_int_ioctl_desc --------------- */

static int ioctl_g_ifparm(struct v4l2_int_device *s, struct v4l2_ifparm *p)
{
	struct sensor_data *sensor = s->priv;
	struct platform_device* pdev = sensor->platform_data;

	dev_info(&pdev->dev, "ioctl_g_ifparm\n");

	if (s == NULL) {
		dev_err(&pdev->dev,"ioctl_g_ifparm: no slave device set\n");
		return -1;
	}

	memset(p, 0, sizeof(*p));
	p->u.bt656.clock_curr = 500*1000*1000; // IPU_CSI_CLK_MODE_GATED_CLK
	p->if_type = V4L2_IF_TYPE_BT656;
	p->u.bt656.mode = V4L2_IF_TYPE_BT656_MODE_NOBT_8BIT;
	p->u.bt656.clock_min = 0;
	p->u.bt656.clock_max = 0;
	p->u.bt656.bt_sync_correct = 1;  /* Indicate external vsync */
	p->u.bt656.latch_clk_inv = 0;

	return 0;
}

static int ioctl_s_power(struct v4l2_int_device *s, int on)
{
	struct sensor_data *sensor = s->priv;
	struct platform_device* pdev = sensor->platform_data;

	dev_info(&pdev->dev, "ioctl_s_power: %d\n", on);

	sensor->on = on;

	return 0;
}

static int ioctl_g_parm(struct v4l2_int_device *s, struct v4l2_streamparm *a)
{
	struct sensor_data *sensor = s->priv;
	struct platform_device* pdev = sensor->platform_data;
	struct v4l2_captureparm *cparm = &a->parm.capture;
	int ret = 0;

	dev_info(&pdev->dev, "ioctl_g_parm\n");

	switch (a->type) {
		case V4L2_BUF_TYPE_VIDEO_CAPTURE:
			memset(a, 0, sizeof(*a));
			a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

			cparm->capability = sensor->streamcap.capability;
			cparm->timeperframe = sensor->streamcap.timeperframe;
			cparm->capturemode = sensor->streamcap.capturemode;

			ret = 0;
			break;

		default:
			dev_err(&pdev->dev, "ioctl_s_parm: type is not V4L2_BUF_TYPE_VIDEO_CAPTURE but %d\n", a->type);
			ret = -EINVAL;
			break;
	}

	return ret;
}

static int ioctl_s_parm(struct v4l2_int_device *s, struct v4l2_streamparm *a)
{
	struct sensor_data *sensor = s->priv;
	struct platform_device* pdev = sensor->platform_data;
	struct v4l2_fract *timeperframe = &a->parm.capture.timeperframe;
	
	u32 tgt_fps;

	int ret = 0;

	dev_info(&pdev->dev, "ioctl_s_parm\n");

	switch (a->type) {
		case V4L2_BUF_TYPE_VIDEO_CAPTURE:
			if ((timeperframe->numerator == 0) || (timeperframe->denominator == 0)) {
				timeperframe->denominator = DEFAULT_FPS;
				timeperframe->numerator = 1;
			}

			tgt_fps = timeperframe->denominator / timeperframe->numerator;

			sensor->streamcap.timeperframe = *timeperframe;
			sensor->streamcap.capturemode =	(u32)a->parm.capture.capturemode;

			ret = 0;
			break;

		default:
			dev_err(&pdev->dev, "ioctl_s_parm: type is not V4L2_BUF_TYPE_VIDEO_CAPTURE but %d\n", a->type);
			ret = -EINVAL;
			break;
	}

	return ret;
}

static int ioctl_g_ctrl(struct v4l2_int_device *s, struct v4l2_control *vc)
{
	return -EINVAL;
}

static int ioctl_s_ctrl(struct v4l2_int_device *s, struct v4l2_control *vc)
{
	return -EINVAL;
}

static int ioctl_enum_framesizes(struct v4l2_int_device *s, struct v4l2_frmsizeenum *fsize)
{
	struct sensor_data *sensor = s->priv;
	struct platform_device* pdev = sensor->platform_data;

	dev_info(&pdev->dev, "ioctl_enum_framesizes\n");

	if (fsize->index > 0) {
		dev_err(&pdev->dev, "ioctl_enum_framesizes: wrong mode index %d\n",  fsize->index);
		return -EINVAL;
	}

	if ((fsize->pixel_format == V4L2_PIX_FMT_Y16) || (fsize->pixel_format == V4L2_PIX_FMT_YUYV) || (fsize->pixel_format == V4L2_PIX_FMT_UYVY) || (fsize->pixel_format == V4L2_PIX_FMT_RGB565) || (fsize->pixel_format == V4L2_PIX_FMT_GREY)) {

		fsize->type = V4L2_FRMSIZE_TYPE_STEPWISE;

		fsize->stepwise.min_width = 8;
		fsize->stepwise.max_width = 8192;
		fsize->stepwise.step_width = 8;

		fsize->stepwise.min_height = 8;
		fsize->stepwise.max_height = 8192;
		fsize->stepwise.step_height = 8;
	} else {
		dev_err(&pdev->dev, "ioctl_enum_framesizes: wrong pixel format %08x\n",  fsize->pixel_format);
		return -EINVAL;
	}

	return 0;
}

static int ioctl_init(struct v4l2_int_device *s)
{
	struct sensor_data *sensor = s->priv;
	struct platform_device* pdev = sensor->platform_data;

	dev_info(&pdev->dev, "ioctl_init\n");

	return 0;
}

static int ioctl_try_fmt_cap(struct v4l2_int_device *s,
			     struct v4l2_format *f)
{
	struct sensor_data *sensor = s->priv;
	struct platform_device* pdev = sensor->platform_data;
	struct v4l2_pix_format *pix = &f->fmt.pix;
	int ifmt;
	u32 tmp;

	dev_info(&pdev->dev, "ioctl_try_fmt_cap: %d x %d, %s\n", pix->width, pix->height, decodeFourCC(pix->pixelformat));

	pix->priv = 0;

	tmp = pix->width;
	tmp = tmp > 8192 ? 8192 : (tmp < 8 ? 8 : tmp + tmp % 8);
	pix->width = tmp;

	tmp = pix->height;
	tmp = tmp > 8192 ? 8192 : (tmp < 8 ? 8 : tmp + tmp % 8);
	pix->height = tmp;

	for (ifmt = 0; ifmt < SANITAS_MXC_V4L2_MIPI_NUM_CAPTURE_FORMATS; ifmt++) {
		if (pix->pixelformat == sanitas_mxc_v4l2_mipi_formats[ifmt].pixelformat) {
			break;
		}
	}

	if (ifmt == SANITAS_MXC_V4L2_MIPI_NUM_CAPTURE_FORMATS) {
		dev_err(&pdev->dev, "ioctl_try_fmt_cap: format %s not found, fallback is %s. Continuing...\n", decodeFourCC(pix->pixelformat), decodeFourCC(0));
		ifmt = 0;
	}

	pix->pixelformat = sanitas_mxc_v4l2_mipi_formats[ifmt].pixelformat;

	switch(pix->pixelformat) {
		case V4L2_PIX_FMT_Y16:
			pix->bytesperline = pix->width * 2;
			break;
		case V4L2_PIX_FMT_YUYV:
		case V4L2_PIX_FMT_UYVY:
			pix->bytesperline = pix->width * 2;
			break;
		case V4L2_PIX_FMT_RGB565:
			pix->bytesperline = pix->width * 2;
			break;
		case V4L2_PIX_FMT_GREY:
			pix->bytesperline = pix->width * 1;
			break;
		default:
			break;
			return -EINVAL;
	}

	pix->sizeimage = pix->bytesperline * pix->height;
	pix->priv = 0;

    // Is this needed? DAVIDE
	switch (pix->pixelformat) {
		case V4L2_PIX_FMT_Y16:
		case V4L2_PIX_FMT_UYVY:
		case V4L2_PIX_FMT_YUYV:
		case V4L2_PIX_FMT_GREY:
		default:
			pix->colorspace = V4L2_COLORSPACE_JPEG;
			break;
		case V4L2_PIX_FMT_RGB565:
			pix->colorspace = V4L2_COLORSPACE_SRGB;
			break;
	}

	return 0;
}

static int ioctl_s_fmt_cap(struct v4l2_int_device *s,
				struct v4l2_format *f)
{
	struct sensor_data *sensor = s->priv;
	struct platform_device* pdev = sensor->platform_data;
	struct v4l2_pix_format *pix = &f->fmt.pix;
	int rval;

	dev_info(&pdev->dev, "ioctl_s_fmt_cap: %d x %d, %s\n", sensor->pix.width, sensor->pix.height, decodeFourCC(sensor->pix.pixelformat));

	rval = ioctl_try_fmt_cap(s, f);
	if (rval)
		return rval;

	sensor->pix = *pix;

	rval = sanitas_mxc_v4l2_mipi_configure(s);


	return rval;

}

static int ioctl_g_fmt_cap(struct v4l2_int_device *s, struct v4l2_format *f)
{
	struct sensor_data *sensor = s->priv;
	struct platform_device* pdev = sensor->platform_data;

	dev_info(&pdev->dev, "ioctl_g_fmt_cap: %d x %d, %s\n", sensor->pix.width, sensor->pix.height, decodeFourCC(sensor->pix.pixelformat));

	f->fmt.pix = sensor->pix;

	return 0;
}

static int ioctl_enum_fmt_cap(struct v4l2_int_device *s,
			      struct v4l2_fmtdesc *fmt)
{
	struct sensor_data *sensor = s->priv;
	struct platform_device* pdev = sensor->platform_data;

	int index = fmt->index;

	dev_info(&pdev->dev, "ioctl_enum_fmt_cap: index %d not allowed\n", index);

	switch (fmt->type) {
		case V4L2_BUF_TYPE_VIDEO_CAPTURE:
			break;
		default:
			return -EINVAL;
	}

	if (index >= SANITAS_MXC_V4L2_MIPI_NUM_CAPTURE_FORMATS) {
		dev_err(&pdev->dev, "ioctl_enum_fmt_cap: index %d not allowed\n", index);
		return -EINVAL;
	}

	fmt->flags = sanitas_mxc_v4l2_mipi_formats[index].flags;
	strlcpy(fmt->description, sanitas_mxc_v4l2_mipi_formats[index].description,	sizeof(fmt->description));
	fmt->pixelformat = sanitas_mxc_v4l2_mipi_formats[index].pixelformat;

	return 0;
}

static int ioctl_dev_init(struct v4l2_int_device *s)
{
	struct sensor_data *sensor = s->priv;
	struct platform_device* pdev = sensor->platform_data;
	void *mipi_csi2_info;

	sensor->on = true;

	mipi_csi2_info = mipi_csi2_get_info();

	/* enable mipi csi2 */
	if (mipi_csi2_info)
		mipi_csi2_enable(mipi_csi2_info);
	else {
		dev_info(&pdev->dev, "ioctl_dev_init: fail to get mipi_csi2_info\n");
		return -EPERM;
	}
	
	dev_info(&pdev->dev, "ioctl_dev_init\n");

	return 0;
}

static int ioctl_dev_exit(struct v4l2_int_device *s)
{
	struct sensor_data *sensor = s->priv;
	struct platform_device* pdev = sensor->platform_data;
	void *mipi_csi2_info;

	mipi_csi2_info = mipi_csi2_get_info();

	/* disable mipi csi2 */
	if (mipi_csi2_info)
		if (mipi_csi2_get_status(mipi_csi2_info))
			mipi_csi2_disable(mipi_csi2_info);

	dev_info(&pdev->dev, "ioctl_dev_exit\n");

	return 0;
}



static inline void sanitas_mxc_v4l2_mipi_reset(void)
{}

/*!
 * This structure defines all the ioctls for this module and links them to the
 * enumeration.
 */
static struct v4l2_int_ioctl_desc sanitas_mxc_v4l2_mipi_ioctl_desc[] = {
	{ vidioc_int_dev_init_num, (v4l2_int_ioctl_func *)ioctl_dev_init },
	{ vidioc_int_dev_exit_num, (v4l2_int_ioctl_func *)ioctl_dev_exit },

	{ vidioc_int_s_power_num, (v4l2_int_ioctl_func *)ioctl_s_power },
	{ vidioc_int_g_ifparm_num, (v4l2_int_ioctl_func *)ioctl_g_ifparm },
	{ vidioc_int_init_num, (v4l2_int_ioctl_func *)ioctl_init },

	{ vidioc_int_enum_fmt_cap_num, (v4l2_int_ioctl_func *)ioctl_enum_fmt_cap },
	{ vidioc_int_try_fmt_cap_num,  (v4l2_int_ioctl_func *)ioctl_try_fmt_cap },
	{ vidioc_int_g_fmt_cap_num, (v4l2_int_ioctl_func *)ioctl_g_fmt_cap },
	{ vidioc_int_s_fmt_cap_num, (v4l2_int_ioctl_func *)ioctl_s_fmt_cap },

	{ vidioc_int_g_parm_num, (v4l2_int_ioctl_func *)ioctl_g_parm },
	{ vidioc_int_s_parm_num, (v4l2_int_ioctl_func *)ioctl_s_parm },

	{ vidioc_int_g_ctrl_num, (v4l2_int_ioctl_func *)ioctl_g_ctrl },
	{ vidioc_int_s_ctrl_num, (v4l2_int_ioctl_func *)ioctl_s_ctrl },

	{ vidioc_int_enum_framesizes_num, (v4l2_int_ioctl_func *)ioctl_enum_framesizes },
};

static struct v4l2_int_slave sanitas_mxc_v4l2_mipi_slave = {
	.ioctls = sanitas_mxc_v4l2_mipi_ioctl_desc,
	.num_ioctls = ARRAY_SIZE(sanitas_mxc_v4l2_mipi_ioctl_desc),
};

static struct v4l2_int_device sanitas_mxc_v4l2_mipi_int_device = {
	.module = THIS_MODULE,
	.name = "sanitas_mxc_v4l2_mipi",
	.type = v4l2_int_type_slave,
	.u = {
		.slave = &sanitas_mxc_v4l2_mipi_slave,
	},
};

static int sanitas_mxc_v4l2_mipi_probe(
		struct platform_device* pdev)
{
	struct sanitas_mxc_v4l2_mipi_data *data;
	int ret = -EINVAL;

	struct device_node* np = pdev->dev.of_node;

	data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
	if (!data) {
		ret = -ENOMEM;
		goto out_error;
	}
	platform_set_drvdata(pdev, data);

	pr_info("sanitas_mxc_v4l2_mipi_probe\n");

	/* Set initial values for the sensor struct. */
	memset(&data->sensor, 0, sizeof(struct sensor_data));

	ret = of_property_read_u32(np, "csi_id", &(data->sensor.csi));
	if (ret) {
		dev_err(&pdev->dev, "csi id missing or invalid\n");
		goto out_error;
	}

	data->sensor.io_init = sanitas_mxc_v4l2_mipi_reset;
	data->sensor.platform_data = pdev;

	data->sensor.pix.pixelformat = V4L2_PIX_FMT_GREY;
	data->sensor.pix.width = 1920;
	data->sensor.pix.height = 1080;

	data->sensor.streamcap.capability = V4L2_MODE_HIGHQUALITY | V4L2_CAP_TIMEPERFRAME;
	data->sensor.streamcap.capturemode = 0;
	data->sensor.streamcap.timeperframe.denominator = DEFAULT_FPS;
	data->sensor.streamcap.timeperframe.numerator = 1;

	data->v4l2_int_device = &sanitas_mxc_v4l2_mipi_int_device;
	data->v4l2_int_device->priv = &data->sensor;

	ret = v4l2_int_device_register(data->v4l2_int_device);

	dev_info(&pdev->dev, "driver registered.\n");

	return 0;

out_error:
	return ret;
}

static int sanitas_mxc_v4l2_mipi_remove(
		struct platform_device* pdev)
{
	struct sanitas_mxc_v4l2_mipi_data *data = dev_get_drvdata(&pdev->dev);

	v4l2_int_device_unregister(data->v4l2_int_device);

	dev_info(&pdev->dev, "driver removed.\n");

	return 0;
}

static const struct of_device_id sanitas_mxc_v4l2_mipi_id_table[] = {
		{ .compatible = "sanitas,sanitas_mxc_v4l2_mipi", },
		{ }
};
MODULE_DEVICE_TABLE(of, sanitas_mxc_v4l2_mipi_id_table);

static struct platform_driver sanitas_mxc_v4l2_mipi_driver = {
		.probe = sanitas_mxc_v4l2_mipi_probe,
		.remove = sanitas_mxc_v4l2_mipi_remove,
		.driver = {
				.name = DRIVER_NAME,
				.of_match_table = sanitas_mxc_v4l2_mipi_id_table,
				.owner = THIS_MODULE,
		},
};

module_platform_driver(sanitas_mxc_v4l2_mipi_driver);

MODULE_AUTHOR("Sanitas EG srl");
MODULE_DESCRIPTION("Sanitas V4L2 MIPI Parallel Port Camera Driver for Inventami");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");
MODULE_ALIAS("platform:" DRIVER_NAME);

