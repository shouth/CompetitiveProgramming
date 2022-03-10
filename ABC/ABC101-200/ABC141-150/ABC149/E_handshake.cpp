#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), acc(n+1);
    for (int i = 0; i <= n; i++) cin >> a[i];
    partial_sum(a.begin(), a.end(), acc.begin());

    for (int i = 1, pc = 0; i <= n; i++) {
    }
}
