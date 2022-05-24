#include<bits/stdc++.h>
#define name "OFTEN"
#define Enterprise freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
using namespace std;
int main()
{
    Enterprise;
    long long n,d[100001],a[100001];
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    d[0]=0;
    d[1]=a[1];
    d[2]=max(a[1],a[2]);
    d[3]=max(a[1]+a[3],d[2]);
    for (int i=4;i<=n;i++)
    {
        d[i]=max(d[i-2]+a[i],d[i-1]);
    }
    cout<<d[n]<<endl;
    return 0;
}