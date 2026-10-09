#include<iostream>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
ll c[2005][2005];
ll quickpow(ll k,ll n)
{
	ll sum=1;
	while(n>0)
	{
		if(n&1)
		{
			sum=sum*k%mod;
		}
		k=k*k%mod;
		n>>=1;
	}
	return sum;
}
int main()
{
	for(int i=1;i<=2001;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==1||j==i-1)
			{
				c[i][j]=i;
			}
			else if(j==0||j==i)
			{
				c[i][j]=1;
			}
			else
			{
				c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
			}
		}
	}
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		if(m<2*k)
		{
			cout<<"0"<<endl;
		}
		else if(n==k)
		{
			cout<<"1"<<endl;
		}
		else
		{
			cout<<c[n][k]%mod*c[n-k][m-2*k]%mod*quickpow(2,m-2*k)%mod<<endl;
		}
	}
	return 0;
}
