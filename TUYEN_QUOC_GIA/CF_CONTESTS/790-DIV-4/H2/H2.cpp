#pragma GCC optimize("Ofast")
 
#include <bits/stdc++.h>

#define int long long

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
                    tree[id].begin());
    }
    
    int get(int id, int l, int r, int u, int v, int k) {
        if (v < l || r < u) return 0;
        if (u <= l && r <= v) 
            return tree[id].size() 
                - (lower_bound(tree[id].begin(), tree[id].end(), k) - tree[id].begin());

        int mid = (l + r) / 2;
        return get(id * 2, l, mid, u, v, k) + get(id * 2 + 1, mid + 1, r, u, v, k);
    }
  
};

void solve() {
    int n, ans = 0;
    cin >> n;

    int arr[n];    
    Segment_Tree tree = Segment_Tree(n);

    for(int i = 0; i < n; i++) cin >> arr[i];
    tree.update(1, 0, n-1, arr);

    for(int i = 0; i < n; i++) ans += tree.get(1, 0, n-1, 0, i, arr[i]) - 1;
    cout << ans << endl;
}

int32_t main() {
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    freopen("H2.INP", "r", stdin);
    freopen("H2.OUT", "w", stdout);

    int t;
    cin >> t;
    while (t--) solve();

	return 0;
}