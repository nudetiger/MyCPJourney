#include<bits/stdc++.h>

using namespace std;
long long d[10000000],n;

int main(){
    freopen("SHOOT.INP","r",stdin);
    freopen("SHOOT.OUT","w",stdout);
    cin >> n;
    d[1]=0;
    d[2]=1;
    d[3]=3;
    for (int i=4; i<=n; i++)
        d[i]=d[i-1]*2-d[i-3];
    cout << d[n];

return 0;
}
