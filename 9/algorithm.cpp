#include "algorithm.hpp"

void max_sum_range(int arr[], int size)
{
    int max_sum = INT_MIN, max_sum_temp = 0, start = 0, end = 0, start_temp = 0;

    for (int i = 0; i < size ; i++){
        max_sum_temp += arr[i];

        if (max_sum < max_sum_temp){
            max_sum = max_sum_temp;
            start = start_temp;
            end = i;
        }
        
        if(max_sum_temp < 0){
            max_sum_temp = 0;
            start_temp = i + 1;
        }
    }

    std::cout << "Максимальная сумма: " << max_sum <<std::endl;
    std::cout << "Начало: " << start << std::endl;
    std::cout << "Конец: " << end << std::endl;
}

void test_max_sum_range()
{
// Test 1
    printf("\e[32mTEST#1\e[0m\n");
    printf("Массив: ");
    int first_array[] = {4, -7, 5, -1, 8};
    int size = sizeof(first_array)/sizeof(first_array[0]);
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", first_array[i]);
    }
    printf("\n");
    max_sum_range(first_array, size);
    printf("\n");

// Test 2
    printf("\e[32mTEST#2\e[0m\n");
    printf("Массив: ");
    int second_array[] = {6, 0, -18, 20, 1, 15, -228, 1512, 444};
    int size2 = sizeof(second_array)/sizeof(second_array[0]);
    for (int i = 0; i < size2; i++) 
    {
        printf("%d ", second_array[i]);
    }
    printf("\n");
    max_sum_range(second_array, size2);
    printf("\n");

// Test 3
    printf("\e[32mTEST#3\e[0m\n");
    printf("Массив: ");
    int third_array[] = {67, 20, -148, -240, 11, 15, -2280, 15, 10};
    int size3 = sizeof(third_array)/sizeof(third_array[0]);
    for (int i = 0; i < size3; i++) 
    {
        printf("%d ", third_array[i]);
    }
    printf("\n");
    max_sum_range(third_array, size3);
}