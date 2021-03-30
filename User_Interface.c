#include <stdio.h>
#include <stdlib.h>//其中包含system函数
#include <string.h>//定义字符数组
#include "User_Interface.h"

extern char user;//界面显示用户名

void ManagementMenu() //图书馆信息菜单
{
printf("\n(logged in as: %s)\n",user);
printf("Please choose an option:\n");
printf("1)Add a book\n");
printf("2)Remove a book\n");
printf("3)Search for books\n");
printf("4)Display all books\n");
printf("5)Log out\n");
printf(" Option: ");
return ;
}

void findbymenu()//目录系统 
{
	printf("\n1)Find book by title\n");
	printf("2)Find book by author\n");
	printf("3)Find book by year\n");
	printf("4)Return to previous menu\n");
	return ;
 } 
 
void Borrow_And_Return_Menu()//显示借书菜单
{
	printf("\n(logged in as: %s)\n",user); 
	printf("1)Borrow a book\n");
	printf("2)Return a book\n");
	printf("3)Search for books\n");
	printf("4)Display all books\n");
    printf("5)Log out\n");
	printf(" Option: ");
	return ;
}

void Login_Menu()//显示登录菜单
{
printf("\nPlease choose an option:\n1) Register an account\n2) Login\n3) Search for books\n4) Display all books\n5) Quit\nOption: ");
return ;
}


