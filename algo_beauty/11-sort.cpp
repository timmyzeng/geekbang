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
