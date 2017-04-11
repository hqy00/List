#include "chessboard.h"
#include<stdio.h>
#include<stdlib.h>

void  init_board(char board[rows][cols],int x,int y)	//初始化棋盘
{
	int i=0;
	int j=0;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			board[i][j] = ' ';
		}
	}


}

void display_board(char board[rows][cols],int x,int y)		//显示棋盘
{
	int i;
	for(i=0;i<x;i++)
	{
		printf("%c | %c | %c\n",board[i][0],board[i][1],board[i][2]);
		if(i<(x-1))
		{
			printf("---------\n");
		}
	}

}


void player_move(char board[rows][cols],int x,int y)		//玩家下棋，玩家下‘x’
{
	 int a = 0;  
     int b = 0;  
    while (1)  
    {  
        printf("玩家输入坐标:");  
        scanf("%d %d", &a, &b);				  
        if ((a > 0 && a <= x) && (b > 0 && b <= y))      //判断坐标是否合法,玩家输入的是坐标，而不是数组下标
        {  
            if (board[a - 1][b - 1] == ' ')				 //判断此处有没有被下棋
            {  
                board[a - 1][b - 1] = 'x';  
                break;  
            }  
            else  
            {  
              printf("此处已有棋子，不能下在此处.\n");  
            }  
        }  
        else  
        {  
            printf("坐标输入不合法\n");  
        }  
    }  

}

void computer_move(char board[rows][cols])		//电脑下棋，电脑下‘0’
{
	while (1)  
    {   
		int  x = 0;  
		int  y = 0; 
		x = rand() % 3;			//让下标合法，取余后，能下的行数只能为0，1，2
        y = rand() % 3;			//取余后，能下的列数只能为0，1，2
		
		if (board[x][y] == ' ')  
        {  
            board[x][y] = '0'; 
            break;  
		} 
    }  
}


int board_full(char board[rows][cols],int x,int y)		//检查棋盘是否有空位
{	int i=0,j=0;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			if(board[i][j]==' ')
				return 0;
		}
	}
return 1;
}

char check_win(char board[rows][cols],int x,int y)		//判断输赢
{	
	int i=0,j=0;//判断玩家的输赢，玩家下的是x, 赢得话就让它返回x
	int ret = board_full(board,rows,cols );

	for(i=0;i<x;i++)
	{	
		if ((board[i][0]==board[i][1]) && (board[i][1]==board[i][2]) && (board[i][0]=='x'))		//判断一行的三个是否相等
		{
		return 'x';
		}
	}
		

	for(j=0;j<y;j++)
	{
		if(( board[0][j]==board[1][j]) && (board[1][j]==board[2][j]) &&(board[0][j]=='x'))	//判断一列的三个是否相等
		{
		return 'x';
		}

	}

	if((board[0][0]==board[1][1]) &&(board[1][1]==board[2][2]) &&(board[0][0]=='x'))	//判断一条对角线的三个是否相等
	{	
	
		return 'x';
	}		
	
		
	
	if((board[0][2]==board[1][1]) && (board[1][1]==board[2][0]) &&(board[0][2]=='x'))		//判断另一条对角线的三个是否相等
	{

		return 'x';
	}
	


	
	for(i=0;i<x;i++)		//判断电脑的输赢，电脑下的是0, 赢得话就让它返回0,
	{	
		if (( board[i][0]==board[i][1]) && (board[i][1]==board[i][2]) && (board[i][0]=='0'))		
		{
	
		return '0';
		}

	}
	for(j=0;j<y;j++)
	{
		if(( board[0][j]==board[1][j]) && (board[1][j]==board[2][j]) &&(board[0][j]=='0'))	
		{
		return '0';
		}
	}

	if(( board[0][0]==board[1][1]) &&( board[1][1]==board[2][2]) &&(board[0][0]=='0'))		
	{
		return '0';
	}		
	
		
	
	if(( board[0][2]==board[1][1]) && (board[1][1]==board[2][0]) &&(board[0][2]=='0'))		
	{
		return '0';
	}

		if(ret==1)		//判断棋盘是否已下满
	{
		return 'm';
	}
	

return  ' ';

}

