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
    int v = 0, lv = 1;
};

struct Segment_Tree {

    int size; 
    vector<Node> seg;

    Segment_Tree(int n) {
        this->size = 4 * n;
        seg.resize(4 * n);
    }

    void update(int id, int l, int r, int i, int v) {
        if(i < l || i > r) return;
        if(l == r) {
            seg[id].v = v;
            seg[id].lv = 1;
            return;
        }

        int m = (l + r) / 2;
        update(id*2, l, m, i, v);
        update(id*2 + 1, m + 1, r, i, v);

        seg[id].lv = seg[id * 2].lv + 1;
        if(seg[id].lv & 1) {
            seg[id].v = seg[id * 2].v ^ seg[id * 2 + 1].v;
        } else {
            seg[id].v = seg[id * 2].v | seg[id * 2 + 1].v;
        }
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("D.INP", "r", stdin);
    freopen("D.OUT", "w", stdout);

    int n, m, inp;

    cin >> n >> m;
    
    int size = (1 << n);
    Segment_Tree tree = Segment_Tree(size);

    for(int i = 0; i < size; i++) {
        cin >> inp;
        tree.update(1, 0, size-1, i, inp);
    }

    int x = ((2 | 6) ^ (4 | 5)) | ((8 | 4) ^ (2 | 3));
    cout << x << endl;


    int p, b;
    while(m--) {
        cin >> p >> b;
        tree.update(1, 0, size-1, p-1, b);
        cout << tree.seg[1].v << endl;
    }
    return 0;
}