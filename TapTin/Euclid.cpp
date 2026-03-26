// khai báo các thư viện cần thiết
#include<stdio.h>
#include<math.h>
// Định nghĩa cấu trúc lưu thông tin tọa độ
typedef struct // đặt tên khác cho dữ liệu - tên khác
{
    float x;
    float y;
} ToaDo;

// Định nghĩa các hàm cần thiết ở dạng mặt nạ (interface)
void NhapDiem(ToaDo &p);
void XuatDiem(ToaDo p);
float TinhKhoangCach(ToaDo a, ToaDo b);
void XuatKetQua(ToaDo a, ToaDo b);

//
void XuatDiem(ToaDo p)
{
    printf("Diem co toa do x = [%.3f], y=[%.3f]\n", p.x, p.y);
}

//
void NhapDiem(ToaDo &p){
    float gt_x, gt_y; // khởi tạo các biến chứa giá trị (x) và (y)
    printf("Nhap gia tri tai truc (x):");
    scanf("%f", &gt_x);
    printf("Nhap gia tri tai truc (y):");
    scanf("%f", &gt_y);
    // gán giá trị cho tọa độ (x) và (y)
    p.x=gt_x;
    p.y=gt_y;
    // xuất thông tin tọa độ của điểm vừa nhâp ra màn hình
    XuatDiem(p);
}

//cài đặt hàm tính khỏang cách giữa 2 điểm a và b
float TinhKhoangCach(ToaDo a, ToaDo b){
    // Euclid
    return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}

//cài đặt hàm xuất kq
void XuatKetQua(ToaDo a, ToaDo b){
    float khoang_cach=TinhKhoangCach(a,b);
    printf("Khoang cach Euclid giua hai diem (a) va (b) la: [%.3f]", khoang_cach);
}

int main(){
    ToaDo diem_a, diem_b;
    printf("Nhap diem (a):\n");
    NhapDiem(diem_a);
    printf("Nhap diem (b):\n");
    NhapDiem(diem_b);
    printf("---\n");

    XuatKetQua(diem_a, diem_b);
    return 0;
}


