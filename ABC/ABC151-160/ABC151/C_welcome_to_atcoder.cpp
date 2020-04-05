#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> res(n), done(n);
    int cor = 0, pen = 0;
    for (int i = 0; i < m; i++) {
        int p;
        string s;
        cin >> p >> s, p--;
        if (!done[p]) {
            if (s == "AC") {
                pen += res[p], done[p] = 1, cor++;
            } else {
                res[p]++;
            }
        }
    }

    cout << cor << " " << pen << endl;
}
