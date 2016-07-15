#include<iostream>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int n,k,a,m,shots[200010],tmp[200010];
int func (int size)
{
	return ((size+1)/(a+1));
}
int numShips (int x)
{
	FOR(i,0,x)
		tmp[i] = shots[i+1];
	sort(tmp,tmp+x);
	int ret = func(tmp[0] - 1) + func(n-tmp[x-1]);
	FOR(i,0,x-1)
		ret+= func(tmp[i+1] - tmp[i] -1);
	return ret;
}

int binarySearch(int i, int j)
{
	if(i>=j)
	{
		if(i-1==m)
			return -1;
		return i;
	}
	int mid = (i+j)/2;
	if(numShips(mid) < k)
		return binarySearch(i,mid);
	return binarySearch(mid+1,j);
}
int main ()
{
	cin>>n>>k>>a>>m;
	FOR(i,1,m+1)
		cin>>shots[i];
	cout<<binarySearch(1,m+1)<<endl;
}
