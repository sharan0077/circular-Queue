#include "circularQueLib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
cirQueue* create(int typeSize,int noOfElements){
	cirQueue *queue = malloc(sizeof(cirQueue));
	queue->baseAddress = calloc(noOfElements,typeSize);
	queue->length = noOfElements;
	queue->elementSize = typeSize;
	queue->front = -1;
	queue->rear = 0;
	return queue;
}
int enqueue(cirQueue *queue,void* element){
	void* destinationAddr; 
	if((queue->rear)%queue->length==queue->front)
		return 0;
	destinationAddr = queue->baseAddress+(queue->rear*queue->elementSize); 
	memcpy(destinationAddr,element,queue->elementSize);
	queue->rear = (queue->rear+1)%queue->length;
	if(queue->front==-1) queue->front = 0;
	return 1;
}
void* dequeue(cirQueue *queue){
	void *dequedElement;
	if(queue->front==queue->rear && queue->front!=0)
		return NULL;
	dequedElement = queue->baseAddress+(queue->front*queue->elementSize);
	queue->front = (queue->front+1)%queue->length;
	return dequedElement;
}