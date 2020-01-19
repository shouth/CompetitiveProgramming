#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    string sa(b, '0' + a), sb(a, '0' + b);
    cout << (sa < sb ? sa : sb) << endl;
}
