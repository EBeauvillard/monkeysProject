#include <getopt.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "various.h"
#include "reader.h"
#include "statistician.h"
#include "printer.h"
#include "writer.h"
#include "monkeys_work.h"
#include "display.h"
#include "arg_test.h"

#define MAX_TURN 1000

struct pool pool = { {}, pool.m };  //Initialisation of the pool in order to allocate the necessary place in the memory for creating queues

int main(int argc, char* argv[])
{
  parse_opt(argc, argv);
  FILE* file = fopen(argv[optind], "r");
  test_file(file);
  //Initialisation of game parameters
  int turn = 1;
  int number_word_read=0;
  int printed_counter=0;
  int number_diff_word=0;
  int max_occ=1;
  int min_occ=1;
  struct monkeys monkeys = {1,1,1,0,3};  //Struct monkeys contains, in order the status of reader,printer, statistician and writer (1 : active, else : 0) and the number of active monkeys
  struct queue queue_read = {NULL,NULL};
  struct queue queue_stat = {NULL,NULL};
  struct queue queue_writer = {NULL,NULL};
  while(turn <= MAX_TURN && monkeys.number_active_monkeys)
  //The game ends when the max_turn is overtook or if there is no longer active monkey
    {
      sel_monkey_work_round(&monkeys, &queue_read, &queue_stat, &queue_writer, &printed_counter, &number_diff_word, &number_word_read,file);
      turn++;
      if(turn == 100)
	{
	  monkeys.writer++;
	  monkeys.number_active_monkeys++;
	}
    }	 
  fclose(file);
  display(&queue_stat,number_word_read,number_diff_word,printed_counter,&max_occ,&min_occ);
  return 0;
}
