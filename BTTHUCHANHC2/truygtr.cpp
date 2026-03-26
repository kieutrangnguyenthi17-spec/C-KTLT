#include<stdio.h>
int main(){
    float a= 10.5;
    float* a_ptr=&a;
    printf("Gia tri cua bien con tro (a_ptr): [%p]\n", a_ptr);
    printf("Gia tri cua bien (a): [%.3f]\n", a);
    printf("Gia tri cua bien (a)=[%.1f]\n", a);
    printf("Gia tri cua bien (a) gian tiep tiep qua con tro(a_ptr): [%.1f]", *a_ptr);
}

