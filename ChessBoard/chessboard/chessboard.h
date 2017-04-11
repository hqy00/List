#define _CRT_SECURE_NO_WARNINGS 1


#define rows 3		//定义行数
#define cols 3		//定义列数

void  init_board(char board[rows][cols],int x,int y);		//初始化棋盘
void display_board(char board[rows][cols],int x,int y);		//显示棋盘
void player_move(char board[rows][cols],int x,int y);		//玩家下棋
void computer_move(char board[rows][cols]);					//电脑下棋
char check_win(char board[rows][cols],int x,int y);			//判断输赢


