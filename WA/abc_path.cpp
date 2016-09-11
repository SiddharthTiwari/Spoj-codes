#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string s="",bottom="";
	char ch;
	int n;
	cin>>n;
	cin>>s;
	for(int i=0;i<s.length();i+=2)
	{
		if(s[i]=='A'&&s[i+1]=='B'||s[i]=='B'&&s[i+1]=='A')
		{
			if(i==0)bottom+="CD";
			else
			{
				if(bottom[i-1]=='C')bottom+="DC";
				else bottom+="CD";
			}
			
			}
		if(s[i]=='A'&&s[i+1]=='C'||s[i]=='C'&&s[i+1]=='A')
		{
			if(i==0)bottom+="BD";
			else
			{
				if(bottom[i-1]=='B')bottom+="DB";
				else bottom+="BD";
			}
			}
		if(s[i]=='A'&&s[i+1]=='D'||s[i]=='D'&&s[i+1]=='A')
		{
			if(i==0)bottom+="BC";
			else
			{
				if(bottom[i-1]=='B')bottom+="CB";
				else bottom+="BC";
			}
			}
		if(s[i]=='B'&&s[i+1]=='C'||s[i]=='C'&&s[i+1]=='B')
		{
			if(i==0)bottom+="AD";
			else
			{
				if(bottom[i-1]=='A')bottom+="DA";
				else bottom+="AD";
			}
			}
		if(s[i]=='B'&&s[i+1]=='D'||s[i]=='D'&&s[i+1]=='B')
		{
			if(i==0)bottom+="AC";
			else
			{
				if(bottom[i-1]=='A')bottom+="CA";
				else bottom+="AC";
			}
			}
		if(s[i]=='C'&&s[i+1]=='D'||s[i]=='D'&&s[i+1]=='C')
		{
			if(i==0)bottom+="AB";
			else
			{
				if(bottom[i-1]=='A')bottom+="BA";
				else bottom+="AB";
			}
			}
	}
	cout<<bottom<<endl;
}

