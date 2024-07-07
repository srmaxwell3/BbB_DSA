#include <stdbool.h>
#include <stdlib.h>

typedef struct ArrayOfInt ArrayOfInt;
struct ArrayOfInt {
  size_t capacity;	// The current maximum size of this array
  size_t size;		// The current size of this array; size <= capacity
  int *values;		// The actual values.
};

// ArrayOfInt_Create(): Create a new array on the heap, with capacity
// == initialCapacity, and size == 0 (empty).
// O(1) space and O(1) time.
ArrayOfInt *ArrayOfInt_Create(size_t initialCapacity);

// ArrayOfInt_Destroty(): Destroy an array.
// O(1) space and time.
void ArrayOfInt_Destroy(ArrayOfInt *a);

// ArrayOfInt_GetCapacity(): Return the array's current capacity.
// O(1) space and O(1) time.
size_t ArrayOfInt_GetCapacity(ArrayOfInt *a);

// ArrayOfInt_SetCapacity(): Change the array's current capacity.
// O(1) space and O(1) time.
void ArrayOfInt_SetCapacity(ArrayOfInt *a, size_t newCapacity);

// ArrayOfInt_GetSize(): Return the array's current size.
// O(1) space and O(1) time.
size_t ArrayOfInt_GetSize(ArrayOfInt *a);

// ArrayOfInt_SetSize(): Change the array's current size; if necessary
// enlarge the array's capacity to accommodate the new size.
// O(1) space and O(1) time.
void ArrayOfInt_SetSize(ArrayOfInt *a, size_t size);

// ArrayOfInt_IsEmpty(): Return true if the array is empty, i.e. size
// == 0.
// O(1) space and O(1) time.
bool ArrayOfInt_IsEmpty(ArrayOfInt *a);

// ArrayOfInt_IsFull(): Return true if the array is full, i.e. size ==
// capacity.

// O(1) space and O(1) time.
bool ArrayOfInt_IsFull(ArrayOfInt *a);

// ArrayOfInt_At(): Return a pointer to the array's i'th element, if i
// < the array's size; otherwise announce an error, and exit.
// O(1) space and O(1) time.
int *ArrayOfInt_At(ArrayOfInt *a, size_t i);

// ArrayOfInt_GetAt(): Return the value of the array's i'th element.
// O(1) space and O(1) time.
int ArrayOfInt_GetAt(ArrayOfInt *a, size_t i);

// ArrayOfInt_SetAt(): Set the value of the array's i'th element to value.
// O(1) space and O(1) time.
void ArrayOfInt_SetAt(ArrayOfInt *a, size_t i, int value);

// ArrayOfInt_InsertAt(): Insert the value at the i'th position of the
// array, increasing the array's size by 1.

// O(1) space and (generally) O(N) time.
void ArrayOfInt_InsertAt(ArrayOfInt *a, size_t i, int value);

// ArrayOfInt_PushBack(): Append value to the end of the array,
// growing the array's size by 1.
// O(1) space and O(1) time.
void ArrayOfInt_PushBack(ArrayOfInt *a, int value);

// ArrayOfInt_PushFront(): Prepend value to the beginning of the
// array, growing the array's size by 1.
// O(1) space and O(1) time.
void ArrayOfInt_PushFront(ArrayOfInt *a, int value);

// ArrayOfInt_DeleteAt(): Delete the value at the i'th position of the
// array, decreasing the array's size by 1.
// O(1) space and (generally) O(N) time.
void ArrayOfInt_DeleteAt(ArrayOfInt *a, size_t i);

// ArrayOfInt_PopBack(): Delete the value from the end of the array,
// decreasing the array's size by 1.
// O(1) space and O(1) time.
void ArrayOfInt_PopBack(ArrayOfInt *a, int value);

// ArrayOfInt_PopFront(): Delete the value from the beginning of the
// array, decreasing the array's size by 1.
// O(1) space and O(1) time.
void ArrayOfInt_PopFront(ArrayOfInt *a, int value);

// ArrayOfInt_LinearSearch(): Assuming no ordering, search though the
// array for the provided value, returning its indoex (position).  If
// not found, return the size of the array (i.e. the position
// following the last element in the array).
// O(1) space, O(N) time.
size_t ArrayOfInt_LinearSearch(ArrayOfInt *a, int value);

// ArrayOfInt_BinarySearch(): Assuming ascending order, search though
// the array for the provided value, returning its indoex (position).
// If not found, return the size of the array (i.e. the position
// following the last element in the array).
// O(1) space, O(lg N) time.
size_t ArrayOfInt_BinarySearch(ArrayOfInt *a, int value);

// ArrayOfInt_BubbleSort(): Sorts the array using bubble-sort.
// O(1) space, minimum O(N), maximum O(N^2) time.
void ArrayOfInt_BubbleSort(ArrayOfInt *a);

// ArrayOfInt_QuickSort(): Sorts the array using quick-sort.
// O(1) space, minimum O(N), average O(N lg N), maximum O(N^2) time.
void ArrayOfInt_QuickSort(ArrayOfInt *a);
