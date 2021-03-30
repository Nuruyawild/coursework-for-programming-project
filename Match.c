#include <stdio.h>
#include <stdlib.h>//其中包含system函数
#include <string.h>//定义字符数组
#include "Match.h"



int match(char m[20],char a[20])//匹配数据库中的账号密码
{
	FILE*fp;
	int n=0,i=0;
	char zhanghao[20];
	char password[20];

	if ((fp=fopen("Login.txt","r"))==NULL)//不存在读者文件
	  {
          
		 printf("\nPlease register an account!");
	 	 
		Login_Main();
	
      }


        for(;!feof(fp);)
      {
        fscanf(fp,"%s %s",&zhanghao,password);
        if((strcmp(m,"librarian")==0)&&(strcmp(a,"librarian")==0))
		{
			return 2;
		}
        if(strcmp(m,zhanghao)==0)
        {
        	if(strcmp(a,password)==0)
			return 1;
			else
			{
			return -1;
		   }
	    }
	    
	    
	  }
	  return 0;
 }
 
 



