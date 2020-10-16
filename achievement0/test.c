#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "queue.h"
#include "reader.h"
#include "various.h"
#include "statistician.h"

struct pool pool = { {}, pool.m };

void print_queue(struct queue* queue_read)
{
  struct cell* cell = queue_read->first_cell;
  while(cell != NULL)
    {
      printf("%s ", cell->word);
      cell = cell->next;
    }
}

void add_word_queue_test( struct queue* queue_read, struct monkeys* monkeys, int* number_word_read, FILE* file)
{
  for(int i=0; i<=10; i++)
      reader_work(queue_read, monkeys, file,number_word_read);
  printf("words in queue_read are :\n");
  print_queue(queue_read);
}

void manage_queue_stat_test(struct queue* queue_stat, struct queue* queue_read, int* number_diff_word, struct monkeys* monkeys)
{
  struct cell* cell=queue_read->first_cell;
  while( cell != NULL)
    {
      manage_queue_stat(cell->word, queue_stat, number_diff_word, monkeys);
      cell = cell->next;
    }
  printf("words in queue_stat are:\n");
  print_queue(queue_stat);
  printf("%d different words in queue_stat\n", *number_diff_word);
}

      
void pull_word_queue_test( struct queue* queue_read)
{
  pull_word_queue(queue_read);
  printf("words in queue_read after pulling are :\n");
  print_queue(queue_read);
}


void max_min_occurence_test(struct queue* queue_stat, int* max_occ, int* min_occ)
{  
  max_min_occurence(queue_stat, max_occ, min_occ);
  printf("words with highest occurence are:\n");
  words_extrem_occurence(queue_stat, *max_occ);
  printf("words with lowest occurence are:\n");
  words_extrem_occurence(queue_stat, *min_occ);
}
  
    
int main(int argc, char* argv[])
{
 
  (void)argc;
  FILE* file = fopen(argv[1], "r");
  int number_word_read=0;
  int number_diff_word=0;
  int max_occ=1;
  int min_occ=1;
  struct monkeys monkeys = {1,1,1,3}; 
  struct queue queue_read = {NULL,NULL};
  struct queue queue_stat = {NULL,NULL};

  printf("\ntest of add_word_queue and reader_work\n");
  add_word_queue_test(&queue_read, &monkeys, &number_word_read, file);
  printf("test of manage_queue_stat and stat_work\n");
  manage_queue_stat_test(&queue_stat, &queue_read, &number_diff_word, &monkeys);
  printf("test of pull_word_queue");
  pull_word_queue_test(&queue_read);
  printf("test of words with occurence\n");
  printf("highest occurence is:%d and lowest occurence is %d\n",max_occ, min_occ);
  max_min_occurence_test(&queue_stat, &max_occ, &min_occ);

  fclose(file);
  return 0;
}

