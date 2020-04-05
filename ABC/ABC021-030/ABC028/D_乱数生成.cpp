#include<bits/stdc++.h>
using namespace std;

int main() {
    double n, k;
    cin >> n >> k;
    cout << fixed
         << setprecision(15)
         << ((k-1) * (n-k) * 6 + (n-1) * 3 + 1) / (n * n * n)
         << endl;
}
