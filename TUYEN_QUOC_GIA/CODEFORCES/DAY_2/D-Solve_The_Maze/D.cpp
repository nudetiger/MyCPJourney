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

int m_x[4] = {0, 0, 1, -1};
int m_y[4] = {1, -1, 0, 0};

int n, m;

vector<II> bad;
vector<II> good;
string g[51];

map<II, int> vst;

void dfs() {
    int cnt = 0;
    vst[{n-1, m-1}] = 1;
    stack<II> st;

    st.push({n-1, m-1});

    while(!st.empty()) {

        II u = st.top();
        st.pop();

        for(int i = 0; i < 4; i++) {
            int x = max(min(u.fs + m_x[i], n-1), 0ll);
            int y = max(min(u.sc + m_y[i], m-1), 0ll);

            II v = {x, y};
            if(vst[v] == 1 || g[x][y] == '#') continue;

            vst[v] = 1;
            if(g[x][y] == 'G') cnt ++;
            st.push(v);
        }
    }

    if(cnt == good.size()) cout << "Yes\n";
    else cout << "No\n";

}


void solve() {
    bad.clear();
    good.clear();
    vst.clear();

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> g[i];
        for(int j = 0; j < m; j++) {
            if(g[i][j] == 'B') bad.push_back({i, j});
            else if(g[i][j] == 'G') good.push_back({i, j});
        }
    }

    if(good.size() == 0) {
        cout << "Yes\n";
        return;
    }

    for(int i = 0; i < bad.size(); i++) {
        II b = bad[i];
        
        for(int j = 0; j < 4; j++) {
            int x = max(min(b.fs + m_x[j], n-1), 0ll);
            int y = max(min(b.sc + m_y[j], m-1), 0ll);
            
            if(g[x][y] == 'G' || (x == n-1 && y == m-1)) {
                cout << "No\n";
                return;
            }
            g[x][y] = '#';
        }
    }

    dfs();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("D.INP", "r", stdin);
    freopen("D.OUT", "w", stdout);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}