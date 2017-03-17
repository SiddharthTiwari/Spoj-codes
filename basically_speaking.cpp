#include<iostream>
#include<vector>
#include<string>

using namespace std;
#define ll long long int

string dig_to_string(ll n)
{
	if(n<=9)return to_string(n);
	if(n==10)return "A";
	if(n==11)return "B";
	if(n==12)return "C";
	if(n==13)return "D";
	if(n==14)return "E";
	if(n==15)return "F";
}

ll str_to_dig(string s)
{
	if(int(s[0])<58)return stoi(s);
	if(s=="A")return 10;
	if(s=="B")return 11;
	if(s=="C")return 12;
	if(s=="D")return 13;
	if(s=="E")return 14;
	if(s=="F")return 15;

}

ll ctob10(string s,ll base)
{
	ll mulfac=1;
	ll ans=0;
	for(int i=s.length()-1;i>=0;i--)
	{
		ans+=mulfac*str_to_dig(s.substr(i,1));
		mulfac*=base;
	}
	return ans;
}

int main()
{
	string s;
	ll strt,end;
	vector<string> ans;
	while(cin>>s)
	{
		cin>>strt>>end;
		ll b10 = ctob10(s,strt);
		string bend="";
		while(b10!=0)
		{
			bend=dig_to_string(b10%end)+bend;
			b10/=end;
		}
		if(bend.length()>7)ans.push_back("ERROR");
		else ans.push_back(bend);
	}
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<7-ans[i].length();j++)cout<<" ";cout<<ans[i]<<endl;
	}

}
