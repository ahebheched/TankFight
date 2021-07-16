#ifndef _dfs_H
#define _dfs_H

#include<stdio.h>
#include<stdbool.h>

//bugfix
#include "block.h"
#include "datas.h"

int move[4][2]={1,0,0,1,-1,0,0,-1},dp[18][18];//dp是从{x,y}到pos1的最小代价
int x[18][18],y[18][18];//x,y分别记录从{x,y}到pos2的最佳路径的下一步
void dfs2(int (*map)[18],vec2 pos1,vec2 pos2)
{
//	printf("%d %d\n",pos1.x,pos1.y);
    int i,cost;
    if(pos1.x==pos2.x&&pos1.y==pos2.y)return ;
    for(i=0;i<4;i++)
    {
        if(pos1.x+move[i][0]>=0&&pos1.x+move[i][0]<18)
            if(pos1.y+move[i][1]>=0&&pos1.y+move[i][1]<18)
            {
                //	printf("  %d %d %d\n",map[choice][pos1.x+move[i][0]][pos1.y+move[i][1]],pos1.x+move[i][0],pos1.y+move[i][1]);
                if(map[pos1.x+move[i][0]][pos1.y+move[i][1]]==0)
                    cost=0;
                else
                    cost=1;
                if(dp[pos1.x+move[i][0]][pos1.y+move[i][1]]>dp[pos1.x][pos1.y]+cost)
                {
                    dp[pos1.x+move[i][0]][pos1.y+move[i][1]]=dp[pos1.x][pos1.y]+cost;
                    x[pos1.x][pos1.y]=pos1.x+move[i][0];
                    y[pos1.x][pos1.y]=pos1.y+move[i][1];
                    vec2 hh;
                    hh.x=pos1.x+move[i][0];
                    hh.y=pos1.y+move[i][1];
                    dfs2(map,hh,pos2);
                }
            }
    }
}

void dfs(int (*map)[18],vec2 pos1,vec2 pos2,vec2 ans[])
{
    int i,j;
    for(i=0;i<18;i++)
        for(j=0;j<18;j++)
        {
            dp[i][j]=0x3f3f3f3f;
        }
    dp[pos1.x][pos1.y]=0;
    dfs2(map,pos1,pos2);
    ans[0].x=x[pos1.x][pos1.y];
    ans[0].y=y[pos1.x][pos1.y];
    for(i=1;i<5;i++)
    {
        ans[i].x=x[ans[i-1].x][ans[i-1].y];
        ans[i].y=y[ans[i-1].x][ans[i-1].y];
    }
}

#endif
