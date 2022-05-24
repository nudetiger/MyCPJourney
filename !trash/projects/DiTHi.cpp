#include<iostream>
#include <math.h>

using namespace std;

int main() {
    int i,j,n,m;
    int sum;
    double s;
    int x[10^9], y[10^9];
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
    	cin >> x[i-1];
	}
	for(i = 1; i <= m; i++) {
    	cin >> y[i-1];
	}
	
	for(i = 1; i <= m; i++){
		//MainCode
		sum = 0;
		s = y[i-1];
		for(j = 1; j <= n; j++){
			s = ceil(s / x[j-1]);
			sum = sum + s;
		}
		if(y[i-1] == 0) {
			sum = 0;
		} else if (y[i-1] == 1) {
			sum = n;
		}
		cout << "\n" << sum;
	}
	
}

