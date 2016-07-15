#include <iostream>
#include <algorithm>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
typedef long long ll;
const long long delta = 11471, MAX = 963761198400; 
vector<pair<ll,ll> > M;
int main()
{
	for(ll i = 1; i*i<=MAX; i++)
		if(MAX%i == 0)
		{
			M.push_back(make_pair(i,0));
			if(i != MAX/i)
				M.push_back(make_pair(MAX/i,0));
		}
	sort(M.begin(),M.end());
	M[0].second = 1;
	FOR(i,0,M.size())
		FOR(j,i+1,M.size())
			if(M[j].first%M[i].first == 0){
				M[j].second += M[i].second;
				M[j].second%=delta;
			}
	cout<<M.back().second<<endl;
}
