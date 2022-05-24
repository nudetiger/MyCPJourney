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

vector<int> ans, g[200005];
bool vis[200005];
int inputorder[200005], relorder[200005];

bool cmp(int a,int b){
    return relorder[a]<relorder[b];
}

int32_t main() {	
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    freopen("D.INP", "r", stdin);
    freopen("D.OUT", "w", stdout);

    int n, x, a, b;
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 0; i < n; i++) {
        cin >> inputorder[i];
        relorder[inputorder[i]] = i;
    }

    for(int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end(), cmp);

    queue<int> q;
    q.push(1);
    memset(vis, false, sizeof(vis));

    while(!q.empty()){
        queue<int> temp;
        while(!q.empty()) {
            int x = q.front();
            q.pop();

            ans.push_back(x);
            vis[x] = true;

            for(int j = 0;j < g[x].size(); j++)
                if(vis[g[x][j]] == 0)
                    temp.push(g[x][j]);
        }
        q = temp;
    }
    for(int i = 0; i < n; i++)
        if(inputorder[i] != ans[i]) {
            cout << "No" << endl;
            return 0;
        }

    cout<< "Yes"  << endl;

    return 0;
}