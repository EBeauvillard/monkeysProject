#ifndef statistician1_h
#define statistician1_h

#include "various.h"

struct cell* search_precedent_cell(struct queue* queue_stat, char* precedent_word);

void manage_successor_queue(struct queue* queue_stat, char* precedent_word, char* next_word);

void manage_queue_stat(char* word, struct queue* queue_stat, int* number_diff_word, struct monkeys* monkeys);

void stats_work(struct queue* queue_stat, struct queue* queue_read , int* number_diff_word, struct monkeys *monkeys);

void max_min_occurence( struct queue* queue_stat, int* max_occ, int* min_occ);

void words_extrem_occurence(struct queue* queue_stat, int n);

#endif
