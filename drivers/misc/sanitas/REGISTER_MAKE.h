#ifndef __KERNEL__
#include <limits>

#ifdef min
  #undef min
#endif

#ifdef max
  #undef max
#endif
#endif

#if defined(REGISTER_MODE_READ) && defined(REGISTER_MODE_WRITE)
	#define REGISTER_ATTR_MODE REGISTERFLAG_READ | REGISTERFLAG_WRITE
	#define REGISTER_SYSFS_MODE (S_IRUSR|S_IRGRP|S_IROTH) | S_IWUSR
	#define REGISTER_SYSFS_SHOW showRegister
	#define REGISTER_SYSFS_STORE storeRegister
#elif defined(REGISTER_MODE_READ)
	#define REGISTER_ATTR_MODE REGISTERFLAG_READ
	#define REGISTER_SYSFS_MODE (S_IRUSR|S_IRGRP|S_IROTH)
	#define REGISTER_SYSFS_SHOW showRegister
	#define REGISTER_SYSFS_STORE NULL
#elif defined(REGISTER_MODE_WRITE)
	#define REGISTER_ATTR_MODE REGISTERFLAG_WRITE
	#define REGISTER_SYSFS_MODE S_IWUSR
	#define REGISTER_SYSFS_SHOW NULL
	#define REGISTER_SYSFS_STORE storeRegister
#else
	#error REGISTER_MODE is undefined
#endif
 
#if defined(REGISTER_INIT)
	#define REGISTER_ATTR_INIT_VALUE REGISTER_INIT 
	#define REGISTER_ATTR_INIT REGISTERFLAG_INITIALIZE
#else
	#define REGISTER_ATTR_INIT_VALUE 0x00
	#define REGISTER_ATTR_INIT REGISTERFLAG_NONE
#endif

#if defined(REGISTER_NAME)
	#define REGISTER_REG_NAME(__name__) REGISTER_NAME
#else
  #ifndef REGISTER_REG_NAME
	#define REGISTER_REG_NAME(__name__) register_ ## __name__
#endif
#endif

#ifndef REGISTER_ATTR_NAME
	#define REGISTER_ATTR_NAME(__name__) register_dev_attr_##__name__
#endif

#if defined(REGISTER_LABEL)
	#define REGISTER_SYSFS_NAME(__name__) REGISTER_LABEL
#else
	#define REGISTER_SYSFS_NAME(__name__) #__name__
#endif

#if defined(REGISTER_DESCRIPTION)
  #define REGISTER_REG_DESCRIPTION REGISTER_DESCRIPTION
#else
  #define REGISTER_REG_DESCRIPTION ""
#endif

#if defined(REGISTER_HIDE)
  #define REGISTER_ATTR_VISIBILITY REGISTERFLAG_VISIBILITY_HIDE
#elif defined(REGISTER_ADVANCED)
  #define REGISTER_ATTR_VISIBILITY REGISTERFLAG_VISIBILITY_ADVANCED
#else
  #define REGISTER_ATTR_VISIBILITY REGISTERFLAG_NONE
#endif

#if defined(REGISTER_ENUM)
  #undef REGISTER_MIN
  #undef REGISTER_MAX
  #define REGISTER_TYPE REGISTERTYPE_ENUM
#ifndef __KERNEL__  
  #define REGISTER_MIN_ (uint32_t) std::numeric_limits<uint32_t>::min()
  #define REGISTER_MAX_ (uint32_t) std::numeric_limits<uint32_t>::max()
 #else
  #define REGISTER_MIN_ (0U)
  #define REGISTER_MAX_ (4294967295U)
 #endif
#else
  #define REGISTER_ENUM {0, 0}
  #if defined(REGISTER_SIGNED)
	#define REGISTER_TYPE REGISTERTYPE_SIGNED
	#ifndef __KERNEL__  
		#define REGISTER_MIN_ (uint32_t) std::numeric_limits<int32_t>::min()
		#define REGISTER_MAX_ (uint32_t) std::numeric_limits<int32_t>::max()
	#else
		#define REGISTER_MIN_ (-2147483647-1)
		#define REGISTER_MAX_ (2147483647)
	#endif
  #elif defined(REGISTER_FLOAT)
	#define REGISTER_TYPE REGISTERTYPE_FLOAT
	#ifndef __KERNEL__  
		#define REGISTER_MIN_ (uint32_t) std::numeric_limits<float>::min()
		#define REGISTER_MAX_ (uint32_t) std::numeric_limits<float>::max()
	#else
		#define REGISTER_MIN_ -1000000000.0f
		#define REGISTER_MAX_  1000000000.0f
	#endif
  #elif defined(REGISTER_HEX)
	#define REGISTER_TYPE REGISTERTYPE_HEX
	#ifndef __KERNEL__  
		#define REGISTER_MIN_ (uint32_t) std::numeric_limits<uint32_t>::min()
		#define REGISTER_MAX_ (uint32_t) std::numeric_limits<uint32_t>::max()
	#else
		#define REGISTER_MIN_ 0
		#define REGISTER_MAX_ (4294967295U)
	#endif
  #else
	#define REGISTER_TYPE REGISTERTYPE_UNSIGNED
	#ifndef __KERNEL__  
		#define REGISTER_MIN_ (uint32_t) std::numeric_limits<uint32_t>::min()
		#define REGISTER_MAX_ (uint32_t) std::numeric_limits<uint32_t>::max()
	#else
		#define REGISTER_MIN_ 0
		#define REGISTER_MAX_ (4294967295U)
	#endif
  #endif
#endif // if defined(REGISTER_ENUM)

#if defined(REGISTER_MIN)
  #define REGISTER_ATTR_MIN REGISTER_MIN
#else
  #define REGISTER_ATTR_MIN REGISTER_MIN_
#endif

#if defined(REGISTER_MAX)
  #define REGISTER_ATTR_MAX REGISTER_MAX
#else
  #define REGISTER_ATTR_MAX REGISTER_MAX_
#endif

#ifdef _WIN32
#ifdef REGISTER_MAKE_REGISTERS
#define DEFECATE_R(__name__) \
   static const Register REGISTER_REG_NAME(__name__) = { \
		REGISTER_TYPE, \
		# __name__, \
		REGISTER_ATTR_INIT_VALUE, \
		REGISTER_ATTR_MIN, \
		REGISTER_ATTR_MAX, \
		REGISTER_ATTR_MODE | REGISTER_ATTR_INIT | REGISTER_ATTR_VISIBILITY, \
		REGISTER_REG_DESCRIPTION, \
		{REGISTER_CMDS,                                                     {0, 0, 0, 0}}, \
		{REGISTER_ENUM,                                                     {0,0}}, \
	};
#else
#define DEFECATE_R(__name__)  ;
#endif
#endif // ifdef _WIN32

#ifdef __linux__
#ifdef REGISTER_MAKE_REGISTERS
#define DEFECATE_R(__name__) \
   static const Register REGISTER_REG_NAME(__name__) = { \
		.type           = REGISTER_TYPE, \
		.label          = # __name__, \
		.initializeWith = REGISTER_ATTR_INIT_VALUE, \
		.min         = REGISTER_ATTR_MIN, \
		.max         = REGISTER_ATTR_MAX, \
		.flags       = REGISTER_ATTR_MODE | REGISTER_ATTR_INIT | REGISTER_ATTR_VISIBILITY, \
		.description = REGISTER_REG_DESCRIPTION, \
		.commands    = {REGISTER_CMDS,                                                     {0, 0, 0, 0}}, \
		.enumEntries = {REGISTER_ENUM,                                                     {0,0}}, \
	};
#else
#define DEFECATE_R(__name__)  ;
#endif
#endif // ifdef __linux__

#ifdef REGISTER_MAKE_SYSFS
	#define DEFECATE_A(__name__) \
	struct register_device_attribute REGISTER_ATTR_NAME(__name__)	= \
		{                                                             \
		.dev_attr   = {                                                     \
					.attr = {                                         \
						.name = REGISTER_SYSFS_NAME(__name__),        \
				.mode = REGISTER_SYSFS_MODE \
			}, \
						.show	= REGISTER_SYSFS_SHOW,                \
						.store	= REGISTER_SYSFS_STORE,               \
				},	                                                  \
			.reg = &( REGISTER_REG_NAME(__name__)  ),                    \
		};
#else
	#define DEFECATE_A(__name__)	;
#endif

#define DEFECATE(__name__) DEFECATE_R(__name__) DEFECATE_A(__name__)

#if defined(REGISTER_NAME) && defined(REGISTER_LABEL)
	DEFECATE()
	#include "REGISTER_RESET.h"
#endif
