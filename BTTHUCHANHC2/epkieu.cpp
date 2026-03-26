#include<stdio.h>
int main(){
    // khai báo 1 biến kiểu float
    float a=10.5;
    // khai báo con trỏ kiểu(void- mặc định) -> trỏ đến biến (a)
    void *a_ptr=&a;
    printf("Gia tri cua bien (a) gian tiep qua con tro(a_ptr): %2f\n",*(float*)a_ptr);
    return 0;
}