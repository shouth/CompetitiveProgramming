#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 111; i < 1000; i += 111) {
        if (i < n) continue;
        cout << i << endl;
        break;
    }
}
