#ifndef writer_h
#define writer_h

#include "queue.h"
#include "various.h"
//prototypes of functions in writer.c
struct cell* random_cell(struct queue* queue_stat, int* number_diff_word);

char random_punctuation();

void writes_rand(struct cell* CELL, struct queue* queue_writer, int* sentence_length);

void writer_work(struct queue* queue_stat, struct queue* queue_writer, int* number_diff_word, struct monkeys* monkeys);



#endif
