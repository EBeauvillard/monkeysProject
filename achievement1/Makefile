CFLAGS=-Wall  -Wextra -Werror -std=c99 -g3
ARGS.h=queue.h various.h reader.h printer.h statistician.h writer.h
ARGS.o=queue.o various.o reader.o printer.o statistician.o writer.o

all : display_project

clean :
	rm *.o | rm *~ | rm *#* | rm project | rm a.out

tags :
	git ls-files . | grep "\.[ch]*" | xargs etags

queue.c : queue.h

queue.o : queue.c
	gcc ${CFLAGS} -c $< -o $@

various.c : various.h

various.o : various.c
	gcc ${CFLAGS} -c $< -o $@

reader.c : queue.h various.h

reader.o : reader.c
	gcc ${CFLAGS} -c $< -o $@

statistician.c : reader.h queue.h various.h

statistician.o : statistician.c
	gcc ${CFLAGS} -c $< -o $@

writer.c : queue.h statistician.h various.h

writer.o : writer.c
	gcc ${CFLAGS} -c $< -o $@

printer.c : writer.h queue.h various.h

printer.o : printer.c
	gcc ${CFLAGS} -c $< -o $@

monkeys_work.c : ${ARGS.h}

monkeys_work.o : monkeys_work.c
	gcc ${CFLAGS} -c $< -o $@

display.c : ${ARGS.h}

display.o : display.c
	gcc ${CFLAGS} -c $< -o $@

#arg_test.c : ... ; arg_test.c ne dépend d'aucun *.h

arg_test.o : arg_test.c
	gcc ${CFLAGS} -c $< -o $@

game_main.c : ${ARGS.h} monkeys_work.h display.h arg_test.h

game_main.o : game_main.c
	gcc ${CFLAGS} -c $< -o $@

project : ${ARGS.o} game_main.o monkeys_work.o display.o arg_test.o 
	gcc ${CFLAGS} $^ -o $@

display_project : project
	./project

test.c : queue.h statistician.h reader.h various.h

test.o : test.c
	gcc ${CFLAGS} -c $< -o $@

bin_test : test.o queue.o statistician.o reader.o various.o
	gcc ${CFLAGS} $^ -o $@

test : bin_test
	./bin_test ../test.txt
