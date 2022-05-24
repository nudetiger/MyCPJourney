#include <bits/stdc++.h>

#define int long long
#define INF 9223372036854775807

using namespace std;

struct Node {
    int lazy = 0; int v;
};

struct Segment_Tree {

    int size; 
    vector<Node> seg;

    Segment_Tree(int n) {
        this->size = 4 * n;
        seg.resize(4 * n);
    }

    void down(int id) {
        int t = seg[id].lazy;

        seg[id*2].lazy += t; seg[id*2].v += t;
        seg[id*2+1].lazy += t; seg[id*2+1].v += t;

        seg[id].lazy = 0;
    }

    void update(int id, int l, int r, int i, int v) {
        if(i < l || i > r) return;
        if(l == r) {
            seg[id].v = v;
            return;
        }

        down(id);

        int mid = (l + r) / 2;
        update(id*2, l, mid, i, v);
        update(id*2 + 1, mid + 1, r, i, v);

        // OPTIMAL VAL FOR ID
        seg[id].v = max(seg[id * 2].v, seg[id * 2 + 1].v);
    }
    
    void updateRange(int id, int l, int r, int u, int v, int val) {
        if (v < l || r < u) {
            return ;
        }
        if (u <= l && r <= v) {
            seg[id].v += val;
            seg[id].lazy += val;
            return ;
        }

        down(id);

        int mid = (l + r) / 2;
        updateRange(id*2, l, mid, u, v, val);
        updateRange(id*2+1, mid+1, r, u, v, val);

        seg[id].v = max(seg[id*2].v, seg[id*2 + 1].v);
    }

    int get(int id, int l, int r, int u, int v) {
        if (v < l || r < u)  return -INF;
        if (u <= l && r <= v) return seg[id].v;

        down(id);

        int mid = (l + r) / 2;
        return max(get(id*2, l, mid, u, v), get(id*2 + 1, mid+1, r, u, v));
    }

};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("INCMAXIT.INP", "r", stdin);
    freopen("INCMAXIT.OUT", "w", stdout);

    int n, q, inp;
    cin >> n;

    Segment_Tree tree = Segment_Tree(n);
    for(int i = 0; i < n; i++) {
        cin >> inp;
        tree.update(1, 0, n-1, i, inp);
    }
    
    cin >> q;

    int x, y, z, w;
    while(q--) {
        cin >> x >> y >> z;
        if(x == 1) {
            cin >> w;
            tree.updateRange(1, 0, n-1, y-1, z-1, w);
        } else {
            cout << tree.get(1, 0, n-1, y-1, z-1) << "\n";
        }     
    }

    return 0;
}