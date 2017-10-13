#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin >> t;
	string s;
	cin.ignore();
	while(t--){
		getline(cin, s);
		for(int i = 0; i < s.length(); i++){
			if( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
				s[i] = (s[i] + 3);
		}
		reverse(s.begin(), s.end());
		int m = (s.length() / 2);
		for(int i = m; i < s.length(); i++){
			s[i] = (s[i] - 1);
		}
		cout << s << endl;
	}

	return 0;
}