#include<cstdio>

int main(){
double ar[1001] {0};
for(int i = 0;i <2 ;++i){
    int k = 0;
    scanf("%d",&k);
    for(int j = 0;j < k;++j){
        int a = 0;
        double b = 0;
        scanf("%d%lf",&a,&b);
        ar[a]+=b;     
    }
}
int count = 0;
for(int i = 0;i<1001;i++){
    if (ar[i]!=0)
    {
        count++;
    }
}
printf("%d",count);
for(int i = 1000;i>=0;--i){
    if (ar[i]!=0)
    {
    // cout<<" "<<i<<" "<<ar[i];
     printf(" %d %.1lf",i,ar[i]);   
    }
}
}