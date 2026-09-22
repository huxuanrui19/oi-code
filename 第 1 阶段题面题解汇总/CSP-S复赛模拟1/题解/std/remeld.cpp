#include<bits/stdc++.h>
#define ll long long 
#define double long double
#define maxn 10005
using namespace std;
int vis[28];
int used[28];
int ret;
int cmp(pair<int,int> x,pair<int,int> y) {return x.second>y.second;}
int fangan[10];
void dfs(int turn,int num,int l,int r,int pre)
{
	
	if (turn==6) {ret=min(ret,num); return;}
	if (num>=ret) return;
	if (ret==0) return;
	vector<pair<int,int>> choice;
	if (turn==5) //选将 
	{
		for (int i=1;i<=27;i++)
		if (!(l<=i && i<=r) && used[i]<=2)
		{
			ret=min(ret,num+2-min(vis[i],2));
		}
		return;
	}
	else //选xxx或者x(x+1)(x+2) 
	{
		for (int i=1;i<=27;i++)
		if (!(l<=i && i<=r))
		{
			if (used[i]<=1) choice.push_back({i,min(vis[i],3)});
			if (used[i]<=3 && used[i+1]<=3 && used[i+2]<=3)
			if (i+2<=27 && i+1!=10 && i+2!=10 && i+1!=19 && i+2!=19)
				choice.push_back({-i,min(vis[i],1)+min(vis[i+1],1)+min(vis[i+2],1)});
		}
		for (pair<int,int> tt:choice)
		{
			int id=tt.first,cost=tt.second;
			if (abs(pre)>abs(id)) continue;
			if (id>0) //xxx
			{
				vis[id]-=cost; used[id]+=3;
				fangan[turn]=id;
				dfs(turn+1,num+(3-cost),l,r,id);
				vis[id]+=cost; used[id]-=3;
			}
			else //xx+1x+2
			{
				id=-id;
				int f[3]={0};
				if (vis[id]) f[0]=1,vis[id]--;
				if (vis[id+1]) f[1]=1,vis[id+1]--;
				if (vis[id+2]) f[2]=1,vis[id+2]--;
				used[id]++; used[id+1]++; used[id+2]++;
				fangan[turn]=-id;
				dfs(turn+1,num+(3-cost),l,r,id);
				used[id]--; used[id+1]--; used[id+2]--;
				if (f[0]) vis[id]++;
				if (f[1]) vis[id+1]++;
				if (f[2]) vis[id+2]++;
			}
		}
	}
	return;
}

void work()
{
	memset(vis,0,sizeof(vis));
	ret=14; int x;
	for (int i=1;i<=14;i++) {cin>>x; vis[x]++;} 
	dfs(1,0,1,9,0);  //一共5轮 
	dfs(1,0,10,18,0);
	dfs(1,0,19,27,0);
	cout<<ret<<endl;
}

int main()
{
	int T,cas;
	cin>>T>>cas;
	while (T--) work();
}