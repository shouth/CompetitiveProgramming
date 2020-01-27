#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t h;
    cin >> h;
    cout << (1l << (int64_t) (log2(h) + 1l)) - 1l << endl;
}
