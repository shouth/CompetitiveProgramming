#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> ss(m, 0);
    for(auto& e : ss) {
        int k;
        cin >> k;

        for (int i=0; i<k; i++) {
            int s;
            cin >> s;
            e += (1 << (s-1));
        }
    }

    vector<int> surplus(m);
    for (auto& e : surplus) {
        cin >> e;
    }

    int ans = 0;
    for (int i=0; i<(1<<n); i++) {
        
    	bool bc = true;
        for (int j=0; j<m; j++) {
            int ba = i & ss[j];

            int bs = 0;
            for (int k=0; k<n; k++) {
                if (ba & (1 << k)) bs ^= 1;
            }

            if (bs != surplus[j]) bc = false;
        }

	    if (bc) ans++;
    }
    cout << ans << endl;
}
