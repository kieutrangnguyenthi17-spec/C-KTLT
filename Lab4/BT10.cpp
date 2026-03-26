#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>

using namespace std;

vector<string> split(const string &s) {
    vector<string> res;
    string tmp;
    stringstream ss(s);
    while (getline(ss, tmp, ',')) {
        res.push_back(tmp);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    vector< map<string, int> > freq(N);   
    vector<int> maxf(N, 0);                
    map<string, int> df;
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);
        vector<string> words = split(line);

        map<string, bool> appeared;
        for (const string &w : words) {
            freq[i][w]++;
            maxf[i] = max(maxf[i], freq[i][w]);
            appeared[w] = true;
        }

        for (const auto &x : appeared) {
            df[x.first]++;
        }
    }

    int Q;
    cin >> Q;
    cin.ignore();

    while (Q--) {
        string query;
        getline(cin, query);
        vector<string> qwords = split(query);

        double best_score = -1;
        int best_doc = 0;

        for (int d = 0; d < N; ++d) {
            double score = 0.0;

            for (const string &t : qwords) {
                if (freq[d].count(t)) {
                    double TF = 0.5 + 0.5 * freq[d][t] / maxf[d];
                    double IDF = log2((double)N / df[t]);
                    score += TF * IDF;
                }
            }

            if (score > best_score) {
                best_score = score;
                best_doc = d;
            }
        }

        cout << best_doc + 1 << "\n";
    }

    return 0;
}

