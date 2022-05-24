#include <bits/stdc++.h>

#define int long long

using namespace std;

int m, n;
vector<vector<int>> mt;
vector<int> vst;
vector<int> pre;

void bfs() {

    queue<int> q;
    q.push(0);

    pre[0] = -1;
    vst[0] = 1;

    while(!q.empty()) {

        int u = q.front();
        q.pop();

        for(int i = 0; i < mt[u].size(); i++) {
            int v = mt[u][i];
            
            if(vst[v] == 1) continue;

            q.push(v);
            pre[v] = u;
            vst[v] = 1;


            if(v == n-1) {
                int f = v;
                stack<int> st;
                while(pre[f] != -1) {
                    st.push(f+1);
                    f = pre[f];
                }
                st.push(1);
                while(!st.empty()) {
                    cout << st.top() << " ";
                    st.pop();
                }
                return;
            }


        }

    }

}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("BFS.INP", "r", stdin);
    freopen("BFS.OUT", "w", stdout);

    cin >> n >> m;

    mt.resize(n);
    pre.resize(n);
    vst.assign(n, 0);

    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        mt[u-1].push_back(v-1);
    }
    
    for(int i = 0; i < n; i++) {
        sort(mt[i].begin(), mt[i].end());
    }

    bfs();

    return 0;
}