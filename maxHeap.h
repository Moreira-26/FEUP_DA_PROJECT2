//
// Created by moreira on 25-05-2022.
//

#ifndef DA_PROJECT2_MAXHEAP_H
#define DA_PROJECT2_MAXHEAP_H

#include <vector>
#include <unordered_map>
#include <iostream>

#define LEFT(i) (2*(i))
#define RIGHT(i) (2*(i)+1)
#define PARENT(i) ((i)/2)

using namespace std;

// Binary max-heap to represent integer keys of type K with values (priorities) of type V
template <class K, class V>
class MaxHeap {
    struct Node { // An element of the heap: a pair (key, value)
        K key;
        V value;
    };

    int size;                  // Number of elements in heap
    int maxSize;               // Maximum number of elements in heap
    vector<Node> a;            // The heap array
    unordered_map<K, int> pos; // maps a key into its position on the array a
    const K KEY_NOT_FOUND;

    /**
     * Makes a value go up the tree until it reaches it's position
     * @param i
     */
    void upHeap(int i);

    /**
     * Makes a value go down the tree until it reaches it's position
     * @param i
     */
    void downHeap(int i);

    /**
     * Changes two positions in the heap (updates their positions)
     * @param i1
     * @param i2
     */
    void swap(int i1, int i2);

public:
    /**
     * Constructor of the MaxHeap class
     * @param n maximum size of the heap
     * @param notFound
     */
    MaxHeap(int n, const K& notFound); // Create a min-heap for a max of n pairs (K,V) with notFound returned when empty

    /**
     *
     * @return Number of elements of the heap
     */
    int getSize();

    /**
     * This method indicates if the key has a value
     * @param key
     * @return true if it has
     */
    bool hasKey(const K& key);

    /**
     * This method insertts (key,value) in the heap
     * @param key
     * @param value
     */
    void insert(const K& key, const V& value);

    /**
     * Este método aumenta o valor de uma key
     * @param key
     * @param value
     */
    void increaseKey(const K& key, const V& value);

    /**
     * his method removes and returnes the key with the highest value
     * @return the key with the highest value
     */
    K removeMax();
};



template <class K, class V>
void MaxHeap<K,V>::upHeap(int i) {
    while (i>1 && a[i].value > a[PARENT(i)].value) { // while pos bigger than parent, keep swapping to upper position
        swap(i, PARENT(i));
        i = PARENT(i);
    }
}


template <class K, class V>
void MaxHeap<K,V>::downHeap(int i) {
    while (LEFT(i) <= size) { // while within heap limits
        int j = LEFT(i);
        if (RIGHT(i)<=size && a[RIGHT(i)].value > a[j].value) j = RIGHT(i);
        if (a[i].value > a[j].value) break;
        swap(i, j);
        i = j;
    }
}

template <class K, class V>
void MaxHeap<K,V>::swap(int i1, int i2) {
    Node tmp = a[i1]; a[i1] = a[i2]; a[i2] = tmp;
    pos[a[i1].key] = i1;
    pos[a[i2].key] = i2;
}


template <class K, class V>
MaxHeap<K,V>::MaxHeap(int n, const K& notFound) : KEY_NOT_FOUND(notFound), size(0), maxSize(n), a(n+1) {

}

template <class K, class V>
int MaxHeap<K,V>::getSize() {
    return size;
}


template <class K, class V>
bool MaxHeap<K, V>::hasKey(const K& key) {
    return pos.find(key) != pos.end();
}


template <class K, class V>
void MaxHeap<K,V>::insert(const K& key, const V& value) {
    if (size == maxSize) return; // heap is full, do nothing
    if (hasKey(key)) return;     // key already exists, do nothing
    a[++size] = {key, value};
    pos[key] = size;
    upHeap(size);
}

template <class K, class V>
void MaxHeap<K,V>::increaseKey(const K& key, const V& value) {
    if (!hasKey(key)) return; // key does not exist, do nothing
    int i = pos[key];
    if (value < a[i].value) return; // value would increase, do nothing
    a[i].value = value;
    upHeap(i);
}

template <class K, class V>
K MaxHeap<K,V>::removeMax() {
    if (size == 0) return KEY_NOT_FOUND;
    K max = a[1].key;
    pos.erase(max);
    a[1] = a[size--];
    downHeap(1);
    return max;
}

#endif //DA_PROJECT2_MAXHEAP_H
