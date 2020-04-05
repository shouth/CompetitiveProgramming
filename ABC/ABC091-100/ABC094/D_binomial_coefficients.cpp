#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;

    sort(begin(a), end(a));
    int select = 1e9;
    int mother = a.back();
    int target = (mother + 1) / 2;
    a.erase(end(a) - 1);
    a.shrink_to_fit();
    for (int i = 0; i < n; i++) {
        select = abs(select - target) < abs(a[i] - target) ? select : a[i];
    }

    cout << mother << " " << select << endl;
}
