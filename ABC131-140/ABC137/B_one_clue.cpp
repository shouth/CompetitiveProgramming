#include<bits/stdc++.h>
using namespace std;

int main() {
    int k, x;
    cin >> k >> x;
    for (int i = max(x - k + 1, -1000000); i <= min(x + k - 1, 1000000); i++) {
        cout << i << endl;
    }
}
