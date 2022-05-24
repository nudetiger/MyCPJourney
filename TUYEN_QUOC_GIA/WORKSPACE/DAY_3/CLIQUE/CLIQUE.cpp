#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

#define int long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int l = 1, r = n+1;
    
    int k;
    while(l+1 < r) {
        k = (l + r) / 2;

        int g1 = n % k;
        int g2 = k - g1;
        int sz1 = n / k + 1;
        int sz2 = n / k;
        int val = g1 * sz1 * g2 * sz2 + g1 * (g1 - 1) * sz1 * sz1 / 2 + g2 * (g2 - 1) * sz2 * sz2 / 2;
        
        if(val < m) l = k;
        else r = k;
    }
    cout << r << "\n";
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("CLIQUE.INP", "r", stdin);
    freopen("CLIQUE.OUT", "w", stdout);
    
    int t;
    cin >> t;
    while(t--) solve(); 
    
    return 0;
}