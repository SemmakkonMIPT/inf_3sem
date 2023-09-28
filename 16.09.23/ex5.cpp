#include <iostream>
#include <ctime>   // Для инициализации генератора случайных чисел
#include <cstdlib> // Для работы с функцией rand()

auto input(){
    int i{};
    std::cin >> i;
    return i;
}


int getRandomNumber(int min, int max) {
    return min + (rand() % (max - min + 1));
}

int* generateRandomArray(int size, int minValue, int maxValue) {
    if (size <= 0) {
        return nullptr;
    }

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned>(time(0)));

    int* dynamicArray = new int[size];

    for (int i = 0; i < size; i++) {
        dynamicArray[i] = getRandomNumber(minValue, maxValue);
    }

    return dynamicArray;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void freeArray(int* arr) {
    delete[] arr; // Освобождаем память
}

void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
/*
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (arr[middle] < target) {
            left = middle + 1;
        } else if (arr[middle] > target) {
            right = middle - 1;
        } else {
            return middle;
        }
    }

    return -1;
}*/

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        auto middle = left + (right - left) / 2;

        if (arr[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return (left <= size - 1 && arr[left] == target) ? left : -1;
}

int main() {
    int size = 30;
    int minValue = 1;
    int maxValue = 50;

    int* dynamicArray = generateRandomArray(size, minValue, maxValue);
    insertionSort(dynamicArray, 0, size-1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;

    int target = input();

    int result = binarySearch(dynamicArray, size, target);

    if (result != -1) {
        std::cout << "Value " << target << " found at position " << result << std::endl;
    } else {
        std::cout << "Value " << target << " not found in the array." << std::endl;
    }

    return 0;
}
