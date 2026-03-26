//Cài đặt bài hình vuông Latinh (là hình vuông có dòng đầu và cột đầu gồm
// các số từ 1 đến n. Trên mỗi dòng và mỗi cột đều là một hoán vị của các phần tử từ 1
// đến n.
/**/
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> board;
vector<bool> usedRow, usedCol;

bool canPlace(int row, int col, int val) {
    // Kiểm tra giá trị val có lặp trong dòng row không
    for (int j = 0; j < n; j++) {
        if (board[row][j] == val) return false;
    }
    // Kiểm tra giá trị val có lặp trong cột col không
    for (int i = 0; i < n; i++) {
        if (board[i][col] == val) return false;
    }
    return true;
}

bool solve(int row, int col) {
    if (row == n) {
        // Đã điền hết ma trận, in ra kết quả
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        return true; // Có thể đổi thành false nếu muốn in tất cả lời giải
    }

    if (col == n) return solve(row + 1, 1); // Chuyển sang dòng tiếp theo, cột 1

    // Nếu đang ở dòng 0 hoặc cột 0, đã cố định rồi nên bỏ qua
    if (row == 0 || col == 0) {
        return solve(row, col + 1);
    }

    for (int val = 1; val <= n; val++) {
        if (canPlace(row, col, val)) {
            board[row][col] = val;
            if (solve(row, col + 1)) {
                // return true; // nếu muốn chỉ in ra 1 lời giải thôi
            }
            board[row][col] = 0; // backtrack
        }
    }
    return false;
}

int main() {
    cin >> n;
    board.assign(n, vector<int>(n, 0));

    // Khởi tạo dòng đầu và cột đầu là 1..n
    for (int i = 0; i < n; i++) {
        board[0][i] = i + 1; // dòng đầu
        board[i][0] = i + 1; // cột đầu
    }

    solve(0, 1); // bắt đầu điền từ (0,1) vì (0,0) đã cố định

    return 0;
}
