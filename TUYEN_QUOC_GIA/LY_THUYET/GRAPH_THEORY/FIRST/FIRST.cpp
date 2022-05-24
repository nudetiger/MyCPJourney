#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <climits>

#include <vector>
#include <bitset>
#include <set>
#include <string>

#define II pair<int, int>
#define fs first
#define sc second
#define mp(a, b) make_pair(a, b)
#define LINF 9223372036854775807
#define INF 2147483647

using namespace std;

void solve() {
    char x[4];
    string q;
    int n, k, u, v;
    cin >> x >> n >> k;

    set<int> sset;
    if(k == 1) for(int i = 1; i <= n; i++) sset.insert(i);

    vector<set<int>> matrix(n+1, sset); 
    
    cin >> q;
    while(q != "") {
        if(q == "ADD") {
            cin >> u >> v;
            matrix[u].insert(v);
        } else if(q == "DEL") {
            cin >> u >> v;
            matrix[u].erase(v);
        } else if(q == "ANY") {
            int found = 0;

            for(int i = 1; i <= n; i++) {
                if(matrix[i].size() == 0) continue;

                set<int>::iterator it = --matrix[i].end();
                matrix[i].erase(it);

                cout << i << " " << *it << "\n"; 
                found = 1;
                break;
            }

            if(found == 0) {
                cout << -1 << "\n";
            }

        } else if(q == "EDG") {
            cin >> u >> v;
            (matrix[u].count(v)) ? cout << "YES" << "\n" : cout << "NO" << "\n";
        }
        q = "";
        cin >> q;
    }
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("FIRST.INP", "r", stdin);
    freopen("FIRST.OUT", "w", stdout);

    solve();

    return 0;
}