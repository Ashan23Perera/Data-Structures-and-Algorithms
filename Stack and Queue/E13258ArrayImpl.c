#include "StackAndQueue.h"
#include <stdio.h>
#include <stdlib.h>

#define Nu_Of_Elements 1000000

//define the stack
struct stack
{
	int stacknumber[Nu_Of_Elements];
	int number;	
};

//define the queue
struct queue 
{
	int queuenumber[Nu_Of_Elements];
	int number;
	
};

//create the Stack
Stack* CreateStack() 
{
	Stack* stk=(Stack *)malloc(sizeof(Stack));
	stk -> number = 0; //when create a stack it start to count 0 always
	
return stk;
}

//delete Stack
int DeleteStack(Stack* stack) 
{
	free(stack);  
        stack=NULL;
	return 0;
}

//Create Queue
Queue* CreateQueue() 
{
	Queue* que =(Queue *)malloc(sizeof(Queue));
	que -> number = 0;  //when create a queue it start to count 0 always
return que;
}

//delete Queue
int DeleteQueue(Queue* queue) 
{
	
	free(queue);
        queue=NULL;
return 0;
} 

//Stack push
int StackPush(Stack* stack, int value) 
{
     int ret=0; 
     if((stack->number)!=(Nu_Of_Elements))
     { 
        stack->stacknumber[stack->number]=value;
        stack->number=(stack->number)+1;  
         
     }
     else
     {
        ret=-1; 
     }
  return ret;
}

//Stack Pop
int StackPop(Stack* stack, int* value) 
{
	int ret=0;
        if (stack -> number != -1)
        {
  	  stack -> number=(stack->number)-1;
	  *value = stack -> stacknumber[stack -> number];
        }
        else
        {
            ret = -1;
        } 
  return ret;
}

//Stack Peek
int StackPeek(const Stack* stack, int* value)
{
	int ret=0;
        if (stack -> number != -1)
        {
	    *value = stack -> stacknumber[stack -> number];
            printf("%d\n",*value);
        }
        else
        {
              ret=-1;
        }     	
  return ret;
}

//Queueu Enqueue
int QueueEnqueue(Queue* queue, int value)
{
   int ret=0; 
     if((queue->number)!=(Nu_Of_Elements))
     { 
        queue->queuenumber[queue->number]=value;
        queue->number=(queue->number)+1;  
         
     }
     else
     {
        ret=-1; 
     }
  return ret;
}

//Queue Dequeue
int QueueDequeue(Queue* queue, int* value)
{
        int ret=0;
	if(queue -> number == 0)
        { 
           ret =-1;
        }
        else 
        {
              *value = queue -> queuenumber[0];
             int i;
	     for(i=1;i<queue -> number;i++)
             {
	         queue->queuenumber[i-1]=queue->queuenumber[i];
	     }
	     queue -> number=(queue ->number)-1;
        }
    return ret;
}

//Queue Peek
int QueuePeek(const Queue* queue, int* value) 
{
	int ret =0;
        if(queue -> number == 0)
        {
              ret = -1;
	} 
        else
        {
              *value = queue -> queuenumber[0];
              printf("%d\n",*value);
 	}
  return ret;
}
