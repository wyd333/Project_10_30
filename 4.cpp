#include<bits/stdc++.h>

#define pb push_back
#define PI pair<int,int>
#define lson l,m,rt<<1,ls,rs
#define rson m+1,r,rt<<1|1,ls,rs
#define test printf("here!!!\n")
#define INF 0x3f3f3f3f;
#define fi first
#define se second
#define MP make_pair
#define ll long long
using namespace std;

const int gadless=6e5+10;
int n,m,altertttt;

char s[gadless];

int sa[gadless],tp[gadless],rk[gadless],rdx[gadless],height[gadless];

//带排序的字符串转换为int类型存储在r数组中，从r [ 0 ] r[0]r[0]到r [ n − 1 ] r[n-1]r[n−1]，长度为n，且范围在0和m之间。为了操作方便，规定除r [ n − 1 ] r[n-1]r[n−1]外所有r [ i ] r[i]r[i]都大于0，r [ n − 1 ] = 0 r[n-1]=0r[n−1]=0。s a sasa数组从s a [ 0 ] sa[0]sa[0]到s a [ n − 1 ] sa[n-1]sa[n−1]。

void getsa() {
	for (int i=0; i<=m; ++i) rdx[i]=0;
	for (int i=1; i<=n; ++i) ++rdx[rk[i]];
	for (int i=1; i<=m; ++i) rdx[i]+=rdx[i-1];
	for (int i=n; i>=1; --i) sa[rdx[rk[tp[i]]]--]=tp[i];
}
void SAAAA() {
	m=(int)'z';
	for (int i=1; i<=n; ++i) rk[i]=(int)s[i],tp[i]=i;
	getsa();
	for (int w=1,p=0; p<n; m=p,w<<=1) {
		p=0;
		for (int i=n-w+1; i<=n; ++i) tp[++p]=i;
		for (int i=1; i<=n; ++i) {
			if (sa[i]>w) tp[++p]=sa[i]-w;
	}
		getsa();
		swap(tp,rk);
		rk[sa[1]]=p=1;
		for (int i=2; i<=n; ++i)
			rk[sa[i]]=(tp[sa[i-1]]==tp[sa[i]]&&((sa[i-1]+w>n&&sa[i]+w>n)||(sa[i-1]+w<=n&&sa[i]+w<=n&&tp[sa[i-1]+w]==tp[sa[i]+w])))?p:++p;
	}

}
void getheight() {
	int k=0;

	for (int i=1; i<=n; ++i) {
		if (rk[i]==1) continue;
		if (k) --k;
		int j=sa[rk[i]-1];
		while (i+k<=n&&j+k<=n&&s[i+k]==s[j+k]) ++k;
		height[rk[i]]=k;
	}

}
int main() {
	scanf("%s",s+1);
	int l=strlen(s+1);
	for(int i=1; i<=l; i++) {
		s[i+l]=s[i];
	}
	n=strlen(s+1);
	int altertttt1=1,altertttt=l+1;
	SAAAA();
	getheight();
	ll ans1=0,ans=0;
	for (int i=1; i<=n; ++i) {
		ans1+=(n-sa[i]+1)-min(max(altertttt-1,height[i]),n-sa[i]+1);
	}
	for (int i=1; i<=n; ++i) {
		ans+=(n-sa[i]+1)-min(max(altertttt1-1,height[i]),n-sa[i]+1);
	}
	printf("%lld\n",ans-ans1);
}
