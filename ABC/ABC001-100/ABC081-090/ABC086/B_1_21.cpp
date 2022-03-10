#include<bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int n = stoi(a + b);
    int s = sqrt(n);
    cout << (n == s*s ? "Yes" : "No") << endl;
}
