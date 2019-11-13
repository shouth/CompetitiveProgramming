#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> b(n-1);
    for (auto& e : b) cin >> e;

    vector<int> a(n);
    a[0] = a[1] = b[0];
    
    for (int i = 1; i < n-1; i++) {
        if (a[i] < b[i]) a[i+1] = b[i];
        else a[i+1] = a[i] = b[i];
    }

    cout << accumulate(begin(a), end(a), 0) << endl;
}
