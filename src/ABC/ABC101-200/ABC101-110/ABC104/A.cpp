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
    int r;
    cin >> r;
    vector<string> contest{ "ABC", "ARC", "AGC" };
    cout << contest[(r >= 1200) + (r >= 2800)] << endl;
}
