#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

void old(int *a, int n){
    printf("Cac so le: ");
    for(int i=0;i<n;i++){
        if(*(a+i)%2!=0){
            printf("%d ",*(a+i));
        }
    }
    printf("\n");
}
void tt(int *a, int n, int x){
    a[n-1] = x;  
    printf("Mang sau khi thay the x vao cuoi: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int maxnum(int *a, int n){
    int max=*(a+0);
    for(int i=0;i<n;i++){
        if(*(a+i)>max){
            max=*(a+i);
        }
    }
    return max;
 
}
void xoa(int *a, int *n, int index) {
    if (index < 0 || index >= *n) return;  // kiểm tra vị trí hợp lệ

    for (int i = index; i < *n - 1; i++) {
        *(a + i) = *(a + i + 1);
    }
    (*n)--; 
}
void xoamax(int *a, int *n){
    int max = maxnum(a, *n);
    for(int i=0; i<*n; ){
        if(*(a+i) == max){
            xoa(a, n, i); 
            break;
        } else {
            i++;
        }
    }
    printf("Mang sau khi xoa max: ");
    for(int i=0; i<*n; i++){
        printf("%d ", *(a+i));
    }
    printf("\n");
}


bool snt(int n){
    if(n<2) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
void xsnt(int *a, int *n){
    for(int i=0;i<*n;i++){
        if(snt(*(a+i))){
            xoa(a,n,i);
            break;
        } else {
            i++;
        }
    }
    printf("Mang sau khi xoa so nguyen to: ");
     for (int i = 0; i < *n; i++) {
        printf("%d ", *(a+i));
    }
    printf("\n");
}
int main(){
    
    int n,x;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    int *a = (int*) malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Cap phat bo nho that bai!\n");
        return 1;
    }

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);  // Hoặc scanf("%d", arr + i);
    }
    old(a,n);
    printf("Nhap x:");
    scanf("%d",&x);
    tt(a,n,x);
    xoamax(a,&n);
    xsnt(a,&n);
    free(a);
    return 0;
}
