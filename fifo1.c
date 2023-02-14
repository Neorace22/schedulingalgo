#include <stdio.h>
int queue_size = 0, queue[20], f = -1, r = -1;

void push(int item)
{
    if (f== -1)
    {
        f = r = 0;
    }
    else
        r++;
    queue[r] = item;
    queue_size++;
}

void pop()
{
    f++;
    queue_size--;
}

int search(int item)
{
    for (int i = f; i <= r; i++)
    {
        if(queue[i]==item)
        return 1;
    } 
    return 0;
}

void display()
{
    for(int i=f;i<=r;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main()
{
    int n, l, page_fault = 0;
    int ref_string[20];
    printf("Enter the number of page frames : ");
    scanf("%d", &n);
    printf("Enter the length of the input string : ");
    scanf("%d", &l);
    printf("Enter the reference string : ");

    for (int i = 0; i < l; i++)
    {
        scanf("%d", &ref_string[i]);
    }

    for (int i = 0; i < l; i++)
    {
        if (search(ref_string[i]) == 0)
        {
            page_fault++;
            if (queue_size < n)
                push(ref_string[i]);
            else
            {
                pop();
                push(ref_string[i]);
            }
            
            display();
        }
        else 
        display();
    }

    printf("No of page faults : %d",page_fault);
}