#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iomanip>

using namespace std;

vector<vector<double> > ans;


double myans(int x, int y)
{
	if(x<0||y<0)return 0.0;
	if(ans[x][y]>=0.0)return ans[x][y];
	if(y<x)return 0.0;
	double var=0.0;
	for(int i=1;i<=6;i++)
	{
		var+=((1.0/6.0)*(myans(x-1,y-i)));
	}
	ans[x][y]=var;
	return var;
}


void doit()
{
	
	for(int i=0;i<2000;i++)
	{
		ans[i][0]=0;
		ans[0][i]=0;
	}
	ans[1][1]=(1.0/6.0);
	ans[1][2]=(1.0/6.0);
	ans[1][3]=(1.0/6.0);
	ans[1][4]=(1.0/6.0);
	ans[1][5]=(1.0/6.0);
	ans[1][6]=(1.0/6.0);
	for(int i=1;i<2000;i++)
	{
		for(int j=1;j<2000;j++)
		{
			if(ans[i][j]<0.0)ans[i][j]=myans(i,j);
		}
	}
}

int main()
{
	ans.resize(2000);
	for(int i=0;i<2000;i++)
	{
		ans[i].resize(2000);
	}
	for(int i=0;i<2000;i++)
	{
		for(int j=0;j<2000;j++)ans[i][j]=-1.0;
	}
	doit();
	int t;
	cin>>t;
	int x,y;
	for(int i=0;i<t;i++)
	{
		cin>>x>>y;
		if(x>=2000||y>=2000)cout<<0<<endl;
		else cout<<int(ans[x][y]*100.0)<<endl;
	}
}
