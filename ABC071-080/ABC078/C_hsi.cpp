#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cout << ((n - m) * 100 + m * 1900) * pow(2, m) << endl;
}
