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
    int k;
    cin >> k;
    map<string, int> m;
    for (int i = 0; i+k <= (int) s.size(); i++) m[s.substr(i, k)]++;
    cout << m.size() << endl;
}
