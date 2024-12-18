build: clean format
	@gcc -o build/chess.o example.c -lncurses

run: build
	@./build/chess.o

clean:
	@rm -f build/chess.o

format:
	@clang-format -i -style=file include/*.h src/*.c
