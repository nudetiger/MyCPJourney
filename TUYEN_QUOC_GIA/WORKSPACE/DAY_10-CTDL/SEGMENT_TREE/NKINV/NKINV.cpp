#pragma GCC optimize("Ofast")
 
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Segment_Tree {
    
    int size;
    vector<vector<int>> tree;
    
    Segment_Tree(int n) {
        this->size = 4 * n;
        tree.resize(this->size);
    }
    
    void update(int id, int l, int r, int* arr) {
        if(l == r) {
            tree[id].push_back(arr[l]);
            return;
        }
        int m = (l + r) / 2;
        
        update(id * 2, l, m, arr);
        update(id * 2 + 1, m + 1, r, arr);

        tree[id].resize(tree[id * 2].size() + tree[id * 2 + 1].size());
        merge(tree[id * 2].begin(), tree[id * 2].end(), 
                tree[id * 2 + 1].begin(), tree[id * 2 + 1].end(), 
                    tree[id].begin(), greater<int>());
    }
    
    int get(int id, int l, int r, int u, int v, int k) {
        if (v < l || r < u) return 0;
        if (u <= l && r <= v) 
            return lower_bound(tree[id].begin(), tree[id].end(), k, greater<int>()) - tree[id].begin();

        int mid = (l + r) / 2;
        return get(id * 2, l, mid, u, v, k) + get(id * 2 + 1, mid + 1, r, u, v, k);
    }
  
};
 
int main() {
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    freopen("NKINV.INP", "r", stdin);
    freopen("NKINV.OUT", "w", stdout);
 
	int n, ans = 0;
    cin >> n;

    int arr[n];    
    Segment_Tree tree = Segment_Tree(n);

    for(int i = 0; i < n; i++) cin >> arr[i];
    tree.update(1, 0, n-1, arr);

    for(int i = 0; i < n; i++) ans += tree.get(1, 0, n-1, 0, i, arr[i]);
    
    cout << ans;
    
	return 0;
}