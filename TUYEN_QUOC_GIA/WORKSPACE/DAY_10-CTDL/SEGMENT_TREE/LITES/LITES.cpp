#pragma GCC optimize("Ofast")
 
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
 
#define INF 2147483647
 
using namespace std;
 

struct Node {
    int on = 0, off = 1, lazy = 0;   
    void sw() { swap(on, off); }
};

struct Segment_Tree {
    
    int size;
    vector<Node> tree;
    
    Segment_Tree(int n) {
        this->size = 4 * n;
        tree.resize(this->size);

        for(int i = 0; i < n; i++) {
            update(1, 0, n-1, i, i, 0);
        }
    }
    
    void down(int id) {
        if(tree[id].lazy == 1) {
            tree[id * 2].lazy = 1 - tree[id * 2].lazy;
            tree[id * 2].sw();
            
            tree[id * 2 + 1].lazy = 1 - tree[id * 2 + 1].lazy;
            tree[id * 2 + 1].sw();
            
            tree[id].lazy = 0;
        } 
    }
    
    void update(int id, int l, int r, int u, int v, int val) {
        if(v < l || r < u) return;
        if(u <= l && r <= v) {
            if(val > 0) {
                tree[id].sw();
                tree[id].lazy = 1 - tree[id].lazy;
            }
            return;
        }
        
        int m = (l + r) / 2;
        
        down(id);
        update(id * 2, l, m, u, v, val);
        update(id * 2 + 1, m + 1, r, u, v, val);
        
        tree[id].on = tree[id * 2].on + tree[id * 2 + 1].on;
        tree[id].off = tree[id * 2].off + tree[id * 2 + 1].off;
    }
    
    int get(int id, int l, int r, int u, int v) {
        
        if(v < l || r < u) return 0;
        if(u <= l && r <= v) return tree[id].on;
        
        int m = (l + r) / 2;
        
        down(id);
        return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
    }
  
};

 
int main() {
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    freopen("LITES.INP", "r", stdin);
    freopen("LITES.OUT", "w", stdout);
 
	int n, m;
 
	cin >> n >> m;
    
    Segment_Tree tree = Segment_Tree(n);
    
    int a, x, y;
    
	while(m--) {
	    cin >> a >> x >> y;
	    
	    if(a == 0) {
	        tree.update(1, 0, n-1, x-1, y-1, 1);
	    } else {
	        cout << tree.get(1, 0, n-1, x-1, y-1) << " ";
	    }
    }
    
	return 0;
}