#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

i32 n, k;
vector<i32> a;

bool validate(i32 d) {
    vector<i32> r(n+1);
    transform(begin(a), end(a), begin(r)+1, [&](i32 i) { return i % d; });
    sort(begin(r)+1, end(r));
    partial_sum(begin(r), end(r), begin(r));
    
    for (i32 i = 0; i <= n && r[i] <= k; i++) {
        if (r[i] == (n-i) * d - (r[n] - r[i])) return true;
    }
    return false;
}

int main() {
    cin >> n >> k;
    a.assign(n, 0);
    for (auto& e : a) cin >> e;
    i64 s = accumulate(begin(a), end(a), 0l);
    
    i32 ans = 0;
    for (i32 i = 1; i <= sqrt(s); i++) {
        if (s % i != 0) continue;
        if (ans < i && validate(i)) ans = i;
        if (ans < s / i && validate(s / i)) ans = s / i; 
    }
    cout << ans << endl;
}
