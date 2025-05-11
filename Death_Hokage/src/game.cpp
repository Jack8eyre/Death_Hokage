#include "../game.h"

// 全局变量定义
/*flagbt_dt：被攻击时的方向状态
flagAD：水平移动状态
flagK：跳跃状态
flagS：防御状态
flagJ：普通攻击状态
flagL：闪避状态
flagU：技能1状态
flagI：技能2状态
flagO：技能3状态
blood：血量
  */
int player1_x, player1_y, player2_x, player2_y;
int player1old_y, player2old_y, player1old_x, player2old_x;
int player1flagbt_dt = 0, player1flagAD = 1, player1flagK = 0, player1flagS = 0;
int player1flagJ = 0, jumpnum1 = 0, player1flagL = 0, player1flagU = 0;
int player1flagbt = 0, player1flagI = 0, player1flagO = 0, player1flagW = 0, player1blood = 526;
int player2flagbt_dt = 0, player2flagAD = -1, player2flagK = 0, player2flagS = 0;
int player2flagJ = 0, jumpnum2 = 0, player2flagL = 0, player2flagU = 0;
int player2flagbt = 0, player2flagI = 0, player2flagO = 0, player2flagW = 0, player2blood = 526;
int player1select = 1, player2select = 2; // 1：玩家1，2：玩家2
int player1yz = 0, player2yz = 0;
int x_head1 = 95, y_head1 = 95, x_head2 = 1295, y_head2 = 95;//选框位置
int flag1 = 1, flag2 = 1;
int x = 0, y = 0;
int esc = 0;
int flagi = 1;

// 图像资源定义
/*
img_player1walk2, //行走
img_player1jp2,   //跳跃
img_player1df2,   //防御
img_player1ft12,  //攻击1
img_player1ft22,  //攻击2
img_player1ft32,  //攻击3
img_player1jf2,   //跳攻
img_player1dg2,   //闪避
img_player1sk12,  //技能1
img_player1bt2,   //被打
img_player1sk22,  //技能2
img_player1sk32;  //技能3*/
IMAGE img_bk;
IMAGE img_player1walk1, img_player1walk2, img_player1jp1, img_player1jp2;
IMAGE img_player1df1, img_player1df2, img_player1ft11, img_player1ft12;
IMAGE img_player1ft21, img_player1ft22, img_player1ft31, img_player1ft32;
IMAGE img_player1jf1, img_player1jf2, img_player1dg1, img_player1dg2;
IMAGE img_player1sk11, img_player1sk12, img_player1bt1, img_player1bt2;
IMAGE img_player1sk21, img_player1sk22, img_player1sk31, img_player1sk32;
IMAGE img_player2walk1, img_player2walk2, img_player2jp1, img_player2jp2;
IMAGE img_player2df1, img_player2df2, img_player2ft11, img_player2ft12;
IMAGE img_player2ft21, img_player2ft22, img_player2ft31, img_player2ft32;
IMAGE img_player2jf1, img_player2jf2, img_player2dg1, img_player2dg2;
IMAGE img_player2sk11, img_player2sk12, img_player2bt1, img_player2bt2;
IMAGE img_player2sk21, img_player2sk22, img_player2sk31, img_player2sk32;
IMAGE img_blood2, img_blood1, img_blood, img_blood_head_left2;
IMAGE img_blood_head_left1, img_blood_head_right2, img_blood_head_right1;
IMAGE img_gameover1, img_gameover2;
