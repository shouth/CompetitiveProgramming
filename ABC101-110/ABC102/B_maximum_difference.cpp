#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    sort(begin(a), end(a));
    cout << a[n-1] - a[0] << endl;
}
