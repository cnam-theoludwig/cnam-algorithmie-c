LIBRARY_NAME = tp3project
CC = gcc
CC_FLAGS = -Wall -Wextra -Wfloat-equal -Wundef -Wno-unused-variable -std=c17 -pedantic -pedantic-errors -O3 -I./
CC_SANITIZER_FLAGS =
# CC_SANITIZER_FLAGS = -fsanitize=address -fsanitize=undefined

HEADER_FILES = $(wildcard lib/*.h) ./${LIBRARY_NAME}.h
LIB = ./build/${LIBRARY_NAME}.a
LIB_CC_FLAGS = -L. -l:${LIB} -lm
LIB_SOURCES = $(wildcard lib/*.c)
LIB_OBJECTS = $(patsubst %.c, %.o, $(LIB_SOURCES))

MAIN_EXECUTABLE = bin/tp3

.PHONY: all
all: ${LIB} ${MAIN_EXECUTABLE}

${LIB}: $(addprefix build/, ${LIB_OBJECTS})
	rm --force ${LIB}
	ar -rcs ${LIB} $(addprefix build/, ${LIB_OBJECTS})

${MAIN_EXECUTABLE}: ${LIB} ./main.c
	mkdir --parents ./bin
	${CC} ${CC_FLAGS} ${CC_SANITIZER_FLAGS} -o ${MAIN_EXECUTABLE} ./main.c ${LIB_CC_FLAGS}

build/lib:
	mkdir --parents ./build/lib

build/lib/%.o: lib/%.c ${HEADER_FILES} | build/lib
	${CC} ${CC_FLAGS} ${CC_SANITIZER_FLAGS} -c $< -o $@

.PHONY: run
run: ${MAIN_EXECUTABLE}
	./${MAIN_EXECUTABLE} ${ARGS}

.PHONY: lint
lint:
	clang-format --Werror --dry-run ${LIB_SOURCES} ${HEADER_FILES} ./main.c

.PHONY: clean
clean:
	rm --recursive --force ./build ./bin
