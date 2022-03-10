#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    cout << (a >= 13 ? b : a <= 5 ? 0 : b/2) << endl;
}
