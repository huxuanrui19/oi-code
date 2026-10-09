//Ìæ×ïÑòÊ÷(Scapegoat Tree)ÊµÏÖ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
const double alpha=0.75;
struct node{
	int ls,rs;
	int val;
	int tot,size;
	int del;
}t[N];
int order[N],cnt;
int tree_stack[N],top=0;
int root=0;
void inorder(int u){
	if(!u) return;
	inorder(t[u].ls);
	if(t[u].del) order[++cnt]=u;
	else tree_stack[++top]=u;
	inorder(t[u].rs);
}
void initnode(int u){
	t[u].ls=t[u].rs=0;
	t[u].size=t[u].tot=t[u].del=1;
}
void update(int u){
	t[u].size=t[t[u].ls].size+t[t[u].rs].size+1;
	t[u].tot=t[t[u].ls].tot+t[t[u].rs].tot+1;
}
//int rebuild_num=0;
void build(int l,int r,int &u){
	//rebuild_num++;
	int mid=(l+r)>>1;
	u=order[mid];
	if(l==r){initnode(u);return;}
	if(l<mid) build(l,mid-1,t[u].ls);
	if(l==mid) t[u].ls=0;
	build(mid+1,r,t[u].rs);
	update(u);
}
void rebuild(int &u){
	cnt=0;
	inorder(u);
	if(cnt) build(1,cnt,u);
	else u=0;
}
bool notbalance(int u){
	if((double)t[u].size*alpha<=(double)max(t[t[u].ls].size,t[t[u].rs].size)) return true;
	else return false;
}
void insert(int &u,int x){
	if(!u){
		u=tree_stack[top--];
		t[u].val=x;
		initnode(u);
		return;
	}
	t[u].size++;
	t[u].tot++;
	if(t[u].val>=x) insert(t[u].ls,x);
	else insert(t[u].rs,x);
	if(notbalance(u)) rebuild(u);
}
int Rank(int u,int x){
	if(u==0) return 0;
	if(x>t[u].val) return t[t[u].ls].size+t[u].del+Rank(t[u].rs,x);
	else return Rank(t[u].ls,x);
}
int kth(int k){
	int u=root;
	while(u){
		if(t[u].del&&t[t[u].ls].size+1==k) return t[u].val;
		else if(t[t[u].ls].size>=k) u=t[u].ls;
		else{
			k-=t[t[u].ls].size+t[u].del;
			u=t[u].rs;
		}
	}
	return t[u].val;
}
void del_k(int &u,int k){
	t[u].size--;
	if(t[u].del&&t[t[u].ls].size+1==k){
		t[u].del=0;
		return;
	}
	if(t[t[u].ls].size+t[u].del>=k) del_k(t[u].ls,k);
	else del_k(t[u].rs,k-t[t[u].ls].size-t[u].del);
}
void del(int x){
	del_k(root,Rank(root,x)+1);
	if(t[root].tot*alpha>=t[root].size) rebuild(root);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=N-1;i>=1;i--) tree_stack[++top]=i;
	int q;cin>>q;
	while(q--){
		int opt,x;
		cin>>opt>>x;
		switch(opt){
			case 1: insert(root,x);break;
			case 2: del(x);break;
			case 3: cout<<(Rank(root,x)+1)<<"\n";break;
			case 4: cout<<kth(x)<<"\n";break;
			case 5: cout<<kth(Rank(root,x))<<"\n";break;
			case 6: cout<<kth(Rank(root,x+1)+1)<<"\n";break;
		}
	}
	return 0;
}

