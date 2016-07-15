#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
const int MAX = 1000000;
int n;
pair<int,int> btl[MAX],a,b,t;
double T;
vector<double> ans;
pair<double,int> da[MAX],db[MAX];
double dist (pair<int,int> l , pair<int,int> k)
{
	double ret = pow((l.first-k.first),2) + pow((l.second-k.second),2);
	ret = sqrt(ret);
	return ret;
}
int main()
{
	cin>>a.first>>a.second>>b.first>>b.second>>t.first>>t.second>>n;
	FOR(i,0,n)
	{
		int x,y;
		cin>>btl[i].first>>btl[i].second;
		T+=2*dist(btl[i],t);
		da[i] = make_pair(dist(a,btl[i]) - dist(btl[i],t), i);
		db[i] = make_pair(dist(b,btl[i]) - dist(btl[i],t), i);
	}
	sort(da,da+n);
	sort(db,db+n);
	ans.push_back( min( dist(a,t) , dist(b,t)));
	ans.push_back( da[0].first);
	ans.push_back( db[0].first);
	if(db[0].second != da[0].second)
		ans.push_back( db[0].first + da[0].first);
	else
	{
		ans.push_back( db[0].first + da[1].first);
	       ans.push_back( da[0].first + db[1].first);
	}
	sort(ans.begin(),ans.end());
	cout.precision(12);
	cout<<ans[0] + T<<endl;
}
