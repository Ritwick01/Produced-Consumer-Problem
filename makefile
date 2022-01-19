all: Producer Consumer

Producer: Producer.c
	gcc Producer.c -o p

Consumer: Consumer.c
	gcc Consumer.c -o c

clean:
	rm p c 