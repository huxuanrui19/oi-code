#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int de(int a,int b,int c)
{
	return b*b-4*a*c; 
}
int issq(int n)
{
	int c=floor(sqrt(double(n)));
	if(c*c==n)
	{
		return 1;
	}
	return 0;
}
int sq(int n)
{
	int k=1;
	for(int i=2;i<=floor(sqrt(n));i++)
	{
		if(n%(i*i)==0)
		{
			k=i;
		}
	}
	return k;
}
int main()
{
	int t,m;
	cin>>t>>m;
	for(int i=1;i<=t;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int delta=de(a,b,c);
		if(delta<0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		else
		{
			if(a<0)
			{
				a*=-1;
				b*=-1;
				c*=-1;
			}
			if(issq(delta))
			{
				int p=-1*b+sqrt(delta);
				int q=2*a;
				int g=gcd(abs(p),q);
				p/=g;
				q/=g;
				if(q==1)
				{
					cout<<p<<endl;
					continue;
				}
				else
				{
					cout<<p<<"/"<<q<<endl;
				}
			}
			else
			{
				int p1=-1*b;
				int q1=2*a;
				if(p1!=0)
				{
					
					int g1=gcd(abs(p1),q1);
					p1/=g1;
					q1/=g1;
					if(q1==1)
					{
						cout<<p1<<"+";
					}
					else
					{
						cout<<p1<<"/"<<q1<<"+";
					}
					q1*=g1;
				}
				int d=sq(delta);
				if(d==1)
				{
					cout<<"sqrt("<<delta<<")"<<"/"<<q1<<endl;
				}
				else
				{
					int _d=delta/(d*d);
					int g2=gcd(d,q1);
					d/=g2;
					q1/=g2;
					if(q1==1&&d==1)
					{
						cout<<"sqrt("<<_d<<")"<<endl;
					}
					else if(q1!=1&&d!=1)
					{
						cout<<d<<"*sqrt("<<_d<<")/"<<q1<<endl;
					}
					else if(q1==1&&d!=1)
					{
						cout<<d<<"*sqrt("<<_d<<")"<<endl;
					}
					else
					{
						cout<<"sqrt("<<_d<<")/"<<q1<<endl;
					}
					continue;
				}
			}
		}
	}
	return 0;
}
