#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*top = NULL;

void push(int x)
{
    struct Node *t = new struct Node;
    t->data = x;
    t->next = top;
    top = t;
}

int pop()
{
    struct Node *t;
    int x = -1;
    if(top==NULL)
        return x;
    else
        t = top;
    x = t->data;
    top = top->next;
    delete t;
    return x;
}

int isOperand(char c)
{
    if(c=='+' ||c=='-' ||c=='*' ||c=='/')
        return 0;
    else
        return 1;
}

int Eval(char *post)
{
    int i, x1, x2, r;
    for(i=0; post[i]!='\0'; i++)
    {
        if(isOperand(post[i]))
            push(post[i] - '0');
//integer stack, so post[i] will be stored as ascii value which isn't actual number, so we're subtracting '0'/48
        else
        {
            x2 = pop();       //first popped out element will be 2nd operator
            x1 = pop();       //second popped out element will be 1st operator
            switch(post[i])
            {
            case '+' :
                r= x1+x2;
                break;
            case '-' :
                r= x1-x2;
                break;
            case '*' :
                r= x1*x2;
                break;
            case '/' :
                r= x1/x2;
                break;
            }
            push(r);        //push result into the stack
        }
    }
    return pop();
}

int main()
{
    char *postfix = "234*+82/-";

    int res = Eval(postfix);
    cout<< res;
}
