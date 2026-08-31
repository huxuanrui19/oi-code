#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,ans,p[N],pre1[N],nxt1[N],pre2[N],nxt2[N];	//leftmax,rightmax,leftmin,rightmin;
int top=0,stk[N];
int query(int x,int k){
	int l=1,r=x,cnt=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(stk[mid]>=k){
			cnt=mid;l=mid+1;
		}else r=mid-1;
	}
	return x-cnt;
}
int main() {
	//freopen("interval2.in","r",stdin);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i];
	ans=n*(n-1)/2;
	for(int i=1;i<=n;i++){
		while(top&&p[stk[top]]<p[i]) stk[top--]=0;
		pre1[i]=stk[top];
		stk[++top]=i;
	}
	top=0;
	for(int i=n;i>=1;i--){
		while(top&&p[stk[top]]<p[i]) stk[top--]=0;
		nxt1[i]=(top==0)?n+1:stk[top];
		stk[++top]=i;
	}
	for(int i=1;i<=n;i++) ans-=(nxt1[i]-pre1[i]-2);
	top=0;
	for(int i=1;i<=n;i++){
		while(top&&p[stk[top]]>p[i]) stk[top--]=0;
		pre2[i]=stk[top];
		stk[++top]=i;
	}
	top=0;
	for(int i=n;i>=1;i--){
		while(top&&p[stk[top]]>p[i]) stk[top--]=0;
		nxt2[i]=(top==0)?n+1:stk[top];
		stk[++top]=i;
	}
	for(int i=1;i<=n;i++) ans-=(nxt2[i]-pre2[i]-2);
	top=0;
	for(int i=n;i>=1;i--){
		while(top&&p[stk[top]]<p[i]) stk[top--]=0;
		stk[++top]=i;
		ans+=query(top,nxt2[i])-1;
	}
	top=0;
	for(int i=n;i>=1;i--){
		while(top&&p[stk[top]]>p[i]) stk[top--]=0;
		stk[++top]=i;
		ans+=query(top,nxt1[i])-1;
	}
	cout<<ans;
	return 0;
}