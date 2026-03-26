#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void taomatran(int ***mt, int *m, int *n){
    printf("Nhap m:");
    scanf("%d",m);
    printf("Nhap n:");
    scanf("%d",n);
    *mt = (int**)malloc((*m)*sizeof(int*));
    for (int i=0;i<*m;i++){
        (*mt)[i] = (int*)malloc((*n)*sizeof(int));
    }
    srand(time(NULL));
    for (int i=0;i<*m;i++){
        for (int j=0;j<*n;j++){
            (*mt)[i][j]=rand() % 51; // chạy từ 0 -> 50        }
        }
    }
}
void inmatran(int **mt, int m, int n)
{
    printf("In ma tran:\n");
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            printf("%3d",mt[i][j]);
        }
        printf("\n");
    }
}
// chuyển ma trận thành mảng 1 chiều
int* chuyenmang1c(int **mt, int m, int n){
    int *a=(int*)malloc(m*n*sizeof(int));
    int k=0;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            a[k++]=mt[i][j];
        }
    }
    return a;
}
// xóa dòng có chứa x xuất hiện đầu tiên
void xoadongchuax(int ***mt, int *m, int n, int x){
    int dong =-1;
    for(int i=0;i<*m;i++){
        for(int j=0;j<n;j++){
            if((*mt)[i][j]==x){
                dong=i;
                break;
            }
        }
        if(dong!=-1) break;
    }
    if(dong==-1){
        printf("\n khong tim thay %d trong ma tran!", x);
        return;
    }
    free((*mt)[dong]);
    // dồn các dòng lên phía trên
    for(int i=dong;i<*m-1;i++){
        (*mt)[i]=(*mt)[i+1];
    }
    // thu nhỏ mảng
    *mt=(int**) realloc(*mt, (*m-1)*sizeof(int*));
    (*m)--;
    printf("\Da xoa dong %d\n", dong);
}
void them(int ***mt,int *m,int n){
    *mt = (int**)realloc(*mt, (*m + 1) * sizeof(int*));
    (*mt)[*m] = (int*)malloc(n * sizeof(int));
    
     for (int j = 0; j < n; j++)
        (*mt)[*m][j] = rand() % 51;

    (*m)++;
    printf("In mang moi them:");
    for (int i=0;i<*m;i++){
        for(int j=0;j<n;j++){
            printf("%3d ",(*mt)[i][j]);
        }
    }
}
int main(){
    int **mt;
    int m,n;
    //a)
    taomatran(&mt,&m,&n);
    inmatran(mt,m,n);
    //b)
    int *a = chuyenmang1c(mt, m, n);
    printf("\nMang 1 chieu a: ");
    for (int i = 0; i < m*n; i++) printf("%d ", a[i]);
    printf("\n");
     // c)
    int x;
    printf("\nNhap gia tri x de xoa dong: ");
    scanf("%d", &x);
    xoadongchuax(&mt, &m, n, x);
    inmatran(mt, m, n);
    // d)
    them(&mt, &m, n);
    inmatran(mt, m, n);

    // Giải phóng bộ nhớ
    for (int i = 0; i < m; i++)
        free(mt[i]);
    free(mt);
    free(a);

    return 0;
}

