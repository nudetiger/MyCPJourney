#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define int long long
#define INF 9223372036854775807

using namespace std;

const int ZR = 0;

struct Segment_Tree {

    int size; 
    vector<int> seg;

    Segment_Tree(int n) {
        this->size = 4 * n;
        seg.resize(4 * n);
    }

    void update(int id, int l, int r, int i, int v) {
        if(i < l || i > r) return;
        if(l == r) {
            seg[id] = max(v, ZR);
            return;
        }

        int m = (l + r) / 2;
        update(id*2, l, m, i, v);
        update(id*2 + 1, m + 1, r, i, v);

        seg[id] = seg[id * 2] + seg[id * 2 + 1];
    }  

    int get(int id, int l, int r, int u, int v) {
        if(v < l || r < u) return 0;
        if(u <= l && r <= v) return seg[id];

        int m = (l + r) / 2;
        return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
    }

};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("GSS.INP", "r", stdin);
    freopen("GSS.OUT", "w", stdout);

    int n, q, inp, a, b;

    cin >> n;
    Segment_Tree tree = Segment_Tree(n);

    for(int i = 0; i < n; i++) {
        cin >> inp;
        tree.update(1, 0, n-1, i, inp);
    }

    cin >> q;

    while(q--) {
        cin >> a >> b;

        cout << tree.get(1, 0, n-1, a-1, b-1) << "\n";

    }

    return 0;
}