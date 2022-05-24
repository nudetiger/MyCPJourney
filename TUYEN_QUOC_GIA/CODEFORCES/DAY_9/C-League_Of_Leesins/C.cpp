#include <bits/stdc++.h>

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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("C.INP", "r", stdin);
    freopen("C.OUT", "w", stdout);
    
    int n;
    cin >> n;

    vector<int> a(n+1, 0), vst(n+1, 0);
    vector<set<int>> v(n+1);

    int x, y, z;
    for(int i = 1; i <= n-2; i++) {
        cin >> x >> y >> z;
        v[x].insert(y); v[x].insert(z);
        v[y].insert(z); v[y].insert(x);
        v[z].insert(x); v[z].insert(y);

        a[x]++; a[y]++; a[z]++;
    }

    int f = -1, l = -1, k1 = -1, k2 = -1;
    for(int i = 1; i <= n; i++) {
        if(f == -1 && a[i] == 1) {
            f = i;
        } else if(a[i] == 1) {
            l = i;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(k1 == -1 && a[i] == 2) {
            k1 = i;
        } else if(a[i] == 2) {
            k2 = i;
        }
    }

    queue<int> q;
    vst[f] = 1;
    q.push(f);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vst[u] = 1; 
        cout << u << " ";
        if(vst[k1] == 1 && vst[k2] == 0) vst[k2] = 2;
        else if(vst[k2] == 1 && vst[k1] == 0) vst[k1] = 2;
        for(auto& t : v[u]) {
            if(vst[t]) continue;
            a[t]--;
            if(a[t] == 1) q.push(t); 
        }
    }
    if(vst[k1] == 2) cout << k1 << " ";
    else cout << k2 << " ";

    cout << l << endl;

    return 0;
}