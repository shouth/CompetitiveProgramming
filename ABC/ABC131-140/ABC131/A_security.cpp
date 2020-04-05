#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    cout << (adjacent_find(str.begin(), str.end()) == str.end() ? "Good" : "Bad") << endl;
}
