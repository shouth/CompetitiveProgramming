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
    int n, q;
    cin >> n >> q;
    vector<int> board(n);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r, l--, r--;
        board[l]++;
        if (r+1 < n) board[r+1]--;
    }

    partial_sum(begin(board), end(board), begin(board));
    for (auto& e : board) cout << e % 2;
    cout << endl;
}
