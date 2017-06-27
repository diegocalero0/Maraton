#include<bits/stdc++.h>
using namespace std;

int main(){

	string s;

	while(getline(cin, s)){
		int l, r;
		int flag = 0;
		int res;
		int i = s.length();
		for(i = s.length() - 1; i >= 0; i -= 2){
			if(s[i] >= '0' && s[i] <= '9'){
				if(flag == 2){
					cout << "Invalid expression." << endl;
					break;
				}
				if(flag == 0){
					r = s[i] - 48;
					flag = 1;
				}
				else{
					l = s[i] - 48;
					flag = 2;
				}
			}else{
				if(flag != 2){
					cout << "Invalid expression." << endl;
					break;
				}
				if(s[i] == '+')
					r = r + l;
				if(s[i] == '-')
					r = r - l;
				if(s[i] == '*')
					r = r * l;
				if(s[i] == '/'){
					if(l == 0){
						cout << "Division by zero." << endl;
						break;
					}else{
						r = floor(r / l);
					}
				}
				flag = 1;
			}
		}
		if(i == -2)
			cout << r << endl;
	}

	return 0;
} 