#include<iostream>
#include<vector>
#include<math.h>

using namespace std;
#define ll long long int
#define MOD %1000000007
#define inv 111111112


vector<ll> powers_of_10,powers_of_2;


ll power(ll a, ll n)
{
	//cout<<a<<" "<<n<<endl;
	ll ans=1;
	for(int i=62;i>=0;i--)
	{
		if(powers_of_2[i]<=n)
		{
			//cout<<i<<powers_of_2[i]<<endl;
			ans*=powers_of_10[i];
			ans=ans MOD;
			n-=powers_of_2[i];
		}
	}
	//cout<<ans<<"ans"<<endl;
	return ans;
}

int main()
{
	powers_of_10.resize(70);
	powers_of_2.resize(64);
	powers_of_10[0]=10;;
	powers_of_2[0]=1;
	ll var=1;
	for(int i=1;i<70;i++)
	{
		powers_of_10[i]=(powers_of_10[i-1]*powers_of_10[i-1])MOD;
	}
	for(int i=1;i<64;i++)
	{
		var*=2;
		powers_of_2[i]=var;
	}
	ll t;
	//for(int i=1;i<10;i++)cout<<powers_of_10[i]<<endl;
	cin>>t;

	for(int i=0;i<t;i++)
	{
		ll n;
		cin>>n;
		ll a,b,c,d,e,f;
		//cout<<n<<n%1000000007<<endl;
		a=n%1000000007;
		//cout<<a<<endl;
		//while(a<0)a+=1000000007;
		b=(power(10,n)-10)%1000000007;
		//cout<<b<<"b"<<endl;
		c=(b*inv) MOD ;
		//cout<<c<<"c"<<endl;
		c=(((n-c-power(10,n)) MOD )*-5) MOD ;
		//cout<<c<<endl;
		d=(c*inv)MOD;
		cout<<(n+d) MOD <<endl;
	}
}


