#include "../head/duLinkedList.h"
#include "stdlib.h"
#define DULINKEDLIST_H_INCLUDED
#define OVERFLOW -1

void main()
{
   DuLinkedList L;
   InitList_DuL(&L);
   DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode));
   q->data = 2;
   InsertBeforeList_DuL(L,q);
   DeleteList_Dul(L,2);
   InsertAfterList_DuL(L,q);
   TraverseList_DuL(L,(*visit)());
   DestroyList_DuL L;
}

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L)
{
   if(*L!=NULL)
   {
	   *L = (DuLinkedlist)malloc(sizeof(DuLNode));
      (*L)->next = *L;
      (*L)->prior = *L;
       return SUCCESS;
   }
   else 
	   return ERROR;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
Status DestroyList_DuL(DuLinkedList *L)
{
   DuLinkedList p = (*L)->next;
   DuLinkedList q;
   while(p!=NULL)
   {
	   q = p->next;
	   free(p);
	   p = q;
   }
   free(*L);
   *L = NULL;
   return SUCCESS;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
   q->prior = p->prior;
   q->next = p;
   p->prior = q;
   p->prior->next = q;
   return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
    q->prior = p;
	q->next = p->next;
	p->next->prior = q;
	p->next = q;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{
   *e = p->next->data;
   p->next = p->next->next;
   p->next->prior = p;
   free(p->next);
   return SUCCESS;

/*p->next = p->next->next;
   p->next->next->prior = p;
   *e = p->next;
   free(p->next);
   return SUCCESS;*/
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
Status TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
    DuLinkedlist current = L;
	while(current!=NULL)
	{
		visit(current->data);
		current = current->next;
		return SUCCESS;
	}
	return ERROR;
}
