#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		if(a.size()<b.size())
		{
			cout<<"N"<<endl;
			continue;
		}
		int lena=a.size();
		a=a+a;
		int rs=0;
		for(int i=0;i<lena;i++)
		{
			string c=a.substr(i,lena);
			int k=0;
			for(int j=0;j<lena;j++)
			{
				if(c[j]==b[k])
				{
					k++;
				}
				if(k==b.size())
				{
					rs=1;
					break;
				}
			}
			if(rs)
			{
				break;
			}
		}
		if(rs==1)
		{
			cout<<"Y"<<endl;
		}
		else
		{
			cout<<"N"<<endl;
		}
	}
	return 0;
}
