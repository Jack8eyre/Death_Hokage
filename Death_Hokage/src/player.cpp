#include"..//game.h"
#include"..//player.h"


//玩家1的动作
void player1()
{
	static int player1i = 0;
	static int player1j = 0;
	static int player1left_i = 1, player1right_i = 1;
	static int player1k = 0;
	Sleep(25);
	if (player1flagK == 2)
	{
		player1flagK = 1;
		player1i = 0;
	}
	if (player1flagbt > 0)
	{
		player1flagJ = 0;
		player1flagL = 0;
		player1flagU = 0;
		player1flagS = 0;
		player1flagO = 0;
		if (player1flagAD > 0)
			player1flagAD = 1;
		else if (player1flagAD < 0)
			player1flagAD = -1;
		if (player1flagbt_dt == -1)
		{
			if (player1_x >= 30 && player1yz == 0)
				player1_x -= 30;
			putimage(player1_x, player1_y, 80, 120, &img_player1bt1, 0, 0, NOTSRCERASE);
			putimage(player1_x, player1_y, 80, 120, &img_player1bt2, 0, 0, SRCINVERT);
		}
		else if (player1flagbt_dt == 1)
		{
			if (player1_x <= 1390 && player1yz == 0)
				player1_x += 30;
			putimage(player1_x, player1_y, 80, 120, &img_player1bt1, 0, 120, NOTSRCERASE);
			putimage(player1_x, player1_y, 80, 120, &img_player1bt2, 0, 120, SRCINVERT);
		}
		player1yz++;
		if (player1yz == 5)
		{
			player1yz = 0;
			player1flagbt--;
		}

	}
	else if (player1flagK == 1)
	{
		if (player1flagAD == 2 && player1_x <= 1390)
			player1_x += 30;
		else if (player1flagAD == -2 && player1_x >= 30)
			player1_x -= 30;
		if (player1i < 5)
			player1_y -= 30;
		if (player1i >= 5)
			player1_y += 30;
		if (player1flagAD == 2)
		{
			putimage(player1_x, player1_y, 80, 120, &img_player1jp1, 0, 0, NOTSRCERASE);
			putimage(player1_x, player1_y, 80, 120, &img_player1jp2, 0, 0, SRCINVERT);
			player1flagAD = 1;
		}
		else if (player1flagAD == -2)
		{
			putimage(player1_x, player1_y, 80, 120, &img_player1jp1, 0, 120, NOTSRCERASE);
			putimage(player1_x, player1_y, 80, 120, &img_player1jp2, 0, 120, SRCINVERT);
			player1flagAD = -1;
		}
		if (player1flagJ == 1)
		{
			if (player1flagAD == 1)
			{
				putimage(player1_x, player1_y, 80, 120, &img_player1jf1, 0, 0, NOTSRCERASE);
				putimage(player1_x, player1_y, 80, 120, &img_player1jf2, 0, 0, SRCINVERT);
				if (player1_x <= player2_x + 60 && player1_x >= player2_x - 80 && player1_y <= player2_y + 80 && player1_y >= player2_y - 110 && (player2flagS == 0 || player2flagS == 1 && player1flagAD * player2flagAD > 0))
				{
					player2flagbt = 1;
					player2yz = 0;
					player2blood -= 5;
				}
				player2flagbt_dt = 1;
			}
			else if (player1flagAD == -1)
			{
				putimage(player1_x, player1_y, 80, 120, &img_player1jf1, 0, 120, NOTSRCERASE);
				putimage(player1_x, player1_y, 80, 120, &img_player1jf2, 0, 120, SRCINVERT);
				if (player1_x <= player2_x + 80 && player1_x >= player2_x - 60 && player1_y <= player2_y + 80 && player1_y >= player2_y - 110 && (player2flagS == 0 || player2flagS == 1 && player1flagAD * player2flagAD > 0))
				{
					player2flagbt = 1;
					player2yz = 0;
					player2blood -= 5;
				}
				player2flagbt_dt = -1;
			}
			player1flagJ = 0;
		}
		else if (player1flagAD == 1)
		{
			putimage(player1_x, player1_y, 80, 120, &img_player1jp1, 0, 0, NOTSRCERASE);
			putimage(player1_x, player1_y, 80, 120, &img_player1jp2, 0, 0, SRCINVERT);
		}
		else if (player1flagAD == -1)
		{
			putimage(player1_x, player1_y, 80, 120, &img_player1jp1, 0, 120, NOTSRCERASE);
			putimage(player1_x, player1_y, 80, 120, &img_player1jp2, 0, 120, SRCINVERT);
		}
		player1i++;
		if (player1old_y == player1_y)
		{
			player1i = 0;
			player1flagK = 0;
			if (player1flagAD == 1)
			{
				putimage(player1_x, player1_y, 80, 120, &img_player1walk1, 0, 0, NOTSRCERASE);
				putimage(player1_x, player1_y, 80, 120, &img_player1walk2, 0, 0, SRCINVERT);
			}
			if (player1flagAD == -1)
			{
				putimage(player1_x, player1_y, 80, 120, &img_player1walk1, 240, 120, NOTSRCERASE);
				putimage(player1_x, player1_y, 80, 120, &img_player1walk2, 240, 120, SRCINVERT);
			}
			jumpnum1 = 0;
		}
		if (player1flagS == 1)
			player1flagS = 0;
		if (player1flagL == 1)
			player1flagL = 0;
	}
	else if (player1flagO == 1)
	{
		static int k = -1, l = 1, i = 11;
		if (player1flagAD == 1)
		{
			if (k == -1)
			{
				player1old_x = player1_x;
				k++;
			}
			if (i >= 0)
			{
				putimage(player1_x, player1_y, 80, 120, &img_player1sk31, 0, 0, NOTSRCERASE);
				putimage(player1_x, player1_y, 80, 120, &img_player1sk32, 0, 0, SRCINVERT);
				if (k == 0)
				{
					player1old_x += 100;
					putimage(player1old_x, player1_y - 150, 100, 270, &img_player1sk31, k * 100 + 80, 0, NOTSRCERASE);
					putimage(player1old_x, player1_y - 150, 100, 270, &img_player1sk32, k * 100 + 80, 0, SRCINVERT);
					Sleep(25);
				}
				else if (k == 1)
				{
					putimage(player1old_x, player1_y - 150, 100, 270, &img_player1sk31, k * 100 + 80, 0, NOTSRCERASE);
					putimage(player1old_x, player1_y - 150, 100, 270, &img_player1sk32, k * 100 + 80, 0, SRCINVERT);
				}
				k++;
				if (k == 2)
					k = 0;
				if (player1old_x >= player2_x - 80 && player1old_x <= player2_x + 100 && player2_y >= player1_y - 270 && (player2flagS == 0 || player2flagS == 1 && player1flagAD * player2flagAD > 0))
				{
					player2flagbt = 1;
					player2yz = 0;
					player2blood -= 10;
				}
				player2flagbt_dt = 1;
				i--;
			}
			if (i == -1)
			{
				i = 11;
				k = -1;
				player1flagO = 0;
			}
		}
		else if (player1flagAD == -1)
		{
			if (k == -1)
			{
				player1old_x = player1_x;
				k++;
			}
			if (i >= 0)
			{
				putimage(player1_x, player1_y, 80, 120, &img_player1sk31, 0, 120, NOTSRCERASE);
				putimage(player1_x, player1_y, 80, 120, &img_player1sk32, 0, 120, SRCINVERT);
				if (k == 0)
				{
					player1old_x -= 100;
					putimage(player1old_x, player1_y - 150, 100, 270, &img_player1sk31, k * 100 + 80, 0, NOTSRCERASE);
					putimage(player1old_x, player1_y - 150, 100, 270, &img_player1sk32, k * 100 + 80, 0, SRCINVERT);
					Sleep(25);
				}
				else if (k == 1)
				{
					putimage(player1old_x, player1_y - 150, 100, 270, &img_player1sk31, k * 100 + 80, 0, NOTSRCERASE);
					putimage(player1old_x, player1_y - 150, 100, 270, &img_player1sk32, k * 100 + 80, 0, SRCINVERT);
				}
				k++;
				if (k == 2)
					k = 0;
				if (player1old_x >= player2_x - 80 && player1old_x <= player2_x + 100 && player2_y >= player1_y - 270 && (player2flagS == 0 || player2flagS == 1 && player1flagAD * player2flagAD > 0))
				{
					player2flagbt = 1;
					player2yz = 0;
					player2blood -= 10;
				}
				player2flagbt_dt = -1;
				i--;
			}
			if (i == -1)
			{
				i = 11;
				k = -1;
				player1flagO = 0;
			}
		}
	}
	else if (player1flagI == 1)
	{
		static int k = 0, l = 9;
		if (player1flagAD == 1)
		{
			if (k == 0)
				player1old_x = player1_x;
			if (k <= 4)
			{
				putimage(player1_x, player1_y, 80, 120, &img_player1sk21, k * 80, 0, NOTSRCERASE);
				putimage(player1_x, player1_y, 80, 120, &img_player1sk22, k * 80, 0, SRCINVERT);
			}
			else if (k <= 6)
			{
				if (player1_x <= 1220)
					player1_x += 200;
				else
					player1_x = 1420;
				putimage(player1_x, player1_y, 80, 120, &img_player1sk21, k * 80, 0, NOTSRCERASE);
				putimage(player1_x, player1_y, 80, 120, &img_player1sk22, k * 80, 0, SRCINVERT);
				if (player2_x >= player1old_x && player2_x <= player1old_x + 400 && player2_y >= player1_y - 120 && (player2flagS == 0 || player2flagS == 1 && player1flagAD * player2flagAD > 0))
				{
					player2flagbt = 1;
					player2yz = 0;
					player2blood -= 30;
				}
				player2flagbt_dt = 1;
			}
			else if (k <= 8)
			{
				putimage(player1_x, player1_y, 80, 120, &img_player1sk21, k * 80, 0, NOTSRCERASE);
				putimage(player1_x, player1_y, 80, 120, &img_player1sk22, k * 80, 0, SRCINVERT);
			}
			k++;
			if (k == 9)
			{
				putimage(player1_x, player1_y, 80, 120, &img_player1sk21, k * 80, 0, NOTSRCERASE);
				putimage(player1_x, player1_y, 80, 120, &img_player1sk22, k * 80, 0, SRCINVERT);
				Sleep(25);
				k = 0;
				player1flagI = 0;
			}
		}
		else if (player1flagAD == -1)
		{
			if (l == 9)
				player1old_x = player1_x;
			if (l >= 5)
			{
				putimage(player1_x, player1_y, 80, 120, &img_player1sk21, l * 80, 120, NOTSRCERASE);
				putimage(player1_x, player1_y, 80, 120, &img_player1sk22, l * 80, 120, SRCINVERT);
			}
			else if (l >= 3)
			{
				if (player1_x >= 200)
					player1_x -= 200;
				else
					player1_x = 0;
				putimage(player1_x, player1_y, 80, 120, &img_player1sk21, l * 80, 120, NOTSRCERASE);
				putimage(player1_x, player1_y, 80, 120, &img_player1sk22, l * 80, 120, SRCINVERT);
				if (player2_x <= player1old_x && player2_x >= player1old_x - 400 && player2_y >= player1_y - 120 && (player2flagS == 0 || player2flagS == 1 && player1flagAD * player2flagAD > 0))
				{
					player2flagbt = 1;
					player2yz = 0;
					player2blood -= 30;
				}
				player2flagbt_dt = -1;
			}
			else if (l >= 1)
			{
				putimage(player1_x, player1_y, 80, 120, &img_player1sk21, l * 80, 120, NOTSRCERASE);
				putimage(player1_x, player1_y, 80, 120, &img_player1sk22, l * 80, 120, SRCINVERT);
			}
			l--;
			if (l == 0)
			{
				putimage(player1_x, player1_y, 80, 120, &img_player1sk21, l * 80, 0, NOTSRCERASE);
				putimage(player1_x, player1_y, 80, 120, &img_player1sk22, l * 80, 0, SRCINVERT);
				Sleep(25);
				l = 9;
				player1flagI = 0;
			}
		}
	}
	else if (player1flagU == 1)
	{
		static int k = 0, l = 3;
		if (player1flagAD == 1)
		{
			putimage(player1_x, player1_y, 80, 120, &img_player1sk11, k * 80, 0, NOTSRCERASE);
			putimage(player1_x, player1_y, 80, 120, &img_player1sk12, k * 80, 0, SRCINVERT);
			k++;
			if (k == 3)
			{
				if (player1_x < player2_x)
					player1_x = player2_x;
				putimage(player1_x, player1_y, 80, 120, &img_player1sk11, k * 80, 0, NOTSRCERASE);
				putimage(player1_x, player1_y, 80, 120, &img_player1sk12, k * 80, 0, SRCINVERT);
				Sleep(25);
				if (player1_x <= player2_x + 60 && player1_x >= player2_x - 80 && player1_y <= player2_y + 80 && player1_y >= player2_y - 110 && (player2flagS == 0 || player2flagS == 1 && player1flagAD * player2flagAD > 0))
				{
					player2flagbt = 1;
					player2yz = 0;
					player2blood -= 10;
				}
				player2flagbt_dt = 1;
				k = 0;
				player1flagU = 0;
			}
		}
		else if (player1flagAD == -1)
		{
			putimage(player1_x, player1_y, 80, 120, &img_player1sk11, l * 80, 120, NOTSRCERASE);
			putimage(player1_x, player1_y, 80, 120, &img_player1sk12, l * 80, 120, SRCINVERT);
			l--;
			if (l == 0)
			{
				if (player1_x > player2_x)
					player1_x = player2_x;
				putimage(player1_x, player1_y, 80, 120, &img_player1sk11, l * 80, 120, NOTSRCERASE);
				putimage(player1_x, player1_y, 80, 120, &img_player1sk12, l * 80, 120, SRCINVERT);
				Sleep(25);
				if (player1_x <= player2_x + 80 && player1_x >= player2_x - 60 && player1_y <= player2_y + 80 && player1_y >= player2_y - 110 && (player2flagS == 0 || player2flagS == 1 && player1flagAD * player2flagAD > 0))
				{
					player2flagbt = 1;
					player2yz = 0;
					player2blood -= 10;
				}
				player2flagbt_dt = -1;
				l = 3;
				player1flagU = 0;
			}
		}
	}
	else if (player1flagL == 1)
	{
		if (player1flagAD == 1)
		{
			putimage(player1_x, player1_y, 80, 120, &img_player1dg1, 0, 0, NOTSRCERASE);
			putimage(player1_x, player1_y, 80, 120, &img_player1dg2, 0, 0, SRCINVERT);
			Sleep(25);
		}
		else if (player1flagAD == -1)
		{
			putimage(player1_x, player1_y, 80, 120, &img_player1dg1, 0, 120, NOTSRCERASE);
			putimage(player1_x, player1_y, 80, 120, &img_player1dg2, 0, 120, SRCINVERT);
			Sleep(25);
		}
		if (player1k == 0)
		{
			if (player1flagAD == 1)
			{
				if (player1_x <= 1120)
					player1_x += 300;
				else
					player1_x = 1420;
			}
			else if (player1flagAD == -1)
			{

				if (player1_x >= 300)
					player1_x -= 300;
				else
					player1_x = 0;
			}
			player1k++;
		}
		else if (player1k == 1)
		{
			player1k = 0;
			player1flagL = 0;
		}
	}
	else if (player1flagK == 0)
	{
		if (player1flagJ == 0)
			player1j = 0;
		if (player1flagS == 1)
		{
			if (player1flagAD == 1)
			{
				putimage(player1_x, player1_y, 80, 120, &img_player1df1, 0, 0, NOTSRCERASE);
				putimage(player1_x, player1_y, 80, 120, &img_player1df2, 0, 0, SRCINVERT);
			}
			else if (player1flagAD == -1)
			{
				putimage(player1_x, player1_y, 80, 120, &img_player1df1, 0, 120, NOTSRCERASE);
				putimage(player1_x, player1_y, 80, 120, &img_player1df2, 0, 120, SRCINVERT);
			}
			player1flagS = 0;
		}
		else if (player1flagJ == 1)
		{
			static int k = 0, l = 2;
			if (player1j == 0)
			{
				if (player1flagAD == 1)
				{
					putimage(player1_x, player1_y, 80, 120, &img_player1ft11, k * 80, 0, NOTSRCERASE);
					putimage(player1_x, player1_y, 80, 120, &img_player1ft12, k * 80, 0, SRCINVERT);
					Sleep(15);
					if (k == 1 && player1_x <= player2_x + 60 && player1_x >= player2_x - 80 && player1_y <= player2_y + 80 && player1_y >= player2_y - 110 && (player2flagS == 0 || player2flagS == 1 && player1flagAD * player2flagAD > 0))
					{
						player2flagbt = 1;
						player2yz = 0;
						player2blood -= 10;
					}
					player2flagbt_dt = 1;
					k++;
				}
				else if (player1flagAD == -1)
				{
					putimage(player1_x, player1_y, 80, 120, &img_player1ft11, l * 80, 120, NOTSRCERASE);
					putimage(player1_x, player1_y, 80, 120, &img_player1ft12, l * 80, 120, SRCINVERT);
					Sleep(15);
					if (l == 1 && player1_x <= player2_x + 80 && player1_x >= player2_x - 60 && player1_y <= player2_y + 80 && player1_y >= player2_y - 110 && (player2flagS == 0 || player2flagS == 1 && player1flagAD * player2flagAD > 0))
					{
						player2flagbt = 1;
						player2yz = 0;
						player2blood -= 10;
					}
					player2flagbt_dt = -1;
					l--;
				}
			}
			else if (player1j == 1)
			{
				if (player1flagAD == 1)
				{
					putimage(player1_x, player1_y, 80, 120, &img_player1ft21, k * 80, 0, NOTSRCERASE);
					putimage(player1_x, player1_y, 80, 120, &img_player1ft22, k * 80, 0, SRCINVERT);
					Sleep(15);
					if (k == 1 && player1_x <= player2_x + 60 && player1_x >= player2_x - 80 && player1_y <= player2_y + 80 && player1_y >= player2_y - 110 && (player2flagS == 0 || player2flagS == 1 && player1flagAD * player2flagAD > 0))
					{
						player2flagbt = 1;
						player2yz = 0;
						player2blood -= 10;
					}
					player2flagbt_dt = 1;
					k++;
				}
				else if (player1flagAD == -1)
				{
					putimage(player1_x, player1_y, 80, 120, &img_player1ft21, l * 80, 120, NOTSRCERASE);
					putimage(player1_x, player1_y, 80, 120, &img_player1ft22, l * 80, 120, SRCINVERT);
					Sleep(15);
					if (l == 1 && player1_x <= player2_x + 80 && player1_x >= player2_x - 60 && player1_y <= player2_y + 80 && player1_y >= player2_y - 110 && (player2flagS == 0 || player2flagS == 1 && player1flagAD * player2flagAD > 0))
					{
						player2flagbt = 1;
						player2yz = 0;
						player2blood -= 10;
					}
					player2flagbt_dt = -1;
					l--;
				}
			}
			else if (player1j == 2)
			{
				if (player1flagAD == 1)
				{
					putimage(player1_x, player1_y, 80, 120, &img_player1ft31, k * 80, 0, NOTSRCERASE);
					putimage(player1_x, player1_y, 80, 120, &img_player1ft32, k * 80, 0, SRCINVERT);
					Sleep(15);
					if (k == 1 && player1_x <= player2_x + 60 && player1_x >= player2_x - 80 && player1_y <= player2_y + 80 && player1_y >= player2_y - 110 && (player2flagS == 0 || player2flagS == 1 && player1flagAD * player2flagAD > 0))
					{
						player2flagbt = 1;
						player2yz = 0;
						player2blood -= 10;
					}
					player2flagbt_dt = 1;
					k++;
				}
				else if (player1flagAD == -1)
				{
					putimage(player1_x, player1_y, 80, 120, &img_player1ft31, l * 80, 120, NOTSRCERASE);
					putimage(player1_x, player1_y, 80, 120, &img_player1ft32, l * 80, 120, SRCINVERT);
					Sleep(15);
					if (l == 1 && player1_x <= player2_x + 80 && player1_x >= player2_x - 60 && player1_y <= player2_y + 80 && player1_y >= player2_y - 110 && (player2flagS == 0 || player2flagS == 1 && player1flagAD * player2flagAD > 0))
					{
						player2flagbt = 1;
						player2yz = 0;
						player2blood -= 10;
					}
					player2flagbt_dt = -1;
					l--;
				}
			}
			if (k == 3)
			{
				player1flagJ = 0;
				player1j++;
				k = 0;
			}
			if (l == -1)
			{
				player1flagJ = 0;
				player1j++;
				l = 2;
			}
			if (player1j == 3)
				player1j = 0;
		}
		else if (player1flagAD == 1)
		{
			putimage(player1_x, player1_y, 80, 120, &img_player1walk1, 0, 0, NOTSRCERASE);
			putimage(player1_x, player1_y, 80, 120, &img_player1walk2, 0, 0, SRCINVERT);
		}
		else if (player1flagAD == -1)
		{
			putimage(player1_x, player1_y, 80, 120, &img_player1walk1, 240, 120, NOTSRCERASE);
			putimage(player1_x, player1_y, 80, 120, &img_player1walk2, 240, 120, SRCINVERT);
		}
		if (player1flagAD == 2)
		{
			if (player1_x <= 1390)
				player1_x += 30;
			player1left_i++;
			if (player1left_i == 3)
				player1left_i = 1;
			putimage(player1_x, player1_y, 80, 120, &img_player1walk1, player1left_i * 80, 0, NOTSRCERASE);
			putimage(player1_x, player1_y, 80, 120, &img_player1walk2, player1left_i * 80, 0, SRCINVERT);
			player1flagAD = 1;
		}
		else if (player1flagAD == -2)
		{
			if (player1_x >= 30)
				player1_x -= 30;
			player1right_i++;
			if (player1right_i == 3)
				player1right_i = 1;
			putimage(player1_x, player1_y, 80, 120, &img_player1walk1, player1right_i * 80, 120, NOTSRCERASE);
			putimage(player1_x, player1_y, 80, 120, &img_player1walk2, player1right_i * 80, 120, SRCINVERT);
			player1flagAD = -1;
		}
		if (player1flagL == 1)
			player1flagL = 0;
	}
}
//玩家2的动作
void player2()
{
	static int player2i = 0;
	static int player2j = 0;
	static int player2left_i = 1, player2right_i = 1;
	static int player2k = 0;
	Sleep(25);
	if (player2flagK == 2)
	{
		player2flagK = 1;
		player2i = 0;
	}
	if (player2flagbt > 0)
	{
		player2flagJ = 0;
		player2flagK = 0;
		player2flagL = 0;
		player2flagU = 0;
		player2flagS = 0;
		player2flagO = 0;
		if (player2flagAD > 0)
			player2flagAD = 1;
		else if (player2flagAD < 0)
			player2flagAD = -1;
		if (player2flagbt_dt == -1)
		{
			if (player2_x >= 30 && player2yz == 0)
				player2_x -= 30;
			putimage(player2_x, player2_y, 80, 120, &img_player2bt1, 0, 0, NOTSRCERASE);
			putimage(player2_x, player2_y, 80, 120, &img_player2bt2, 0, 0, SRCINVERT);
		}
		else if (player2flagbt_dt == 1)
		{
			if (player2_x <= 1390 && player2yz == 0)
				player2_x += 30;
			putimage(player2_x, player2_y, 80, 120, &img_player2bt1, 0, 120, NOTSRCERASE);
			putimage(player2_x, player2_y, 80, 120, &img_player2bt2, 0, 120, SRCINVERT);
		}
		player2yz++;
		if (player2yz == 5)
		{
			player2flagbt--;
			player2yz = 0;
		}

	}
	else if (player2flagK == 1)
	{
		static int k = 0, l = 0, skill_x = 0, skill_y = 0;
		if (player2flagAD == 2 && player2_x <= 1390)
			player2_x += 30;
		else if (player2flagAD == -2 && player2_x >= 30)
			player2_x -= 30;
		if (player2i < 5)
			player2_y -= 30;
		if (player2i >= 5)
			player2_y += 30;
		if (player2flagAD == 2)
		{
			putimage(player2_x, player2_y, 80, 120, &img_player2jp1, 0, 0, NOTSRCERASE);
			putimage(player2_x, player2_y, 80, 120, &img_player2jp2, 0, 0, SRCINVERT);
			player2flagAD = 1;
		}
		else if (player2flagAD == -2)
		{
			putimage(player2_x, player2_y, 80, 120, &img_player2jp1, 0, 120, NOTSRCERASE);
			putimage(player2_x, player2_y, 80, 120, &img_player2jp2, 0, 120, SRCINVERT);
			player2flagAD = -1;
		}
		if (player2flagJ == 1 && k == 0)
		{
			if (player2flagAD == 1)
			{
				putimage(player2_x, player2_y, 80, 120, &img_player2jf1, 0, 0, NOTSRCERASE);
				putimage(player2_x, player2_y, 80, 120, &img_player2jf2, 0, 0, SRCINVERT);
				if (player2_x <= player1_x + 60 && player2_x >= player1_x - 80 && player2_y <= player1_y + 80 && player2_y >= player1_y - 110 && (player1flagS == 0 || player1flagS == 1 && player1flagAD * player2flagAD > 0))
				{
					player1flagbt = 1;
					player1yz = 0;
					player1blood -= 5;
				}
				l = 1;
				skill_x = player2_x;
				skill_y = player2_y;
				skill_x += 80;
				k++;
				player1flagbt_dt = 1;
			}
			else if (player2flagAD == -1)
			{
				putimage(player2_x, player2_y, 80, 120, &img_player2jf1, 360, 120, NOTSRCERASE);
				putimage(player2_x, player2_y, 80, 120, &img_player2jf2, 360, 120, SRCINVERT);
				if (player2_x <= player1_x + 80 && player2_x >= player1_x - 60 && player2_y <= player1_y + 80 && player2_y >= player1_y - 110 && (player1flagS == 0 || player1flagS == 1 && player1flagAD * player2flagAD > 0))
				{
					player1flagbt = 1;
					player1yz = 0;
					player1blood -= 5;
				}
				l = -1;
				skill_x = player2_x;
				skill_y = player2_y;
				skill_x -= 100;
				k++;
				player1flagbt_dt = -1;
			}
			player2flagJ = 0;
		}
		else if (player2flagAD == 1)
		{
			putimage(player2_x, player2_y, 80, 120, &img_player2jp1, 0, 0, NOTSRCERASE);
			putimage(player2_x, player2_y, 80, 120, &img_player2jp2, 0, 0, SRCINVERT);
		}
		else if (player2flagAD == -1)
		{
			putimage(player2_x, player2_y, 80, 120, &img_player2jp1, 0, 120, NOTSRCERASE);
			putimage(player2_x, player2_y, 80, 120, &img_player2jp2, 0, 120, SRCINVERT);
		}
		player2i++;
		if (player2_y == player2old_y)
		{
			player2i = 0;
			player2flagK = 0;
			if (player2flagAD == 1)
			{
				putimage(player2_x, player2_y, 80, 120, &img_player2walk1, 0, 0, NOTSRCERASE);
				putimage(player2_x, player2_y, 80, 120, &img_player2walk2, 0, 0, SRCINVERT);
			}
			if (player2flagAD == -1)
			{
				putimage(player2_x, player2_y, 80, 120, &img_player2walk1, 160, 120, NOTSRCERASE);
				putimage(player2_x, player2_y, 80, 120, &img_player2walk2, 160, 120, SRCINVERT);
			}
			jumpnum2 = 0;
		}
		if (player2flagS == 1)
			player2flagS = 0;
		if (player2flagL == 1)
			player2flagL = 0;
		if (k != 0)
		{
			if (l == 1)
			{
				putimage(skill_x, skill_y, 120, 120, &img_player2jf1, 80 + (k - 1) * 120, 0, NOTSRCERASE);
				putimage(skill_x, skill_y, 120, 120, &img_player2jf2, 80 + (k - 1) * 120, 0, SRCINVERT);
				if (k == 1 && skill_x <= player1_x + 80 && skill_x >= player1_x - 120 && skill_y <= player1_y + 120 && skill_y >= player1_y - 120 && (player1flagS == 0 || player1flagS == 1 && player1flagAD * player2flagAD > 0))
				{
					player1flagbt = 1;
					player1yz = 0;
					player1blood -= 5;
				}
				player1flagbt_dt = 1;
			}
			else if (l == -1)
			{
				putimage(skill_x, skill_y, 120, 120, &img_player2jf1, 360 - k * 120, 120, NOTSRCERASE);
				putimage(skill_x, skill_y, 120, 120, &img_player2jf2, 360 - k * 120, 120, SRCINVERT);
				if (k == 1 && skill_x <= player1_x + 80 && skill_x >= player1_x - 120 && skill_y <= player1_y + 120 && skill_y >= player1_y - 120 && (player1flagS == 0 || player1flagS == 1 && player1flagAD * player2flagAD > 0))
				{
					player1flagbt = 1;
					player1yz = 0;
					player1blood -= 5;
				}
				player1flagbt_dt = -1;
			}
			k++;
			if (k == 4)
				k = 0;
			player2flagJ = 0;
		}
	}
	else if (player2flagO == 1)
	{
		static int k = -1, j = 0;
		if (player2flagAD == 1)
		{
			if (j <= 4)
			{
				if (k == -1)
				{
					k++;
					player2old_x = player2_x - 10;
					player1flagbt_dt = 1;
				}
				if (k == 5)
					player2old_x += 150;
				if (k <= 3)
				{
					putimage(player2_x, player2_y, 80, 120, &img_player2sk31, k * 80, 0, NOTSRCERASE);
					putimage(player2_x, player2_y, 80, 120, &img_player2sk32, k * 80, 0, SRCINVERT);
				}
				else if (k == 4)
				{
					putimage(player2_x + 10, player2_y, 130, 120, &img_player2sk31, 320, 0, NOTSRCERASE);
					putimage(player2_x + 10, player2_y, 130, 120, &img_player2sk32, 320, 0, SRCINVERT);
				}
				else
				{
					putimage(player2_x + 10, player2_y, 130, 120, &img_player2sk31, 320, 0, NOTSRCERASE);
					putimage(player2_x + 10, player2_y, 130, 120, &img_player2sk32, 320, 0, SRCINVERT);
					putimage(player2old_x, player2_y - 100, 200, 300, &img_player2sk31, 450 + (k - 5) * 200, 0, NOTSRCERASE);
					putimage(player2old_x, player2_y - 100, 200, 300, &img_player2sk32, 450 + (k - 5) * 200, 0, SRCINVERT);
					if (player2old_x >= player1_x - 150 && player2old_x <= player1_x + 50 && player1_y >= player2_y - 200 && (player1flagS == 0 || player1flagS == 1 && player1flagAD * player2flagAD > 0))
					{
						player1flagbt = 1;
						player1yz = 0;
						player1blood -= 5;
					}
				}
				k++;
				if (k == 15)
				{
					k = 5;
					j++;
				}
			}
			if (j == 2)
			{
				k = -1;
				j = 0;
				player2flagO = 0;
			}
		}
		else if (player2flagAD == -1)
		{
			if (j <= 4)
			{
				if (k == -1)
				{
					k++;
					player2old_x = player2_x - 100;
					player1flagbt_dt = -1;
				}
				if (k == 5)
					player2old_x -= 150;
				if (k <= 3)
				{
					putimage(player2_x, player2_y, 80, 120, &img_player2sk31, 2370 - k * 80, 300, NOTSRCERASE);
					putimage(player2_x, player2_y, 80, 120, &img_player2sk32, 2370 - k * 80, 300, SRCINVERT);
				}
				else if (k == 4)
				{
					putimage(player2_x - 60, player2_y, 130, 120, &img_player2sk31, 2000, 300, NOTSRCERASE);
					putimage(player2_x - 60, player2_y, 130, 120, &img_player2sk32, 2000, 300, SRCINVERT);
				}
				else
				{
					putimage(player2_x - 60, player2_y, 130, 120, &img_player2sk31, 2000, 300, NOTSRCERASE);
					putimage(player2_x - 60, player2_y, 130, 120, &img_player2sk32, 2000, 300, SRCINVERT);
					putimage(player2old_x, player2_y - 100, 200, 300, &img_player2sk31, 2000 - (k - 4) * 200, 300, NOTSRCERASE);
					putimage(player2old_x, player2_y - 100, 200, 300, &img_player2sk32, 2000 - (k - 4) * 200, 300, SRCINVERT);
					if (player2old_x >= player1_x - 150 && player2old_x <= player1_x + 50 && player1_y >= player2_y - 200 && (player1flagS == 0 || player1flagS == 1 && player1flagAD * player2flagAD > 0))
					{
						player1flagbt = 1;
						player1yz = 0;
						player1blood -= 5;
					}
				}
				k++;
				if (k == 15)
				{
					k = 5;
					j++;
				}
			}
			if (j == 2)
			{
				k = -1;
				j = 0;
				player2flagO = 0;
			}
		}
	}
	else if (player2flagI == 1)
	{
		static int k = -1;
		if (player2flagAD == 1)
		{
			if (k == -1)
			{
				k++;
				player1flagbt_dt = 1;
			}
			if (k == 0)
			{
				putimage(player2_x, player2_y - 20, 80, 140, &img_player2sk21, 0, 0, NOTSRCERASE);
				putimage(player2_x, player2_y - 20, 80, 140, &img_player2sk22, 0, 0, SRCINVERT);
			}
			else if (k == 1)
			{
				putimage(player2_x - 90, player2_y - 20, 160, 140, &img_player2sk21, 80, 0, NOTSRCERASE);
				putimage(player2_x - 90, player2_y - 20, 160, 140, &img_player2sk22, 80, 0, SRCINVERT);
			}
			else if (k == 2)
			{
				putimage(player2_x - 90, player2_y - 20, 270, 140, &img_player2sk21, 240, 0, NOTSRCERASE);
				putimage(player2_x - 90, player2_y - 20, 270, 140, &img_player2sk22, 240, 0, SRCINVERT);
				if (player2_x >= player1_x - 180 && player2_x <= player1_x + 90 && player1_y >= player2_y - 110 && (player1flagS == 0 || player1flagS == 1 && player1flagAD * player2flagAD > 0))
				{
					player1flagbt = 1;
					player1yz = 0;
					player1blood -= 20;
				}
			}
			else if (k == 3)
			{
				putimage(player2_x + 25, player2_y - 20, 160, 140, &img_player2sk21, 510, 0, NOTSRCERASE);
				putimage(player2_x + 25, player2_y - 20, 160, 140, &img_player2sk22, 510, 0, SRCINVERT);
				if (player2_x >= player1_x - 95 && player2_x <= player1_x + 55 && player1_y >= player2_y - 110 && (player1flagS == 0 || player1flagS == 1 && player1flagAD * player2flagAD > 0))
				{
					player1flagbt = 1;
					player1yz = 0;
					player1blood -= 20;
				}
			}
			else if (k == 4)
			{
				putimage(player2_x, player2_y - 20, 80, 140, &img_player2sk21, 670, 0, NOTSRCERASE);
				putimage(player2_x, player2_y - 20, 80, 140, &img_player2sk22, 670, 0, SRCINVERT);
			}
			Sleep(15);
			k++;
			if (k == 5)
			{
				k = -1;
				player2flagI = 0;
			}
		}
		else if (player2flagAD == -1)
		{
			if (k == -1)
			{
				k++;
				player1flagbt_dt = -1;
			}
			if (k == 0)
			{
				putimage(player2_x, player2_y - 20, 80, 140, &img_player2sk21, 670, 140, NOTSRCERASE);
				putimage(player2_x, player2_y - 20, 80, 140, &img_player2sk22, 670, 140, SRCINVERT);
			}
			else if (k == 1)
			{
				putimage(player2_x + 10, player2_y - 20, 160, 140, &img_player2sk21, 510, 140, NOTSRCERASE);
				putimage(player2_x + 10, player2_y - 20, 160, 140, &img_player2sk22, 510, 140, SRCINVERT);
			}
			else if (k == 2)
			{
				putimage(player2_x - 100, player2_y - 20, 270, 140, &img_player2sk21, 240, 140, NOTSRCERASE);
				putimage(player2_x - 100, player2_y - 20, 270, 140, &img_player2sk22, 240, 140, SRCINVERT);
				if (player2_x >= player1_x - 150 && player2_x <= player1_x + 180 && player1_y >= player2_y - 110 && (player1flagS == 0 || player1flagS == 1 && player1flagAD * player2flagAD > 0))
				{
					player1flagbt = 1;
					player1yz = 0;
					player1blood -= 20;
				}
			}
			else if (k == 3)
			{
				putimage(player2_x - 105, player2_y - 20, 160, 140, &img_player2sk21, 80, 140, NOTSRCERASE);
				putimage(player2_x - 105, player2_y - 20, 160, 140, &img_player2sk22, 80, 140, SRCINVERT);
				if (player2_x >= player1_x - 20 && player2_x <= player1_x + 120 && player1_y >= player2_y - 110 && (player1flagS == 0 || player1flagS == 1 && player1flagAD * player2flagAD > 0))
				{
					player1flagbt = 1;
					player1yz = 0;
					player1blood -= 20;
				}
			}
			else if (k == 4)
			{
				putimage(player2_x, player2_y - 20, 80, 140, &img_player2sk21, 0, 140, NOTSRCERASE);
				putimage(player2_x, player2_y - 20, 80, 140, &img_player2sk22, 0, 140, SRCINVERT);
			}
			Sleep(15);
			k++;
			if (k == 5)
			{
				k = -1;
				player2flagI = 0;
			}
		}
	}
	else if (player2flagU == 1)
	{
		static int k = -1;
		if (player2flagAD == 1)
		{
			if (k == -1)
			{
				player2old_x = player2_x;
				player1flagbt_dt = 1;
				k++;
			}
			if (k <= 7)
			{
				putimage(player2_x, player2_y, 80, 120, &img_player2sk11, k * 80, 0, NOTSRCERASE);
				putimage(player2_x, player2_y, 80, 120, &img_player2sk12, k * 80, 0, SRCINVERT);
			}
			else if (k <= 18)
			{
				player2old_x += 50;
				putimage(player2_x, player2_y, 80, 120, &img_player2sk11, 560, 0, NOTSRCERASE);
				putimage(player2_x, player2_y, 80, 120, &img_player2sk12, 560, 0, SRCINVERT);

				putimage(player2old_x, player2_y, 100, 100, &img_player2sk11, 640 + (k - 8) * 100, 0, NOTSRCERASE);
				putimage(player2old_x, player2_y, 100, 100, &img_player2sk12, 640 + (k - 8) * 100, 0, SRCINVERT);
				if (player2old_x >= player1_x - 100 && player2old_x <= player1_x + 80 && player1_y >= player2_y - 120 && (player1flagS == 0 || player1flagS == 1 && player1flagAD * player2flagAD > 0))
				{
					player1flagbt = 1;
					player1yz = 0;
					player1blood -= 10;
				}

			}
			else
			{
				putimage(player2_x, player2_y, 80, 120, &img_player2sk11, 560, 0, NOTSRCERASE);
				putimage(player2_x, player2_y, 80, 120, &img_player2sk12, 560, 0, SRCINVERT);

				putimage(player2old_x, player2_y - 280, 300, 400, &img_player2sk11, 1740 + (k - 19) * 300, 0, NOTSRCERASE);
				putimage(player2old_x, player2_y - 280, 300, 400, &img_player2sk12, 1740 + (k - 19) * 300, 0, SRCINVERT);
				if (player2old_x >= player1_x - 300 && player2old_x <= player1_x + 80 && player1_y >= player2_y - 400 && (player1flagS == 0 || player1flagS == 1 && player1flagAD * player2flagAD > 0))
				{
					player1flagbt = 1;
					player1yz = 0;
					player1blood -= 10;
				}
			}
			k++;
			if (k == 22)
			{
				k = -1;
				player2flagU = 0;
			}
		}
		else if (player2flagAD == -1)
		{
			if (k == -1)
			{
				player2old_x = player2_x;
				player1flagbt_dt = -1;
				k++;
			}
			if (k <= 7)
			{
				putimage(player2_x, player2_y, 80, 120, &img_player2sk11, 560 - k * 80, 120, NOTSRCERASE);
				putimage(player2_x, player2_y, 80, 120, &img_player2sk12, 560 - k * 80, 120, SRCINVERT);
			}
			else if (k <= 18)
			{
				player2old_x -= 50;
				putimage(player2_x, player2_y, 80, 120, &img_player2sk11, 0, 120, NOTSRCERASE);
				putimage(player2_x, player2_y, 80, 120, &img_player2sk12, 0, 120, SRCINVERT);

				putimage(player2old_x, player2_y, 100, 100, &img_player2sk11, 2540 - (k - 8) * 100, 400, NOTSRCERASE);
				putimage(player2old_x, player2_y, 100, 100, &img_player2sk12, 2540 - (k - 8) * 100, 400, SRCINVERT);
				if (player2old_x >= player1_x - 100 && player2old_x <= player1_x + 80 && player1_y >= player2_y - 120 && (player1flagS == 0 || player1flagS == 1 && player1flagAD * player2flagAD > 0))
				{
					player1flagbt = 1;
					player1yz = 0;
					player1blood -= 10;
				}
			}
			else
			{
				if (k == 19)
					player2old_x -= 200;
				putimage(player2_x, player2_y, 80, 120, &img_player2sk11, 0, 120, NOTSRCERASE);
				putimage(player2_x, player2_y, 80, 120, &img_player2sk12, 0, 120, SRCINVERT);

				putimage(player2old_x, player2_y - 280, 300, 400, &img_player2sk11, 1540 - (k - 18) * 300, 400, NOTSRCERASE);
				putimage(player2old_x, player2_y - 280, 300, 400, &img_player2sk12, 1540 - (k - 18) * 300, 400, SRCINVERT);
				if (player2old_x >= player1_x - 300 && player2old_x <= player1_x + 80 && player1_y >= player2_y - 400 && (player1flagS == 0 || player1flagS == 1 && player1flagAD * player2flagAD > 0))
				{
					player1flagbt = 1;
					player1yz = 0;
					player1blood -= 10;
				}
			}
			k++;
			if (k == 22)
			{
				k = -1;
				player2flagU = 0;
			}

		}
	}
	else if (player2flagL == 1)
	{
		if (player2flagAD == 1)
		{
			putimage(player2_x, player2_y, 80, 120, &img_player2dg1, 0, 0, NOTSRCERASE);
			putimage(player2_x, player2_y, 80, 120, &img_player2dg2, 0, 0, SRCINVERT);
			Sleep(25);
		}
		else if (player2flagAD == -1)
		{
			putimage(player2_x, player2_y, 80, 120, &img_player2dg1, 0, 120, NOTSRCERASE);
			putimage(player2_x, player2_y, 80, 120, &img_player2dg2, 0, 120, SRCINVERT);
			Sleep(25);
		}
		if (player2k == 0)
		{
			if (player2flagAD == 1)
			{
				if (player2_x <= 1120)
					player2_x += 300;
				else
					player2_x = 1420;
			}
			else if (player2flagAD == -1)
			{
				if (player2_x >= 300)
					player2_x -= 300;
				else
					player2_x = 0;
			}
			player2k++;
		}
		else if (player2k == 1)
		{
			player2k = 0;
			player2flagL = 0;
		}
	}
	else if (player2flagK == 0)
	{
		if (player2flagJ == 0)
			player2j = 0;
		if (player2flagS == 1)
		{
			if (player2flagAD == 1)
			{
				putimage(player2_x, player2_y, 80, 120, &img_player2df1, 0, 0, NOTSRCERASE);
				putimage(player2_x, player2_y, 80, 120, &img_player2df2, 0, 0, SRCINVERT);
			}
			else if (player2flagAD == -1)
			{
				putimage(player2_x, player2_y, 80, 120, &img_player2df1, 0, 120, NOTSRCERASE);
				putimage(player2_x, player2_y, 80, 120, &img_player2df2, 0, 120, SRCINVERT);
			}
			player2flagS = 0;
		}
		else if (player2flagJ == 1)
		{
			if (player2flagW == 0)
			{
				static int k = 0, l = 3;
				if (player2flagAD == 1)
				{
					putimage(player2_x, player2_y, 80, 120, &img_player2ft11, k * 80, 0, NOTSRCERASE);
					putimage(player2_x, player2_y, 80, 120, &img_player2ft12, k * 80, 0, SRCINVERT);
					Sleep(15);
					if (k == 1 && player2_x <= player1_x && player2_x >= player1_x - 60 && player2_y <= player1_y + 80 && player2_y >= player1_y - 110 && (player1flagS == 0 || player1flagS == 1 && player1flagAD * player2flagAD > 0))
					{
						player1flagbt = 1;
						player1yz = 0;
						player1blood -= 15;
					}
					player1flagbt_dt = 1;
					k++;
				}
				else if (player2flagAD == -1)
				{
					putimage(player2_x, player2_y, 80, 120, &img_player2ft11, l * 80, 120, NOTSRCERASE);
					putimage(player2_x, player2_y, 80, 120, &img_player2ft12, l * 80, 120, SRCINVERT);
					Sleep(15);
					if (l == 1 && player2_x <= player1_x + 60 && player2_x >= player1_x && player2_y <= player1_y + 80 && player2_y >= player1_y - 110 && (player1flagS == 0 || player1flagS == 1 && player1flagAD * player2flagAD > 0))
					{
						player1flagbt = 1;
						player1yz = 0;
						player1blood -= 15;
					}
					player1flagbt_dt = -1;
					l--;
				}
				if (k == 4)
				{
					player2flagJ = 0;
					k = 0;
				}
				if (l == -1)
				{
					player2flagJ = 0;
					l = 3;
				}
			}
			else if (player2flagW == 1)
			{
				static int k = 0, l = 4;
				if (player2j == 0)
				{
					if (player2flagAD == 1)
					{
						if (k <= 1)
						{
							putimage(player2_x, player2_y, 90, 120, &img_player2ft21, k * 90, 0, NOTSRCERASE);
							putimage(player2_x, player2_y, 90, 120, &img_player2ft22, k * 90, 0, SRCINVERT);
							Sleep(15);
						}
						else
						{
							putimage(player2_x + 20, player2_y, 90, 120, &img_player2ft21, k * 90, 0, NOTSRCERASE);
							putimage(player2_x + 20, player2_y, 90, 120, &img_player2ft22, k * 90, 0, SRCINVERT);
							Sleep(15);
							if (k == 2 && player2_x <= player1_x + 20 && player2_x >= player1_x - 90 && player2_y <= player1_y + 80 && player2_y >= player1_y - 110 && (player1flagS == 0 || player1flagS == 1 && player1flagAD * player2flagAD > 0))
							{
								player1flagbt = 1;
								player1yz = 0;
								player1blood -= 10;
							}
							player1flagbt_dt = 1;
						}
						k++;
					}
					else if (player2flagAD == -1)
					{
						if (l >= 3)
						{
							putimage(player2_x, player2_y, 90, 120, &img_player2ft21, l * 90, 120, NOTSRCERASE);
							putimage(player2_x, player2_y, 90, 120, &img_player2ft22, l * 90, 120, SRCINVERT);
							Sleep(15);
						}
						else
						{
							putimage(player2_x - 20, player2_y, 90, 120, &img_player2ft21, l * 90, 120, NOTSRCERASE);
							putimage(player2_x - 20, player2_y, 90, 120, &img_player2ft22, l * 90, 120, SRCINVERT);
							Sleep(15);
							if (l == 2 && player2_x <= player1_x + 90 && player2_x >= player1_x - 20 && player2_y <= player1_y + 80 && player2_y >= player1_y - 110 && (player1flagS == 0 || player1flagS == 1 && player1flagAD * player2flagAD > 0))
							{
								player1flagbt = 1;
								player1yz = 0;
								player1blood -= 10;
							}
							player1flagbt_dt = -1;
						}
						l--;
					}
				}
				else if (player2j == 1)
				{
					if (player2flagAD == 1)
					{
						if (k == 2)
						{
							putimage(player2_x + 20, player2_y - 60, 110, 180, &img_player2ft31, k * 110, 0, NOTSRCERASE);
							putimage(player2_x + 20, player2_y - 60, 110, 180, &img_player2ft32, k * 110, 0, SRCINVERT);
							if (player2_x <= player1_x && player2_x >= player1_x - 100 && player2_y <= player1_y + 80 && player2_y >= player1_y - 110 && (player1flagS == 0 || player1flagS == 1 && player1flagAD * player2flagAD > 0))
							{
								player1flagbt = 1;
								player1yz = 0;
								player1blood -= 10;
							}
							player1flagbt_dt = 1;
						}
						else
						{
							putimage(player2_x, player2_y - 60, 110, 180, &img_player2ft31, k * 110, 0, NOTSRCERASE);
							putimage(player2_x, player2_y - 60, 110, 180, &img_player2ft32, k * 110, 0, SRCINVERT);
						}
						Sleep(15);
						k++;
						if (k == 4)
						{
							player2flagJ = 0;
							player2j++;
							k = 0;
						}
					}
					else if (player2flagAD == -1)
					{
						if (l == 2)
						{
							putimage(player2_x - 50, player2_y - 60, 110, 180, &img_player2ft31, (l - 1) * 110, 180, NOTSRCERASE);
							putimage(player2_x - 50, player2_y - 60, 110, 180, &img_player2ft32, (l - 1) * 110, 180, SRCINVERT);
							if (player2_x <= player1_x + 90 && player2_x >= player1_x - 10 && player2_y <= player1_y + 80 && player2_y >= player1_y - 110 && (player1flagS == 0 || player1flagS == 1 && player1flagAD * player2flagAD > 0))
							{
								player1flagbt = 1;
								player1yz = 0;
								player1blood -= 10;
							}
							player1flagbt_dt = -1;
						}
						else
						{
							putimage(player2_x - 20, player2_y - 60, 110, 180, &img_player2ft31, (l - 1) * 110, 180, NOTSRCERASE);
							putimage(player2_x - 20, player2_y - 60, 110, 180, &img_player2ft32, (l - 1) * 110, 180, SRCINVERT);
						}
						Sleep(15);
						l--;
						if (l == 0)
						{
							player2flagJ = 0;
							player2j++;
							l = 4;
						}
					}
				}
				if (k == 5)
				{
					player2flagJ = 0;
					player2j++;
					k = 0;
				}
				if (l == -1)
				{
					player2flagJ = 0;
					player2j++;
					l = 4;
				}
			}
			if (player2j == 2)
				player2j = 0;
		}
		else if (player2flagAD == 1)
		{
			putimage(player2_x, player2_y, 80, 120, &img_player2walk1, 0, 0, NOTSRCERASE);
			putimage(player2_x, player2_y, 80, 120, &img_player2walk2, 0, 0, SRCINVERT);
		}
		else if (player2flagAD == -1)
		{
			putimage(player2_x, player2_y, 80, 120, &img_player2walk1, 160, 120, NOTSRCERASE);
			putimage(player2_x, player2_y, 80, 120, &img_player2walk2, 160, 120, SRCINVERT);
		}
		if (player2flagAD == 2)
		{
			if (player2_x <= 1390)
				player2_x += 30;
			player2left_i++;
			if (player2left_i == 3)
				player2left_i = 1;
			putimage(player2_x, player2_y, 80, 120, &img_player2walk1, player2left_i * 80, 0, NOTSRCERASE);
			putimage(player2_x, player2_y, 80, 120, &img_player2walk2, player2left_i * 80, 0, SRCINVERT);
			player2flagAD = 1;
		}
		else if (player2flagAD == -2)
		{
			if (player2_x >= 30)
				player2_x -= 30;
			player2right_i++;
			if (player2right_i == 2)
				player2right_i = 0;
			putimage(player2_x, player2_y, 80, 120, &img_player2walk1, player2right_i * 80, 120, NOTSRCERASE);
			putimage(player2_x, player2_y, 80, 120, &img_player2walk2, player2right_i * 80, 120, SRCINVERT);
			player2flagAD = -1;
		}
	}
}
