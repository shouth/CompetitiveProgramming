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
    int l1, l2, l3;
    cin >> l1 >> l2 >> l3;
    if (l1 == l2) cout << l3 << endl;
    else if (l2 == l3) cout << l1 << endl;
    else cout << l2 << endl;
}
