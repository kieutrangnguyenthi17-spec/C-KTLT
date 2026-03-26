// Dưới đây cung cấp đoạn code đơn giản để tính hàm sigmoid theo công thức trực tiếp.
// Hãy viết hàm tính xấp xỉ sigmoid(x) đến độ chính xác 10−6 và có tốc độ nhanh hơn ít nhất 30% so
// với code đơn giản.
// Gợi ý: sử dụng kỹ thuật "chuẩn bị trước" như trong slide.
// In [ ]:
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>
using namespace std;
const int LIMIT = 100;
const int NUM_ITER = 100000;
const int NUM_INPUTS = NUM_ITER * 100;
double sigmoid_slow(double x) {
return 1.0 / (1.0 + exp(-x));
}
double x[NUM_INPUTS];
void prepare_input() {
const int PRECISION = 1000000;
const double RANGE = LIMIT / 20.0;
for (int i = 0; i < NUM_INPUTS; ++i) {
x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
}
}
const int TABLE_SIZE = 10000;         // số điểm trong bảng tra cứu
const double MIN_X = -6.0;             // giới hạn dưới
const double MAX_X = 6.0;              // giới hạn trên
double step = (MAX_X - MIN_X) / TABLE_SIZE;  // bước giữa 2 điểm
double table[TABLE_SIZE + 1];          // bảng giá trị sigmoid
void precalc() {
 for (int i = 0; i <= TABLE_SIZE; ++i) {
        double x = MIN_X + i * step;
        table[i] = 1.0 / (1.0 + exp(-x));
    }
}
//# hàm tính sigmoid(x) nhanh sigmoid_fast(x)
inline double sigmoid_fast(double x) {
if (x <= MIN_X) return table[0];            // gần 0
    if (x >= MAX_X) return table[TABLE_SIZE];   // gần 1

    double pos = (x - MIN_X) / step;
    int idx = (int)pos;
    double frac = pos - idx;

    // nội suy tuyến tính
    return table[idx] * (1 - frac) + table[idx + 1] * frac;
}
//# END fast code
double benchmark(double (*calc)(double), vector<double> &result) {
const int NUM_TEST = 20;

double taken = 0;
result = vector<double>();
result.reserve(NUM_ITER);
int input_id = 0;
clock_t start = clock();
for (int t = 0; t < NUM_TEST; ++t) {
double sum = 0;
for (int i = 0; i < NUM_ITER; ++i) {
double v = fabs(calc(x[input_id]));
sum += v;
if (t == 0) result.push_back(v);
if ((++input_id) == NUM_INPUTS) input_id = 0;
}
}
clock_t finish = clock();
taken = (double)(finish - start);
//# printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
return taken;
}
bool is_correct(const vector<double> &a, const vector<double> &b) {
const double EPS = 1e-6;
if (a.size() != b.size()) return false;
for (int i = 0; i < a.size(); ++i) {
if (fabs(a[i] - b[i]) > EPS) {
return false;
}
}
return true;
}
int main() {
prepare_input();
precalc();
vector<double> a, b;
double slow = benchmark(sigmoid_slow, a);
double fast = benchmark(sigmoid_fast, b);
double xval;
scanf("%lf", &xval);
printf("%.2f \n", sigmoid_fast(xval));
if (is_correct(a, b) && (slow/fast > 1.3)) {
printf("Correct answer! Your code is faster\n");
} else {
printf("Wrong answer or your code is not fast enough!\n");
}
return 0;
}