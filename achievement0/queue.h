#ifndef queue_h
#define queue_h

#define MAX_WORD_LENGTH 20
#define MAX_CELLS 200

struct cell {
  char word[MAX_WORD_LENGTH+1];
  int noccs;
  struct cell* next;
  int status;
};

struct pool {
  struct cell m[MAX_CELLS];
  struct cell* next_free;
};

struct queue {
  struct cell* first_cell;
  struct cell* last_cell;
};

struct cell* create_new_cell( struct pool *pool, char word[],int noccs,int status, struct cell* next);

int add_word_queue( struct queue *queue_read, char *word, int noccs, int status);

void pull_word_queue(struct queue* queue_read);

extern struct pool pool;


#endif
