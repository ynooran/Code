#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
using namespace std;
const int MAX = 1e4 + 10;
pair<int,int> A[MAX];
set <pair<int,int> > S;
void upd(int l, int h)
{
	if(h-l==1)
		return;
	int m = l + (h-l)/2;
	FOR(i,l,h)
		S.insert(mp(A[m].first,A[i].second));
	upd(l,m);
	upd(m,h);
}
int32_t main(){
	int n;
	cin>>n;
	FOR(i,0,n){
		cin>>A[i].first>>A[i].second;
		S.insert(A[i]);
	}
	sort(A,A+n);
	upd(0,n);
	cout<<S.size()<<endl;
	for(auto x : S)
		cout<<x.first<<" "<<x.second<<endl;
}
