# Files
S_FILES=main.c

# Output
EXEC=app

# Build settings
CC=clang
# SDL options
CC_SDL=`sdl2-config --cflags --libs`

all:Build

Build:
	$(CC) $(S_FILES) -o $(EXEC) $(CC_SDL)

build_run:Build
	$(EXEC)
