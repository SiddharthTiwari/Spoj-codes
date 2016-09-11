#include<bits/stdc++.h>

using namespace std;

#define ll long long int

vector<ll> parent,sizes;

class street{
public:
	ll strt,end,length;
};

ll find_root(ll a)
{
	if(parent[a]==-1)return a;
	ll p = find_root(parent[a]);
	parent[a]=p;
	return p;
}

bool merge(ll a, ll b)
{
	ll p1 = find_root(a);
	ll p2 =find_root(b);
	if(p1==p2)return false;
	ll sz1=sizes[p1],sz2=sizes[p2];
	if(sz1>=sz2){parent[p2]=p1;sizes[p1]+=sz2;}
	else{parent[p1]=p2;sizes[p2]+=sz1;}
	return true;
}

bool comp(street p, street q)
{
	if(p.length<q.length)return true;
	return false;
}

int main()
{
	ll n,m;
	cin>>n>>m;
	while(!(n==0&&m==0))
	{
		ll max_cost=0;
		parent.resize(n);
		sizes.resize(n);
		for(ll i=0;i<n;i++)
		{
			parent[i]=-1;
			sizes[i]=1;
		}
		vector<street> streets;
		streets.resize(m);
		for(ll i=0;i<m;i++)
		{
			cin>>streets[i].strt>>streets[i].end>>streets[i].length;
			max_cost+=streets[i].length;
		}
		sort(streets.begin(),streets.end(),comp);
		ll ans=0;
		for(ll i=0;i<streets.size();i++)
		{
			if(merge(streets[i].strt,streets[i].end))ans+=streets[i].length;
		}
		cout<<max_cost-ans<<endl;
		cin>>n>>m;
	}
}
