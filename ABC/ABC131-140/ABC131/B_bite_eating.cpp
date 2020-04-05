#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    cout << n*l + n*(n-1)/2 - (l>0)*l - (l+n-1<0)*(l+n-1) << endl;
}
