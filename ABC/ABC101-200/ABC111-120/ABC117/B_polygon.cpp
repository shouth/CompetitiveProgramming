#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    for (auto& e : l) cin >> e;
    sort(l.begin(), l.end());
    int m = l.back();
    l.pop_back();
    cout << (accumulate(l.begin(), l.end(), 0) > m ? "Yes" : "No") << endl;
}