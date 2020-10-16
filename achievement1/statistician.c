#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "queue.h"
#include "reader.h"


//This function search in queue stat the cell containing precedent_word in order to add next_word as its successor
struct cell* search_precedent_cell(struct queue* queue_stat, char* precedent_word)
{
  struct cell* cell= queue_stat->first_cell;

  /*we didn't need to test if the cell is NULL because we're sure
   *to find precedent_word in queue_stat as we call the function
   * "search_precedent_cell" after statistician has read at least 
   *the first word in queue_read
   */
  while(strcmp(cell->word,precedent_word))
    {
      cell=cell->next;
    } 
  return cell;
}


//Here we add a successor or increase occurence if it already exists
void manage_successor_queue(struct queue* queue_stat, char* precedent_word, char* next_word)
{
  //Search the cell containing precedent_word
  struct cell* cell = search_precedent_cell(queue_stat, precedent_word);
  struct cell* cell_succ = (cell->queue_follower).first_cell;
  cell->number_foll_word += 1;
  while( cell_succ != NULL)
    {
      //If next_word already exists as successor
      if (strcmp(cell_succ->word, next_word) == 0) 
	{
	  cell_succ->noccs = cell_succ->noccs + 1;  
	  return;
	}
      cell_succ = cell_succ->next;
    }
  assert(cell_succ == NULL);
  //Else we add it as successor
  add_word_queue(&(cell->queue_follower), next_word); 
}


//This function adds words only in queue_stat
void manage_queue_stat(char* word, struct queue* queue_stat, int* number_diff_word, struct monkeys* monkeys)
{
  struct cell* cell = NULL;
  cell = queue_stat->first_cell;
  while( cell != NULL )
    {
       //If queue_stat already contains the word, we increase it occurence and stop
      if (strcmp(cell->word, word) == 0) 
	{
	  cell->noccs = cell->noccs + 1;
	  return;
	}
      cell = cell->next;
    }
  assert( cell == NULL );
  //If we reach the end, we did not find our word, so we add it
  if(add_word_queue(queue_stat, word) == 0 )
    {
      monkeys->statistician = 0;
      monkeys->number_active_monkeys--;
      return;
    }
  *number_diff_word = *number_diff_word + 1;
}


void stats_work(struct queue* queue_stat, struct queue* queue_read , int* number_diff_word, struct monkeys *monkeys)
{
  /*We make precedent_word as a static variable because statistician
   *pull-of queue_read after reading the first_cell
   */
  static char precedent_word[MAX_WORD_LENGTH] = "-";
  /*If reader has not read a word from the file yet or it is
   *the last of queue_read, statistician is going to strike
   */
  if(queue_read->first_cell == NULL)
    {
      (*monkeys).statistician=0;
      (*monkeys).number_active_monkeys--;      
    }
  else
    {
      /*This 'if' manages the successor queue (adding successor or
       *increasing occurence if already successor)
       */
      if(strcmp(precedent_word,"-")) 
	manage_successor_queue(queue_stat, precedent_word, queue_read->first_cell->word);
      //Here we manage statistician queue (look at the role of the function above)
      manage_queue_stat(queue_read->first_cell->word, queue_stat, number_diff_word, monkeys);
      //Remember the word as precedent word
      strcpy(precedent_word, queue_read->first_cell->word);
      pull_word_queue(queue_read);
    }
}


//This function search in queue_stat the biggest and lowest occurences of word
void max_min_occurence( struct queue* queue_stat, int* max_occ, int* min_occ)
//max_occ and min_occ given as pointer and initialized in main
{
  struct cell* cell = queue_stat->first_cell;
 
  while(cell!=NULL)
    {
      if ((*cell).noccs > *max_occ)
	*max_occ=(*cell).noccs;
      if ((*cell).noccs < *min_occ)
	*min_occ=(*cell).noccs;
      cell=cell->next;
    }
}


//Given a number, this function is going to print all the words which have this number as occurence.
void words_extrem_occurence(struct queue* queue_stat, int n)
{
  struct cell* cell=queue_stat->first_cell;
  while(cell!=NULL)
    {
      if ((*cell).noccs == n)
	{
	  printf("%s\n", (*cell).word);
	}
      cell=cell->next;
    }
}
