//
// Created by 123 on 2021/7/9.
//
#pragma once

#include "global_ver.h"

typedef struct {
    int block_id;
    int tank_id;
    int spownpoint;

}map;

int save_map(int (*map)[18], int map_id){
    char dir[1000];
    sprintf(dir,".\\map\\%d.map",map_id);
    FILE *fp = fopen(dir, "w");
    if(fp == NULL) return -1;
    for(int y = 0; y < 18; y++){
        for(int x = 0; x < 18; x++){
            fprintf(fp,"%d ",map[y][x]);
        }
    }
    fclose(fp);
    return 0;
}

int load_map(int (*map)[18], int map_id){
    char dir[1000];
    sprintf(dir,".\\map\\%d.map",map_id);
    int a;
    FILE *fp = fopen(dir, "r");
    if(fp == NULL) return -1;
    for(int y = 0; y < 18; y++){
        for(int x = 0; x < 18; x++){
            fscanf(fp,"%d",&a);
            map[y][x] = a;
            if(a == 4){
                map[y][x] = 0;
                player -> life = 2;
                player -> spawnpoint.x = x;
                player -> spawnpoint.y = y;
                player -> pos = {(float)x,(float)y};
            }
            if(a == 8){
                map[y][x] = 0;
                for(auto & i : ai){
                    i -> life = 2;
                    i -> spawnpoint = {x,y};
                    i -> pos = {(float)x,(float)y};
                }
            }
        }
    }
    fclose(fp);
    return 0;
}

int tank_in_map[18][18]={
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};
