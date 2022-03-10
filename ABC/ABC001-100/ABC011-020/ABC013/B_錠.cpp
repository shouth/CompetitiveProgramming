#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << min({ abs(a-b), 10+a-b, 10-a+b }) << endl;
}
