#include <stdio.h>

/* 数组越界问题 */
/* arr[3] = 0 修改的位置正好是 i 的内存位置 */
/* 这样导致 i = 0，从而死循环 */
/* 这种情况其实跟编译器的内存管理有关 */
 
int main(){
    int i = 0;
    int arr[3] = {0};
    for(; i <= 3; ++i){
        arr[i] = 0;
        printf("hello world\n");
    }
    return 0;
}

