#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<cmath>
#include<cctype>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<sstream>
#include<ctime>
#include<cstdlib>
#include<unordered_map>
#define L ch[x][0]
#define R ch[x][1]
#define KT (ch[ ch[rt][1] ][0])
#define ll long long
using namespace std;
const int inf  = ~0u>>2;

/*
	#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<cmath>
#include<cctype>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<sstream>
#include<ctime>
#include<cstdlib>
#include<unordered_map>
#define L ch[x][0]
#define R ch[x][1]
#define KT (ch[ ch[rt][1] ][0])
#define ll long long
using namespace std;
const int inf  = ~0u>>2;
*/

const int maxn = 50010;
int lim;
struct SplayTree {
    int PG[maxn];
    int ch[maxn][2];
    int pre[maxn];
    int rt,top;
    inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	
	/*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*/
	
    inline void Rotate(int x,int f){
        int y=pre[x];
        ch[y][!f] = ch[x][f];
        pre[ ch[x][f] ] = y;
        pre[x] = pre[y];
        if(pre[x]) ch[ pre[y] ][ ch[pre[y]][1] == y ] =x;
        ch[x][f] = y;
        pre[y] = x;
        up(y);
    }
	/*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*/
    inline void Splay(int x,int goal){//??xDy¡Áa¦Ì?goal¦Ì?????
        while(pre[x] != goal){
            if(pre[pre[x]] == goal) Rotate(x , ch[pre[x]][0] == x);
            else   {
                int y=pre[x],z=pre[y];
                int f = (ch[z][0]==y);
                if(ch[y][f] == x) Rotate(x,!f),Rotate(x,f);
                else Rotate(y,f),Rotate(x,f);
            }
        }
		/*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*/
        up(x);
        if(goal==0) rt=x;
    }
    inline void RTO(int k,int goal){//??¦Ì¨²k??¨ºyDy¡Áa¦Ì?goal¦Ì?????
        int x=rt;
        while(PG[ L ] != k-1) {
            if(k < PG[ L ]+1) x=L;
            else {
                k-=(PG[ L ]+1);
                x = R;
            }
        }
		/*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*/
        Splay(x,goal);
    }
    inline void vist(int x){
        if(x){
            printf("?¨¢¦Ì?%2d : ¡Á¨®?¨´¡Á¨®  %2d   ¨®¨°?¨´¡Á¨®  %2d   val:%2d PG=%d  cnt:%d\n",x,L,R,val[x],PG[x],cnt[x]);
            vist(L);
            vist(R);
        }
    }
    void debug() {
        puts("");
        vist(rt);
        puts("");
    }
    inline void Newnode(int &x,int c,int f){
        x=++top;
        L = R = 0;
        pre[x] = f;
        PG[x]=1; cnt[x]=1;
        val[x] = c;
    }
    inline void init(){
        ch[0][0]=ch[0][1]=pre[0]=PG[0]=0;
        rt=top=0; cnt[0]=0;
    }
    inline void Insert(int &x,int key,int f){
        if(!x) {
            Newnode(x,key,f);
            Splay(x,0);//¡Á¡é¨°a2?¨¨?¨ª¨º3¨¦o¨®splay
            return ;
        }
		/*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*/
        if(key==val[x]){
            cnt[x]++;
            PG[x]++;
            Splay(x,0);//¡Á¡é¨°a2?¨¨?¨ª¨º3¨¦o¨®splay
            return ;
        }else if(key<val[x]) {
            Insert(L,key,x);
        } else {
            Insert(R,key,x);
        }
        up(x);
    }
    void Del_root(){//¨¦?3y?¨´?¨²¦Ì?
        int t=rt;
        if(ch[rt][1]) {
            rt=ch[rt][1];
            RTO(1,0);
            ch[rt][0]=ch[t][0];
            if(ch[rt][0]) pre[ch[rt][0]]=rt;
        }
		/*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*/
        else rt=ch[rt][0];
        pre[rt]=0;
        up(rt);
    }
	/*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*/
    void findpre(int x,int key,int &ans){//?¨°?¡ã?y?¨²¦Ì?
        if(!x)  return ;
        if(val[x] <= key){
            ans=x;
            findpre(R,key,ans);
        } else
            findpre(L,key,ans);
    }
    void findsucc(int x,int key,int &ans){//?¨°o¨®?¨¬?¨²¦Ì?
        if(!x) return ;
        if(val[x]>=key) {
            ans=x;
            findsucc(L,key,ans);
        } else
            findsucc(R,key,ans);
    }
	/*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*/
    inline int find_kth(int x,int k){ //¦Ì¨²kD?¦Ì?¨ºy
        if(k<PG[L]+1) {
			/*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*/
            return find_kth(L,k);
        }else if(k > PG[ L ] + cnt[x] )
            return find_kth(R,k-PG[L]-cnt[x]);
        else{
            Splay(x,0);
            return val[x];
        }
    }
    int find(int x,int key){
        if(!x) return 0;
		/*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*/
        else if(key < val[x])  return find(L,key);
        else if(key > val[x])  return find(R,key);
        else return x;
    }
    int getmin(int x){
        while(L) x=L;    return val[x];
    }
    int getmax(int x){
        while(R) x=R;   return val[x];
    }
    //¨¨¡¤?¡§key¦Ì?????
    int getrank(int x,int key,int cur){//cur:¦Ì¡À?¡ã¨°??a¡À¨¨¨°a?¨®?a??¡ê¡§key¡ê?D?¦Ì?¨ºy¦Ì???¨ºy
        if(key == val[x])
            return PG[L] + cur + 1;
        else if(key < val[x])
            getrank(L,key,cur);
        else
			/*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*/
            getrank(R,key,cur+PG[L]+cnt[rt]);
    }
    int get_lt(int x,int key){//D?¨®¨²key¦Ì?¨ºy¦Ì???¨ºy lt:less than
        if(!x) return 0;
        if(val[x]>=key) return get_lt(L,key);
        return cnt[x]+PG[L]+get_lt(R,key);
    }
    int get_mt(int x,int key){//¡ä¨®¨®¨²key¦Ì?¨ºy¦Ì???¨ºy mt:more than
        if(!x) return 0;
        if(val[x]<=key) return get_mt(R,key) ;
        return cnt[x]+PG[R]+get_mt(L,key);
    }
    void del(int &x,int f){//¨¦?3yD?¨®¨²lim¦Ì??¨´¨®D¦Ì?¨ºy?¨´?¨²¦Ì??¨²¦Ì?
        if(!x) return ;
        if(val[x]>=lim){
            del(L,x);
        } else {
            x=R;
            pre[x]=f;
            if(f==0)  rt=x;
            del(x,f);
        }
        if(x)  up(x);
    }
    inline void update(){
        del(rt,0);
    }
    int get_mt(int key) {
        return get_mt(rt,key);
    }
    int get_lt(int key) {
        return get_lt(rt,key);
    }
	/*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*/
    void insert(int key) {
        Insert(rt,key,0);
    }
    void Delete(int key) {
        int node=find(rt,key);
        Splay(node,0);
        cnt[rt]--;
        if(!cnt[rt])Del_root();
    }
	/*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*/
    int kth(int k) {
        return find_kth(rt,k);
    }
    int cnt[maxn];
    int val[maxn];
    int lim;
}spt;
int root=0;


/*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*//*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*//*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*//*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*//*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*//*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*/
const int M=1820;

const int N = 1000010;
long long n,a[N],cnt,pri[N],mu[N],res;
bool vis[N];
const int mod = 998244353;
void solve(int n)
{
    int res = 0;
    for(int i = 1;i <= n;i++)
        for(int j = i;j <= n;j++)
            for(int k = j;k <= n;k++)
            {
                if(j%i || k%j) continue;
                if(__gcd(j/i,k/j) == 1) res++;
            }
	/*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*/
    cout<<res<<endl;
}


void solve() {
    scanf("%lld",&n);
    mu[1]=1;
    for(int i = 2;i < N;++i){
        if(!pri[i]) pri[++cnt] = i,mu[i] = -1;
        for(int j = 1;j <= cnt && i*pri[j] < N;++j)
        {
            pri[i*pri[j]] = 1;
            if(i%pri[j] == 0)
            {
                mu[i*pri[j]] = 0;
                break;
            }
            else mu[i*pri[j]] = -mu[i];
        }
    }
    
    ll res=0;
    for(ll l = 1;l*l <= n;++l)
    {
        ll r = n/l/l,tmp = 0;
        for(ll x = 1;x*x*x <= r;++x)
         for(ll y = x;y*y <= r/x;++y)
         {
             ll z = r/x/y-y;
             if(x != y) tmp = (tmp+3+z*6) %mod;
             else tmp = (tmp+1+z*3) %mod;
        }
        res = (res+mu[l]*tmp)%mod;
    }
    
    cout<<res<<endl;
  
}

signed main() {

    for(int i=1;i<=100;i++) {
        spt.Insert(root,i,0);
    }
    spt.del(root,20);
    spt.del(root,40);

    solve();

    spt.del(root,22);
    spt.del(root,60);
    spt.del(root,89);
	/*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*//*
		inline void up(int x){
        PG[x]  = cnt[x]  + PG[ L ] + PG[ R ];
    }
	*/
    return 0;
}
