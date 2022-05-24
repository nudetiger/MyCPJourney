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
    int r = 0;
    bool att = false;   
};

struct Segment_Tree {
    
    int size;
    vector<Node> tree;
    
    Segment_Tree(int n) {
        this->size = 4 * n;
        tree.resize(this->size);
    }
    
    void update(int id, int l, int r, int i, int val) {
        if(i < l || r < i) return;
        if(l == r) {
            if(val == 0) {
                tree[id].r -= 1;
                if(tree[id].r <= 0) {
                    tree[id].att = false;
                }
            } else {
                tree[id].r += 1;
                tree[id].att = true;
            }
            return;
        }
        
        int m = (l + r) / 2;
        
        update(id * 2, l, m, i, val);
        update(id * 2 + 1, m + 1, r, i, val);
        
        tree[id].att = tree[id * 2].att && tree[id * 2 + 1].att;
    }
    
    bool get(int id, int l, int r, int u, int v) {
        
        if(v < l || r < u) return 1;
        if(u <= l && r <= v) return tree[id].att;
        
        int m = (l + r) / 2;
        
        //tree[id].att = get(id * 2, l, m, u, v) && get(id * 2 + 1, m + 1, r, u, v);
        return get(id * 2, l, m, u, v) && get(id * 2 + 1, m + 1, r, u, v);
    }
  
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("C.INP", "r", stdin);
    freopen("C.OUT", "w", stdout);

    int n, q;

    cin >> n >> q;

    Segment_Tree tx = Segment_Tree(n);
    Segment_Tree ty= Segment_Tree(n);

    
    int t, x, x1, x2, y, y1, y2;

    while(q--) {
        cin >> t;

        if(t == 1) {
            cin >> x >> y;
            tx.update(1, 0, n-1, x-1, 1);
            ty.update(1, 0, n-1, y-1, 1);
        } else if(t == 2) {
            cin >> x >> y;
            tx.update(1, 0, n-1, x-1, 0);
            ty.update(1, 0, n-1, y-1, 0);
        } else {
            cin >> x1 >> y1 >> x2 >> y2;
            //bool attX = tx.get(1, 0, n-1, x1-1, x2-1);
            //bool attY = ty.get(1, 0, n-1, y1-1, y2-1);

            bool att = tx.get(1, 0, n-1, x1-1, x2-1) || ty.get(1, 0, n-1, y1-1, y2-1);

            if(att) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    

    return 0;
}