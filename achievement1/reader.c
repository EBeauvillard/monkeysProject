#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "various.h"

void reader_work( struct queue* queue_read,
		  struct monkeys *monkeys,
		  FILE* file,
		  int* number_word_read )
{
  char word_read[MAX_WORD_LENGTH];

  //If there is still words in the file .txt we read it...
  if(fscanf(file," %s",word_read) == 1)
    {
      //...and create a cell to contain it
      if(add_word_queue(queue_read, word_read) == 0)
	{
	  monkeys->reader = 0;
	  monkeys->number_active_monkeys--;
	  return;
	}
      (*number_word_read) = (*number_word_read) + 1;
    }
  else
    {
       //Else reader is going to strike
      (*monkeys).reader = 0;  
      (*monkeys).number_active_monkeys--;
    }
}











