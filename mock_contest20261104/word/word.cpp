#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+10,M=4e6;
const ll inf=1e18,mod=1e9+7;
int n,m;
struct node{
    int son[27];
    int num;
};
string s[N];
vector<node> trie;
void insert(string s){
    int p=0;
    for(int i=0;i<m;i++){
        int idx=(s[i]=='?')?26:(s[i]-'a');
        if(trie[p].son[idx]==0) trie[p].son[idx]=trie.size(),trie.push_back({});
        p=trie[p].son[idx];
    }
    trie[p].num++;
}
int query(int pos,int i,string s){
    if(i==m) return trie[pos].num;
    int idx=(s[i]=='?')?26:(s[i]-'a');
    int ans=0;
    if(trie[pos].son[idx]!=0) ans+=query(trie[pos].son[idx],i+1,s);
    if(s[i]=='?'){
        for(int idx=0;idx<=25;idx++){
            if(trie[pos].son[idx]!=0) ans+=query(trie[pos].son[idx],i+1,s);
        }
    }
    else{
        if(trie[pos].son[26]!=0) ans+=query(trie[pos].son[26],i+1,s);
    }
    return ans;
}
int main(){
    freopen("word.in","r",stdin);
    freopen("word.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    trie.resize(1);
    insert(s[1]);
    ll ans=0;
    for(int i=2;i<=n;i++){
        ans+=query(0,0,s[i]);
        insert(s[i]);
    }
    cout<<ans;
    return 0;
}