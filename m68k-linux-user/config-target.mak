# Automatically generated by configure - do not modify
CONFIG_QEMU_INTERP_PREFIX="/usr/gnemul/qemu-m68k"
TARGET_SHORT_ALIGNMENT=2
TARGET_INT_ALIGNMENT=2
TARGET_LONG_ALIGNMENT=2
TARGET_LLONG_ALIGNMENT=2
TARGET_ARCH=m68k
TARGET_M68K=y
TARGET_ARCH2=m68k
TARGET_BASE_ARCH=m68k
TARGET_ABI_DIR=m68k
CONFIG_NO_XEN=y
TARGET_WORDS_BIGENDIAN=y
CONFIG_USER_ONLY=y
CONFIG_LINUX_USER=y
TARGET_XML_FILES= /home/nuk/qemu/qemu-1.0.1/gdb-xml/cf-core.xml /home/nuk/qemu/qemu-1.0.1/gdb-xml/cf-fp.xml
TARGET_HAS_BFLT=y
CONFIG_USE_GUEST_BASE=y
CONFIG_I386_DIS=y
CONFIG_M68K_DIS=y
LDFLAGS+=-Wl,-T../config-host.ld -Wl,-T,$(SRC_PATH)/$(ARCH).ld 
QEMU_CFLAGS+=
QEMU_INCLUDES+=-I$(SRC_PATH)/linux-headers -I$(SRC_PATH)/tcg -I$(SRC_PATH)/tcg/i386 
