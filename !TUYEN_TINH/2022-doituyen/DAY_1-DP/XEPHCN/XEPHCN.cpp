#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>

int box(vector<pii>& v, int& n) {

    vector<int> seq;
    seq.push_back(v[0].second);

    for(int i = 0; i < n; i ++) {
        if(seq.back() < v[i].second) {
            seq.push_back(v[i].second);
        } else {
            int ind = lower_bound(seq.begin(), seq.end(), v[i].second) - seq.begin();
            seq[ind] = v[i].second;
        }
    }

    return seq.size();
}


int main(){

    freopen("XEPHCN.INP", "r", stdin);
    // freopen("XEPHCN.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<pii> v, v2;
    int a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(a >= b) v.push_back(make_pair(b,a));
        else v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end());
    v2.push_back(v[0]);
    for(int i = 1; i < n; i++) {
        if(v[i].first != v[i-1].first) v2.push_back(v[i]); 
    }
    
    // for(int i = 0; i < v2.size(); i++) {
    //     cout << v2[i].first << " " << v2[i].second << "\n";
    // }

    int ans = box(v2, n);
    cout << ans << "\n";

    return 0;
}
