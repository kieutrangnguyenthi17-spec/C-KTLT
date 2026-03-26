// Viết hàm so sánh cho thuật toán sắp xếp.
// In [ ]:
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {

printf("Ho Va Ten: Nguyen Thi Kieu Trang\n");
printf("MSSV: 24133064\n\n");

int val1, val2;
cin >> val1 >> val2;
vector< vector<int> > a = {
{1, 3, 7},
{2, 3, 4, val1},
{9, 8, 15},
{10, val2},
};

sort(a.begin(), a.end(), [] (const vector<int>& v1, const vector<int>& v2){
 int sum1 = 0;
            for(unsigned int i=0; i<v1.size(); i++)
                sum1 += v1[i];

            int sum2 = 0;
            for(unsigned int i=0; i<v2.size(); i++)
                sum2 += v2[i];

            return sum1 > sum2;
});
for (const auto &v : a) {
for (int it : v) {
cout << it << ' ';
}
cout << endl;
}
return 0;
}