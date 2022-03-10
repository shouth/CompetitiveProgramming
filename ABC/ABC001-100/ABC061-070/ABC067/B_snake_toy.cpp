#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> l(n);
    for (auto& e : l) cin >> e;
    sort(begin(l), end(l), greater<>());
    cout << accumulate(begin(l), begin(l) + k, 0) << endl;
}
