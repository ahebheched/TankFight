//
// Created by 123 on 2021/7/14.
//
#pragma once

#include "global_ver.h"

void gaming_loop(block *b[], Tank *player, Tank *ai[], bullet *bu[], bullet *buai[][15], int *bu_id, int *time, int *blockid, int *time2){
    for(;is_run(); delay_fps(60)){
        //delay(1000);
        cleardevice();
        setbkcolor(EGERGB(28,28,28));
        Gaming_screen(true, gamemap2, b, player, ai, bu, buai, bu_id, time, time2);
        if(debug)
            xyprintf(10,80,"FPS : %f", getfps());
        Map_making_screen(true, b, 7, 0, blockid);
        if(debug)
            for(int i = 0; i < 10; i++){
                xyprintf(10,100 + 20 * i,"ai[%d] : x : %f, y : %f", i, ai[i]->pos.x, ai[i]->pos.y);
            }
        Main_screen(true);
        New_world_screen(true);
    }
}

int win_lose_check(){
    if(player -> life <= 0){
        return -1;
    }
    int a = 0;
    for(auto i : ai){
        if(i->life>0){
            a++;
        }
    }
    if(a == 0)
        return 1;
    return 0;
}