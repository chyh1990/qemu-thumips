# Automatically generated by configure - do not modify
CONFIG_QEMU_INTERP_PREFIX="/usr/gnemul/qemu-ppcemb"
TARGET_SHORT_ALIGNMENT=2
TARGET_INT_ALIGNMENT=4
TARGET_LONG_ALIGNMENT=4
TARGET_LLONG_ALIGNMENT=8
TARGET_ARCH=ppcemb
TARGET_PPCEMB=y
TARGET_ARCH2=ppcemb
TARGET_BASE_ARCH=ppc
TARGET_ABI_DIR=ppc
CONFIG_NO_XEN=y
TARGET_WORDS_BIGENDIAN=y
TARGET_PHYS_ADDR_BITS=64
CONFIG_SOFTMMU=y
LIBS+=-lutil -lrbd -lrados -lcurl   -lncurses  -luuid -lpng12   -ljpeg -lsasl2 -lgnutls   -lSDL   -lX11  -laio 
HWDIR=../libhw64
TARGET_XML_FILES= /home/nuk/qemu/qemu-1.0.1/gdb-xml/power-core.xml /home/nuk/qemu/qemu-1.0.1/gdb-xml/power-fpu.xml /home/nuk/qemu/qemu-1.0.1/gdb-xml/power-altivec.xml /home/nuk/qemu/qemu-1.0.1/gdb-xml/power-spe.xml
CONFIG_I386_DIS=y
CONFIG_PPC_DIS=y
LDFLAGS+=
QEMU_CFLAGS+=-DHAS_AUDIO -DHAS_AUDIO_CHOICE 
QEMU_INCLUDES+=-I$(SRC_PATH)/linux-headers -I$(SRC_PATH)/tcg -I$(SRC_PATH)/tcg/i386 
