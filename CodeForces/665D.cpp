#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n,cnt1;
vector<int> odd,even;
bool prime(int x)
{
	for(int i=2;i*i<=x; i++)
		if(x%i==0)
			return false;
	return true;
}
int main()
{
	cin>>n;
	FOR(i,0,n)
	{
		int tmp;
		cin>>tmp;
		if(tmp==1)
			cnt1++;
		if(tmp%2)
			odd.push_back(tmp);
		else
			even.push_back(tmp);
	}
	if(cnt1>1)
	{
		vector<int> cand;
		for(int x: even)
			if(prime(x+1))
				cand.push_back(x);
		if(cand.empty())
		{
			cout<<cnt1<<endl;
			FOR(i,0,cnt1)
				cout<<"1 ";
			cout<<endl;
		}
		else
		{
			cout<<cnt1+1<<endl;
			FOR(i,0,cnt1)
				cout<<"1 ";
			cout<<cand[0]<<endl;
		}
	}
	else
	{
		for(int e : even)
			for(int o : odd)
				if(prime(e+o))
				{
					cout<<2<<endl<<e<<" "<<o<<endl;
					goto hell;
				}
		cout<<1<<endl<<(even.empty() ? odd[0]:even[0])<<endl;
		hell:;
	}
}
