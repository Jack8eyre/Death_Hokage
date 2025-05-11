#include "..//game.h"
#include "..//player.h"

//绘制玩家的血条和相关的头像图像
void blood()
{
	int i;
	putimage(0, 0, &img_blood1, NOTSRCERASE);
	putimage(0, 0, &img_blood2, SRCERASE);
	putimage(0, 0, &img_blood_head_left1, NOTSRCERASE);
	putimage(0, 0, &img_blood_head_left2, SRCERASE);
	putimage(1228, 0, &img_blood_head_right1, NOTSRCERASE);
	putimage(1228, 0, &img_blood_head_right2, SRCERASE);
	for (i = 1; i <= player1blood; i++)//玩家1生命条
		putimage(149 + i, 45, &img_blood);
	for (i = 1; i <= player2blood; i++)
		putimage(1357 - i, 45, &img_blood);//玩家2生命条
}
//加载图片
void blackground()
{
	loadimage(&img_bk, _T("resource\\Map\\TUT.bmp"));//1228*602
	loadimage(&img_blood2, _T("resource\\Map\\血条2.jpg"));
	loadimage(&img_blood1, _T("resource\\Map\\血条1.jpg"));
	loadimage(&img_blood, _T("resource\\Map\\1血量.jpg"));
	loadimage(&img_gameover1, _T("resource\\Map\\KO1.jpg"));
	loadimage(&img_gameover2, _T("resource\\Map\\KO2.jpg"));
}
//初始化游戏的基本环境和资源
void startup()
{
	initgraph(WIDTH, HEIGHT);
	player1_x = 100;
	player1_y = 480;
	player2_x = 1000;
	player2_y = 480;
	blackground();
	//玩家1
	if (player1select == 1)
	{
		loadimage(&img_player1walk1, _T("resource\\Figures\\佩恩\\行走动画1.jpg"));
		loadimage(&img_player1walk2, _T("resource\\Figures\\佩恩\\行走动画2.jpg"));
		loadimage(&img_player1jp1, _T("resource\\Figures\\佩恩\\跳跃12.jpg"));
		loadimage(&img_player1jp2, _T("resource\\Figures\\佩恩\\跳跃11.jpg"));
		loadimage(&img_player1df1, _T("resource\\Figures\\佩恩\\防御1.jpg"));
		loadimage(&img_player1df2, _T("resource\\Figures\\佩恩\\防御2.jpg"));
		loadimage(&img_player1ft11, _T("resource\\Figures\\佩恩\\攻击11.jpg"));
		loadimage(&img_player1ft12, _T("resource\\Figures\\佩恩\\攻击12.jpg"));
		loadimage(&img_player1ft21, _T("resource\\Figures\\佩恩\\攻击21.jpg"));
		loadimage(&img_player1ft22, _T("resource\\Figures\\佩恩\\攻击22.jpg"));
		loadimage(&img_player1ft31, _T("resource\\Figures\\佩恩\\攻击31.jpg"));
		loadimage(&img_player1ft32, _T("resource\\Figures\\佩恩\\攻击32.jpg"));
		loadimage(&img_player1jf1, _T("resource\\Figures\\佩恩\\跳攻1.jpg"));
		loadimage(&img_player1jf2, _T("resource\\Figures\\佩恩\\跳攻2.jpg"));
		loadimage(&img_player1dg1, _T("resource\\Figures\\佩恩\\闪避1.jpg"));
		loadimage(&img_player1dg2, _T("resource\\Figures\\佩恩\\闪避2.jpg"));
		loadimage(&img_player1sk11, _T("resource\\Figures\\佩恩\\技能11.jpg"));
		loadimage(&img_player1sk12, _T("resource\\Figures\\佩恩\\技能12.jpg"));
		loadimage(&img_player1bt1, _T("resource\\Figures\\佩恩\\被打1.jpg"));
		loadimage(&img_player1bt2, _T("resource\\Figures\\佩恩\\被打2.jpg"));
		loadimage(&img_player1sk21, _T("resource\\Figures\\佩恩\\技能21.jpg"));
		loadimage(&img_player1sk22, _T("resource\\Figures\\佩恩\\技能22.jpg"));
		loadimage(&img_player1sk31, _T("resource\\Figures\\佩恩\\技能31.jpg"));
		loadimage(&img_player1sk32, _T("resource\\Figures\\佩恩\\技能32.jpg"));
	}
	//玩家2
	if (player2select == 2)
	{
		loadimage(&img_player2walk1, _T("resource\\Figures\\鸣人\\行走动画1.jpg"));
		loadimage(&img_player2walk2, _T("resource\\Figures\\鸣人\\行走动画2.jpg"));
		loadimage(&img_player2jp1, _T("resource\\Figures\\鸣人\\跳跃1.jpg"));
		loadimage(&img_player2jp2, _T("resource\\Figures\\鸣人\\跳跃2.jpg"));
		loadimage(&img_player2df1, _T("resource\\Figures\\鸣人\\防御1.jpg"));
		loadimage(&img_player2df2, _T("resource\\Figures\\鸣人\\防御2.jpg"));
		loadimage(&img_player2sk11, _T("resource\\Figures\\鸣人\\技能11.jpg"));
		loadimage(&img_player2sk12, _T("resource\\Figures\\鸣人\\技能12.jpg"));
		loadimage(&img_player2jf1, _T("resource\\Figures\\鸣人\\跳攻1.jpg"));
		loadimage(&img_player2jf2, _T("resource\\Figures\\鸣人\\跳攻2.jpg"));
		loadimage(&img_player2bt1, _T("resource\\Figures\\鸣人\\被打1.jpg"));
		loadimage(&img_player2bt2, _T("resource\\Figures\\鸣人\\被打2.jpg"));
		loadimage(&img_player2dg1, _T("resource\\Figures\\鸣人\\闪避1.jpg"));
		loadimage(&img_player2dg2, _T("resource\\Figures\\鸣人\\闪避2.jpg"));
		loadimage(&img_player2sk21, _T("resource\\Figures\\鸣人\\技能21.jpg"));
		loadimage(&img_player2sk22, _T("resource\\Figures\\鸣人\\技能22.jpg"));
		loadimage(&img_player2ft11, _T("resource\\Figures\\鸣人\\攻击11.jpg"));
		loadimage(&img_player2ft12, _T("resource\\Figures\\鸣人\\攻击12.jpg"));
		loadimage(&img_player2ft21, _T("resource\\Figures\\鸣人\\攻击21.jpg"));
		loadimage(&img_player2ft22, _T("resource\\Figures\\鸣人\\攻击22.jpg"));
		loadimage(&img_player2ft31, _T("resource\\Figures\\鸣人\\攻击31.jpg"));
		loadimage(&img_player2ft32, _T("resource\\Figures\\鸣人\\攻击32.jpg"));
		loadimage(&img_player2sk31, _T("resource\\Figures\\鸣人\\技能31.jpg"));
		loadimage(&img_player2sk32, _T("resource\\Figures\\鸣人\\技能32.jpg"));
	}

	BeginBatchDraw();
}
void show()
{

}
//处理玩家的输入，并根据输入更新游戏状态
void updateWithInput()

{
	if (player1flagbt == 0)
	{
		if (GetAsyncKeyState('S') & 0x8000)
			player1flagS = 1;
		if (player1flagS == 0 && player1flagU == 0 && player1flagI == 0 && player1flagO == 0 && player1flagL == 0)
		{
			if (GetAsyncKeyState('D') & 0x8000)
				player1flagAD = 2;
			if (GetAsyncKeyState('A') & 0x8000)
				player1flagAD = -2;
			if (GetAsyncKeyState('W') & 0x8000)
				player1flagW = 1;
			else
				player1flagW = 0;
			if (GetAsyncKeyState('J') & 0x8000)
				player1flagJ = 1;
			if (player1flagAD != -2 && player1flagAD != 2)
			{
				if (GetAsyncKeyState('L') & 0x8000)
					player1flagL = 1;
			}
			if (GetAsyncKeyState('K') & 0x8000)
			{
				if (player1flagK == 0)
				{
					player1old_y = player1_y;
					player1flagK = 1;
				}
				else if (player1flagK == 1 && jumpnum1 == 0)
				{
					player1flagK = 2;
					jumpnum1 = 1;
				}
			}
			if (player1flagAD != -2 && player1flagAD != 2 && player1flagK == 0)
			{
				if (GetAsyncKeyState('U') & 0x8000)
					player1flagU = 1;
				if (GetAsyncKeyState('I') & 0x8000)
					player1flagI = 1;
				if (GetAsyncKeyState('O') & 0x8000)
					player1flagO = 1;
			}
		}
	}
	if (player2flagbt == 0)
	{
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			player2flagS = 1;
		if (player2flagS == 0 && player2flagU == 0 && player2flagI == 0 && player2flagO == 0 && player2flagL == 0)
		{
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
				player2flagAD = 2;
			if (GetAsyncKeyState(VK_LEFT) & 0x8000)
				player2flagAD = -2;
			if (GetAsyncKeyState(VK_UP) & 0x8000)
				player2flagW = 1;
			else
				player2flagW = 0;
			if (GetAsyncKeyState(0x61) & 0x8000)
				player2flagJ = 1;
			if (player2flagAD != -2 && player2flagAD != 2)
			{
				if (GetAsyncKeyState(0x63) & 0x8000)
					player2flagL = 1;
			}
			if (GetAsyncKeyState(0x62) & 0x8000)
			{
				if (player2flagK == 0)
				{
					player2old_y = player2_y;
					player2flagK = 1;
				}
				else if (player2flagK == 1 && jumpnum2 == 0)
				{
					player2flagK = 2;
					jumpnum2 = 1;
				}
			}
			if (player2flagAD != -2 && player2flagAD != 2 && player1flagK == 0)
			{
				if (GetAsyncKeyState(0x64) & 0x8000)
					player2flagU = 1;
				if (GetAsyncKeyState(0x65) & 0x8000)
					player2flagI = 1;
				if (GetAsyncKeyState(0x66) & 0x8000)
					player2flagO = 1;
			}
		}
	}

	cleardevice();//清屏
	putimage(0, 0, WIDTH, HEIGHT, &img_bk, 0, 0);
	blood();
	player1();
	player2();

	FlushBatchDraw();//刷新屏幕

	// 检查玩家血量是否为零
	if (player1blood <= 0 || player2blood <= 0)
	{
		gameover(); // 调用游戏结束函数
		return;     // 退出循环，防止继续执行
	}

}
void updateWithoutInput()
{

}
//游戏结束函数
void gameover()
{
	putimage(250, 130, &img_gameover1, NOTSRCERASE);
	putimage(250, 130, &img_gameover2, SRCERASE);

	EndBatchDraw();
	_getch();
	Sleep(10000);//延时10秒自动退出终端
	closegraph();
	exit(0);
}
int main()
{
	initgraph(WIDTH, HEIGHT);
	/*start();*/
	BeginBatchDraw();

	//flagi = 1;
	startup();
	while (1)
	{
		show();
		updateWithoutInput();
		updateWithInput();
	}
	gameover();
	return 0;
}