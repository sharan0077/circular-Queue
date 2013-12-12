#include <stdio.h>

int testCount=0;
int passCount=0;

void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();

void testStarted(char* name){
	printf("\t%s\n",name);
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber){
	printf("\t\t*** failed at %s:%d\n",fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	setup();
		test_should_create_cirQue_to_store_intData_and_return_true();
	tearDown();

	setup();
		test_should_create_cirQue_to_store_doubleData_and_return_true();
	tearDown();

	setup();
		test_should_create_cirQue_to_store_StringData_and_return_true();
	tearDown();

	setup();
		test_should_enqueue_intElement_into_que_and_return_true();
	tearDown();

	setup();
		test_should_enqueue_doubleElement_into_que_and_return_true();
	tearDown();

	setup();
		test_should_enqueue_stringElement_into_que_and_return_true();
	tearDown();

	setup();
		test_should_dequeue_stringElement_from_que_and_return_true();
	tearDown();

	setup();
		test_should_dequeue_Intelement_from_the_queue_and_return_address_of_it();
	tearDown();

	setup();
		test_should_dequeue_DoubleElement_from_the_queue_and_return_address_of_it();
	tearDown();

	setup();
		test_should_not_enque_Element_into_que_and_return_false_when_que_full();
	tearDown();

	setup();
		test_should_not_dequeue_Element_from_que_and_return_false_when_que_empty();
	tearDown();

	setup();
		test_should_enqueue_intElement_into_que_at_zero_position();
	tearDown();


	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
