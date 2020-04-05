#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (auto& e : x) cin >> e;

    vector<int> s = x;
    sort(begin(s), end(s));

    for (auto& e : x) cout << (e <= s[n/2-1] ? s[n/2] : s[n/2-1]) << endl;
}
