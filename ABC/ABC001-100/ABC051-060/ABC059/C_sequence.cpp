#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for (auto& e : a) cin >> e;

    int64_t can1 = 0, can2 = 0;
    for (int64_t i = 0, acc1 = 0, acc2 = 0; i < n; i++) {
        acc1 += a[i], acc2 += a[i];
        if (i % 2 == 0) {
            if (acc1 <= 0) {
                can1 += -acc1 + 1;
                acc1 = 1;
            }
            if (acc2 >= 0) {
                can2 += acc2 + 1;
                acc2 = -1;
            }
        } else {
            if (acc1 >= 0) {
                can1 += acc1 + 1;
                acc1 = -1;
            }
            if (acc2 <= 0) {
                can2 += -acc2 + 1;
                acc2 = 1;
            }
        }
    }

    cout << min(can1, can2) << endl;
}
