#include <bits/stdc++.h>

#define int long long
#define INF 9223372036854775807

using namespace std;

struct Node {
    int lazy = 0; int v, l = 0;
};

struct Segment_Tree {

    int size; 
    vector<Node> seg;

    Segment_Tree(int n) {
        this->size = 4 * n;
        seg.resize(4 * n);
    }

    void down(int id, int l, int r) {
        if(seg[id].l == 0) return;
        int t = seg[id].lazy;

        int mid = (l + r) / 2;

        seg[id*2].lazy = t; seg[id*2].v = (mid - l + 1) * t; seg[id*2].l = 1;
        seg[id*2+1].lazy = t; seg[id*2+1].v = (r - mid) * t; seg[id*2+1].l = 1;

        seg[id].l = 0;
    }

    void update(int id, int l, int r, int i, int v) {
        if(i < l || i > r) return;
        if(l == r) {
            seg[id].v = v;
            return;
        }

        down(id, l, r);

        int mid = (l + r) / 2;
        update(id*2, l, mid, i, v);
        update(id*2 + 1, mid + 1, r, i, v);

        // OPTIMAL VAL FOR ID
        seg[id].v = seg[id * 2].v + seg[id * 2 + 1].v;
    }
    
    void updateRange(int id, int l, int r, int u, int v, int val) {
        if (v < l || r < u) {
            return ;
        }
        if (u <= l && r <= v) {
            seg[id].v = val * (r - l + 1);
            seg[id].lazy = val;
            seg[id].l = 1;
            return ;
        }

        down(id, l, r);

        int mid = (l + r) / 2;
        updateRange(id*2, l, mid, u, v, val);
        updateRange(id*2+1, mid+1, r, u, v, val);

        seg[id].v = seg[id*2].v + seg[id*2 + 1].v;
    }

    int get(int id, int l, int r, int u, int v) {
        if (v < l || r < u)  return 0;
        if (u <= l && r <= v) return seg[id].v;

        down(id, l, r);

        int mid = (l + r) / 2;
        return get(id*2, l, mid, u, v) + get(id*2 + 1, mid+1, r, u, v);
    }

};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("B.INP", "r", stdin);
    freopen("B.OUT", "w", stdout);

    int n, q, inp;
    cin >> n >> q;

    Segment_Tree tree = Segment_Tree(n);
    for(int i = 0; i < n; i++) {
        cin >> inp;
        tree.update(1, 0, n-1, i, inp);
    }

    int x, y, w;
    while(q--) {
        cin >> x >> y;
        if(x == 1) {
            cin >> w;
            tree.updateRange(1, 0, n-1, y-1, y-1, w);
        } else {
            tree.updateRange(1, 0, n-1, 0, n-1, y);
        }     
        cout << tree.get(1, 0, n-1, 0, n-1) << "\n";
    }

    return 0;
}