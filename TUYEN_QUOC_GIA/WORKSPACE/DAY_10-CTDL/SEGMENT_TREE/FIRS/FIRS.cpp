#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define int long long
#define INF 9223372036854775807

using namespace std;

struct Node {
    int v, pos;
    Node(int v, int pos) {
        this->v = v;
        this->pos = pos;
    }
};

struct Segment_Tree {

    int size; 
    vector<Node> seg;

    Segment_Tree(int n) {
        this->size = 4 * n;
        seg.assign(4 * n, Node(0, 0));
    }

    void update(int id, int l, int r, int i, int v) {
        if(i < l || i > r) return;
        if(l == r) {
            seg[id].v += v;
            seg[id].pos = i;
            return;
        }

        int m = (l + r) / 2;
        update(id*2, l, m, i, v);
        update(id*2 + 1, m + 1, r, i, v);

        if(seg[id * 2].v <=  seg[id * 2 + 1].v) {
            seg[id].v = seg[id * 2].v;
            seg[id].pos = seg[id * 2].pos;
        } else {
            seg[id].v = seg[id * 2 + 1].v;
            seg[id].pos = seg[id * 2 + 1].pos;
        }
        
    }  

    int get(int id, int l, int r, int u, int v) {
        if(v < l || r < u) return INF;
        if(u <= l && r <= v) return seg[id].v;

        int m = (l + r) / 2;
        return min(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
    }

};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("FIRS.INP", "r", stdin);
    freopen("FIRS.OUT", "w", stdout);

    int n;
    cin >> n;
    
    vector<int> arr(n, 0);
    Segment_Tree tree = Segment_Tree(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        tree.update(1, 0, n-1, i, arr[i]);
    }

    int day = 0;

    while(tree.seg[1].v < 28112005) {

        day ++;
        int pos = tree.seg[1].pos;

        tree.update(1, 0, n-1, pos, 128112005);

        if(pos > 0) tree.update(1, 0, n-1, pos-1, 128112005);
        if(pos < n-1) tree.update(1, 0, n-1, pos+1, 128112005);

        
    }
    cout << day;

    return 0;
}