#include <bits/stdc++.h>

#define int long long
#define INF 9223372036854775807

using namespace std;

struct Node {
    int lazy = 0; int v;
};

struct BIT {
    int n, *bit1, *bit2;

    int get(int b[], int i){
        int sum = 0;
        i++;
        while (i > 0) {
            sum += b[i];
            i -= i & (-i);
        }
        return sum;
    }

    void update(int b[], int i, int val) {
        i = i + 1;
        while (i <= n) {
            b[i] += val;
            i += i & (-i);
        }
    }

    void updateRange(int l, int r, int value) {
        update(bit1, l, value);
        update(bit1, r + 1, -value);
        update(bit2, l, value * (l - 1));
        update(bit2, r + 1, -value * r);
    }

    int sum(int x) {
        return (get(bit1, x) * x) - get(bit2, x);
    }

    int range(int l, int r) {
        return sum(r) - sum(l - 1);
    }


    BIT(int n) {
        this->n = n + 1;
        bit1 = new int[n + 2];
        bit2 = new int[n + 3];

        bit2[n+2] = 0;
        for (int i = 0; i <= n + 1; i++) {
            bit1[i] = bit2[i] = 0;
        }
    }

};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("INCSUMIT.INP", "r", stdin);
    freopen("INCSUMIT.OUT", "w", stdout);

    int n, q, inp;
    cin >> n;

    BIT tree = BIT(n);
    for (int i = 1; i <= n; i++){
        cin >> inp;
        tree.updateRange(i, i, inp);
    }
    
    
    
    cin >> q;

    int x, y, z, w;
    while(q--) {
        cin >> x >> y >> z;
        if(x == 1) {
            cin >> w;
            tree.updateRange(y, z, w);
        } else {
            cout << tree.range(y, z) << "\n";
        }     
    }

    return 0;
}