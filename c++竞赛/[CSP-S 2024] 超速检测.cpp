#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N=1e5+5,inf=1e9+10;
struct block{
	int l,r;
}bl[N];
bool cmp(block a,block b){
	if(a.r!=b.r)return a.r<b.r;
	return a.l<b.l;
}
int d[N],a[N],v[N],p[N];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,l,vm,ans=0;			//车辆数量，测试仪数量，道路长度，道路限速。
		cin>>n>>m>>l>>vm;
		
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		
		for(int i=1;i<=n;i++){
			int ls,rs,flag1,flag2;			//1->yk,2->zk; 
			if(a[i]>0){
				rs=l;
				flag1=0;
				if(v[i]>=vm){
					ls=d[i];
					flag2=(v[i]==vm);
				}
				else if(d[i]+((vm*vm-v[i]*v[i])+2*a[i]-1)/(2*a[i])>l)
				{
					continue;
				}
				else
				{
					ls=d[i]+((vm*vm-v[i]*v[i])+2*a[i]-1)/(2*a[i]);
					flag2=(ls==d[i]+(vm*vm-v[i]*v[i])/(2*a[i]));
				}
			}
			else if(a[i]==0){
				if(v[i]<=vm)
				{
					continue;
				}
				flag1=flag2=0;
				ls=d[i];
				rs=l;
			}
			else{
				if(v[i]<=vm){
					continue;
				}
				ls=d[i],flag2=0;
				if(d[i]+(vm*vm-v[i]*v[i])/(2*a[i])>=l){
					rs=l;
					flag1=0;
				}
				else{
					rs=d[i]+(vm*vm-v[i]*v[i])/(2*a[i]);
					flag1=((vm*vm-v[i]*v[i])%(2*a[i])==0);
				}
			}
			
			int lp=1,rp=m,mid;
			while(lp<rp){
				mid =(lp + rp)>>1;
				if(p[mid]>ls||p[mid]==ls&&!flag2)rp=mid;
				else lp=mid+1;
			}
			if(p[lp]<ls||p[lp]==ls&&flag2||p[lp]>rs||p[lp]==rs&&flag1)continue; 
			bl[++ans].l=lp; 
			lp=1,rp=m;
			while(lp<rp){
				mid=(lp+rp+1)>>1;
				if(p[mid]<rs||p[mid]==rs&&!flag1)lp=mid;
				else rp=mid-1;
			}
			bl[ans].r=lp;
		}
		cout<<ans<<" ";
		
		sort(bl+1,bl+ans+1,cmp);
		int las=-1,_ans=0;
		for(int i=1;i<=ans;i++){
			if(bl[i].l<=las){
				continue;
			}
			las=bl[i].r;
			_ans++;
		}
		cout<<m-_ans<<endl;
	}
	return 0;
} 
