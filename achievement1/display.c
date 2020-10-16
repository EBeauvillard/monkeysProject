#include <stdio.h>
#include <string.h>
#include "monkeys_work.h"
#include "statistician.h"

void display(struct queue* queue_stat,int number_word_read, int number_diff_word, int printed_counter,int* max_occ, int* min_occ)
{
  printf("\n\n--------End of game--------\nThe Balance sheet is: \n");
  printf("Number of read words: %d\n", number_word_read);
  printf("Number of different words: %d\n", number_diff_word);
  printf("Number of printed words: %d\n", printed_counter);
  max_min_occurence(queue_stat,max_occ,min_occ);
  if (*max_occ==*min_occ)
    {
      printf("All the words appear only once:\n");
      words_extrem_occurence(queue_stat,1);
    }
  else
    {
      printf("the biggest occurence is %d with word(s) : \n", *max_occ);
      words_extrem_occurence(queue_stat,*max_occ);
      printf("the lowest occurence is 1 with word(s) : \n");
      words_extrem_occurence(queue_stat,1);
    }
}
