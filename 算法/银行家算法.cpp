#include <stdio.h>
#include <stdlib.h>

#define P 10	//��������
#define R 5		//�����Դ����

int p=0;	//ʵ�ʽ�����
int r=0;	//ʵ����Դ����
int i,j;	//��ʱ����

int max[P][R]={0};			//�������
int allocation[P][R]={0};	//�ѷ���
int need[P][R]={0};			//����
int available[P][R]={0};	//������
int work[P][R]={0};			//����
int workAndAllocation[P][R]={0};	//����+������
int finish[P]={0};			//���˳��
int resourceMax[R]={0};		//��Դ����
int resource[R]={0};		//��Դ��ǰʣ����
int finishCount=0;			//��ǰ����ɽ��̸���

int openFile(){
	
	FILE *fp=fopen("data.txt","r");
	if(fp==NULL)	//�ļ�������
	{
		fp=fopen("data.txt","w");	//�½��ļ�
		fprintf(fp,"5 3\n7 5 3 0 1 0\n3 2 2 2 0 0\n9 0 2 3 0 2\n2 2 2 2 1 1\n4 3 3 0 0 2\n10 5 7\n");
		fclose(fp);
		printf("�����ʽ��\n��һ�У��������� ��Դ����\n�ڶ��У�����0����������ѷ�����Դ��������Դ��������д����\n�����У�����1��...�Դ����ơ����һ�У�������Դ��������\nʾ��������д�룬������д�����ݣ������ļ����ٴ����д˳���\n");
		system("start data.txt");	//��TXT�ļ�
		return 0;
	}else{	//�ļ�����
		fscanf(fp,"%d %d",&p,&r);	//��ȡʵ�ʽ���p����Դr
		for(i=0;i<p;i++){	//�����������max���ѷ���allocation
			for(j=0;j<r;j++){
				fscanf(fp,"%d ",&max[i][j]);
			}
			for(j=0;j<r;j++){
				fscanf(fp,"%d ",&allocation[i][j]);
			}
		}
		for(i=0;i<r;i++){	//���������Դ��resourceMax
			fscanf(fp,"%d ",&resourceMax[i]);
		}
		for(i=0;i<p;i++){	//���㻹��need
			for(j=0;j<r;j++){
				need[i][j]=max[i][j]-allocation[i][j];
			}
		}
		for(i=0;i<r;i++){	//������Դ��ǰʣ����resource
			resource[i]=resourceMax[i];
			for(j=0;j<p;j++){
				resource[i]-=allocation[j][i];
			}
		}
	}
	fclose(fp);
	return 1;
}

void showInit(){
	printf("�������� %d ������Դ���� %d ��(�������Ϊ ",p,r);
	for(i=0;i<r;i++){
		printf("%d ",resourceMax[i]);
	}
	printf("��ʣ������Ϊ ");
	for(i=0;i<r;i++){
		printf("%d ",resource[i]);
	}
	printf(")\n\n��ʼ״̬Ϊ��\n\n| ����  |  �������  |   �ѷ���   |    ����    |\n");
	for(i=0;i<p;i++){
		printf("|  P%-4d|",i);
		for(j=0;j<r;j++){
			printf("%3d ",max[i][j]);
		}
		printf("|");
		for(j=0;j<r;j++){
			printf("%3d ",allocation[i][j]);
		}
		printf("|");
		for(j=0;j<r;j++){
			printf("%3d ",need[i][j]);
		}
		printf("|\n");
	}
}

void showEnd(){
	int order[P]={0};	//ִ��˳��
	int temp;			//�м����
	temp=finishCount;	//��¼��ɽ�������
	
	for(i=0;i<p;i++){	//����ִ��˳��
		for(j=0;j<p;j++){
			if(finish[j]==i+1){	//������
				order[i]=j;	//������ŵ�ͷ��
				break;
			}
		}
		if(finish[i]==0){	//����
			order[temp++]=i;	//������ŵ�β��
			for(j=0;j<r;j++){	//���ù�����ԴworkΪ��ǰ��Դ
				work[i][j]=resource[j];
			}
		}
	}
	printf("\n���������£�\n\n");
	printf("| ����  |  ������Դ  |    ����    |   �ѷ���   |   ������   |  ���˳��  |\n");
	for(i=0;i<p;i++){
		temp=i;
		i=order[i];
		if(finish[i]==0){
			printf("--------------------------------------------------------------------------\n");
		}
		printf("|  P%-4d|",i);
		for(j=0;j<r;j++){
			printf("%3d ",work[i][j]);
		}
		printf("|");
		for(j=0;j<r;j++){
			printf("%3d ",need[i][j]);
		}
		printf("|");
		for(j=0;j<r;j++){
			printf("%3d ",allocation[i][j]);
		}
		printf("|");
		for(j=0;j<r;j++){
			printf("%3d ",workAndAllocation[i][j]);
		}
		printf("|");
		printf("%7d     ",finish[i]);
		printf("|\n");
		i=temp;
	}
	if(finishCount==5){
		printf("\n��������ִ��˳��Ϊ");
		for(i=0;i<p;i++){
			printf("P%d ",order[i]);
		}
		printf("\n");
	}else{
		printf("\n�����������������˳��Ϊ0��Ϊ�������̡�\n");
	}
}

//�ݹ�ʵ��
//-1��δ�ҵ�
//�������ҵ�
void compute(int find){
	int flag;
	if(find==-1){	//δ�ҵ�
		for(i=0;i<p;i++){
			if(finish[i]==0){	//ֻ��ѯδ��ɵ�
				for(j=0;j<r;j++){	//��ѯÿ����Դ
					if(need[i][j]>resource[j]){	//������Դ����ʣ����Դ��ȥ��
						flag=0;	//��ǲ���������
						break;	//�ж�jѭ������һ����Դ���㣬�����ж�
					}//r���ж϶����ã�ִ���������
					flag=1;	//�����������
				}
				if(flag==1){
					find=i;		//�ҵ����������
					compute(find);	//�ݹ�
					break;	//�ж�iѭ����ֻȡ��һ�����
				}
			}
		}
	}else{	//�ҵ�
		i=find;	//�滻
		for(j=0;j<r;j++){	//���㹤��work��������workAndAllocation����Դ��ǰʣ����resource
			work[i][j]=resource[j];
			workAndAllocation[i][j]=work[i][j]+allocation[i][j];
			resource[j]=workAndAllocation[i][j];
		}
		finish[i]=++finishCount;	//���ִ��˳�򣬴�1��ʼ��0Ϊδִ��
		compute(-1);	//�ݹ�
	}
}

void initFile(){	//��ʼ�������ļ�
	finishCount=0;	//��ʼ����ɸ���finishCount
	for(i=0;i<p;i++){	//��ʼ�����˳��finish
		finish[i]=0;
	}
	for(i=0;i<r;i++){	//��ʼ����Դ��ǰʣ����resource
		resource[i]=resourceMax[i];
		for(j=0;j<p;j++){
			resource[i]-=allocation[j][i];
		}
	}
	
}

//������Դ
int request(){
	int pro;	//����
	int num[R];		//����
	printf("������Ҫ������Դ�Ľ��̣�");
	scanf("%d",&pro);
	if(pro>=p){	//���̲�����
		printf("���󣺲����ڸý��̣�\n");
		return -1;
	}
	printf("������������Դ�ĸ�����");
	for(i=0;i<r;i++){
		scanf("%d",&num[i]);
	}
	for(i=0;i<r;i++){	//������Դ����
		if(num[i]>need[pro][i]){
			printf("���󣺳�����Դ���룡\n");
			return -1;
		}
	}
	for(i=0;i<r;i++){	//ʣ����Դ����
		if(num[i]>resource[i]){
			printf("����ʣ����Դ���㣡\n");
			return -1;
		}
	}
	for(i=0;i<r;i++){	//�滻������Դ
		need[pro][i]=num[i];
	}
	return pro;
}

void main()
{
	printf("���м��㷨\n\n");
	if(openFile()==1){
		showInit();
		printf("--------------------------------------------------------------------------\n");
		printf("�жϵ�ǰϵͳ�Ƿ�����\n");
		compute(-1);
		showEnd();
		printf("--------------------------------------------------------------------------\n");
		printf("�жϽ���������Դ���Ƿ�����\n");
		initFile();
		int progress=request();
		if(progress!=-1){
			compute(progress);
			showEnd();
		}
	}
}
