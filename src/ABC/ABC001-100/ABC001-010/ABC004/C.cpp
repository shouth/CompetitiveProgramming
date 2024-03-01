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
    string s = "123456";
    n %= 30;
    for (int i = 0; i < n; i++) {
        swap(s[i%5], s[i%5+1]);
    }

    cout << s << endl;
}
