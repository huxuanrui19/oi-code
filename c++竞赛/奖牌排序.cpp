#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int cnt,rk[N],num[N];
struct node{
	int au,ag,cu,id;
}a[N];
bool cmp1(node x,node y){
	return x.au>y.au;
}
bool cmp2(node x,node y){
	return x.ag>y.ag;
}
bool cmp3(node x,node y){
	return x.cu>y.cu;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].au>>a[i].ag>>a[i].cu;
		a[i].id=i;
	}
	a[0]={-1,-1,-1,0};
	memset(rk,0x3f,sizeof(rk));
	sort(a+1,a+n+1,cmp1);
	int last=1;
	for(int i=1;i<=n;i++){
		if(a[i].au==a[i-1].au){
			last++;
			num[i]=num[i-1];
		}
		else{
			num[i]=num[i-1]+last;
			last=1;
		}
		rk[a[i].id]=min(rk[a[i].id],num[i]);
	}
	sort(a+1,a+n+1,cmp2);
	last=1;
	for(int i=1;i<=n;i++){
		if(a[i].ag==a[i-1].ag){
			last++;
			num[i]=num[i-1];
		}
		else{
			num[i]=num[i-1]+last;
			last=1;
		}
		rk[a[i].id]=min(rk[a[i].id],num[i]);
	}
	sort(a+1,a+n+1,cmp3);
	last=1;
	for(int i=1;i<=n;i++){
		if(a[i].cu==a[i-1].cu){
			last++;
			num[i]=num[i-1];
		}
		else{
			num[i]=num[i-1]+last;
			last=1;
		}
		rk[a[i].id]=min(rk[a[i].id],num[i]);
	}
	for(int i=1;i<=n;i++){
		cout<<rk[i]<<'\n';
	}
	return 0;
}

