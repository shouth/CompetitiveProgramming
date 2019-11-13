#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> ap;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        ap.emplace_back(a, i);
    }

    sort(begin(ap), end(ap));
    for (auto& e : ap) cout << e.second << " ";
}
