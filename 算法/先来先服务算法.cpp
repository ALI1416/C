#include<stdio.h>
#define N 10	//��������
#define T 100	//���ʱ�䳤��
#define M 100	//��������

int queue[M]={0};	//����
int head=0;	//��ͷ
int end=0;	//��β

void queue_in(int i){	//���
	queue[end++]=i;
}

int queue_out(){	//����
	return queue[head++];
}

int queue_empty(){	//�ӿ�
	if(end==head)
		return 1;
	return 0;
}

void main(){
	int i,j;		//�м����
	int n;			//��������
	int arrive[N];	//����ʱ��
	int serve[N];	//����ʱ��
	int serve_copy[N];	//����ʱ�俽��
	int start[N];	//��ʼִ��ʱ��
	int finish[N];		//����ִ��ʱ��
	int interval[N];	//��תʱ��
	float interval_average[N];	//ƽ����תʱ��
	int running=-1;	//�������еĽ������
	int end_number=0;	//��ɽ��̸���
	
	printf("�����ȷ����㷨��\n\n��������̸��� ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("������� %d �����̵� ����ʱ�� �� ����ʱ�� ",i);
		scanf("%d%d",&arrive[i],&serve[i]);
	}
	
	for(i=0;i<n;i++){	//��������ʱ��
		serve_copy[i]=serve[i];
	}
	printf("\n����˳��Ϊ��\n");
	for(i=0;i<T;i++){	//����ʱ������+1
		if(end_number==n){	//���н��������
			break;	//�˳�ѭ��
		}
		
		for(j=0;j<n;j++){	//���ҵ������
			if(arrive[j]==i){	//���ڵ���ʱ��Ϊ����ʱ��Ľ���
				queue_in(j);	//�Ž�����
			}
		}
		
		if(queue_empty()==1&&running==-1){	//���������cpu�п���
			printf("�� ");	//����˳��
			continue;	//����Ϊ�գ�û���������еĽ��̣����һ��н���δִ��
		}
		
		if(running==-1){	//û���������еĽ���
			running=queue_out();	//����ȡ��
			start[running]=i;	//��¼�ý��̿�ʼʱ��
			printf("%d ",running);	//����˳��
			serve_copy[running]--;	//����ʱ��--
			if(serve_copy[running]==0){	//����������ý��̷���ʱ��Ϊ1
				finish[running]=i+1;	//����ʱ��Ϊ��ǰʱ��+1
				running=-1;	//����޽���������
				end_number++;	//��ɽ���+1
			}
		}else{	//������������
			printf("%d ",running);	//����˳��
			serve_copy[running]--;	//����ʱ��--
			if(serve_copy[running]==0){	//�ý��������н���
				finish[running]=i+1;	//����ʱ��Ϊ��ǰʱ��+1
				running=-1;	//����޽���������
				end_number++;	//��ɽ���+1
			}			
		}
	}
	
	for(i=0;i<n;i++){	//������ת��ƽ����ת
		interval[i]=finish[i]-arrive[i];
		interval_average[i]=(float)interval[i]/serve[i];
	}
	
	printf("\n\n����\t����\t����\t��ʼ\t����\t��ת\tƽ����ת\n");
	for(i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%.2f\n",i,arrive[i],serve[i],start[i],finish[i],interval[i],interval_average[i]);
	}
}