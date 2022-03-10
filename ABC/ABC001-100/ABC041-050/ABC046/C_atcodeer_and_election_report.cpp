#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;
    int64_t tv = 1, av = 1;
    for (int i = 0; i < n; i++) {
        int64_t t, a;
        cin >> t >> a;
        int64_t p = max((tv+t-1) / t, (av+a-1) / a);
        tv = t * p, av = a * p;
    }
    cout << tv + av << endl;
}
