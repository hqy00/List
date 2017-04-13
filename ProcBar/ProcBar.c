#include<stdio.h>
#include<string.h>
#include<unistd.h>

void ProcBar()
{
    char str[102];
    char tag[] = {'|','/','-','\\'};
    memset(str,'\0',sizeof(str));
    int rate = 0;
    while(rate <= 100)
    {
        str[rate] = '#';
        printf("[%-100s] [%d\%][%c]\r",str,rate,tag[rate%4]);                  
        fflush(stdout);
        usleep(100000);
        rate ++;
    }
    printf("\n");

}

int main()
{
    ProcBar();
    return 0;
}
                                                                                                                                                                                                                 
