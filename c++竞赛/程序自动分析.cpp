#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int cnt,fa[2*N];
vector<int> b;
int fi(int s){
	if(s!=fa[s]) return fa[s]=fi(fa[s]);
	return s;
}
void mer(int x,int y){
	x=fi(x);
	y=fi(y);
	if(x!=y) fa[x]=y; 
}
struct oper{
	int x,y,op;
}a[N];
bool cmp(oper n,oper m){
	return n.op>m.op;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].op;
			b.push_back(a[i].x);
			b.push_back(a[i].y);
		}
		sort(b.begin(),b.end());
		b.erase(unique(b.begin(),b.end()),b.end());
        int l=b.size();
		for(int i=0;i<=l;i++){
			fa[i]=i;
		}
		sort(a+1,a+n+1,cmp);
		int flag=0;
		for(int i=1;i<=n;i++){
			a[i].x=lower_bound(b.begin(),b.end(),a[i].x)-b.begin()+1;
			a[i].y=lower_bound(b.begin(),b.end(),a[i].y)-b.begin()+1;
			if(a[i].op==1){
				mer(a[i].x,a[i].y);
			}
			else{
				if(fi(a[i].x)==fi(a[i].y)){
					cout<<"NO"<<endl;
					flag=1;
					break;
				}
			}
		}
		if(!flag){
			cout<<"YES"<<endl;
		}
		b.clear();
		cnt=0;
	}
	return 0;
}
