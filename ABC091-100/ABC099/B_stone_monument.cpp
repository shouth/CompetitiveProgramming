#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int h = 0;
    for (int i = 1; i <= b-a; i++) h += i;
    cout << h-b << endl;
}
