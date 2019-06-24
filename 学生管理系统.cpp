#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

#define N 128//���ṹ������
#define stlen sizeof(struct st)//�ṹ�峤��
#define PW "123"//����

struct st
{
	int no;       //���
	int flag;     //���
	char num[8];  //ѧ��
	char name[8]; //����
	float cpp;    //C���Գɼ�
	float eng;    //Ӣ��ɼ�
	float math;   //��ѧ�ɼ�
	float ave;    //ƽ����
};

struct st s[N];
int tot=0;  //�ṹ�����
int flag0=0;//���Ϊ0�ĸ���

int all(int t);
int change();
int delall();
int delpart();
int display();
int find();
int findswitch(int t);
int index();
int input();
int insert();
int judge();
int main();
int part(int t);
int password();
int print(int t);
int recycle();
int reset();
int save();
int sort();
int sortswitch(int x);

int judge()
{
	printf("\t\t\t\t******************************\n");
	printf("\t\t\t\t*      �����س�����ȷ��      *\n");
	printf("\t\t\t\t*      ������������ȡ��      *\n");
	printf("\t\t\t\t******************************\n");
	if(getch()==13)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int input()//����
{
	FILE *fp;
	fp=fopen("data.dat","ab+");
	//system("cls");
	printf("�������롾ѧ�š�����������C���Գɼ�����Ӣ��ɼ����������ɼ���\n");
	printf("����ѧ�š����롾0�����沢�������˵�\n");
	for(int i=0;i<N-tot;i++)
	{
		scanf("%s",s[i].num);//������ѧ��
		if(strlen(s[i].num)==1&&s[i].num[0]=='0') //�������ĳ���Ϊ1������0���˳�
		{
			fclose(fp); return 0;//�������˳��ر��ļ�
		}
		scanf("%s%f%f%f",&s[i].name,&s[i].cpp,&s[i].eng,&s[i].math);//�ٴ�����ʣ������
		s[i].ave=(s[i].cpp+s[i].eng+s[i].math)/3;//����ƽ����
		s[i].no=++tot;//�����ṹ���������
		s[i].flag=0;//�����Ϊ0
		flag0++;//���0��������
		fwrite(&s[i],stlen,1,fp);//д���ļ�
	}
	fclose(fp);//�����˳��ر��ļ�
	printf("�����ѳ�������ɾ��������ӡ�\n");
	return 1;
}

int print(int t)//���
{
	system("cls");
	if((t==0&&flag0==0)||(t==1&&tot==flag0))//��ʾ����Ϊ0�������վ����Ϊ0
		return 0;
	else
	{
		FILE *fp;
		fp=fopen("data.dat","rb");
		fread(s,stlen,tot,fp);
		printf("���\tѧ��\t����\tC����\tӢ��\t����\tƽ����\n");
		for(int i=0;i<tot;i++)
		{
			if(s[i].flag==t)
				printf("%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n",
				s[i].no,s[i].num,s[i].name,s[i].cpp,s[i].eng,s[i].math,s[i].ave);
		}
		fclose(fp);
		return 1;
	}
}

int display()
{
	if(flag0==0)
	{
		printf("�����ݣ�\n");
	}
	else
	{
		print(0);//�����ʾ
		printf("\t\t\t\t******************************\n");
		printf("\t\t\t\t*    ������Ϊѧ�����ݣ�      *\n");
		printf("\t\t\t\t*    ����ѡ�������          *\n");
		printf("\t\t\t\t*      ��1.����ɾ��          *\n");
		printf("\t\t\t\t*      ��2.ȫ��ɾ��          *\n");
		printf("\t\t\t\t*      ��3.�޸�              *\n");
		printf("\t\t\t\t*      ��4.����              *\n");
		printf("\t\t\t\t*      ��5.����              *\n");
		printf("\t\t\t\t*      ��6.����              *\n");
		printf("\t\t\t\t*      ��7.���Ϊ...         *\n");
		printf("\t\t\t\t*    �������������������˵�  *\n");
		printf("\t\t\t\t******************************\n");
		switch(getch())
		{
		case '1'://����ɾ��
			{
				printf("\t\t\t\t******************************\n");
				printf("\t\t\t\t*    �����ڽ��ж���ɾ������  *\n");
				printf("\t\t\t\t*    �����롾��š�ɾ��      *\n");
				printf("\t\t\t\t*    ������֮��ӡ��ո�    *\n");
				printf("\t\t\t\t*    �������ӡ�0��           *\n");
				printf("\t\t\t\t******************************\n");
				part(1);
			}break;
			
		case '2'://ȫ��ɾ��
			{
				printf("\t\t\t\t******************************\n");
				printf("\t\t\t\t*    ��ȷ����ȫ��ɾ������  *\n");
				printf("\t\t\t\t******************************\n");
				if(judge()==1)
				{
					all(1);
					printf("ȫ��ɾ���ɹ���\n");
				}
				else 
				{
					printf("����ȡ��ȫ��ɾ����\n");
				}
			}break;	
			
		case '3'://�����޸�
			{
				printf("\t\t\t\t******************************\n");
				printf("\t\t\t\t*    �����ڽ��������޸Ĳ���  *\n");
				printf("\t\t\t\t*    ��������Ҫ�޸ĵġ���š�*\n");
				printf("\t\t\t\t*    ����0��ȡ��             *\n");
				printf("\t\t\t\t******************************\n");
				change();
			}break;

		case '4'://����
			{
				insert();
			}break;

		case '5'://����
			{
				find();
			}break;

		case '6'://����
			{
				sort();
			}break;

		case '7'://���Ϊ
			{
				save();
			}break;
		}
	}
	getch();
	return 0;
}

int part(int t)//����
{
	int x[N],i=0,co=0;
	while(1)
	{
		scanf("%d",&x[i]);co++;
		if(x[0]==0)return 0;
		if(x[i++]==0)break;
	}
	co--;
	printf("��������ѧ�����Ϊ��");
	for(i=0;i<co;i++)
	{
		printf("��%d��",x[i]);
	}
	printf("\n");
	if(judge()==1)
	{
		if(t==1)flag0-=co;
		if(t==0)flag0+=co;
		FILE *fp;
		fp=fopen("data.dat","wb+");
		for(int i=0;i<co;i++)
		{
			s[x[i]-1].flag=t;//�滻��ֵ
		}
		fwrite(s,stlen,tot,fp);
		fclose(fp);
	}
	else 
		return 0;
}

int delpart()//����
{
	struct st s2[N];
	int x[N],i=0,j=0,co=0,k=1;
	while(1)
	{
		scanf("%d",&x[i]);co++;
		if(x[0]==0)return 0;
		if(x[i++]==0)break;
	}
	co--;
	printf("������ѧ�����Ϊ��");
	for(i=0;i<co;i++)
	{
		printf("��%d��",x[i]);
	}
	printf("\n");
	if(judge()==1)
	{
		for(i=0;i<co;i++)
			s[x[i]-1].flag=2;//�滻��ֵ
		for(i=0;i<tot;i++)
		{
			if(s[i].flag!=2)
			{
				s2[j++]=s[i];
				s2[j-1].no=k++;
			}
		}
		tot=tot-co;
		FILE *fp;
		fp=fopen("data.dat","wb+");
		fwrite(s2,stlen,tot,fp);
		fclose(fp);
	}
	else 
		return 0;
}

int delall()//ȫ��
{
	struct st s2[N];
	int i=0,j=0,k=1;
	
	for(i=0;i<tot;i++)
	{
		if(s[i].flag==0)
		{
			s2[j++]=s[i];
			s2[j-1].no=k++;
		}
	}
	tot=flag0;
	FILE *fp;
	fp=fopen("data.dat","wb+");
	fwrite(s2,stlen,tot,fp);
	fclose(fp);
	return 0;
}

int all(int t)//ȫ��
{
	
	if(t==1)flag0=0;
	if(t==0)flag0=tot;
	FILE *fp;
	fp=fopen("data.dat","wb+");
	for(int j=0;j<tot;j++)
		s[j].flag=t;//�滻��ֵ
	fwrite(s,stlen,tot,fp);
	fclose(fp);
	return 0;
}

int recycle()//����վ
{
	if(tot==flag0)
		printf("�����ݣ�\n");
	else
	{
		print(1);
		printf("\t\t\t\t******************************\n");
		printf("\t\t\t\t*    ������Ϊ����վ���ݣ�    *\n");
		printf("\t\t\t\t*    ����ѡ�������          *\n");
		printf("\t\t\t\t*      ��1.����ָ�          *\n");
		printf("\t\t\t\t*      ��2.ȫ���ָ�          *\n");
		printf("\t\t\t\t*      ��3.�����ɾ��      *\n");
		printf("\t\t\t\t*      ��4.��ջ���վ        *\n");
		printf("\t\t\t\t*    �������������������˵�  *\n");
		printf("\t\t\t\t******************************\n");
		switch(getch())
		{
		case '1':
			{
				printf("\t\t\t\t******************************\n");
				printf("\t\t\t\t*    �����롾��š��ָ�      *\n");
				printf("\t\t\t\t*    ������֮��ӡ��ո�    *\n");
				printf("\t\t\t\t******************************\n");
				part(0);
				printf("���ݻָ��ɹ������ڷ�����һ����\n");
			}break;
			
		case '2':
			{
				printf("\t\t\t\t******************************\n");
				printf("\t\t\t\t*    ��ȷ����ȫ���ָ�����  *\n");
				printf("\t\t\t\t******************************\n");
				if(judge()==1)
				{
					all(0);
					printf("ȫ���ָ��ɹ������ڷ�����һ����\n");
				}
				else 
					printf("����ȡ��ȫ���ָ������ڷ�����һ����\n");
			}break;

		case '3':
			{
				printf("\t\t\t\t******************************\n");
				printf("\t\t\t\t*    �����롾��š�����ɾ��  *\n");
				printf("\t\t\t\t*    ������֮��ӡ��ո�    *\n");
				printf("\t\t\t\t******************************\n");
				delpart();
				printf("����ɾ���ɹ������ڷ�����һ����\n");
			}break;
			
		case '4':
			{
				printf("\t\t\t\t******************************\n");
				printf("\t\t\t\t*    ��ȷ������ջ���վ����*\n");
				printf("\t\t\t\t******************************\n");
				if(judge()==1)
				{
					delall();
					printf("��ջ���վ�ɹ������ڷ�����һ����\n");
				}
				else 
					printf("����ȡ����ջ���վ�����ڷ�����һ����\n");
			}break;
		}
	}
	Sleep(500);
	return 0;
}

int sortswitch(int x)//������
{
	struct st t,s0[N];
	int i,j,k=0;
	FILE *fp;
	fp=fopen("data.dat","rb");
	fread(s,stlen,tot,fp);
	fclose(fp);
	for(i=0;i<tot;i++)
	{
		if(s[i].flag==0)
			s0[k++]=s[i];
	}
	for(i=0;i<flag0-1;i++)
	{
		k=i;
		for(j=i+1;j<flag0;j++)
		{
			if(x==1&&strcmp(s0[k].num,s0[j].num)>0)k=j;
			if(x==2&&strcmp(s0[k].name,s0[j].name)>0)k=j;
			if(x==3&&s0[k].cpp<s0[j].cpp)k=j;
			if(x==4&&s0[k].eng<s0[j].eng)k=j;
			if(x==5&&s0[k].math<s0[j].math)k=j;
			if(x==6&&s0[k].ave<s0[j].ave)k=j;			
			if(k!=i){t=s0[i];s0[i]=s0[k];s0[k]=t;}
		}
	}	
	printf("���\tѧ��\t����\tC����\tӢ��\t����\tƽ����\n");
	for(i=0;i<flag0;i++)
		printf("%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n",
		s0[i].no,s0[i].num,s0[i].name,s0[i].cpp,s0[i].eng,s0[i].math,s0[i].ave);
	system("PAUSE");
	return 0;
}

int insert()
{
	printf("������Ҫ����ġ���š�\n");
	int no;
	scanf("%d",&no);
	if(no==0)return 0;
	if(no>tot)
	{
		printf("��������\n");return 0;
	}
	if(no>0&&no<=tot)
	{
		for(int i=tot+1;i>no-1;i--)
		{
			s[i]=s[i-1];
			s[i].no++;
		}
		printf("�����롾ѧ�š�����������C���Գɼ�����Ӣ��ɼ����������ɼ���\n");
		printf("(���롾0��ȡ�����������˵�)\n");
		i=no-1;
		scanf("%s",s[i].num);
		if(strlen(s[i].num)==1&&s[i].num[0]=='0') return 0;
		scanf("%s%f%f%f",&s[i].name,&s[i].cpp,&s[i].eng,&s[i].math);
		s[i].ave=(s[i].cpp+s[i].eng+s[i].math)/3;
		printf("\t\t\t\t******************************\n");
		printf("\t\t\t\t*    ��ȷ�����޸����ݡ���  *\n");
		printf("\t\t\t\t******************************\n");
		if(judge()==1)
		{
			FILE *fp;
			fp=fopen("data.dat","wb+");
			fwrite(s,stlen,tot+1,fp);
			fclose(fp);
			tot++;
			flag0++;
			printf("�޸ĳɹ���\n");
		}
		else 
			printf("����ȡ���޸ģ����ڷ�����һ����\n");
	}
	return 0;
}

int change()
{
	int no;
	scanf("%d",&no);
	if(no==0)return 0;
	if(no>tot)
	{
		printf("δ�ҵ���\n");return 0;
	}
	if(no>0&&no<=tot)
	{
		int i=no-1;
		printf("��ԭ����Ϊ��\n");
		printf("���\tѧ��\t����\tC����\tӢ��\t����\tƽ����\n");
		printf("%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n",
			s[i].no,s[i].num,s[i].name,s[i].cpp,s[i].eng,s[i].math,s[i].ave);
		printf("���������޸ĺ�����ݣ�\n");
		printf("�����롾ѧ�š�����������C���Գɼ�����Ӣ��ɼ����������ɼ���\n");
		printf("(���롾0��ȡ�����������˵�)\n");
		scanf("%s",s[i].num);
		if(strlen(s[i].num)==1&&s[i].num[0]=='0') return 0;
		scanf("%s%f%f%f",&s[i].name,&s[i].cpp,&s[i].eng,&s[i].math);
		s[i].ave=(s[i].cpp+s[i].eng+s[i].math)/3;
		printf("\t\t\t\t******************************\n");
		printf("\t\t\t\t*    ��ȷ�����޸����ݡ���  *\n");
		printf("\t\t\t\t******************************\n");
		if(judge()==1)
		{
			FILE *fp;
			fp=fopen("data.dat","wb+");
			fwrite(s,stlen,tot,fp);
			fclose(fp);
			printf("�޸ĳɹ���\n");
		}
		else 
			printf("����ȡ���޸ģ����ڷ�����һ����\n");
		Sleep(500);							
		}
		return 0;
}

int findswitch(int t)
{
	int i;
	char ch[8];
	gets(ch);
	for(i=0;i<tot;i++)
	{
		if(t==1&&strcmp(ch,s[i].num)==0)break;
		if(t==2&&strcmp(ch,s[i].name)==0)break;
	}
	if(s[i].flag==0&&i<tot)
	{
		printf("���ҵ���\n");
		printf("���\tѧ��\t����\tC����\tӢ��\t����\tƽ����\n");
		printf("%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n",
			s[i].no,s[i].num,s[i].name,s[i].cpp,s[i].eng,s[i].math,s[i].ave);
	}
	else 
		printf("δ�ҵ���\n");
	system("PAUSE");
	return 0;
}

int find()
{
	while(1)
	{
		system("cls");
		printf("\t\t\t\t******************************\n");
		printf("\t\t\t\t*    ����ѡ����ҷ�ʽ        *\n");
		printf("\t\t\t\t*      ��1.ѧ��              *\n");
		printf("\t\t\t\t*      ��2.����              *\n");
		printf("\t\t\t\t*    ��0.�������˵�          *\n");
		printf("\t\t\t\t******************************\n\n");
		switch(getch())
		{
		case '1':printf("������Ҫ���ҵġ�ѧ�š�\n");findswitch(1);break;
		case '2':printf("������Ҫ���ҵġ�������\n");findswitch(2);break;
		case '0':return 0;break;
		default :printf("�����������������롣\n");Sleep(500);
		}
	}
}

int sort()//����
{
	while(1)
	{
		system("cls");
		printf("\t\t\t\t******************************\n");
		printf("\t\t\t\t*    ����ѡ������ʽ(����)��*\n");
		printf("\t\t\t\t*      ��1.ѧ��              *\n");
		printf("\t\t\t\t*      ��2.����(����)        *\n");
		printf("\t\t\t\t*      ��3.C���Գɼ�         *\n");
		printf("\t\t\t\t*      ��4.Ӣ��ɼ�          *\n");
		printf("\t\t\t\t*      ��5.�����ɼ�          *\n");
		printf("\t\t\t\t*      ��6.ƽ����            *\n");
		printf("\t\t\t\t*    ��0.�������˵�          *\n");
		printf("\t\t\t\t******************************\n\n");
		switch(getch())
		{
		case '1':printf("���ա�ѧ�š��������£�      \n");sortswitch(1);break;
		case '2':printf("���ա�����(����)���������£�\n");sortswitch(2);break;
		case '3':printf("���ա�C���Գɼ����������£� \n");sortswitch(3);break;
		case '4':printf("���ա�Ӣ��ɼ����������£�  \n");sortswitch(4);break;
		case '5':printf("���ա������ɼ����������£�  \n");sortswitch(5);break;
		case '6':printf("���ա�ƽ���֡��������£�    \n");sortswitch(6);break;
		case '0':return 0;break;
		default :printf("�����������������롣\n");Sleep(500);
		}
	}
}

int save()//����
{
	system("cls");
	while(1)
	{
		system("cls");
		printf("\t\t\t\t******************************\n");
		printf("\t\t\t\t*    ����ѡ�񵼳���ʽ��      *\n");
		printf("\t\t\t\t*      ��1.txt�ı��ĵ�       *\n");
		printf("\t\t\t\t*      ��2.xls����ļ�       *\n");
		printf("\t\t\t\t*    ��0.�������˵�          *\n");
		printf("\t\t\t\t******************************\n");
		int ch=getch();
		if(ch=='0')return 0;
		if(ch=='1'||ch=='2')
		{
			FILE *fp;
			if(ch=='1')fp=fopen("data.txt","w");
			if(ch=='2')fp=fopen("data.xls","w");
			fprintf(fp,"���\tѧ��\t����\tC����\tӢ��\t����\tƽ����\n");
			for(int i=0;i<tot;i++)
				if(s[i].flag==0)
					fprintf(fp,"%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n",
					s[i].no,s[i].num,s[i].name,s[i].cpp,s[i].eng,s[i].math,s[i].ave);
				fclose(fp);
				printf("�����ɹ���\n");
		}
		if(!(ch=='0'||ch=='1'||ch=='2'))printf("�����������������롣\n");
		Sleep(500);
	}
}

int reset()//����
{
	printf("\t\t\t\t******************************\n");
	printf("\t\t\t\t*    ��ȷ��������ϵͳ����  *\n");
	printf("\t\t\t\t******************************\n");
	if(judge()==1)
	{
		FILE *fp;
		fp=fopen("data.dat","w");
		fclose(fp);
		tot=0;
		flag0=0;
		printf("���óɹ������ڷ�����һ����\n");
	}
	else 
		printf("����ȡ�����ã����ڷ�����һ����\n");
	Sleep(500);
	return 0;
}

int index()
{
	FILE *fp;
	if((fp=fopen("data.dat","r"))==NULL)//���û���ļ�
		fp=fopen("data.dat","wb+");     //����һ���ļ�
	fp=fopen("data.dat","rb");
	fseek(fp,0L,SEEK_END);//ָ���ļ�β
	tot=ftell(fp)/stlen;  //�ṹ�����
	fseek(fp,0L,SEEK_SET);//ָ���ļ�ͷ
	fread(s,stlen,tot,fp);
	for(int i=0;i<tot;i++)
	{
		if(s[i].flag==0)
			flag0++;//���ұ��Ϊ0�ĸ���
	}
	fclose(fp);
	while(1)
	{
		system("cls");
		printf("\t\t\t\t******************************\n");
		printf("\t\t\t\t*    ��ӭʹ��ѧ������ϵͳ    *\n");
		printf("\t\t\t\t*      ����������Ӧ����      *\n");
		printf("\t\t\t\t******************************\n");
		printf("\t\t\t\t*    ��1.����ѧ������        *\n");
		printf("\t\t\t\t*    ��2.��ʾ                *\n");
		printf("\t\t\t\t*    ��3.����վ              *\n");
		printf("\t\t\t\t*    ��4.����ϵͳ            *\n");
		printf("\t\t\t\t*    ��0.�˳�                *\n");
		printf("\t\t\t\t******************************\n");
		switch(getch())
		{
		case '1':input();break;
		case '2':display();break;
		case '3':recycle();break;
		case '4':reset();break;
		case '0':return 0;break;
		default :printf("�����������������롣\n");Sleep(500);
		}
	}
}

int password()
{
	printf("��������\n");
	char get[16],pw[]=PW;//����
	int count=3;
	while(count)
	{
		gets(get);
		if(strcmp(get,pw)==0)
		{
			printf("������ȷ�����ڽ���ϵͳ...\n");
			Sleep(500);return 1;
		}
		else
		{
			if(count!=1)
			{
				printf("����������������룡\n");
				printf("������%d�λ��ᣡ\n",--count);
			}
			else
			{
				printf("������󣡰�������˳�ϵͳ��\n");
				getch();return 0;
			}
		}
	}

}

int main()
{
	system("mode con cols=94 lines=30");//94��30�У����У�
	SetConsoleTitle("ѧ������ϵͳ");    //����
	system("color F0");//�׵׺���
	printf("��ӭʹ��ѧ������ϵͳ\n");
	if(password()==1)
		index();
	else
		return 0;
}

