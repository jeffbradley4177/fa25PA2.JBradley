//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        //  insert index at end of heap, restore order using upheap()
        data[size] = idx;
        size++;
        upheap(size-1,weightArr);
    }

    int pop(int weightArr[]) {
        // remove and return smallest index

    }

    void upheap(int pos, int weightArr[]) {
        // swap child upward while smaller than parent
        int parent = (pos - 1) / 2;
        while (pos >0 && weightArr[pos] < weightArr[parent]) {
            swap(pos, parent);
            pos = parent;
            parent = (pos-1)/2;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
    }
};

#endif