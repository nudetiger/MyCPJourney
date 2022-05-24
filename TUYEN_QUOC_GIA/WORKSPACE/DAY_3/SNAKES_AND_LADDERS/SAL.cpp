#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int m, n;
int vst[100];
int dis[100];
vector<int> gmap[100];

void bfs() {
    
    queue<int> q;
    q.push(0);
    vst[0] = 1;
    dis[0] = 0;

    while(!q.empty()) {

        int u = q.front();
        q.pop();

        for(int i = 1; i <= min(99-u, 6); i++) {
            int v = u + i;

            if(vst[v] == 1) continue;
            vst[v] = 1;
            if(!gmap[v].empty()) {
                v = gmap[v].back();
                vst[v] = 1;
            }
            dis[v] = dis[u] + 1;
            q.push(v);

            if(v == 99) {
                cout << dis[v] << endl;
                return;
            }

        }

    }

    cout << -1 << endl;

}

void solve() {

    for(int i = 0; i < 100; i++) {
        dis[i] = -1; vst[i] = 0; gmap[i].clear();
    }
    int a, b;


    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        gmap[a-1].push_back(b-1);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        gmap[a-1].push_back(b-1);
    }

    bfs();

}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("SAL.INP", "r", stdin);
    freopen("SAL.OUT", "w", stdout);
    
    int t;
    cin >> t;
    while(t--) solve(); 
    
    return 0;
}