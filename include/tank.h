//
// Created by Harley on 2021/7/8.
//
#pragma once

#include "global_ver.h"

Tank * new_tank(int life, int blood, int agg, int effect, vec2 spawnpoint, PIMAGE a)
{
    Tank *t;
    t = (Tank *)malloc(sizeof(Tank));
    t -> life = life;
    t -> blood = blood;
    t -> agg = agg;
    t -> fight_speed = 30;
    t -> effect = effect;
    t -> speed = 1;
    t -> spawnpoint = spawnpoint;
    t -> pos.x = (float)spawnpoint.x;
    t -> pos.y = (float)spawnpoint.y;
    t -> pimage = a;
    t -> collision_size = {0.2, 0.8};
    t -> o = forward;
    return t;
}

void ai_tank_init(Tank *t[], PIMAGE pimage, int num)
{
    pimage = newimage();
    getimage_pngfile(pimage,R"(.\assets\tank\player\9.png)");
    for(int i = 0; i < num; i++){
        srand((unsigned)time(0));
        t[i] = new_tank(2, 3, 1, -1, {0,0}, pimage);
        t[i] -> speed = (rand()%100)/80.0+1;
        t[i] -> collision_size = {0.1, 0.9};
    }
}

void tank_move(Tank *t, vec2_f pos)
{
    t -> pos.x = pos.x;
    t -> pos.y = pos.y;
}

vec4 block_check(Tank *t, int (*map)[map_size_h])
{
    vec4 v = {1,1,1,1};
    float point_x[2] = {
            (t->pos.x + t->collision_size.a),
            (t->pos.x + t->collision_size.b)
    };
    float point_y[2] = {
            (t->pos.y + t->collision_size.a),
            (t->pos.y + t->collision_size.b)
    };
    //if(debug || log)
        //printf("_____log_____true player pos: X : %d - %d, Y : %d - %d\n",x,x_,y,y_);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            float x = point_x[i];
            float y = point_y[j];
            if(map[(int)y][(int)(x+0.1*(t->speed))] != 0 || x+0.1*(t->speed) > map_size_h) v.r = 0;
            if(map[(int)y][(int)(x-0.1*(t->speed))] != 0 || x-0.1*(t->speed) < 0) v.l = 0;
            if(map[(int)(y+0.1*(t->speed))][(int)x] != 0 || y+0.1*(t->speed) > map_size_h ) v.d = 0;
            if(map[(int)(y-0.1*(t->speed))][(int)x] != 0 || y-0.1*(t->speed) < 0) v.u = 0;
        }
    }
    return v;
}

int a[10],b[10],c[10],d[10];
void ai_tank_move(Tank *t[],int num, int (*map)[map_size_h],int *time)
{
    for(int i = 0; i < num; i++){
        if(*time >= 30){
            for(int i = 0; i < num; i++){
                a[i] = (rand()%100 > 49), b[i] = !a[i], c[i] = (rand()%100 > 49), d[i] = !c[i];
                if(a[i]){
                    a[i] = (rand()%100 > 49);
                }
                if(b[i]){
                    b[i] = (rand()%100 > 49);
                }
                if(c[i]){
                    c[i] = (rand()%100 > 49);
                }
                if(d[i]){
                    d[i] = (rand()%100 > 49);
                }
                //printf("i:%d,%d,%d,%d,%d\n",i,a[i],b[i],c[i],d[i]);
            }
            (*time) = 0;
        }
        if(t[i] -> life > 0){
            if(block_check(t[i],map).r && a[i]){
                t[i] -> pos.x = t[i] -> pos.x + 0.1*(t[i] -> speed);
                t[i] -> o = right;
                //printf("_________right,i:%d,%d,%d,%d,%d\n",i,a[i],b[i],c[i],d[i]);

            }

            if(block_check(t[i],map).l && b[i]){
                t[i] -> pos.x = t[i] -> pos.x - 0.1*(t[i] -> speed);
                t[i] -> o = left;
                //printf("_________right,i:%d,%d,%d,%d,%d\n",i,a[i],b[i],c[i],d[i]);
            }

            if(block_check(t[i],map).d && c[i]){
                t[i] -> pos.y = t[i] -> pos.y + 0.1*(t[i] -> speed);
                t[i] -> o = backward;
            }
            if(block_check(t[i],map).u && d[i]){
                t[i] -> pos.y = t[i] -> pos.y - 0.1*(t[i] -> speed);
                t[i] -> o = forward;
            }
        }
        else{
            //t[i] -> pos = {-1.0, -1.0};
        }

        //t[i] -> pos.y = t[i] -> pos.y + (rand()%10)/10.0;;
    }
    (*time)++;
}

void tank_move_key(Tank *t, int (*map)[map_size_h])
{
    if(keystate('W')){
        if(block_check(t,map).u){
            t->pos.y-=0.1*(t->speed);
            if(log)
                printf("_____log_____:player move tank to X : %f, Y : %f\n",t->pos.x, t->pos.y);
        }
        t->o = forward;
        if(log)
            printf("_____log_____:player press W\n");
    }
    if(keystate('S')){
        if(block_check(t,map).d){
            t->pos.y+=0.1*(t->speed);
            if(log)
                printf("_____log_____:player move tank to X : %f, Y : %f\n",t->pos.x, t->pos.y);
        }
        t->o = backward;
        if(log)
            printf("_____log_____:player press S\n");
    }
    if(keystate('A')){
        if(block_check(t,map).l) {
            t->pos.x -= 0.1 * (t->speed);
            if(log)
                printf("_____log_____:player move tank to X : %f, Y : %f\n",t->pos.x, t->pos.y);
        }
        t->o = left;
        if(log)
            printf("_____log_____:player press A\n");
    }
    if(keystate('D')){
        if(block_check(t,map).r){
            t->pos.x+=0.1*(t->speed);
            if(log)
                printf("_____log_____:player move tank to X : %f, Y : %f\n",t->pos.x, t->pos.y);
        }
        t->o = right;
        if(log)
            printf("_____log_____:player press D\n");
    }
}
