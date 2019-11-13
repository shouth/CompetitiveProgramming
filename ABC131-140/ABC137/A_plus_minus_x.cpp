#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int ans = max(a + b, a - b);
    cout << max(ans, a * b) << endl;
}
