#include<bits/stdc++.h>
using namespace std;

int n, t1, t2, friends[20], seen[20];
string clase[3], names[20], cate[20];
vector< vector<int> > ady(20);
void ans(int i){

    for(int j = 0; j < n; j++){
        seen[j] = 0;
    }

    seen[i] = 1;
    queue<int> c;
    c.push(i);
    int aux;
    while(!c.empty()){
        aux = c.front();
        c.pop();

        if(friends[aux] < t1)
            cate[aux] = cate[aux] + " " + clase[0];
        else if(friends[aux] >= t1 && friends[aux] < t2)
            cate[aux] = cate[aux] + " " + clase[1];
        else
            cate[aux] = cate[aux] + " " + clase[2];

        for(int  j= 0; j < ady[aux].size(); j++){
            if(seen[ady[aux][j]] == 0){
                seen[ady[aux][j]] = 1;
                c.push(ady[aux][j]);
            }
        }

    }

}

int main(){

    int f, i , j, originator;

    while(cin >> n && n){
        for(i = 0; i < n; i++){
            cate[i] = "";
            j = 0;
            ady[i].clear();
            while(cin >> f && f){
                j++;
                ady[i].push_back(--f);
            }
            friends[i] = j;
        }

        while(cin >> originator && originator){
            originator--;
            cin >> t1 >> t2 >> clase[0] >> clase[1] >> clase[2];
            ans(originator);
            for(i = 0; i < n; i++){
                if(seen[i] == 0)
                    cate[i] = cate[i] + " " + clase[0];
            }
        }

        for(i = 0; i < n; i++){
            cin >> names[i];
        }

        for(int i = 0; i < n; i++){
            cout << names[i] << ":" << cate[i] << " " << endl;
        }

    }

    return 0;
}
