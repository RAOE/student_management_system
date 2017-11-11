#define LG (sizeof(struct student))
struct student
{
  char name[10];//保存学生姓名
  char sex[5];//保存学生的性别
  long int num;//学号
  int xuhao;//
  int age;
  float score[3];
  float averange;//平均分
  char DJ;//存放等级哦
  struct student *next;

       };//定义结构体变量保存 名字 性别 年龄 成绩]   结构体声明
int n;//存放学生人数
int man;//存放统计的男生数
int time=3000;//定义全局变量暂停时间
float JY(float a)//成绩校验函数
{
	int n=0;
	while(1)
	{
	if(a>100||a<0)
	{
    printf("          输入成绩有误,范围应该0-100，请重新输入：");
	scanf("%f",&a);
	n=n+1;
	}
	else
	{
	return a;
	}
	}
}
struct student *creat(void)// 链表创建函数
{
    struct student *head;//头指针 
    struct student *p1,*p2,*p3;// 其他指针 
    int mm=0;
    int m=1;
       n=0;
       p1=p2=(struct student *)malloc(LG); // 开辟内存空间 
	  if(p1==NULL)
	  {
	  printf("开辟内存空间失败\n");
	  }
	   //内存空间开辟后最后一定要释放
	   printf("请先输入学号(输入0退出录入)\n");
	   printf("   ");
	   p1->xuhao=m;
	   m++;
	   scanf("%d",&p1->num);
	   if(p1->num!=0)
	   {
	   printf("  请输入您的姓名\n");
	   printf("    ");
       scanf("%s",&p1->name);
	   printf("  你好,%s!",p1->name);
       printf("请输入您的性别male or female\n");
	  //mm=sexJY((char*)p1->sex);//char **类型与char *类型不兼容  需要强制转换为char*类型
	   printf("    ");
       scanf("%s",&p1->sex);   
	   mm=sexJY(p1->sex);
	   if(mm==1)
	   {         
          printf("   请输入三科成绩,（语文成绩，数学成绩，外语成绩）\n");
		  printf("                   第一科的成绩是:");
          scanf("%f",&p1->score[0]); 
		  p1->score[0]=JY(p1->score[0]);//校验第一科的成绩	  
		  printf("                   第二科的成绩是:");
		  scanf("%f",&p1->score[1]); 
		  p1->score[1]=JY(p1->score[1]);//校验第二科的成绩
		  printf("                   第三科的成绩是:");
		  scanf("%f",&p1->score[2]);
		  p1->score[2]=JY(p1->score[2]);//校验第三科的成绩
          printf("                   录入完毕\n");
	      
		  _sleep(1000);
		  printf("-----------------------------------------------------------------------------------------------------------------\n");

	   }  
	   } 
 
 head=NULL;
 while(1)
 {
	n=n+1;
    if(n==1) 
    {
      head=p1;  
            }     
    else 
	{
     p3=(struct student *)malloc(LG);

	printf("请先输入学号(输入0退出录入)\n");
	printf("   ");
	p3->xuhao=m;
	m++;
	scanf("%d",&p3->num);

	if(p3->num!=0)
	   {
	   printf("  请输入您的姓名\n");
	   printf("    ");
       scanf("%s",&p3->name);
	   printf("  你好,%s!",p3->name);
       printf("请输入您的性别male or female\n");
	   printf("    ");
       scanf("%s",&p3->sex);  
	     mm=sexJY(p3->sex);//char **类型与char *类型不兼容  需要强制转换为char*类型
	     if(mm==1)
	       {
	          
            printf("   请输入三科成绩,（语文成绩，数学成绩，外语成绩）\n");
		    printf("                   第一科的成绩是:");
            scanf("%f",&p3->score[0]); 
		    p3->score[0]=JY(p3->score[0]);//校验第一科的成绩	 
		    printf("                   第二科的成绩是:");
		    scanf("%f",&p3->score[1]);
		    p3->score[1]=JY(p3->score[1]);//校验第二科的成绩
		    printf("                   第三科的成绩是:");
		    scanf("%f",&p3->score[2]);
	        p3->score[2]=JY(p3->score[2]);//校验第三科的成绩
            printf("                   录入完毕\n");
			 _sleep(1000);
		    printf("-----------------------------------------------------------------------------------------------------------------\n");
			
			p2->next=p3;
            p2=p3;
			printf("%d",n);
	      }
	   }
	else
	{
	n--;
	break;
	}
	}

 }

p2->next=NULL;
return (head);
}////结构体链表创
void body()//界面设计
{   
/*
char stCmd[128];
sprintf("mode con cols=%d lines=%d", height, width);
system(stCmd);动态设置窗体大小
*/
	system("mode con cols=120 lines=40");
	//system("color f4");
    printf("\n   ----------------------------------------------- 学生成绩管理系统-----------------------------------------------\n"); 
    printf("\n");
	printf("\n");
    printf("                                             ===========================\n");
    printf("                                               =     请先输入数据     =\n");
    printf("                                             ===========================\n");
     printf("                   请输入学生的信息，包含姓名、性别、年龄 、语文成绩、数学成绩、外语成绩。\n \n \n");
	printf("   ---------------------------------------------------------------------------------------------------------------\n   "); 
    printf("\n");
}
void body2()//界面设计
{
    printf("\n   ----------------------------------------- 学生成绩管理系统-----------------------------------------------\n"); 
    printf("\n");
	printf("\n");
    printf("                                      ==========================\n");
    printf("                                          =      欢迎    =\n");
	printf("                                           该系统共有%d个学生\n",n);
    printf("                                      ===========================\n");
}
int showdata(struct student *head)//功能界面，
{
    struct student *p,*p1;
	int sexJY(char *sex);//性别校验函数
	void *dell(struct student *head);//摧毁函数
	struct student *del(struct student *head);
	struct student *del2(struct student *head);
    long int search(struct student *head);//查找功能
	int showdata3(struct student *head);//系统设置
	void print1(struct student *head);//打印功能1
	void print2(struct student *head);//打印功能2
    void print3(struct student *head);//打印功能3
	void out1(struct student *head);//输出到文件功能
	struct student *add(struct student *head);//添加功能
	void cont(struct student *head);//计算功能1
	void  change1(struct student*head);//修改功能
	struct student* input1();//外部导入功能
	//void input1(struct student *head);//录入功能
	//void change1(struct student*head, long int i)//修改功能 
	struct student *add(struct student *head);//插入数据
	struct student*nsert(struct student *head);
	void sort(struct student *head);//排序功能
//	void destroy1(struct student *head);//摧毁链表
	int TJ(struct student *head);//男生计算功能
    int i;//存放学生编号 
	int iii;//存放选择显示参数
    int j;//存放选择参数 
	int o;//选择颜色参数
	int num;//存放需要删除的节点 
    long int ii;//存放需要修改的学生编号
	long int jj;//存放需要查找的学生编号
    char a;
    

p=head; 

	while(1)
{
    body2();
    printf("\n");
	printf("\n");
    printf("\n---------- 学生成绩管理系统------------\n"); 
    printf("\n");
    printf("     1  ======================\n");
    printf("       =       主菜单       =\n");
    printf("       ======================\n");
    printf("\n");
    printf("      请根据需要选择操作\n");
    printf("\n");
    printf("      选择查询的方式\n");
	printf("     (0) 输入0退出该系统\n");
    printf("    （1）增加一个同学信息                                                         \n");
    printf("    （2）删除一个同学信息                                                            \n");
    printf("    （3）修改一个学生信息                                                            \n");//完成
	printf("    （4）计算学生的三科平均分并且给予等级                                             \n");//完成
	printf("    （5）显示所有学生的信息                                                              \n");//完成
	//printf("     (6) 设置系统背景                                                              \n");//完成
	printf("     (6) 数据存盘                                                  \n");//完成
	printf("     (7) 查找一个学生的信息\n");
	printf("     (8) 统计男生的人数\n");
	printf("     (9) 局部显示学生的信息\n");
	printf("     (10)系统设置\n");
	printf("     (11)排序 \n");//实现排序功能，对总分进行排序？并返回链表
	//printf("     (12) 删除所有学生的数据\n");
	//printf("     (13) 数据存盘\n       ");
	printf("     请选择1-11\n");

    scanf("%d",&j);//选择不同的功能
	if(j==0)
	{
	break;
	}
	if(j>=1&&j<=11)
	{
    switch(j)
    {
		 case 1:
         add(p);
         _sleep(time);
		 system("cls");//清屏操作 
         break;
         case 2:  
         p=del(p);
         _sleep(time);
		 system("cls"); 
         break;
         case 3:
         print3(p);
		 change1(p);
		 break;
	 //    change1(p,ii);
		 system("cls"); 
         break;
		 case 4:
		 cont(p);
	     //rank(stu);
		 _sleep(time);
		 system("cls"); 
		 break;
		 case 5:
	     print3(p);
        _sleep(time);				 
		 break;
		 case 6:
			 out1(p);
			 _sleep(time);
			 break;
		/* case 6:
		 printf("请选择颜色\n");
		 printf("（1）天蓝色");
		 printf("（2）红色");
		 printf(" (3) 白色 ");
		 printf(" (4) 亮白色 ");
		 printf(" (5)绿色 ");
		 scanf("%d",&o);
		 switch(o)
		 {
		 case 1:
	     system("color 0B");
		 break;
		 case 2:
		 system("color 0C");
		 break;
		 case 3:
		 system("color 07");
		 break;
		 case 4:
		 system("color 0F");
		 break;
		 case 5:
          system("color 0A");
		 break;
	     default://其他值均为默认
			system("color 07");
		 break;
		 }
		 break;*/
		 case 7:
			 printf("请输入要查找的学生学号");
			 search(p);
			_sleep(time);
		     break;
		 case 8:
			 TJ(p);//计算男生人数
		_sleep(time);
		    break;
		 case 9:
			 showdata2(p);
			 _sleep(time);
			// _sleep(5000); 
		    break;
		 case 10://系统设置
			 showdata3(p);
			 _sleep(time);
			 break;
			 
	     case 11:
		    sort(p);
			time=time*1000;
			_sleep(time);
			break;
			
		 /*case 12:
			 printf("正在摧毁链表\n");
			 dell(p);
			 time=time*1000;
			_sleep(time);*/
		 /*case 13:
			 out1(p);
			 _sleep(time);
			 */

       }
 }
	else
	{
	printf("输入错误\n");
	_sleep(time);
	system("cls");
	}


	   }

     }
int showdata2(struct student *head)
{

    struct student *p;

	int sexJY(char *sex);//性别校验函数
	struct student *del(struct student *head);
	struct student *del2(struct student *head);//删除功能2
//	long int search(struct student *head,long int i);//查找功能
	void print1(struct student *head);//打印功能1
	void print2(struct student *head);//打印功能2
    void print3(struct student *head);//打印功能3
	void cont(struct student *head);//计算功能1
	void  change1(struct student*head);
	struct student *add(struct student *head);//插入数据
	struct student*nsert(struct student *head);
	int TJ(struct student *head);//男生计算功能
	int iii;//存放学生的查询参数
	p=head;
	system("cls");//清屏
	printf("     1  ======================\n");
    printf("       =       副菜单       =\n");
    printf("       ======================\n");
	printf("     选择查询的方式\n");
	printf("\n  1.显示所有学生的成绩\n");
    printf("\n  2.显示所有学生的学号性别\n");
	printf("\n  3.显示所有学生的所有信息\n");
	printf("     请选择1-3\n");
			 scanf("%d",&iii);
			
			 switch (iii)
			 {
			 case 1:
				 print2(p);
				  _sleep(1000);
				 break;
			 case 2:
				 print1(p);
				 _sleep(1000);
				 break;
			 case 3:
				 print3(p);
				 _sleep(1000);
				 break;
			 default:
				 printf("输入错误,返回主菜单\n");
				 break;
			 }

			 return 0;

}//二级菜单 
int showdata3(struct student *head)//系统设置选项
{
	struct student *p;
	int iii;
	int o;
	p=head;
	system("cls");//清屏
	printf("     1  ======================\n");
    printf("       =       副菜单       =\n");
    printf("       ======================\n");
	printf("     选择查询的方式\n");
	printf("\n (1). 设置系统背景     \n");
    printf("\n (2). 修改系统延时     \n");
	printf("\n (3). 删除链表所有数据并重新读入\n");
	printf("     请选择1-2\n");
	 scanf("%d",&iii);
			
		 switch (iii)
			 {
		 case 1:
		 printf("请选择颜色\n");
		 printf("（1）天蓝色");
		 printf("（2）红色");
		 printf(" (3) 白色 ");
		 printf(" (4) 亮白色 ");
		 printf(" (5)绿色 ");
		 scanf("%d",&o);
	     switch(o)
		 {
		 case 1:
	     system("color 0B");
		 break;
		 case 2:
		 system("color 0C");
		 break;
		 case 3:
		 system("color 07");
		 break;
		 case 4:
		 system("color 0F");
		 break;
		 case 5:
          system("color 0A");
		 break;
	     default://其他值均为默认
			system("color 07");
		 break;
		 }
		   _sleep(1000);
			 break;
			case 2:
			printf("输入暂停时间(s),默认3s\n");
			scanf("%d",&time);
			time=time*1000;
			_sleep(time);
			break;
			case 3:
			printf("正在摧毁链表\n");
			 dell(p);
			 time=time*1000;
			_sleep(1000);
			break;
			 default:
				 printf("输入错误,返回主菜单\n");
				 break;
			 }

			 return 0;

}
void print1(struct student *head)
{
	struct student *p;
	p=head;
	if(head==NULL)
	{
	exit(0);
	}
	printf("------------------------------------------------------------------------------------------------------------------\n");
	do
	{
		printf("\n 姓名:%s,学号%d,%s\n\n",p->name,p->num,p->sex);//姓名，学号
		p=p->next;
	}while(p!=NULL);
}//不同显示数据的方式 第一种
void print2(struct student *head)//显示所有学生的成绩
{
	struct student *p;
	p=head;
	if(head==NULL)
	{
	exit(0);
	}
	printf("------------------------------------------------------------------------------------------------------------------\n");
	do
	{
		printf("\n\n 姓名%s,语文:%3.1f,数学:%3.1f,外语:%3.1f\n",p->name,p->score[0],p->score[1],p->score[2]);
		p=p->next;
	}while(p!=NULL);
}//不同显示数据的方式 第二种
void print3(struct student *head)
{
	float a;
	struct student *p;
 	p=head;
	if(head==NULL)
	{
	exit(0);
	}
 	
		printf("------------------------------------------------------------------------------------------------------------------------------------------");
	while(p!=NULL)
		{
		printf("\n\n序号 %d 学号 %ld 姓名:%s   性别: %s   语文: %3.1f    数学:%3.1f   外语:%3.1f",p->xuhao,p->num,p->name,p->sex,p->score[0],p->score[1],p->score[2]);//姓名，性别
		a=p->score[0]+p->score[1]+p->score[2];
       

		printf(" 总分:%3.1f",a);
		printf("  等级%c\n",p->DJ);
		p=p->next;
}
}
int passwd(char *name, char *pwd) 
{
   int u = 0;
    if (strcmp(name, "root") == 0 && strcmp(pwd, "123456") == 0)
        {
			u =1;
			return u;
	     }
   else if (strcmp(name, "1") == 0 && strcmp(pwd, "1") == 0)
       {
		   u = 1;
		   return u;
     	}
	return 0;
}//密码校验函数 传递两个字符数组，一个账号，一个密码。
void  change1(struct student*head)
{
   long int i;
    struct student *p;
    p=head;//定义指针
 if(head==NULL)
	{
	exit(0);
	}
printf("输入想要修改的学生的学号:\n");
scanf("%ld",&i);
do
{	
//printf("test1");
	if(p->num==i)//当结点跳转到该学生时修改成绩
{
 
      printf("开始修改信息\n");
       printf("请先输入学号\n");
	   printf("   ");

	   scanf("%ld",&p->num);
	   if(p->num!=0)
	   {
	   printf("  请输入您的姓名\n");
	   printf("    ");
       scanf("%s",&p->name);
	   printf("  你好,%s!",p->name);
       printf("请输入您的性别male or female\n");

	   printf("    ");
       scanf("%s",&p->sex);         
       printf("   请输入三科成绩,（语文成绩，数学成绩，外语成绩）\n");
		  printf("                   第一科的成绩是:");
          scanf("%f",&p->score[0]); 
		  p->score[0]=JY(p->score[0]);//校验第一科的成绩	  
		  printf("                   第二科的成绩是:");
		  scanf("%f",&p->score[1]); 
		  p->score[1]=JY(p->score[1]);//校验第二科的成绩
		  printf("                   第三科的成绩是:");
		  scanf("%f",&p->score[2]);
		  p->score[2]=JY(p->score[2]);//校验第三科的成绩
          printf("                   录入完毕\n");
		  printf("-----------------------------------------------------------------------------------------------------------------\n");
		break;  
	   } 
	 p=p->next;//需要把下一个结点赋值给p
	 
	}


} while(p->next!=NULL);







}
void cont(struct student *head)//计算学生等级函数
{
	struct student *p;
	int i=0;
	p=head;
	if(head==NULL)
	{
	exit(0);
	}
	printf("------------------------------------------------------------------------------------------------------------------\n");
	printf("----------------------------------------计算中----------------------------------------\n");
		do{
			p->averange=((p->score[0])+(p->score[1])+(p->score[2]))/3.0;
			printf("第%d同学的成绩为%3.1f",i+1,p->averange);
			
		        	if(p->averange>=90&&p->averange<=100)
                    { 
					
                   printf("         等级为A\n",i+1);
				   p->DJ='A';
                     }
                    if(p->averange>=60&&p->averange<=89)
                     {
						 		
                   printf("         等级为B\n",i+1);
				   p->DJ='B';
                      }
                    if(p->averange>=0&&p->averange<=60)
                      {
				
                   printf("          等级为C\n",i+1);
				   p->DJ='C';
                      }
                   if(p->averange>100||p->averange<0)
                   {
					   		
                   printf("          incorrect\n");
                    }
			i=i+1;
			p=p->next;
		
		
		
		}while(p!=NULL);

	
}
long int search(struct student *head)//通过学号来查找学生的信息
{
struct student *p;
long jj;

scanf("%ld",&jj);
p=head;
if(head==NULL)
	{
	exit(0);
	}
do{
	if(jj==p->num)
	{
	printf("\n\n学号 %ld 姓名:%s   性别: %s   语文: %3.1f    数学:%3.1f   外语:%3.1f  等级%c\n",p->num,p->name,p->sex,p->score[0],p->score[1],p->score[2],p->DJ);
	return 0;
	}


	p=p->next;
}while(p->next!=NULL);
//遍历链表结点

printf("无该生信息\n");
return 0;




}
/*struct student *del2(struct student *head)
{
   struct student *p=head;
   head=head->next;
   free(p);
   n=n-1;

   return head;


}*/
struct student *del(struct student *head)
{
	int i,j;
	struct student *p1,*p2;
	if(head==NULL)
	{
    printf("空指针异常");
    _sleep(3000);
	exit(0);
	}
	p1=head;
	p2=head;
 printf("输入需要删除的结点");
 scanf("%d",&i);
if(i>n)
{
printf("输入了错误的结点");
_sleep(1000);
return head;
}		
for(j=1;j<i;j++)
 {
  p2=p1;
  p1=p1->next;
 }
if(p1==head)
{
   head=head->next;
   free(p1);
   return head;
}
else
{
  p2->next=p1->next;
}


 free(p1);
 n=n-1;
 printf("\n**********删除中 稍后*********\n");
return head;
}
struct student*nsert(struct student *head)
{
 struct student *p1,*p,*q;
 int i = 1;
 int jj;
 int mm;
 int nn;
 if(head==NULL)
	{
	exit(0);
	}
 
 printf("要插入的位置(尾插)1-%d:",n);
 scanf("%d",&jj);//所要插入第几位学生信息
 if(jj>=1&&jj<=n)
 {


 p = head->next ;
 p1 = (struct student *)malloc(sizeof(struct student));
    printf("请先输入学号(输入0退出录入)\n");
	printf("   ");
    scanf("%ld",&p1->num);
	if(p1->num!=0)
	 {
		p1->xuhao=jj+1;
	   printf("  请输入您的姓名\n");
	   printf("    ");
       scanf("%s",&p1->name);
	   printf("  你好,%s!",p1->name);
       printf("请输入您的性别male or female\n");

	   printf("    ");
       scanf("%s",&p1->sex);     
	    mm=sexJY((char*)p1->sex);//char **类型与char *类型不兼容  需要强制转换为char*类型
	   if(mm==1)
	   {
       printf("   请输入三科成绩,（语文成绩，数学成绩，外语成绩）\n");
	   printf("                   第一科的成绩是:");
       scanf("%f",&p1->score[0]); 
	    p1->score[0]=JY(p1->score[0]);//校验第一科的成绩	  
	    printf("                   第二科的成绩是:");
		 scanf("%f",&p1->score[1]); 
		 p1->score[1]=JY(p1->score[1]);//校验第二科的成绩
		 printf("                   第三科的成绩是:");
		 scanf("%f",&p1->score[2]);
		 p1->score[2]=JY(p1->score[2]);//校验第三科的成绩
         printf("                   录入完毕\n");
		  n=n+1;//系统学生数自增1
		 printf("-----------------------------------------------------------------------------------------------------------------\n");
	   }
	}
 
 if(1 == jj)
 {
  struct student*q = head->next ;
  head->next = p1;
  p1 ->next = q; 
 }
 else
 while( p )
 {
  if(i == (jj-1))
  {
   struct student*q  = p->next ;
   p->next = p1;
   p1->next = q;
  }
  p = p->next ;
  i++;
 }

 return p;

}
 else
 {
	 printf("\n---------录入错误---------\n");
	 printf("请重试\n");
	 return head;
}
}
int sexJY2(char *sex) 
{
   int u = 0;
   if (strcmp(sex,"male") == 0)
        {
			u =1;
			return u;
	     }
    return 0;
}
int sexJY(char *sex) 
{
   int u = 0;
   while(1)
   {
   if (strcmp(sex, "male") == 0 || strcmp(sex, "female") == 0)
        {
			u =1;
			return u;
	     }
   else
   {
	   printf("性别错误请重新输入\n");
	   scanf("%s",sex);
 
   }
   }
}
int TJ(struct student *head)
{
	int sexJY2(char *sex);
	int mm;
	int nn;
	struct student *p;
	man=0;
	if(head==NULL)
	{
	exit(0);
	}
	p=head;
	do
	{    
		nn=sexJY((p->sex));//强制转换
	
	 if(nn==1)
		{
		man++;
		}

		p=p->next;//一直向下指直到

	
	
	}while(p!=NULL);

	printf("\n男生人数为:%d\n",man);
	return 0;
}//遍历整个链表 计算男生的人数
int in()
{

	int i,j;
	int m;
	int n=0;//如果密码输入错误三次则跳出循环
	char user[20]={'0'};
	char pas[20]={'0'};
	char aa[20]={' ','U','s','e','r',' ','N','a','m','e',':'};//输出账号登陆
	char bb[20]={' ','P','a','s','s','w','o','r','d',':'};
	system("mode con cols=45 lines=15");
	while(1)
   {
    printf("\n");
    for(i=0;i<12;i++)
	{
	   printf("%c",aa[i]);
	   _sleep(50);
	
	}
	  //printf(" User Name:");
	 gets(user);//输入账号
	 for(i=0;i<10;i++)
	 {
	    printf("%c",bb[i]);
	    _sleep(50);
	
	 }
	 gets(pas);//如何隐藏输入的密码 安全性getch(); printf("*");
	m=passwd(user,pas);
	if(m==1)
	{
	 return m;
	}
	else
	{
    n++;  
	printf("incorrect please try again\n");
	if(n==3)
	{
	system("color 04");
	system("cls");
    while(1)
	{
	printf("快滚出老子的魔仙堡！！！！\n");
	_sleep(1000);
	}
	return 0;
	}
	}
}
}
struct student *add(struct student *head)
{
 struct student *p,*p1,*p2;
 int i = 1;
 int jj;
 int mm;
 int nn;
 p=head;
 printf("输入要插入的位置1-%d:  ",n);
 scanf("%d",&i);
 jj=i;

    p1=(struct student*)malloc(LG);//开辟p1内存空间
    p2=(struct student*)malloc(LG);//开辟p2内存空间
    printf("请先输入学号(输入0退出录入)\n");
	printf("   ");
    scanf("%ld",&p1->num);
	if(p1->num!=0)
	 {
		p1->xuhao=jj+1;
	   printf("  请输入您的姓名\n");
	   printf("    ");
       scanf("%s",&p1->name);
	   printf("  你好,%s!",p1->name);
       printf("请输入您的性别male or female\n");

	   printf("    ");
       scanf("%s",&p1->sex);     
	    mm=sexJY((char*)p1->sex);//char **类型与char *类型不兼容  需要强制转换为char*类型
	   if(mm==1)
	   {
       printf("   请输入三科成绩,（语文成绩，数学成绩，外语成绩）\n");
	   printf("                   第一科的成绩是:");
       scanf("%f",&p1->score[0]); 
	    p1->score[0]=JY(p1->score[0]);//校验第一科的成绩	  
	    printf("                   第二科的成绩是:");
		 scanf("%f",&p1->score[1]); 
		 p1->score[1]=JY(p1->score[1]);//校验第二科的成绩
		 printf("                   第三科的成绩是:");
		 scanf("%f",&p1->score[2]);
		 p1->score[2]=JY(p1->score[2]);//校验第三科的成绩
         printf("                   录入完毕\n");
		 printf("-----------------------------------------------------------------------------------------------------------------\n");
	   }
	}
	if(i==1)//如果插入点为头部head 则
	{
     p2=head->next;
	 head->next=p1;
	 p1->next=p2;
	 n=n+1;//系统学生数自增1
	 return head;
	}
	else
	{
		p=head;
		if(i==n)
		{
		//如果输入等于n
	    while(p->next!=NULL)
		{
		p=p->next;
		}
		p->next=p1;
		p1->next=NULL;
		//插入函数写完后一定要把指针指向空
		//printf("%d",p1->xuhao);
		n=n+1;
	    return head;
		
		}
		else
		{
			//如果不是头也不是尾巴
			//则从中间插
			while(i--)
			{
				p=p->next;
			
			}
		//	printf("已找到");
			p2=p->next;
			p->next=p1;
			p1->next=p2;
			n=n+1;
		return head;

		}
	}
}
void *dell(struct student *head)
{
struct student *p=head;
free(p);
printf("\n\n链表已摧毁\n\n");


}
int choose(int i)
{
    printf("\n   ----------------------------------------------- 学生成绩管理系统-----------------------------------------------\n"); 
    printf("\n");
	printf("\n");
	printf("                                           请选择信息录入的方式\n");
    printf("                                         ===========================\n");
    printf("                                         =   （1）手动输入       =\n");
	printf("                                         =   （2）通过外部导入信息 =\n");
    printf("                                        ===========================\n");
	 printf("                                            请选择:");
	while(1)
	{
	 scanf("%d",&i);
	 if(i==1||i==2)
	 {
	//printf("%d",n);
	return i;
	 }
	 else
	 {
	 printf("\n                                        请输入一个有效的值:");
	 }
	 
	 }


}
void load()
{
printf("\n该功能还在完善中\n    敬请期待\n");

}
//实现输出输入文件的功能
void out1(struct student *head)
{
FILE *out;
struct student *p;
char outfile[20];
char ch;
int i;
ch=getchar();
if((out=fopen("stu.txt","wb"))==NULL)
{
	printf(" 找不到输出文件");
	exit(0);
}
p=head;
while(p!=NULL)
{
	if(fwrite(p,LG,1,out)!=1) 
	{  
            printf("\n写入数据出错\n");  
            fclose(out);  
            return;  
        }  
	p=p->next;
} 
    fclose(out);  
}  
struct student *input1 () 
{  
    struct student *head = NULL;  
    struct student *p1, *p2;//s = p1;p = p2;  
  
    FILE *fp;  
    if((fp=fopen("stu.txt","rb+"))==NULL)  
    {  
        printf("打开文件出错\n");  
        exit(0);  
    }  
    while(!feof(fp)) {  
        if((p1=(struct student*)malloc(LG))==NULL){  
            printf("内存申请出错\n");  
            fclose(fp);  
            exit(0);  
        }  
        if(fread(p1,LG,1,fp)!=1){  
            free(p1);  
            break;  
        }  
        if(head==NULL)  
		{
		head=p2=p1;
		n=n+1;
		}    
        else{  
            p2->next=p1;  
            p2=p1;
			n=n+1;
        }  
    }  
    fclose(fp);  
    return (head);  
}  
/*   struct head 链表头指针
 *   return 返回新的链表
 *    
 */
void sort(struct student *head)
{ 

float num;// 暂时存放
int i;
struct student *p;
p=head;

//定义一个指针指向表
num=p->averange;

while(p!=NULL)
{
if(num<(p->averange))
{
   num=p->averange;
}
p=p->next;

}
printf("平均分最大的：%5.2f",num);



}
