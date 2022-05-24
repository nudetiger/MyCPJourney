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



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("D.INP", "r", stdin);
    freopen("D.OUT", "w", stdout);
    
    int n;
    cin >> n;

    vector<int> a(n+1), v(n+1, 0), v2(n+1, 0);

    set<int> s;
    for(int i = 1; i <= n; i++) s.insert(i);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s.erase(a[i]);
        v[a[i]] ++; v2[a[i]] = 1;
    }

    set<int>::iterator it = s.begin();
    cout << s.size() << endl;
    for(int i = 1; i <= n; i++) {
        if(*it < a[i] && v[a[i]] >= 2) {
            v[a[i]] --;
            a[i] = *it;
            it++;
        } else if(*it > a[i]) {
            if(v2[a[i]] == 1) v2[a[i]] = 0;
            else a[i] = *it, it++;
        }
        cout << a[i] << " ";
    }

    return 0;
}