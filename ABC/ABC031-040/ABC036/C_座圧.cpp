#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;

    vector<int> b = a;
    sort(begin(b), end(b));
    auto itr = unique(begin(b), end(b));
    b.erase(itr, end(b));

    map<int, int> m;
    for (int i = 0; i < (int) b.size(); i++) m[b[i]] = i;

    for (auto& e : a) cout << m[e] << endl;
}
