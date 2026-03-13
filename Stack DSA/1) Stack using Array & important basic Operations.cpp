#include<iostream>
using namespace std;
struct Stack
{
    int size;
    int top;                  //Index of the top element in the stack
    int *p;                   //pointer to the array representing the stack
};

void create(struct Stack *st)
{
    cout<< "Enter the size of the stack: ";
    cin>> st->size;
    if(st->size <= 0)
    {
        cout<< "Invalid stack size. Setting stack size to 1.";
        st->size=1 ;
    }
    st->top= -1 ;              //Initially, stack is empty
    st->p = new int[st->size];
}

void Display(const struct Stack &st)
{
    for(int i=st.top; i>=0; i--)       //display starts from top
    {
        cout<< st.p[i] << " ";
    }
    cout<<endl;
}

void push(struct Stack *st, int x)         ///PUSH FUNCTION
{
    if(st->top==st->size-1)
    {
        cout<< "Stack Overflow" <<endl;
    }
    else
    {
        st->top++ ;
        st->p[st->top] = x;
    }
}

int pop(struct Stack *st)                   ///POP FUNCTION
{
    int x= -1;
    if(st->top== -1)
        cout<< "Stack Underflow" <<endl;
    else
    {
        x = st->p[st->top];
        st->top-- ;
    }
    return x;
}

int peek(const struct Stack &st, int pos)           ///PEEK FUNCTION
{
    int x= -1;
    if(pos<=0 || pos > st.top+1)
        cout<< "Invalid position" << "\t";
    else
    {
        x = st.p[st.top-pos+1];        //Index = st.top-pos+1
    }
    return x;
}

int stackTop(const struct Stack &st)              ///STACK TOP FUNCTION
{
    if(st.top==-1)
        return -1;
    else
        return st.p[st.top];
}

int isEmpty(const struct Stack &st)              ///IS EMPTY FUNCTION
{
    return st.top == -1? 1:0 ;    //Return 1 (true) if empty, else 0 (false)
}

int isFull(const struct Stack &st)               ///IS FULL FUNCTION
{
    return st.top == st.size-1 ? 1:0 ;   //Return 1 (true) if empty, else 0 (false)
}

int main()
{
    struct Stack ob;
    create(&ob);
    push(&ob,7);
    push(&ob,10);
    push(&ob,15);

    Display(ob);

    cout<< peek(ob,3) <<endl;

    cout<< pop(&ob) <<endl;

    cout<< stackTop(ob) <<endl;

    cout<< isEmpty(ob) <<endl;

    cout<< isFull(ob);

    delete []ob.p;                    ///Deallocating the heap memory
    ob.p = nullptr;                 //better to use nullptr than NULL in c++
}
