#include<bits/stdc++.h>
using namespace std;
void ch(string &s)
{
	for(int i=0;i<s.size();i++)
	{
		s[i]=tolower(s[i]);
	}
}
int solve(){
	string s,_s;
	cin>>_s>>s;
	ch(_s),ch(s);
	int pos=0,num=0;
	while(s.find(_s[0],pos)!=string::npos) 
	{
		pos=s.find(_s[0],pos);
		int flag=1;
		for(int i=0;i<_s.size();i++)
		{
			if(s[pos+i]==_s[i])
			{
				continue;
			}
			else
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			num++;
		}
		pos++;
	}
	cout<<num<<endl;
	return 0;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		solve();
	}
	return 0;
}
