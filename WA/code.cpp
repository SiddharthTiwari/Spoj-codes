#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin>>n;
	string ch;
	getline(cin,ch);
	for(int i=0;i<n;i++)
	{
		int k;
		string s,ans="";
		getline(cin,s);
		cin>>k;
		getline(cin,ch);
		//cout<<s<<k<<endl;
		k=k%26;
		int x;
		for(int j=0;j<s.length();j++)
		{
			if(int(s[j])>=97&&s[j]<=122){x=int(s[j])-k;if(x<97)x+=26;ans+=char(x);}
			else if(s[j]>=65&&s[j]<=90){x=int(s[j])-k;if(x<65)x+=26;ans+=char(x);}
			else ans+=s.substr(j,1);
		}
		cout<<ans<<endl;
	}
}
