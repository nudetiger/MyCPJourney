#include <iostream>
using namespace std;

int rev(long a){
	long n = a;
	long reverse = 0, rem;
	
	while(n != 0) {
		rem = n % 10;
    	reverse = reverse * 10 + rem;
    	n /= 10;
  	}
	return reverse;	
}


int main() {
	
	long n = 295;
	int test = 100;
	int i = 1;
	
	long a = n;
	for(i = 1; i < test; i++) {
		
		if(rev(n) == n) {
			break;
		} else {
			n += rev(n);
		}
		
	}
	
	cout << "Start number: " << a << "\n";
	cout << "Palindrome: " << n << "\n";
	cout << "Attempts: " << i << "\n";
	
	return 0;
}
