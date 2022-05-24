#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
using namespace __gnu_pbds;



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("H1.INP", "r", stdin);
    freopen("H1.OUT", "w", stdout);

    int t, n, inp, ans;
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n;

        tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> s;
        for(int i = 0; i < n; i++){
            cin >> inp;
            ans += s.size() - s.order_of_key(inp);
            s.insert(inp);
        } 

        cout << ans << endl;
    }
    

    return 0;
}