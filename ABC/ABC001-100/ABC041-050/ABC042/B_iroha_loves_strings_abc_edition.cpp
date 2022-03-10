#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    vector<string> s(n);
    for (auto& e : s) cin >> e;
    sort(begin(s), end(s));
    cout << accumulate(begin(s), end(s), ""s) << endl;
}
