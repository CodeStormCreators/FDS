/*In any language program mostly syntax error occurs due to unbalancing delimiter such as
(),{},[]. Write C++ program using stack to check whether given expression is well
parenthesized or not.*/

#include <iostream>
using namespace std;
#define size 10
class stack
{
public:
    int rear = -1;
    char s[size];
    int isfull()
    {
        if (rear == size - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int isempty()
    {
        if (rear == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void push(char x)
    {
        if (isfull() == 1)
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            rear++;
            s[rear] = x;
        }
    }
    void pop()
    {
        if (isempty() == 1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            char a;
            a = s[rear];
            rear--;
        }
    }
};

int main()
{
    stack obj;
    char expression[20];
    char ch, n;
    int i = 0;
    do
    {
        cout << "Enter a expression : ";
        cin >> expression;
        if ((expression[0] == ')') || (expression[0] == ']') || (expression[0] == '}'))
        {
            cout << "Invalid expression....." << endl;
            exit(0);
        }
        else
        {
            while (expression[i] != '\0')
            {
                ch = expression[i];
                switch (ch)
                {
                case '(':
                    obj.push(ch);
                    break;
                case '[':
                    obj.push(ch);
                    break;
                case '{':
                    obj.push(ch);
                    break;
                case ')':
                    obj.pop();
                    break;
                case ']':
                    obj.pop();
                    break;
                case '}':
                    obj.pop();
                    break;
                }
                i++;
            }
        }
        if (obj.isempty() == 1)
        {
            cout << "Valid expression....." << endl;
        }
        else
        {
            cout << "Invalid expression....." << endl;
        }
        cout << "Do you want to check one more expression (y/ n) : ";
        cin >> n;
    } while (n == 'y');
    return 0;
}
