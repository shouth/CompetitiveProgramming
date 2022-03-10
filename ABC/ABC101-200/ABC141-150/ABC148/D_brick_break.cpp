#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == s+1) s++;
    }
    cout << (s != 0 ? n-s : -1) << endl;
}
