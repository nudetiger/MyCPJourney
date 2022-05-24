#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

#define int long long

using namespace std;

int m, n, start;
vector<vector<int>> mt;
vector<int> vst;
vector<int> dis;

void bfs() {

    queue<int> q;
    q.push(start);

    dis[start] = 0;
    vst[start] = 1;

    while(!q.empty()) {

        int u = q.front();
        q.pop();

        for(int i = 0; i < mt[u].size(); i++) {
            int v = mt[u][i];
            
            if(vst[v] == 1) continue;

            q.push(v);
            dis[v] = dis[u] + 6;
            vst[v] = 1;
        }

    }

}

void solve(int t) {
    cin >> n >> m;
    
    mt.assign(n, vector<int>());
    dis.assign(n, -1);
    vst.assign(n, 0);

    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        mt[u-1].push_back(v-1);
        mt[v-1].push_back(u-1);
    }
    
    cin >> start;
    start -= 1;

    bfs();

    for(int i = 0; i < n; i++) {
        if(i == start) continue;
        cout << dis[i] << " ";
    }
    cout << "\n";
    
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("BFS.INP", "r", stdin);
    freopen("BFS.OUT", "w", stdout);

    int t;
    cin >> t;
    while(t--) solve(t);

    return 0;
}