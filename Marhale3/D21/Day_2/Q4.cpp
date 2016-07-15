#include <iostream>
#include <set>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int N = 100*1000*1000, delta = 10091;
int nums[N+1], T;
int main()
{
	FOR(i,2,N+1)
	{
		if(!nums[i])
			for(int j= i; j<=N; j+=i)
				nums[j]++;
		if(nums[i] == i%10)
		{
			T+=i;
			T%=delta;
		}
	}
	cout<<T<<endl;
}
