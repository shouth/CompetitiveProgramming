#include <utility>
#include <bitset>
#include <tuple>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <complex>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    string s;
    cin >> s;
    map<char, int> c;
    for (auto& e : s) c[e]++;
    for (char i = 'A'; i != 'G'; i++) cout << c[i] << (i != 'F' ? " " : "");
    cout << endl;
}
