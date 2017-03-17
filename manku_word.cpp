#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define ull unsigned long long int
#define LIM 1000000000000000000

vector<ull> numwords,nw;

void calc_num_words()
{
	numwords.push_back(0);
	nw.push_back(1);
	ull var=1;
	while(var<LIM)
	{
		var*=5;
		numwords.push_back(var);
		nw.push_back(var);
		numwords[numwords.size()-1]+=numwords[numwords.size()-2];
	}
	return;
}

int main()
{
	calc_num_words();
	string vars[5] = {"m","a","n","k","u"};
	string varr[6]={"m","m","a","n","k","u"};
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ull word_num;
		cin>>word_num;
		int position;
		for(int i=0;i<numwords.size();i++)
		{
			if(numwords[i]>=word_num)
			{
				position=i;
				break;
			}
		}
		word_num--;
		word_num-=numwords[position-1];
		string ans="";
		for(int i=position-1;i>=0;i--)
		{
			ans=ans+vars[word_num/nw[i]];
			word_num%=nw[i];
		}
		cout<<ans<<endl;
	}
}
