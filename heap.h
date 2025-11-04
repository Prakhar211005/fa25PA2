//
// Created by Manju Muralidharan on 10/19/25.
// Modified by Prakhar Sahu
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) { // The operation to add a new element to the heap
        if (size >=64) return;
        data[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) { // The operation to remove the root element from the heap
        if (size == 0) return -1;
        int root = data[0];
        size--;
        data[0] = data[size];
        downheap(0, weightArr);
        return root;
    }

    void upheap(int pos, int weightArr[]) { // Used after inserting an element
        while (pos > 0) { // It starts with the newly inserted node and compares it with its parent. If the heap property is violated, they are swapped.
            int parent = (pos - 1) / 2; // This process repeats, moving the element upward in the tree along a single path until the heap property is satisfied or the element reaches the root.
            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                swap(data[pos], data[parent]);
                pos = parent;
            } else {
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) { // Used after the root has been replaced during a pop operation or during the initial heap construction.
        while (true) { // It starts with the element at the (new) root and compares it with its children. If the heap property is violated, it is swapped with the appropriate child.
            int left  = 2 * pos + 1; // This process repeats, moving the element downward along a path until it reaches a position where the heap property holds true or it reaches a leaf node.
            int right = 2 * pos + 2;
            int smallest = pos;

            if (left < size && weightArr[data[left]] < weightArr[data[smallest]])
                smallest = left;
            if (right < size && weightArr[data[right]] < weightArr[data[smallest]])
                smallest = right;

            if (smallest == pos) break;

            swap(data[pos], data[smallest]);
            pos = smallest;
        }
    }
};

#endif