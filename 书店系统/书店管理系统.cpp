#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
int i,bknum;
FILE *fp;
typedef struct
{
	char isbn[10];//���
	char bkname[20];//����
	char author[10];//����
	float price;//���� 
	int num; //���� 
}BOOK;
BOOK bk[100];
//��ȡ�ļ� 
void rdata()
{
	FILE *fp;
	if((fp=fopen("bookdata.txt","r"))==NULL)
	{
		printf("Can not open the file!\n");
		return;
	}

   while(!feof(fp))
   {
  	fscanf(fp,"%s%s%s%f%d\n",&bk[bknum].isbn,&bk[bknum].bkname,&bk[bknum].author,&bk[bknum].price,&bk[bknum].num);
 	bknum++;
   }
	fclose(fp);
} 
// д���ļ� 
 void wdata()
 {
    FILE *fp;
    if((fp=fopen("bookdata.txt","w"))==NULL)
	{
 		printf("Can not open the file!\n");
 		return;
    }
    for(int i=0;i<bknum;i++)
    {
	fprintf(fp,"%-14s%-22s%-14s%-9.2f%-5d\n",bk[i].isbn,bk[i].bkname,bk[i].author,bk[i].price,bk[i].num);
	fputc('\n',fp);
 	} 
    fclose(fp);
}
// ��ӡָ��λ�õ���Ϣ 
void pb(int i,int j)
{
	if(j!=0)
	{
		printf("\n");
		printf("%-14s%-22s%-14s%-9s%-5s\n","���","����","����","����","����");
		printf("----------------------------------------------------------\n"); 
	}
	if(i!=-1)
	{
		printf("%-14s%-22s%-14s%-9.2f%-5d\n",bk[i].isbn,bk[i].bkname,bk[i].author,bk[i].price,bk[i].num);
	}
}
// ͼ���б��� 
void bklist()
 {
 	int i;
 	system("cls");
 	printf("%-14s%-22s%-14s%-9s%-5s\n","���","����","����","����","����");
 	printf("---------------------------------------------------\n");
 	for(i=0;i<bknum;i++)
 	{
 		printf("%-14s%-22s%-14s%-9.2f%-5d\n",bk[i].isbn,bk[i].bkname,bk[i].author,bk[i].price,bk[i].num);	
    }
	getch();
}
//ͼ��¼�뺯�� 
void bkin()
{
	int i,n1;
	char b[10];
	system("cls");
	printf("\n\n\n");
	printf("----------------------ͼ�����------------------\n");
	printf("------------------------------------------------\n");
	printf("\n\n\n");
	printf("��������ţ�");
	scanf("%s",b);
    if(strcmp(b,"000"))
	{
		int count=0;
		for(i=0;i<bknum;i++)
		{
			if(strcmp(bk[i].isbn,b)==0)
			{
				printf("�����Ѵ��룬�������������\n");
				scanf("%d",&n1);
				bk[i].num+=n1;
				count++;
			}
		}
		if(count==0)
		{
			strcpy(bk[i].isbn,b);
			printf("������������");
			scanf("%s",bk[i].bkname);
			printf("���������ߣ�");
     	    scanf("%s",bk[i].author);
			printf("������۸�");
			scanf("%f",&bk[i].price);
			printf("������������");
			scanf("%d",&bk[i].num);
			bknum++;
		}
	}
	wdata();
}
//ͼ�����ۺ��� 
void bksell()
{
	int i,count=0,a;
	char b[10];
	BOOK s[100];
	float sum=0,in,out;
	system("cls");
	printf("----------------ͼ������----------------\n\n\n");
	printf("\n\n"); 
	printf("��������Ż�����000ֹͣ���㣺>");
   	scanf("%s",b);
	int cou=0;
	while(strcmp(b,"000"))
	{
		
		for(i=0;i<bknum;i++)
		{
			if(strcmp(bk[i].isbn,b)==0)
			{
				cou++;
			    if(bk[i].num>0)
			    {
				s[count++]=bk[i];
				bk[i].num--;
				sum+=bk[i].price;
			    }
			    else
			    {
				printf("��Ǹ�������治��\n");
				printf("�����������\n");
				getch();
				break;
			   }
			}
		}
		
	    if(cou==0)
		{
			printf("����δ���\n");
			printf("���������ٽ�������\n");
			getch();
		}
		printf("��������ţ�>");
   	    scanf("%s",b);
		wdata();
	}
	system("cls");
		printf("---------------------------------------------------------\n");
		printf("---------------�����嵥\t����000���ɽ��н���-------------\n");
		printf("---------------------------------------------------------\n");
		scanf("%d",&a);
		system("cls");
		if(a==000)
		{
		    printf("%-10s%-20s%-10s%-6s\n","���","����","����","����"); 
		    printf("---------------------------------------------------------\n");
	        for(i=0;i<count;i++)
		    {
			printf("%-10s%-20s%-10s%-6.2f\n",s[i].isbn,s[i].bkname,s[i].author,s[i].price);
		    }
		}
	
	printf("---------------------------------------------------------\n");
	printf("�ܼۣ�> %.2f\n",sum);
	printf("��������鱾����Ϊ��> %d",count);
	printf("\n�����������>");
	scanf("%f",&in);
	out=in-sum;
	printf("���㣺> %6.2f",out);
	getch();
}
//ͼ���ѯ���� 
void bkfind()
{
	int select=-1,t=0;
	char in[20],b;
	while(select)
	{
		system("CLS");
		printf("\n\n �밴������в�ѯ��""\n\n\t\t\t\t1. ������\n\n\t\t\t\t2. ������\n\n\t\t\t\t3. �����\n\n\t\t\t\t0. �˳�\n  -->");
		scanf("%d",&b);
		switch(b)
		{
			case 0:
				select=0;
				break;
			case 1:
				select=1;
				break;
			case 2:
				select=2;
				break;
			case 3:
		    	select=3;
				break; 
			default :
				printf("�����������������");
		}
		
		if(select==1)
		{
			printf("\n ������������>");
			scanf("%s",in);
			if(strlen(in)==0)
			{
				continue;
			}
			
			for(int i=0;i<bknum;i++)
			{
				if(strcmp(in,bk[i].bkname)==0)
				{
					pb(i,1);
					t=1;
				}
			}
			if(t!=1)
			{
				printf("\n �Ҳ�����Ӧ���飡\n");
			}
				
		}
		if(select==2)
		{
			printf("\n ���������ߣ�>");
			scanf("%s",in);
			for(int i=0;i<bknum;i++)
			{
				if(strcmp(in,bk[i].author)==0)
				{
					pb(i,1);
					t=1;
				}
			}
			if(t!=1)
			{
				printf("\n �Ҳ�����Ӧ���飡\n");
			}
				
	   }
	   	if(select==3)
		{
			printf("\n ��������ţ�>");
			scanf("%s",in);
			for(int i=0;i<bknum;i++)
			{
				if(strcmp(in,bk[i].isbn)==0)
				{
					pb(i,1);
					t=1;
				}
			}
			if(t!=1)
			{
				printf("\n �Ҳ�����Ӧ���飡\n");
			}
				
	   }
		
			getch();
	} 	
}
//ͼ��ɾ������ 
void bookdelete()
{
	char text[10];
	int i,j,k,tip=0,t20=0;
	system("CLS");
	printf("\n ���롾del ��š����س���ִ��ɾ�������磺del 001\n");
	printf("\n ����f��ˢ���б�Ŷ��\n ");
	printf("\n ����000����\n");
	printf("\n----------------------------------------\n");
	pb(-1,1);
	for(i=0;i<bknum;i++,t20++)
	{
	   pb(i,0);
		if(t20==20)
		{
			printf("\n\n");
			system("PAUSE");
		}
	}
	printf("\n");
	while(1) 
	{
			 if(bknum==0)
		 {
		 	printf("�б�Ϊ�գ�\n\n");
		 }
		 printf("-->");
		scanf("%s",text);
		if(strcmp(text,"del")==0)
		{
		 	tip=0;
		 	scanf("%s",text);
		 	for(j=0;j<bknum;j++)
			{
				if(strcmp(text,bk[j].isbn)==0)
		 		{
		 			for(k=j;k<bknum;k++)
		 			{
		 				bk[k]=bk[k+1];
	     			}
				     bknum--;		
						 printf("\nɾ���ɹ�!\n\n");
						 tip=1;
				}	 
			 }	
			  if(tip==0)
					 {
					 	printf("\nδ�ҵ�ɾ���\n\n");
					 }		 
		}
		 if(strcmp(text,"000")==0)
		 {
		 	return;
		 }
		 if(strcmp(text,"f")==0)
		 {
		 	bklist();
		 	getch();
		 	return ;
		 }
		 fflush(stdin);
		  wdata();
	} 
  	
}
//�˵��б� 
int showsell()
{
	int sell;
	system("cls");
	
	printf("  \n\n\n");
	printf("                ������ϵͳ\n");
	printf("------------------------------------------\n");
	printf("                0���˳�\n\n");
	printf("                1��ͼ���б�\n");
	printf("                2��ͼ��¼��\n");
	printf("                3��ͼ������\n");
	printf("                4��ͼ���ѯ\n");
	printf("                5��ͼ��ɾ��\n");
	printf("------------------------------------------\n");
	printf("             �����������ѯ�ģ�>          \n");
	
	scanf("%d",&sell);
	return sell;
	
}
//������ 
 int main()
 {
 	int sell=-1;
 	int k;
 	rdata();
 	while(sell!=0)
 	{
 		switch(sell)
 		{
 			case 0:break;
 			case 1:bklist();break;
 			case 2:bkin();break;
 			case 3:bksell();break;
 			case 4:bkfind();break;
 			case 5:bookdelete();break;
		 }
		 sell=showsell();
	 }
 }
 

