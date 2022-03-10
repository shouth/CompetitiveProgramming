#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> count;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        while (!(a & 1)) a >>= 1;
        count[a]++;
    }
    cout << count.size() << endl;
}
