#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>

using namespace std;

class prop
{
public:
	int h,a,d;
	char ar;

};

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int h,a;
		cin>>h>>a;
		queue<prop> q;
		prop p,nex;
		p.h=h+3;p.a=a+2;
		p.ar='a';p.d=1;
		if(p.h>0&&p.a>0)
		q.push(p);
		unordered_map<string,int> m1,m2,m3;
		while(!q.empty())
		{
			p=q.front();
			q.pop();
			if(p.ar=='a')
				{
					nex.d=p.d+1;nex.ar='w';
					nex.h=p.h-5;nex.a=p.a-10;
					if(nex.a>0&&nex.h>0)q.push(nex);
					nex.d=p.d+1;nex.ar='f';
					nex.h=p.h-20;nex.a=p.a+5;
					if(nex.a>0&&nex.h>0)q.push(nex);
				}
			else if(p.ar=='w')
				{
					nex.d=p.d+1;nex.ar='a';
					nex.h=p.h+3;nex.a=p.a+2;
					if(nex.a>0&&nex.h>0)q.push(nex);
					nex.d=p.d+1;nex.ar='f';
					nex.h=p.h-20;nex.a=p.a+5;
					if(nex.a>0&&nex.h>0)q.push(nex);
				}
			else if(p.ar=='f')
			{
				nex.d=p.d+1;nex.ar='w';
					nex.h=p.h-5;nex.a=p.a-10;
					if(nex.a>0&&nex.h>0)q.push(nex);
					nex.d=p.d+1;nex.ar='a';
					nex.h=p.h+3;nex.a=p.a+2;
					if(nex.a>0&&nex.h>0)q.push(nex);
			}
		}
		int ans1;
		if(p.h>0&&p.a>0)
		ans1=p.d;else ans1=0;
		cout<<ans1<<endl;
		p.h=h-5;p.a=a-10;
		p.ar='w';p.d=1;
		if(p.h>0&&p.a>0)
		q.push(p);
		while(!q.empty())
		{
			p=q.front();
			q.pop();
			if(p.ar=='a')
				{
					nex.d=p.d+1;nex.ar='w';
					nex.h=p.h-5;nex.a=p.a-10;
					if(nex.a>0&&nex.h>0)q.push(nex);
					nex.d=p.d+1;nex.ar='f';
					nex.h=p.h-20;nex.a=p.a+5;
					if(nex.a>0&&nex.h>0)q.push(nex);
				}
			else if(p.ar=='w')
				{
					nex.d=p.d+1;nex.ar='a';
					nex.h=p.h+3;nex.a=p.a+2;
					if(nex.a>0&&nex.h>0)q.push(nex);
					nex.d=p.d+1;nex.ar='f';
					nex.h=p.h-20;nex.a=p.a+5;
					if(nex.a>0&&nex.h>0)q.push(nex);
				}
			else if(p.ar=='f')
			{
				nex.d=p.d+1;nex.ar='w';
					nex.h=p.h-5;nex.a=p.a-10;
					if(nex.a>0&&nex.h>0)q.push(nex);
					nex.d=p.d+1;nex.ar='a';
					nex.h=p.h+3;nex.a=p.a+2;
					if(nex.a>0&&nex.h>0)q.push(nex);
			}
		}
		int ans2;
		if(p.h>0&&p.a>0)
		ans2=p.d;else ans2=0;
	cout<<ans2<<endl;
		p.h=h-20;p.a=a+5;
		p.ar='f';p.d=1;
		if(p.h>0&&p.a>0)
		q.push(p);
		while(!q.empty())
		{
			p=q.front();
			q.pop();
			if(p.ar=='a')
				{
					nex.d=p.d+1;nex.ar='w';
					nex.h=p.h-5;nex.a=p.a-10;
					if(nex.a>0&&nex.h>0)q.push(nex);
					nex.d=p.d+1;nex.ar='f';
					nex.h=p.h-20;nex.a=p.a+5;
					if(nex.a>0&&nex.h>0)q.push(nex);
				}
			else if(p.ar=='w')
				{
					nex.d=p.d+1;nex.ar='a';
					nex.h=p.h+3;nex.a=p.a+2;
					if(nex.a>0&&nex.h>0)q.push(nex);
					nex.d=p.d+1;nex.ar='f';
					nex.h=p.h-20;nex.a=p.a+5;
					if(nex.a>0&&nex.h>0)q.push(nex);
				}
			else if(p.ar=='f')
			{
				nex.d=p.d+1;nex.ar='w';
					nex.h=p.h-5;nex.a=p.a-10;
					if(nex.a>0&&nex.h>0)q.push(nex);
					nex.d=p.d+1;nex.ar='a';
					nex.h=p.h+3;nex.a=p.a+2;
					if(nex.a>0&&nex.h>0)q.push(nex);
			}
		}
		int ans3;
		if(p.h>0&&p.a>0)
		ans3=p.d;else ans3=0;
	cout<<ans1<<endl;
	cout<<max(ans1,max(ans2,ans3))<<endl;

	}
}
