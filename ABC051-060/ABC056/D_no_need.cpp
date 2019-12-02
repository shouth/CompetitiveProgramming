#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> left(n+2, vector<int>(k+1)), right(n+2, vector<int>(k+1));
    left[0][0] = right[n+1][0] = 1;
    for (int i = 0; i+1 <= n; i++) {
        for (int j = 0; j <= k; j++) {
            left[i+1][j] |= left[i][j];
            if (j+a[i+1] <= k) left[i+1][j+a[i+1]] |= left[i][j];
        }
    }
    for (int i = n+1; i-1 >= 1; i--) {
        for (int j = 0; j <= k; j++) {
            right[i-1][j] |= right[i][j];
            if (j+a[i-1] <= k) right[i-1][j+a[i-1]] |= right[i][j];
        }
    }
    for (int i = 0; i <= n+1; i++) {
        partial_sum(begin(right[i]), end(right[i]), begin(right[i]));
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if ((j + a[i] < k && left[i-1][j] && right[i+1][k-j-1] - right[i+1][k-j-a[i]-1])
                || (j >= k - a[i] && left[i-1][j])) {
                ans++;
                break;
            }
        }
    }
    cout << n - ans << endl;
}
