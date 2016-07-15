#include<iostream>
#include<algorithm>
#include<vector>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define dbug(x) #x<<": "<<x<<' '
using namespace std;
int n;
vector<int> a, stack[2], b, trs;
bool ans(int inb)
{
	if(inb==n+1)
		return true;
	int bind = (stack[0].back() < stack[1].back() ? 0 : 1);
	if(stack[bind].back() == inb)
	{
		b.push_back(inb);
		stack[bind].pop_back();
		return ans(inb+1);
	}
	int x = a.back();
	a.pop_back();
	if(x<stack[bind].back())
	{
		trs.push_back(bind+1);
		stack[bind].push_back(x);
		return ans(inb);
	}
	else if(x<stack[bind^1].back())
	{
		trs.push_back((bind^1)+1);
		stack[bind^1].push_back(x);
		return ans(inb);
	}
	else
		return false;
}
int main(){
	cin>>n;
	FOR(i,0,n)
	{
		int tmp;
		cin>>tmp;
		a.push_back(tmp);
	}
	reverse(a.begin(),a.end());
	stack[0].push_back(n+1);
	stack[1].push_back(n+1);
	if(ans(1))
	{
		cout<<"TAK\n";
		FOR(i,0,trs.size())
			cout<<trs[i]<<" ";
		cout<<endl;
	}
	else
		cout<<"NIE"<<endl;
}
