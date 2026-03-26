//Cài đặt bài toán 8 con hậu.
/**/
#include <iostream>
#include <cmath>
using namespace std;

const int N = 8;
int board[N]; // Lưu vị trí quân hậu ở từng hàng
int countSolution = 0;

// Kiểm tra vị trí (row, col) có an toàn không
bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        // Cùng cột hoặc cùng đường chéo
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

// Đặt quân hậu bắt đầu từ hàng 'row'
void solve(int row) {
    if (row == N) {
        // Đã đặt đủ 8 quân hậu, in ra lời giải
        countSolution++;
        cout << "Loi giai thu " << countSolution << ":\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i] == j) cout << "Q ";
                else cout << ". ";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }
    
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {    // Nếu an toàn
            board[row] = col;      // Đặt quân hậu
            solve(row + 1);        // Chuyển sang hàng tiếp theo
        }
    }
}

int main() {
    solve(0);
    cout << "Tong so loi giai: " << countSolution << endl;
    return 0;
}
