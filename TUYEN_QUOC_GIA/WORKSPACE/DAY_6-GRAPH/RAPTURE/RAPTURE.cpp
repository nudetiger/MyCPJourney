//#pragma GCC optimize("Os")
// #pragma GCC target("avx,avx2,fma")

#include <iostream>
#include <vector>
#include <set>

#define II pair<int, int>
#define mp(a,b) make_pair(a,b)
#define fs first
#define sc second

using namespace std;

int n, m;
set<II> S;
vector<int> vst, dis;
vector<II> g[50000];

void dijkstra(int s) 
{
	vst[s] = 1;
	S.insert(II(dis[s], s));

	while(!S.empty())
	{
		II t = *S.begin();
		S.erase(t);

		int u = t.sc;

		for(int i = 0; i < int(g[u].size()); i++)
		{   
			int v = g[u][i].fs, w = g[u][i].sc;
			if(vst[v] == 0)
			{

				vst[v] = 1;
				dis[v] = max(w, dis[u]);

				S.insert(II(dis[v], v));

			} else if(dis[v] > max(dis[u], w)) {

				S.erase(II(dis[v], v));

				dis[v] = max(dis[u], w);

				S.insert(II(dis[v], v));

			}
		}
	}
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("RAPTURE.INP", "r", stdin);
    freopen("RAPTURE.OUT", "w", stdout);

    cin >> n >> m;

    vst.assign(n, 0);
    dis.assign(n, 0);

    int a, b, w;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        g[--a].push_back(mp(--b, w));
        g[b].push_back(mp(a, w));
    }

    dijkstra(0);

    if(dis[n-1] == 0) {
        cout << "NO PATH EXISTS";
    } else cout << dis[n-1];

    return 0;
}