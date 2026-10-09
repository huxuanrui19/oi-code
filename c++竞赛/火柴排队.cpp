#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll mod=1e8-3;
struct node{
	ll num,ind;
}a[N],b[N];
int x[N],tmp[N];
ll cnt=0;
bool cmp(node x,node y){
	return x.num<y.num;
}
void mer(int l,int mid,int r){
	int i=l,j=mid+1,t=0;
	while(i<=mid&&j<=r){
		if(x[i]>x[j]){
			tmp[t++]=x[j++];
			cnt=(cnt+mid-i+1)%mod;
		}
		else{
			tmp[t++]=x[i++];
		}
	}
	while(i<=mid) tmp[t++]=x[i++];
	while(j<=r) tmp[t++]=x[j++];
	for(int i=0;i<t;i++){
		x[l+i]=tmp[i];
	}
}
void ms(int l,int r){
	if(l<r){
		int mid=(l+r)>>1;
		ms(l,mid);
		ms(mid+1,r);
		mer(l,mid,r);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		a[i].ind=i;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i].num;
		b[i].ind=i;
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++){
		x[b[i].ind]=a[i].ind;
	}
	ms(1,n);
	cout<<cnt;
	return 0;
}

