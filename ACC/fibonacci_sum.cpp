#include<iostream>
#include<vector>

using namespace std;

class marix
{
public:
	long long int a11,a12,a21,a22;
};
vector<marix> v;

marix marcacl(long long int n)
{
	marix ans;
	ans.a11=1;
	ans.a12=0;
	ans.a21=0;
	ans.a22=1;
	long long int i=-1;
	while(n!=0)
	{	//cout<<n<<endl;
		long long int  x=n&0x1;
		n=n>>1;
		i++;
		if(x==0)continue;
		long long  a,b,c,d;
		a=(ans.a11*v[i].a11+ans.a12*v[i].a21)%1000000007;
		b=(ans.a11*v[i].a12+ans.a12*v[i].a22)%1000000007;
		c=(ans.a21*v[i].a11+ans.a22*v[i].a21)%1000000007;
		d=(ans.a21*v[i].a12+ans.a22*v[i].a22)%1000000007;
		ans.a11=a;ans.a12=b;ans.a21=c;ans.a22=d;

	}
	return ans;
}


int main()
{
	
	v.resize(35);
	v[0].a11=1;v[0].a12=1;v[0].a21=1;v[0].a22=0;
	for(long long int i=1;i<35;i++)
	{
		long long  a,b,c,d;
		a=(v[i-1].a11*v[i-1].a11+v[i-1].a12*v[i-1].a21)%1000000007;
		b=(v[i-1].a11*v[i-1].a12+v[i-1].a12*v[i-1].a22)%1000000007;
		c=(v[i-1].a21*v[i-1].a11+v[i-1].a22*v[i-1].a21)%1000000007;
		d=(v[i-1].a21*v[i-1].a12+v[i-1].a22*v[i-1].a22)%1000000007;
		//cout<<i<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		v[i].a11=a;v[i].a12=b;v[i].a21=c;v[i].a22=d;
	}
	//for(int i=1;i<35;i++)cout<<v[i].a11<<endl;
	long long int t;
	cin>>t;
	for(long long int i=0;i<t;i++)
	{
		long long  n,m;
		cin>>n>>m;
		marix f1,f2;
		f1=marcacl(n+1);
		f2=marcacl(m+2);
		if(f2.a12<f1.a12)f2.a12+=1000000007;
		//cout<<f1.a12<<" "<<f2.a12<<endl;
		cout<<(f2.a12-f1.a12)%1000000007<<endl;
	}
}
