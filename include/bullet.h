#pragma once

#include "global_ver.h"

bullet *new_bullet(Tank *t, float speed, int effect, PIMAGE a)
{
    bullet *b;
    b = (bullet *)malloc(sizeof(bullet));
    b -> target = t;
    b -> speed = speed;
    b -> effect = effect;
    b -> collision_size = {0.4, 0.6};
    b -> pos = {-1.0, -1.0};
    b -> o = t -> o;
    b -> display = 0;
    //strcpy(b->image, image);
    b -> pimage = a;
    return b;
}

void bullet_damage(bullet *bu, Tank *t)
{
    float x = bu->pos.x, y = bu->pos.y;
    float x_ = t->pos.x, y_ = t->pos.y;
    float aa = bu->collision_size.a, bb = bu->collision_size.b;
    float aa_ = t->collision_size.a, bb_ = t->collision_size.b;
    if((x >= x_ + aa_ && x <= x_ + bb_ && y >= y_ + aa_ && y <= y_ + bb_)||(x + aa >= x_ + aa_ && x + bb <= x_ + bb_ && y + aa >= y_ + aa_ && y + bb <= y_ + bb_)){
        t -> life --;
        if(log)
            printf("_____log_____:damage tank, life = %d \n",t -> life);
    }
}

void bullet_init(Tank *t, bullet *bu[], int num, PIMAGE bullet_image)
{
    //PIMAGE bullet_image = newimage();
    getimage_pngfile(bullet_image,R"(.\assets\tank\bullet\0.png)");
    for(int i = 0; i < num; i++){
        bu[i] = new_bullet(t,5,-1,bullet_image);
    }
}

void bullet_key(bullet *bu[], int num, Tank *player, int *bullet_id, int *time)
{
    if(keystate('K')){
        (*time)++;
        if(*time >= player->fight_speed){
            bu[*bullet_id] -> pos = player -> pos;
            bu[*bullet_id] -> o = player -> o;
            bu[*bullet_id] -> display = 1;
            (*bullet_id) ++;
            if((*bullet_id) >= num) (*bullet_id) = 0;
            (*time) = 0;
        }
    }
}


void bullet_ai(bullet *bu[], int num, Tank *player, int *bullet_id, int *time)
{
    if(player -> life > 0){
        (*time)++;
        if(*time >= player->fight_speed){
            bu[*bullet_id] -> pos = player -> pos;
            bu[*bullet_id] -> o = player -> o;
            bu[*bullet_id] -> display = 1;
            (*bullet_id) ++;
            if((*bullet_id) >= num) (*bullet_id) = 0;
            (*time) = 0;
        }
    }
}

vec4 block_check_delete(bullet *t, int (*map)[map_size_h])
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
            if(map[(int)y][(int)(x+0.1*(t->speed))] != 0 && t->o == right){
                map[(int)y][(int)(x+0.1*(t->speed))] = 0;
                t -> display = 0;
                t -> pos = {-1.0,-1.0};
            }
            if(map[(int)y][(int)(x-0.1*(t->speed))] != 0 && t->o == left){
                map[(int)y][(int)(x-0.1*(t->speed))] = 0;
                t -> display = 0;
                t -> pos = {-1.0,-1.0};
            }
            if(map[(int)(y+0.1*(t->speed))][(int)x] != 0 && t->o == backward){
                map[(int)(y+0.1*(t->speed))][(int)x] = 0;
                t -> display = 0;
                t -> pos = {-1.0,-1.0};
            }
            if(map[(int)(y-0.1*(t->speed))][(int)x] != 0 && t->o == forward){
                map[(int)(y-0.1*(t->speed))][(int)x] = 0;
                t -> display = 0;
                t -> pos = {-1.0,-1.0};
            }
        }
    }
    return v;
}

void bullet_refresh(bullet *bu[], int num, int (*map)[18])
{
    for(int i = 0; i < num; i++){
        if(bu[i]->display == 1){
            if(bu[i]->o == forward){
                bu[i] -> pos.y -= 0.1*(bu[i]->speed);
            }
            else if(bu[i]->o == backward)
                bu[i] -> pos.y += 0.1*(bu[i]->speed);
            else if(bu[i]->o == left)
                bu[i] -> pos.x -= 0.1*(bu[i]->speed);
            else
                bu[i] -> pos.x += 0.1*(bu[i]->speed);



            if(bu[i] -> pos.y < 0 || bu[i] -> pos.y > map_size_h-1 || bu[i] -> pos.x < 0 || bu[i] -> pos.x > map_size_h-1){
                bu[i] -> display = 0;
                bu[i] -> pos = {-1.0,-1.0};
                if(debug){
                    HANDLE hOut;
                    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
                    printf("______debug_______: bullet beyond\n");
                }
            }
            else block_check_delete(bu[i], map);
        }
    }
}
