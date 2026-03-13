#include<iostream>
using namespace std;
struct Stack
{
    char data;
    struct Stack *next;
};
typedef struct Stack Node;
Node *top = NULL;

void push(char x)
{
    Node *t = new Node;
    t->data = x;
    t->next = top;
    top = t;
}

char pop()
{
    Node *t;
    char x= -1;
    if(top==NULL)
        return x;

    t = top;
    top = top->next;
    x = t->data;
    delete t;
    return x;
}

int isMatchingPair(char open, char close)
{
    if(open=='(' && close==')') return 1;
    if(open=='{' && close=='}') return 1;
    if(open=='[' && close==']') return 1;
    return 0;
}

int isBalanced(char *p)
{
    for(int i=0; p[i]!='\0'; i++)
    {
        if(p[i]=='(' || p[i]=='{' || p[i]=='[')
        {
            push(p[i]);
        }
        else if(p[i]==')' || p[i]=='}' || p[i]==']')
        {
            if(top==NULL)
                return 0;
            char topBracket = pop();

            if( !isMatchingPair(topBracket, p[i]))
                return 0;
        }
    }
    if(top==NULL)
        return 1;               //return true if balanced, false otherwise
    else
        return 0;
}
int main()
{
    char str[] = "({[a+b]*(c+d)})";
    char *p = str;
    cout<< isBalanced(p);
}
