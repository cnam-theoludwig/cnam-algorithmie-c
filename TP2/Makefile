LIBRARY_NAME = tp2project
CC = gcc
CC_FLAGS = -Wall -Wextra -Wfloat-equal -Wundef -Wno-unused-variable -std=c17 -pedantic -pedantic-errors -O3 -I./
CC_SANITIZER_FLAGS = -fsanitize=address -fsanitize=undefined

HEADER_FILES = $(wildcard lib/*.h) ./${LIBRARY_NAME}.h
LIB = ./build/${LIBRARY_NAME}.a
LIB_CC_FLAGS = -L. -l:${LIB} -lm
LIB_SOURCES = $(wildcard lib/*.c)
LIB_OBJECTS = $(patsubst %.c, %.o, $(LIB_SOURCES))

DEPENDENCIES_FOLDER = ../dependencies

LIBCPROJECT_REPO = https://github.com/theoludwig/libcproject.git
LIBCPROJECT_VERSION = v4.3.0
LIBCPROJECT_FOLDER = ${DEPENDENCIES_FOLDER}/libcproject
LIBCPROJECT_PATH = ${LIBCPROJECT_FOLDER}/build/libcproject.a
LIBCPROJECT_LIB = -l:${LIBCPROJECT_PATH}

MAIN_EXECUTABLE = bin/tp2

.PHONY: all
all: ${LIB} ${MAIN_EXECUTABLE}

${LIB}: $(addprefix build/, ${LIB_OBJECTS})
	rm --force ${LIB}
	ar -rcs ${LIB} $(addprefix build/, ${LIB_OBJECTS})

${MAIN_EXECUTABLE}: ${LIB} ./main.c ${LIBCPROJECT_PATH}
	mkdir --parents ./bin
	${CC} ${CC_FLAGS} ${CC_SANITIZER_FLAGS} -o ${MAIN_EXECUTABLE} ./main.c ${LIB_CC_FLAGS} ${LIBCPROJECT_LIB}

${LIBCPROJECT_PATH}: ${DEPENDENCIES_FOLDER}
	if [ ! -d "${LIBCPROJECT_FOLDER}" ]; then \
		git clone ${LIBCPROJECT_REPO} ${LIBCPROJECT_FOLDER}; \
		git -C ${LIBCPROJECT_FOLDER} checkout ${LIBCPROJECT_VERSION}; \
	fi
	${MAKE} -C ${LIBCPROJECT_FOLDER}

${DEPENDENCIES_FOLDER}:
	mkdir --parents ${DEPENDENCIES_FOLDER}

build/lib:
	mkdir --parents ./build/lib

build/lib/%.o: lib/%.c ${HEADER_FILES} | build/lib ${LIBCPROJECT_PATH}
	${CC} ${CC_FLAGS} ${CC_SANITIZER_FLAGS} -c $< -o $@ ${LIBCPROJECT_LIB}

.PHONY: run
run: ${MAIN_EXECUTABLE}
	./${MAIN_EXECUTABLE} ${ARGS}

.PHONY: libcproject
libcproject: ${LIBCPROJECT_PATH}

.PHONY: lint
lint:
	clang-format --Werror --dry-run ${LIB_SOURCES} ${HEADER_FILES} ./main.c

.PHONY: clean
clean:
	rm --recursive --force ./build ./bin ./documentation
