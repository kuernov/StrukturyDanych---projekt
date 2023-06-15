#include <iostream>
#include <queue>
#include <utility>
#include "Heap.h"

using namespace std;

Heap::Heap(int size) {
    max_size = size;
    act_size = 0;
    array = new int[size];
}

Heap::~Heap() {
    delete[] array;
}

int Heap::parent(int i) {
    return (i - 1) / 2;
}

int Heap::left(int i) {
    return (2 * i + 1);
}

int Heap::right(int i) {
    return (2 * i + 2);
}

void Heap::heapify_up(int i) {
    if (i == 0) return;
    if (array[i] > array[parent(i)]) {
        swap(array[i], array[parent(i)]);
    }
    heapify_up(parent(i));
}

void Heap::heapify_down(int i) {
    if (act_size == 0) return;
    int largest = i;
    if (left(i) < act_size && array[left(i)] > array[largest]) {
        largest = left(i);
    }
    if (right(i) < act_size && array[right(i)] > array[largest]) {
        largest = right(i);
    }
    if (largest == i) return;
    swap(array[i], array[largest]);
    heapify_down(largest);
}

void Heap::resize() {
    int* new_array;
    new_array = new int[max_size * 2];
    for (int i = 0; i < max_size; i++) {
        new_array[i] = array[i];
    }
    delete[] array;
    array = new_array;
    max_size *= 2;
}

void Heap::insert(int value) {
    if (act_size == max_size) {
        resize();
    }
    array[act_size] = value;
    heapify_up(act_size);
    act_size++;
}

void Heap::pop() {
    if (is_empty()) return;
    array[0] = array[--act_size];
    array[act_size] = 0;
    heapify_down(0);
}

void Heap::show() {
    int index = 0;
    if (index >= act_size) {
        cout << "heap is empty\n";
        return;
    }
    cout << "----\n";
    cout << array[index] << "\n";
    while (index < act_size / 2) {
        cout << array[left(index)] << "\n";
        if (array[right(index)] == 0) {
            break;
        }
        cout << array[right(index)] << "\n";
        index++;
    }
}

bool Heap::is_empty() {
    return act_size == 0;
}

int Heap::root() {
    if (is_empty()) return -1;



}

int Heap::search(int value) {
    return searchHelper(0, value);  // Start the search from the root (index 0)
}

int Heap::searchHelper(int index, int value) {
    if (index >= act_size) {
        return -1;  // Element not found
    }

    if (array[index] == value) {
        return getDepth(index);  // Return the depth of the element if found
    }

    if (value > array[index]) {
        int rightChildIndex = right(index);
        if (rightChildIndex < act_size && array[rightChildIndex] >= value) {
            return searchHelper(rightChildIndex, value);  // Search in the right subtree
        }
    }
    else {
        int leftChildIndex = left(index);
        if (leftChildIndex < act_size && array[leftChildIndex] >= value) {
            return searchHelper(leftChildIndex, value);  // Search in the left subtree
        }
    }

    return -1;  // Element not found
}

int Heap::getDepth(int index) {
    int depth = 0;
    while (index != 0) {
        index = parent(index);
        depth++;
    }
    return depth;
}

