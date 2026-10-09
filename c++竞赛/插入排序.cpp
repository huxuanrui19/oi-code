#include<bits/stdc++.h>
using namespace std;
struct node{
	int val,id;
}a[8005];
bool cmp(node x,node y){
	if(x.val!=y.val) return x.val<y.val;
	return x.id<y.id;
}
int b[8005];
int main(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].val;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		b[a[i].id]=i;
	}
	for(int i=1;i<=q;i++){
		int op;
		cin>>op;
		if(op==1){
			int x,v;
			cin>>x>>v;
			a[b[x]].val=v;
			for(int j=n;j>1;j--){
				if(!cmp(a[j-1],a[j])){
					swap(a[j-1],a[j]);
				}
			}
			for(int j=2;j<=n;j++){
				if(!cmp(a[j-1],a[j])){
					swap(a[j-1],a[j]);
				}
			}
			for(int j=1;j<=n;j++){
				b[a[j].id]=j;
			}
		}
		if(op==2){
			int x;
			cin>>x;
			cout<<b[x]<<endl;
		}
	}
	return 0;
}
