#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int head=1,tail=1,sub[int(1e6+5)],pri[int(1e6+5)];
int main()
{
	int n;
	cin>>n;
	ll sum=0;
	for(int k=1;k<=n;k++)
	{
		int op,pr,ti;
		cin>>op>>pr>>ti;
		if(!op)
		{
			sum+=pr;
			sub[tail]=ti+45;
			pri[tail++]=pr;
		}
		else
		{
			if(head>=tail)
			{
				sum+=pr;
				continue;
			}
			while(sub[head]<ti&&head<tail)
			{
				head++;
			}
			if(head>=tail)
			{
				sum+=pr;
				continue;
			}
			int i=head;
			while(i<tail)
			{
				if(pri[i]>=pr)
				{
					break;
				}
				i++;
			}
			if(i>=tail)
			{
				sum+=pr;
			}
			else
			{
				for(int j=i-1;j>=head;j--)
				{
					pri[j+1]=pri[j];
					sub[j+1]=sub[j];
				}
				head++;
			}
		}
	}
	cout<<sum;
	return 0;
}
