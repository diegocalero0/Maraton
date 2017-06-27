#include<bits/stdc++.h>
using namespace std;

int main(){

	double a, b, c;

	cin >> a >> b >> c;
	vector<double> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	sort(v.begin(), v.end());
	a = v.back(); v.pop_back();
	b = v.back(); v.pop_back();
	c = v.back(); v.pop_back();
	if(a >= b + c){
		cout << "NAO FORMA TRIANGULO" << endl;
		return 0;
	}
	if(a * a == b * b + c * c)
		cout << "TRIANGULO RETANGULO" << endl;
	if(a * a > b * b + c * c)
		cout << "TRIANGULO OBTUSANGULO" << endl;
	if(a * a < b * b + c * c)
		cout << "TRIANGULO ACUTANGULO" << endl;
	if(a == b && b == c)
		cout << "TRIANGULO EQUILATERO" << endl;
	else if(a == b || b == c || a == c)
		cout << "TRIANGULO ISOSCELES" << endl;


	return 0;
}