#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t k;
    cin >> k;
    vector<int64_t> ans(50);
    iota(begin(ans), end(ans), 0);
    for (auto& e : ans) e += k / 50, e -= k % 50;
    for (int64_t i = 0; i < k % 50; i++) ans[i] += 51;
    cout << 50 << endl;
    for (auto& e : ans) cout << e << " ";
}
