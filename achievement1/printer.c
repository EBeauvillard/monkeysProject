#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "queue.h"
#include "reader.h"
#include "various.h"

void printer_work(struct queue* queue_writer, int* printed_counter, struct monkeys* monkeys)
{
  static struct cell* last_position = NULL;
  struct cell* current_position = NULL;
  if (last_position == NULL)
    current_position = queue_writer->first_cell;
  else
    current_position = last_position->next;
  if(current_position == NULL) 
    {
      (*monkeys).printer=0;
      (*monkeys).number_active_monkeys--;
    }
  else
    {
      printf("%s ", current_position->word);
      (*printed_counter)++;
      last_position = current_position;
    }
}


