#include <bits/stdc++.h>

using namespace std;

unsigned long long  n;

int main () {
freopen ("modulo.inp","r",stdin);
freopen ("modulo.out","w",stdout);
cin >>n;
n=(((n%2017)*((n+1)%2017))/2)%2017;
n=(n*n)%2017;
cout <<n % 2017;
return 0;
}
