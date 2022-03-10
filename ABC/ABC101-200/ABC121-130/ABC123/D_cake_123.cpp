#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<int64_t> a(x), b(y), c(z);
    for (auto& e : a) cin >> e;
    for (auto& e : b) cin >> e;
    for (auto& e : c) cin >> e;
    vector<int64_t> ab;
    for (auto& e : a) {
        for (auto& f : b) {
            ab.push_back(e + f);
        }
    }
    sort(ab.begin(), ab.end(), greater<int64_t>());
    vector<int64_t> abc;
    for (int64_t i = 0; i < min(k, (int64_t) ab.size()); i++) {
        for (auto& e : c) {
            abc.push_back(ab[i] + e);
        }
    }
    sort(abc.begin(), abc.end(), greater<int64_t>());
    for (int64_t i = 0; i < k; i++) {
        cout << abc[i] << endl;
    }
}