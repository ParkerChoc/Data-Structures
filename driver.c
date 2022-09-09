#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "dynarray.h"

int main()
{
  struct list* a = list_create();
  free(a);
  return 0;
}
