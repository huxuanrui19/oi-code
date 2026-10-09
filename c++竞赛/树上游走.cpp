#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	long long n,st;
	cin>>n>>st;
	cin>>s;
	stack<int> b;
	stack<int> ss;
	while(st)
	{
		ss.push(st&1);
		st/=2;
	}
	while(!ss.empty())
	{
		b.push(ss.top());
		ss.pop();
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='U')
		{
			if(st!=1)
			{
				int cnt=b.top();
				b.pop();
				if(b.empty())
				{
					b.push(cnt);
				}
			}
		}
		else if(s[i]=='L')
		{
			b.push(0);
		}
		else
		{
			b.push(1);
		} 
	}
	long long num=0,i=0;
	while(!b.empty())
	{
		num+=b.top()*pow(2,i);
		b.pop();
		i++;
	}
	cout<<num;
	return 0;
}
