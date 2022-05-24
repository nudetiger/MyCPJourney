#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node {

    vector<Segment_Tree> sub;
    int v, y1 = -1, y2 = -1, r = 0;
};

struct Segment_Tree {

    int size;

    vector<Node> tree;
    
    Segment_Tree(int n) {
        this->size = 4 * n;
        tree.resize(this->size);
        //sub.resize(this->size);
    }

    void down(id) {
        int t1 = tree[id].l1;
        int t2 = tree[id].l2;
        if(t1 < 0 && t2 < 0) return;

        if(tree[2*id].r == 1) {

            return;
        }
        if(tree[2*id].l1 > t1) tree[2*id].l1 = t1;
        if(tree[2*id].l2 < t2) tree[2*id].l2 = t2;

        if(tree[2*id]. l1 > t1) tree[2*id].l1 = t1;
        if(tree[2*id].l2 < t2) tree[2*id].l2 = t2;

    }

};

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("AREA.INP", "r", stdin);
    freopen("AREA.OUT", "w", stdout);

    int n;
    int x, y, x2, y2;
    cin >> x >> y >> x2 >> y2;


    return 0;
}