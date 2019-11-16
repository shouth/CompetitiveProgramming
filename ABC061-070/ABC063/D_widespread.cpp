#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, a, b;
    cin >> n >> a >> b;
    vector<int64_t> h(n);
    for (auto& e : h) cin >> e;

    int64_t left = -1, right = 1e9;
    while (abs(right - left) > 1) {
        int64_t middle = left + (right - left) / 2;
        int64_t c = 0;
        for (auto& e : h) c += (max(0l, e - middle * b) + a - b - 1) / (a - b);
        (c > middle ? left : right) = middle;
    }

    cout << right << endl;
}
