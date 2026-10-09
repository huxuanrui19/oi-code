#include<bits/stdc++.h>
using namespace std;
int n,k,m,x,y,o[1005],c[1005],s[1005],ans[1005];
unordered_map<int,int> ma;
int two(int xx,int yy)
{
	return (n+1)*xx+yy;
}
int three(int xx,int yy,int zz)
{
	return (n+1)*(n+1)*xx+(n+1)*yy+zz;
}
int main()
{
	memset(ans,0,sizeof(ans));
	cin>>n>>k>>m>>x>>y;
	if(k==1)
	{
		for(int i=1;i<=m;i++)
		{
			cin>>o[i];
			ma[o[i]]=1;
		}
		for(int i=1;i<=x;i++)
		{
			cin>>s[i];
			ma[s[i]]=2;
		}
		for(int i=1;i<=y;i++)
		{
			cin>>c[i];
			ma[c[i]]=3;
		}
		for(int i=1;i<=n;i++)
		{
			if(ma.find(i)==ma.end())
			{
				ma[i]=0;
			}
		}
		for(int i=1;i<=y;i++)
		{
			int j=c[i];
			while(j-1)
			{
				j--;
				if(ma[j]==1)
				{
					ans[i]++;
				}
				if(ma[j])
				{
					break;
				}
			}
			j=c[i];
			while(j<n)
			{
				j++;
				if(ma[j]==1)
				{
					ans[i]++;
				}
				if(ma[j])
				{
					break;
				}
			}
		}
		for(int i=1;i<=y;i++)
		{
			cout<<ans[i]<<" ";
		}
	}
	else if(k==2)
	{
		int xx,yy;
		for(int i=1;i<=m;i++)
		{
			cin>>xx>>yy;
			o[i]=two(xx,yy);
			ma[o[i]]=1;
		}
		for(int i=1;i<=x;i++)
		{
			cin>>xx>>yy;
			s[i]=two(xx,yy);
			ma[s[i]]=2;
		}
		for(int i=1;i<=y;i++)
		{
			cin>>xx>>yy;
			c[i]=two(xx,yy);
			ma[c[i]]=3;
		}
		for(int i=1;i<=y;i++)
		{
			int xj=c[i]/(n+1);
			int yj=c[i]%(n+1);
			while(xj)
			{
				xj--;
				if(ma.find(two(xj,yj))!=ma.end())
				{
					if(ma[two(xj,yj)]==1)
					{
						ans[i]++;
					}
					break;
				}
			}
			xj=c[i]/(n+1);
			while(xj<n)
			{
				xj++;
				if(ma.find(two(xj,yj))!=ma.end())
				{
					if(ma[two(xj,yj)]==1)
					{
						ans[i]++;
					}
					break;
				}
			}
			xj=c[i]/(n+1);
			yj=c[i]%(n+1);
			while(yj)
			{
				yj--;
				if(ma.find(two(xj,yj))!=ma.end())
				{
					if(ma[two(xj,yj)]==1)
					{
						ans[i]++;
					}
					break;
				}
			}
			yj=c[i]%(n+1);
			while(yj<n)
			{
				yj++;
				if(ma.find(two(xj,yj))!=ma.end())
				{
					if(ma[two(xj,yj)]==1)
					{
						//cout<<"4 "<<xj<<" "<<yj<<endl;
						ans[i]++;
					}
					break;
				}
			}
		}
		for(int i=1;i<=y;i++)
		{
			cout<<ans[i]<<" ";
		}
	}
	else
	{
		int xx,yy,zz;
		for(int i=1;i<=m;i++)
		{
			cin>>xx>>yy>>zz;
			o[i]=three(xx,yy,zz);
			ma[o[i]]=1; 
		}
		for(int i=1;i<=x;i++)
		{
			cin>>xx>>yy>>zz;
			s[i]=three(xx,yy,zz);
			ma[s[i]]=2; 
		}
		for(int i=1;i<=y;i++)
		{
			cin>>xx>>yy>>zz;
			c[i]=three(xx,yy,zz);
			ma[c[i]]=3; 
		}
		for(int i=1;i<=y;i++)
		{
			int xj=c[i]/(n+1)/(n+1);
			int yj=(c[i]/(n+1))%(n+1);
			int zj=c[i]%(n+1);
			while(xj)
			{
				xj--;
				if(ma.find(three(xj,yj,zj))!=ma.end())
				{
					if(ma[three(xj,yj,zj)]==1)
					{
						ans[i]++;
					}
					break;
				}
			}
			xj=c[i]/(n+1)/(n+1);
			yj=(c[i]/(n+1))%(n+1);
			zj=c[i]%(n+1);
			while(xj<n)
			{
				xj++;
				if(ma.find(three(xj,yj,zj))!=ma.end())
				{
					if(ma[three(xj,yj,zj)]==1)
					{
						ans[i]++;
					}
					break;
				}
			}
			xj=c[i]/(n+1)/(n+1);
			yj=(c[i]/(n+1))%(n+1);
			zj=c[i]%(n+1);
			while(yj)
			{
				yj--;
				if(ma.find(three(xj,yj,zj))!=ma.end())
				{
					if(ma[three(xj,yj,zj)]==1)
					{
						ans[i]++;
					}
					break;
				}
			}
			xj=c[i]/(n+1)/(n+1);
			yj=(c[i]/(n+1))%(n+1);
			zj=c[i]%(n+1);
			while(yj<n)
			{
				yj++;
				if(ma.find(three(xj,yj,zj))!=ma.end())
				{
					if(ma[three(xj,yj,zj)]==1)
					{
						//cout<<"4 "<<xj<<" "<<yj<<endl;
						ans[i]++;
					}
					break;
				}
			}
			xj=c[i]/(n+1)/(n+1);
			yj=(c[i]/(n+1))%(n+1);
			zj=c[i]%(n+1);
			while(zj)
			{
				zj--;
				if(ma.find(three(xj,yj,zj))!=ma.end())
				{
					if(ma[three(xj,yj,zj)]==1)
					{
						ans[i]++;
					}
					break;
				}
			}
			xj=c[i]/(n+1)/(n+1);
			yj=(c[i]/(n+1))%(n+1);
			zj=c[i]%(n+1);
			while(zj<n)
			{
				zj++;
				if(ma.find(three(xj,yj,zj))!=ma.end())
				{
					if(ma[three(xj,yj,zj)]==1)
					{
						//cout<<"4 "<<xj<<" "<<yj<<endl;
						ans[i]++;
					}
					break;
				}
			}
		}
		for(int i=1;i<=y;i++)
		{
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}
