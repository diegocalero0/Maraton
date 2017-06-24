#include<bits/stdc++.h>
using namespace std;
#define eps 1e-9

struct point
{
	int x, y;
	point(){x = y = 0;};
	point(int x_, int y_):x(x_), y(y_){};
};

struct segment
{
	point p1, p2;
	segment(){};
	segment(point p1_, point p2_):p1(p1_), p2(p2_){};

	bool operator <(segment s) const{
		if(p1.y >  p2.y)
			if(s.p1.y > s.p2.y)
				return p1.y > s.p1.y;
			else
				return p1.y > s.p2.y;
		else
			if(s.p1.y > s.p2.y)
				return p2.y > s.p1.y;
			else
				return p2.y > s.p2.y;
	}
};

struct vector_
{
	int x, y;
	vector_(int x_, int y_):x(x_), y(y_){};
};

void swapPoint(point &p1, point &p2){
	point p3 = p1;
	p1 = p2;
	p2 = p3;
}

vector_ toVec(point p1, point p2){
	return vector_(p2.x - p1.x, p2.y - p1.y);
}

double cross(vector_ v1, vector_ v2){
	return v1.x * v2.y - v1.y * v2.x;
}
double ccw(point p1, point p2, point c){
	return cross(toVec(p1, p2), toVec(p1, c));
}

void solve(vector<segment> s, point g){
	segment seg;
	for(int i = 0; i < s.size(); i++){
		seg = s[i];
		if(g.x >= seg.p1.x && g.x <= seg.p2.x){
			if(ccw(seg.p1, seg.p2, g) >= eps)
				if(seg.p1.y < seg.p2.y)
					g.x = seg.p1.x;
				else
					g.x = seg.p2.x;
		}
	}
	cout << g.x << endl;
}

int main(){
	vector<segment> s;
	int t, ns, np;
	cin >> t;
	point p1, p2, g;
	while(t--){
		cin >> ns;
		s.clear();
		while(ns--){
			cin >> p1.x >> p1.y >> p2.x >> p2.y;
			if(p1.x > p2.x){
				swapPoint(p1, p2);
			}
			s.push_back(segment(p1, p2));
		}

		sort(s.begin(), s.end());
		cin >> np;
		while(np--){
			cin >> g.x >> g.y;
			solve(s, g);
		}	
		if(t != 0)
			cout << endl;
	}

	return 0;
}
