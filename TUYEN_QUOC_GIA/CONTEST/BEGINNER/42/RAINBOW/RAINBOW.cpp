#pragma GCC optimize("Ofast")

#include <iostream>

#include <map>
#include <queue>

#define II pair<int, int>
#define fs first
#define sc second
#define mp(a, b) make_pair(a, b)

using namespace std;

int move_x[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int move_y[8] = {1, -1, 0, 0, 1, -1, 1, -1};

II st, en;

map<II, bool> g, vst;
map<II, int> dis;


void bfs() {

    queue<II> q;
    q.push(st);
    dis[st] = 0;
    vst[st] = 1;
    
    while(!q.empty()) {
        
        II u = q.front();
        q.pop();

        for(int i = 0; i < 8; i++) {

            II v = mp(u.fs + move_x[i], u.sc + move_y[i]);
            
            if(g[v] == true) {
                if(vst[v] == true) continue;

                if(v == en) {
                    cout << dis[u] + 1;
                    return;
                }

                dis[v] = dis[u] + 1;
                vst[v] = true;
                q.push(v);

            }
        }
    }

    cout << -1;


}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("RAINBOW.INP", "r", stdin);
    freopen("RAINBOW.OUT", "w", stdout);

    int n, r, a, b;

    cin >> st.fs >> st.sc >> en.fs >> en.sc;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> r >> a >> b;

        for(int i = a; i <= b; i++) {
            II u = mp(r, i);
            g[u] = true;        
        }
    }

    bfs();
    

    return 0;
}