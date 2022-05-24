#include <bits/stdc++.h>

#define int long long

using namespace std;

int m, n;
vector<vector<int>> mt;
vector<int> vst;
vector<vector<int>> connect;

void bfs(int x, int start) {

    queue<int> q;
    
    q.push(start);
    vst[start] = 1;
    connect[x].push_back(start);

    while(!q.empty()) {

        int u = q.front();
        q.pop();

        for(int i = 0; i < mt[u].size(); i++) {
            
            int v = mt[u][i];
            if(vst[v] == 1) continue;

            connect[x].push_back(v);
            q.push(v);
            vst[v] = 1;

        }

    }

}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("CONNECT.INP", "r", stdin);
    freopen("CONNECT.OUT", "w", stdout);

    cin >> n >> m;

    mt.resize(n);
    vst.resize(n, 0);

    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        mt[u-1].push_back(v-1);
        mt[v-1].push_back(u-1);
    }
    
    for(int i = 0; i < n; i++) {
        sort(mt[i].begin(), mt[i].end());
    }

    int x = 0;
    for(int i = 0; i < n; i++) {
        if(vst[i] == 1) continue;
        connect.push_back(vector<int>());
        bfs(x, i);
        x++;
    }

    for(int i = 0; i < connect.size(); i++) {
        sort(connect[i].begin(), connect[i].end());
        for(int j = 0; j < connect[i].size(); j++) {
            cout << connect[i][j] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}