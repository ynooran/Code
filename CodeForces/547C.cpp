#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int beers[200000];
bool shelf[200000];
vector< vector<bool> > coprime (200000);
int n,q;
int score;

void displaymatrix()
{
	for(int i=0;i<n;i++){
		for(int j=0; j<n; j++)
			cerr<<coprime[i][j]<<" ";
		cout<<endl;
	}
}
void displayshelf()
{
	cout<<"shelf:"<<endl;
	for(int i=0; i<n; i++)
		cout<<shelf[i]<<" ";
}


void displayScore()
{
	cout<<score<<endl;
}

void updateShelf()
{
	int a,delta=0;
	cin>>a;
	a--;
	for(int i=0; i<n; i++)
		if(shelf[i])
			if(coprime[a][i])
				delta++;
	if(shelf[a])
		delta = -delta;
	shelf[a]^=true;
	score+=delta;
}

int main ()
{
	cin>>n>>q;
	for(int i=0; i<n; i++)
		shelf[i] = false;
	for(int i=0; i<n; i++)
		cin>>beers[i];
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			coprime[i][j] =(__gcd(beers[i],beers[j]) == 1),coprime[j][i] = coprime[i][j];
	displaymatrix();
	while(q--)
		updateShelf(),displayScore();

}

