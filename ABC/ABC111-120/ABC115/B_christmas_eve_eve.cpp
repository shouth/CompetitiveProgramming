#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& e : p) cin >> e;
    sort(begin(p), end(p));

    cout << accumulate(begin(p), end(p) - 1, p.back() / 2) << endl;
}
