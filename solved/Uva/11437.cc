#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x " = " << (x) << endl
struct Point{
	double x, y;
};

double dist(Point a, Point b){
	return sqrt( (a.y - b.y) * (a.y - b.y) +  (a.x - b.x) * (a.x - b.x));
}

Point calcP(Point a, Point b){
	double ab = dist(a, b);
	double cb = ab / (double)3;
	double ac = (double)2 * cb;
	double m = (a.y - b.y) / (a.x - b.x);
	double cx1 = a.x + (sqrt(ac * ac)  / sqrt( (m * m) + 1));
	double cx2 = a.x - (sqrt(ac * ac)  / sqrt( (m * m) + 1));
	double cx;
	if( (cx1 > a.x && cx1 < b.x) || (cx1 > b.x && cx1 < a.x))
		cx = cx1;
	else
		cx = cx2;
	double cy = a.y - (a.x - cx) * m;
	
	Point c = {cx, cy};
	return c;
}

Point intersec(Point a, Point b, Point c, Point d){
	double m1 = (a.y - b.y) / (a.x - b.x);
	double b_ = (-m1 * b.x + b.y);
	double m2 = (c.y - d.y) / (c.x - d.x);
	double d_ = (-m2 * d.x + d.y);
	double x = (d_ - b_) / (m1 - m2);
	double y = m1 * x + b_;
	Point res = {x, y};
	return res;
}

int main(){
	int n;
	cin >> n;
	Point a, b, c, d, e, f, g, h, i;
	while(n--){
		cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
		d = calcP(b, a);
		e = calcP(a, c);
		f = calcP(c, b);

		g = intersec(d, c, e, b);
		h = intersec(e, b, f, a);
		i = intersec(f, a, d, c);
		d = g;
		e = h;
		f = i;
		double det  = (d.x * e.y + e.x * f.y + f.x * d.y) - (e.y * f.x + f.y * d.x + d.y * e.x);
		int result = round(abs(det) / 2);
		cout << result << endl;
	}

	return 0;
}