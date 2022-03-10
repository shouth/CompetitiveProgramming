#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<char> s(n);
    for (auto& e : s) cin >> e;
    sort(begin(s), end(s));
    auto itr = unique(begin(s), end(s));
    cout << ((itr - begin(s)) == 3 ? "Three" : "Four") << endl;
}
