#include<bits/stdc++.h>
using namespace std;

/// Set your CPU's L1 data cache size (in bytes) here
const int L1D_CACHE_SIZE = 32768;

/// Generate primes using the segmented sieve of Eratosthenes.
/// This algorithm uses O(n log log n) operations and O(sqrt(n)) space.
/// @param limit  Sieve primes <= limit.
///

vector<long> preCalc;

bool isPrime(long n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;


    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;
 
    for (long i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
 
    return true;
}

string voltear(string s){
    string res = s;
    reverse(res.rbegin(), res.rend());
    return res;
}

bool check2(string s){
      stringstream ss;
      ss << s;
      long n;
      ss >> n;
    if(s.length() == 1){
      if(isPrime(n))
        return true;
      return false;
    }else{
      int sum = 0;
      for(int i = 0; i < s.length(); i++)
        sum += s[i] - 48;
      if(sum % 3 && isPrime(n)){
        return check2(s.substr(1));
      }else{
        return false;
      }
    }
}

bool check(string s){
    if(check2(s) && check2(voltear(s)))
      return true;
    return false;
}

void segmented_sieve(long limit)
{
  int sqrt = (int) std::sqrt(limit);
  int segment_size = std::max(sqrt, L1D_CACHE_SIZE);

  long count = (limit < 2) ? 0 : 1;
  long s = 3;
  long n = 3;

  // generate small primes <= sqrt
  std::vector<char> is_prime(sqrt + 1, 1);
  for (int i = 2; i * i <= sqrt; i++)
    if (is_prime[i])
      for (int j = i * i; j <= sqrt; j += i)
        is_prime[j] = 0;

  // vector used for sieving
  std::vector<char> sieve(segment_size);
  std::vector<int> primes;
  std::vector<int> next;

  for (long low = 0; low <= limit; low += segment_size)
  {
    std::fill(sieve.begin(), sieve.end(), 1);

    // current segment = interval [low, high]
    long high = std::min(low + segment_size - 1, limit);

    // add new sieving primes <= sqrt(high)
    for (; s * s <= high; s += 2)
    {
      if (is_prime[s])
      {
        primes.push_back((int) s);
          next.push_back((int)(s * s - low));
      }
    }
    
    // sieve the current segment
    for (std::size_t i = 0; i < primes.size(); i++)
    {
      int j = next[i];
      for (int k = primes[i] * 2; j < segment_size; j += k)
        sieve[j] = 0;
      next[i] = j - segment_size;
    }

    for (; n <= high; n += 2)
      if (sieve[n - low]){ // n is a prime
        count++;
        stringstream ss;
        ss << n;
        string s;
        ss >> s;
        bool flag = true;
        for(int i = 0; i < s.length(); i++){
          if(s[i] == '0'){
            flag = false;
            break;
          }
        }
        if(n == 2 || n == 5){
          preCalc.push_back(n);
          cout << n << endl;
        }
        if(flag && ((s[0] - 48) % 5) && ((s[0] - 48) % 2) && ((s[s.length() - 1] - 48) % 2) && check(s)){
          preCalc.push_back(n);
          cout << n << endl;
        }
      }
  }

  std::cout << count << " primes found." << std::endl;
}

/// Usage: ./segmented_sieve n
/// @param n  Sieve the primes up to n.
///
int main(){

    //segmented_sieve(1000000000);
    long pre[21] = {2, 3, 5, 7, 37, 73, 313, 347, 353, 373, 383, 743, 797, 3467, 7643, 34673, 37643, 76367, 79397, 7693969, 799636997};
    int t;
    long a, b;
    int res;
    cin >> t;

    while(t--){
      cin >> a >> b;
      res = 0;
      for(int i = 0; i < 21; i++){
        if(pre[i] >= a && pre[i] <= b)
          res++;
      }
      cout << res << endl;
    }

    return 0;
}








