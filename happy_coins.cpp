#include<iostream>
#include<string>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string s;
		int l=0,h=0,n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			if(s=="lxh")l++;
			else h++;
		}
		if(l%2==0)cout<<"hhb"<<endl;
		else cout<<"lxh"<<endl;

	}
}
