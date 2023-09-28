#include <iostream>

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

void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[middle + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;
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

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

void hybridSort(int arr[], int left, int right, int insertionThreshold) {
    if (left < right) {
        int size = right - left + 1;
        if (size <= insertionThreshold) {
            insertionSort(arr, left, right);
        } else {
            int middle = left + (right - left) / 2;
            hybridSort(arr, left, middle, insertionThreshold);
            hybridSort(arr, middle + 1, right, insertionThreshold);
            merge(arr, left, middle, right);
        }
    }
}

int main() {
    int size = 100;
    int minValue = 1;
    int maxValue = 1000;
    int insertionThreshold = 10;

    int* dynamicArray = generateRandomArray(size, minValue, maxValue);
    
    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;

    hybridSort(dynamicArray, 0, size-1, insertionThreshold);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;

    delete[] dynamicArray;

    return 0;
}