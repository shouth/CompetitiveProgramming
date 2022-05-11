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
    map<int, int> count;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        while (!(a & 1)) a >>= 1;
        count[a]++;
    }
    cout << count.size() << endl;
}
