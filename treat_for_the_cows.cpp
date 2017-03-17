#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>

using namespace std;
#define ull int


vector<ull> v,sums;
void dosum()
{
  sums[0]=v[0];
  for(int i=1;i<sums.size();i++)
  {
    sums[i]=sums[i-1]+v[i];
  }
  return;
}

ull subsum(int i, int j)
{
  if(i<=0)return sums[j];
  else if(i>j)return 0;
  else return sums[j]-sums[i-1];
}


int main()
{
  int n;
  cin>>n;
  v.resize(n);
  vector<vector<int> > ans;
  ans.resize(n);
  for(int i=0;i<n;i++)ans[i].resize(n);
  sums.resize(n);
  for(int i=0;i<n;i++)scanf("%d",&v[i]);
  dosum();
  //unordered_map<int,int> ans;
  ans[0][0]=0;
  for(int j=0;j<n;j++)
  {
    ans[j][j]=v[j];
  }
  for(int i=2;i<=n;i++)
  {
    for(int j=0;j<=n-i;j++)
    {
      ans[j][i+j-1]=max(v[j]+ans[j+1][i+j-1]+subsum(j+1,i+j-1),v[i+j-1]+ans[j][i+j-2]+subsum(j,i+j-2));
    //  cout<<ans[j*3000+(i+j-1)]<<endl;
    }
  }
  printf("%d\n",ans[0][n-1]);

}
