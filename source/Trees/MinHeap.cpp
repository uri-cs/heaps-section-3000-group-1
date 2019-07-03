#include "MinHeap.hpp"
#include <iostream>

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

MinHeap::MinHeap(unsigned int cap) {
    arr = new int[cap] {0};
    capacity = cap;
    size = 0;
}

MinHeap::~MinHeap() {
    delete[] arr;
}

void MinHeap::swim() {
    int pos = size;
    while (pos > 0 && arr[pos] < arr[pos/2]) {
        swap(&arr[pos/2], &arr[pos]);
        pos = pos / 2;
    }
    print();
}

void MinHeap::sink(int i) {
    int pos = i;
    while (pos <= size && (arr[pos] > arr[2 * pos] || arr[pos] > arr[2 * pos + 1])) {
        (arr[2 * pos] < arr[2 * pos + 1]) ? swap(&arr[pos], &arr[2 * pos]) : swap(&arr[pos], &arr[2 * pos + 1]);
        pos = (arr[2 * pos] < arr[2 * pos + 1]) ? (2 * pos) : (2 * pos + 1);
    }
}

bool MinHeap::search(int i, int data) {
    if (i > size || data < arr[i]) return false;
    if (data == arr[i]) return true;
    return search(2 * i, data) || search(2 * i + 1, data);
}

void MinHeap::erase(int i, int data) {
    if (i > size || data < arr[i]) return;
    if (data == arr[i]) remove(i);
    erase(2 * i, data);
    erase(2 * i + 1, data);
}

void MinHeap::push(int data) {
    if (size == capacity) {
        int* newArr = new int[2 * capacity];
        for (int i = 1; i <= size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity *= 2;
    }
    arr[size++] = data;
    swim();
}

int MinHeap::count() {
    return size;
}

int MinHeap::pop() {
    if (!count()) throw "Empty!";
    int to_remove = arr[size];
    swap(&arr[1], &arr[size--]);
    sink(1);
    return to_remove;
}

int MinHeap::peek() {
    if (!count()) throw "Empty!";
    return arr[1];
}

bool MinHeap::search(int data) {
    if (!count()) throw "Empty!";
    return search(1, data);
}

int MinHeap::remove(int i) {
    if (!count() || i > size || i < 1) throw "Empty!";
    int to_remove = arr[i];
    swap(&arr[i], &arr[size--]);
    sink(i);
    return to_remove;
}

void MinHeap::erase(int data) {
    if (!count()) throw "Empty!";
    erase(1, data);
}

void MinHeap::print(std::ostream& oss) {
    for (int i = 0; i <= size; i++) {
        oss << arr[i] << ", ";
    }
    oss << "\n";
}