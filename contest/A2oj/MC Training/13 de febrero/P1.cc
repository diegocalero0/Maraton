#include<bits/stdc++.h>
using namespace  std;
#define debug(x) cout << #x << " = " << x << endl;

int main(){
	string n1, n2;
	while(cin >> n1 && cin >> n2 && n1 != "0" || n2 != "0"){
		int a = 0;
		int b = 0;
		if(n1.length() == 1)
			a = n1[0] - 48;
		if(n2.length() == 1)
			b = n2[0] - 48;
		while(n1.length() > 1){
			a = 0;
			for(int i = 0; i < n1.length(); i++){
				a += n1[i] - 48;
			}
			stringstream conv;
			conv << a;
			n1 = conv.str();
		}
		while(n2.length() > 1){
			b = 0;
			for(int i = 0; i < n2.length(); i++){
				b += n2[i] - 48;
			}
			stringstream conv;
			conv << b;
			n2 = conv.str();
		}
		if(a > b)
			cout << 1 << endl;
		else if(a < b)
			cout << 2 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}