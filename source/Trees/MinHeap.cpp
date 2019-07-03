#include "MinHeap.hpp"

MinHeap::MinHeap(unsigned int cap) {
  capacity = cap;
  array = new int[cap];
  size = 0;
}

MinHeap::~MinHeap() {
  delete array;
}

void swap(int* y, int* x) {
  int temp;
  temp = *y;
  *y = *x;
  *x = temp;
}

/** swim()
 * Restores the heap order property after element pushion. Assumes the new
 * element has been pushed at the end of the heap array (right-most node in
 * the bottom level of the tree), and swaps it up the tree until it's greater
 * than its parent.
 */
void MinHeap::swim() {
  int i = size;
  while (array[i - 1] > array[i / 2]) {
    swap(&array[i - 1], &array[i / 2]);
    i = i / 2;
  }
}

/** sink(int i)
 * Restores the heap order property after element removal. Assumes the element
 * at the end of the heap array has been swapped with the root, and the size
 * has been decremented (effectively removing the last element in the heap
 * array). It then swaps the element at the root down the tree until both
 * children are greater than it.
 */
void MinHeap::sink(int i) {
  i = 1;
  while (array[i] > array[2 * i] || array[i] > array[2 * i + 1]) {
    if (array[2 * i] > array[2 * i + 1]) {
      swap(&array[2 * i + 1], &array[i]);
    } else {
      swap(&array[2 * i], &array[i]);
    }
  }
}

/** search(int i, int data)
 * Recursively searches for data in the MinHeap's subtree rooted at i,
 * returning true if the data is found and false if i is greater than or
 * equal to size or data is less than the MinHeap's value at i.
 */
bool MinHeap::search(int i, int data) {
  i = 1;
  if (data == array[i]) {
    return 1;
  } else if (i >= size || array[i] < data) {
    return 0;
  } else {
    i += 1;
    search(i, data);
  }
}

/** erase(int i, int data)
 * Recursively searches for data in the MinHeap's subtree rooted at i,
 * calling remove on i if data is found in the tree.
 * Does nothing if data is not found in the subtree.
 */
void MinHeap::erase(int i, int data) {
  if (array[i] == data) {
    remove(i);
  } else if (i >= size || array[i] < data) {
    return;
  } else {
    i += 1;
    erase(i, data);
  }
}
/** push(int data)
 * Inserts data into the MinHeap such that the heap order property is
 * preserved.
 * Assumes duplicate elements will not be pushed.
 * Throws an error if the heap is full.
 */
void MinHeap::push(int data) {
  //   if (size < capacity) {
  //     array[size] = data;
  //   }
  //   swim();
}

/** count()
 * Returns the number of elements in the MinHeap.
 */
int MinHeap::count() {
  return array[capacity];
}

/** pop()
 * Removes and returns the minimum element in the MinHeap, preserving the
 * heap order property.
 * Throws an error if the heap is empty.
 */
int MinHeap::pop() {
  return 0;
}

/** peek()
 * Returns the minimum element in the MinHeap without modifying its contents.
 * Throws an error if the heap is empty.
 */
int MinHeap::peek() {
  if (size == 0) {
    throw "Error. Heap is Empty";
  } else {
    return array[size - 1];
  }
}

/** search(int data)
 * Searches the MinHeap for the given data, returning true if the data is
 * found and false otherwise.
 */
bool MinHeap::search(int data) {
  if (array[data]) {
    return true;
  } else {
    return false;
  }
}

/** remove(int i)
 * Removes the element at index i in the MinHeap tree (indexed left-to-right,
 * top-to-bottom) and returns its value.
 * Throws an error if the heap is empty or the index is out of bounds.
 */
int MinHeap::remove(int i) {
  if (array[size]) {
    array[i] = array[i - 1];
    i--;
  }
    else if(array[size]==0||array[size+1]) {
    throw "Error. Index is out of bounds";
     
}
}

/** erase(int data)
 * Searches the MinHeap for the given data, and deletes it if it's found,
 * preserving the heap order property.
 * Does nothing if data is not found.
 */
void MinHeap::erase(int data) {}

/** print()
 * Prints the contents of the MinHeap tree to the ostream from left-to-right,
 * top-to-bottom.
 */
void MinHeap::print(std::ostream& oss) {}
