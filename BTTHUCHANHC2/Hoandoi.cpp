#include <stdio.h>

void hoandoi1(int *x, int *y) {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}
void hoandoi2(int *x, int *y) {
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}
void hoandoi3(int *x, int *y) {
    int temp = *x;  // Lưu giá trị tại địa chỉ x
    *x = *y;        // Gán giá trị y vào x
    *y = temp;      // Gán giá trị tạm vào y
}
int main(){
    int x,y;
    printf("Nhập x: ");
    scanf("%d", &x);
    printf("Nhập y: ");
    scanf("%d",&y);
    hoandoi1(&x,&y);
    printf("Sau khi hoan doi: x = %d, y = %d\n", x, y);
    return 0;


}