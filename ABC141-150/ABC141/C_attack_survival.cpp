#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> an(n, k-q);
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        an[a-1]++;
    }
    for (auto& e : an) cout << (e > 0 ? "Yes" : "No") << endl;
}
