#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>


using namespace std;

int main()
{
	int t;
	cin>>t;
	for(long long int i=0;i<t;i++)
	{
		long long int n;
		cin>>n;
		vector<long long int> v;
		v.resize(n+1);
		v[0]=0;
		cin>>v[1];
		for(long long int i=2;i<=n;i++){cin>>v[i];v[i]+=v[i-1];}
		//for(int i=0;i<=n;i++)cout<<v[i]<<" ";cout<<endl;
		unordered_map<long long int,long long int> m;
		for(long long int i=0;i<=n;i++)m[v[i]]++;
		long long int ans=0,var;
		unordered_map<long long int,long long int>::iterator it=m.begin();
		while(it!=m.end())
		{
			var=it->second;
			//cout<<it->first<<" "<<var<<" okay"<<endl;
			ans+=(var*(var-1))/2;
			it++;
		}
		cout<<ans<<endl;
	}
}
