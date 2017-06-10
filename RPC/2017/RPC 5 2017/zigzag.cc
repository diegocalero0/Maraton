#include<bits/stdc++.h>
using namespace std;
int n;

int main(){

	cin >> n;
	int k = ceil((double)n / (double)25) + 1;
	
	if(k > 2){
		string res = "a.", concat = "";
		bool flag = true;
		for(int i = 0; i < k - 2; i++){
			if(flag)
				concat += "a";
			else
				concat += "z";
			flag = !flag;
		}
		int acum = (k - 3) * 25;
		int temp = n - acum;
	 	
	 	res = res + concat;
	 	if(temp % 2 == 0){
	 		res[1] = 'a' + (temp / 2);
	 	}else{
	 		if(flag){
	 			//fue una z
	 			res[1] = 'b' + (temp / 2);
	 			res[ res.length() - 1]--;
	 		}else{
				//fue una a
	 			res[1] = 'b' + (temp / 2);
	 			res[ res.length() - 1]++;
	 		}
	 	}
	 	cout << res << endl;
	}else{
		cout << 'a' <<(char)('a' + n) << endl;
	}
	return 0;
}