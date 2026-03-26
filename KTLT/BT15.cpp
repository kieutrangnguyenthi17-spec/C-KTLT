// Cài đặt bài mã đi tuần
//* */
#include <iostream>
#include <vector>
using namespace std;

int N;  // kích thước bàn cờ

// 8 hướng đi của mã
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int x, int y, vector<vector<int>>& board) {
    return (x >= 0 && y >= 0 && x < N && y < N && board[x][y] == -1);
}

bool KnightTour(int x, int y, int movei, vector<vector<int>>& board) {
    if (movei == N * N) {
        return true;  // đã đi qua hết ô
    }

    for (int k = 0; k < 8; k++) {
        int next_x = x + dx[k];
        int next_y = y + dy[k];
        if (isValid(next_x, next_y, board)) {
            board[next_x][next_y] = movei;
            if (KnightTour(next_x, next_y, movei + 1, board))
                return true;
            else
                board[next_x][next_y] = -1; // quay lui
        }
    }
    return false;
}

int main() {
    cout << "Nhap kich thuoc ban co (N): ";
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, -1));

    // Bắt đầu từ ô (0,0)
    board[0][0] = 0;

    if (KnightTour(0, 0, 1, board)) {
        cout << "Duong di hop le:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << "\t";
            }
            cout << "\n";
        }
    } else {
        cout << "Khong co duong di hop le\n";
    }

    return 0;
}
