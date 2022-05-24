#include <bits/stdc++.h>

using namespace std;

struct st {

    vector<int> tree;
    int size , n;

    st(int s) {
        n = s;
        size = 4*n;
        tree.resize(size, 0);
    }

    int get(int x){
        if(x < 0)
            return 0;
        return get(1 , 0 , n-1 , x);
    }
    int get(int pos , int l , int r , int x){
        if(r < x)
            return INT_MIN;
        if(l >= x){
            return tree[pos];
        }
        int mid = (l + r) / 2;
        return max(get(pos*2 , l , mid , x) , get(pos*2+1 ,mid+1 , r , x));
    }


    void update(int x , int val){
        update(1 , 0 , n-1 , x , val);
    }
    void update(int pos , int l , int r , int x, int val){
        if(l > x || r < x)
            return;
        if(l == r && l == x){
            tree[pos] = val;
            return;
        }
        int mid = (l + r) / 2;
        if(x <= mid)
            update(pos*2 , l , mid , x , val);
        else update(pos*2+1 , mid+1 , r , x , val);
        tree[pos] = max(tree[pos*2] , tree[pos*2+1]);
    }

    void print() { 
        int d = 0;
        for(int i = 0; i < size; i++) {
            cout << tree[i] << " ";
            int sad = pow(2, d);
            if(i % sad == 0) {
                cout << "\n";
                d++;
            }
        }
    }

};

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    st tree = st(n);
    for(int i = 0; i < n; i++) tree.update(i, arr[i]);
    tree.print();
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);

    solve();

    return 0;
}