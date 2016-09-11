#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace  std;

class pos
{
public:
	int x,y;
};

int main()
{
	int n,m;
	cin>>n>>m;
	vector<string> vec;
	vec.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>vec[i];
	}
	vector<pos> poss;
	pos temp;
	vector<int> ys,xs;
	ys.resize(n);
	xs.resize(m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(vec[i][j]=='*')
			{
				temp.y=i;
				temp.x=j;
				poss.push_back(temp);
				xs[j]++;
				ys[i]++;
			}
		}
	}
	int cx=0,cy=0,xp,yp;
	for(int i=0;i<n;i++)
	{
		if(ys[i]>cy){cy=ys[i];yp=i;}
	}
	for(int i=0;i<m;i++)
	{
		if(xs[i]>cx){cx=xs[i];xp=i;}
	}
	if(poss.size()==0)
	{
		cout<<"YES"<<endl;
		cout<<1<<" "<<1<<endl;
	}
	else if(poss.size()==1)
	{
		cout<<"YES"<<endl;
		cout<<poss[0].y+1<<" "<<poss[0].x+1<<endl;	
	}
	else if(poss.size()==2)
	{
		cout<<"YES"<<endl;
		cout<<poss[0].y+1<<" "<<poss[1].x+1<<endl;	
	}
	//int cx=xs[m-1],cy=ys[n-1];
	else
	{
		cx=xp;
	cy=yp;
	//cout<<cx<<cy<<endl;
	bool dont=true;
	vector<int> tpo,tpx;
	for(int i=0;i<poss.size();i++)
	{
		if(poss[i].x!=cx){tpo.push_back(poss[i].y);}
		if(poss[i].y!=cy){tpx.push_back(poss[i].x);}
	}
	sort(tpo.begin(),tpo.end());
	sort(tpx.begin(),tpx.end());
	if(tpo.size()!=0&&tpx.size()!=0)
	{
		if(tpo[0]!=tpo[tpo.size()-1]&&tpx[0]!=tpx[tpx.size()-1])dont=false;
	}
	if(dont)cout<<"YES"<<endl<<cy+1<<" "<<cx+1<<endl;
	else cout<<"NO"<<endl;
}
	

}
