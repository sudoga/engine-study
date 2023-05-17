TARGET   = enjin

CC       = clang
CFLAGS   = -std=c18 -Wall -I.

CXX      = clang++
CXXFLAGS = -std=c++17 -Wall -I.

CXXFLAGS += -DGLM_FORCE_RADIANS -I"./lib/glm" \
	-isystem "./lib/image" \
	`sdl2-config --cflags` \
	-fno-exceptions


LINKER   = clang++ 

LFLAGS   = 					\
	-fuse-ld=lld 			\
	-lm 		 			\
	`sdl2-config --libs` 	\
	-flto 

SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(SRCDIR)/*/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.hpp) $(wildcard $(SRCDIR)/*/*.hpp)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm       = rm -f

OPT := -O2 -flto

ifeq ($(OS),Windows_NT)
	LFLAGS += -lmingw32 -mconsole
endif

$(BINDIR)/$(TARGET): $(OBJECTS)
	$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"