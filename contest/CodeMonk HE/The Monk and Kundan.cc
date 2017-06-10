#include<bits/stdc++.h>
using namespace std;

int main(){

    int t, numS, sum;
    string temp, strcurr;
    cin >> t;
    cin.ignore();

    while(t--){
        numS = 0;
        sum = 0;
        getline(cin, temp);
        stringstream curr(temp);
        while(curr >> strcurr){
            numS++;
            for(int i = 0; i < strcurr.length(); i++){
                if(strcurr[i] >= 97 && strcurr[i] <= 122){
                    sum += i + strcurr[i] - 97;
                }
                if(strcurr[i] >= 65 && strcurr[i] <= 90){
                    sum += i + strcurr[i] - 29;
                }
                if(strcurr[i] >= 49 && strcurr[i] <= 57){
                    sum += i + strcurr[i] - 23;
                }
                if(strcurr[i] == 48){
                    sum += i + 35;
                }
            }
        }
        cout << sum * numS << "\n";
    }

    return 0;
}
