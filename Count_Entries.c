#include <stdio.h>
#include <stdlib.h>//其中包含system函数
#include <string.h>//定义字符数组
#include "Count_Entries.h"

int Number_Of_Books()//统计图书文本个数
{
FILE *fp;
int txcl=0,tmany=0,n;
char tname[20]={'\0'},tauthor[20]={'\0'},tchuban[20]={'\0'},tkind[20]={'\0'},tshuhao[20]={'\0'};
fp=fopen("library.txt","r");//打开文件
for (n=0;!feof(fp);n++)//逐个读文件
fscanf(fp,"%s%s%s%s%d%d",tshuhao,tname,tauthor,tchuban,&tmany,&txcl);
n--;
fclose(fp);//关闭文件
return (n);//返回个数
}


int Records_Of_Books()//统计借书读者个数函数

{
FILE *fp;
int n,i;
char zuser={'\0'},zhenghao[20]={'\0'},mingzi[20]={'\0'},riqi[20]={'\0'},zname[20]={'\0'};
fp=fopen("reader.txt","r");//打开文件
for (n=0;!feof(fp);n++)//逐个读文件
fscanf(fp,"%s%s%s%s%s",&zuser,&zhenghao,&mingzi,&riqi,&zname);
i++;
fclose(fp);//关闭文件
return (n);//返回个数
}
