#include<bits/stdc++.h>
using namespace std;

double s(int64_t x) {
    return (x != 0 ? s(x / 10) + x % 10 : 0);
}

int64_t f(int64_t n) {
    vector<pair<double, int64_t>> candidates{{ n / s(n), n }};
    for (int64_t d = 0; d <= log10(n) + 1; d++) {
        double x = pow(10, d+1) * floor(n / pow(10, d+1) + 1) - 1;
        candidates.emplace_back(x / s(x), x);
    }

    sort(begin(candidates), end(candidates));
    return candidates[0].second;
}

int main() {
    int64_t k;
    cin >> k;

    for (int64_t i = 0, n = 1; i < k; i++, n = f(n+1)) cout << n << endl;
}
