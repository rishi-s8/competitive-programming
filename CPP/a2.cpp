#include <iostream>
using namespace std;
#include <math.h>
#define val (pow(10,9)+7)
int res[100000];int ar[1001][3];void perform1(int b,int c){for(int j=b-1;j<c;++j)++(res[j]);}void perform2(int b,int c){for(int i=b-1;i<c;++i){if(ar[i][0]==1)perform1(ar[i][1],ar[i][2]);else perform2(ar[i][1],ar[i][2]);}}int main(){int T,n,m,a,b,c;scanf("%d",&T);while(T--){scanf("%d%d",&n,&m);for(int s=0;s<n;s++)res[s]=0;for(int i=0;i<m;++i){scanf("%d%d%d",&a,&b,&c);if(a==1){perform1(b,c);}else{perform2(b,c);}ar[i][0]=a;ar[i][1]=b;ar[i][2]=c;}int temp;for(int s=0;s<n;s++){temp=res[s]%(int)val;printf("%d ",temp);}printf("\n");}return 0;}
