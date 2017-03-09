#include<bits/stdc++.h>
using namespace std;
string sec;

void process2(){
	if(sec != "")
		cout << '1';
		for(int i = 0; i < sec.length(); i++){
			if(sec[i] == '1')
				cout << '1';
			cout << sec[i];
		}
		cout << '1';
		sec = "";
}

void process(char c, int rep){
	if(rep >= 2 && rep <= 9)
		cout << rep << c;
}

int main(){
	int rep;
	string s;
	char curr;
	while(getline(cin, s)){
		sec = "";
		for(int i = 0; i < s.length(); i++){
			curr = s[i];
			rep = 1;
			if(i == s.length() - 1){
				sec = s[i];
				process2();
			}
			for(int j = i + 1; j < s.length(); j++){
				if(s[j] == curr){
					rep++;
					if(rep == 9 || j == s.length() - 1){
						process(curr, rep);
						i = j;
						break;
					}
				}else{
					if(rep >= 2){
						process(curr, rep);
						i = j - 1;
						break;
					}else{
						sec += curr;
						if(j + 1 == s.length()){
							i = j;
							sec += s[j];
							process2();
							break;
						}else if(s[j] == s[j + 1]){
							i = j - 1;
							process2();
							break;
						}
						curr = s[j];
					}
				}
			}
		}
		
		cout << endl;
	}

	return 0;
}