#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    sort(begin(a), end(a));
    int s = unique(begin(a), end(a)) - begin(a);
    cout << n-(n-s+1)/2*2 << endl;
}
