#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string ans = "Bad";
    switch (n / 10) {
    case 6:
    case 7:
    case 8:
        ans = "Good";
        break;
    case 9:
        ans = "Great";
        break;
    case 10:
        ans = "Perfect";
        break;
    }

    cout << ans << endl;
}
