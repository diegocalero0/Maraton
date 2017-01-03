#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cases = 0, n, nums[13];
    while(cin >> n && n){
        for(int i = 0; i < n; i++)
            cin >> nums[i];
        if(cases++)
            cout << "\n";
        for(int i = 0; i < n - 5; i++)
            for(int j = i + 1; j < n - 4; j++)
                for(int k = j + 1; k < n - 3; k++)
                    for(int l = k + 1; l < n - 2; l++)
                        for(int m = l + 1; m < n - 1; m++)
                            for(int o = m + 1; o < n; o++)
                                cout << nums[i] << " " << nums[j] << " " << nums[k] << " " << nums[l] << " " << nums[m] << " " << nums[o] << "\n";
    }

    return 0;
}
