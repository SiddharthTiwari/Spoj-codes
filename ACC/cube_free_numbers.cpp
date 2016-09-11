#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> prims;
	prims.resize(102);
	prims[0]=1;
	prims[1]=0;
	for(int i=2;i<102;i++)
	{
		if(prims[i]==1)continue;
		for(int j=2*i;j<102;j+=i)prims[j]=1;
	}
	vector<int> cubes;
	for(int i=2;i<102;i++)
	if(prims[i]==0)cubes.push_back(i*i*i);
	vector<int> v;
	v.resize(1000005);
	for(int i=0;i<cubes.size();i++)
	{
		for(int j=cubes[i];j<1000005;j+=cubes[i])v[j]=1;
	}
	int var=1;
	for(int i=1;i<1000005;i++)
		if(v[i]==1){v[i]=-1;}
			else{v[i]=var;var++;}
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>var;
		cout<<"Case "<<i+1<<": ";
		if(v[var]==-1){cout<<"Not Cube Free"<<endl;}
			else{cout<<v[var]<<endl;}
	}

	
}
