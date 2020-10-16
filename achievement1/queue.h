#ifndef queue1_h
#define queue1_h

#define MAX_WORD_LENGTH 20
#define MAX_CELLS 20000

struct queue{
    struct cell* first_cell;
    struct cell* last_cell;
};

struct cell {
  char word[MAX_WORD_LENGTH+1];
  int noccs;
  int number_foll_word;
  struct queue queue_follower;
  struct cell* next;  
};
  
struct pool {
  struct cell m[MAX_CELLS];
  struct cell* next_free;
};

struct cell* create_new_cell( struct pool *pool, char word[]);

int add_word_queue( struct queue *queue_read, char *word);

void pull_word_queue(struct queue* queue_read);

extern struct pool pool;

#endif
