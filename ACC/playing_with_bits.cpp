#include<iostream>
#include<vector>
#include<string>
#include<math.h>

using namespace std;


int main()
{
	int t;
	cin>>t;
	vector<int> powers_of_2,power_2_m1;
	powers_of_2.resize(31);
	power_2_m1.resize(32);
	powers_of_2[0]=1;
	power_2_m1[1]=1;
	int var=1;
	for(int i=1;i<=30;i++)
	{
		var*=2;
		powers_of_2[i]=var;
		power_2_m1[i+1]=power_2_m1[i]+var;
	}
	for(int i=0;i<t;i++)
	{
		int n,k;
		cin>>n>>k;
		if(k<=0||n==1){cout<<-1<<endl;continue;}
		int ans=0,count=0;;

		for(int i=30;i>=1;i--)
		{
			if(count<k-1&&ans+powers_of_2[i]<n){count++;ans+=powers_of_2[i];}
		}
		ans+=1;
		if(count<=k-1)cout<<ans<<endl;
	}
}
