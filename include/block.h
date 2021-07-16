//
// Created by Harley on 2021/7/14.
//
#pragma once

#include <cstdio>

#include "graphics.h"

#include "global_ver.h"

void block_init(block *b[], PIMAGE pimage[], int num)
{
    char resource[1000];
    for(int i = 0; i < num; i++){
        pimage[i] = newimage();
        sprintf(resource,R"(.\assets\map\blocks\%c%c.png)",i/10+'0',i%10+'0');
        int state = getimage_pngfile(pimage[i],resource);
        b[i] = (block *)malloc(sizeof(block));
        b[i]->id = i;
        b[i]->durable = 1;
        b[i]->player_spownpoint = 0;
        b[i]->ai_spownpoint = 0;
        b[i]->pimage = pimage[i];

        if(log){
            if(state == 0){
                HANDLE hOut;
                hOut = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hOut,FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                printf("_____log_____:load block resource \"%s\" success.\n",resource);
            }
            else{
                HANDLE hOut;
                hOut = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hOut,FOREGROUND_RED | FOREGROUND_INTENSITY);
                printf("_____log_____:load block resource \"%s\" failure.\n",resource);
            }
        }
    }
}
