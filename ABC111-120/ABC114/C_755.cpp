#include<bits/stdc++.h>
using namespace std;

int main() {
    int s;
    cin >> s;

    int ans = 0;
    queue<int64_t> q;
    q.push(0);
    while (!q.empty()) {
        int64_t n = q.front();
        q.pop();

        if (s < n) continue;

        int c3 = 0, c5 = 0, c7 = 0;

        for (int64_t d = 1; d < n; d *= 10) {
            if (n / d % 10 == 3) c3++;
            if (n / d % 10 == 5) c5++;
            if (n / d % 10 == 7) c7++;
        }

        if (c3 && c5 && c7) ans++;

        q.push(n * 10 + 3);
        q.push(n * 10 + 5);
        q.push(n * 10 + 7);
    }

    cout << ans << endl;
}
