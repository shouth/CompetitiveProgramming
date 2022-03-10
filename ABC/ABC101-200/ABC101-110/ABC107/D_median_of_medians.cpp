#include<bits/stdc++.h>
using namespace std;

struct bit {
    int64_t size;
    vector<int64_t> v;

    bit(int64_t n): size(n+1), v(size) {}

    void add(int64_t a, int64_t w) {
        for (int64_t x = a; x <= size; x += x & -x) v[x] += w;
    }

    int sum(int64_t a) {
        int64_t res = 0;
        for (int64_t x = a; x > 0; x -= x & -x) res += v[x];
        return res;
    }
};

int main() {
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for (auto& e : a) cin >> e;
    
    int64_t top = 1e9, bottom = 0;
    while (top - bottom > 1) {
        int64_t target = (top + bottom) / 2;
        
        bit b(n*2+2);
        b.add(n+1, 1);
        int64_t num = 0, sum = 0;
        for (int64_t i = 0; i < n; i++) {
            sum += (a[i] <= target ? 1 : -1);
            num += b.sum(sum+n);
            b.add(sum+n+1, 1);
        }

        (num > n * (n+1) / 4 ? top : bottom) = target;
    }

    cout << top << endl;
}
