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
    string a, b;
    cin >> a >> b;

    if (a.size() != b.size()) {
        cout << (a.size() > b.size() ? "GREATER" : "LESS") << endl;
    } else if (a != b) {
        cout << (a > b ? "GREATER" : "LESS") << endl;
    } else {
        cout << "EQUAL" << endl;
    }
}
