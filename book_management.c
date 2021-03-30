#include <stdio.h>
#include <stdlib.h>//其中包含system函数
#include <string.h>//定义字符数组
#include "book_management.h"
#include "User_Interface.h"

#define LEN sizeof(struct _Book)//有关图书信息的结构体
#define LEN1 sizeof(struct reader)//有关读者信息的结构体
#define LEN2 sizeof(struct Login)//有关登录系统的结构体

struct reader//读者借阅信息
{
	unsigned int jnum;
	char juser[20];
	char jnam[20],jaut[20];
	unsigned int jyear;
	struct reader *next;
};






void Management_Main();//图书菜单功能
void Search_For_Books_Main();//查询图书菜单 
void Display_Books_For_Librarian();//管理员浏览图书
void Display_Books_For_NotLogin();//未登录时的浏览图书
void Display_Books_For_Users();//用户浏览图书 

void Borrow_And_Return_Main();//读者借阅信息
void Borrow_Books();//借书
void Return_Books();//还书
void Display_Borrow_Books();// 浏览借书情况

void Login();//登录功能系统
void Create_New_Account();//创建账号密码
void Login_Main();//登录界面函数

char user[20]={'\0'};//界面显示用户名
int a=1;//存储书的最终ID







void Management_Main()
{
	int add_book(Book book);
	int remove_book(Book book);
	Book book;
	void Display_Books_For_Librarian();
	int a;
	char choose[2]={'\0'};
	ManagementMenu();
	gets(choose);
	a=atoi(choose);

	switch(a)
	{
	case 1:
		add_book(book);
		Management_Main();
		break;
	case 2:
		remove_book(book);
		Management_Main();
		break;
	case 3:
		Search_For_Books_Main();
		break;
	case 4:
		Display_Books_For_Librarian();
		break;
	case 5:
		Login_Main();
		break;
	}
    
}


int add_book(Book book)//增加图书
{
	FILE*fp;
	char i;
	int c;
	int n;
	int year;
	int copies;
	int manyofremain;
    char  title[20]={'\0'},authors[20]={'\0'},many1[10]={'\0'},year1[20]={'\0'};
     

    if ((fp=fopen("library.txt","r"))==NULL)//if语句：打开图书馆文件，不存在此文件则新建
	{
      fp=fopen("library.txt","w");
      fclose(fp);
    }
    
    fp=fopen("library.txt", "rb");
    
    
	fp=fopen("library.txt","a");

		printf("Enter the title of the book you wish to add: ");
		gets(title);
		
		printf("Enter the author of the book you wish to add: ");
		gets(authors);
		
		printf("Enter the year that the book you wish to add was released: ");
		gets(year1);
		
		printf("Enter the number of copies of the book you wish to add: ");
		gets(many1);
		
		copies=atoi(many1);
		manyofremain=atoi(many1);
		
		
		
		if(isdigit(year1[0])!=0)
		{
			book.title=(char*)malloc(sizeof(char));
			book.authors=(char*)malloc(sizeof(char));
			year=atoi(year1);
			strcpy(book.title,title);
		    strcpy(book.authors,authors);
		    book.year=year;
		    book.copies=copies;
		    book.manyofremain=manyofremain;
			fprintf(fp,"%-8d%-19s%-14s%-18d%-8d%-8d\n",a,book.title,book.authors,book.year,book.copies,book.manyofremain);
			a=a+1;
			printf("\nBook was successfully added!\n");
			fclose(fp);
			return 0;
		}
		else
		{
			printf("Sorry, you attempt to add an invalid book, please try again.\n\n");
			return -1;
		}

	
	//返回上一层
}

int store_books(FILE *file)
{
   FILE *fp;
   
   if((fp=fopen("library.txt","r"))!=NULL)
   {
   	return 1;
   }
   else
   {
   	return 0;
   }
}

int load_books(FILE *file)
{
   FILE *fp;
   
   if((fp=fopen("library.txt","r"))!=NULL)
   {
   	return 1;
   }
   else
   {
   	return 0;
   }
}

int remove_book(Book book)//删除图书
{
	   struct _Book *head=NULL;
       struct _Book *p,*p1,*p2;
       int tmany=0,tmanyofremain=0,n=0,j,k,q;
       unsigned int tyear,jyear,tnum,jnum,jjnum;
       char  tnam[20]={'\0'},taut[20]={'\0'};
       char  jnam[20]={'\0'},jaut[20]={'\0'},juser[20]={'\0'};
	   char jjnum1[20]={'\0'};
	   char i;
       FILE *fp,*fp3;
       if ((fp=fopen("library.txt","r"))==NULL)//打开文件
       {
           printf("\nThe record file does not exist!");
           return -1;
       }

	   else//实现删除的功能
	   {
	      printf("\nPlease enter the book you wish to delete:");//输入删除图书书名
          gets(jjnum1);
          jjnum=atoi(jjnum1);
	      fp=fopen("library.txt","r");
		  j=Number_Of_Books();
		  fp3=fopen("reader.txt","r");
		  q=Records_Of_Books();
		  
		  for(k=0;k<q;k++)
		  {
		  	fscanf(fp3,"%s%d%s%s%d",juser,&jnum,jnam,jaut,&jyear);
		  	if(jjnum==jnum)
		  	{
		  		printf("Delete failed! Because someone has already borrowed the book!\n");
		  		return -1;
			  }
		  }

	   for (k=0;k<j;k++)
       {
	       fscanf(fp,"%d%s%s%d%d%d",&tnum,tnam,taut,&tyear,&tmany,&tmanyofremain);
           if (jjnum!=tnum)//比较ID，将不同ID的信息复制到链表
          {
	          n++;//相同返回值为0不执行if语句继续循环，不同则执行直到将所有不同的书名建立成链表
	            if (n==1)//建立链表
                {
		          p1=p2=(struct _Book*)malloc(LEN);
                  head=p1;
                  p1->authors=(char*)malloc(sizeof(char));
                  p1->title=(char*)malloc(sizeof(char));
				}
                else
			    {
			      p2->next=p1;
				  p2=p1;
                  p1=(struct _Book*)malloc(LEN);//新建链表
                  p1->authors=(char*)malloc(sizeof(char));
                  p1->title=(char*)malloc(sizeof(char));
                }

                p1->id=tnum;//复制书号
                strcpy(p1->title,tnam);//复制书名
                strcpy(p1->authors,taut);//复制作者名字
                p1->year=tyear;//复制年份
                p1->copies=tmany;//复制个数
                p1->manyofremain=tmanyofremain;//复制剩余个数 
           }
       }
             if (n==0)//如果图书只有一项且这一项刚好和要删除的相同
			 {
			 head=NULL;
			 }
			 else//建立链表的最后剩余一个储存空间，所以封底
			 {
			 p2->next=p1;
			 p1->next=NULL;
			 fclose(fp);
			 }
    }
    
   

   fp=fopen("library.txt","w");
   fclose(fp);
   	p=head;
    fp=fopen("library.txt","a");//追加文件
   for (;p!=NULL;)//把链表内容覆盖到文件
   {
   	   fprintf(fp,"%-8d%-9s%-14s%-18d%-8d%-8d\n",p->id,p->title,p->authors,p->year,p->copies,p->manyofremain);
   	   p=p->next;
   }
   fclose(fp);
   if(store_books("library.txt")==1)
   {
   	printf("\nDelete book successfully!");
   	return 0;
   }
   
}


 
void funcoffindbymenu()
{
	char title;
    char author;
    int year;
	BookArray find_book_by_title (const char *title);
	BookArray find_book_by_author (const char *author);
	BookArray find_book_by_year (unsigned int year);
	char choose[1]={'\0'};
	int a; 
	gets(choose);
	a=atoi(choose);
		switch(a)
		{
			case 1:
			find_book_by_title (title);
			Search_For_Books_Main();
			break;
			case 2:
			find_book_by_author (author);
			Search_For_Books_Main();
			break;
			case 3:
			find_book_by_year (year);
			Search_For_Books_Main();
			break;
			case 4:
			Management_Main();
			break;
		}
 } 
 
void Search_For_Books_Main()//查询图书
{
	   FILE *fp;
       int k=0,copies=0,m=0,n=0;
       char  title[20]={'\0'},authors[20]={'\0'},year[20]={'\0'},id[20]={'\0'};
       char i;
       char chazhao[20]={'\0'};
       findbymenu();
       funcoffindbymenu();
}



BookArray find_book_by_title (const char *title)//按照标题查询图书
{
	   FILE *fp;
	   BookArray p;
       int k=0,copies=0,manyofremain=0,m=0,n=0;
       int year,id;
       char  title1[20]={'\0'},authors[20]={'\0'};
       char i;
       char chazhao[20]={'\0'};
       if (store_books("library.txt")==0)//打开文件
       {
           printf("\nThe record file does not exist!");
		   Management_Main();
       }
       
	   p.array->authors=(char*)malloc(sizeof(char));
       p.array->title=(char*)malloc(sizeof(char));
	   
       printf("Please enter tltle: ");
       gets(chazhao);
       m=Number_Of_Books();
       title=&chazhao;
       
       
       if(load_books("library.txt")==1)
       {
       	fp=fopen("library.txt","r");
	   }
       
	   for (n=0;n<m;n++)
	   {
	   	
	    fscanf(fp,"%d%s%s%d%d%d",&id,title,authors,&year,&copies,&manyofremain);
        if(!strcmp(chazhao,title1))
        {
        	if(k==0)
            {
			  printf("\nID\tTitle\t\t\tAuthors\t\tYear\tCopies\tCopies of remain\n");
            }
			printf("%-8d%-24s%-16s%-8d%-8d%-8d\n",id,title1,authors,year,copies,manyofremain);
			p.array->id=id;
			strcpy(p.array->title,title1);
			strcpy(p.array->authors,authors);
			p.array->year=year;
			p.array->copies=copies;
			p.array->manyofremain=manyofremain;
			p.length=sizeof(p.array);
            k++;
        }
       }
        if (k==0)//文件夹为空则输出无记录并返回上一层
        {  
        printf("\nThere is no matching item!\n");
        p.length=0;
        Management_Main();
		}
		fclose(fp);//查询结束
		return p;
}

BookArray find_book_by_author (const char *author)//按作者查询图书
{
	   FILE *fp;
	   BookArray p;
       int k=0,copies=0,manyofremain=0,m=0,n=0;
       int year,id;
       char  title[20]={'\0'},authors[20]={'\0'};
       char i;
       char chazhao[20]={'\0'};
       if (store_books("library.txt")==0)//打开文件
       {
           printf("\nThe record file does not exist!");
		   Management_Main();
       }
       
	   p.array->authors=(char*)malloc(sizeof(char));
       p.array->title=(char*)malloc(sizeof(char));
	   
       printf("Please enter author: ");
       gets(chazhao);
       m=Number_Of_Books();
       author=&chazhao;
       
       
       if(load_books("library.txt")==1)
       {
       	fp=fopen("library.txt","r");
	   }
       
	   for (n=0;n<m;n++)
	   {
	   	
	    fscanf(fp,"%d%s%s%d%d%d",&id,title,authors,&year,&copies,&manyofremain);
        if(strstr(authors,chazhao)!=NULL)
        {
        	if(k==0)
            {
			  printf("\nID\tTitle\t\t\tAuthors\t\tYear\tCopies\tCopies of remain\n");
            }
			printf("%-8d%-24s%-16s%-8d%-8d%-8d\n",id,title,authors,year,copies,manyofremain);
			p.array->id=id;
			strcpy(p.array->title,title);
			strcpy(p.array->authors,authors);
			p.array->year=year;
			p.array->copies=copies;
			p.array->manyofremain=manyofremain;
			p.length=sizeof(p.array);
            k++;
        }
       }
        if (k==0)//文件夹为空则输出无记录并返回上一层
        {  
        printf("\nThere is no matching item!\n");
        p.length=0;
        Management_Main();
		}
		fclose(fp);//查询结束
		return p;
}

BookArray find_book_by_year (unsigned int year)//按照年份查询图书
{
	   FILE *fp;
	   BookArray p;
       int k=0,copies=0,manyofremain=0,m=0,n=0;
       int year1,id,chazhao;
       char  title[20]={'\0'},authors[20]={'\0'};
       char i;
       char chazhao1[20]={'\0'};
       if (store_books("library.txt")==0)//打开文件
       {
           printf("\nThe record file does not exist!");
		   Management_Main();
       }
       
	   p.array->authors=(char*)malloc(sizeof(char));
       p.array->title=(char*)malloc(sizeof(char));
	   
       printf("Please enter tltle: ");
       gets(chazhao1);
       chazhao=atoi(chazhao1);
       m=Number_Of_Books();
       year=chazhao;
       
       
       if(load_books("library.txt")==1)
       {
       	fp=fopen("library.txt","r");
	   }
       
	   for (n=0;n<m;n++)
	   {
	   	
	    fscanf(fp,"%d%s%s%d%d%d",&id,title,authors,&year1,&copies,&manyofremain);
        if(chazhao==year)
        {
        	if(k==0)
            {
			  printf("\nID\tTitle\t\t\tAuthors\t\tYear\tCopies\tCopies of remain\n");
            }
			printf("%-8d%-24s%-16s%-8d%-8d%-8d\n",id,title,authors,year1,copies,manyofremain);
			p.array->id=id;
			strcpy(p.array->title,title);
			strcpy(p.array->authors,authors);
			p.array->year=year1;
			p.array->copies=copies;
			p.array->manyofremain=manyofremain;
			p.length=sizeof(p.array);
            k++;
        }
       }
        if (k==0)//文件夹为空则输出无记录并返回上一层
        {  
        printf("\nThere is no matching item!\n");
        p.length=0;
        Management_Main();
		}
		fclose(fp);//查询结束
		return p;
}

void Display_Books_For_NotLogin()//未登录时的浏览图书
{
	FILE *fp;
	int n=0;
       int k=0,m=0,copies=0,manyofremain=0;
       char  title[20]={'\0'},authors[20]={'\0'},year[20]={'\0'},id[20]={'\0'};
  	   char i;
	   if ((fp=fopen("library.txt","r"))==NULL)//打开文件
       {
	        
           printf("\nRecord file does not exist!");
           Management_Main();
	   }
	   n= Number_Of_Books();
       if (n==0)
      {
	   
      printf("\nNo record exists!");
      }

	     fp=fopen("library.txt","r");//打开只读文件
	     printf("\nID\tTitle\t\t\t\t\tAuthors\t\t\t\t\tYear\tCopies\tCopies of remain\n");
  
	   for (m=0;m<n;m++)//输出数据
	     {
	     fscanf(fp,"%s%s%s%s%d%d",id,title,authors,year,&copies,&manyofremain);
		 printf("%-8s%-40s%-40s%-8s%-8d%-8d\n",id,title,authors,year,copies,manyofremain);
	 	}
		fclose(fp);
        Login_Main();
}

void Display_Books_For_Librarian()//浏览图书
{
	FILE *fp;
	int n=0;
       int k=0,m=0,copies=0,manyofremain=0;
       char  title[20]={'\0'},authors[20]={'\0'},year[20]={'\0'},id[20]={'\0'};
  	   char i;
	   if ((fp=fopen("library.txt","r"))==NULL)//打开文件
       {
	        
           printf("\nRecord file does not exist!");
           Management_Main();
	   }
	   n= Number_Of_Books();
       if (n==0)
      {
	   
      printf("\nNo record exists!");
      }

	     fp=fopen("library.txt","r");//打开只读文件
	     printf("\nID\tTitle\t\t\t\t\tAuthors\t\t\t\t\tYear\tCopies\tCopies of remain\n");
  
	   for (m=0;m<n;m++)//输出数据
	     {
	     fscanf(fp,"%s%s%s%s%d%d",id,title,authors,year,&copies,&manyofremain);
		 printf("%-8s%-40s%-40s%-8s%-8d%-8d\n",id,title,authors,year,copies,manyofremain);
	 	}
		fclose(fp);
        Management_Main();
}

void Display_Books_For_Users()//用户浏览图书
{
	FILE *fp;
	int n=0;
       int k=0,m=0,copies=0,manyofremain=0;
       char  title[20]={'\0'},authors[20]={'\0'},year[20]={'\0'},id[20]={'\0'};
  	   char i;
	   if ((fp=fopen("library.txt","r"))==NULL)//打开文件
       {
	        
           printf("\nRecord file does not exist!");
           Management_Main();
	   }
	   n= Number_Of_Books();
       if (n==0)
      {
	   
      printf("\nNo record exists!");
      }

	     fp=fopen("library.txt","r");//打开只读文件
	     printf("\nID\tTitle\t\t\t\t\tAuthors\t\t\t\t\tYear\tCopies\tCopies of remain\n");
  
	   for (m=0;m<n;m++)//输出数据
	     {
	     fscanf(fp,"%s%s%s%s%d%d",id,title,authors,year,&copies,&manyofremain);
		 printf("%-8s%-40s%-40s%-8s%-8d%-8d\n",id,title,authors,year,copies,manyofremain);
	 	}
		fclose(fp);
        Borrow_And_Return_Main();
}
	



void Borrow_And_Return_Main()//借阅系统函数
{
	void Borrow_Books();
	void Return_Books();
	void Display_Borrow_Books();
	int a;
	char choose[1]={'\0'};
	Borrow_And_Return_Menu();
	gets(choose);
	a=atoi(choose);
	
		switch(a)
		{
			case 1:
			Borrow_Books();
			break;
			case 2:
			Return_Books();
			break;
			case 3:
			Search_For_Books_Main();
			break;
			case 4:
			Display_Books_For_Users();
			break;
			case 5:
			printf("\nLogging out...\n");
			Login_Main();
			break;
		}
	

}



void Borrow_Books()//借书函数
{
	FILE *fp,*fp3;
	struct _Book *head=NULL;
    struct _Book *p,*p1,*p2;
    int i,loop,k,a,flag=0,s=0;
    int m=0,n=0;
    unsigned int id,year,jnum,tyear,tshuhao,znum,copies,copiesofremain,num1,year1;
    char title[20]={'\0'},authors[20]={'\0'};
	int many=0,manyofremain=0;
	char tname[20]={'\0'},tauthor[20]={'\0'},tchuban[20]={'\0'},
         ttname[20]={'\0'};
    char user1[20]={'\0'},nam1[20]={'\0'},aut1[20]={'\0'},znum1[10]={'\0'};
	char hit=0;

	 
	if((fp=fopen("library.txt","r"))==NULL)
	{
		 
		printf("\n No books in the library!");
		exit(0);
	}
	else
	{
        printf("\nEnter the ID number of the book you wish to borrow:");
		gets(znum1);
		znum=atoi(znum1);
		fp=fopen("library.txt","r");
        k=Number_Of_Books();//统计图书馆文件个数
    
	for (i=0;i<k;i++)//先将图书信息建立链表，更改库存
    	{
    		fscanf(fp,"%d%s%s%d%d%d",&tshuhao,tname,tauthor,&tyear,&many,&manyofremain);
			n++;
			if(n==1)
			{
				p1=p2=(struct _Book*)malloc(LEN);
				head=p1;
				p1->authors=(char*)malloc(sizeof(char));
				p1->title=(char*)malloc(sizeof(char));
			}
		    else
           	{
                p2->next=p1;
                p2=p1;
                p1=(struct _Book*)malloc(LEN);
                p1->authors=(char*)malloc(sizeof(char));
				p1->title=(char*)malloc(sizeof(char));
            }
			p1->id=tshuhao;//复制书号
			strcpy(p1->title,tname);//复制书名
			strcpy(p1->authors,tauthor);//复制作者
			p1->year=tyear;//复制年份
			p1->copies=many;//复制现存量
			p1->manyofremain=manyofremain;//复制剩余量 
			
        }
        if(n==0)
 		head=NULL;
		else
		 {
		 	p2->next=p1;
		 	p1->next=NULL;
		 	fclose(fp);
		 }

	}
	p=head;
	
	for (;p!=NULL;)
	{
		if(p->id==znum)//判断要借书的是否存在，标记等于1，存在库存减一
		{
            flag=1;
		 	loop=p->manyofremain;
		 	(p->manyofremain)--;
		 }
			p=p->next;
  }
	if((flag==1)&&(loop>0))//存在被借的图书且现存量大于0，把库存量变化后的链表存入文件
    {

		fp=fopen("library.txt","w");
    	fclose(fp);
    	fp=fopen("library.txt","a");
    	p=head;

		for(;p !=NULL;)
    	{
    		fprintf(fp,"%-8d%-40s%-40s%-8d%-8d%-8d\n",p->id,p->title,p->authors,p->year,p->copies,p->manyofremain);
   		   	p=p->next;
		}
		free(p);
		fclose(fp);

		if ((fp3=fopen("reader.txt","r"))==NULL)//建读者文件夹存入借书信息
        {
		    fp3=fopen("reader.txt","w");//如果文件不存在则创建文件
            fclose(fp3);
        }
        
		fp3=fopen("reader.txt","r");
        fp=fopen("library.txt","r");
        a=Records_Of_Books();//统计借书记录数
        for (n=0;n<a;n++)
        {
        	
			fscanf(fp3,"%s%d%s%s%d",user1,&num1,nam1,aut1,&year1);
			if((znum==num1)&&(!(strcmp(user,user1))))
            {
        	printf("Sorry, you already have a copy of this book on loan.\n");
        	goto exit;
		    }
		}
		fclose(fp3);
		
		fp3=fopen("reader.txt","a");
        for (n=0;n<k;n++)
	    {
	    fscanf(fp,"%d%s%s%d%d%d",&id,title,authors,&year,&copies,&copiesofremain);
        if(znum==id)
        {
			fprintf(fp3,"%-8s%-8d%-24s%-24s%-8d\n",user,id,title,authors,year);
			printf("You have successfully borrowed the book!\n");
        }
        }
        
        fclose(fp);
	    fclose(fp3);
		exit:Borrow_And_Return_Main();//调用借阅系统
   }
	else
    {
    	if(loop==0)
        printf("The book has been borrowed out!");//否则输出此书已被借完
		if(flag==0)
		printf("This book does not exist!");
	}
        Borrow_And_Return_Main();//调用借阅系统

}


void Return_Books ()//还书函数
{
 	 FILE *fp,*fp3;
	 struct reader *head=NULL;
	 struct reader *p,*p1,*p2;
	 struct _Book *lhead1=NULL;
	 struct _Book *zp1,*lp1,*lp2;
	 int txcl=0,tmany=0,i;
	 int tshuhao,ttnum,tnum,tyear;
	 char tname[20]={'\0'},tauthor[20]={'\0'},tkind[20]={'\0'},
	 tchuban[20]={'\0'},ttname[20]={'\0'},ttnum1[20]={'\0'};
	 int n=0,k=0,t=0,flag=0;
	 char ttitle[20]={'\0'},tuser[20]={'\0'};

	 
     {
 	 if ((fp=fopen("reader.txt","r"))==NULL)//不存在读者文件，则输出不能还书
	  {
		 printf("\n There are no borrowers!");
		 Borrow_And_Return_Main();
      }

	  else
	  {{
	  	 Display_Borrow_Books();
	     printf("\nPlease enter the ID of the book you want to return:");
		 gets(ttnum1);//输入ID
		 ttnum=atoi(ttnum1);
		 k=Records_Of_Books();//获取读者文件夹信息个数
		 for(;!feof(fp);)//读取读者文件夹信息
           {
			fscanf(fp,"%s%d%s%s%d",tuser,&tnum,ttitle,tauthor,&tyear);
			if((tnum==ttnum)&&(!(strcmp(tuser,user))))//如果ID存在且是这个用户，则标记为1
			{
				flag=1;
			}
			
			}
      fclose(fp);
	  fp=fopen("reader.txt","r");//打开读者文件，删除借书信息
	  if(flag)
	  {
	  for (i=0;i<k;i++)//将读者文件复制到链表
	  {
	  fscanf(fp,"%s%d%s%s%d",tuser,&tnum,ttitle,tauthor,&tyear);//读取文件信息
	  if((ttnum!=tnum)||((strcmp(tuser,user))!=0))
	  {
          n++;
		  if (n==1)
		  {
		      p1=p2=(struct reader*)malloc(LEN1);//新建链表
		      
			  head=p1;
		  }
		  else
		  {
		        p2->next=p1;
				p2=p1;
				p1=(struct reader*)malloc(LEN1);//新建链表
          }
          strcpy(p1->juser,tuser);
		  p1->jnum=tnum;//复制ID
		  strcpy(p1->jnam,ttitle);//复制书名 
		  strcpy(p1->jaut,tauthor);//复制作者 
		  p1->jyear=tyear;//复制日期 
		  }}
		  if (n==0)
		  head=NULL;
		  else
		  {
		       p2->next=p1;
			   p1->next=NULL;
			   fclose(fp);
	      }
		  fp=fopen("reader.txt","w");//清空读者文件
		  fclose(fp);
		  fp=fopen("reader.txt","a");//追加信息
		  p=head;
		  for (i=1;i<k-1;i++)//把链表内容覆盖读者文件
		  {
		      fprintf(fp,"\n%-8s%-8d%-23s%-18s%-10d\n",p->juser,p->jnum,p->jnam,p->jaut,p->jyear);
			  p=p->next;
	      }
		  free(p);
		  fclose(fp);
		  }}}}

		  if(flag==1)//标记为1，即还书时更改库存
		  {{
		  {
			  n=0;flag=0;
			  fp3=fopen("library.txt","r");//打开图书馆文件
			  k=Number_Of_Books();//获取图书馆文件个数
			  for (i=0;i<k;i++)//将图书馆文件复制到链表
			  {
			       fscanf(fp3,"%d%s%s%d%d%d\n",&tshuhao,tname,tauthor,&tyear,&tmany,&txcl);//读取信息
				   n++;
				   if (n==1)
				   {
				       lp1=lp2=(struct _Book*)malloc(LEN);//新建链表
				       lp1->authors=(char*)malloc(sizeof(char));
				       lp1->title=(char*)malloc(sizeof(char));
					   lhead1=lp1;
				   }
				   else
				   {
				       lp2->next=lp1;
					   lp2=lp1;
					   lp1=(struct _Book*)malloc(LEN);//新建链表
					   lp1->authors=(char*)malloc(sizeof(char));
				       lp1->title=(char*)malloc(sizeof(char));
				   }
				   lp1->id=tshuhao;//复制书号
				   strcpy(lp1->title,tname);//复制书名
				   strcpy(lp1->authors,tauthor);//复制作者
				   lp1->year=tyear;//复制年份
				   lp1->copies=tmany; //复制现存量
				   lp1->manyofremain=txcl;//复制剩余量 
				   }
				   if (n==0)
				   {
 	  		          lhead1=NULL;
				   }
				   else
				   {
				   	   lp2->next=lp1;
				   	   lp1->next=NULL;
				   	   fclose(fp3);
				   }}}
				   zp1=lhead1;
				   for (;zp1!=NULL;)
				   {
				        if(zp1->id==ttnum)//寻找书名相同
						++(zp1->manyofremain);//现存量加1
						zp1=zp1->next;
					}
					fp3=fopen("library.txt","w");//清空图书馆文件
					fclose(fp);
					fp3=fopen("library.txt","a");//追加信息
					zp1=lhead1;
					for (;zp1!=NULL;)//把链表内容覆盖图书馆文件
					{
                         fprintf(fp3,"%-8d%-9s%-14s%-18d%-8d%-8d\n",
        				 zp1->id,zp1->title,zp1->authors,zp1->year,zp1->copies,zp1->manyofremain);
						 zp1=zp1->next;
				    }
				    printf("Return the book successfully!"); 
					fclose(fp3);
					Borrow_And_Return_Main();//调用借阅系统
					}
					else
					printf("This information does not exist!");
					Borrow_And_Return_Main();//调用借阅系统
}


void Display_Borrow_Books()//显示借书情况函数

{
    FILE *fp;
    int xcl=0,n=0,i=0,j=0;
    char zhenghao[20]={'\0'},mingzi[20]={'\0'},riqi[20]={'\0'},zname[20]={'\0'},zuser[20]={'\0'};
	if ((fp=fopen("reader.txt","r"))==NULL)//打开读者文件夹
    {
         
        printf("\n记录文件不存在!按任意键返回");
	    Borrow_And_Return_Main();
    }
    n=Records_Of_Books();
    printf("\nID\tTitle\t\t\tAuthor\t\tYear\n");
    if(n==0)
	{  
	printf("\n无任何记录!");
	}
	fp=fopen("reader.txt","r");
	for(i=0;i<(n-1);i++)
	{
		fscanf(fp,"%s%s%s%s%s",zuser,zhenghao,mingzi,riqi,zname);
		if(!(strcmp(user,zuser)))
		{
			printf("%-8s%-24s%-16s%-8s\n",zhenghao,mingzi,riqi,zname);
		}
	}
	fclose(fp);
}






void Login_Main()//登录功能函数
{
	void Login();
	void Create_New_Account(); 
	int a;
	char choose[2]={'\0'};
	Login_Menu();
	gets(choose);
	a=atoi(choose);
	switch(a)//功能函数
  {
	  case 1:
	    Create_New_Account();
	    break;
	  case 2:
	  	Login();
	  	break;
	  case 3:
	  	Search_For_Books_Main();
	  	break;
	  case 4:
	  	Display_Books_For_NotLogin();//未登录时的浏览图书
		break; 
	  case 5:
	  	printf("\nThank you for using the library!\n");
	  	printf("Goodbye!");
	  	exit(0);
	  default:
		printf("\nSorry, the option you entered was invalid, please try again.\n");
		Login_Main();
	break;
  }
}



void Create_New_Account()//新建账户密码
{
	FILE *fp;
	char m[20];
	char n[20];
	char zhanghao[20];
	char password[20];
	int i;
	if ((fp=fopen("Login.txt","r"))==NULL)//if语句：打开图书馆文件，不存在此文件则新建
	{
      fp=fopen("Login.txt","w");
      fclose(fp);
    }
	
	printf("\nPlease enter your username: ");
	gets(zhanghao);
	printf("Please enter your password: ");
	gets(password);
	fp=fopen("Login.txt","r");
	fscanf(fp,"%s %s",&m,n);
    if(match(zhanghao, password)==1||match(zhanghao, password)==2)
    {
        printf("\nSorry, registration unsuccessful, the username you entered already exists.\n");
	}
	else
	{
		fp=fopen("Login.txt","a");
		fprintf(fp,"%s %s\n",zhanghao,password);
        fclose(fp);
        printf("\nRegistered library account successfully!\n");
	}
	
    Login_Main();
}


void Login()//输入账户密码的登录函数
{
	char zhanghao[20];
	char password[20];
	int i=2,j,k,n;
	char hit=0;
	 
	
	printf("\nPlease enter your username: ");
    gets(zhanghao);
    
	printf("Please enter your password: ");
	gets(password);
     i=match(zhanghao,password);
     if(i==1)
	 {
	   strcpy(user,zhanghao);
	   Borrow_And_Return_Main();
	 }
	 if(i==2)
	 {
	   strcpy(user,zhanghao);
	   Management_Main(); 
	 }
	 else
	 {
	 	if(i==-1)
		 {
		 printf("\nPassword error!\n");
         Login();
		 }
		 if(i==0)
		 printf("\nThis user does not exist!\n");
		  
		 Login_Main();
	 }
}








int main()
{
	
	Login_Main();
	return 0;
}

