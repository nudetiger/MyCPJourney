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

double cmb(int n, int r) {
    if(r == n) return 1;
    if(r > n) return 0;
    if(r > n - r) r = n - r;
    int ans = 1;
    for(int i = 1; i <= r; i++) {
        ans = ans * (n - r + i) / i;
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("B.INP", "r", stdin);
    freopen("B.OUT", "w", stdout);
    
    string s1, s2;
    cin >> s1 >> s2;

    int n =  s1.size();

    int d = 0, pos = 0, x = 0;

    for (int i = 0; i < n; i++) {
        if(s1[i] == '+') pos++;
        else if(s1[i] == '-') pos--;
        
        if(s2[i] == '+') d++;
        else if(s2[i] == '-') d--;
        else x++;
    }

    int f = abs(d - pos);
    if(x < f) {
        cout << "0.000000000000" << endl;
        return 0;
    }

    if((f + x) % 2 != 0) {
        cout << "0.000000000000" << endl;
        return 0;
    }

    double ans = cmb(x, (x+f)/2) / (1 << x);

    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}