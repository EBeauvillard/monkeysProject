#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "various.h"
#include "reader.h"
#include "printer.h"
#include "statistician.h"
#include "monkeys_work.h"

void sel_monkey_work(struct monkeys* monkeys, struct queue* queue_read, struct queue* queue_stat, int* printed_counter, int* number_diff_word, int* number_word_read, FILE* file)
{
  int test_random = random_select(monkeys);
  if (test_random == 0)
    {
      reader_work(queue_read, monkeys, file, number_word_read);
      if (monkeys->statistician == 0)
	{
	  //Reader is the only one able to wake up statistician. So when reader works we make sure statistician is active for the next round
	  monkeys->statistician = 1; 
	  monkeys->number_active_monkeys++; 
	}
    }
  else if (test_random == 1)
    {
      printer_work(queue_read, printed_counter, monkeys);
    }
  else if (test_random == 2)
    {
      stats_work(queue_stat, queue_read, number_diff_word, monkeys);
      if (monkeys->printer == 0)
	{
	  //For the same reason as for reader/statistician, we wake up printer after statistician's work
	  monkeys->printer = 1; 
	  monkeys->number_active_monkeys++;
	}
    }
}
