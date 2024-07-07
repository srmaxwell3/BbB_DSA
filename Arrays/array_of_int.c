#include "array_of_int.h"
#include <assert.h>
#include <memory.h>
#include <stdlib.h>

// ArrayOfInt_Create(): Create a new array on the heap, with capacity == initialCapacity,
// and size == 0 (empty).
// O(1) space and O(1) time.
ArrayOfInt *ArrayOfInt_Create(size_t initialCapacity) {

  // Allocate space for the ArrayOfInt structure.
  ArrayOfInt *a = (ArrayOfInt *) malloc(sizeof(ArrayOfInt));
  assert(a);

  // Setup for an empty array, with some initial capacity.
  a->capacity = initialCapacity;
  a->size =  0;

  // Allocate space for capacity elements.
  a->values = (int *) malloc(sizeof(int) * a->capacity);
  assert(a->values || a->capacity == 0);
}

// ArrayOfInt_Destroty(): Destroy an array.
// O(1) space and time.
void ArrayOfInt_Destroy(ArrayOfInt *a) {
  assert(a);
  free(a->values);
  free(a);
}

// ArrayOfInt_GetCapacity(): Return the array's current capacity.
// O(1) space and O(1) time.
size_t ArrayOfInt_GetCapacity(ArrayOfInt *a) {
  return a->capacity;
}

// ArrayOfInt_SetCapacity(): Change the array's current capacity.
// O(1) space and O(1) time.
size_t ArrayOfInt_SetCapacity(ArrayOfInt *a, size_t newCapacity) {
  assert(a);

  // Reallocate space for the values, given the new capacity.
  a->values = (int *) realloc(a->values, newCapacity * sizeof(int));
  assert(a->values);
  a->capacity = newCapacity;

  // We can't have a size greater than capacity.  If we decreased the array's capacity,
  // we may have decreased its size, too.
  if (a->size > a->capacity) {
    assert(a);
    a->size = a->capacity;
  }
}

// ArrayOfInt_GetSize(): Return the array's current size.
// O(1) space and O(1) time.
size_t ArrayOfInt_GetSize(ArrayOfInt *a) {
  assert(a);
  return a->size;
}

// ArrayOfInt_SetSize(): Change the array's current size; if necessary
// enlarge the array's capacity to accommodate the new size.
// O(1) space and O(1) time.
size_t ArrayOfInt_SetSize(ArrayOfInt *a, size_t size) {
  assert(a);
  return a->size;
}

// ArrayOfInt_IsEmpty(): Return true if the array is empty, i.e. size == 0.
// O(1) space and O(1) time.
bool ArrayOfInt_IsEmpty(ArrayOfInt *a) {
  assert(a);
  return a->size == 0;
}

// ArrayOfInt_IsFull(): Return true if the array is full, i.e. size == capacity.
// O(1) space and O(1) time.
bool ArrayOfInt_IsFull(ArrayOfInt *a) {
  assert(a);
  return a->size == a->capacity;
}

// ArrayOfInt_At(): Return a pointer to the array's i'th element, if i < the array's
// size; otherwise announce an error, and exit.
// O(1) space and O(1) time.
int *ArrayOfInt_At(ArrayOfInt *a, size_t i) {
  assert(a);
  assert(i < a->size);
  return &a->values[i];
}

// ArrayOfInt_GetAt(): Return the value of the array's i'th element.
// O(1) space and O(1) time.
int ArrayOfInt_GetAt(ArrayOfInt *a, size_t i) {
  return *ArrayOfInt_At(a, i);
}

// ArrayOfInt_SetAt(): Set the value of the array's i'th element to value.
// O(1) space and O(1) time.
int ArrayOfInt_SetAt(ArrayOfInt *a, size_t i, int value) {
  *ArrayOfInt_At(a, i) = value;
}

// ArrayOfInt_InsertAt(): Insert the value at the i'th position of the array, increasing
// the array's size by 1.
// O(1) space and (generally) O(N) time.
void ArrayOfInt_InsertAt(ArrayOfInt *a, size_t i, int value) {
  assert(a);

  // We can only insert within, or at the very end, of the array.
  assert(i <= a->size);

  // If there's no room, get some.
  if (ArrayOfInt_IsFull(a)) {
    ArrayOfInt_SetCapacity(a, a->capacity + 16);
  }

  // If i == the size of the array, then this is just a push back, and O(1).
  if (i == a->size) {
    a->values[a->size++] = value;
    return;
  }

  // We need to open a hole at the i'th position, to make room for the inserted value.
  // This loop is what makes insertion O(N); on average we'll have to move a->size / 2
  // elements.
  for (int *p = &a->values[a->size + 1], p != &a->values[i]; p++) {
    p[0] = p[-1];	// Yes, this is legal, and means *p = *(p - 1). 
  }
  a->size += 1;

  // Now that we have our hole, we can fill it.
  a->values[i] = value;
}

// ArrayOfInt_PushBack(): Append value to the end of the array, growing the array's size
// by 1.
// O(1) space and O(1) time.
void ArrayOfInt_PushBack(ArrayOfInt *a, int value) {
  ArrayOfInt_InsertAt(a, a->size, value);
}

// ArrayOfInt_PushFront(): Prepend value to the beginning of the array, growing the array's
// size by 1.
// O(1) space and O(1) time.
void ArrayOfInt_PushFront(ArrayOfInt *a, int value) {
  ArrayOfInt_InsertAt(a, 0, value);
}

// ArrayOfInt_DeleteAt(): Delete the value at the i'th position of the array, decreasing the
// array's size by 1.
// O(1) space and (generally) O(N) time.
void ArrayOfInt_DeleteAt(ArrayOfInt *a, size_t i) {
  assert(a);

  // We can only delete within the array.
  assert(i < a->size);

  // We need to close a hole at the i'th position, to remove the deleted value.  This
  // loop is what makes insertion O(N); on average we'll have to move a->size / 2 elements.
  for (int *p = &a->values[i], p != &a->values[a->size]; p++) {
    p[0] = p[1];	// Yes, this is legal, and means *p = *(p + 1). 
  }
  a->size -= 1;
}

// ArrayOfInt_PushBack(): Append value to the end of the array, growing the
// array's size by 1.
// O(1) space and O(1) time.
void ArrayOfInt_PopBack(ArrayOfInt *a, int value) {
  ArrayOfInt_DeleteAt(a, a->size, value);
}

// ArrayOfInt_PushFront(): Prepend value to the beginning of the array, growing the
// array's size by 1.
// O(1) space and O(1) time.
void ArrayOfInt_PopFront(ArrayOfInt *a, int value) {
  ArrayOfInt_DeleteAt(a, 0, value);
}

// ArrayOfInt_LinearSearch(): Assuming no ordering, search though the array for the
// provided value, returning its index (position).  If not found, return the size
// of the array (i.e. the position following the last element in the array).
size_t ArrayOfInt_LinearSearch(ArrayOfInt *a, int value) {
  assert(a);
  size_t i = 0;
  while (i < a->size) {
    if (ArrayOfInt_GetAt(i) == value) {
      break;
    }
    i += 1;
  }
  return i;
}

// ArrayOfInt_BinarySearch(): Assuming ascending order, search though the array for the
// provided value, returning its indoex (position).  If not found, return the size of
// the array (i.e. the position following the last element in the array).
size_t ArrayOfInt_BinarySearch(ArrayOfInt *a, int value) {
  assert(a);
  size_t lo = 0;
  size_t hi = a->size;
  while (lo < hi) {
    size_t mi = (lo + hi) / 2;
    if (ArrayOfInt_GetAt(i) == value) {
      return mi;
    }
    if (ArrayOfInt_GetAt(i) < value) {
      hi = mi;
    } else {
      lo = mi + 1;
    }
  }
  return a->size;
}

// ArrayOfInt_BubbleSort(): Sorts the array using bubble-sort.
// O(N2)
void ArrayOfInt_BubbleSort(ArrayOfInt *a) {
  assert(a);

  // We keep track, through each linear pass of the array, or whether any change was
  // made.  This helps prevent sorting an already sorted array.
  bool changesMade = true;

  // Make a linear pass through the array, each time shrinking the range by 1 element.
  for (size_t i = a->size; changesMake && i > 0; i--) {

    // No changes yet, this pass.
    changesMade = false;

    // Make a single linear path through the current range.  We're looking for elements
    // that are out-of-order, by comparing each pair of consecutive elements.
    for (size_t j = 1; j < i; j++) {
      int x = ArrayOfInt_GetAt(a, j - 1);
      int y = ArrayOfInt_GetAt(a, j);
      if (x > y) {

        // x is out of order with respect to y, so swap the pair, and remember that
        // we've made a change.
        ArrayOfInt_SetAt(a, j - 1, y);
        ArrayOfInt_SetAt(a, j, x);
        changesMade = true;
      }
    }
  }
  return a;
}

// ArrayOfInt_QuickSort(): Sorts the array using quick-sort)
static void ArrayOfInt_QuickSortHelper(ArrayOfInt *a, size_t lo, size_t hi) {
  if (lo == hi) {
    return;
  }
  if (lo + 1 == hi) {
    int x = ArrayOfInt_GetAt(a, lo);
    int y = ArrayOfInt_GetAt(a, hi);
    if (x > y) {
      ArrayOfInt_SetAt(a, lo, y);
      ArrayOfInt_SetAt(a, hi, x);
      return;
    }
  }
  int pivot = ArrayOfInt_GetAt(a, (lo + hi) / 2);
  size_t left = lo;
  size_t right = hi - 1;
  while (left < right) {
    int y = ArrayOfInt_GetAt(a, right);
    while (left < right && ArrayOfInt_GetAt(a, left) <= pivot) {
      left += 1;
    }
    while (left < right && ArrayOfInt_GetAt(a, right) >= pivot) {
      right -= 1;
    }
    if (left < right) {
      int x = ArrayOfInt_GetAt(a, lo);
      int y = ArrayOfInt_GetAt(a, hi);
      ArrayOfInt_SetAt(a, left, y);
      ArrayOfInt_SetAt(a, right, x);

    }
  }
  ArrayOfInt_QuickSortHelper(a, lo, left);
  ArrayOfInt_QuickSortHelper(a, left + 1, hi);
}

void ArrayOfInt_QuickSort(ArrayOfInt *a) {
  ArrayOfInt_QuickSortHelper(a, 0, a->size);
}
