#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

vector<int> positions;


bool possible(int dist,int cows)
{
	int lpos=positions[0];
	cows--;
	for(int i=0;i<positions.size();i++)
	{
		if(positions[i]-lpos>=dist){lpos=positions[i];cows--;}
	}
	if(cows<=0)
	return true;
else return false;
}


int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,c;
		cin>>n>>c;
		positions.resize(n);
		for(int i=0;i<n;i++)cin>>positions[i];
		sort(positions.begin(),positions.end());
		int x,y;
		x=0;
		y=2*(positions[positions.size()-1]-positions[0]);
		while(y-x>1)
		{
			int mid=(x+y)/2;
			if(possible(mid,c)){x=mid;}
			else y=mid;
		}
		cout<<x<<endl;
	}
}
