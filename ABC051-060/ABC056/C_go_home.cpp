#include<bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
    int i = 1, sum = 0;
    while (sum+i < x) sum += i, i++;
    cout << i << endl;
}
