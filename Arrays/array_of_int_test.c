#include "array_of_int.h"

#include <stdio.h>
#include <math.h>

int main(int argc, char *const argv[]) {
  ArrayOfInt *a = ArrayOfInt_Create(10000);

  for (size_t i = 0; i < ArrayOfInt_GetCapacity(a); i++) {
    ArrayOfInt_PushBack(a, rand());
  }
  ArrayOfInt_QuickSort(a);

  int previous = ArrayOfInt_GetAt(a, 0);
  size_t nErrors = 0;

  for (size_t i = 1; i < ArrayOfInt_GetCapacity(a); i++) {
    int current = ArrayOfInt_GetAt(a, i);
    if (previous > current) {
      fprintf(stderr, "%s: a[%zu](%d) > a[%zu](%d)!\n", argv[0], i - 1, previous, i, current);
      nErrors++;
    }
  }
  return nErrors > 0 ? 1 : 0;
}
