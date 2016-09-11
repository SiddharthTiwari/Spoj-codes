#include<iostream>
#include<vector>
#include<math.h>
#include<string>


using namespace std;


int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string s;
		cin>>s;
		//cout<<s<<endl;
		string s1,s2,s3;
		double are,r,h,so;
		s1=s.substr(0,s.find("e"));
		s=s.substr(s.find("e")+1);

		s2=s.substr(0,s.find("e"));
		s=s.substr(s.find("e")+1);

		s3=s.substr(0,s.find("e"));
		//s=s.substr(s.find("e")+1);
		//cout<<s1<<" "<<s2<<" "<<s3<<endl;
//they have been assigned proper values
		r=stod(s1);
		so=stod(s2);
		h=stod(s3);

		are=3.1415*r*sqrt(r*r+h*h);
		are*=so;
		cout<<ceil(are)<<endl;

	}
}
