#include<cstdio>
#include<algorithm>

#define INF 1000000000

using namespace std;

int G[510][510];//存储图
int weight[510];//点权
bool vis[510] = {false};


int num[510];//最短路径数量
int d[510];//记录最短距离
int w[510];//记录最大点权之和

int main(){

fill(G[0],G[0]+510*501,INF);//将边初始化最大(去掉所有边)
fill(d,d+510,INF);

fill(w,w+510,0);//将点权初始化为零
fill(num,num+510,0);//将最短路径数量初始化为零

int n,m,c1,c2;
scanf("%d%d%d%d",&n,&m,&c1,&c2);
for(int i = 0;i < n;i++){
    scanf("%d",&weight[i]);
}

for(int i = 0;i < m;i++){
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    G[x][y] = G[y][x] = z;
}

d[c1] = 0; //起点距离设为0
num[c1] = 1; //
w[c1] = weight[c1];

//遍历n次
for(int i = 0;i < n;i++){
    int u = -1;
    int MIN = INF;

//寻找未访问的顶点中的d[u]最小的
    for(int j = 0;j < n;j++){   
        if(vis[j] == false && d[j] <MIN){
            u = j;
            MIN = d[j];
        }
    }

//找不到小与INf的点，说明剩下的顶点和起点s不连通
    if(u == -1) return 0;

//记u已经访问
    vis[u] = true;

    // for(int v = 0; v < n;v++){
    //     if(!vis[v] && G[u][v] != INF && d[u] + G[u][v] < d[v]){
    //         d[v] = d[u] + G[u][v];
    //     }
    // }

    for(int v = 0;v < n;v++){
        //v点未访问&& u 和 v 点之间有路
        if(!vis[v] && G[u][v] != INF){
            if(d[u] + G[u][v] < d[v]){
                d[v] = d[u] + G[u][v];
                num[v] = num[u];
                w[v] = w[u] + weight[v];
            }else if(d[u] + G[u][v] == d[v]){
                num[v] = num[u] + num[v];
                if(w[v] < w[u] + weight[v]){
                    w[v] = w[u] + weight[v];
                }
            }
        }
    }
}
printf("%d %d",num[c2],w[c2]);
}