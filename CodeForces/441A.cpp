#include <iostream>
#include <algorithm>
#include<set>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
set <int> goodDealers;
int main()
{
	int n,v;cin>>n>>v;
	FOR(i,1,n+1)
	{
		int q;cin>>q;
		FOR(j,0,q)
		{
			int l;cin>>l;
			if(l<v)
				goodDealers.insert(i);
		}
	}
	cout<<goodDealers.size()<<endl;
	for (set<int>::iterator it=goodDealers.begin(); it!=goodDealers.end(); ++it)
		    std::cout << *it<<' ';
	cout<<endl;
}

