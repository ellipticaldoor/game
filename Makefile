PKG_CONFIG=`pkg-config --libs --cflags sdl2 sdl2_image sdl2_ttf`
FLAGS=-std=c++17 -Wall -Wextra -Wfatal-errors -Wshadow -Iinclude -Wweak-vtables -Wmissing-noreturn -Wunreachable-code
RELEASE_FLAGS=-O2 -Werror
BUILD=time clang++ ${FLAGS} ${PKG_CONFIG} -I ./src src/main.cpp

build-pch:
	@time clang++ ${FLAGS} ./src/pch.hpp -o bin/pch.hpp.gch

build:
	@if [ ! -f ./bin/pch.hpp.gch ]; then make build-pch; fi
	@${BUILD} ${ARGS} -include-pch bin/pch.hpp.gch -o bin/game.out

release:
	@${BUILD} ${RELEASE_FLAGS} -o bin/game.release.out

debug:
	@make build ARGS=-g

run:
	@make debug && ./bin/game.out

format:
	@find src -type f -name "*.cpp" -o -name "*.hpp" | xargs clang-format --verbose -i

test:
	@./scripts/test.sh
