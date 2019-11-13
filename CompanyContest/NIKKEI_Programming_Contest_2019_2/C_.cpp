#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& e : a) cin >> e;
    for (auto& e : b) cin >> e;

    int c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= b[i]) c++;
    }

    sort(begin(a), end(a));
    sort(begin(b), end(b));
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) d++;
    }

    cout << (c >= 2 && d == 0)
}
