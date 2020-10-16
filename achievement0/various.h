#ifndef various_h
#define various_h

#define NUMBER_MONKEYS 3

struct monkeys {
  int reader;
  int printer;
  int statistician;
  int number_active_monkeys;
};

int random_select(struct monkeys* monkeys);

#endif
