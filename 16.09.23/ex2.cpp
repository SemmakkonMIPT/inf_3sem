#include <iostream>
#include <ctime>   // Для инициализации генератора случайных чисел
#include <cstdlib> // Для работы с функцией rand()

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

/*
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
}*/

void insertionSort(int* arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        for (int j = i; j > left && arr[j] < arr[j - 1]; j--) {
            // Swap arr[j] и arr[j-1]
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
        }
    }
}

int main() {
    int size = 10;
    int minValue = 1;
    int maxValue = 100;

    int* dynamicArray = generateRandomArray(size, minValue, maxValue);
    
    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;

    insertionSort(dynamicArray, 0, size-1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;

    delete[] dynamicArray;

    return 0;
}
