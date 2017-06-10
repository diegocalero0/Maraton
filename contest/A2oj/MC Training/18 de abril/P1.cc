#include<bits/stdc++.h>
using namespace std;

int main(){
	string a;
	int res = 0;
	while(getline(cin, a)){
		res += a.length();
	}

	if(res <= 140)
		cout << "TWEET" << endl;
	else
		cout << "MUTE" << endl;
	return 0;
}