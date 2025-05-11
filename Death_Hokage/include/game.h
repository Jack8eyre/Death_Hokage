#pragma once
#ifndef GAME_H
#define GAME_H
#define WIDTH 1500
#define HEIGHT 600

#include <graphics.h>
#include <conio.h>
#pragma comment(lib,"Winmm.lib")
#include <windows.h>
#include <stdio.h>
#include "player.h"
// 全局变量声明
extern int player1_x, player1_y, player2_x, player2_y;
extern int player1old_y, player2old_y, player1old_x, player2old_x;
extern int player1flagbt_dt, player1flagAD, player1flagK, player1flagS;
extern int player1flagJ, jumpnum1, player1flagL, player1flagU;
extern int player1flagbt, player1flagI, player1flagO, player1flagW, player1blood;
extern int player2flagbt_dt, player2flagAD, player2flagK, player2flagS;
extern int player2flagJ, jumpnum2, player2flagL, player2flagU;
extern int player2flagbt, player2flagI, player2flagO, player2flagW, player2blood;
extern int player1select, player2select;
extern int player1yz, player2yz;
extern int x_head1, y_head1, x_head2, y_head2;//选框位置
extern int flag1, flag2;
extern int x, y, esc, flagi;

// 图像资源
extern IMAGE img_bk;
extern IMAGE img_player1walk1, img_player1walk2, img_player1jp1, img_player1jp2;
extern IMAGE img_player1df1, img_player1df2, img_player1ft11, img_player1ft12;
extern IMAGE img_player1ft21, img_player1ft22, img_player1ft31, img_player1ft32;
extern IMAGE img_player1jf1, img_player1jf2, img_player1dg1, img_player1dg2;
extern IMAGE img_player1sk11, img_player1sk12, img_player1bt1, img_player1bt2;
extern IMAGE img_player1sk21, img_player1sk22, img_player1sk31, img_player1sk32;
extern IMAGE img_player2walk1, img_player2walk2, img_player2jp1, img_player2jp2;
extern IMAGE img_player2df1, img_player2df2, img_player2ft11, img_player2ft12;
extern IMAGE img_player2ft21, img_player2ft22, img_player2ft31, img_player2ft32;
extern IMAGE img_player2jf1, img_player2jf2, img_player2dg1, img_player2dg2;
extern IMAGE img_player2sk11, img_player2sk12, img_player2bt1, img_player2bt2;
extern IMAGE img_player2sk21, img_player2sk22, img_player2sk31, img_player2sk32;
extern IMAGE img_blood2, img_blood1, img_blood, img_blood_head_left2;
extern IMAGE img_blood_head_left1, img_blood_head_right2, img_blood_head_right1;
extern IMAGE img_gameover1, img_gameover2;

// 函数声明
void startup();
void background();
void bkmusic();
void blood();
void player1();
void player2();
void updateWithInput();
void updateWithoutInput();
void show();
void gameover();

#endif // GAME_H