#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
#define min(a,b) a<b?a:b
#define max(a,b) (a>b?a:b)
#define sc(c) scanf("%d",&c)
#define st(c,d) ("%d %d",&c,&d)
#define MAX 500000
typedef long long int ll;
inline int max3(int a, int b, int c) {
return max(a, max(b, c));
}
struct node {
    int left,right,full,maxx;
}tree[MAX];
int arr[MAX],m,n,ii,jj;
node combine(node ,node);
void build(int n,int s,int e) {
    if(s==e) {
        tree[n].left=arr[s];
        tree[n].right=arr[s];
        tree[n].full=arr[s];
        tree[n].maxx=arr[s];
        return ;
    }
    int child,mid;
    mid=(s+e)/2;
    child=n*2;
    build(child,s,mid);
    build(child+1,mid+1,e);
    tree[n]=combine(tree[child],tree[child+1]);
}
node combine(node a,node b) {
    node tmp;
    tmp.left=max(a.left,a.full+b.left);
    tmp.right=max(b.full+a.right,b.right);
    tmp.full=a.full+b.full;
    tmp.maxx=max3(a.maxx,b.maxx,a.right+b.left);
    return tmp;
}
node query(int n,int s,int e,int i,int j) {
    if(i<=s&&j>=e) return tree[n];
    int child=n*2;
    int mid=(s+e)/2;
    if(j<=mid) return query(child,s,mid,i,j);
    if(i>mid) return query(child+1,mid+1,e,i,j);
    node p,q;
    p=query(child,s,mid,i,j);
    q=query(child+1,mid+1,e,i,j);
    node tmp;
    tmp.left=max(p.left,p.full+q.left);
    tmp.right=max(q.full+p.right,q.right);
    tmp.full=q.full+p.full;
    tmp.maxx=max3(p.maxx,q.maxx,p.right+q.left);
    return tmp;
}
int main () {
	sc(n);
	for(int i=1;i<=n;i++) sc(arr[i]);
	build(1,1,n);
	sc(m);
	for(int i=1;i<=m;i++) {
        sc(ii);sc(jj);
        node tmp;
        tmp=query(1,1,n,ii,jj);
        printf("%d\n",tmp.maxx);
	}
return 0;
}
