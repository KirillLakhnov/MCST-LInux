#ifndef MERGESORT_H
#define MERGESORT_H

#include <stdio.h>
#include <assert.h>
#include <pthread.h>

struct SortParams {
    int* array;

    int left;
    int right;
};

void* mergesort(void* params);

void merge(int array[], int left, int middle, int right);

void test_mergesort();

#endif //MERGESORT_H