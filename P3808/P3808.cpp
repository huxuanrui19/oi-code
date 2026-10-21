#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
const ll inf=1e18,mod=1e9+7;
struct node{
    int son[N];
    int end,fail;
}tree[N];
string s[N];
string t;
int n,cnt=0;
void insert(string s){
    int p=0;
    for(int i=0;i<s.size();i++){
        int ch=s[i]-'a';
        if(tree[p].son[ch]==0) tree[p].son[ch]=++cnt;
        p=tree[p].son[ch];
    }
    tree[p].end++;
}
void getfail(){
    queue<int> q;
    for(int i=0;i<26;i++){
        if(tree[0].son[i]) q.push(tree[0].son[i]);
    }
    while(!q.empty()){
        int p=q.front();q.pop();
        for(int i=0;i<26;i++){
            if(tree[p].son[i]){
                tree[tree[p].son[i]].fail=tree[tree[p].fail].son[i];
                q.push(tree[p].son[i]);
            }
            else tree[p].son[i]=tree[tree[p].fail].son[i];
        }
    }
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) insert(s[i]);
    cin>>t;
    getfail();
    return 0;
}