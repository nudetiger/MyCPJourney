#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hackerlandRadioTransmitters(vector<int>& x, int k, int n) {
    
    int ans = 0;

    int i = lower_bound(x.begin(), x.end(), x[0] + k) - x.begin();
    //int i = 0;

    if(i >= n) {
        return 1;
    } 
    
    while(i < n) {
        
        ans ++;
        
        i = upper_bound(x.begin()+i, x.end(), x[i] + k) - x.begin();
        int tmp = i;
        if(i >= n) {
            break;
        }
        i = lower_bound(x.rbegin(), x.rend(),
            x[i] + k, greater<int>()) - x.rbegin();
        i = n - 1 - i;

        if(i >= n-1) {
            ans ++;
            break;
        }
        
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("HACKERLAND.INP", "r", stdin);
    freopen("HACKERLAND.OUT", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    vector<int> xtmp(n), x;
    for(int i = 0; i < n; i++) {
        cin >> xtmp[i];
    }
    sort(xtmp.begin(), xtmp.end());
    
    x.push_back(xtmp[0]);
    for(int i = 1; i < n; i++) {
        if(xtmp[i] != xtmp[i-1]) {
            x.push_back(xtmp[i]);
        }
    }
    n = x.size();

    int ans = hackerlandRadioTransmitters(x, k, n);
    cout << ans;
    
    return 0;
}