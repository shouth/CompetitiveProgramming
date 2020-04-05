#include<bits/stdc++.h>
using namespace std;

int main() {
    int r;
    cin >> r;
    vector<string> contest{ "ABC", "ARC", "AGC" };
    cout << contest[(r >= 1200) + (r >= 2800)] << endl;
}
