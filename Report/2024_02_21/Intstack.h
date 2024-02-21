#ifndef ___IntStack
#define ___IntStack

//<--스텍을 구현하는 구조체-->//
typedef struct {
	int max; //stack capacity
	int ptr; // stack pointer
	int *stk; // stack first pointer
}IntStack; 

//stack initialize
int Initialize(IntStack *s, int max);

//data push
int Push(IntStack *s, int x);

//data pop
int Pop(IntStack *s, int *x);

//Peek to data in stack
int Peek(const IntStack *s,int *x);

//delete stack
void Clear(IntStack *s);

//stack maximum
int Capacity(const IntStack *s);

//data number
int Size(const IntStack *s);

//is empty?
int IsEmpty(const IntStack *s);

//is full?
int IsFull(const IntStack *s);

//search
int Search(const IntStack *s,int x);

//print all data
void Print(const IntStack *s);

//end

void Terminate(IntStack *s);
#endif 

 

