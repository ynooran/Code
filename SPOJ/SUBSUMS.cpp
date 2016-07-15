#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
long long nums[34],ans;
vector<long long> x,y;
int n,a,b,sizex,sizey;
int main()
{
	cin>>n>>a>>b;
	sizex = n/2;
	sizey = n - sizex;
	FOR(i,0,n)
		cin>>nums[i];
	FOR(i,0,1<<sizex)
	{
		int num  = i;
		long long tmp=0;
		for(int j=0; j<sizex; j++,num/=2)
			if(num%2)
				tmp+=nums[j];
		x.push_back(tmp);
	}
	FOR(i,0,1<<sizey)
	{
		int num = i;
		long long tmp = 0;
		for(int j=0;j<sizey; j++,num/=2)
			if(num%2)
				tmp+=nums[sizex+j];
		y.push_back(tmp);
	}
	sort(y.begin(),y.end());
	for(auto sum : x)
	{
		long long low = a - sum;
		long long high = b-sum;
		low= lower_bound(y.begin(),y.end(),low) - y.begin();
		high= upper_bound(y.begin(),y.end(),high)- y.begin();
		long long tmp = high - low;
		ans+=tmp;
	}
	cout<<ans<<endl;
}
