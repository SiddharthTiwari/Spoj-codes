#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
	int n;
	cin>>n;
	int mxx=-1,mnn=200;
	vector<int> hats;
	hats.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>hats[i];
		mxx=max(hats[i],mxx);
		mnn =min(hats[i],mnn);
	}
	if(mxx-mnn>1)
	{
		cout<<-1<<endl;
		return 0;
	}
	int tothats=hats[0];
	int count=0;
	for(int i=1;i<n;i++)
	{
		if(hats[i]==tothats-1)count++;
	}
	if(count==tothats){cout<<tothats<<endl; return 0;}
	tothats=hats[0]+1;
	count=1;
	for(int i=1;i<n;i++)
	{
		if(hats[i]==tothats-1)count++;
	}
	if(count==tothats){cout<<tothats<<endl; return 0;}
	cout<<-1<<endl;
}
