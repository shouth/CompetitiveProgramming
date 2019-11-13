#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int64_t k;
    cin >> k;

    s += '*';
    int64_t l1 = 0;
    while (s[l1] == '1') l1++;

    cout << (k <= l1 ? '1' : s[l1]) << endl;
}
