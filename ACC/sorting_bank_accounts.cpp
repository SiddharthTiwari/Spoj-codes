#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		map<string,int> m;
		int n;
		cin>>n;
		string s="",a;
		for(int j=0;j<n;j++)
		{
			s="";
			for(int k=0;k<6;k++){cin>>a;s+=a;}
				m[s]=m[s]+1;
		}
		map<string,int>::iterator it=m.begin();
		while(it!=m.end())
		{
			cout<<it->first.substr(0,2)<<" "<<it->first.substr(2,8)<<" "<<it->first.substr(10,4)<<" "<<it->first.substr(14,4)<<" "<<it->first.substr(18,4)<<" "<<it->first.substr(22,4)<<" "<<it->second<<endl;
		it++;
		}
		cout<<endl;

	}
}
