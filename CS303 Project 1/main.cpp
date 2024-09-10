#include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;

int main() {
    int* arr = nullptr;   // create array
    int size = 0;
    int choice;

    ifstream inputFile("A1input.txt");
    if (!inputFile) {
        cerr << "Error: Could not open the file. Please check the file path." << endl;
        return 1;
    }

    int tempValue;
    while (inputFile >> tempValue) {
        addValue(arr, size, tempValue);
    }
    inputFile.close();

    // mennu for options
    do {
        cout << "\nMenu:\n";
        cout << "1. Find the index of a value in the array\n";
        cout << "2. Modify the value at a given index\n";
        cout << "3. Add a new integer to the end of the array\n";
        cout << "4. Remove a value at a given index\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // cases
        switch (choice) {
        case 1: {
            int value;
            cout << "Enter value to search: ";
            cin >> value;

            int index = findIndex(arr, size, value);
            if (index != -1) {
                cout << "Value " << value << " is at index " << index << ".\n";
            }
            else {
                cout << "Value " << value << " is not found.\n";
            }
            break;
        }
        case 2: {
            int index, newValue, oldValue;
            cout << "Enter index to modify (0 to " << size - 1 << "): ";
            cin >> index;

            if (index < 0 || index >= size) {
                cout << "Error: Index out of range. Current size of array is " << size << ".\n";
            }
            else {
                cout << "Enter new value: ";
                cin >> newValue;

                try {
                    modifyValue(arr, index, newValue, oldValue, size);
                    cout << "Value at index " << index << " was changed from " << oldValue << " to " << newValue << ".\n";
                }
                catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
            }
            break;
        }
        case 3: {
            int newValue;
            cout << "Enter new value to add to end of array: ";
            cin >> newValue;

            addValue(arr, size, newValue);
            cout << "Added new value " << newValue << " to array. New array size: " << size << ".\n";
            break;
        }
        case 4: {
            int index;
            cout << "Enter index to remove (0 to " << size - 1 << "): ";
            cin >> index;

            if (index < 0 || index >= size) {
                cout << "Error: Index out of range. The current size of array is " << size << ".\n";
            }
            else {
                try {
                    removeValue(arr, size, index);
                    cout << "Removed value at index " << index << ". New array size: " << size << ".\n";
                }
                catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
            }
            break;
        }
        case 5:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please select a valid option from menu.\n";
        }
    } while (choice != 5);

    delete[] arr;

    return 0;
}