#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

#define ll long long int
vector<ll> voters;
ll n,b;

bool possible(ll bsize)
{
	ll bllts=0;
	for(int i=0;i<voters.size();i++)
	{
		bllts+=(ll)(ceil(double(voters[i])/double(bsize)));
	}
	if(bllts>b)return false;
	return true;
}

void do_output(ll bsize)
{
	ll ans=-1000000000;
	for(int i=0;i<voters.size();i++)
	{
		ans=max(ans,voters[i]/bsize);
	}
	cout<<ans<<endl;
	return;
}


int main()
{
	
	cin>>n>>b;
	while(!(n==-1&&b==-1))
	{
		ll tot_votes=0;
		voters.resize(n);
		for(int i=0;i<n;i++)
		{
			cin>>voters[i];
			tot_votes+=voters[i];
		}
		tot_votes++;
		ll x=0,y=tot_votes;
		while(y-x>1)
		{
			ll mid = (x+y)/2;
			if(possible(mid)){y=mid;}
			else x=mid;
		}
		//do_output(y);
		cout<<y<<endl;
		cin>>n>>b;

	}
}
