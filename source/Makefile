# Makefile.in for Doom-PSP

TARGET = Duke3d
OBJS    = actors.o game.o gamedef.o global.o menues.o player.o premap.o \
	  sector.o sounds.o rts.o config.o animlib.o testcd.o osdfuncs.o osdcmds.o \
	  a-c.o baselayer.o cache1d.o compat.o crc32.o defs.o engine.o kplib.o mmulti_null.o \
	  osd.o pragmas.o scriptfile.o sdlayer.o control.o file_lib.o keyboard.o mouse.o scriplib.o \
	  util_lib.o mathutil.o audiolib_fx_sdl.o audiolib_musicstub.o sdlayer.o pspDveManager.o


INCDIR = ../../jfbuild_src_20051009/include/ ../../jfduke3d_src_20051009/source/jmact/ ../../jfduke3d_src_20051009/source/jaudiolib/
CFLAGS = -O1 -G0 -g -funsigned-char -Wall -DPSP -DRENDERTYPESDL -DENGINE_USING_A_C -DDEBUGGINGAIDS -DNOASM -DWITHKPLIB -DUSE_A_C
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR =
LDFLAGS =

PSP_FW_VERSION=390
BUILD_PRX = 1
#PSP_LARGE_MEMORY = 1

PSPBIN = $(PSPSDK)/../bin
#CFLAGS += $(shell $(PSPBIN)/sdl-config --nomain)
CFLAGS += -I$(PSPDEV)/psp/include/SDL
LIBS += -L$(PSPDEV)/psp/lib -lSDL_mixer -lvorbisfile -lvorbis -logg -lm -lSDL -lpspirkeyb -lpsppower -lpspaudio -lpspgu -lGL -lpspvfpu -lpsphprm -lpsprtc -lpsputility

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Duke Nukem 3D-PSP Build 98
PSP_EBOOT_ICON = ICON0.PNG
PSP_EBOOT_PIC1 = PIC1.PNG
PSP_EBOOT_SND0 = SND0.AT3

PSPSDK=$(shell psp-config --pspsdk-path)

include $(PSPSDK)/lib/build.mak


