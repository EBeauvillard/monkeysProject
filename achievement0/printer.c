#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "queue.h"
#include "reader.h"
#include "various.h"

void printer_work(struct queue* queue_read, int* printed_counter, struct monkeys* monkeys)
{
  //printer will strike if there is no more word in queue_read or if the word has not been read by statistician yet
  if( (queue_read->first_cell != NULL) && ( (*(queue_read->first_cell)).status==1 ) )
    {
      printf("%s ", queue_read->first_cell->word);
      pull_word_queue(queue_read);
      (*printed_counter)++;
    }
  else
    {
      (*monkeys).printer = 0;
      (*monkeys).number_active_monkeys--;
    }
}


  

