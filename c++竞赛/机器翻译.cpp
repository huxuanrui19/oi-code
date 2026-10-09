#include<bits/stdc++.h>
using namespace std;
int h[1005]={0};
queue<int> mem;
int main()
{
	int m,n;
	cin>>m>>n;
	int cnt=0;
	while(n--)
	{
		int k;
		cin>>k;
		if(!h[k])
		{
			++cnt;
			mem.push(k);
			h[k]=1;
			if(mem.size()>m)
			{
				h[mem.front()]=0;
				mem.pop();
			}
		}
	}
	cout<<cnt;
	return 0;
}
