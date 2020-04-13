#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "C:\Users\17226\Desktop\QG训练营\第三次\代码和头文件\AQueue\AQueue.h"

int main(){
	AQueue Q;
	InitAQueue(&Q);
	void *e;
	void (*foo)();
	void *q;
	void *memcpy(void *destin, void *source, unsigned n);
	printf("请输入5个元素进入队列\n");
	int i;
	int data[6];
	for(i=1;i<=5;i++){
		scanf("%d",&data);
		EnAQueue(&Q,&data);
	}
	GetHeadAQueue(&Q,e);
	printf("队头元素为：%d\n",e);
	IsEmptyAQueue(&Q);
	printf("判断队列是否为空：%d(1:yes  0:no)\n",IsEmptyAQueue(&Q));
	IsFullAQueue(&Q);
	printf("判断队列是否已满：%d(1:yes  0:no)\n",IsFullAQueue(&Q));
	LengthAQueue(&Q);
	printf("队列的长度为：%d\n",LengthAQueue(&Q));
	TraverseAQueue(&Q,foo));
	printf("遍历整个队列\n"); 
	DeAQueue(&Q);
	printf("删除队头元素\n");
	ClearAQueue(&Q);
	printf("清空队列\n"); 
	DestoryAQueue(&Q);
	printf("队列已销毁\n");
	return 0;
}








void InitAQueue(AQueue *Q){
    int i;
	for (i = 0; i < MAXQUEUE; i++)
	Q->data[i] = (void *)malloc(Q->length);
	Q->front = 0;
	Q->rear  = 0;

}

void DestoryAQueue(AQueue *Q){
	int i;
	for(i = 0;i<MAXQUEUE;i++)
	    free(Q->data[MAXQUEUE]);
}

Status IsFullAQueue(const AQueue *Q){
	if(Q->front ==(Q->rear+1)%MAXQUEUE){
		return TRUE;
	}
	else{
		return FALSE;
	}
}

Status IsEmptyAQueue(const AQueue *Q){
	if(Q->front == Q->rear){
		return TRUE;
	}
	else{
		return FALSE;
	}
}

Status GetHeadAQueue(AQueue *Q, void *e){
	if(IsEmptyAQueue(Q)){
		return FALSE;
	}
	int i = Q->front;
	i = (i + 1)%MAXQUEUE;
	memcpy(e, Q->data[i], Q->length);
	return TRUE;
}

int LengthAQueue(AQueue *Q){
	return(Q->rear-Q->front + MAXQUEUE) % MAXQUEUE;
}

Status EnAQueue(AQueue *Q, void *data){
	if(IsFullAQueue(Q)){
		return FALSE;
	}
	Q->rear = (Q->rear+1)%MAXQUEUE;
	memcpy(Q->data[Q->rear],data,Q->length);
	return TRUE;
}

Status DeAQueue(AQueue *Q){
	if(Q->front == Q->rear){
		return FALSE;
	}
	Q->front = (Q->front + 1)%MAXQUEUE;
	return TRUE;
}

void ClearAQueue(AQueue *Q){
	if(IsEmptyAQueue(Q)){
		return;
	}
	Q->front = 0;
	Q->rear = 0;
	return; 
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
	if(Q->front == Q->rear){
		return FALSE;
	}
	int i = Q->front + 1;
	while(i<=(MAXQUEUE - Q->front + Q->rear)%MAXQUEUE){
		foo(Q->data[i]);
		i = (i+1)%MAXQUEUE;
	}
	return TRUE;
}

void APrint(void *q){
	int size;
	if (size == sizeof(double))
		printf("%lf", *(double *)q);
	if (size == sizeof(char))
		printf("%c", *(char *)q);
	if (size == sizeof (int))
		printf("%d", *(int *)q);
	printf("-<"); 
}
