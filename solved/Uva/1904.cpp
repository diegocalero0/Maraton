#include <bits/stdc++.h>
#define 	mod 		2
#define 	enl 		"\n"
#define 	debug(x) 	cout << #x " = " << (x) << enl
#define 	here 		cout << "Here" << enl;
#define 	rep(i,a,n) 	for(int i = a; i<n; i++)
#define 	sp 			swap


using namespace std;
typedef 	string 				st;
typedef 	long long 			ll;
typedef 	long double			ld;
typedef 	unsigned long long ull;
typedef 	pair<int,int> 		ii;
typedef 	vector<int> 		vi;
typedef 	vector<vi> 			vvi;
typedef 	vector<ii> 			vii;
typedef 	vector<vii> 		vvii;
typedef		map<st,int> 		msi;
typedef 	set<int> 			si;
typedef 	queue<int> 			qi;
typedef		queue<ii> 			qii;
typedef 	stack<int> 			sti;
typedef 	stack<ii> 			stii;
typedef 	tr1::unordered_map<st,int> 	umsi;
typedef 	tr1::unordered_set<int> 	usi;

template<class T> st to_str(T t){stringstream ss; ss<<t; return ss.str();}

bitset<10000010> bs;
vector<int> primes;
const int factsz = 700000;
ull fact[factsz];

void sieve(long bound){
  bs.set();

  bs[0] = bs[1] = 0; fact[0] = fact[1] = 1;
  rep(i,2,factsz) fact[i] = (i*fact[i-1])%mod; 
	for(int i = 2; i <= (bound + 1); i++){
		if(bs[i]){
			for(int j = 2*i; j <= MAX ; j+=i) bs[j] = 0;
			primes.push_back(i);
    	}
    }
}

long upper(ll x){  
    long l=0,r=primes.sz;  
    long mid;  
    while(l<r){  
        mid=((l+r)>>1);
        if( x < primes[mid])r=mid;
        else l=mid+1;
    }
    return r;  
}  

long lower(ll x){  
    long l=0,r=primes.sz;  
    long mid;  
    while(l<r){  
        mid=((l+r)>>1);  
        if(x <= primes[mid])r=mid;  
        else l=mid+1;
    }  
    return r;  
} 

/* Calculates x ^ y % mod*/
ll mod_pow( ll b, ll e)
{
    ll r = 1;
    ll pow = b % mod;
    while( e > 0 )
    {
        if( e&1 ) r = ( r*pow )%mod;
        pow = ( pow*pow )%mod;
        e >>= 1;
    }
    return r;
}

/* Calculates the multiplicative inverse of x*/
ll inv( ll x )
{
    return mod_pow( x, mod-2 );
}

ull comb(int n, int k){
	ull ans = fact[n];
	ull den = inv((fact[k] * fact[n-k]) % mod);
	ans = (ans % mod * den % mod) % mod;
	return ans;
}

unsigned long long int countNonDecreasing(int n)
{
    int N = 10;
 
    // Compute value of N*(N+1)/2*(N+2)/3* ....*(N+n-1)/n
    long long count = 1;
    for (int i=1; i<=n; i++)
    {
        count *= (N+i-1);
        count /= i;
        count %= 2;
    }
    
    return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long a,b;
	ull n,k;
	cin >> a >> b;
	if(a == b) cout << "?" << enl;
	else{
		if(a>b) sp(a,b);
		sieve(b);
		long pa = lower(a) , pb = upper(b);
		n = pb - pa;
		k = b - a;
		ull ans = countNonDecreasing();
		cout << (ans % 2 ? "Alice" : "Bob")<< enl;
	}
	return 0;
}
