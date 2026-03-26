// Sử dụng phương pháp khử đệ quy bằng stack, hãy liệt kê các xâu nhị phân độ dài n không có k bit
// 1 nào liên tiếp
// Dữ liệu vào:
// Một dòng duy nhất chứa hai số nguyên n k (1≤k≤n≤20)
// Kết quả:
// Với mỗi xâu tìm được, in ra n ký tự trên một dòng, các ký tự cách nhau bởi dấu cách. Các xâu cần
// được liệt kê theo thứ tự từ điển
// Ví dụ:
// Dữ liệu mẫu:
// 4 2
// Kết quả mẫu:
// 0 0 0 0
// 0 0 0 1
// 0 0 1 0
// 0 1 0 0
// 0 1 0 1
// 1 0 0 0
// 1 0 0 1
// 1 0 1 0
// Lời giải đệ quy:
// // Giả sử lời giải được lưu bởi xâu x1, x2, ..., xn
// // i : biểu diễn lời giải bộ phận cấp i, trước đó x1, x2, ..., x[i-1] đã
// được gán giá trị
// // j : giá trị ứng cử viên đang xét cho vị trí x[i]
// // old_L: số ký tự 1 liên tiếp ở cuối dãy x1, x2, ..., x[i-1]

// void TRY(int i, int j, int old_L){
// x[i] = j;
// if (i == n) {print_sol(); return;}
// int L = j ? ++old_L : 0;
// TRY(i + 1, 0, L);
// if (L + 1 < K) TRY(i + 1, 1, L);
// }
// In [ ]:
#include <iostream>
#include <stack>
using namespace std;

struct state {
    int i, j, old_L;
    state(int _i = 0, int _j = 0, int _L = 0) : i(_i), j(_j), old_L(_L) {}
};

int main() {
    int n, k;
    cin >> n >> k;
    int* x = new int[n + 1]; 
    stack<state> s;

    s.push(state(1, 0, 0));

    while (!s.empty()) {
        state &top = s.top();

        if (top.i > n) {
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n];
            s.pop();
            continue;
        }

        x[top.i] = 0;
        int new_L = (top.j == 0) ? 0 : top.old_L + 1;
        if (new_L < k) {
            s.push(state(top.i + 1, 0, new_L));
        }

        if (new_L + 1 < k) {
            x[top.i] = 1;
            s.push(state(top.i + 1, 1, new_L + 1));
        }

        s.pop();
    }
    return 0;
}
