// Implement a program to convert infix notation to postfix notation using stack
#include <stdio.h>

void pushopr(char);
char popopr();
char peepopr();
void display();

void pushout(char);
void displayout();

int getpriority(char);

char opr[25] = {'\0'};
char out[25] = {'\0'};
int topopr = -1;
int topout = -1;
char ch;

void main()
{
    char infix[25] = {'0'}, ele, popele;
    int i;
    printf("\n Enter infix Expression :-");
    scanf("%s", infix);
    printf("\n infix EXpression =%s", infix);
    i = 0;
    while (infix[i] != '\0')
    {
        ele = infix[i];
        if (ele == '(')
        {
            pushopr(ele);
        }
        else if (ele == ')')
        {
            while (peepopr() != '(')
            {
                popele = popopr();
                pushout(popele);
            }
            popopr();
        }
        else if (ele == '^' || ele == '*' || ele == '/' || ele == '+' || ele == '-')
        {
            if(topopr>=0)
            {
                while(getpriority(peepopr())>=getpriority(ele) && topopr!=-1)
                {
                popele = popopr();
                pushout(popele);
                }
            }
            pushopr(ele);
        }
        else
        {
            pushout(ele);
        }
        displayopr();
        displayout();
        i++;
    }
    if(topopr!=-1)
    {
        while(topopr!=-1)
        {
         popele = popopr();
         pushout(popele);   
        }
    }
    printf("\n postfix expression = %s",out);
}

int getpriority(char ele)
{
    switch (ele)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    }
    return -1;
}
void pushopr(char ele)
{
    if (topopr == 24)
        printf("\n Operator Stack is Full");
    else
    {
        topopr++;
        opr[topopr] = ele;
    }
}
char popopr()
{
    if (topopr != -1)
    {
        ch = opr[topopr];
        topopr--;
    }
    return ch;
}
char peepopr()
{
    if (topopr != -1)
        ch = opr[topopr];
    return ch;
}
void displayopr()
{
    int i;
    printf("\n Operator Stack =");
    for (i = 0; i <= topopr; i++)
        printf(" | %c ", opr[i]);
}
void pushout(char ele)
{
    if (topout == 24)
        printf("\n Output Stack is Full");
    else
    {
        topout++;
        out[topout] = ele;
    }
}
void displayout()
{
    int i;
    printf("\n output Stack =");
    for (i = 0; i <= topout; i++)
        printf(" | %c ", out[i]);
}