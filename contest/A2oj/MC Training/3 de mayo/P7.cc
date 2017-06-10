#include<bits/stdc++.h>
using namespace std;

int mod = 131071;
int main(){
	string line, l;

	while(cin >> line){
		int i = line.length() - 2;
		int r = 0;
		int k;

		while(line[line.length() - 1] != '#')
		{
			cin >> l;
			line += l;
		}

		for(int i = 0; i < line.length() -1; i++){
			r *= 2;
			r += (line[i] == '1');
			r %= mod;
		}
		if(!r)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}