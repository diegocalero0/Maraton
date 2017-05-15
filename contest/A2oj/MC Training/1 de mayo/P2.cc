#include<bits/stdc++.h>
using namespace std;

int main(){
	set<string> res;
	string line, word;
	while(getline(cin, line)){
		word = "";
		for(int i = 0; i < line.length(); i++){
			char chara = tolower(line[i]);
			if( chara >= 97 && chara <= 122){
				word += chara;
				if(i == line.length() - 1){
					if(word.length() > 0){
						res.insert(word);
						word = "";
					}
				}
			}else{
				if(word.length() > 0){
					res.insert(word);
					word = "";
				}
			}
		}
	}

	std::set<string>::const_iterator
    sit (res.begin()),
    send(res.end());
  	for(;sit!=send;++sit){
  		cout << *sit;
  		cout << std::endl;
  	}
	return 0;
}