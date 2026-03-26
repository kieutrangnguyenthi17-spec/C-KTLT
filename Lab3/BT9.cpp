// Một y tá cần lập lịch làm việc trong N ngày, mỗi ngày chỉ có thể là làm việc hay nghỉ ngơi. Một
// lịch làm việc là tốt nếu không có hai ngày nghỉ nào liên tiếp và mọi chuỗi ngày tối đại làm việc liên
// tiếp đều có số ngày thuộc đoạn [K1,K2]. Hãy liệt kê tất cả các cách lập lịch tốt, với mỗi lịch in ra
// trên một dòng một xâu nhị phân độ dài n với bit 0/1 tương ứng là nghỉ/làm việc. Các xâu phải được
// in ra theo thứ tự từ điển
// Dữ liệu vào:
// Ghi 3 số nguyên N,K1,K2 (N≤200,K1<K2≤70)
// Kết quả:
// Ghi danh sách các lịch tìm được theo thứ tự từ điển
// Ví dụ:

// Dữ liệu mẫu:
// 6 2 3
// Kết quả mẫu:
// 011011
// 110110
// 110111
// 111011
#include <iostream>
using namespace std;

int N, K1, K2;
string s;

void TRY(int i, int last, int cnt1) {
    if (i == N) {
        if (last == 1) {
            if (cnt1 < K1 || cnt1 > K2) return;
        }
        cout << s << '\n';
        return;
    }
    if (last != 0) {
        if (last == 1) {
            if (cnt1 >= K1 && cnt1 <= K2) {
                s[i] = '0';
                TRY(i + 1, 0, 0);
            }
        } else {
            s[i] = '0';
            TRY(i + 1, 0, 0);
        }
    }
    if (cnt1 + 1 <= K2) {
        s[i] = '1';
        TRY(i + 1, 1, cnt1 + 1);
    }
}

int main() {
    cin >> N >> K1 >> K2;
    s.resize(N);
    TRY(0, -1, 0);
    return 0;
}
