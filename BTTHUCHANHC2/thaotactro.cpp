#include<stdio.h>
int main(){
    //Tạo biến a và b cùng các con trỏ (a_ptr) và (b_ptr) trỏ vào a và b
    int a=5, *a_ptr, b=10, *b_ptr;
    a_ptr=&a; //-> trỏ tới địa chỉ a -> a=5
    b_ptr=&b; //-> trỏ tới địa chỉ b -> b=10
    // Tương đương gán a=b
    *a_ptr=*b_ptr; 
}