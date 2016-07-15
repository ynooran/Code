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
node root;
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
void add()
{
	node *cur = &root;
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
void ans (node *l,node *r,int bit)
{
	if(l == NULL || r == NULL)
		return ;
	ll ret = 0;
	if(bit == -1)
		ret += num(l)*num(r);
	else if(!b[bit])
	{
		ret += num(r->right)*num(l->left);
		ans(r->right,l->right,bit-1);
		ans(r->left,l->left,bit-1);
		if(l!=r)
			ret+= num(r->left)*num(l->right);
	}
	else
	{
		ans(l->left,r->right,bit-1);
		if(l!=r)
			ans(l->right,r->left,bit-1);
	}
	sum += ret;
}
int main()
{
	cin>>n>>k;
	add();
	FOR(i,0,n)
	{
		int tmp;
		scanf("%d",&tmp);
		b ^= tmp;
		add();
	}
	b = k;
	ans(&root,&root,29);
	cout<<sum<<endl;
}
