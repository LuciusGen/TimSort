#include <iostream>

#define RUN 32
using namespace std;

//> - true < - false

template<typename ArrayType>
void insertionSort(ArrayType* arr, int left, int right, bool (*key)(ArrayType, ArrayType))
{
    for (int i = left + 1; i <= right; i++)
    {
        ArrayType temp = arr[i];
        int j = i - 1;

        while (key(arr[j], temp) && j >= left)  {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}


template<typename ArrayType>
void merge(ArrayType* arr, int l, int m, int r, bool (*key)(ArrayType, ArrayType)){
    int len1 = m - l + 1, len2 = r - m;

    ArrayType *left = new int [len1];
    ArrayType *right = new int [len2];

    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];

    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < len1 && j < len2)  {
        if (!key(left[i], right[j])){
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }

        k++;
    }

    while (i < len1) {
        arr[k] = left[i];
        k++;
        i++;
    }

    while (j < len2) {
        arr[k] = right[j];
        k++;
        j++;
    }

    delete [] left;
    delete [] right;
}

template<typename ArrayType>
void timSort(ArrayType *arr, size_t n, bool (*key)(ArrayType, ArrayType)){
    for (size_t i = 0; i < n; i+=RUN)
        insertionSort(arr, i, min((i+31), (n-1)), key);

    for (size_t size = RUN; size < n; size = 2*size) {
        for (size_t left = 0; left < n; left += 2*size)
        {
            size_t mid = left + size - 1;
            size_t right = min((left + 2*size - 1), (n-1));

            merge(arr, left, mid, right, key);
        }
    }
}
