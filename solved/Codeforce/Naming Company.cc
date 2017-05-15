#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
int main(){

	string s1, s2;
	cin >> s1 >> s2;
	string res1, res2;
	int n = s1.length();
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	reverse(s2.begin(), s2.end());
	deque<char> s1d, s2d;
	for(int i = 0; i < ((n + 1)/2); i++)
		s1d.push_back(s1[i]);
	for(int i = 0; i < ((n)/2); i++)
		s2d.push_back(s2[i]);
	bool flag = true;
	while(n){

		if(flag){
			if(s1d.front() >= s2d.front()){
				res2 += s1d.back();
				s1d.pop_back();
			}else{
				res1 += s1d.front();
				s1d.pop_front();
			}
		}else{
			if(s1d.front() >= s2d.front()){
				res2 += s2d.back();
				s2d.pop_back();
			}else{
				res1 += s2d.front();
				s2d.pop_front();
			}
		}
		n--;
		flag = !flag;
	}
	reverse(res2.begin(), res2.end());
	cout << res1 << res2 << endl;
	return 0;
}