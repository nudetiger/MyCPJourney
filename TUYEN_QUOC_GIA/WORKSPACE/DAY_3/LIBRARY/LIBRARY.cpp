#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define int long long

using namespace std;

int n, m, lib, road, cnt = 0, cc = 0;
vector<int> ct[100000];
vector<int> vst;

void bfs(int s) {
    
    queue<int> q;
    q.push(s);
    vst[s] = 1;
    
    while(!q.empty()) {
        
        int u = q.front();
        q.pop();
        
        for(int i = 0; i < ct[u].size(); i++) {
            int v = ct[u][i];
            
            if(vst[v] == 1) continue;
            
            vst[v] = 1;
            cnt ++;
            q.push(v);
            
        }
        
    }
    
}

void solve() {
    cin >> n >> m >> lib >> road;
    cnt = 0; cc = 0;

    if(m == 0) {
        cout << lib * n << "\n";
        return;
    }

    vst.assign(n, 0);
    
    int a, b;
    for(int i = 0; i < n; i++) {
        ct[i].clear();
    }
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        ct[a-1].push_back(b-1);
        ct[b-1].push_back(a-1);
    }
    if(lib <= road) {
        cout << lib * n << "\n";
        return;
    }
    
    for(int i = 0; i < n; i++) {
        if(vst[i] == 1) continue;
        bfs(i);
        cc++;
    }
    cout << cc * lib + cnt * road << "\n";
    
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("LIBRARY.INP", "r", stdin);
    freopen("LIBRARY.OUT", "w", stdout);
    
    int q;
    cin >> q;
    while(q--) solve(); 
    
    return 0;
}