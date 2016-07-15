#include <iostream>
#include <map>
using namespace std;
long long n,ans,x,y;
map<int,int> nx, ny;
map<pair<int,int>,int> np;
int main(){
	cin>>n;
	while(n--){
		cin>>x>>y;
		ans+= nx[x]++ + ny[y]++ - np[make_pair(x,y)]++;
	}
	cout<<ans<<endl;
}
