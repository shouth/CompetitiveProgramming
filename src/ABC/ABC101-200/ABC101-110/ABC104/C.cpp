#include <bits/stdc++.h>
using namespace std;


int main() {
    int d, g;
    cin >> d >> g;
    vector<tuple<int, int, int>> problems;
    for (int i = 1; i <= d; i++) {
        int p, c;
        cin >> p >> c;
        problems.emplace_back(i * 100, p, c);
    }
    
    int ans = 1e9;
    do {
        int sum = 0, qs = 0;
        for (auto& e : problems) {
            int score = get<0>(e), number = get<1>(e), bonus = get<2>(e);
            if (sum + score * number < g) {
                sum += score * number;
                qs += number;
                if (sum + bonus < g) {
                    sum += bonus;
                } else {
                    ans = min(ans, qs);
                    break;
                }
            } else {
                for (int i = 1; i <= number; i++) {
                    if (sum + score * i >= g) {
                        ans = min(ans, qs + i);
                        break;
                    }
                }
                break;
            }
        }
    } while (next_permutation(begin(problems), end(problems)));
    
    cout << ans << endl;
}
