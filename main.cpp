#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <windows.h>
 
 
#define Q 15               //����ַ������� 
#define N 500              //���Ա������ 
 
 
typedef struct workers{
	int workersID;            //ְ������
	char name[Q];             //ְ������
	double basicsalary;       //��������
}WORKERS;                     //ְ����Ϣ
 
 
void Menu(int *n);                               //���˵� 
void Payroll();             //�������ʱ� 
void Average();			 //����ƽ���� 
void Sort() ;             //�����ʴӵ͵�������
void Change();             //�޸�ְ���Ĺ�����Ϣ
int Find();                //�����Ų�ѯְ��������Ϣ
void Analyse();            //ְ������ͳ�Ʒ��� 
void Printworkroll();      //��ʾ������ϸ��
void Writefile();          //������ݲ�д�� data.txt �ļ� 
void Deleteemp();          //ɾ��Ա����Ϣ 
void Maxmin();	       	//�������С������Ϣ 
void Inputfile();           //��ȡԱ������ 

int num=0;
WORKERS work[N];

int main()
{   
	char ch;                                     //chΪ����Ƿ񷵻����˵� 
	int n,ret;                             //nΪ������,ret�ж��� 
	Inputfile();
	Sleep(3000);
	while(1){
		system("cls");
		Menu(&n);                                //���˵� 
		
		switch(n){
			case 0:
				system("cls");                   //�˳����� 
				printf("�˳��ɹ���\n");
				exit(0);
			case 1:
				Payroll(); 			 //�������ʱ�
				break;
			case 2:
				Writefile();             //д�� data.txt �ļ� 
				printf("���������txt�ļ���\n");
				Sleep(2000);
				system("cls");
				break;
			case 3:
				Inputfile();
				printf("\n�Ƿ񷵻����˵���Y or N\n");
				fflush(stdin);
				ch=getchar();
				if(ch=='N'){
					exit(0);
				}
				break;
			case 4:
				Sort();                  //�����ʴӵ͵�������
				Printworkroll();         //��ʾ������ϸ��
				printf("\n�Ƿ񷵻����˵���Y or N\n");
				fflush(stdin);
				ch=getchar();
				if(ch=='N'){
					exit(0);
				}
				break;
			case 5:
				Change();                //�޸�ְ���Ĺ�����Ϣ
				printf("\n�Ƿ񷵻����˵���Y or N\n");
				fflush(stdin);
				ch=getchar();
				if(ch=='N'){
					exit(0);
				}
				break;
			case 6:
				ret=Find();              //�����Ų�ѯְ��������Ϣ
				if(ret==0){
					printf("���޴��ˣ�");        //������ѯ������Ϣ 
				}
				printf("\n�Ƿ񷵻����˵���Y or N\n");
				fflush(stdin);
				ch=getchar();
				if(ch=='N'){
					exit(0);
				}
				break;
			case 7:
				Analyse();               //ְ������ͳ�Ʒ���
				printf("\n�Ƿ񷵻����˵���Y or N\n");
				fflush(stdin);
				ch=getchar();
				if(ch=='N'){
					exit(0);
				}
				break;
			case 8:
					Deleteemp();               //ɾ��ְ��������Ϣ 
					printf("\n�Ƿ񷵻����˵���Y or N\n");
					fflush(stdin);
					ch=getchar();
					if(ch=='N'){
						exit(0);
					}
					break;
			case 9:
				Maxmin();               //�������СԱ��������Ϣ 
				printf("\n�Ƿ񷵻����˵���Y or N\n");
				fflush(stdin);
				ch=getchar();
				if(ch=='N'){
					exit(0);
				}
				break;
			case 10:
				Average();               //Ա������ͳ�Ʒ��� 
				printf("\n�Ƿ񷵻����˵���Y or N\n");
				fflush(stdin);
				ch=getchar();
				if(ch=='N'){
					exit(0);
				}
				break;
			case 11:
				Printworkroll();
				printf("\n�Ƿ񷵻����˵���Y or N\n");
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
 
 
void Menu(int *n)                                 //���˵�   *nΪ���ز����� 
{
	int a;
	printf(" ������������ְ�����ʹ���ϵͳ������������\n");
	printf("|       1.����ְ�����ʱ�                 |\n");
	printf("|       2.�����ļ�                       |\n");
	printf("|       3.��ȡ�ļ�                       |\n");
	printf("|       4.���ʴӸߵ�������               |\n");
	printf("|       5.�޸�ְ��������Ϣ               |\n");
	printf("|       6.��ѯְ��������Ϣ               |\n");
	printf("|       7.������Ϣ��Χ��ѯ               |\n");
	printf("|       8.ɾ��ְ��������Ϣ               |\n");
	printf("|       9.�������СԱ��������Ϣ         |\n");
	printf("|       10.ְ������ƽ������              |\n");
	printf("|       11.�������Ա����Ϣ              |\n");
	printf("|       0.�˳�ϵͳ                       |\n");
	printf(" ����������������������������������������\n");
	printf("��ʾ���������������ѡ���Ӧ�Ĳ�����\n");
	scanf("%d",&a);
	*n=a;
	system("cls");
}
 
 
void Payroll()               //�������ʱ� 
{
	char ch;
	do{
		system("cls");
		printf("Ա����%d������Ϣ\n",num+1);
		printf("����:");
		scanf("%d",&work[num].workersID);
		printf("����:");
		scanf("%s",&work[num].name);
		printf("��������:");
		scanf("%lf",&work[num].basicsalary);
		printf("�Ƿ����¼�룿Y or N\n"); 
		fflush(stdin);
		scanf("%c",&ch);
		num++;
	}while(ch=='Y');
	
	system("cls");
}

void Average(){          //����ƽ������ 
	int i;
	double sum=0,count=0;
	for(i=0;i<num;i++){
		sum  = sum+work[i].basicsalary;
		count=count+1;
	}
	double ave=sum/count;
	printf("ƽ������Ϊ��%.2lf\n",ave);
}

void Maxmin() {			//�������С������Ϣ 
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
	printf("��߹��ʹ���%d  ������%s  ����Ϊ��%.2lf\n",work[max].workersID,work[max].name,work[max].basicsalary);
	printf("��͹��ʹ���%d  ������%s  ����Ϊ��%.2lf\n",work[min].workersID,work[min].name,work[min].basicsalary);
}

void Sort()                 //�����ʴӵ͵�������
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

void Deleteemp(){			//ɾ��Ա��������Ϣ 
	printf("��������Ҫɾ����Ա������\n") ;
	int del,i,j;
	scanf("%d",&del);
	for(i=0;i<num;i++){
		if(work[i].workersID==del){
			for(j=i;j<num;j++){
				work[j]=work[j+1];
			}
			printf("ɾ���ɹ���\n");
			num=num-1;
			break;
		}
	}
}
 
 
void Change()               //�޸�ְ���Ĺ�����Ϣ
{
	int n,i,sum;
	char ch;
	printf("�޸�ְ���Ĺ�����Ϣ\n\n");
	printf("��������Ĺ��ţ�");
	scanf("%d",&n);
	putchar('\n');
	for( i=0;i<num;i++){
		if(work[i].workersID==n){
			printf("����:%-10d\n",work[i].workersID);
			printf("����:%s\n",work[i].name); 
			printf("��������:%6.2lf\n",work[i].basicsalary); 
			printf("\n�Ƿ���Ҫ�޸���Ϣ��Y or N\n");
			fflush(stdin);
			scanf("%c",&ch);
			if(ch=='Y'){
				printf("\n��������:");
				scanf("%lf",&work[i].basicsalary);
				system("cls");
				printf("Ա����Ϣ�޸ĳɹ���\n\n");
				printf("��������:%6.2lf\n",work[i].basicsalary); 
				break;	
			}
			else{
				break;
			}	
		}
	}
} 
 
 
int Find()                  //�����Ų�ѯְ��������Ϣ
{
	int s,i,flag=0;
	printf("��ѯְ��������Ϣ\n\n");
	printf("���������Ĺ��ţ�");
	scanf("%d",&s);
	putchar('\n');
	for(i=0;i<num;i++)
	{
		if(work[i].workersID==s)                 //��ѯ����Ĺ��Ų�������Ϣ�� 
		{
			flag=1; 
			printf("����:%d\n",work[i].workersID);
			printf("����:%s\n",work[i].name); 
			printf("��������:%.2lf\n",work[i].basicsalary); 
			break;
		}
    }
    return flag;
}
 
 
void Analyse()              //ְ������ͳ�Ʒ���
{
	int i;
	double j,k;
	int count=0;
	int arr[num];
	printf("�����빤�ʵķ�Χ\n");
	scanf("%lf",&j);
	scanf("%lf",&k);
	for(i=0;i<num;i++){
		if(work[i].basicsalary>=j&&work[i].basicsalary<=k){
			arr[count]=i;
			count++;
		}
	}
	printf("�����������˹���%d��:\n",count);
	for(i=0;i<count;i++){
		printf("���ţ�%d������%s���ʣ�%.2lf\n",work[arr[i]].workersID,work[arr[i]].name,work[arr[i]].basicsalary);
	}
	
}
 
 
void Printworkroll()        //��ʾ������ϸ��
{int i;
	printf("����\t����\t��������\n");
	for(i=0;i<num;i++){
		printf("%d\t",work[i].workersID);
		printf("%s\t",work[i].name); 
		printf("%.2lf\t\n",work[i].basicsalary);
	}
}
 
 
void Writefile()            //д�� data.txt �ļ�
{ 	
	int i,j;
	WORKERS temp;
	for(i=0;i<num-1;i++)						//���� 
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
		printf("����\n");
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
		printf("����\n");
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
	printf("��ȡ����%d������\n",num);
	Printworkroll();
	fclose(fp);
}


