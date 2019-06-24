#include<stdio.h>
#define N 100	//�����������
#define M 10	//������������

int n=20;	//ʵ�ʽ�������
int m=3;	//ʵ�����������
int page[N]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};	//ҳ���
int miss[N];	//�Ƿ�ȱҳ
int map[N][M];	//�û�ͼ
int i,j,k;	//�ֲ�����

void scan(){
	printf("��������������� ");
	scanf("%d",&m);
	printf("���������ҳ��ţ�-1��������\n");
	for(i=0;i<N;i++){
		scanf("%d",&k);
		if(k!=-1){
			page[i]=k;
		}else{
			n=i;
			break;
		}
	}
}

void init(){
	for(i=0;i<n;i++){	//��ʼ��map
		for(j=0;j<m;j++){
			map[i][j]=-1;
		}
	}
	for(i=0;i<n;i++){	//��ʼ��miss
		miss[i]=0;
	}
}

void input(int x,int i,int j,int num_v){
	//x=0 fifo�㷨 ����i,num_v (���׳���,num_v���)
	//x=1  lru�㷨 ����i,j (���j���ӣ�map[i][j]���)
	int num;
	for(k=0;k<m;k++){	//������ʹ�õ����������
		if(map[i][k]==-1){
			num=k-1;
			break;
		}else{
			num=m-1;
		}
	}
	if(x==0){	//fifo
		for(k=0;k<num;k++){	//�滻
			map[i][k]=map[i][k+1];
		}
	}else{	//lru
		num_v=map[i][j];	//�����ҳ���
		for(k=j;k<num;k++){	//�滻
			map[i][k]=map[i][k+1];
		}
	}
	map[i][num]=num_v;	//�Ѹ�ҳ��ŷŵ���β
}

void fifo_lru(int x){
	//x=0 fifo
	//x=1 lru
	int find,num,num_v;
	for(i=0;i<n;i++){
		find=0;
		for(j=0;j<m;j++){	//��һ�� Ѱ�Ҵ��ڵ�ҳ���
			if(map[i][j]==-1){	//���ҵ���������� ��������
				break;
			}
			if(map[i][j]==page[i]){	//�ҵ���ͬ�����
				find=1;	
				if(x==1)	//���Ϊlru�㷨
					input(1,i,j,0);
				break;
			}
		}
		if(find==0){
			for(j=0;j<m;j++){	//�ڶ��� Ѱ�ҿ��������
				if(map[i][j]==-1){
					map[i][j]=page[i];	//�ҵ�
					find=1;
					miss[i]=1;	//���Ϊȱҳ
					break;
				}
			}
			if(find==0){
				input(0,i,0,page[i]);	//fifo&lru
				miss[i]=1;	//���Ϊȱҳ
			}
		}
		for(j=0;j<m;j++){	//���Ƶ�ǰҳ���map����һ��
			map[i+1][j]=map[i][j];
		}
	}
}

void print(){
	int miss_num=0;
	printf("����ҳ���Ϊ��\n");
	for(i=0;i<n;i++){
		printf("%4d",page[i]);
	}
	printf("\n�û�ͼΪ��\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%4d",map[j][i]);
		}
		printf("\n");
	}
	for(i=0;i<n;i++){
		if(miss[i]==1){
			miss_num++;
			printf("  ȱ");
		}
		else
			printf("    ");
	}
	printf("\n");
	printf("ȱҳ %d �Σ�ȱҳ�� %.2f %%\n",miss_num,miss_num/(float)n*100);
}

void main(){
	int def;
	printf("����0ʹ��Ĭ�����ݣ�����1�ֶ���������");
	scanf("%d",&def);
	if(def!=0)
		scan();

	printf("�ܹ� %d �����̣��� %d �������\n",n,m);
	printf("\n�����ȷ����㷨(FIFO)\n");
	init();
	fifo_lru(0);
	print();

	printf("\n������δʹ���㷨(LRU)\n");
	init();
	fifo_lru(1);
	print();
}