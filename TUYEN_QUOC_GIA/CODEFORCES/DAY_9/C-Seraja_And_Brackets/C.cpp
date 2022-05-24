#include <bits/stdc++.h>

#define int long long
#define II pair<int, int>
#define III pair<int, pair<int, int>>
#define DI pair<double, int>
#define fs first
#define sc second
#define mp(a, b) make_pair(a, b)
#define LINF 9223372036854775807
#define INF 2147483647

using namespace std;

struct Node {
    int opt = 0, l = 0, r = 0;
    Node(int o, int op, int cl) {
        opt = o;
        l = op;
        r = cl;
    }
};

Node sum(Node a, Node b) {
    Node ans = Node(0, 0, 0);
    int t = min(a.l, b.r);

    ans.opt = a.opt + b.opt + t;
    ans.l = a.l + b.l - t;
    ans.r = a.r + b.r - t;

    return ans; 
}

struct SegmentTree {

    int size;
    vector<Node> tree;

    SegmentTree(int n, string s) {
        this->size = 4*n;
        tree.assign(this->size, Node(0, 0, 0));

        for(int i = 0; i < n; i++) {
            update(1, 0, n-1, i, s[i]);
        }
    }

    void update(int id, int l, int r, int i, char x) {

        if(i < l || i > r) return;
        if(l == r) {
            if(x == '(') tree[id] = Node(0, 1, 0);
            else tree[id] = Node(0, 0, 1);
            return;
        }

        int mid = (l + r) >> 1;

        update(id * 2, l, mid, i, x);
        update(id * 2 + 1, mid + 1, r, i, x);

        tree[id] = sum(tree[id * 2], tree[id * 2 + 1]);
    }

    Node get(int id, int l, int r, int u, int v) {
        if(v < l || r < u) return Node(0, 0, 0);
        if(u <= l && r <= v) return tree[id];

        int mid = (l + r) >> 1;

        return sum(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }

};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("C.INP", "r", stdin);
    freopen("C.OUT", "w", stdout);
    
    string s;
    cin >> s;

    int n = s.length();
    SegmentTree tree = SegmentTree(n, s);

    int q;
    cin >> q;
    int l, r;
    while (q--) {
        cin >> l >> r;
        cout << tree.get(1, 0, n-1, l-1, r-1).opt * 2 << endl;
    }
    
    return 0;
}