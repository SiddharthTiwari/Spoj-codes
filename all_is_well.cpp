#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> vec;
int n,m;
vector<vector<int> > visited;

bool fnd(int i,int j, string s)
{
	//cout<<s<<i<<j<<endl;
	if(s=="")return true;
	visited[i][j]=1;
	if(vec[i][j]==s[0])
	{
		if(s.length()==1)return true;
		if(i+1<n)
		{
			if(visited[i+1][j]==0)
			{
				if(fnd(i+1,j,s.substr(1)))return true;
			}
		
			if(j+1<m)
			{
				if(visited[i+1][j+1]==0)
				{
					if(fnd(i+1,j+1,s.substr(1)))return true;
				}
			}
			if(j-1>=0)
			{
				if(visited[i+1][j-1]==0)
				{
					if(fnd(i+1,j-1,s.substr(1)))return true;
				}	
			}
		}
		if(i-1>=0)
		{
			if(visited[i-1][j]==0)
			{
				if(fnd(i-1,j,s.substr(1)))return true;
			}
		
			if(j+1<m)
			{
				if(visited[i-1][j+1]==0)
				{
					if(fnd(i-1,j+1,s.substr(1)))return true;
				}
			}
			if(j-1>=0)
			{
				if(visited[i-1][j-1]==0)
				{
					if(fnd(i-1,j-1,s.substr(1)))return true;
				}	
			}
		}
		if(j-1>=0)
		{
			if(visited[i][j-1]==0)
			{
				if(fnd(i,j-1,s.substr(1)))return true;
			}
		}
		if(j+1<m)
		{
			if(visited[i][j+1]==0)
			{
				if(fnd(i,j+1,s.substr(1)))return true;
			}
		}
	}
	visited[i][j]=0;
	return false;
}

int main()
{
	int t;
	cin>>t;
	for(int test=0;test<t;test++)
	{
		
		cin>>n>>m;
		visited.resize(n);
		vec.resize(n);
		for(int i=0;i<n;i++)
		{
			cin>>vec[i];
			visited[i].resize(m);
			for(int j=0;j<m;j++)visited[i][j]=0;
		}
		bool found=false;
		for(int i=0;i<n&&!found;i++)
		{
			for(int j=0;j<m&&!found;j++)
			{
				if(vec[i][j]=='A')
				{
					if(fnd(i,j,"ALLIZZWELL"))found=true;
				}
			}
		}
		if(found)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

}
