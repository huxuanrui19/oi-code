#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a[16]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
int main()
{
	string s;
	cin>>s;
	int num=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==':')
		{
			num++;
		}
	}
	queue<string> st;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==':')
		{
			if(s[i+1]!=':')
			{	
				if(st.size()<4)
				{
					for(int j=1;j<=4-st.size();j++)
					{
						cout<<"0000";
					}
				}
				while(!st.empty())
				{
					cout<<st.front();
					st.pop();
				}
			}
			else
			{
				if(st.size()<4)
				{
					for(int j=1;j<=4-st.size();j++)
					{
						cout<<"0000";
					}
				}
				while(!st.empty())
				{
					cout<<st.front();
					st.pop();
				}
				for(int i=1;i<=7-num;i++)
				{
					cout<<"0000000000000000";
				}
			}
		}
		else
		{
			int cur=0;
			if(s[i]>='0'&&s[i]<='9')
			{
				cur=s[i]-'0';
			}
			else
			{
				cur=s[i]-'A'+10;
			}
			st.push(a[cur]);
		}
	}
	if(st.size()<4)
	{
		for(int j=1;j<=4-st.size();j++)
		{
			cout<<"0000";
		}
	}
	while(!st.empty())
	{
		cout<<st.front();
		st.pop();
	}
	return 0;
}
