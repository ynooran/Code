#include <iostream>
#include <algorithm>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
bool brem[1000];
vector<int> vrem;
int main()
{
	bool flag = false;
	int n,m;cin>>n>>m;
	FOR(i,0,n)
	{
		int tmp;
		cin>>tmp;
		tmp%=m;
		vector<int> vtmp;
		if(!brem[tmp])
			vtmp.push_back(tmp);
		FOR(j,0,vrem.size())
		{
			int l = (tmp + vrem[j]) %m;
			if(!brem[l])
				vtmp.push_back(l);
		}
		while (!vtmp.empty())
		{
			int t = vtmp.back();
			vtmp.pop_back();
			brem[t] = true;
			vrem.push_back(t);
		}
		if(brem[0]){
			flag = true;break;}
	}
	if(flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
