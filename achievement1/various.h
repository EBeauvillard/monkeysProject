#ifndef various_h
#define various_h

#define NUMBER_MONKEYS 4

struct monkeys {
  int reader;
  int printer;
  int statistician;
  int writer;
  int number_active_monkeys;
};

int random_select(struct monkeys* monkeys);

int random_a_b(int a, int b);

#endif
