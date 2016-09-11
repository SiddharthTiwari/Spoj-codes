#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n!=-1)
	{
		int tot=0;
		vector<int> v;
		v.resize(n);
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			tot+=v[i];
		}
		int pp=tot/n,ans=0;
		if(pp*n!=tot)
		{
			cout<<"-1"<<endl;
		}
		else {for(int i=0;i<n;i++)
		{
			ans+=abs(pp-v[i]);
		}
		cout<<ans/2<<endl;}
		cin>>n;


	}
}
