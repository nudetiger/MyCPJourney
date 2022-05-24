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

void solve() {

    int n, inp;
    cin >> n;

    set<int> s, s2;
    for(int i = 0; i < n; i++) {
        cin >> inp;
        if(s.count(inp) == 1) s2.insert(inp);
        else s.insert(inp);
    }

    vector<int> er;
    int f = s.size();
    for(auto& c : s) {
        if(s.size() - er.size() <= s2.size()) break; 
        if(s2.count(c) == 0) {
            s2.insert(c);
            er.push_back(c);
        }
    }
    for(int i = 0; i < er.size(); i++) {
        s.erase(er[i]);
    } 

    cout << max(s.size(), s2.size()) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("C.INP", "r", stdin);
    freopen("C.OUT", "w", stdout);
    
    int t;
    cin >> t;
    while (t--) solve();   

    return 0;
}