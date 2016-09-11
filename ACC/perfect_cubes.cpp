#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

class point
{
public:
	int a,b,c,d;
};

bool comp(point p, point q)
{
	if(p.a<q.a)return true;
	if(p.a==q.a&&p.b<q.b)return true;
	if(p.a==q.a&&p.b==q.b&&p.c<q.c)return true;
	if(p.a==q.a&&p.b==q.b&&p.c==q.c&&p.d<q.d)return true;
	return false;
}

int main()
{
	vector<int> cubes;
	cubes.resize(101);
	for(int i=0;i<=100;i++)
	{
		cubes[i]=i*i*i;
	}
	vector<point> vec;
	point ver;
	for(int i=2;i<=100;i++)
	{
		for(int j=i;j<100;j++)
		{
			for(int k=j;k<=100;k++)
			{
				vector<int>::iterator it  = lower_bound(cubes.begin(),cubes.end(),i*i*i+j*j*j+k*k*k);
				if(*it==i*i*i+j*j*j+k*k*k)
				{
					ver.a = it-cubes.begin();
					ver.b=i;ver.c=j;ver.d=k;
					vec.push_back(ver);
				}
			}
		}
	}
	sort(vec.begin(),vec.end(),comp);
	for(int i=0;i<vec.size();i++)
	{
		cout<<"Cube = "<<vec[i].a<<", Triple = ("<<vec[i].b<<","<<vec[i].c<<","<<vec[i].d<<")"<<endl;
	}
}
