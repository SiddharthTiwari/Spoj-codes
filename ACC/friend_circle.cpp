#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

unordered_map<string,int> um2;
unordered_map<string,string>um1;
vector<string> v1,v2;


string find_root(string s)
{
	if(um1[s]=="-1")return s;
	string par=find_root(um1[s]);
	um1[s]=par;
	return par;
}

void merge(string s1, string s2)
{
	string a1=find_root(s1),a2=find_root(s2);
	int sz1=um2[a1],sz2=um2[a2];
	if(a1!=a2)
	{
	if(sz1>=sz2)
	{
		um1[a2]=a1;
		um2[a1]=sz1+sz2;
		cout<<um2[a1]<<endl;
	}
	else
	{
		um1[a1]=a2;
		um2[a2]=sz1+sz2;
		cout<<um2[a2]<<endl;
	}}
	else cout<<um2[a1]<<endl;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		v1.resize(0);
		v2.resize(0);
		um1.clear();
		um2.clear();
		int n;
		cin>>n;
		string s1,s2;
		for(int j=0;j<n;j++)
		{
			cin>>s1>>s2;
			v1.push_back(s1);
			v2.push_back(s2);
			um1[s1]="-1";
			um2[s1]=1;
			um1[s2]="-1";
			um2[s2]=1;
		}
		for(int j=0;j<n;j++)
		{
			merge(v1[j],v2[j]);
		}

	}
}
