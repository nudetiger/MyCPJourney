#include <bits/stdc++.h>
using namespace std ;
#define name "FORTRESS"
#define op freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define f(a,b,c) for (int a=b;a<=c;a++)

long long i,n,k,a[1000000],t[1000000];
int main()
{
    op;
    cin >> n >> k ;
    f(i,1,n-1) cin >> a[i] ;
    t[1] = a[1] ;
    if ( k==1 ) t[2] = a[2] ;
    else if ( k==3 ) t[2] = a[1] ;
         else t[2] = a[1] + a[2] ;
    f(i,3,n)
        if ( k==i+1 ) t[i] = min(t[i-1],t[i-2] + a[i]) ;
        else t[i] = min(t[i-1],t[i-2]) + a[i] ;

    cout << t[n-1] ;
    return 0;
}
