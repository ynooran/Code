#include<iostream>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int n,k,a,m,shots[200010];
bool hit[200010];
int func (int size)
{
	return ((size+1)/(a+1));
}
int numShips (int x)
{
	int ret=0,tmp=0;
	FOR(i,0,x)
		hit[shots[i+1]] = true;
	FOR(i,1,n+1)
	{
		if(hit[i])
		{
			ret+=func(tmp);
			tmp=0;
			hit[i] = false;
		}
		else
			tmp++;
	}
	ret+= func(tmp);
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
	FOR(i,0,m)
		cin>>shots[i+1];
	cout<<binarySearch(1,m+1)<<endl;
}
