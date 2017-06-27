#include<bits/stdc++.h>
using namespace std;

bool decF(const int &a, const int &b){
	return a > b;
}

int main(){

	int n, top, res = 0, last = 0;
	cin >> n;
	n *= 2;
	vector<int> box;
	string oper;
	while(n--){
		cin >> oper;

		if(oper == "add"){
			cin >> top;
			box.push_back(top);
		}else{
			last++;
			if(box.back() == last){
				box.pop_back();
			}else if(box.size() > 0){
				res++;
				while(box.size() > 0)
					box.pop_back();
			}
		}
		

	}
	cout << res << endl;
	return 0;
}