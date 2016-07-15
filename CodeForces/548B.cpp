# include <iostream>
# include <cmath>
# include <algorithm>

using namespace std;
bool grid [500][500];
int m,n,q;


void showmax ()
{
	int MAX =0;
	int counter=0;
	for(int row=0; row<n; row++){
	counter=0;for(int j=0;j<m;j++)
	{
		if(grid[row][j])
			counter++;
		else
			counter = 0;
		MAX = max (counter,MAX);
	}}
	cout<<MAX<<endl;
}

void update ()
{
	int i,j;
	cin>>i>>j;
	i--;
	j--;
	grid[i][j]^= true;
	showmax();
}

int main ()
{
	cin>>n>>m>>q;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>grid[i][j];
	while(q--)
		update();
}

