main.out: queue.o semaphore.o main.o
	gcc -g -Wall -Werror -o main.out queue.o semaphore.o main.o
	
minesweeper.o: main.c queue.h semaphore.h
	gcc -g -Wall -Werror -c minesweeper.c

input_val.o: queue.c queue.h
	gcc -g -Wall -Werror -c
	
playGame.o: semaphore.c semaphore.h
	gcc -g -Wall -Werror -c playGame.c
clean:
	rm -fr *.o *.out
