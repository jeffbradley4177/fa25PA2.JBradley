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
        int mindIdx = data[0];
        data[0] = data[size-1];
        size--;
        downheap(0,weightArr);
        return minIdx;
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
        //swap parent downward while larger than any child
        int left = 2 * pos + 1;
        int right = 2 * pos + 2;
        int smallest = pos;
        if (left < size && weightArr[left] < weightArr[pos]) {
            smallest = left;
        }
        if (right < size && weightArr[right] > weightArr[pos]) {
            smallest = right;
        }
        while (smallest != pos) {
            swap(data[pos], data[smallest]);
            pos = smallest;
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            smallest = pos;
            if (left < size && weightArr[left] < weightArr[pos]) {
                smallest = left;
            }
            if (right < size && weightArr[right] > weightArr[pos]) {
                smallest = right;
            }
        }
    }
};

#endif