LIBS=-lraylib -lm  # posix?
LIBS=-lraylib -mwindows -lwinmm

main: main.c raylib/src/raylib.h raylib/src/raymath.h raylib/src/libraylib.a
	cc -I raylib/src/ -L raylib/src/ -o main main.c ${LIBS}

raylib/src/libraylib.a: raylib/src/*.c raylib/src/*.h
	make -C raylib/src/

clean:
	make -C raylib/src/ PLATFORM_SHELL=sh clean
	rm main.exe || true
	rm main || true
