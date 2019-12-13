#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string piano = "WBWBWWBWBWBWWBWBWWBWBWBW";
    int wi = piano.find(s.substr(0, 12));
    string ans;
    switch (wi) {
    case 0: ans = "Do"; break;
    case 2: ans = "Re"; break;
    case 4: ans = "Mi"; break;
    case 5: ans = "Fa"; break;
    case 7: ans = "So"; break;
    case 9: ans = "La"; break;
    case 11: ans = "Si"; break;
    }
    cout << ans << endl;
}
