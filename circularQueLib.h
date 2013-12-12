typedef struct{
	void* baseAddress;
	int elementSize;
	int length;
	int front;
	int rear;
}cirQueue;
typedef char String[256];
cirQueue* create(int typeSize,int noOfElements);
int enqueue(cirQueue *queue,void* element);
void* dequeue(cirQueue *queue);
