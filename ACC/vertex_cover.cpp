#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

vector<int> vertex_cover_wo_this,vertex_cover_w_this;
vector<bool> visited;
vector<vector<int> > neighbours;

void calc_vertex_cover(int node)
{
	if(vertex_cover_w_this[node]>=0)return;
	visited[node]=1;
	vertex_cover_w_this[node]+=2;
	vertex_cover_wo_this[node]+=1;
	for(int i=0;i<neighbours[node].size();i++)
	{
		if(!visited[neighbours[node][i]])
		{
			calc_vertex_cover(neighbours[node][i]);
			vertex_cover_w_this[node]+=min(vertex_cover_w_this[neighbours[node][i]],vertex_cover_wo_this[neighbours[node][i]]);//need to be more specific
			vertex_cover_wo_this[node]+=vertex_cover_w_this[neighbours[node][i]];
		}
		//if(vertex_cover_w_this[node]<0)vertex_cover_w_this[node]=1;
		//vertex_cover_w_this[node]+=2;
		//vertex_cover_wo_this[node]+=1;
	}
	//vertex_cover_w_this[node]+=2;
	//vertex_cover_wo_this[node]+=1;
	return;
}


int main()
{
	int n;
	cin>>n;
	vertex_cover_w_this.resize(n+1);
	vertex_cover_wo_this.resize(n+1);
	for(int i=0;i<=n;i++)
	{
		vertex_cover_wo_this[i]=-1;
		vertex_cover_w_this[i]=-1;
	}
	visited.resize(n+1);
	neighbours.resize(n+1);
	int a,b;
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b;
		neighbours[a].push_back(b);
		neighbours[b].push_back(a);
	}
	calc_vertex_cover(1);
	cout<<min(vertex_cover_wo_this[1],vertex_cover_w_this[1])<<endl;;

}
