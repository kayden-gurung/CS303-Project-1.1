#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// defining functions for programs
int findIndex(int* arr, int size, int value);

void modifyValue(int* arr, int index, int newValue, int& oldValue, int size);

void addValue(int*& arr, int& size, int newValue);

void removeValue(int*& arr, int& size, int index);

#endif