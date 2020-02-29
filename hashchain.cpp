#include<stdio.h>
#include<stdlib.h>
#define size 7
struct node
{
    int data;
    struct node *next;
};

struct node *chain[size];

void init()
{
    int i;
    for(i = 0; i < size; i++)
        chain[i] = NULL;
}

void insert(int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    int key = value % size;
    if(chain[key] == NULL)
        chain[key] = newNode;
    else
    {
        struct node *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}
int search(int key)
{
    int i;

    i=key%size;
    struct node *temp = chain[i];
    while(temp)
    {
        if(temp->data==key);
            return 1;
        temp = temp->next;
    }
    return 0;
}

void print()
{
    int i;

    for(i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        printf("chain[%d]-->",i);
        while(temp)
        {
            printf("%d -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int del(int value)
{
    int key = value % size;
    struct node *temp = chain[key], *dealloc;
    if(temp != NULL)
    {
        if(temp->data == value)
        {
            dealloc = temp;
            temp = temp->next;
            free(dealloc);
            return 1;
        }
        else
        {
            while(temp->next)
            {
                if(temp->next->data == value)
                {
                    dealloc = temp->next;
                    temp->next = temp->next->next;
                    free(dealloc);
                    return 1;
                }
                temp = temp->next;
            }
        }
    }

    return 0;
}

int main()
{
    init();
    int n,i,k,c;
    while(1)
    {
        printf("1.Insert()\n2.search()\n3.delete\n4.print()\n5.exit()\n");
        printf("Enter your choise : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("Enter how many elements you want to give : ");
                    scanf("%d",&n);
                    printf("Enter elements : ");
                    for(i=0;i<n;i++)
                    {
                     scanf("%d",&k);
                        insert(k);
                    }
                    break;
            case 2:printf("Enter element : ");
                    scanf("%d",&k);
                    if(search(k))
                    printf("YES\n");
                    else
                    printf("NO\n");
                    break;
            case 3:printf("Enter element To Delete: ");
                    scanf("%d",&k);
                    if(del(k))
                    printf("Deletion successful\n");
                    else
                    printf("Deletion Unsuccessful\n");
                    break;
            case 4:print();
                    break;
            case 5:exit(0); 
        }
    }

    return 0;
}
/*
OUTPUT:
1.Insert()                                                                                                              
2.search()                                                                                                              
3.delete                                                                                                                
4.print()                                                                                                               
5.exit()                                                                                                                
Enter your choise : 1                                                                                                   
Enter how many elements you want to give : 6                                                                            
Enter elements : 1 2 3 4 5 6                                                                                            
1.Insert()                                                                                                              
2.search()                                                                                                              
3.delete                                                                                                                
4.print()                                                                                                               
5.exit()                                                                                                                
Enter your choise : 2                                                                                                   
Enter element : 4                                                                                                       
YES                                                                                                                     
1.Insert()                                                                                                              
2.search()                                                                                                              
3.delete                                                                                                                
4.print()                                                                                                               
5.exit()
Enter your choise : 3                                                                                                   
Enter element To Delete: 5                                                                                              
Deletion successful                                                                                                     
1.Insert()                                                                                                              
2.search()                                                                                                              
3.delete                                                                                                                
4.print()                                                                                                               
5.exit()                                                                                                                
Enter your choise : 4                                                                                                   
chain[0]-->NULL                                                                                                         
chain[1]-->1 -->NULL                                                                                                    
chain[2]-->2 -->NULL                                                                                                    
chain[3]-->3 -->NULL                                                                                                    
chain[4]-->4 -->NULL                                                                                                    
chain[5]-->0 -->NULL                                                                                                    
chain[6]-->6 -->NULL                                                                                                    
1.Insert()                                                                                                              
2.search()                                                                                                              
3.delete                                                                                                                
4.print()                                                                                                               
5.exit()                                                                                                                
Enter your choise : 5         
*/