#include<iostream>
#include<algorithm>
#include<math.h>
#include<iomanip>

using namespace std;

#define PI 3.14159265

int main()
{
	double a,b,s,m,n;
	cin>>a>>b>>s>>m>>n;
	while(!(a==0&&b==0&&s==0&&m==0&&n==0))
	{
		double y = (b*n)/s,x=(a*m)/s;
		double velo = sqrt(x*x+y*y);
		double angle = atan(y/x)*(180.0/PI);
		cout<<fixed<<setprecision(2)<<angle<<" "<<velo<<endl;


		cin>>a>>b>>s>>m>>n;
	}
}
