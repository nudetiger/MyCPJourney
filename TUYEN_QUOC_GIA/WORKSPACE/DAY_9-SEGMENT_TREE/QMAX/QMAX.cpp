#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define int long long
#define INF 9223372036854775807

using namespace std;

struct Segment_Tree {

    int size; 
    vector<int> seg;

    Segment_Tree(int n) {
        this->size = 4 * n;
        seg.resize(4 * n);
    }

    void print() {
        for(int i = 0; i < size; i++) cout << seg[i] << " ";
    }

    void build(int n, vector<int>& arr) {
        for(int i = 0; i < n; i++) update(1, 0, n-1, i, arr[i]);
    }

    void update(int id, int l, int r, int i, int v) {
        if(i < l || i > r) return;
        if(l == r) {
            seg[id] = v;
            return;
        }

        int m = (l + r) / 2;
        update(id*2, l, m, i, v);
        update(id*2 + 1, m + 1, r, i, v);

        seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
    }  

    int get(int id, int l, int r, int u, int v) {
        if(v < l || r < u) return -INF;
        if(u <= l && r <= v) return seg[id];

        int m = (l + r) / 2;
        return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
    }

};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("QMAX.INP", "r", stdin);
    freopen("QMAX.OUT", "w", stdout);

    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n + 1, 0);

    int x, y, w;
    for(int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        arr[x-1] += w; arr[y] -= w;
    }
    for(int i = 1; i < n; i++) arr[i] += arr[i-1];

    Segment_Tree tree = Segment_Tree(n);
    tree.build(n, arr);
    
    int p;
    cin >> p;

    while(p--) {
        cin >> x >> y;
        cout << tree.get(1, 0, n-1, x-1, y-1) << endl;
    }

    return 0;
}