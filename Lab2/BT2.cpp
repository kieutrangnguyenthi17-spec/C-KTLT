// // Viết hàm hoán vị vòng tròn 3 biến a, b, c. Sau khi thực hiện hàm, các biến a, b, c tương ứng nhận
// // các giá trị mới b, c, a.Viết hàm hoán vị vòng tròn 3 biến a, b, c. Sau khi thực hiện hàm, các biến a, b, c tương ứng nhận
// #include <stdio.h>
// void rotate(int &x, int &y, int &z) {
//  int temp=x;
//    x=y;
//    y=z;
//    z=temp;
// }
// int main() {
// int x, y, z;
// printf("Nhap 3 so nguyen: ");
// scanf("%d %d %d", &x, &y, &z);
// printf("Before: %d, %d, %d\n", x, y, z);
// rotate(x, y, z);
// printf("After: %d, %d, %d\n", x, y, z);
// return 0;
// }
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
void rotate(int &x, int &y, int &z) {
    /****************
        Ho va ten : Nguyen Thi Kieu Trang
        MSSV : 24133064
    */
    int tmp = x;
    x = y;
    y = z;
    z = tmp;
    /*****************/
}
int main() {
    printf("Ho Va Ten: Nguyen Thi Kieu Trang\n");
    printf("MSSV: 24133064\n\n");
    int x, y, z;

    //# Nhập 3 số nguyên
    /*****************/
    cin >> x >> y >> z;
    /*****************/

    printf("Before: %d, %d, %d\n", x, y, z);
    rotate(x, y, z);
    printf("After: %d, %d, %d\n", x, y, z);

    return 0;
}
