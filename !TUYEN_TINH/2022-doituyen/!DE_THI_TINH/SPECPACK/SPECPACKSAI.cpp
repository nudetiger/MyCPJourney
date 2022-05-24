#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

bool cmp(pii a, pii b)  {

    if(a.second < b.second) return true;
    
    return false;

}

int lis(int n, vector<pii>& v) {

    vector<int> seq;
    int i = 0;
    for(i = 0; i < n; i ++) {
        if(v[i].first == 0 || v[i].first == 1) continue;
        seq.push_back(v[i].first);
        break;
    }
    for(i = i + 1; i < n; i ++) {
        if(v[i].first == 0 || v[i].first == 1) continue;
        if(seq.back() > v[i].first) {
            seq.push_back(v[i].first);
        } else {
            int ind = lower_bound(seq.begin(), seq.end(), v[i].first, greater<int>()) - seq.begin();
            seq[ind] = v[i].first;
        }
    }

    return seq.size();
}

void solve() {
    int n;
    cin >> n;
    vector<pii> v(n);
    for(int i = 0; i < n; i ++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());

    int m = v[n-1].first;
    for(int i = 2; i * i <= m; i += 2) {
        if(i == 4) i--;
        int ind = lower_bound(v.begin(), v.end(), make_pair(i*i, 0)) - v.begin();
        for(int j = ind; j < n; j++) {
            if(v[j].first == 0) continue;
            if(v[j].first % i == 0) {
                v[j].first = 0;
            } 
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++) {
        cout << v[i].first << " ";
    }
    cout << "\n";
    int ans = lis(n, v);
    cout << ans;
}

void generate(int l, int r) {
    freopen("SPECPACK.INP", "w", stdout);
    //srand(time(NULL));
    int n = rand() % (l-r) + l;
    cout << n << "\n";
    for(int i = 0; i < n; i++) cout << rand() << "\n";
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    
    freopen("SPECPACK.INP", "r", stdin);
    freopen("SPECPACK.OUT", "w", stdout);

    //generate(10, 11);
    solve();

    return 0;
}