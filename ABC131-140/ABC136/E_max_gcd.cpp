#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, k;
    cin >> n >> k;
    vector<int64_t> a(n);
    for (auto& e : a) cin >> e;
    int64_t sum = accumulate(begin(a), end(a), 0ll);
    priority_queue<int64_t> ds;
    for (int64_t i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ds.push(i);
            if (i * i != n) ds.push(n / i);
        }
    }
    while (!ds.empty()) {
        int64_t d = ds.top(); ds.pop();
        
    }
}
