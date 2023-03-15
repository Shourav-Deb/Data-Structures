// Create a program to evaluate the expression after being converted from infix to postfix (using only single digit & '+','-','*','/' operator).

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


char stack[20], evo[20], * x, * y;                                  // Variable Declaration & Initialization
float temp[20], a, b, c;
int top = -1, etop = -1, etemp = -1, size = 20;


int precition(char j)                                                   // function to check operator precision
{
    if (j == '+' || j == '-')
        return 1;
    if (j == '*' || j == '/')
        return 2;
    return 1;
}


void push(char i)                                                       // stack operation (push pop) while conversion
{
    top++;
    stack[top] = i;
}

void pop()
{
    printf("%c ", stack[top]);
    evo[++etop] = stack[top];
    top--;
}

void temp_push(float x)                                                  // stack operation (push pop) while evolution
{
    temp[++etemp] = x;
    printf("\nPushed - %.2f.", temp[etemp]);
}

float temp_pop()
{
    printf("\nPopped - %.2f.", temp[etemp]);
    return temp[etemp--];
}

int main()
{

    printf("# Enter the infix expression : ");
    scanf("%s", temp);

    // conversion process

    printf("\n\n--> The postfix expression is: (");

    x = temp;
    while (*x != NULL)
    {
        if (isdigit( *x))
        {
            printf("%c ", *x);
            evo[++etop] = *x;
        }
        else if ( * x == '+' || * x == '-' || * x == '*' || * x == '/')
        {
            while (top != -1)
            {
                if (precition(stack[top]) >= precition( * x))
                    pop();
                else
                    break;
            }
            push( * x);
        }
        else
        {
            printf("Expression contains invalid character !");
            break;
        }
        x++;
    }

    while (top != -1)
    {
        pop();
    }

    // evolution process

    printf(").\n\n\n>> Evaluation process of (%s):-\n",evo);

    y = evo;
    while ( * y != NULL)
    {
        if (isdigit( * y))
        {
            int number = * y - 48;
            temp_push(number);
        }
        else
        {
            a = temp_pop();
            b = temp_pop();

            if ( * y == '+')
            {
                c = b + a;
                printf("\t [%.2f + %.2f = %.2f]", b,a,c);
            }
            else if ( * y == '-')
            {
                c = b - a;
                printf("\t [%.2f - %.2f = %.2f]", b,a,c);
            }
            else if ( * y == '*')
            {
                c = b * a;
                printf("\t [%.2f * %.2f = %.2f]", b,a,c);
            }
            else if ( * y == '/')
            {
                c = b / a;
                printf("\t [%.2f / %.2f = %.2f]", b,a,c);
            }

            temp_push(c);
        }
        y++;
    }

    printf("\n\n--> The evaluated result of (%s) is: %.2f.\n\n", evo, temp_pop());

    return 0;
}
