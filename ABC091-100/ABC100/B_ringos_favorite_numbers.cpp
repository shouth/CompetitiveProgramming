#include<bits/stdc++.h>
using namespace std;

int main() {
    int d, n;
    cin >> d >> n;
    if (n == 100) n++;
    cout << (int) (n * pow(100, d)) << endl;
}
