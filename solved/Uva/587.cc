#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-9

#define diag 1 * cos(45 * acos(0) / 180 * 2)

struct point
{
	double x, y;
	point(){x = y = 0;};
};

double dist(point p1, point p2){
	return hypot(p2.x - p1.x, p2.y - p1.y);
}

int main(){
	string s;
	int step;
	char dir_, des;
	string dir;
	int t = 1;
	while(cin >> s && s != "END"){
		stringstream ss;
		ss << s;
		point i, f;
		while(ss >> step >> dir_ >> des){
			dir = dir_;
			if(des != ',' && des != '.'){
				dir+= des;
				ss >> des;
			}
			if(dir == "N")
				f.y += step;
			if(dir == "S")
				f.y -= step;
			if(dir == "E")
				f.x += step;
			if(dir == "W")
				f.x -= step;
			if(dir == "NE"){
				f.x += (step * diag), f.y += (step * diag);
			}
			if(dir == "SE"){
				f.x += (step * diag), f.y -= (step * diag);
			}
			if(dir == "SW"){
				f.x -= (step * diag), f.y -= (step * diag);
			}
			if(dir == "NW"){
				f.x -= (step * diag), f.y += (step * diag);
			}
		}
		printf("Map #%d\nThe treasure is located at (%.3f,%.3f).\nThe distance to the treasure is %.3f.\n\n", t++, f.x, f.y, dist(i, f));
	}
	return 0;
}
