#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _BANK_H_
#define _BANK_H_
#include<stdio.h>
#include<windows.h>


#define MAXPROCESS 50       //最大进程数  
#define MAXRESOURCE 100		//最大资源种类

void Init();	//初始化
void bank();	//银行家算法
bool safe();	//安全性检测
void show(int,int);	//显示



#endif




