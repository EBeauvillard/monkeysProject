#include <getopt.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "various.h"
#include "reader.h"
#include "printer.h"
#include "statistician.h"
#include "monkeys_work.h"
#include "display.h"
#include "arg_test.h"

#define MAX_TURN 500

struct pool pool = { {}, pool.m };  //Initialisation of the pool in order to allocate the necessary place in the memory for creating queues

int main(int argc, char* argv[])
{
  parse_opt(argc, argv);
  FILE* file = fopen(argv[optind], "r");
  test_file(file);
  int turn = 1;
  //Struct monkeys contains, in order, the status of reader, printer and statistician (1 : active, else : 0) and the number of active monkeys
  //Initialisation of game parameters
  struct monkeys monkeys = {1,1,1,3}; 
  struct queue queue_read = {NULL,NULL};
  struct queue queue_stat = {NULL,NULL};
  int number_word_read = 0;
  int printed_counter = 0;
  int number_diff_word = 0;
  int max_occ = 1;
  int min_occ = 1;
  while( (turn <= MAX_TURN) && monkeys.number_active_monkeys)
  //The game ends when the max_turn is overtook or if there is no longer active monkey
    {
      sel_monkey_work(&monkeys, &queue_read, &queue_stat, &printed_counter, &number_diff_word, &number_word_read,file);
      turn++;
    }
  fclose(file);
  display(&queue_stat,number_word_read,number_diff_word,printed_counter,&max_occ,&min_occ);
  return 0;
}
