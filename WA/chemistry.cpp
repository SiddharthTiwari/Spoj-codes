#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n,k;
	cin>>n;
	cin>>k;
	vector<int> values;
	values.resize(n+1);
	int temp;
	values[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>temp;
		values[i]=values[i-1]+temp;
	}
	
	int l,r,x,ans=0;
	for(int i=0;i<k;i++)
	{
		cin>>l>>r>>x;
		if(values[r]-values[l-1]>=x)ans++;
	}
	cout<<ans<<endl;

}
