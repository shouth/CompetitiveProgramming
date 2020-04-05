#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, z, w;
    cin >> n >> z >> w;
    vector<int> a(n);
    for (auto& e : a) cin >> e;

    cout << (n == 1 ? abs(a[0] - w) : max(abs(a[n-2] - a[n-1]), abs(a[n-1] - w))) << endl;
}
