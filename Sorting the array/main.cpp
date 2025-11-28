
#include <iostream>
using namespace std;

// Функція для виводу масиву
void PrintArray(int* arr, int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int array[] = { 0, 1, 3, 4, 5, 2, 1, -4, -1, 10, 55 };
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Block 1:" << endl;
    for(int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;

    cout << "Block 2:" << endl;
    for(int i = size - 1; i >= 0; i--)
        cout << array[i] << " ";
    cout << endl;

    cout << "Block 3:" << endl;
    for(int i = 0; i < size; i++)
        if(array[i] % 2 == 0)
            cout << array[i] << " ";
    cout << endl;

    cout << "Block 4:" << endl;
    for(int i = 0; i < size; i += 2)
        cout << array[i] << " ";
    cout << endl;

    cout << "Block 5:" << endl;
    for(int i = 0; i < size; i++) {
        if(array[i] == -1)
            break;
        cout << array[i] << " ";
    }
    cout << endl;

    size = 5;
    int* dynArray = new int[size]{ 10, 20, 30, 40, 50 };

    cout << "\nOriginal array: ";
    PrintArray(dynArray, size);

    {
        int value = 99;
        int* bigger = new int[size + 1];
        for(int i = 0; i < size; i++)
            bigger[i] = dynArray[i];
        bigger[size] = value;
        size++;
        delete[] dynArray;
        dynArray = bigger;
        cout << "Block 1 (add to end): ";
        PrintArray(dynArray, size);
    }

    {
        int value = 77;
        int* bigger = new int[size + 1];
        bigger[0] = value;
        for(int i = 0; i < size; i++)
            bigger[i + 1] = dynArray[i];
        size++;
        delete[] dynArray;
        dynArray = bigger;
        cout << "Block 2 (add to start): ";
        PrintArray(dynArray, size);
    }

    {
        int value = 88;
        int position = 4;
        int* bigger = new int[size + 1];
        for(int i = 0; i < position; i++)
            bigger[i] = dynArray[i];
        bigger[position] = value;
        for(int i = position; i < size; i++)
            bigger[i + 1] = dynArray[i];
        size++;
        delete[] dynArray;
        dynArray = bigger;
        cout << "Block 3 (add at position 4): ";
        PrintArray(dynArray, size);
    }

    {
        int* smaller = new int[size - 1];
        for(int i = 0; i < size - 1; i++)
            smaller[i] = dynArray[i];
        size--;
        delete[] dynArray;
        dynArray = smaller;
        cout << "Block 4 (remove last): ";
        PrintArray(dynArray, size);
    }

    {
        int* smaller = new int[size - 1];
        for(int i = 1; i < size; i++)
            smaller[i - 1] = dynArray[i];
        size--;
        delete[] dynArray;
        dynArray = smaller;
        cout << "Block 5 (remove first): ";
        PrintArray(dynArray, size);
    }

    {
        int position = 2;
        int* smaller = new int[size - 1];
        for(int i = 0, j = 0; i < size; i++) {
            if(i == position)
                continue;
            smaller[j++] = dynArray[i];
        }
        size--;
        delete[] dynArray;
        dynArray = smaller;
        cout << "Block 6 (remove at position 2): ";
        PrintArray(dynArray, size);
    }

    {
        int arr1[] = {1, 2, 3};
        int arr2[] = {4, 5, 6};
        int newSize = 6;
        int* merged = new int[newSize];
        for(int i = 0; i < 3; i++)
            merged[i] = arr1[i];
        for(int i = 0; i < 3; i++)
            merged[3 + i] = arr2[i];
        cout << "Block 7 (merge arrays): ";
        PrintArray(merged, newSize);
        delete[] merged;
    }

    delete[] dynArray;
    return 0;
}
