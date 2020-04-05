#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> v(n);
    for (auto& e : v) cin >> e;

    sort(rbegin(v), rend(v));
    for (int i = 0; i + 1 < n; i++) {
        for (int j = i; j < n; j++) {
            v[j] /= 2;
        }
    }

    cout << accumulate(begin(v), end(v), .0) << endl;
}
