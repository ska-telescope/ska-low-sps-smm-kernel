ifeq ($(CONFIG_VIDEO_MXC_IPU_CAMERA),y)
	obj-$(CONFIG_VIDEO_MXC_CAPTURE) += mxc_v4l2_capture.o
	obj-$(CONFIG_MXC_IPU_PRP_VF_SDC) += ipu_prp_vf_sdc.o ipu_prp_vf_sdc_bg.o
	obj-$(CONFIG_MXC_IPU_DEVICE_QUEUE_SDC) += ipu_fg_overlay_sdc.o ipu_bg_overlay_sdc.o
	obj-$(CONFIG_MXC_IPU_PRP_ENC) += ipu_prp_enc.o ipu_still.o
	obj-$(CONFIG_MXC_IPU_CSI_ENC) += ipu_csi_enc.o ipu_still.o
endif

obj-$(CONFIG_VIDEO_V4L2_MXC_INT_DEVICE) += v4l2-int-device.o

sanitas_mxc_v4l2_csi-objs := sanitas__mxc_v4l2_csi.o
obj-$(CONFIG_SANITAS_MXC_V4L2_CSI) += sanitas_mxc_v4l2_csi.o

sanitas_mxc_v4l2_mipi-objs := sanitas__mxc_v4l2_mipi.o
obj-$(CONFIG_SANITAS_MXC_V4L2_MIPI) += sanitas_mxc_v4l2_mipi.o

#ccflags-y := -std=gnu99 -Wno-declaration-after-statement # To suppress all those annoying C90 forbids bla bla... 
sanitas_cmv4000_sensor-objs := register_map.o sanitas__cmv4000_sensor.o
sanitas_cmv4000_frontend-objs := register_map.o sanitas__cmv4000_frontend.o
obj-$(CONFIG_SANITAS_CMV4000) += sanitas_cmv4000_sensor.o sanitas_cmv4000_frontend.o

sanitas_mt9p031_sensor-objs := register_map.o sanitas__mt9p031_sensor.o
sanitas_mt9p031_frontend-objs := register_map.o sanitas__mt9p031_frontend.o
obj-$(CONFIG_SANITAS_MT9P031) += sanitas_mt9p031_sensor.o sanitas_mt9p031_frontend.o

#ccflags-y := -std=gnu99 -Wno-declaration-after-statement # To suppress all those annoying C90 forbids bla bla... 
sanitas_inventami_colorbar-objs := register_map.o sanitas__inventami_colorbar.o
obj-$(CONFIG_SANITAS_INVENTAMI_COLORBAR) += sanitas_inventami_colorbar.o

#ccflags-y := -std=gnu99 -Wno-declaration-after-statement # To suppress all those annoying C90 forbids bla bla...
sanitas_inventami_video_ch-objs := register_map.o sanitas__inventami_video_ch.o
obj-$(CONFIG_SANITAS_INVENTAMI_VIDEO_CH) += sanitas_inventami_video_ch.o

#ccflags-y := -std=gnu99 -Wno-declaration-after-statement # To suppress all those annoying C90 forbids bla bla...
sanitas_inventami_video_out-objs := register_map.o sanitas__inventami_video_out.o
obj-$(CONFIG_SANITAS_INVENTAMI_VIDEO_OUT) += sanitas_inventami_video_out.o

#CFLAGS_mxc_v4l2_capture.o := -DDEBUG
#CFLAGS_v4l2-int-device.o := -DDEBUG
#CFLAGS_ipu_csi_enc.o := -DDEBUG
#CFLAGS_sanitas__inventami_csi.o := -DDEBUG
#CFLAGS_sanitas__inventami_mipi.o := -DDEBUG