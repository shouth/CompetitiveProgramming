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
    string o, e;
    cin >> o >> e;
    e += ' ';
    for (int i = 0; i < o.size(); i++) cout << o[i] << e[i];
}
