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
    string ss, t;
    cin >> ss >> t;
    priority_queue<string, vector<string>, greater<string>> can;
    for (size_t i = 0; i + t.size() <= ss.size(); i++) {
        bool f = true;
        for (size_t j = 0; j < t.size(); j++) {
            if (ss[i+j] != t[j] && ss[i+j] != '?') f = false;
        }
        if (!f) continue;
        string tmp = ss;
        copy(begin(t), end(t), begin(tmp) + i);
        replace(begin(tmp), end(tmp), '?', 'a');
        can.push(tmp);
    }

    cout << (can.empty() ? "UNRESTORABLE" : can.top()) << endl;
}
