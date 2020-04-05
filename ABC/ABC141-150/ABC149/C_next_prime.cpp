#include<bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;

    for (int i = x; true; i++) {
        bool prime = true;
        for (int n = 2; n <= sqrt(i); n++) {
            if (i % n == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            cout << i << endl;
            break;
        }
    }
}
