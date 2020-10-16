#ifndef reader_h
#define reader_h

#include "various.h"
#include "queue.h"


struct cell* create_new_cell( struct pool *pool, char word[],int noccs,int status, struct cell* next);

void reader_work( struct queue* queue_read,struct monkeys *monkeys, FILE* fichier, int* number_word_read);

#endif
