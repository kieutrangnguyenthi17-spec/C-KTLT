#include <iostream>
using namespace std;

int main() {
    int *p = new int(5);
    int *q = p;

    delete p;   // giải phóng vùng nhớ mà cả p và q đang trỏ tới

    cout << *q; // truy cập con trỏ treo (dangling pointer) -> lỗi hành vi không xác định

    return 0;
}
