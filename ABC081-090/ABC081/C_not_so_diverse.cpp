#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    map<int, int> a;
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        a[ai]++;
    }

    vector<int> m;
    transform(begin(a), end(a), back_inserter(m), [](auto a) { return a.second; });
    sort(begin(m), end(m));
    cout << accumulate(begin(m), begin(m) + max((int) m.size() - k, 0), 0) << endl;
}
