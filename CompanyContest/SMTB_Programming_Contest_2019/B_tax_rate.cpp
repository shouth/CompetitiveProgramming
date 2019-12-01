#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int xcan = n / 1.08;
    int ncan1 = xcan * 1.08, ncan2 = (xcan + 1) * 1.08;
    cout << (ncan1 == n ? to_string(xcan) : ncan2 == n ? to_string(xcan + 1) : ":(") << endl;
}
