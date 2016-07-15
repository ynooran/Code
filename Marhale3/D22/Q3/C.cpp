#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
const int N = 48, delta = 10459;
int gcd( int a, int b)
{
	return b? gcd(b,a%b) : a;
}

vector<int> divisors_naive(int x)
{
	vector<int> ret;
	FOR(i,1,x+1)
	{
		if(x%i==0)
			ret.push_back(i);
	}
	return ret;
}
vector<int> divisors_sqrt(int x)
{
	vector<int> ret;
	for(int i=1; i*i<=x; i++)
	{
		if(x%i == 0)
		{
			ret.push_back(i);
			if(i*i != x)
				ret.push_back(x/i);

		}
	}
	return ret;
}
vector<int> divisors_fast(int x)
{
	vector<int> ret;
	ret.push_back(1);
	for(int i=2; i*i<=x; i++)
	{
		int num=0;
		while(x%i==0)
		{
			x/=i;
			num++;
		}
		int c = i;
		int size = ret.size();
		while(num--)
		{
			FOR(k,0,size)
			{
				ret.push_back(ret[k]*c);
			}
			c*=i;
		}
	}
	if(x!=1)
	{
		int size = ret.size();
		FOR(i,0,size)
		{
			ret.push_back(ret[i]*x);
		}
	}
	return ret;
}
int ans( int l )
{
	int ret=0;
	vector<int> d = divisors_naive(l);
	d.pop_back();
	FOR(mask,1,1<<d.size())
	{
		int c = -1;
		int g = 0;
		FOR(i,0,d.size())
		{
			if(mask&(1<<i))
			{
				c *= -1;
				g = gcd(d[i],g);
			}
		}
		ret+= c*(1<<(g-1));
		cerr<<dbug(g)<<dbug(c)<<dbug(ret)<<endl;
	}
	return ret;
}
void show( vector<int> v )
{
	for(int a : v)
		cout<<a<<" ";
	cout<<endl;
}
int main()
{
	int s = 0;
	FOR(i,2,N+1)
		s+=ans(i);
	s%=delta;
	int val = 1;
	FOR(i,0,delta)
	{
		val*=s;
		val%=delta;
		cout<<dbug(val)<<endl;
	}
}
