#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,d;
}ty[10005];
int judge(string s,int i)
{
	if(s[i]=='L')
	{
		if(i<s.size()-1)
		{
			if(s[i+1]==char(39))
			{
				return 2;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			return 1;
		}
	}
	else if(s[i]=='R')
	{
		if(i<s.size()-1)
		{
			if(s[i+1]==char(39))
			{
				return 4;
			}
			else
			{
				return 3;
			}
		}
		else
		{
			return 3;
		}
	}
}
int main()
{
	string s;
	cin>>s;
	int flag;
	cin>>flag;
	int zk=0,type=0,len=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(')
		{
			zk=1;
			len++;
		}
		if(s[i]==')')
		{
			zk=0;
			type++;
		}
		if((s[i]=='L'||s[i]=='R')&&zk==0)
		{
			type++;
			if(judge(s,i)==1)
			{
				ty[++len].a++;
			}
			if(judge(s,i)==2)
			{
				ty[++len].b++;
			}
			if(judge(s,i)==3)
			{
				ty[++len].c++;
			}
			if(judge(s,i)==4)
			{
				ty[++len].d++;
			}
		}
		if(zk==1&&s[i]=='L'||s[i]=='R')
		{
			if(judge(s,i)==1)
			{
				ty[len].a++;
			}
			if(judge(s,i)==2)
			{
				ty[len].b++;
			}
			if(judge(s,i)==3)
			{
				ty[len].c++;
			}
			if(judge(s,i)==4)
			{
				ty[len].d++;
			}
		}
	}
	cout<<type<<endl;
	if(flag==1)
	{
		int mark=0,maxl=-1,cur=0;
		for(int j=1;j<=len;j++)
		{
			if(ty[j].a)
			{
				mark=1;
				cur++;
			}
			if(!ty[j].a)
			{
				mark=0;
				maxl=max(cur,maxl);
				cur=0;
			}
		}
		maxl=max(cur,maxl);
		cout<<maxl<<" ";
		mark=0,maxl=-1,cur=0;
		for(int j=1;j<=len;j++)
		{
			if(ty[j].b)
			{
				mark=1;
				cur++;
			}
			if(!ty[j].b)
			{
				mark=0;
				maxl=max(cur,maxl);
				cur=0;
			}
		}
		maxl=max(cur,maxl);
		cout<<maxl<<" ";
		mark=0,maxl=-1,cur=0;
		for(int j=1;j<=len;j++)
		{
			if(ty[j].c)
			{
				mark=1;
				cur++;
			}
			if(!ty[j].c)
			{
				mark=0;
				maxl=max(cur,maxl);
				cur=0;
			}
		}
		maxl=max(cur,maxl);
		cout<<maxl<<" ";
		mark=0,maxl=-1,cur=0;
		for(int j=1;j<=len;j++)
		{
			if(ty[j].d)
			{
				mark=1;
				cur++;
			}
			if(!ty[j].d)
			{
				mark=0;
				maxl=max(cur,maxl);
				cur=0;
			}
		}
		maxl=max(cur,maxl);
		cout<<maxl;
	}
	return 0;
}
