#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b[int(5e5+5)],sum[int(5e5+5)];
struct node{
	ll num,f,g,id;
}a[int(5e5+5)];
bool comp(node x,node y){
	return x.num>y.num;
}
int main(){
	int c,n,k;
	cin>>c>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+n+1,comp);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i].num;
		b[a[i].id]=i;
	}
	a[1].f=1;
	for(int i=2;i<=n;i++){
		if(a[i-1].num==a[i].num){
			a[i].f=a[i-1].f;
		}
		else
		{
			a[i].f=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(i==n){
			a[i].g=n;
			break;
		}
		if(a[i].num!=a[i+1].num){
			a[i].g=i;
		}
	}
	for(int i=n;i>=1;i--){
		if(a[i].g){
			continue;
		} 
		a[i].g=a[i+1].g;
	}
	for(int i=1;i<=n;i++){
		if(a[b[i]].f>k){
			cout<<a[k].num-a[b[i]].num<<endl;
		}
		else if(a[b[i]].g<k){
			cout<<(k-b[i]+1)*a[b[i]].num-sum[k]+sum[b[i]-1]<<endl;
		}
		else{
			cout<<"0"<<endl;
		}
	}
	return 0;
}

