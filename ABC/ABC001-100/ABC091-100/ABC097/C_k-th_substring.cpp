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
    string s;
    cin >> s;
    int k;
    cin >> k;

    vector<string> words;
    for (auto litr = begin(s); litr != end(s); litr++) {
        for (auto ritr = litr + 1; ritr != min(litr + 5, end(s)) + 1; ritr++) {
            words.push_back(string(litr, ritr));
        }
    }

    sort(begin(words), end(words));
    unique(begin(words), end(words));
    words.shrink_to_fit();

    cout << words[k-1] << endl;
}
