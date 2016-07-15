#include <iostream>
#include <bitset>
#define FOR(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
using namespace std;
struct node{
	node *right, *left;
	int cnt;
	node() : cnt(0) { right = left = NULL; }
};
int n,k;
ll sum;
bitset<30> b;
void mvright(node* &x)
{
	if(x->right == NULL)
		x->right = new node;
	x = x->right;
	x->cnt++;
}
void mvleft(node* &x)
{
	if(x->left == NULL)
		x->left = new node;
	x = x->left;
	x->cnt++;
}
void add(node *cur)
{
	FOR(i,0,30)
	{
		if(b[29-i])
			mvright(cur);
		else
			mvleft(cur);
	}
}
ll num(node* x)
{
	if(x == NULL)
		return 0;
	return x->cnt;
}
ll chooseTwo(ll x)
{
	return (x*(x-1))/2;
}
void ans (node *l,node *r,int bit)
{
	if(l == NULL || r == NULL || bit==-1)
		return ;
	ll ret = 0;
	if(b[bit])
	{
		if(l==r)
		{
			ret+= chooseTwo(num(l->right));
			ret+= chooseTwo(num(r->left));
		}
		else
		{
			ret+= num(l->right) * num(r->right);
			ret+= num(r->left) * num(l->left);
		}

		ans(l->left,r->right,bit-1);
		ans(l->right,r->left,bit-1);
	}
	else
	{
		ans(l->left,r->left,bit-1);
		ans(l->right,r->right,bit-1);
	}
	sum += ret;
}
void solve()
{
	sum = 0;
	b = 0;
	node root;
	cin>>n>>k;
	add(&root);
	FOR(i,0,n)
	{
		int tmp;
		scanf("%d",&tmp);
		b ^= tmp;
		add(&root);
	}
	b = k;
	ans(&root,&root,29);
	cout<<sum<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
}
