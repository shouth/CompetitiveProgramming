#include<bits/stdc++.h>
using namespace std;

int combi(int n, int r) {
    if (n < r) return 0;
    int num = 1;
    for (int i = 1; i <= r; i++) {
        num = num * (n - i + 1) / i;
    }
    return num;
}

int main() {
    string n;
    cin >> n;
    int m = n.size();
    int64_t k;
    cin >> k;

    if (m < k) {
        cout << 0 << endl;
        return 0;
    }

    int64_t ans = (n[0] - '0' - 1) * combi(m-1, k-1) * pow(9, k-1) + combi(m-1, k) * pow(9, k);

    cout << ans << endl;
}
