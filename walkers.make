# GNU Make project makefile autogenerated by Premake
ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifndef CC
  CC = gcc
endif

ifndef CXX
  CXX = g++
endif

ifndef AR
  AR = ar
endif

ifeq ($(config),debug)
  OBJDIR     = obj/Debug
  TARGETDIR  = .
  TARGET     = $(TARGETDIR)/walkers
  DEFINES   += -DDEBUG
  INCLUDES  += -I/usr/local/include -Iinclude -Ilib
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -Wall -std=c++11
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -L/usr/local/lib -Llib
  LIBS      += -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(ARCH) $(LIBS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),release)
  OBJDIR     = obj/Release
  TARGETDIR  = .
  TARGET     = $(TARGETDIR)/walkers
  DEFINES   += -DNDEBUG
  INCLUDES  += -I/usr/local/include -Iinclude -Ilib
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -Wall -std=c++11
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -Wl,-x -L/usr/local/lib -Llib
  LIBS      += -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(ARCH) $(LIBS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

OBJECTS := \
	$(OBJDIR)/Entity.o \
	$(OBJDIR)/EntityFactory.o \
	$(OBJDIR)/FontManager.o \
	$(OBJDIR)/GameplayState.o \
	$(OBJDIR)/GameStateManager.o \
	$(OBJDIR)/Graphics.o \
	$(OBJDIR)/main.o \
	$(OBJDIR)/SoundEngine.o \
	$(OBJDIR)/SoundManager.o \
	$(OBJDIR)/SystemFactory.o \
	$(OBJDIR)/Vector2d.o \
	$(OBJDIR)/World.o \
	$(OBJDIR)/asset_helper.o \
	$(OBJDIR)/TextureManager.o \
	$(OBJDIR)/CollisionSystem.o \
	$(OBJDIR)/CorpseSystem.o \
	$(OBJDIR)/DamageSystem.o \
	$(OBJDIR)/FacingSystem.o \
	$(OBJDIR)/MonsterSpawningSystem.o \
	$(OBJDIR)/MonsterSystem.o \
	$(OBJDIR)/MoveSystem.o \
	$(OBJDIR)/ParticleSystem.o \
	$(OBJDIR)/RemoveSystem.o \
	$(OBJDIR)/ShootingSystem.o \
	$(OBJDIR)/jsoncpp.o \

RESOURCES := \

SHELLTYPE := msdos
ifeq (,$(ComSpec)$(COMSPEC))
  SHELLTYPE := posix
endif
ifeq (/bin,$(findstring /bin,$(SHELL)))
  SHELLTYPE := posix
endif

.PHONY: clean prebuild prelink

all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

$(TARGET): $(GCH) $(OBJECTS) $(LDDEPS) $(RESOURCES)
	@echo Linking walkers
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

$(TARGETDIR):
	@echo Creating $(TARGETDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(TARGETDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(TARGETDIR))
endif

$(OBJDIR):
	@echo Creating $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(OBJDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(OBJDIR))
endif

clean:
	@echo Cleaning walkers
ifeq (posix,$(SHELLTYPE))
	$(SILENT) rm -f  $(TARGET)
	$(SILENT) rm -rf $(OBJDIR)
else
	$(SILENT) if exist $(subst /,\\,$(TARGET)) del $(subst /,\\,$(TARGET))
	$(SILENT) if exist $(subst /,\\,$(OBJDIR)) rmdir /s /q $(subst /,\\,$(OBJDIR))
endif

prebuild:
	$(PREBUILDCMDS)

prelink:
	$(PRELINKCMDS)

ifneq (,$(PCH))
$(GCH): $(PCH)
	@echo $(notdir $<)
	-$(SILENT) cp $< $(OBJDIR)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
endif

$(OBJDIR)/Entity.o: src/Entity.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/EntityFactory.o: src/EntityFactory.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/FontManager.o: src/FontManager.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/GameplayState.o: src/GameplayState.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/GameStateManager.o: src/GameStateManager.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Graphics.o: src/Graphics.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/main.o: src/main.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/SoundEngine.o: src/SoundEngine.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/SoundManager.o: src/SoundManager.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/SystemFactory.o: src/SystemFactory.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Vector2d.o: src/Vector2d.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/World.o: src/World.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/asset_helper.o: src/assets/asset_helper.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/TextureManager.o: src/assets/TextureManager.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/CollisionSystem.o: src/systems/CollisionSystem.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/CorpseSystem.o: src/systems/CorpseSystem.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/DamageSystem.o: src/systems/DamageSystem.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/FacingSystem.o: src/systems/FacingSystem.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/MonsterSpawningSystem.o: src/systems/MonsterSpawningSystem.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/MonsterSystem.o: src/systems/MonsterSystem.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/MoveSystem.o: src/systems/MoveSystem.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ParticleSystem.o: src/systems/ParticleSystem.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/RemoveSystem.o: src/systems/RemoveSystem.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ShootingSystem.o: src/systems/ShootingSystem.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/jsoncpp.o: lib/jsoncpp.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
