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
    int n;
    cin >> n;
    string s;
    cin >> s;

    string can = "b";
    int i;
    for (i = 0; (int) can.size() < n; i++) {
        switch ((i+1) % 3) {
        case 0:
            can = "b" + can + "b";
            break;
        case 1:
            can = "a" + can + "c";
            break;
        case 2:
            can = "c" + can + "a";
            break;
        }
    }

    cout << (can == s ? i : -1) << endl;
}
