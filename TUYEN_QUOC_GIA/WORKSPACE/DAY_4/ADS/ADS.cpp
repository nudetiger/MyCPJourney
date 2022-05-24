#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
int vst[2000];
vector<int> g[2000];

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("ADS.INP", "r", stdin);
    freopen("ADS.OUT", "w", stdout);

    cin >> n >> m;

    int a, b;
    for(int i = 0; i < m; ++i) {
        cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }

    int k = 0;
    for(int i = 0; i < n; ++i) if(!vst[i]) {
        k++;
        queue<int> q; q.push(i);

        while(!q.empty()) {
            int u = q.front(); 
            q.pop();

            for(int i = 0; i < g[u].size(); i++) {
                int v = g[u][i];
                if(vst[v] == 1) continue;
                vst[v] = 1;
                q.push(v);
            } 
        }
    }

    cout << m - n + k;


    return 0;
}