#include <iostream>
#include <cmath>

#define ll long long
#define ull unsigned long long

using namespace std;

float quangcao(long a[], long b[], long n, long w, long h) {

    ll high = pow(10, 17);
    ll low = 0;
	
	ll k = (high - low)/2;
    bool correct = false;
    ll max = 0;

    long loop = 0;
    while (true)
    {   
        loop ++;
        ll height;
        ll width;
        ll x = w*pow(10, 16)/k;
        ll y = h*pow(10, 16)/k;
        height = 0;
        width = x;
        long i = 0;

        while(i < n){
            height += b[i]*pow(10, 9);
            if(height > y) {
                correct = false;
                break;
            }

            long line = 0;
            while(width > 0) {
                if(width - a[i]*pow(10, 9) < 0) {
                    width = x;
                    break;
                }
                if(line >= 1 && b[i] != b[i-1]) {
                    width = x;
                    break;
                }
                width -= a[i]*pow(10, 9);
                line += 1;
                i += 1;
                if(i == n){
                    if(k > max) {
                        max = k;
                        correct = true;
                        break;
                    } else {
                        return k;                    
                    }
                }
            }
        }

            if(correct) {
                low = k;
                if(height == y) {
                    return k;
                }
            } else {
                high = k;
            }

            k = (low+high)/2;
            if((low/10 == high/10) || (k/10 == low/10) || (k/10 == high/10)) {
                return k;
            }
    }
    
    return 0;
}

int main() {
	
    long n, w, h;
    freopen("D.inp" , "r" , stdin);
    freopen("D.out" , "w" , stdout);
    
    cin >> n >> w >> h;
    long a[n];
    long b[n];

    for(long i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    ll ans = quangcao(a, b, n, w, h)/10;
    string str = to_string(ans);
    str.insert(str.size() - 6, ".");
    cout << str;
    return 0;
}
