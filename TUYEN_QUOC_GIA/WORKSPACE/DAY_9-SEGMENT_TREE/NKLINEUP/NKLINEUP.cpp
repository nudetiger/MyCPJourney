#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <algorithm>

#define int long long
#define INF 9223372036854775807

using namespace std;

struct Node {
    int mx, mn;
};

struct Segment_Tree {

    int size;
    vector<Node> tree;

    Segment_Tree(int n) {
        this->size = 4*n;
        tree.resize(this->size);
    }

    void update(int id, int l, int r, int i, int v) {
        if(i < l || i > r) return;
        if(l == r) {
            tree[id].mx = v;
            tree[id].mn = v;
            return;
        }

        int mid = (l + r) / 2;
        update(id * 2, l, mid, i, v);
        update(id * 2 + 1, mid + 1, r, i, v);

        tree[id].mn = min(tree[id*2].mn, tree[id*2 + 1].mn);
        tree[id].mx = max(tree[id*2].mx, tree[id*2 + 1].mx);
    }

    int getMin(int id, int l, int r, int u, int v) {

        if(v < l || r < u) return INF;
        if(u <= l && r <= v) return tree[id].mn;

        int mid = (l + r) / 2;
        return min(getMin(id*2, l, mid, u, v), getMin(id*2 + 1, mid + 1, r, u, v));
    }

    int getMax(int id, int l, int r, int u, int v) {

        if(v < l || r < u) return -INF;
        if(u <= l && r <= v) return tree[id].mx;

        int mid = (l + r) / 2;
        return max(getMax(id*2, l, mid, u, v), getMax(id*2 + 1, mid + 1, r, u, v));
    }

    int get(int id, int l, int r, int u, int v) {
        return getMax(id, l, r, u, v) - getMin(id, l, r, u, v);
    }

};

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("NKLINEUP.INP", "r", stdin);
    freopen("NKLINEUP.OUT", "w", stdout);

    int n, q;
    cin >> n >> q;
    
    int arr[n];
    Segment_Tree tree = Segment_Tree(n);
 
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        tree.update(1, 0, n-1, i, arr[i]);
    }

    int a, b;

    while(q--) {
        cin >> a >> b;
        cout << tree.get(1, 0, n-1, a-1, b-1) << endl;
    }

    return 0; 
}