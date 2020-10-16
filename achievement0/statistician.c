#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "queue.h"
#include "reader.h"
#include "various.h"

void manage_queue_stat(char* word, struct queue* queue_stat, int* number_diff_word, struct monkeys *monkeys)
{
  struct cell* cell;
  cell = queue_stat->first_cell;
  while( cell != NULL )
    {
      //If queue_stat already contains the word, we increase its occurence and stop
      if (strcmp(cell->word, word) == 0)
	{
	  cell->noccs = cell->noccs + 1;
	  return;
	}
      cell = cell->next;
    }
  assert( cell == NULL );
  //Else we add a cell containing the word
  if(add_word_queue(queue_stat, word, 1, 0) == 0 )
    {
      monkeys->statistician = 0;
      return;
    }
  *number_diff_word = *number_diff_word + 1;
}

void stats_work(struct queue* queue_stat, struct queue* queue_read , int* number_diff_word, struct monkeys *monkeys)
{               
  /*We make position_stat as a static variable in order to help
   *statistician remember the position he was in queue_read
   *at the last round
   */
  static struct cell* current_position = NULL;
  static int end;
  end = 0;
  if( current_position == NULL && end == 0 )
    current_position = queue_read->first_cell;
  /*If reader has not read a word from the file yet or it is the
   *last of queue_read, statistician is going to strike
   */
  if(current_position == NULL)
    {
      (*monkeys).statistician = 0;
      (*monkeys).number_active_monkeys--;
    }
  else
    {
      /*Else if statistician find a word in queue_read, he marks
       *his passage by changing the status.This detail is
       *particularly important for the printer
       */
      (*current_position).status = 1;
      //Here we manage statistician queue
      manage_queue_stat(current_position->word,queue_stat,number_diff_word, monkeys);
      /*So statistician steps forward in queue_read ans waits
       *the next round
       */
      if (current_position->next==NULL)
	end=1;
      current_position = current_position->next;
      
    }
}

/*This function search in queue_stat the biggest and lowest 
 *occurences of word
 */
void max_min_occurence( struct queue* queue_stat, int* max_occ, int* min_occ) //max_occ is given as pointer and initialized in main
{
  struct cell* cell = queue_stat->first_cell;
  while(cell!=NULL)
    {
      if (cell->noccs > *max_occ)
	*max_occ = cell->noccs;
      if(cell->noccs < *min_occ)
	*min_occ = cell->noccs;
      cell = cell->next;
    }
}

/*Given a number, this function is going to print all the words
 * which have this number as occurence
 */
void words_extrem_occurence(struct queue* queue_stat, int n)
{
  struct cell* cell = queue_stat->first_cell;
  while(cell != NULL)
    {
      if (cell->noccs == n)
	printf("%s\n", (*cell).word);
      cell = cell->next;
    }
}
