#include "mergesort.h"

void merge(int array[], int left, int middle, int right) 
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int left_arr[n1], right_arr[n2];

    for (int i = 0; i < n1; i++)
        left_arr[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        right_arr[j] = array[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) 
    {
        if (left_arr[i] <= right_arr[j]) 
        {
            array[k] = left_arr[i];
            i++;
        } 
        else 
        {
            array[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        array[k] = left_arr[i];
        i++;
        k++;
    }
    while (j < n2) 
    {
        array[k] = right_arr[j];
        j++;
        k++;
    }
}

void* mergesort(void *params) 
{
    assert(params);

    struct SortParams* sort_params = (struct SortParams*)params;

    int left = sort_params->left;
    int right = sort_params->right;
    int* array = sort_params->array;

    if (left < right) 
    {
        int middle = left + (right - left)/2;

        struct SortParams left_params = {array, left, middle};
        struct SortParams right_params = {array, middle + 1, right};

        pthread_t left_thread, right_thread;
        pthread_create(&left_thread, NULL, mergesort, &left_params);
        pthread_create(&right_thread, NULL, mergesort, &right_params);

        pthread_join(left_thread, NULL);
        pthread_join(right_thread, NULL);

        merge(array, left, middle, right);
    }

    pthread_exit(0);
}

void test_mergesort()
{
    // Test 1
    int arr[] = {39, 43, 25, 1, 7, 12, 87};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("\e[32mTEST#1\e[0m\n");
    printf("Массив: ");
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    struct SortParams params = {arr, 0, size - 1};

    pthread_t sort_thread;
    pthread_create(&sort_thread, NULL, mergesort, &params);
    pthread_join(sort_thread, NULL);

    printf("Отсортированный массив: ");
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Test 2
    int arr1[] = {3, 7, 43, 23, 56, 12, 127, 120, 5, 99};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);

    printf("\e[32mTEST#2\e[0m\n");
    printf("Массив: ");
    for (int i = 0; i < size1; i++) 
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    struct SortParams params1 = {arr1, 0, size1 - 1};

    pthread_t sort_thread1;
    pthread_create(&sort_thread1, NULL, mergesort, &params1);
    pthread_join(sort_thread1, NULL);

    printf("Отсортированный массив: ");
    for (int i = 0; i < size1; i++) 
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
}