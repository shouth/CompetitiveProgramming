#include<bits/stdc++.h>
using namespace std;

struct unionfindtree {
    vector<int> parent;

    unionfindtree(int size): parent(size) {
        iota(begin(parent), end(parent), 0);
    }

    void unite(int a, int b) {
        if ((a = find(a)) == (b = find(b))) return;
        parent[b] = a;
    }

    int find(int a) {
        return (parent[a] == a ? a : parent[a] = find(parent[a]));
    }
};

int main() {
    int n, m, l;
    cin >> n >> m >> l;

}
