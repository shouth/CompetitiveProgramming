#include <bits/stdc++.h>
using namespace std;

int main() {
    string str, acgt = "ACGT";
    int s = 0, t = 0;
    cin >> str;

    for(size_t i = 0; i < str.size(); i++) {
        if(acgt.find(str[i]) == string::npos) {
            t = 0;
        } else {
            t++;
        }
        if(t > s) s = t;
    }
    
    cout << s << endl;
}