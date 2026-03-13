#include<iostream>
#include<cstring>
using namespace std;

struct Node
{
    char data;
    struct Node *next;
}*top = NULL;

void push(char x)
{
    struct Node *t = new struct Node;
    t->data = x;
    t->next = top;
    top = t;
}

char pop()
{
    struct Node *t;
    char x = -1;
    if(top==NULL)
        return x;
    else
        t = top;
    x = t->data;
    top = top->next;
    delete t;
    return x;
}

int isOperand(char c)           //check if character is operand or not
{
    if(c=='+' ||c=='-' ||c=='*' ||c=='/')
        return 0;
    else
        return 1;
}

int pre(char c)                 //check precedence
{
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    return 0;           //when stack is empty, return 0
}

char *convert(char *infix)
{
    char *postfix;
    int len = strlen(infix);
    postfix = new char[len+1];      //increasing string size by +1
    int i=0,j=0;
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(top==NULL || pre(infix[i]) > pre(top->data))   //if stack is empty, we will push operator in the stack
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }
    while(top!=NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j] ='\0';
    return postfix;
}
int main()
{
    char *infix = "a+b*c-d/e";    ///pointer to an array behaves like an array name

    char *postfix = convert(infix);
    cout<< postfix;

    delete[] postfix;
}
