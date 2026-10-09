#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
int n,t,a[N],pos[N];
int cal(int l,int r){
	int cnt[N],len=0;
	for(int i=l;i<=r;i++){
		cnt[++len]=a[i];
	}
	sort(cnt+1,cnt+len+1);
	int tt=t-abs(pos[r]-pos[l]);
	int sum=0;
	for(int i=1;i<=len;i++){
		if(tt>=cnt[i]){
			tt-=cnt[i];
			sum++;
		}
		else{
			return sum;
		}
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		cin>>pos[j];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans=max(ans,cal(i,j));
		}
	}
	cout<<ans;
	return 0;
}

