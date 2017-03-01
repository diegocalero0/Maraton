#include<bits/stdc++.h>
using namespace std;

int main(){
	double curr, sum = 0, amount = 0;
	char f;
	cin >> f;
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 12; j++){
			cin >> curr;
			if(i > j)
				sum += curr, amount++;
		}
	}
	double ave = sum / amount;
	if(f == 'S')
		printf("%.1f\n", sum);
	else
		printf("%.1f\n", ave);
	return 0;
}
