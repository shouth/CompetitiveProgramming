#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int m = n; m != 0; m /= 10) sum += m % 10;
    cout << (n % sum == 0 ? "Yes" : "No") << endl;
}
