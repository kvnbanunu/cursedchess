build: clean format
	@gcc -o build/chess.o src/white.c src/board.c src/game.c src/piece.c src/render.c -lncurses

run:
	@./build/chess.o

clean:
	@rm -f build/chess.o

format:
	@clang-format -i -style=file include/*.h src/*.c
