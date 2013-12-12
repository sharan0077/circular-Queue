#include "testUtils.h"
#include "circularQueLib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

cirQueue expected,*actual;

int areEqual(cirQueue a,cirQueue e){
	int result;
	result = a.length == e.length && a.elementSize == e.elementSize;
	if(!result) return 0;
	return 0 == memcmp(a.baseAddress,e.baseAddress,a.elementSize*a.length); 
}
void test_should_create_cirQue_to_store_intData_and_return_true(){
	int arr[] = {0,0,0,0,0};
	int result;
	expected.baseAddress = arr;
	expected.length = 5;
	expected.elementSize = sizeof(int);
	actual = create(sizeof(int),5);
	result = areEqual(*actual,expected);
	ASSERT(result);
	ASSERT(actual->front==-1);
	ASSERT(actual->rear==0);
	ASSERT(*((int*)actual->baseAddress+2) == 0);
	free(actual->baseAddress);
	free(actual);
}
void test_should_create_cirQue_to_store_doubleData_and_return_true(){
	double arr[] = {0,0,0,0,0};
	int result;
	expected.baseAddress = arr;
	expected.length = 5;
	expected.elementSize = sizeof(double);
	actual = create(sizeof(double),5);
	result = areEqual(*actual,expected);
	ASSERT(result);
	ASSERT(actual->front==-1);
	ASSERT(actual->rear==0);
	ASSERT(*((double*)actual->baseAddress+2) == 0);
	free(actual->baseAddress);
	free(actual);
}
void test_should_create_cirQue_to_store_StringData_and_return_true(){
	String *ptr = calloc(5,sizeof(String));
	int result;
	expected.baseAddress = ptr;
	expected.length = 5;
	expected.elementSize = sizeof(String);
	actual = create(sizeof(String),5);
	result = areEqual(*actual,expected);
	ASSERT(result);
	ASSERT(actual->front==-1);
	ASSERT(actual->rear==0);
	ASSERT(0==strcmp("", (char*)actual->baseAddress+2));
	free(actual->baseAddress);
	free(actual);
}
void test_should_enqueue_intElement_into_que_and_return_true(){
	int result;
	int* element = malloc(sizeof(int));
	*element = 4;
	actual = create(sizeof(int),5);
	result = enqueue(actual,element);
	ASSERT(result);
	ASSERT(*((int*)actual->baseAddress)==4);
	ASSERT(actual->rear==1);
	free(actual->baseAddress);
	free(actual);
	free(element);
}
void test_should_enqueue_doubleElement_into_que_and_return_true(){
	int result;
	double* element = malloc(sizeof(double));
	*element = 4.5;
	actual = create(sizeof(double),5);
	result = enqueue(actual,element);
	ASSERT(result);
	ASSERT(*((double*)actual->baseAddress)==4.5);
	ASSERT(actual->rear==1);
	free(actual->baseAddress);
	free(actual);
	free(element);
}
void test_should_enqueue_stringElement_into_que_and_return_true(){
	int result;
	char* element = malloc(sizeof(String));
	strcpy(element, "abc");
	actual = create(sizeof(String),3);
	result = enqueue(actual,element);
	ASSERT(result);
	ASSERT(0 == strcmp("abc",(*(String*)actual->baseAddress)));
	ASSERT(actual->rear==1);
	free(actual->baseAddress);
	free(actual);
	free(element);
}
void test_should_dequeue_stringElement_from_que_and_return_true(){
	char* result;
	char* element = malloc(sizeof(String));
	strcpy(element, "abc");
	actual = create(sizeof(String),3);
	enqueue(actual,element);
	result = dequeue(actual);
	ASSERT(0 == strcmp("abc",result));
	ASSERT(actual->rear==1);
	free(actual->baseAddress);
	free(actual);
	free(element);
}
void test_should_dequeue_Intelement_from_the_queue_and_return_address_of_it(){
	int result;
	int* element = malloc(sizeof(int));
	*element = 4;
	actual = create(sizeof(int),5);
	enqueue(actual,element);
	*element = 5;
	enqueue(actual,element);
	ASSERT(*(int*)dequeue(actual)==4);
	free(actual->baseAddress);
	free(actual);
	free(element);
}
void test_should_dequeue_DoubleElement_from_the_queue_and_return_address_of_it(){
	int result;
	double* element = malloc(sizeof(double));
	*element = 4.5;
	actual = create(sizeof(double),5);
	enqueue(actual,element);
	*element = 5.5;
	enqueue(actual,element);
	ASSERT(*(double*)dequeue(actual)==4.5);
	free(actual->baseAddress);
	free(actual);
	free(element);
}
void test_should_not_enque_Element_into_que_and_return_false_when_que_full(){
	int result;
	int* element = malloc(sizeof(int));
	*element = 4;
	actual = create(sizeof(int),3);
	enqueue(actual,element);
	enqueue(actual,element);
	enqueue(actual,element);
	result = enqueue(actual,element);
	ASSERT(!result);
	ASSERT(*((int*)actual->baseAddress)==4);
	ASSERT(actual->rear==0);
	free(actual->baseAddress);
	free(actual);
	free(element);
}
void test_should_not_dequeue_Element_from_que_and_return_false_when_que_empty(){
	void* result;
	int* element = malloc(sizeof(int));
	actual = create(sizeof(int),3);
	*element = 4;
	enqueue(actual,element);
	dequeue(actual);
	result  = dequeue(actual);
	ASSERT(result==NULL);
	free(actual->baseAddress);
	free(actual);
	free(element);
}
void test_should_enqueue_intElement_into_que_at_zero_position(){
	int result;
	int* element = malloc(sizeof(int));
	*element = 4;
	actual = create(sizeof(int),3);
	enqueue(actual,element);
	*element = 5;
	enqueue(actual,element);
	*element = 6;
	enqueue(actual,element);
	dequeue(actual);
	*element = 7;
	result = enqueue(actual,element);
	ASSERT(result);
	ASSERT(*((int*)actual->baseAddress)==7);
	ASSERT(actual->rear==1);
	free(actual->baseAddress);
	free(actual);
	free(element);
}
