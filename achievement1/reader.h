#ifndef reader_h
#define reader_h

#include "various.h"
#include "queue.h"
//all the prototypes of functions in reader.c

void reader_work( struct queue* queue_read,struct monkeys *monkeys, FILE* fichier, int* number_word_read);

#endif
