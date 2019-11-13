#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    sort(rbegin(a), rend(a));

    int alice = 0, bob = 0;
    for (int i = 0; i < n; i++) (i % 2 == 0 ? alice : bob) += a[i];
    cout << alice - bob << endl;
}
