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
    vector<vector<char>> c(4, vector<char>(4));
    for (auto& e : c) for (auto& f : e) cin >> f;
    for (int i = 3; i >= 0; i--) {
        for (int j = 3; j >= 0; j--) cout << c[i][j] << (j == 0 ? "" : " ");
        cout << endl;
    }
}
