#include<bits/stdc++.h>
using namespace std;
#define esp 1e-10
int main(){

	double l, w, f, s;

	while(cin >> l >> w){
		f = (4 * (w + l) - sqrt(16.0 * (w + l) * (w + l) - 48.0 * (w * l))) / (24.0);
		s = min(l, w) * 0.5;
		printf("%.3f %.3f %.3f\n", f + esp, 0.0, s);
	}

	return 0;
}