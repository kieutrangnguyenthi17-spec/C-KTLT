#include<stdio.h>
int main(){
    int mt[3][3]={{1,2,3},{4,5,6},{7,8,9}}, n=3, m=3;
    int *mt_ptr = mt[0];
    int count=0;
    printf("Ma tran (mt): \n");
    for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < m; j++)
            {  
             // printf("%d",*(mt[i]+j));  
              printf("%d",*(mt_ptr +count));
              count +=1;
            }
            printf("\n");
   }
}