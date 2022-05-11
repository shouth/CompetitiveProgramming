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
    string abcd;
    cin >> abcd;

    for (int i = 0; i < 2 << 3; i++) {
        int can = abcd[0] - '0';
        stringstream ss;
        ss << abcd[0];
        for (int j = 0; j < 3; j++) {
            if (i & 1 << j) {
                can += abcd[j+1] - '0';
                ss << "+" << abcd[j+1];
            } else {
                can -= abcd[j+1] - '0';
                ss << "-" << abcd[j+1];
            }
        }
        ss << "=7";
        if (can == 7) {
            cout << ss.str() << endl;
            break;
        }
    }
}
