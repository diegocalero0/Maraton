#include<bits/stdc++.h>
using namespace std;

long A[100];
long B[100];
int n;
int m;
int res;

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);

  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

int main(){
    int c=0;
    int casos,i,j;
    cin >> casos;
    while(casos--){

        res = 0;
        cin >> n;
        for(i=0;i<n;i++)
            cin >> A[i];
        cin >> m;
        VVI w(n,VI(m,0));
        for(i=0;i<m;i++){
            cin >> B[i];
            for(j=0;j<n;j++){
                if(B[i]==0&&A[j]==0){
                    w[j][i]=1;
                }else if(A[j]==0){
                    continue;
                }else if(B[i]%A[j]==0){
                    w[j][i]=1;
                }
            }
        }

        VI mr;
        VI mc;

        res=BipartiteMatching(w,mr,mc);
        cout << "Case " << ++c << ": " << res <<"\n";
    }
    return 0;
}