#include "functions.h"
#include <stdexcept>
#include <iostream>
using namespace std;

// func to find index for number
int findIndex(int* arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// modify value function
void modifyValue(int* arr, int index, int newValue, int& oldValue, int size) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index is out of bounds");
    }
    oldValue = arr[index];
    arr[index] = newValue;
}

// add value to end of array
void addValue(int*& arr, int& size, int newValue) {
    int* newArr = new int[size + 1];

    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    newArr[size] = newValue;
    delete[] arr;
    arr = newArr;
    size++;
}

// remove index at number
void removeValue(int*& arr, int& size, int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index is out of bounds");
    }

    int* newArr = new int[size - 1];
    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) {
            newArr[j] = arr[i];
            j++;
        }
    }
    delete[] arr;
    arr = newArr;
    size--;
}