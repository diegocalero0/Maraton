#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<string, deque<string>, greater<string> > yes;
    priority_queue<string, deque<string>, greater<string> > no;
    map<string, int> ma;
    int inMap = 0;
    string name, aux;
    string mayor = "";
    while(cin >> name && name != "FIM"){
        cin >> aux;
        if(aux == "YES"){
            if(ma.find(name) == ma.end()){
                ma[name] = inMap++;
                yes.push(name);
                if(name.length() > mayor.length())
                    mayor = name;
            }
        }else{
            if(ma.find(name) == ma.end()){
                ma[name] = inMap++;
                no.push(name);
            }
        }
    }

        while(!yes.empty()){
            cout << yes.top() << endl;
            yes.pop();
        }

        while(!no.empty()){
            cout << no.top() << endl;
            no.pop();
        }

        cout << endl << "Amigo do Habay:" << endl << mayor << endl;

    return 0;
}
