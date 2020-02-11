#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int, greater<>> c;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        c[a]++;
    }

    cout << next(begin(c))->first << endl;
}
