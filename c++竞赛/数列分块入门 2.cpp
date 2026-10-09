#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10,M=505;
ll n,m,a[N],cop[N],lt[M],rt[M],pos[N],add[M];
void build(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cop[i]=a[i];
	}
	m=sqrt(n);
	int j=1;
	for(int i=1;i<=m;i++){
		lt[i]=m*(i-1)+1;
		rt[i]=m*i;
	}
	rt[m]=n;
	for(int i=1;i<=m;i++){
		for(int j=lt[i];j<=rt[i];j++){
			pos[j]=i;
		}
	}
	for(int i=1;i<=m;i++){
		sort(cop+lt[i],cop+rt[i]+1);
	}
}
void update(int l,int r,ll c){
	if(pos[l]==pos[r]){
		for(int i=l;i<=r;i++){
			a[i]+=c;
		}
		int lid=lt[pos[l]],rid=rt[pos[l]];
        for(int i=lid;i<=rid;i++){
            a[i]+=add[pos[l]];
        }
        add[pos[l]]=0;
		for(int i=lid;i<=rid;i++){
			cop[i]=a[i];
		} 
		sort(cop+lid,cop+rid+1);
	}
	else{
		for(int i=pos[l]+1;i<pos[r];i++){
			add[i]+=c;
		}
		update(l,rt[pos[l]],c);
		update(lt[pos[r]],r,c);
	}
}
ll query(int l,int r,ll c){
	int ans=0;
	if(pos[l]==pos[r]){
		for(int i=l;i<=r;i++){
			if((a[i]+add[pos[l]])<c){
				ans++;
			}
		}
		return ans;
	}
	else{
		for(int i=pos[l]+1;i<pos[r];i++){
			int num=lower_bound(cop+lt[i],cop+rt[i]+1,c-add[i])-(cop+lt[i]);
			ans+=num;
		}
		ans+=query(l,rt[pos[l]],c);
		ans+=query(lt[pos[r]],r,c);
		return ans;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	build();
	for(int i=1;i<=n;i++){
		ll opt,l,r,c;
		cin>>opt>>l>>r>>c;
		if(opt==0){
			update(l,r,c);
		}
		else cout<<query(l,r,c*c)<<"\n";
	}
	return 0;
}
