//rotate Treap 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int cnt=0;
struct node{
	int ls,rs;
	int key,pri;
	int size;
}t[N];
void newnode(int x){
	cnt++;
	t[cnt].size=1;
	t[cnt].ls=t[cnt].rs=0;
	t[cnt].key=x;t[cnt].pri=rand();
}
void update(int u){
	t[u].size=t[t[u].ls].size+t[t[u].rs].size+1;
}
void rotate(int &o,int d){
	int k;
	if(d==1){
		k=t[o].rs;
		t[o].rs=t[k].ls;
		t[k].ls=o;
	}	//×óÐý 
	else{
		k=t[o].ls;
		t[o].ls=t[k].rs;
		t[k].rs=o;
	}
	t[k].size=t[o].size;
	update(o);
	o=k;
}
void insert(int &u,int x){
	if(u==0){
		newnode(x);u=cnt;return;
	}
	t[u].size++;
	if(x>=t[u].key) insert(t[u].rs,x);
	else insert(t[u].ls,x);
	if(t[u].ls!=0&&t[u].pri>t[t[u].ls].pri) rotate(u,0);
	if(t[u].rs!=0&&t[u].pri>t[t[u].rs].pri) rotate(u,1);
	update(u);
}
void del(int &u,int x){
	t[u].size--;
	if(t[u].key==x){
		if(t[u].ls==0&&t[u].rs==0){
			u=0;return;
		}
		else if(t[u].ls==0||t[u].rs==0){
			u=t[u].ls+t[u].rs;return;
		}
		else if(t[t[u].ls].pri<t[t[u].rs].pri){
			rotate(u,0);del(t[u].rs,x);return;
		}
		else{
			rotate(u,1);del(t[u].ls,x);return;
		}
	}
	if(t[u].key>=x) del(t[u].ls,x);
	else del(t[u].rs,x);
	update(u);
}
int Rank(int u,int x){
	if(u==0) return 0;
	if(x>t[u].key) return t[t[u].ls].size+1+Rank(t[u].rs,x);
	return Rank(t[u].ls,x);
}
int kth(int u,int k){
	if(k==t[t[u].ls].size+1) return t[u].key;
	if(k>t[t[u].ls].size+1) return kth(t[u].rs,k-t[t[u].ls].size-1);
	if(k<=t[t[u].ls].size) return kth(t[u].ls,k);
}
int precursor(int u,int x){
	if(u==0) return 0;
	if(t[u].key>=x) return precursor(t[u].ls,x);
	int tmp=precursor(t[u].rs,x);
	if(tmp==0) return t[u].key;
	return tmp;
}
int successor(int u,int x){
	if(u==0) return 0;
	if(t[u].key<=x) return successor(t[u].rs,x);
	int tmp=successor(t[u].ls,x);
	if(tmp==0) return t[u].key;
	return tmp;
}
int main(){
	srand(time(NULL));
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int root=0;
	int n;cin>>n;
	while(n--){
		int opt,x;
		cin>>opt>>x;
		switch(opt){
			case 1: insert(root,x);break;
			case 2: del(root,x);break;
			case 3: cout<<Rank(root,x)+1<<"\n";break;
			case 4: cout<<kth(root,x)<<"\n";break;
			case 5: cout<<precursor(root,x)<<"\n";break;
			case 6: cout<<successor(root,x)<<"\n";break; 
		}
	}
	return 0;
}
