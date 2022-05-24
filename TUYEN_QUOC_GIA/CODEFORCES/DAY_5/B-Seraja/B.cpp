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
    
    freopen("B.INP", "r", stdin);
    freopen("B.OUT", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    int arr[n+1];
    int l[n+1];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    set<int> s;
    for(int i = n-1; i >= 0; i--) {
        s.insert(arr[i]);
        l[i] = s.size();
    }

    int q;
    while(m--) {
        cin >> q;
        cout << l[q-1] << endl;
    }

    return 0;
}