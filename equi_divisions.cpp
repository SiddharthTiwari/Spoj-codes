#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

vector<vector<int> > visited,colors;
vector<int> colored;
int n;
void color_it(int i, int j)
{
	visited[i][j]=1;
	if(i-1>0)
	{
		if(colors[i-1][j]==colors[i][j]&&!visited[i-1][j])color_it(i-1,j);
	}
	if(i+1<=n)
	{
		if(colors[i+1][j]==colors[i][j]&&!visited[i+1][j])color_it(i+1,j);
	}
	if(j-1>0)
	{
		if(colors[i][j-1]==colors[i][j]&&!visited[i][j-1])color_it(i,j-1);
	}
	if(j+1<=n)
	{
		if(colors[i][j+1]==colors[i][j]&&!visited[i][j+1])color_it(i,j+1);
	}
	return;
}


int main()
{
	
	cin>>n;
	while(n!=0)
	{
		visited.resize(n+1);
		colors.resize(n+1);
		for(int i=0;i<=n;i++)
		{
			colored.resize(n);
			visited[i].resize(n+1);
			colors[i].resize(n+1);
			for(int j=0;j<=n;j++)
			{
				visited[i][j]=0;
				colors[i][j]=0;
			}
		}
		bool ans=true;
		for(int i=0;i<n;i++)colored[i]=0;
		int a,b;
		for(int i=1;i<=n-1;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>a>>b;
				if(colors[a][b]!=0)ans=false;
				colors[a][b]=i;
			}
			char ch='x';
			while(ch!='\n')cin.get(ch);
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(visited[i][j]==1)continue;
				if(colored[colors[i][j]]==1){ans=false;continue;}
				color_it(i,j);
				colored[colors[i][j]]=1;
			}
		}
		if(ans)cout<<"good"<<endl;
		else cout<<"wrong"<<endl;
		cin>>n;
	}
}
