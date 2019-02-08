#if 0
/***************
 * bubbleSort *
 ***************/
void bubbleSort(int* arr, int size) {
    if (size <= 1) 
        return;
    for (int i = 0; i < size; ++i) {
        bool flag = false;
        for (int j = 0; j < size - i - 1; ++j) {
            flag = true;
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
        if (!flag) 
            break;
    }
}
#endif

#if 0
/*****************
 * insertionSort *
 *****************/
void insertionSort(int* arr, int size) {
    if (size <= 1)
        return;
    for (int i = 1; i < size; ++i) {
        int tmp = arr[i];
        int j = i - 1;
        for (; j >= 0; --j) {
            if (arr[j] > tmp)
                arr[j+1] = arr[j];
            else
                break;
        }
        arr[j+1] = tmp;
    }
}
#endif

#if 0
/**************
 * selectSort *
 **************/
void selectSort(int* arr, int size){
    if (size <= 1)
        return;
    for (int i = 0; i < size; ++i) {
        int min = i;
        for (int j = i+1; j < size; ++j) {
            if (arr[min] > arr[j])
                arr[min] = arr[j];
        }
        if (arr[i] != arr[min]) {
            int tmp = arr[min];
            arr[min] = arr[i];
            arr[i] = tmp;
        }
    }
}
#endif

#if 0
/*************
 * mergeSort *
 *************/
#include <cstring>
#include <assert.h>

using namespace std;

void merge(int *arr, int l_begin, int l_end, int r_begin, int r_end) {
    assert(l_begin <= l_end);
    assert(r_begin <= r_end);

    if (l_begin >= r_begin)
        return;

    int *tmp = new int[r_end - l_begin + 1];
    int i = 0;

    while (l_begin <= l_end && r_begin <= r_end) {
        if (arr[l_begin] > arr[r_begin]) {
            tmp[i++] = arr[r_begin++];
        }
        else {
            tmp[i++] = arr[l_begin++];
        }
    }

    while (l_begin <= l_end) {
        tmp[i++] = arr[l_begin++];
    }

    while (r_begin <= r_end) {
        tmp[i++] = arr[r_begin++];
    }

    // 陷阱
    memcpy(arr+l_begin, tmp, i);
    delete[] tmp;
}

void mergeSortCore(int *arr, int begin, int end) {
    if (begin >= end)
        return;

    size_t center = (end - begin) / 2 + begin;
    mergeSortCore(arr, begin, center);
    mergeSortCore(arr, center + 1, end);
    merge(arr, begin, center, center + 1, end);
}

void mergeSort(int *arr, int size) {
    mergeSortCore(arr, 0, size-1);
}
#endif

#if 0
/*************
 * quickSort *
 *************/

int partition(int *arr, int begin, int end) {
    int key = arr[end];
    int small = begin;
    int big = begin;

    while (big != end) {
        if (arr[big] < key) {
            swap(arr[big], arr[small]);
            small++;
        }
        big++;
    }

    swap(arr[small], key);

    return small;
}

void quickSortCore(int *arr, int begin, int end) {
    if (begin >= end)
        return;

    int division = partition(arr, begin, end);
    quickSortCore(arr, begin, division - 1);
    quickSortCore(arr, division + 1, end);
}

void quickSort(int *arr, int size) {
    quickSortCore(arr, 0, size-1);
}
#endif
