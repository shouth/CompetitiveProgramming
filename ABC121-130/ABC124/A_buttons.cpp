#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << (a > b ? a + (a-1) : b > a ? b + (b-1) : a + b) << endl;
}