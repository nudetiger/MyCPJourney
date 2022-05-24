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

set<II> s;
vector<II> g[100005];
vector<int> vst(100005, 0), dis(100005, INF);

void dijkstra(int st, int en) {
    vst[st] = 1;
    dis[st] = 0;
    s.insert(mp(dis[st], st));

    while(!s.empty()) {
        II t = *s.begin();
        s.erase(t);
        
        int u = t.sc;
        for(int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].fs, l = g[u][i].sc;
            if(vst[v] == 0) {
                vst[v] = 1;
                dis[v] = dis[u] + l;
                s.insert(mp(dis[v], v));
            } else if(dis[v] > dis[u] + l) {
                s.erase(mp(dis[v], v));
                dis[v] = dis[u] + l;
                s.insert(mp(dis[v], v));
            }
        }
    }

    if(dis[en] == INF) {
        cout << -1 << endl;
        return;
    }

    stack<int> stk;
    int x = en;
    while(dis[x] != 0) {
        for(int i = 0; i < g[x].size(); i++) {
            int v = g[x][i].fs, l = g[x][i].sc;
            if(dis[x] == dis[v] + l) {
                stk.push(x);
                x = v;
                break;
            }
        }
    }

    cout << 1 << " ";
    while(!stk.empty()) {
        cout << stk.top() + 1 << " ";
        stk.pop();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("C.INP", "r", stdin);
    freopen("C.OUT", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    int u, v, w;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        g[u-1].push_back(mp(v-1, w));
        g[v-1].push_back(mp(u-1, w));
    }

    dijkstra(0, n-1);

    return 0;
}