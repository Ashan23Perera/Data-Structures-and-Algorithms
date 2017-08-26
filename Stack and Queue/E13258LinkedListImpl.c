#include <stdio.h>
#include <stdlib.h>
#include "StackAndQueue.h"

//define the stack
struct stack
{
	int current;
	struct stack *next;
};

//define the queue
struct queue
{
	int current;
	struct queue *next;
};

//create the stack
Stack* CreateStack() {
	Stack *stk=(Stack*)malloc(sizeof(Stack));
	stk->next=NULL;
	return stk;
}

//delete stack
int DeleteStack(Stack* stack)
{
    int ret =0;
    if(stack!=NULL)
    {
	Stack* number=(Stack*)malloc(sizeof(Stack));
	int i;
	for(number=stack;stack!=NULL;stack=number->next)
        {
	
	   free(number);
	}
     }
     else
     {
            ret = -1;
     }
 	return 0;
}

//create queue
Queue* CreateQueue()
{
	Queue *que=(Queue*)malloc(sizeof(Queue));
	que->next=NULL;
	return que;
}

//delete queue
int DeleteQueue(Queue* queue) 
{
      int ret = 0;	 
      if(queue!=NULL)
      {
	
	Queue* number=(Queue*)malloc(sizeof(Queue));

	 for(queue=number;(queue!=NULL);queue=number->next)
         {
		free(number);
	 }
     }
     else
     {
          ret = -1;
     }
	return ret;
}

//stack push 
int StackPush(Stack* stack, int value) 
{
 int ret = 0;
    if(stack!=NULL)   
    {
        stack->current=value;
        stack=stack->next;
    }
    else
    {
         ret = -1;
    } 
 return ret;
}

//stack pop
int StackPop(Stack* stack, int* value) 
{
	int ret=-1;
        if(stack->next!=NULL)
        { 
		*value=stack->next->current;
		Stack *node=stack->next;
		stack->next=node->next;
		free(node);
	}
        else
        {
                ret = -1;
        }    
  return ret;
}

//stack peek
int StackPeek(const Stack* stack, int* value) {
        int ret = 0;     
 	if(stack->next==NULL) 
        {
             *value=stack->next->current;
             printf("%d\n",*value);
	}
        else
	{
	        ret = -1;
        }
  return ret;     
}

//queue enqueue
int QueueEnqueue(Queue* queue, int value)
{
	
        for(;queue->next!=NULL;queue=queue->next);
        
        Queue * q=(Queue*)malloc(sizeof(Queue));
	q=queue->next;
        q->next=NULL;
	q->current=value;
 return 0;
}

//Queue dequeue
int QueueDequeue(Queue* queue, int* value) {
        int ret = 0; 
	if(queue->next!=NULL)
        {
	    *value=queue->next->current;
	    queue->next=queue->next->next;
	    free(queue->next);
	}
        else
        {
             ret=-1;
        }    
  return ret;
}

//queue peek
int QueuePeek(const Queue* queue, int* value) {
	int ret = 0;
        if(queue->next!=NULL)
        {
		*value=queue->next->current;
                printf("%d\n",*value);
	}
        else  
	{
            ret = -1;
        }
  return ret;
}


