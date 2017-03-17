#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	double n,m;
	cin>>n>>m;
	while(!(int(n)==0&&int(m)==0))
	{
		if(m>=n)cout<<fixed<<setprecision(6)<<(m-n+1.0)/(m+1)<<endl;
		else cout<<fixed<<setprecision(6)<<0.0<<endl;
		cin>>n>>m;
	}
}
