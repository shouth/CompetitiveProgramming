#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int h = 0;
    for (int i = n; i > 0; i /= 10) h += i % 10;
    cout << (n % h == 0 ? "Yes" : "No") << endl;
}
