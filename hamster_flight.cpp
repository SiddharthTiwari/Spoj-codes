#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>


using namespace std;
#define PI 3.14159265

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		double u,k1,k2;
		cin>>u>>k1>>k2;
		//cout<<k1<<" "<<k2<<endl;
		if(k1==0)
		{
			cout<<fixed<<setprecision(3)<<1.571<<" "<<(k2*u*u)/(2.0*10.0)<<endl;
		}
		else if(k2==0)
		{
			cout<<fixed<<setprecision(3)<<0.785<<" "<<(k1*u*u)/10.0<<endl;
		}
		else 
		{
			//cout<<"hello"<<endl;
			double var = (atan2((4.0*k1),-1.0*k2))/2.0;
			//cout<<var<<endl;
			//double s2t = ((4.0*k1)/k2)/sqrt(1.0+(((4.0*k1)/k2)*((4.0*k1)/k2)));
			//double sst = (0.5)*((1.0)-(1.0/sqrt(1.0+(var*var))));
			double s2t = sin(2*var);
			double sst = sin(var)*sin(var);
			cout<<fixed<<setprecision(3)<<(atan2((4.0*k1),-1.0*k2))/2.0<<" "<<((k1*u*u*s2t)/(10.0))+(k2*u*u*sst)/(2.0*10.0)<<endl;
		}

	}
}
