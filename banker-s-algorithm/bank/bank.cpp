#include "bank.h"

int available[MAXRESOURCE];                    //现有可用资源数组  
int maxneed[MAXPROCESS][MAXRESOURCE];          //最大需求矩阵  
int allocation[MAXPROCESS][MAXRESOURCE];	   //分配矩阵 
int need[MAXPROCESS][MAXRESOURCE];             //目前还需的需求矩阵  
int request[MAXPROCESS][MAXRESOURCE];          //进程需要资源数 
bool finish[MAXPROCESS];                       //系统是否有足够的资源分配  
int id[MAXPROCESS];                             //记录序列 
int m,n;									   //m个进程,n个资源

void Init()	//初始化
{
	int i,j;  
    printf("输入进程的个数:"); 
	scanf("%d",&m);
	printf("请输入资源的种类:"); 
	scanf("%d",&n);
	printf("请输入每个进程最大需求资源数,按照 m * n 矩阵输入:\n");		//输入各进程对各资源的最大需求数
	for(i=0;i<m;i++) 		
	{			
        for(j=0;j<n;j++) 
		{
            scanf("%d",&maxneed[i][j]); 
		}
	}
	printf("\n"); 


	printf("请输入每个进程已经分配的资源数,按照 m * n 矩阵输入：\n");		
	for(i=0;i<m;i++)  
	{
        for(j=0;j<n;j++) 
		{ 
            scanf("%d",&allocation[i][j]);						//各进程当前所分配的资源数目
			need[i][j] = maxneed[i][j] - allocation[i][j];		//各进程当前所需的各资源数目
            if(need[i][j]<0)  
            {  
                printf("第%d个进程的第%d个资源的分配输入有误，请重新输入\n",i+1,j+1);	//某进程分配资源数目输入有误
                j--;  
                continue;  
            } 

		}
	}
	printf("\n"); 


	printf("请输入各个资源现有的数目:\n");	//各个资源现有的数目
    for(i=0;i<n;i++)  
    {  
       scanf("%d",&available[i]);  
    }
	printf("\n"); 


   for(i=0;i<m;i++)//初始化各进程的finishi值
	{
       finish[i]=false;  
    } 
   	printf("\n"); 


}



void bank()	//银行家算法
{
    int i,num,flag = 0,p =0;  
    while(1)  
    {  
        show(m,n);  
		printf("\n"); 
input:  
		printf("请输入要申请资源的进程号(注:第1个进程号为0,依次类推)\n");
        scanf("%d",&num); 
        if (num > m)  
        {  
			printf("没有该进程，请重新输入\n");
            goto input;  
        }  
		printf("请输入该进程所请求的各资源的数量\n");
        for(i=0;i<n;i++)  
        {  
			scanf("%d",&request[num][i]);
        }
		fflush(stdin);
        for(i=0;i<n;i++)  
        {  
            if(request[num][i]>need[num][i])//如果该进程的第i个资源请求数＞该进程目前所需的i资源数量  
            {  
				printf("您输入的请求数超过该进程目前还需的资源数量!\n"); 
                goto input;  
            }  
            if(request[num][i]>available[i])//如果该进程的第i个资源请求数＞系统现有的第i个资源的数量  
           {  
			   printf("您输入的请求数超过系统目前可用的资源数!\n"); 
                goto input;  
            }  
        } 


		for(i=0;i<n;i++)//如果请求合理，那么下面试分配
        {  
            available[i]-=request[num][i];		//目前可用资源 = 原可用资源 - 需求申请了的  
            allocation[num][i]+=request[num][i];//目前分配的资源 = 原来已经分配的资源 + 需求申请了的 
            need[num][i]-=request[num][i];		//线程目前还需要的资源 = 原来还需要的资源 - 减去已申请得到的  
        }  


        if(safe())//检测由于AVAILABLE  ALLOCATION  NEED发生变动，是否会导致系统不安全  
        {  
			printf("安全，同意分配请求!\n");
		}  
        else  
        {  
			printf("不安全，您的请求被拒绝!\n");
            for(i=0;i<n;i++)		//因为不安全，没有分配成功，所以一切又恢复到分配前的状态
            {  
				available[i]+=request[num][i];		  
				allocation[num][i]-=request[num][i]; 
				need[num][i]+=request[num][i];		 
            }  
        } 

        for (i=0;i<n;i++)		//检测该进程当前的need是否已经全部满足
        {  
            if (need[num][i] == 0)  
            {  
                flag++;  
            }  
        }  
        if (flag == n)//如果全部满足，则释放该进程所有分配的资源  
        {  
            for (i=0;i<n;i++)  
            {  
                available[i] += allocation[num][i];  
                allocation[num][i] = 0;  
                need[num][i] = 0;  
            } 
			printf("进程%d的需求已被全部满足，现在释放其占有的资源！\n");
            flag = 0;  
        } 

	     for(i=0;i<m;i++)//每检查一次安全性就可能变动finish值，所以最终无论进程是否能得到分配，都要将所有进程重新赋finish值
		 {
            finish[i]=false;  
         }  

		printf("您还想再次请求分配吗?是请按1,否请按其它键\n");
        scanf("%d",&p); 
		fflush(stdin);

        if(p == 1)  
        {  
            continue;  
        } 
        break;  
    } 

}




bool safe()	//安全性检测
{
    int i,j,k,s=0,tmp=0;
    int work[MAXRESOURCE];      //工作数组  
    for(i=0;i<n;i++)  
    {
        work[i]=available[i]; 
    }

	for(i=0;i<m;)  //i++在表达式中会做修改
	{     
		for(j=0;j<n;j++)//循环查找第i个进程需要的各个资源数 是否 超过系统现有的对应的资源数  
		{  
			if(need[i][j]>work[j])//第i个进程需要的第j个资源数 ＞ 系统现有的第j个资源数  
			{  
				break;  
			}  
		}  

		if(j==n && finish[i]==false)//如果第i个进程所需的各个资源数都没有超过系统现有的对应资源数 ，并且该进程标记为false 
		{   
			printf("P%d进程满足,且finish[%d] = false\n  ",i,i);
			printf("work =");
			printf("work (");
			for(k=0;k<n;k++)  
			{  
				printf("%d",work[k]);
				if(k<n-1)printf(" , ");
				if(k == n-1)printf(") + ");
				
			} 
			printf("allocation[%d](",i);
			for(k=0;k<n;k++)  
			{  
				printf("%d",allocation[i][k]);
				if(k<n-1)printf(" , ");
				if(k == n-1)printf(") = (");
				
			} 

			
			for(k=0;k<n;k++)  //将work赋值为 第i个进程各个已分配资源数＋系统现有的对应资源数
			{  
				work[k]+=allocation[i][k];
				
			}

			
            for(k=0;k<n;k++)  
			{  
				printf("%d",work[k]);
				if(k<n-1)printf(" , ");
				if(k == n-1)printf(")  \n");
				
			} 

			finish[i]=true;		//给该进程的finish标记为true 
			printf("finish[%d] = true\n",i);
			id[s++]=i;	//记录已经分配过的进程号  
			i = 0;		//只要找到了，就再从头开始查找
		}  
		else	// 当前条件是 j!=n || finish[i]!=false,要么是进程的需求大于可用的资源数，要么是该进程已被分配过
		{
			i++;	//循环自增在这里控制
			continue;  
		}	
		if(s==m)//当所有进程都被分配了时  
		{  
			printf("系统是安全的\n"); 
			printf("安全序列为:\n"); 
			for(i=0;i<s;i++)
			{  
				printf("%d",id[i]); 
				if(i!=s-1)  
				{  
					printf("-->"); 
				}  
			}
			printf("\n");

			return true;  
		}
	}//for循环结束 
	
	printf("系统是不安全的\n");
    return false;

}



void show(int m,int n)	//显示
{
	int i,j,k;   
	printf("系统当前可用的资源数目为:\n ");
    for(i=0;i<n;i++)
	{
		printf(" %d  ",available[i]);
	}
    printf("\n"); 

	printf("各进程还需要的资源数目：\n"); 
    for(j=0;j<m;j++)     
    {  
		printf("进程%d",j);
        for(k=0;k<n;k++) 
		{
			printf(" %d ",need[j][k]); 
		}
		printf("\n");
    }     
    printf("\n");   

	printf("各进程进程已经分配到的资源数:\n");
    for(j=0;j<m;j++)     
    {  
		printf("进程%d",j);
        for(k=0;k<n;k++) 
		{
			printf(" %d ",allocation[j][k]); 
		}
		printf("\n");        
    }    
	printf("\n"); 
 

}




int main()
{
	Init();
	bank();
	return 0;
}