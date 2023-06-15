#pragma once

class Heap {
private:
    int act_size;
    int max_size;
    int* array;
    int parent(int i);
    int left(int i);
    int right(int i);
    void heapify_up(int i);
    void heapify_down(int i);
    void resize();

public:
    Heap(int size);

    ~Heap();

    void insert(int value);

    void pop();

    void show();

    bool is_empty();

    int root();
    
    int search(int value);
    int getDepth(int index);
    int searchHelper(int index, int value);
};

