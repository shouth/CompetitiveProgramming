#include<bits/stdc++.h>
using namespace std;

int main() {
    char c;
    cin >> c;
    cout << ("aeiou"s.find(c) != string::npos ? "vowel" : "consonant") << endl;
}
