#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;
    vector<int64_t> l(100);
    l[0] = 2, l[1] = 1;
    for (int64_t i = 0; i + 2 < 100; i++) l[i+2] = l[i+1] + l[i];
    cout << l[n] << endl;
}
