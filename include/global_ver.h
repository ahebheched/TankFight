//
// Created by Harley on 2021/7/14.
//
#pragma once

/************* include ***********/

#include <windows.h>
#include <malloc.h>
#include <time.h>

#include "graphics.h"

/************** ver **************/
const int width = GetSystemMetrics(SM_CXSCREEN),height = GetSystemMetrics(SM_CYSCREEN);
const int screen_w = 1280, screen_h = 720;//渲染界面大小
const int map_size_w = 32;
const int map_size_h = 18;//地图大小，实际只与该变量有关，及map_size_h*map_size_h
const int block_size_ = 40;//地图方块大小
const int block_size_bk = 60;//构成背景方块大小
const int debug = 0, log = 0;//打开log及debug

int block_num = 10;
int buid = 0;
int time3[10];
int gif = 0, flag_gif = 0, time_gif = 0;

PIMAGE pg[7];
char dir[1000];

PIMAGE bk_1 = NULL;
PIMAGE bk_2 = NULL;
PIMAGE ui_1 = NULL;
PIMAGE ui_2 = NULL;

int mu = 0;//载入模板定义



int gamemap1[18][18]={
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

int gamemap2[18][18]={
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,
        0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,
        1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,
        1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,
        1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,
        1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,0,0,1,
        0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,
        0,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,0,
        0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,
        0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,0,
        0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,
        0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,0,
        0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,2,2,2,
        0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,2,0,0,
        0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,2,0,0
};

int game_map_[10][18][18];


/*
int bu_id = 0;
int time = 0;
int blockid = 1;
int time2 = 30;
*/
/*********** my struct ***********/
typedef struct
{
    int x,y;
}vec2;

typedef struct
{
    float x,y;
}vec2_f;

typedef struct{
    int u,d,l,r;
}vec4;

typedef struct{
    int hight;
    int weight;
}size;

enum orientation{
    forward, backward, left, right
};

typedef struct{
    int id;
    int durable;
    int player_spownpoint;
    int ai_spownpoint;
    PIMAGE pimage;
}block;

typedef struct {
    float a,b;
}collision;

typedef struct
{
    int life;
    int blood;//血量
    int agg;//攻击力
    int fight_speed;//攻速
    int effect;//状态
    float speed = 1;
    vec2 spawnpoint;
    vec2_f pos;
    enum orientation o = forward;//朝向
    collision collision_size;
    PIMAGE pimage;
    PIMAGE pg[];
}Tank;

typedef struct{
    Tank *target;
    float speed;
    int effect;
    collision collision_size;
    vec2_f pos = target->pos;
    orientation o;
    char image[1000];
    PIMAGE pimage;
    int display = 0;
    //enum orientation o;
} bullet;

enum screen{
    main_screen, new_world_screen, gaming_screen, pause_screen, map_making_screen
}screen_ = main_screen;


block *block_[10];
Tank *player;
Tank *ai[10];

/*********** 函数声明 ***********/

/*********** tank.h ***********/
Tank * new_tank(int life, int blood, int agg, int effect, vec2 spawnpoint, PIMAGE a);
void ai_tank_init(Tank *t[], PIMAGE pimage, int num);
void tank_move(Tank *t, vec2_f pos);
vec4 block_check(Tank *t, int (*map)[map_size_h]);
void ai_tank_move(Tank *t[],int num, int (*map)[map_size_h],int *time);
void tank_move_key(Tank *t, int (*map)[map_size_h]);

/*********** screen.h ***********/
void screen_init(int w, int h);
void Main_screen(bool render);
void New_world_screen(bool render);
void Gaming_screen(bool render, int (*gaming_map)[map_size_h], block *b[], Tank *player, Tank *ai[], bullet *bu[], bullet *aibu[][15], int *bullet_id, int *time, int *time2);
screen getScreen();
void mouse_init(int xpos, int ypos, int block_size, int *blockid);
void key_init(int *blockid);
void mini_gaming_map(int (*map)[map_size_h], block *b[], int xpos, int ypos, int block_size);
void Map_making_screen(bool render, block *b[], int xpos, int ypos, int *blockid);
void change_screen(screen s);

/*********** block.h ***********/
void block_init(block *b[], PIMAGE pimage[], int num);

/*********** renderer.h ***********/
void background_block_renderer(block b);
void gaming_map_renderer(int (*gaming_map)[map_size_h], block *b[], int xpos, int ypos, int w, int h, int block_size);
void tank_renderer(Tank *t, int xpos, int ypos, int block_size);
void ai_tank_renderer(Tank *t[], int num, int xpos, int ypos, int block_size);
void bullet_renderer(bullet *bu[], int num, int xpos, int ypos, int block_size);

/*********** bullet.h ***********/
bullet *new_bullet(Tank *t, float speed, int effect, PIMAGE a);
void bullet_damage(bullet *bu, Tank *t);
void bullet_init(Tank *t, bullet *bu[], int num, PIMAGE bullet_image);
void bullet_key(bullet *bu[], int num, Tank *player, int *bullet_id, int *time);
void bullet_ai(bullet *bu[][15], int num, Tank *player, int *bullet_id, int *time);
vec4 block_check_delete(bullet *t, int (*map)[map_size_h]);
void bullet_refresh(bullet *bu[], int num, int (*map)[18]);

/******* gaming_loop.h *********/
int win_lose_check();



void getZoomImage(PIMAGE pimg, const char* fileName, int _width, int _height)
{
    PIMAGE temp = newimage();
    getimage(temp, fileName);

    if ((getwidth(pimg) != _width) || (getheight(pimg) != _height))
        resize(pimg, _width, _height);

    putimage(pimg, 0, 0, width, height, temp, 0, 0, getwidth(temp), getheight(temp));

    delimage(temp);
}