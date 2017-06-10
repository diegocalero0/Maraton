#include<bits/stdc++.h>
using namespace std;

int main(){
	int T, c, d;
	cin >> T;

	while(T--){
		cin >> c >> d;
		long f = 1, s = 1;
		for(int i = 0; i < c; i++){
			f *= 26;
		}
		for(int i = 0; i < d; i++){
			s *= 10;
		}
		if(f == 1 && s == 1)
			cout << 0 << endl;
		else if(f == 1 && s != 1)
			cout << s << endl;
		else if(f != 1 && s == 1)
			cout << f << endl;
		else
			cout << f * s << endl;
	}
}