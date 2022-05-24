#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define pii pair<int, int>

int n, k;

int lightimb(vector<pii>& vec) {
    cout << "\n";

    int mark = 0;
    int max_count = 1;
    
    for(int i = 0; i < n; i ++) {
        
    }

    return max_count;
}

int main() {

    freopen("LIGHTIMB.INP", "r", stdin);
    freopen("LIGHTIMB.OUT", "w", stdout);

    cin >> n >> k;
    vector<pii> vec(n);
    int a,b;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        vec[i] = make_pair(a,b);
    }
    sort(vec.begin(), vec.end());

    for(int i = 0; i < n; i ++) {
        cout << vec[i].first << " " << vec[i].second << "\n";
    }

    int ans = lightimb(vec);
    
    cout << ans;

    return 0;
}