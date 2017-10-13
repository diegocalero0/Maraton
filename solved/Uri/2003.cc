#include<bits/stdc++.h>
using namespace std;

int main(){


	int h, m;
	char c;
	
	while(cin >> h >> c >> m){
		int en = 8 * 60;
		int be = h * 60 + m + 60;
		
		cout << "Atraso maximo: ";
		if(be <= en)
			cout << 0 << endl;
		else
			cout << be - en << endl;
	}

	return 0;
}