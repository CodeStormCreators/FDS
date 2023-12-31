/*Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set
B of students like butterscotch ice-cream. Write C++ program to store two sets using
linked list. compute and displaya) Set of students who like both vanilla and butterscotch
b) Set of students who like either vanilla or butterscotch or not both
c) Number of students who like neither vanilla nor butterscotch
*/


#include <iostream>
using namespace std;

struct link *creat(int count, struct link *head);

void display(struct link *head);

void A_U_B();
void A_int_B();
void A_min_B();
void B_min_A();
void U_min_A_U_B();

struct link
{
    int data;
    struct link *next;
} * head_union, *head_A, *head_B;

int main()
{
    head_union = head_A = head_B = NULL;

    for (int i = 1; i < 4; i++)
    {
        if (i == 1)
        {
            int c;
            cout << "No. of student in class : ";
            cin >> c;
            cout << "\n";
            head_union = creat(c, head_union);
            display(head_union);
            cout << "\n";
        }

        if (i == 2)
        {
            int a;
            cout << "No. of student like vanilla icecream : ";
            cin >> a;
            cout << "\n";
            head_A = creat(a, head_A);
            display(head_A);
            cout << "\n";
        }

        if (i == 3)
        {
            int b;
            cout << "No. of student like butterscotch icecream :";
            cin >> b;
            cout << "\n";
            head_B = creat(b, head_B);
            display(head_B);
            cout << "\n";
        }
    }
    cout << "Set A :";
    display(head_A);
    cout << "Set B :";
    display(head_B);
    cout << "Set union :";
    display(head_union);
    cout << "\n";

    A_U_B();
    A_int_B();
    A_min_B();
    B_min_A();
    U_min_A_U_B();

    return 0;
}
struct link *creat(int count, struct link *head)
{
    struct link *s, *newNode;

    for (int i = 0; i < count; i++)
    {
        newNode = new (struct link);
        cout << "Enter roll no of student :";
        cin >> newNode->data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            s = head;
        }
        else
        {
            s->next = newNode;
            s = s->next;
        }
    }
    return head;
}

void display(struct link *head)
{
    struct link *m;
    m = head;
    while (m != NULL)
    {
        cout << " " << m->data;
        m = m->next;
    }
    cout << "\n";
}
void A_U_B()
{
    struct link *p, *q;
    p = head_A;
    q = head_B;
    int a[20];
    int i = 0;
    while (p != NULL && q != NULL)
     {
         if (p->data == q->data)
         {
             a[i] = p->data;
             i++;
             p = p->next;
             q = q->next;
         }
         else
         {
             a[i] = p->data;
             i++;
             p = p->next;
         }
     }
      
    if (p == NULL)
    {
        while (q != NULL)
        {
            a[i] = q->data;
            i++;
            q = q->next;
        }
    }
    if (q == NULL)
    {
        while (p != NULL)
        {
            a[i] = p->data;
            i++;
            p = p->next;
        }
    }
    cout << "Set A union B : ";
    for (int j = 0; j < i; j++)
    {
        cout << " " << a[j];
    }
    cout << "\n";
}

void A_int_B()
{
    struct link *p, *q;
    int b[20];
    p = head_A;

    int i = 0;
    while (p != NULL)
    {
        q = head_B;
        while (q != NULL)
        {
            if (p->data == q->data)
            {
                b[i] = p->data;
                i++;
                break;
            }
            q = q->next;
        }
        p = p->next;
    }

    cout << "Set A intersection B : ";
    for (int j = 0; j < i; j++)
    {
        cout << " " << b[j];
    }
    cout << "\n";
}

void A_min_B()
{
    struct link *p, *q;
    int i = 0;
    int c[20];
    p = head_A;

    while (p != NULL)
    {
        int flag = 0;
        q = head_B;
        while (q != NULL)
        {
            if (p->data == q->data)
            {
                flag = 1;
                break;
            }
            q = q->next;
        }
        if (flag == 0)
        {
            c[i] = p->data;
            i++;
        }
        p = p->next;
    }

    cout << "Set A minues B : ";
    for (int j = 0; j < i; j++)
    {
        cout << " " << c[j];
    }
    cout << "\n";
}

void B_min_A()
{
    struct link *p, *q;
    int i = 0;
    int d[20];
    
    q = head_B;
    while (q != NULL)
    {
        int flag = 0;
        p = head_A;
        while (p != NULL)
        {
            if (p->data == q->data)
            {
                flag = 1;
                break;
            }
            p = p->next;
        }
        if (flag == 0)
        {
            d[i] = q->data;
            i++;
        }
        q = q->next;
    }

    cout << "Set B minus A : ";
    for (int j = 0; j < i; j++)
    {
        cout << " " << d[j];
    }
    cout << "\n";
}
void U_min_A_U_B()
{
    struct link *p, *q, *r;
    int e[20];
    int i = 0;

    r = head_union;
    while (r != NULL)
    {
        int flag = 0;
        p = head_A;
        q = head_B;
        while (p != NULL)
        {
            if (r->data == p->data)
            {
                flag = 1;
                break;
            }
            p = p->next;
        }
        while (q != NULL)
        {
            if (r->data == q->data)
            {
                flag = 1;
                break;
            }
            q = q->next;
        }
        if (flag == 0)
        {
            e[i] = r->data;
            i++;
        }
        r = r->next;
    }
    cout << "Set U minus A union B : ";
    for (int j = 0; j < i; j++)
    {
        cout << " " << e[j];
    }
    cout << "\n";
}
