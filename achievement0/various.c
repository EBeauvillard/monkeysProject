#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "various.h"


//Select a random monkey in the active ones
int random_select(struct monkeys* monkeys)
{
  assert(NUMBER_MONKEYS == 3);
  int tab1[NUMBER_MONKEYS] = {monkeys->reader, monkeys->printer, monkeys->statistician};
  int tab2[monkeys->number_active_monkeys];
  int test_random = rand() % monkeys->number_active_monkeys;
  int i;
  int j = 0;
  for (i = 0 ; i < NUMBER_MONKEYS ; i++) {
    if (tab1[i] == 1) {
      tab2[j] = i;
      j++;
    }
  }
  return tab2[test_random];
}
