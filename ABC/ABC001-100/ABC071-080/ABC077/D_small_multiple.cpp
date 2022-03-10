#include<bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;

    deque<int> q;
    q.push_front(1);
    vector<int> dist(k, 1e9); dist[1] = 0;
    bitset<100001> done;
    while (!q.empty()) {
        int c = q.front(); q.pop_front();
        if ((c*10) % k < k && !done[(c*10) % k]) {
            q.push_front((c*10) % k);
            dist[(c*10) % k] = min(dist[c], dist[(c*10) % k]);
        }
        if ((c+1) % k < k && !done[(c+1) % k]) {
            q.push_back((c+1) % k);
            dist[(c+1) % k] = min(dist[c] + 1, dist[(c+1) % k]);
        }
        done.set(c);
    }
    
    cout << dist[0] + 1 << endl;
}
