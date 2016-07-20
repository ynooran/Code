#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
#define int long long
#define pb push_back
using namespace std;
const int MAX = 2e5 + 10;
int n, p[MAX], ans;
bool seen[MAX];
int32_t main(){
	int root = -1;
	cin>>n;
	FOR(i,1,n+1){
		cin>>p[i];
		if(p[i] == i)
			root = i;
	}
	FOR(i,1,n+1)
		if(!seen[i])
		{
			int ind = i;
			int pind = p[i];
			unordered_set<int> c;
			c.insert(ind);
			while(c.count(pind) == 0 && !seen[pind]){
				ind = p[ind];
				pind = p[pind];
				c.insert(ind);
			}
			if(root == -1)
				root = ind;
			if(!seen[pind] && root!=pind)
				p[ind] = root,ans++;
			for(int x : c)
				seen[x] = true;
		}
	cout<<ans<<endl;
	FOR(i,1,n+1)
		cout<<p[i]<<" ";
	cout<<endl;
}
