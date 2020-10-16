#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

struct cell* create_new_cell( struct pool *pool, char word[])
{
  //First test if there is enough space in the pool for a new cell
  if(pool->next_free - pool->m >= MAX_CELLS)
    return NULL;
  //Initialisation of the new cell
  struct cell* res = pool->next_free;
  strncpy(res->word, word, MAX_WORD_LENGTH+1);
  res->noccs = 1;
  res->next = NULL;
  struct queue queue_tmp = {NULL, NULL};
  res->queue_follower = queue_tmp;
  res->number_foll_word = 0;
  pool->next_free++;
  return res;
}


int add_word_queue( struct queue *queue_read, char *word)
{
  assert(queue_read != NULL);

  struct cell *newcell = create_new_cell(&pool, word);
  if(newcell == NULL)
    return 0;
  //If the queue is empty we add the cell at the beginning
  if(queue_read->first_cell == NULL)
    {
      queue_read->first_cell = newcell;
    }
  else
    {
      queue_read->last_cell->next = newcell;
    }
  queue_read->last_cell = newcell;
  return 1;
}


void pull_word_queue(struct queue* queue_read) //function to cat the first element of a queue by just changing its pointer to the next element.
{
  queue_read->first_cell = queue_read->first_cell->next;
}
