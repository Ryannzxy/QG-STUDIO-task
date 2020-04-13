#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "C:\Users\17226\Desktop\QGѵ��Ӫ\������\�����ͷ�ļ�\LQueue\LQueue.h" 

int main(){
	LQueue Q;
	InitLQueue(&Q);
	void *e;
	void (*foo)(); 
	void *memcpy(void *destin, void *source, unsigned n);
	printf("������5��Ԫ�ؽ������\n");
	int i;
	int data[6];
	for(i=1;i<=5;i++){
		scanf("%d",&data);
		EnLQueue(&Q,&data);
	}
	GetHeadLQueue(&Q,e);
	printf("��ͷԪ��Ϊ��%d\n",e);
	IsEmptyLQueue(&Q);
	printf("�ж϶����Ƿ�Ϊ�գ�%d(1:yes  0:no)\n",IsEmptyLQueue(&Q));
	LengthLQueue(&Q);
	printf("���еĳ���Ϊ��%d\n",LengthLQueue(&Q));
	TraverseLQueue(Q,(*foo));
	printf("������������"); 
	DeLQueue(&Q);
	printf("ɾ����ͷԪ��");
	ClearLQueue(&Q);
	printf("��ն���"); 
	DestoryLQueue(&Q);
	printf("����������");
	return 0;
	
}

void InitLQueue(LQueue *Q){
	Node *p = (Node *)malloc(sizeof(Node));
	if (NULL == p)
		return;
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
	return;
}

void DestoryLQueue(LQueue *Q){
	if (IsEmptyLQueue(Q))
		return; 
	ClearLQueue(Q);
	free(Q->front);
	free(Q->rear);
}

Status IsEmptyLQueue(const LQueue *Q){
	return (Q->front == Q->rear? TRUE: FALSE);
}

Status GetHeadLQueue(LQueue *Q, void *e){
	if (IsEmptyLQueue(Q))
		return FALSE;
	memcpy(e, Q->front->next->data, Q->length);
	return TRUE;
}

int LengthLQueue(LQueue *Q){
	int length;
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front;
	for (length = 0; p != Q->rear; length++)
		p = p->next; 
	return length;
}

Status EnLQueue(LQueue *Q, void *data){
	Node *p = (Node *)malloc(sizeof(Node));
	if (NULL == p)
		return FALSE;
	p->data = (void *)malloc(Q->length);
	memcpy(p->data, data, Q->length);
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return TRUE;
}

Status DeLQueue(LQueue *Q){
	if(IsEmptyLQueue(Q))
		return FALSE;
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front->next;
	Q->front->next = p->next;
	if (NULL == Q->front->next)  
		Q->rear = Q->front;
	free(p);
	return TRUE;
}

void ClearLQueue(LQueue *Q){
	if (IsEmptyLQueue(Q))
		return;
	Node *p, *q;
	Q->rear = Q->front;
	p = Q->front->next; 
	while (NULL != p) {
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	return;
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	int size;
	if (IsEmptyLQueue(Q))
		return FALSE;
	Node* p = (void *)malloc(Q->length); 
		p = Q->front->next; 
			int i = 1;
	while (p != NULL) {
			if (i % 5 == 0) printf("\n"); 
			foo(p->data);
			p = p->next;
			i++;
		}
		printf("\n");
	return TRUE;
}

void LPrint(void *q){
	int size;
	if (size == sizeof(double))
		printf("%lf", *(double *)q);
	if (size == sizeof(char))
		printf("%c", *(char *)q);
	if (size == sizeof (int))
		printf("%d", *(int *)q);
	printf("-<");
}
