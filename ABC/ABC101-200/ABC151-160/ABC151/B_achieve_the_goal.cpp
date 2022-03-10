#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    int asum = 0;
    for (int i = 0; i < n-1; i++) {
        int a;
        cin >> a;
        asum += a;
    }

    int can = n * m - asum;
    cout << (can > k ? -1 : max(0, can)) << endl;
}
