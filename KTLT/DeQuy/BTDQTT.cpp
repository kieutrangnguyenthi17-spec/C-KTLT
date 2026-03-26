#include <iostream>
#include <vector>

using namespace std;

void backtrack(int n, int k, int start, vector<int>& combination, vector<vector<int>>& result) {
    if ((int)combination.size() == k) { // kích cỡ tổ hợp con =k( theo đề )
        result.push_back(combination); // bỏ tổ hợp con( combination) vào result
        return;
    }
    // bắt đầu xây dựng tổ hợp con
    for (int i = start; i <= n; i++) {
        combination.push_back(i);
        backtrack(n, k, i + 1, combination, result);// tăng start lên nhờ đệ quy
        combination.pop_back(); // bỏ phần tử cuối để tìm các phần tử thích hợp thế vào
    }
}

vector<vector<int>> combine(int n, int k) { // trả về danh sách các tổ hợp
    vector<vector<int>> result; //  vector lưu tất cả các tổ hợp con
    vector<int> combination; // xây dựng tổ hợp con
    backtrack(n, k, 1, combination, result);
    return result;
}

int main() {
    int n = 5, k = 3; //n: tổng số phần tử, k: số phần tử trong tập hợp con
    vector<vector<int>> combos = combine(n, k); // gọi hạm combine

    for (const auto& c : combos) { //duyệt qua từng tổ hợp trong combos -- từng phần tử trong combos(c) cũng giống 1 mảng gồm 3 pt
        cout << "{";
        for (size_t i = 0; i < c.size(); i++) { // duyệt từng pt trong "mảng" đó để in
            cout << c[i];
            if (i != c.size() - 1) cout << ","; // phẩy giữa các phần tử
        }
        cout << "}\n";
    }
    return 0;
}
