#include <iostream>
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;
struct node
{
	node *par,*right,*left;
};
const int delta = 10267;
int nodes,leaves;
node root, *cur;
void build ( bool bit )
{
	if(bit)
	{
		if(!cur->right)
		{
			cur->right = new node;
			cur->right->right = cur->right->left = 0;
			nodes++;
			if(cur->left)
				leaves++;
			cur = &root;
		}
		else
			cur = cur->right;
	}
	else
	{
		if(!cur->left)
		{
			cur->left = new node;
			cur->left->right = cur->left->left = 0;
			nodes++;
			if(cur->right)
				leaves++;
			cur = &root;
		}
		else
			cur = cur->left;
	}
	nodes%=delta;
	leaves%= delta;
}
void update (int num)
{
	bool arr[11];
	FOR(i,0,11)
	{
		arr[i] = num%2;
		num/=2;
	}
	for(int i=10; i>=0; i--)
		build(arr[i]);
}
int main()
{
	cur = &root;
	nodes = leaves = 1;
	FOR(i,1389,2011)
		update(i);
	long long ans = leaves * nodes;
	ans%= delta;
	ans*= ans;
	ans%= delta;
	cout<<ans<<endl;
}
