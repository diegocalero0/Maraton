#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
struct point{
	double x, y;
	point(){x = y = 0.0;};
	point(double x_, double y_):x(x_), y(y_){};
};

struct segment{
	point a, b;
	double c;
	segment(){c = 0.0;};
	segment(point a_, point b_, double c_):a(a_), b(b_), c(c_){};

	bool operator <(segment o) const{
		return a.x < o.a.x;
	}
};

void swapPoints(point &a, point &b){
	point c = a;
	a = b;
	b = c;
}

double calc(double a, double b, vector<segment> s){
	segment seg;
	double res = 1.0;
	for(int i = 0; i < s.size(); i++){
		seg = s[i];
		if(seg.a.x <= a){
			if(seg.b.x >= b)
				res *= seg.c;
		}else{
			break;
		}
	}
	return res;	
}

int main(){

	int t, n;
	point a, b;
	double c;
	cin >> t;
	while(t--){
		vector<segment> s;
		vector<double> d;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a.x >> a.y >> b.x >> b.y >> c;
			d.push_back(a.x);
			d.push_back(b.x);
			if(a.x > b.x)
				swapPoints(a, b);
			s.push_back(segment(a, b, c));
		}

		sort(d.begin(), d.end());
		sort(s.begin(), s.end());
		int ss = d.size() + 1;
		printf("%d\n", ss);
		for(int i = 0; i <= d.size(); i++){
			if(i == 0)
				printf("-inf %.3f %.3f\n", d[i], 1.0);
			else if(i == d.size())
				printf("%.3f +inf %.3f\n", d[i - 1], 1.0);
			else
				printf("%.3f %.3f %.3f\n", d[i - 1], d[i], calc(d[i - 1], d[i], s));
		}
		if(t != 0)
			cout << endl;
	}

	return 0;
}
