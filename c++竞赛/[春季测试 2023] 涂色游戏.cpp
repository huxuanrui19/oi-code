#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct his{
	ll num,ti;
}row[N],col[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		memset(col,0,sizeof(col));
		memset(row,0,sizeof(row));
		int n,m,q;
		cin>>n>>m>>q;
		for(int i=1;i<=q;i++){
			int opt,x,c;
			cin>>opt>>x>>c;
			if(opt==0){
				row[x].num=c;
				row[x].ti=i;
			}
			else if(opt==1){
				col[x].num=c;
				col[x].ti=i;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(col[j].ti>row[i].ti){
					cout<<col[j].num<<" ";
				}
				else{
					cout<<row[i].num<<" ";
				}
			}
			cout<<endl;
		}
	}
	return 0;
}

