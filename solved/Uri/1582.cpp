using namespace std;

int mcd(int a,int b){
    if(a%b==0){
        return b;
    }else{
        return mcd(b,a%b);
    }
}


int main(){

    int a;
    int b;
    int c;

    while(cin>>a&&cin>>b&&cin>>c){
        if(a*a+b*b==c*c||a*a+c*c==b*b||c*c+b*b==a*a){
            if(mcd(a,b)==1&&mcd(b,c)==1&&mcd(a,c)==1){
                cout<<"tripla pitagorica primitiva"<<endl;
            }else{
                cout<<"tripla pitagorica"<<endl;
            }
        }else{
            cout<<"tripla"<<endl;
        }
    }
    return 0;
}