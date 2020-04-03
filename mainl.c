#include "../head/linkedList.h"
#include "stdlib.h"
#define LINKEDLIST_H_INCLUDED
#define OVERFLOW -1

void main()
{
   Linkedlist L;
   InitList(&L);
   LinkedList q = (LinkedList)malloc(sizeof(Node));
   q->data = 2;
   InsertList(L,q);
   DeleteList(L,2);
   TraverseList(L,(*visit)());
   SearchList(L,e);
   IsLoopList L;
   ReverseList L;
   DestroyList L;
}

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L)
{
   if(*L!=NULL)
   {
	   *L = (LinkedList)malloc(sizeof(Node));
       (*L)->next = NULL;
	   return SUCCESS;
   }
   else
	   return ERROR;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L)
{
  Linkedlist p, q;
  p = (*L)->next;
  while(p)
  {
	  q = p->next;
	  free(p);
	  p = q;
  }
  (*L)->next = NULL;
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q)
{
   q->next = p->next;
   p->next = q;
   return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e)
{
   p->next = p->next->next;
   *e = p->next->data;
   free(p->next);
   return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
  LinkedList current = L;
    while(current != NULL)
	{
        visit(current->data);
        current = current->next;
	}
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e)
{
   Linkedlist p;
   p = L->next;
   e = p->data;
   return SUCCESS;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L)
{
   Linkedlist *p, *s, *t;
   p = L;
   s = p->next;
   while(s->next!=NULL)
   {
	   t = s->next;
	   s->next = p;
	   p = s;
	   s = t;
   }
   else
	   return ERROR;
   s->next = p;
   L->next->next = NULL;
   L->next = s;
   return SUCCESS;

}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L)
{
   if(L==NULL)return ERROR;
   LinkedList *slow = L;
   LinkedList *fast = L->next;
   while(slow!=fast)
   {
	   if(fast==NULL||fast->next==NULL)
	   {
		   return ERROR;
	   }
	   slow = slow->next;
	   fast = fast->next->next;
   }
   return SUCCESS;
}
