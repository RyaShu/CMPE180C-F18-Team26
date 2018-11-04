Producer-Consumer.out: Producer-Consumer.o
	gcc -pthread -g -Wall -Werror -o Producer-Consumer.out Producer-Consumer.o
clean:
	rm -fr *.o *.out
