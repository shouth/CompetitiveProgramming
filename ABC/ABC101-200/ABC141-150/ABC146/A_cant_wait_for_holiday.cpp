#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    map<string, int> m {
        { "SUN", 7 },
        { "MON", 6 },
        { "TUE", 5 },
        { "WED", 4 },
        { "THU", 3 },
        { "FRI", 2 },
        { "SAT", 1 },
    };
    
    cout << m[s] << endl;
}
