#include<bits/stdc++.h>
using namespace std;
string a[15]={"2(0)","2","2(2)","2(2+2(0))","2(2(2))","2(2(2)+2(0))","2(2(2)+2)","2(2(2)+2+2(0))","2(2(2+2(0)))","2(2(2+2(0))+2(0))","2(2(2+2(0))+2)","2(2(2+2(0))+2+2(0))","2(2(2+2(0))+2(2))","2(2(2+2(0))+2(2)+2(0))","2(2(2+2(0))+2(2)+2)"};
int lowbit(int n)
{
	return n&(-n);
}
int main()
{
	int n;
	cin>>n;
	stack<int> st;
	while(n)
	{
		st.push(lowbit(n));
		n-=lowbit(n);
	}
	while(!st.empty())
	{
		cout<<a[int(log2(st.top()))];
		if(st.size()!=1)
		{
			cout<<"+";
		}
		st.pop();
	}
	return 0;
}
