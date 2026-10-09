#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10,M=20;
int n,arr[N],cnt[N];
ll st[N][M],LOG2[N];
void build(){
	LOG2[0]=-1;
	for(int i=1;i<=n;i++) LOG2[i]=LOG2[i>>1]+1;
	for(int i=1;i<=n;i++) st[i][0]=cnt[i];
	int m=LOG2[n];
	for(int i=1;i<=m;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
}
ll query(ll l,ll r){
	int p=LOG2[r-l+1];
	return max(st[l][p],st[r-(1<<p)+1][p]);
}
int main(){
	//freopen("P2471_6.in","r",stdin);
	//freopen("P2471_61.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i]>>cnt[i];
	}
	build();
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		ll pos1=lower_bound(arr+1,arr+n+1,x)-arr,pos2=lower_bound(arr+1,arr+n+1,y)-arr;
		ll flag1=1,flag2=1;
		if(arr[pos1]!=x) flag1=0;
		if(arr[pos2]!=y) flag2=0;
		if(flag1==0&&flag2==0) cout<<"maybe\n";
		else if(flag1==0&&flag2==1){
			if(pos1==pos2) cout<<"maybe\n";
			else if(query(pos1,pos2-1)>=cnt[pos2]) cout<<"false\n";
			else cout<<"maybe\n";
		}
		else if(flag1==1&&flag2==0){
			if(pos1==pos2-1) cout<<"maybe\n";
			else if(query(pos1+1,pos2-1)<cnt[pos1]) cout<<"maybe\n";
			else cout<<"false\n";
		}
		else{
			if(cnt[pos1]<cnt[pos2]) cout<<"false\n";
			else if(pos1==pos2-1){
				if(y-x==1) cout<<"true\n";
				else cout<<"maybe\n";
			}
			else{
				ll num=query(pos1+1,pos2-1);
				if(num<cnt[pos2]){
					if((pos2-pos1)==(y-x)) cout<<"true\n";
					else cout<<"maybe\n";
				}
				else cout<<"false\n";
			}
		}
	}
	return 0;
}

