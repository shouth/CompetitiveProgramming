#include <bits/stdc++.h>
using namespace std;

int main() {
    char a;
    cin >> a;
    map<char, char> acgt { { 'A', 'T' }, { 'C', 'G' }, { 'G', 'C' }, { 'T', 'A' } };
    cout << acgt[a] << endl;
}