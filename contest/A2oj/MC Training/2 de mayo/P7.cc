#include<bits/stdc++.h>
using namespace std;

int main(){

	map<string, int> mymap;
	mymap["suco de laranja"] = 120;
	mymap["morango fresco"] = 85;
	mymap["mamao"] = 85;
	mymap["goiaba vermelha"] = 70;
	mymap["manga"] = 56;
	mymap["laranja"] = 50;
	mymap["brocolis"] = 34;

	int t, n;
	string line;
	int res;
	while(cin >> t && t){
		res = 0;
		for(int i = 0; i < t; i++){
			cin >> n;
			getline(cin, line);
			res += (n * mymap[line.substr(1)]);
		}
		
		if(res > 130)
			cout << "Menos " << (res - 130) << " mg" << endl;
		else if(res < 110)
			cout << "Mais " << (110 - res) << " mg" << endl;
		else
			cout << res << " mg" << endl;
	}

	return 0;
}