//
// Created by 123 on 2021/7/14.
//
#pragma once

#include "graphics.h"

#include "global_ver.h"

//声明

void screen_init(int w, int h)
{
    //ui_1 = newimage();
    //printf("%d",getimage_pngfile(ui_1,R"(.\assets\ui\b1.png)"));

    setinitmode(INIT_ANIMATION|INIT_TOPMOST, (width-w)/2, (height-h)/2);
    initgraph(w, h);
    setcaption("Tank Fight!");
    setrendermode(RENDER_MANUAL);
}

void Main_screen(bool render)
{
    if(render && screen_ == main_screen){
        if(ui_1 == NULL){
            ui_1 = newimage();
            int i = getimage_pngfile(ui_1,R"(.\assets\ui\b1.png)");
            if(log)printf("_____log_____:ui1 load success %d\n",i);
        }
        if(ui_2 == NULL){
            ui_2 = newimage();
            int i = getimage_pngfile(ui_2,R"(.\assets\ui\ui_2.png)");
            if(log)printf("_____log_____:ui1 load success %d\n",i);
        }
        if(bk_1 == NULL){
            bk_1 = newimage();
            int i = getimage_pngfile(bk_1,R"(.\assets\ui\bk1.png)");
            if(log)
                printf("_____log_____:bk1 load success %d\n",i);
        }
        if(bk_2 == NULL){
            bk_2 = newimage();
            int i = getimage_pngfile(bk_2,R"(.\assets\ui\bk2.png)");
            if(log)printf("_____log_____:bk2 load success %d\n",i);
        }

        setbkmode(TRANSPARENT);
        LOGFONT font;
        getfont(&font);
        font.lfHeight = 200;
        setfont(&font);
        xyprintf(150,80,"Tank Fight");


        font.lfHeight = 40;
        setfont(&font);

        putimage(440,350,13,70,ui_2,0,0,4,22);
        putimage(440+13,350,374,70,ui_2,10,0,2,22);
        putimage(440+387,350,13,70,ui_2,18,0,4,22);
        xyprintf(440+120, 365, "开始游戏");

        putimage(440,440,13,70,ui_2,0,0,4,22);
        putimage(440+13,440,374,70,ui_2,10,0,2,22);
        putimage(440+387,440,13,70,ui_2,18,0,4,22);
        xyprintf(440+160, 455, "设置");

        putimage(440,530,13,70,ui_2,0,0,4,22);
        putimage(440+13,530,374,70,ui_2,10,0,2,22);
        putimage(440+387,530,13,70,ui_2,18,0,4,22);
        xyprintf(440+160, 545, "退出");

        while(mousemsg()){
            auto mouse = getmouse();
            int xx = mouse.x, yy = mouse.y;
            if(mouse.is_down()){
                if(xx >= 440 && yy >= 350 && xx <= 840 && yy <= 420){
                    screen_ = new_world_screen;
                    //change_screen();
                    if(log)
                        printf("_____log_____:press button1\n");
                }
                if(xx >= 440 && yy >= 440 && xx <= 840 && yy <= 510){
                    if(log)
                        printf("_____log_____:press button2\n");
                }
                if(xx >= 440 && yy >= 530 && xx <= 840 && yy <= 600){
                    if(log)
                        printf("_____log_____:press button3\n");
                }
            }
        }
    }
}

void New_world_screen(bool render)
{
    if(render && screen_ == new_world_screen){
        if(ui_1 == NULL){
            ui_1 = newimage();
            int i = getimage_pngfile(ui_1,R"(.\assets\ui\b1.png)");
            if(log)printf("_____log_____:ui1 load success %d\n",i);
        }
        if(ui_2 == NULL){
            ui_2 = newimage();
            int i = getimage_pngfile(ui_2,R"(.\assets\ui\ui_2.png)");
            if(log)printf("_____log_____:ui1 load success %d\n",i);
        }
        if(bk_1 == NULL){
            bk_1 = newimage();
            int i = getimage_pngfile(bk_1,R"(.\assets\ui\bk1.png)");
            if(log)
                printf("_____log_____:bk1 load success %d\n",i);
        }
        if(bk_2 == NULL){
            bk_2 = newimage();
            int i = getimage_pngfile(bk_2,R"(.\assets\ui\bk2.png)");
            if(log)printf("_____log_____:bk2 load success %d\n",i);
        }

        setbkmode(TRANSPARENT);
        LOGFONT font;
        getfont(&font);
        font.lfHeight = 30;
        setfont(&font);

        putimage(100,60,200,600,bk_1,0,0,40,120);
        putimage(300,60,680,600,bk_1,30,0,10,120);
        putimage(980,60,200,600,bk_2,0,0,40,120);

        putimage(180,510,13,70,ui_2,0,0,4,22);
        putimage(180+13,510,354,70,ui_2,10,0,2,22);
        putimage(180+367,510,13,70,ui_2,18,0,4,22);
        xyprintf(180+130, 530, "载入模板");

        putimage(180,115,380,35,ui_1,0,0,120,10);
        putimage(180,115+35,380,310,ui_1,0,10,120,15);
        putimage(180,140+295,380,35,ui_1,0,22,120,10);

        mini_gaming_map(game_map_[0], block_, 41, 27, 5);
        mini_gaming_map(game_map_[1], block_, 64, 27, 5);
        mini_gaming_map(game_map_[2], block_, 87, 27, 5);
        mini_gaming_map(game_map_[3], block_, 41, 50, 5);
        mini_gaming_map(game_map_[4], block_, 64, 50, 5);
        mini_gaming_map(game_map_[5], block_, 87, 50, 5);
        mini_gaming_map(game_map_[6], block_, 41, 73, 5);
        mini_gaming_map(game_map_[7], block_, 64, 73, 5);
        mini_gaming_map(game_map_[8], block_, 87, 73, 5);

        putimage(720,510,13,70,ui_2,0,0,4,22);
        putimage(720+13,510,354,70,ui_2,10,0,2,22);
        putimage(720+367,510,13,70,ui_2,18,0,4,22);
        xyprintf(720+145, 530, "自定义");

        putimage(720,115,380,35,ui_1,0,0,120,10);
        putimage(720,115+35,380,310,ui_1,0,10,120,15);
        putimage(720,140+295,380,35,ui_1,0,22,120,10);

        mini_gaming_map(gamemap1, block_, 52, 10, 15);

        while(mousemsg()){
            auto mouse = getmouse();
            int xx = mouse.x, yy = mouse.y;
            if(mouse.is_down()){
                if(xx >= 180 && yy >= 510 && xx <= 560 && yy <= 580){
                    xyprintf(180+40, 590, "输入对应数字载入模板");
                    while(1){
                        auto key = getkey();
                        if(key.key >= '0' && key.key <= '9'){
                            load_map(gamemap2,key.key-'0');
                            break;
                        }
                    }
                    screen_ = gaming_screen;
                    //change_screen();
                    if(log)
                        printf("_____log_____:press button1\n");
                }
                if(xx >= 720 && yy >= 510 && xx <= 1100 && yy <= 580){
                    screen_ = map_making_screen;
                    if(log)
                        printf("_____log_____:press button2\n");
                }
            }
        }

    }
}

void Gaming_screen(bool render, int (*gaming_map)[map_size_h], block *b[], Tank *player, Tank *ai[], bullet *bu[], bullet *aibu[10][15], int *bullet_id, int *time, int *time2)
{
    if(render && screen_ == gaming_screen){
        int g = win_lose_check();
        bullet_key(bu, 15, player, bullet_id, time);
        for(int i = 0; i < 10; i++){
            bullet_ai(aibu[i],15,ai[i],&buid,&time3[i]);
            bullet_refresh(aibu[i], 15, gaming_map);
        }
        bullet_refresh(bu, 15, gaming_map);
        tank_move_key(player, gaming_map);
        ai_tank_move(ai, 10, gaming_map, time2);
        for(int i = 0; i < 15; i++)
            for(int j = 0; j < 10; j++){
                bullet_damage(bu[i],ai[j]);
                bullet_damage(aibu[j][i],player);
                for(int k = 0; k < 10; k++){
                    if(k != j)
                        bullet_damage(aibu[j][i],ai[k]);
                }
            }

        //background_block_renderer(*b[5]);
        gaming_map_renderer(gaming_map, b, 7, 0, map_size_h, map_size_h, block_size_);
        bullet_renderer(bu, 15, 7, 0, block_size_);
        for(int i = 0; i < 10; i++)
            bullet_renderer(aibu[i], 15, 7, 0, block_size_);
        ai_tank_renderer(ai, 10, 7, 0, block_size_);
        tank_renderer(player, 7, 0, block_size_);

        //右侧信息显示
        setbkmode(TRANSPARENT);
        //setbkcolor(EGERGB(0,0,0));
        setfont(40, 0, "");
        LOGFONT font;
        getfont(&font);
        font.lfWeight = 100;
        setfont(&font);
        setcolor(EGERGB(28,28,28));
        //for(int i = 0; i < 4; i++)
            //putimage(block_size_*25 + i*80,0,80,80,b[5]->pimage,0,0,16,16);
        if(ui_1 == NULL){
            ui_1 = newimage();
            int i = getimage_pngfile(ui_1,R"(.\assets\ui\b1.png)");
            if(log)printf("_____log_____:ui1 load success %d\n",i);
        }
        if(ui_2 == NULL){
            ui_2 = newimage();
            int i = getimage_pngfile(ui_2,R"(.\assets\ui\ui_2.png)");
            if(log)printf("_____log_____:ui1 load success %d\n",i);
        }
        if(bk_1 == NULL){
            bk_1 = newimage();
            int i = getimage_pngfile(bk_1,R"(.\assets\ui\bk1.png)");
            if(log)
                printf("_____log_____:bk1 load success %d\n",i);
        }
        if(bk_2 == NULL){
            bk_2 = newimage();
            int i = getimage_pngfile(bk_2,R"(.\assets\ui\bk2.png)");
            if(log)printf("_____log_____:bk2 load success %d\n",i);
        }
        putimage(0,0,240,720,bk_1,0,0,getwidth(bk_1),getheight(bk_1));
        putimage(240,0,120,720,bk_1,getwidth(bk_1)*2/3,0,getwidth(bk_1),getheight(bk_1));
        putimage(1000,0,120,720,bk_2,0,0,getwidth(bk_2)/3,getheight(bk_2));
        putimage(1040,0,240,720,bk_2,0,0,getwidth(bk_2),getheight(bk_2));

        putimage(block_size_*25,0,280,20,ui_1,0,0,120,10);
        putimage(block_size_*25,20,280,370,ui_1,0,10,120,15);
        putimage(block_size_*25,390,280,20,ui_1,0,22,120,10);

        putimage(block_size_*25,0,13,70,ui_2,0,0,4,22);
        putimage(block_size_*25+13,0,254,70,ui_2,10,0,2,22);
        putimage(block_size_*25+267,0,13,70,ui_2,18,0,4,22);

        putimage(block_size_*25,420,280,20,ui_1,0,0,120,10);
        putimage(block_size_*25,440,280,260,ui_1,0,10,120,15);
        putimage(block_size_*25,700,280,20,ui_1,0,22,120,10);

        putimage(block_size_*25,410,13,70,ui_2,0,0,4,22);
        putimage(block_size_*25+13,410,254,70,ui_2,10,0,2,22);
        putimage(block_size_*25+267,410,13,70,ui_2,18,0,4,22);


        xyprintf(block_size_*27, 15, "计分板");
        //for(int i = 0; i < 4; i++)
            //putimage(block_size_*25 + i*80,420,80,80,b[5]->pimage,0,0,16,16);
        xyprintf(block_size_*27+block_size_/2, 425, "状态");
        font.lfHeight = 20;
        setfont(&font);
        setcolor(EGERGB(250,250,250));
        xyprintf(block_size_*25+10, 80, "玩家得分：");
        for(int i = 1; i <= 10; i++){
            xyprintf(block_size_*25+10, 80 + 30*i, "人机{%d}得分：", i);
        }
        xyprintf(block_size_*25+10, 510, "生命：%d，血量：%d，速度：%.1fsssssss", player -> life, player -> blood, player -> speed);
        xyprintf(block_size_*25+10, 540, "位置：X：%.2f，Y：%.2f", player -> pos.x, player -> pos.y);
        xyprintf(block_size_*25+10, 570, "攻速：%d，攻击力：%d", player -> fight_speed, player -> agg);
        xyprintf(block_size_*25+10, 600, "重生点：（%d，%d）", player -> spawnpoint.x, player -> spawnpoint.y);
        xyprintf(block_size_*25+10, 630, "BUFF：敬请期待");

        //左侧信息显示
        putimage(0,0,282,20,ui_1,0,0,120,10);
        putimage(0,20,282,680,ui_1,0,10,120,15);
        putimage(0,700,282,20,ui_1,0,22,120,10);

        //button1
        putimage(41,80,13,70,ui_2,0,0,4,22);
        putimage(41+13,80,174,70,ui_2,10,0,2,22);
        putimage(41+187,80,13,70,ui_2,18,0,4,22);
        xyprintf(41+80, 105, "保存");

        //button2
        putimage(41,160,13,70,ui_2,0,0,4,22);
        putimage(41+13,160,174,70,ui_2,10,0,2,22);
        putimage(41+187,160,13,70,ui_2,18,0,4,22);
        xyprintf(41+40, 185, "重新载入游戏");

        //button3
        putimage(41,240,13,70,ui_2,0,0,4,22);
        putimage(41+13,240,174,70,ui_2,10,0,2,22);
        putimage(41+187,240,13,70,ui_2,18,0,4,22);
        xyprintf(41+80, 265, "设置");

        //button4
        putimage(41,320,13,70,ui_2,0,0,4,22);
        putimage(41+13,320,174,70,ui_2,10,0,2,22);
        putimage(41+187,320,13,70,ui_2,18,0,4,22);
        xyprintf(41+70, 345, "主菜单");

        //button4
        putimage(41,400,13,70,ui_2,0,0,4,22);
        putimage(41+13,400,174,70,ui_2,10,0,2,22);
        putimage(41+187,400,13,70,ui_2,18,0,4,22);
        xyprintf(41+80, 425, "暂停");

        xyprintf(10, 10, "FPS：%f",getfps());

        while(mousemsg()){
            auto mouse = getmouse();
            int xx = mouse.x, yy = mouse.y;
            if(mouse.is_down()){
                if(xx >= 41 && yy >= 80 && xx <= 241 && yy <= 150){
                    xyprintf(41+20, 160, "选择保存位置，1——9");
                    int a = 0;
                    while(1){
                        auto key = getkey();
                        if(key.key >= '0' && key.key <= '9'){
                            a = key.key - '0';
                            save_map(game_map_[a], a);
                            break;
                        }
                    }
                    //change_screen();
                    if(log)
                        printf("_____log_____:press button1\n");
                }
                if(xx >= 41 && yy >= 160 && xx <= 241 && yy <= 230){
                    xyprintf(180+40, 590, "输入对应数字载入模板");
                    while(1){
                        auto key = getkey();
                        if(key.key >= '0' && key.key <= '9'){
                            load_map(game_map_[key.key-'0'],key.key-'0');
                            break;
                        }
                    }
                    if(log)
                        printf("_____log_____:press button2\n");
                }
                if(xx >= 41 && yy >= 320 && xx <= 241 && yy <= 390){
                    screen_ = main_screen;
                    if(log)
                        printf("_____log_____:press button3\n");
                }
                if(xx >= 41 && yy >= 400 && xx <= 2410 && yy <= 470){
                    xyprintf(41+20, 465, "按ESC回到游戏");
                    while(1){
                        auto key = getkey();
                        if(key.key == 27) break;
                    }
                    //screen_ = main_screen;
                    if(log)
                        printf("_____log_____:press button4\n");
                }
            }
        }
        //screen_ = gaming_screen;
        if(g == 1){
            setbkcolor(EGERGB(28,28,28));
            setbkmode(TRANSPARENT);
            LOGFONT font;
            getfont(&font);
            font.lfHeight = 200;
            setfont(&font);
            xyprintf(150,80,"YOU WIN!");
            font.lfHeight = 20;
            setfont(&font);
            xyprintf(150,300,"press ESC back to main screen");
            while(1){
                auto key = getkey();
                if(key.key == 27) break;
            }

            screen_ = main_screen;
        }
        if(g == -1){
            setbkcolor(EGERGB(28,28,28));
            setbkmode(TRANSPARENT);
            LOGFONT font;
            getfont(&font);
            font.lfHeight = 200;
            setfont(&font);
            xyprintf(150,80,"YOU LOSE!");
            font.lfHeight = 20;
            setfont(&font);
            xyprintf(150,300,"press ESC back to main screen");
            while(1){
                auto key = getkey();
                if(key.key == 27) break;
            }
            screen_ = main_screen;
        }
    }
}

screen getScreen()
{
    return screen_;
}

int flag1 = 0, flag2 = 0;

void mouse_init(int xpos, int ypos, int block_size, int *blockid)
{
    while(mousemsg()){
        auto mouse = getmouse();
        int xx = mouse.x, yy = mouse.y;
        if(mouse.is_left()){
            if(mouse.is_down() && (mouse.y-ypos*block_size)/block_size >= 0 && (mouse.y-ypos*block_size)/block_size < map_size_h && ((mouse.x-xpos*block_size)/block_size) >= 0 && ((mouse.x-xpos*block_size)/block_size) < map_size_h){
                flag1 = 1;
                printf("%d,%d\n",(mouse.y-ypos*block_size)/block_size,((mouse.x-xpos*block_size)/block_size));
            }
            if(mouse.is_up() && flag1 == 1){
                flag1 = 0;
            }
            if(mouse.is_down()){
                if(xx >= 41 && yy >= 80 && xx <= 241 && yy <= 150){
                    xyprintf(41+20, 160, "选择保存位置，1——9");
                    int a = 0;
                    while(1){
                        auto key = getkey();
                        if(key.key >= '0' && key.key <= '9'){
                            a = key.key - '0';
                            save_map(gamemap1, a);
                            break;
                        }
                    }
                    //change_screen();
                    if(log)
                        printf("_____log_____:press button1\n");
                }
                if(xx >= 440 && yy >= 440 && xx <= 840 && yy <= 510){
                    if(log)
                        printf("_____log_____:press button2\n");
                }
                if(xx >= 440 && yy >= 530 && xx <= 840 && yy <= 600){
                    if(log)
                        printf("_____log_____:press button3\n");
                }
                if(xx >= 41 && yy >= 320 && xx <= 241 && yy <= 390){
                    screen_ = main_screen;
                    if(log)
                        printf("_____log_____:press button3\n");
                }
            }
        }
        if(flag1)
            gamemap1[(mouse.y-ypos*block_size)/block_size][((mouse.x-xpos*block_size)/block_size)] = *blockid;
        if(mouse.is_right()){
            if(mouse.is_down() && (mouse.y-ypos*block_size)/block_size >= 0 && (mouse.y-ypos*block_size)/block_size < map_size_h && ((mouse.x-xpos*block_size)/block_size) >= 0 && ((mouse.x-xpos*block_size)/block_size) < map_size_h){
                flag2 = 1;
            }
            if(mouse.is_up() && flag2 == 1){
                flag2 = 0;
            }
        }
        if(flag2)
            gamemap1[(mouse.y-ypos*block_size)/block_size][((mouse.x-xpos*block_size)/block_size)] = 0;

        if(mouse.is_wheel() > 0){
            (*blockid)++;
            if((*blockid) >= block_num){
                (*blockid) = 0;
            }
        }
        if(mouse.is_wheel() < 0){
            (*blockid)--;
            if((*blockid) < 0){
                (*blockid) = block_num - 1;
            }
        }
        //if(mouse.is_mid() && mouse.is_down())
        xyprintf(10,20,"X: %d,Y: %d",mouse.x,mouse.y);
    }
}

void key_init(int *blockid)
{
    while(kbmsg()){
        char aa = getkey().key;
        if(aa >= '1' && aa <='9'){
            *blockid = aa-'0';
        }
        if(aa == 's'){
            FILE *fp = fopen(".\\map\\1.txt","w");
            for(int y = 0; y < map_size_h; y++){
                for(int x = 0; x < map_size_h; x++){
                    fprintf(fp,"%d ",gamemap1[y][x]);
                }
                fprintf(fp,"\n");
            }
            fclose(fp);
        }
        if(aa == 'l'){
            FILE *fp = fopen("D:\\map\\1.txt","r");
            for(int y = 0; y < map_size_h; y++){
                for(int x = 0; x < map_size_h; x++){
                    fscanf(fp,"%d",&gamemap1[y][x]);
                    printf("%d,",gamemap1[y][x]);
                }
                printf("\n");
            }
            fclose(fp);
        }
    }
}

void mini_gaming_map(int (*map)[map_size_h], block *b[], int xpos, int ypos, int block_size)
{
    gaming_map_renderer(map, b, xpos, ypos, map_size_h, map_size_h,block_size);
}

void Map_making_screen(bool render, block *b[], int xpos, int ypos, int *blockid)
{
    if(render && screen_ == map_making_screen){
        if(ui_1 == NULL){
            ui_1 = newimage();
            int i = getimage_pngfile(ui_1,R"(.\assets\ui\b1.png)");
            if(log)printf("_____log_____:ui1 load success %d\n",i);
        }
        if(ui_2 == NULL){
            ui_2 = newimage();
            int i = getimage_pngfile(ui_2,R"(.\assets\ui\ui_2.png)");
            if(log)printf("_____log_____:ui1 load success %d\n",i);
        }
        if(bk_1 == NULL){
            bk_1 = newimage();
            int i = getimage_pngfile(bk_1,R"(.\assets\ui\bk1.png)");
            if(log)
                printf("_____log_____:bk1 load success %d\n",i);
        }
        if(bk_2 == NULL){
            bk_2 = newimage();
            int i = getimage_pngfile(bk_2,R"(.\assets\ui\bk2.png)");
            if(log)printf("_____log_____:bk2 load success %d\n",i);
        }

        key_init(blockid);
        mouse_init(7, 0, block_size_, blockid);

        //background_block_renderer(*b[8]);
        gaming_map_renderer(gamemap1, b, 7, 0, map_size_h, map_size_h, block_size_);

        LOGFONT font;
        getfont(&font);
        font.lfHeight = 20;
        setfont(&font);

        putimage(0,0,240,720,bk_1,0,0,getwidth(bk_1),getheight(bk_1));
        putimage(240,0,120,720,bk_1,getwidth(bk_1)*2/3,0,getwidth(bk_1),getheight(bk_1));
        putimage(1000,0,120,720,bk_2,0,0,getwidth(bk_2)/3,getheight(bk_2));
        putimage(1040,0,240,720,bk_2,0,0,getwidth(bk_2),getheight(bk_2));


        //button1
        putimage(41,80,13,70,ui_2,0,0,4,22);
        putimage(41+13,80,174,70,ui_2,10,0,2,22);
        putimage(41+187,80,13,70,ui_2,18,0,4,22);
        xyprintf(41+80, 105, "保存");

        //button2
        putimage(41,160,13,70,ui_2,0,0,4,22);
        putimage(41+13,160,174,70,ui_2,10,0,2,22);
        putimage(41+187,160,13,70,ui_2,18,0,4,22);
        xyprintf(41+40, 185, "重新载入游戏");

        //button3
        putimage(41,240,13,70,ui_2,0,0,4,22);
        putimage(41+13,240,174,70,ui_2,10,0,2,22);
        putimage(41+187,240,13,70,ui_2,18,0,4,22);
        xyprintf(41+80, 265, "设置");

        //button4
        putimage(41,320,13,70,ui_2,0,0,4,22);
        putimage(41+13,320,174,70,ui_2,10,0,2,22);
        putimage(41+187,320,13,70,ui_2,18,0,4,22);
        xyprintf(41+70, 345, "主菜单");

        //button4
        putimage(41,400,13,70,ui_2,0,0,4,22);
        putimage(41+13,400,174,70,ui_2,10,0,2,22);
        putimage(41+187,400,13,70,ui_2,18,0,4,22);
        xyprintf(41+80, 425, "退出");

        putimage(block_size_*25+20,40,240,20,ui_1,0,0,120,10);
        putimage(block_size_*25+20,60,240,330,ui_1,0,10,120,15);
        putimage(block_size_*25+20,390,240,20,ui_1,0,22,120,10);
        xyprintf(block_size_*25+90, 60, "当前所选块");
        putimage(block_size_*25+90,100,100,100,block_[*blockid]->pimage,0,0,16,16);
        xyprintf(block_size_*25+40, 220, "块介绍：");
        xyprintf(block_size_*25+40, 250, "id：%d", *blockid);
        xyprintf(block_size_*25+40, 280, "强度（耐久）：%d", block_[*blockid]->durable);
        xyprintf(block_size_*25+40, 310, "特性：（敬请期待）");
        xyprintf(block_size_*25+40, 340, "玩家重生点？：%d", block_[*blockid]->player_spownpoint);
        xyprintf(block_size_*25+40, 370, "人机重生点？：%d", block_[*blockid]->ai_spownpoint);

    }
}

void change_screen(enum screen s)
{
    if(s == main_screen)
    {

    }
    else if(s == gaming_screen)
    {

    }
    else if(s == pause_screen){

    }
    else if(s == map_making_screen)
    {

    }
}
