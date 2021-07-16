//
// Created by 123 on 2021/7/9.
//
#pragma once

#include "global_ver.h"

/*****************new version*******************/

void background_block_renderer(block b)
{
    for(int y = 0; y <= screen_h/block_size_bk; y++){
        for(int x = 0; x <= screen_w/block_size_bk; x++){
            putimage(x*block_size_bk,y*block_size_bk,block_size_bk,block_size_bk,b.pimage,0,0,getwidth(b.pimage), getheight(b.pimage));
        }
    }
}

void gaming_map_renderer(int (*gaming_map)[map_size_h], block *b[], int xpos, int ypos, int w, int h, int block_size)
{
    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            putimage((x+xpos)*block_size,(y+ypos)*block_size,block_size,block_size,b[gaming_map[y][x]]->pimage,0,0,getwidth(b[gaming_map[y][x]]->pimage), getheight(b[gaming_map[y][x]]->pimage));
            if(debug){
                setfontbkcolor(EGERGBA(0,0,0,255));
                xyprintf((x+xpos)*block_size,(y+ypos)*block_size,"%d,%d",x,y);
                //xyprintf(x*block_size,y*block_size+20,"Y:%d",y);
                xyprintf((x+xpos)*block_size,(y+ypos)*block_size+20,"id:%d",gamemap1[y][x]);
            }
        }
    }
}

void tank_renderer(Tank *t, int xpos, int ypos, int block_size)
{
    vec2_f v = t -> pos;
    PIMAGE a = pg[gif];
    //resize(a, block_size, block_size);
    //putimage(a, 0, 0, block_size, block_size, pg[gif], 0, 0, getwidth(pg[gif]), getheight(pg[gif]));
    if(time_gif > t -> speed * 10){
        gif++;
        time_gif = 0;
        //printf("change\n");
    }
    time_gif++;
    if(gif >= 7) gif = 0;
    //putimage_withalpha(NULL, a, (int)((v.x+xpos)*block_size), (int)((v.y+ypos)*block_size), block_size, block_size, 0, 0, getwidth(a), getheight(a));
    //putimage_rotatezoom(NULL, a, (int)((v.x+xpos)*block_size), (int)((v.y+ypos)*block_size), 1.0, 0.0, PI * 180 / 180, (float)block_size/getheight(a), 1, -1, 1);
    if(t -> o == forward){
        putimage_rotatezoom(NULL, a, (int)((v.x+xpos)*block_size), (int)((v.y+ypos)*block_size), 0.0, 0.0, PI * 0 / 180, (float)block_size/getheight(a), 1, -1, 1);
    }
    if(t -> o == backward){
        putimage_rotatezoom(NULL, a, (int)((v.x+xpos)*block_size), (int)((v.y+ypos)*block_size), 1.0, 1.0, PI * 180 / 180, (float)block_size/getheight(a), 1, -1, 1);
    }
    if(t -> o == left){
        putimage_rotatezoom(NULL, a, (int)((v.x+xpos)*block_size), (int)((v.y+ypos)*block_size), 1.0, 0.0, PI * 90 / 180, (float)block_size/getheight(a), 1, -1, 1);
    }
    if(t -> o == right){
        putimage_rotatezoom(NULL, a, (int)((v.x+xpos)*block_size), (int)((v.y+ypos)*block_size), 0.0, 1.0, PI * 270 / 180, (float)block_size/getheight(a), 1, -1, 1);
    }
    //putimage_withalpha(NULL, a, (int)((v.x+xpos)*block_size), (int)((v.y+ypos)*block_size), getwidth(a), getheight(a), 0, 0, getwidth(a), getheight(a));
    //printf("%d,%d\n", getwidth(a), getheight(a));
    if(debug)
        xyprintf(10,10,"X: %f, Y: %f",v.x, v.y);
}

void ai_tank_renderer(Tank *t[], int num, int xpos, int ypos, int block_size)
{
    for(int i = 0; i < num; i++){
        vec2_f v = t[i] -> pos;
        PIMAGE a = t[i] -> pimage;
        if(t[i] -> life > 0){
            if(t[i] -> o == forward){
                putimage_rotatezoom(NULL, a, (int)((v.x+xpos)*block_size), (int)((v.y+ypos)*block_size), 0.0, 0.0, PI * 0 / 180, (float)block_size/getheight(a), 1, -1, 1);
            }
            if(t[i] -> o == backward){
                putimage_rotatezoom(NULL, a, (int)((v.x+xpos)*block_size), (int)((v.y+ypos)*block_size), 1.0, 1.0, PI * 180 / 180, (float)block_size/getheight(a), 1, -1, 1);
            }
            if(t[i] -> o == left){
                putimage_rotatezoom(NULL, a, (int)((v.x+xpos)*block_size), (int)((v.y+ypos)*block_size), 1.0, 0.0, PI * 90 / 180, (float)block_size/getheight(a), 1, -1, 1);
            }
            if(t[i] -> o == right){
                putimage_rotatezoom(NULL, a, (int)((v.x+xpos)*block_size), (int)((v.y+ypos)*block_size), 0.0, 1.0, PI * 270 / 180, (float)block_size/getheight(a), 1, -1, 1);
            }
        }
            //putimage_withalpha(NULL, a, (int)((v.x+xpos)*block_size), (int)((v.y+ypos)*block_size), block_size, (int)(block_size/((float)getwidth(a)/getheight(a))), 0, 0, getwidth(a), getheight(a));
        if(debug)
            xyprintf(10,10,"X: %f, Y: %f",v.x, v.y);
    }
}

void bullet_renderer(bullet *bu[], int num, int xpos, int ypos, int block_size)
{
    for(int i = 0; i < num; i++){
        int size = (int)(1/(bu[i]->collision_size.b - bu[i]->collision_size.a));
        if(bu[i]->display)
            putimage_withalpha(NULL, bu[i]->pimage, (int)((bu[i]->pos.x+xpos+0.5)*block_size-block_size/(size*2)), (int)((bu[i]->pos.y+ypos+0.5)*block_size-block_size/(size*2)), block_size/size, (int)(block_size/((float)getwidth(bu[i]->pimage)/getheight(bu[i]->pimage)))/size, 0, 0, getwidth(bu[i]->pimage), getheight(bu[i]->pimage));
    }
}
/******************* end *********************/