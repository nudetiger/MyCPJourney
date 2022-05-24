#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// SHORTCUT
struct info
{
    int r, h;
};
bool cmp(pair<int , int> a , pair<int , int> b){
    if(a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}
// --------------

// VARIABLES INITIALIZATION
int n;
vector<info> a;                 // MAIN VECTOR (Radius and Height)
vector<pair<int , int>> b;      // INDEX VECTOR (Radius and Index)
vector<int> newidx;             // SORTED INDEX VECTOR (Sorted Indices)
// --------------

// SEGMENT STRUCT
struct segment_tree {
    
    vector<int> tree;
    int size , n;

    void init(int s) {
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
            return 0;
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


    void print(){
        // print(0 , 0 , n-1);
        // cout << endl;
        // print(1 , 0 , n-1);
        // cout << endl;
        // print(2 , 0 , n-1);

        for(int i = 1; i < 2*n; i++) {
            cout << tree[i] << " ";
        }
    }
    void print(int pos , int l , int r) {
        if(l == r){
            cout << tree[pos] << " ";
            return;
        }
        int mid = (l + r) / 2;
        print(pos*2 , l , mid); print(pos*2+1 , mid+1 , r);
    }
};
// --------------


// DRIVER CODE
int main() {

    freopen("TOWER.INP", "r", stdin);
    freopen("TOWER.OUT", "w", stdout);
    cin >> n;

    a.resize(n);
    b.resize(n);
    newidx.resize(n);

    for(int i = 0 ; i < n ; i++){
        cin >> a[i].r >> a[i].h;
    }
    for(int i = 0 ; i < n ; i++){
        b[i].first = a[i].r;
        b[i].second = i;
    }
    sort(b.begin() , b.end() , cmp);
    for(int i = 0 ; i < n ; i++)
        newidx[b[i].second] = i;

    int answer = 0;
    segment_tree seg;
    seg.init(n);
    seg.update(newidx[0] , a[0].h);
    for(int i = 1 ; i < n ; i++){
        int x = seg.get(newidx[i] + 1);
        if(i == 1) cout << x << " " << a[i].h;
        answer = max(answer , x + a[i].h);
        seg.update(newidx[i] , x + a[i].h);
    }


    cout << endl;
    seg.print();
    cout << endl;
    cout << answer << endl;

    return 0;
}
// --------------