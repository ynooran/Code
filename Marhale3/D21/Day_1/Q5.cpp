#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int delta = 10039;
vector<int> primes;
int dp[10], ans;
int numDigits(int x)
{
	if(!x)
		return 0;
	return 1+numDigits(x/10);
}
bool isPrime(int x)
{
	for(int j=2; j*j<=x; j++)
		if(x%j == 0)
			return 0;
	return 1;
}
int firstDigit(int x) {
	int tmp = numDigits(x);
	FOR(i,1,tmp) {
		x/=10;
	}
	return x;
}
int main() {
	FOR(i,11,delta) {
		if(isPrime(i)) {
			primes.push_back(i);
		}
	}
	for(int t : primes) {
		dp[t%10] = max(dp[t%10], max(0, dp[firstDigit(t)] - 1) + numDigits(t));
	}
	FOR(i,1,10) {
		ans = max(ans, dp[i]);
	}
	ans = ans*ans*ans;
	cout<<ans%delta<<endl;	
}
