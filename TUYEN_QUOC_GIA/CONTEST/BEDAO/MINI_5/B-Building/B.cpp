#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <climits>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>

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

struct BIT {
    int n; int* bit;
    BIT(int n) {
        this->bit = new int[n+2];
        this->n = n;

        for (int i = 0; i <= n + 1; i++) {
            bit[i] = 0;
        }
    }

    void update(int u, int v) {
        int idx = u;
        while (idx <= n) {
            bit[idx] += v;
            idx += (idx & (-idx));
        }
    }

    int get(int u) {
        int i = u, ans = 0;
        while (i > 0) {
            ans += bit[i];
            i -= (i & (-i));
        }
        return ans;
    }

    int sum(int u, int v) {
        return get(v) - get(u-1);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("B.INP", "r", stdin);
    freopen("B.OUT", "w", stdout);

    int n;
    cin >> n;

    BIT bit = BIT(n);
    int h[n+2];
    h[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
        bit.update(i, abs(h[i]-h[i-1]));
    }

    int q;
    cin >> q;
    int a, p, x;
    while(q--) {
        cin >> a >> p >> x;
        if(a == 1) {
            bit.update(p, abs(x-h[p-1]) - abs(h[p]-h[p-1]));
            bit.update(p+1, abs(h[p+1] - x) - abs(h[p+1]-h[p]));
            h[p] = x;
        } else {
            cout << bit.sum(p+1, x) << endl;
        }
    }

    return 0;
}