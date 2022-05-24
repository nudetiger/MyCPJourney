#pragma GCC optimize("Ofast")
 
#include <bits/stdc++.h>
 
#define int long long
#define INF 9223372036854775807
 
using namespace std;
 
int32_t main() {
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);

    int n, m;
    cin >> n >> m;
 
    set<int> s;
    int ans[n+1];
    for(int i = 1; i <= n; i++) s.insert(i);
 
    int l, r, x;
    while(m--) {
        cin >> l >> r >> x;
        vector<int> toErase;
        for(set<int>::iterator it = s.lower_bound(l); it != s.end(); it++) {
            if(*it > r) break;
            ans[*it] = x;
            if(*it != x) toErase.push_back(*it);
        }
        for(int i = 0; i < toErase.size(); i++) s.erase(toErase[i]);
    }
    set<int>::iterator it = s.begin();
    ans[*it] = 0;
 
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
 
	return 0;
}