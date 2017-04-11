#include "chessboard.h"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

void menu()
{
	printf("********************************\n");
	printf("**********1->>开始游戏**********\n");
	printf("**********0->>游戏结束**********\n");
	printf("********************************\n");

}
void game()
{	int i=0,j=0;
	char rt = 0;
	char board[rows][cols]={ 0 } ;	//rows 和 cols的值宏定义给出了
	srand((unsigned)time(NULL));		//产生随机值的种子
	init_board(board,rows,cols);
	display_board( board,rows,cols);
	do
	{	
		player_move(board,rows,cols);
		display_board( board,rows,cols);
		if((rt = check_win(board,rows,cols))!=' ')
		{
			break;
		}
		printf("电脑正在下棋......\n");
		Sleep(1000);
		computer_move(board);
		display_board( board,rows,cols);
		rt = check_win(board,rows,cols);
	
	}while(rt==' ');

	if(rt=='0')
	{	printf("电脑赢了！\n");	}
	if(rt=='x')
	{	printf("玩家赢了！\n");	}
	if(rt=='m')
	{	printf("这一场是平局！\n");	}
			
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请输入：");
		scanf("%d",&input);
		switch(input)
		{
		case 1:		
			game();		
			break;
		case 0:		
			printf("游戏结束！\n");		
			break;
		default:
			printf("输入有误！！\n");
			break;
		}

	}while(input);

return 0;


}