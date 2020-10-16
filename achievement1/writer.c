#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "queue.h"
#include "statistician.h"
#include "various.h"
#include "monkeys_work.h"


//CELL goes forwards to a random cell
struct cell* random_cell(struct queue* queue_stat, int* number_diff_word)
{
  int n = random_a_b(1,*number_diff_word);
  struct cell* cell = queue_stat->first_cell;
  //Moves to the n-th cell
  for (int i = 0; i < n; i++)  
    cell = cell->next;
  return cell;
}


//Gives a random punctuation
char random_punctuation() {
  char T[4] = ".;?!";
  int i = rand() % 4;
  return T[i];
}


//Writes a random follower of the cell in the writer queue :
void writes_rand(struct cell* CELL, struct queue* queue_writer, int* sentence_length)
{
  
  int x = CELL->number_foll_word; 
  int p = rand() % 10;
  //If there is no following words or on a 0.1 probability, the writer ends the sentence
  if ( (x == 0) || (p == 1) ) 
    {
      //If there is only one word in the sentence
      if (*sentence_length == 1)
	add_word_queue(queue_writer, "!");
      else
	{
	  char punctuation[2] = {random_punctuation(),0};
	  add_word_queue(queue_writer, punctuation);
	}
      *sentence_length = 0;
    }
  else
    {
      int n = random_a_b(1,x);
      struct cell* cell_tmp = (CELL->queue_follower).first_cell;
      int a = cell_tmp->noccs;
      while (a < n)
	{
	  a+= cell_tmp->noccs;
	  cell_tmp = cell_tmp->next;
	}
      //The random word is writen in the writer queue
      add_word_queue(queue_writer, cell_tmp->word);
      (*sentence_length)++;
    }
}


void writer_work(struct queue* queue_stat, struct queue* queue_writer, int* number_diff_word, struct monkeys* monkeys)
{
  //If there is no word in the queue, the writer strikes
  if (number_diff_word == 0) {
    monkeys->writer = 0;
  }
  else
    {
      //Used to know if there is more than one word in the sentence
      static int sentence_length = 0;
      static struct cell* CELL = NULL;
      //If the sentence is empty, writer chose randomly in queue_stat
      if(sentence_length == 0) 
	{  
	  CELL = random_cell(queue_stat, number_diff_word);  
	  add_word_queue(queue_writer, CELL->word);
	  sentence_length++;
	}
      /*Else if there is one word, then CELL is pointer to a
       *queue_read cell, so he chooses in its successors
       */
      else if(sentence_length == 1) 
	{
	  writes_rand(CELL, queue_writer,&sentence_length);
	}
      /*Else CELL is a pointer to a queue_follower cell, so we
       *search the cell in queue_stat containing the same word..;
       */
      else
	{
	  CELL = search_precedent_cell(queue_stat, queue_writer->last_cell->word);
	   //...then we can go forward its successors
	  writes_rand(CELL, queue_writer,&sentence_length); 
	}
    }
}

