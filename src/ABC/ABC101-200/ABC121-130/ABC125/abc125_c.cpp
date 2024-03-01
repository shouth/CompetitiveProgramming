#include <bits/stdc++.h>
using namespace std;

int64_t gcd(int64_t a, int64_t b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    vector<int64_t> gcdl(n), gcdr(n);
    gcdl[0] = a[0], gcdr[n-1] = a[n-1];
    for (int i=1; i<n; i++) gcdl[i] = gcd(a[i], gcdl[i-1]);
    for (int i=n-1; i>0; i--) gcdr[i-1] = gcd(a[i-1], gcdr[i]);

    vector<int64_t> can(n);
    can[0] = gcdr[1], can[n-1] = gcdl[n-2];
    for (int i=1; i<n-1; i++) can[i] = gcd(gcdl[i-1], gcdr[i+1]);

    cout << *max_element(can.begin(), can.end()) << endl;

    return 0;
}