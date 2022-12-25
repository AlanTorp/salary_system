#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <windows.h>
 
 
#define Q 15               //最大字符串长度 
#define N 500              //最大员工数量 
 
 
typedef struct workers{
	int workersID;            //职工工号
	char name[Q];             //职工姓名
	double basicsalary;       //基本工资
}WORKERS;                     //职工信息
 
 
void Menu(int *n);                               //主菜单 
void Payroll();             //建立工资表 
void Average();			 //求工资平均数 
void Sort() ;             //将工资从低到高排序
void Change();             //修改职工的工资信息
int Find();                //按工号查询职工工资信息
void Analyse();            //职工工资统计分析 
void Printworkroll();      //显示工资明细表
void Writefile();          //输出数据并写入 data.txt 文件 
void Deleteemp();          //删除员工信息 
void Maxmin();	       	//求最大最小工资信息 
void Inputfile();           //读取员工数据 

int num=0;
WORKERS work[N];

int main()
{   
	char ch;                                     //ch为检测是否返回主菜单 
	int n,ret;                             //n为操作数,ret判断数 
	Inputfile();
	Sleep(3000);
	while(1){
		system("cls");
		Menu(&n);                                //主菜单 
		
		switch(n){
			case 0:
				system("cls");                   //退出程序 
				printf("退出成功！\n");
				exit(0);
			case 1:
				Payroll(); 			 //建立工资表
				break;
			case 2:
				Writefile();             //写入 data.txt 文件 
				printf("输出数据至txt文件！\n");
				Sleep(2000);
				system("cls");
				break;
			case 3:
				Inputfile();
				printf("\n是否返回主菜单？Y or N\n");
				fflush(stdin);
				ch=getchar();
				if(ch=='N'){
					exit(0);
				}
				break;
			case 4:
				Sort();                  //将工资从低到高排序
				Printworkroll();         //显示工资明细表
				printf("\n是否返回主菜单？Y or N\n");
				fflush(stdin);
				ch=getchar();
				if(ch=='N'){
					exit(0);
				}
				break;
			case 5:
				Change();                //修改职工的工资信息
				printf("\n是否返回主菜单？Y or N\n");
				fflush(stdin);
				ch=getchar();
				if(ch=='N'){
					exit(0);
				}
				break;
			case 6:
				ret=Find();              //按工号查询职工工资信息
				if(ret==0){
					printf("查无此人！");        //反馈查询不到信息 
				}
				printf("\n是否返回主菜单？Y or N\n");
				fflush(stdin);
				ch=getchar();
				if(ch=='N'){
					exit(0);
				}
				break;
			case 7:
				Analyse();               //职工工资统计分析
				printf("\n是否返回主菜单？Y or N\n");
				fflush(stdin);
				ch=getchar();
				if(ch=='N'){
					exit(0);
				}
				break;
			case 8:
					Deleteemp();               //删除职工工资信息 
					printf("\n是否返回主菜单？Y or N\n");
					fflush(stdin);
					ch=getchar();
					if(ch=='N'){
						exit(0);
					}
					break;
			case 9:
				Maxmin();               //求最大最小员工工资信息 
				printf("\n是否返回主菜单？Y or N\n");
				fflush(stdin);
				ch=getchar();
				if(ch=='N'){
					exit(0);
				}
				break;
			case 10:
				Average();               //员工工资统计分析 
				printf("\n是否返回主菜单？Y or N\n");
				fflush(stdin);
				ch=getchar();
				if(ch=='N'){
					exit(0);
				}
				break;
			case 11:
				Printworkroll();
				printf("\n是否返回主菜单？Y or N\n");
					fflush(stdin);
					ch=getchar();
					if(ch=='N'){
						exit(0);
					}
					break;
		}
	}
	return 0;
}
 
 
void Menu(int *n)                                 //主菜单   *n为返回操作数 
{
	int a;
	printf(" ——————职工工资管理系统——————\n");
	printf("|       1.建立职工工资表                 |\n");
	printf("|       2.保存文件                       |\n");
	printf("|       3.读取文件                       |\n");
	printf("|       4.工资从高到低排序               |\n");
	printf("|       5.修改职工工资信息               |\n");
	printf("|       6.查询职工工资信息               |\n");
	printf("|       7.工资信息范围查询               |\n");
	printf("|       8.删除职工工资信息               |\n");
	printf("|       9.求最大最小员工工资信息         |\n");
	printf("|       10.职工工资平均分析              |\n");
	printf("|       11.输出所有员工信息              |\n");
	printf("|       0.退出系统                       |\n");
	printf(" ————————————————————\n");
	printf("提示：请输入数字序号选择对应的操作！\n");
	scanf("%d",&a);
	*n=a;
	system("cls");
}
 
 
void Payroll()               //建立工资表 
{
	char ch;
	do{
		system("cls");
		printf("员工（%d）的信息\n",num+1);
		printf("工号:");
		scanf("%d",&work[num].workersID);
		printf("姓名:");
		scanf("%s",&work[num].name);
		printf("基本工资:");
		scanf("%lf",&work[num].basicsalary);
		printf("是否继续录入？Y or N\n"); 
		fflush(stdin);
		scanf("%c",&ch);
		num++;
	}while(ch=='Y');
	
	system("cls");
}

void Average(){          //计算平均工资 
	int i;
	double sum=0,count=0;
	for(i=0;i<num;i++){
		sum  = sum+work[i].basicsalary;
		count=count+1;
	}
	double ave=sum/count;
	printf("平均收入为：%.2lf\n",ave);
}

void Maxmin() {			//求最大最小工资信息 
	int i;
	int max=0;
	for(i=0;i<num;i++){
		if(work[i].basicsalary>=work[max].basicsalary	){
			max=i;
		}
	}
	int min = max;
	for(i=0;i<num;i++){
		if(work[i].basicsalary<=work[min].basicsalary	){
			min=i;
		}
	}
	printf("最高工资工号%d  姓名：%s  工资为：%.2lf\n",work[max].workersID,work[max].name,work[max].basicsalary);
	printf("最低工资工号%d  姓名：%s  工资为：%.2lf\n",work[min].workersID,work[min].name,work[min].basicsalary);
}

void Sort()                 //将工资从低到高排序
{
	int i,j;
    WORKERS temp;
	for (i=0;i<num-1;i++)
	{
		for(j=i+1;j<num;j++)    
		{
			if (work[i].basicsalary>work[j].basicsalary)
			{
				temp=work[j];
                work[j]=work[i];
                work[i]=temp;
			} 
		}	
	}
} 

void Deleteemp(){			//删除员工工资信息 
	printf("请输入需要删除的员工工号\n") ;
	int del,i,j;
	scanf("%d",&del);
	for(i=0;i<num;i++){
		if(work[i].workersID==del){
			for(j=i;j<num;j++){
				work[j]=work[j+1];
			}
			printf("删除成功！\n");
			num=num-1;
			break;
		}
	}
}
 
 
void Change()               //修改职工的工资信息
{
	int n,i,sum;
	char ch;
	printf("修改职工的工资信息\n\n");
	printf("请输入你的工号：");
	scanf("%d",&n);
	putchar('\n');
	for( i=0;i<num;i++){
		if(work[i].workersID==n){
			printf("工号:%-10d\n",work[i].workersID);
			printf("姓名:%s\n",work[i].name); 
			printf("基本工资:%6.2lf\n",work[i].basicsalary); 
			printf("\n是否需要修改信息？Y or N\n");
			fflush(stdin);
			scanf("%c",&ch);
			if(ch=='Y'){
				printf("\n基本工资:");
				scanf("%lf",&work[i].basicsalary);
				system("cls");
				printf("员工信息修改成功！\n\n");
				printf("基本工资:%6.2lf\n",work[i].basicsalary); 
				break;	
			}
			else{
				break;
			}	
		}
	}
} 
 
 
int Find()                  //按工号查询职工工资信息
{
	int s,i,flag=0;
	printf("查询职工工资信息\n\n");
	printf("请输入您的工号：");
	scanf("%d",&s);
	putchar('\n');
	for(i=0;i<num;i++)
	{
		if(work[i].workersID==s)                 //查询输入的工号并调用信息； 
		{
			flag=1; 
			printf("工号:%d\n",work[i].workersID);
			printf("姓名:%s\n",work[i].name); 
			printf("基本工资:%.2lf\n",work[i].basicsalary); 
			break;
		}
    }
    return flag;
}
 
 
void Analyse()              //职工工资统计分析
{
	int i;
	double j,k;
	int count=0;
	int arr[num];
	printf("请输入工资的范围\n");
	scanf("%lf",&j);
	scanf("%lf",&k);
	for(i=0;i<num;i++){
		if(work[i].basicsalary>=j&&work[i].basicsalary<=k){
			arr[count]=i;
			count++;
		}
	}
	printf("符合条件的人共有%d人:\n",count);
	for(i=0;i<count;i++){
		printf("工号：%d姓名：%s工资：%.2lf\n",work[arr[i]].workersID,work[arr[i]].name,work[arr[i]].basicsalary);
	}
	
}
 
 
void Printworkroll()        //显示工资明细表
{int i;
	printf("工号\t姓名\t基本工资\n");
	for(i=0;i<num;i++){
		printf("%d\t",work[i].workersID);
		printf("%s\t",work[i].name); 
		printf("%.2lf\t\n",work[i].basicsalary);
	}
}
 
 
void Writefile()            //写入 data.txt 文件
{ 	
	int i,j;
	WORKERS temp;
	for(i=0;i<num-1;i++)						//排序 
	{
		for( j=i+1;j<num;j++)
		{
			if(work[i].workersID>work[j].workersID)
			{
			    temp=work[i];
			    work[i]=work[j];
			    work[j]=temp;
			}
		}
	}
	
	FILE *fp;
	if((fp=fopen("data.txt","w"))==0){
		printf("错误！\n");
		exit(0);
	}
	fprintf(fp,"%d\n",num);
	for(i=0;i<num;i++){
		fprintf(fp,"%d\n",work[i].workersID);
		fprintf(fp,"%s\n",work[i].name); 
		fprintf(fp,"%.2lf\n",work[i].basicsalary);
	}
	fclose(fp);
}

void Inputfile()
{
	FILE *fp;
	int count=0;
	if((fp=fopen("data.txt","r"))==0){
		printf("错误！\n");
		exit(0);
	}
	fscanf(fp,"%d\n",&num);
	for(int i=1;i<=num*3;i++){
		if(i%3==1){
			fscanf(fp,"%d",&work[count].workersID);
		}
		else if(i%3==2){
			fscanf(fp,"%s\n",&work[count].name);
		}
		else{
			fscanf(fp,"%lf\n",&work[count].basicsalary);
			count ++;
		}
	}
	printf("读取到了%d条数据\n",num);
	Printworkroll();
	fclose(fp);
}


