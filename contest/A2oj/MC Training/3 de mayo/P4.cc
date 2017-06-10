#include<bits/stdc++.h>
using namespace std;

struct intPoint{
	int x; int y;
};

int n, m;
vector<intPoint> white, black;
long long res;

bool intoTriangle(intPoint s, intPoint a, intPoint b, intPoint c)
{
    int as_x = s.x-a.x;
    int as_y = s.y-a.y;

    bool s_ab = (b.x-a.x)*as_y-(b.y-a.y)*as_x > 0;

    if((c.x-a.x)*as_y-(c.y-a.y)*as_x > 0 == s_ab) return false;

    if((c.x-b.x)*(s.y-b.y)-(c.y-b.y)*(s.x-b.x) > 0 != s_ab) return false;

    return true;
}

void sol(){
	intPoint s, a, b, c;
	long long k2 = 0;
	for(int i = 0; i < m; i++){
		for(int j = i + 1; j < m ; j++){
			for(int k = j + 1; k < m; k++){
				a = black[i];
				b = black[j];
				c = black[k];
				k2 = 0;
				for(int l = 0; l < n; l++){
					s = white[l];
					if(intoTriangle(s, a, b, c))
						k2++;
				}
				res += k2 * k2;
			}
		}
	}
}



int main(){
	int x, y;
	while(cin >> m >> n){
		white.clear();
		black.clear();
		res = 0;	
		for(int i = 0; i < m; i++){
			cin >> x >> y;
			intPoint temp = {x, y};
			black.push_back(temp);
		}
		for(int i = 0; i < n; i++){
			cin >> x >> y;
			intPoint temp = {x, y};
			white.push_back(temp);
		}
		sol();
		cout << res << endl;
	}

}