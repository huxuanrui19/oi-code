#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,L=1e6+10,maxs=INT_MAX; 
int d[N],a[N],v0[N],p[N],b[N],s[L],ls[L];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(d,0,sizeof(d));
		memset(a,0,sizeof(a));
		memset(v0,0,sizeof(v0));
		memset(p,0,sizeof(p));
		memset(s,0,sizeof(s));
		int n,m,l,v;
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v0[i]>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
			ls[p[i]]=1;
		}
		for(int i=1;i<=L;i++)
		{
			s[i]=s[i-1]+ls[i];
		}
        for(int i=1;i<=n;i++)
        {
            if(v0[i]>v)
            {
                if(a[i]<0)
                {
                    b[i]=d[i]+floor((v*v-v0[i]*v0[i]/double(2*a)));
                }
                else
                {
                    b[i]=L;
                }
            }
            else
            {
                if(a[i]>0)
                {
                   b[i]=d[i]+floor((v*v-v0[i]*vo[i])/double(2*a)); 
                }
                else
                {
                    b[i]=d[i];
                }
            }
        }
        int res=0;
        for(i=1;i<=n;i++)
        {
            if(ls[b[i]]-ls[d[i]]>0)
            {
                res++;
            }
        }
        cout<<res<<endl;
	}
    return 0;
}

