#include<stdio.h>
void Swap(int* a_ptr, int* b_ptr){
    // luu tam gia tri
    int tmp=*a_ptr;
    *a_ptr=*b_ptr;
    *b_ptr=tmp;
}

int main(){
    int a=5, b=10;
    Swap(&a, &b);
    printf("Gia tri(a)=[%d] va (b) = [%d]",a,b);
}