#ifndef monkeys_work_h
#define monkeys_work_h

#include "queue.h"
#include "various.h"

void sel_monkey_work(struct monkeys* monkeys, struct queue* queue_read, struct queue* queue_stat, int* printed_counter, int* number_diff_word, int* number_word_read, FILE* file);

#endif
