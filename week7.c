#include<stdio.h>
#include<stdlib.h>

struct node
{
        int info;
        struct node *link;
};
struct node *create_list(struct node *);
struct node *concat( struct node *start1,struct node *start2);
struct node *addatbeg(struct node *start, int data);
struct node *addatend(struct node *start,int data);
void display(struct node *start);

int main()
{
        while(1)
        {
            int ch;
            printf("enter one of the below choices\n");
            printf("1.sort\n");
            printf("2.concatenate\n");
            printf("3.reverse\n");
            printf("4.exit\n");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1 : sortList();
                         break;

                case 2 : toconcat();
                         break;

                case 3 : reverseList();
                         break;

                case 4 : exit(0);

                default : printf("please enter a valid choice \n");


            }
        }

        return 0;

}/*End of main()*/

int toconcat()
{
        struct node *start1=NULL,*start2=NULL;
        start1=create_list(start1);
        start2=create_list(start2);
        printf("\nFirst list is  : ");
        display(start1);
        printf("\nSecond list is  : ");
        display(start2);
        start1=concat(start1, start2);
        printf("\nConcatenated list is  : ");
        display(start1);

        return 0;

}

void sortList() {
        //Node current will point to head
        struct node *start0=NULL;
        start0=create_list(start0);
        printf("initial list is \n");
        display(start0);
        struct node *current = start0, *index = NULL;
        int temp;

        if(start0== NULL) {
            return;
        }
        else {
            while(current != NULL) {
                //Node index will point to node next to current
                index = current->link;

                while(index != NULL) {
                    //If current node's data is greater than index's node data, swap the data between them
                    if(current->info > index->info) {
                        temp = current->info;
                        current->info = index->info;
                        index->info= temp;
                    }
                    index = index->link;
                }
                current = current->link;
            }
        }
        printf("Sorted list: \n");
        display(start0);

    }

void reverseList()
{
    struct node *start3=NULL;
    start3=create_list(start3);
    struct node *prevNode=NULL, *curNode=NULL;

    if(start3 != NULL)
    {
        prevNode = start3;
        curNode = start3->link;
        start3 = start3->link;

        prevNode->link = NULL; // Make first node as last node

        while(start3 != NULL)
        {
            start3 = start3->link;
            curNode->link = prevNode;

            prevNode = curNode;
            curNode = start3;
        }

        start3 = prevNode; // Make last node as head

        printf("SUCCESSFULLY REVERSED LIST\n");
        printf("the reversed list is \n");
        display(start3);
    }
}





struct node *concat( struct node *start1,struct node *start2)
{
        struct node *ptr;
        if(start1==NULL)
        {
                start1=start2;
                return start1;
        }
        if(start2==NULL)
                return start1;
        ptr=start1;
        while(ptr->link!=NULL)
                ptr=ptr->link;
        ptr->link=start2;
        return start1;
}
struct node *create_list(struct node *start)
{
        int i,n,data;
        printf("\nEnter the number of nodes : ");
        scanf("%d",&n);
        start=NULL;
        if(n==0)
                return start;

        printf("Enter the element to be inserted : ");
        scanf("%d",&data);
        start=addatbeg(start,data);

        for(i=2;i<=n;i++)
        {
                printf("Enter the element to be inserted : ");
                scanf("%d",&data);
                start=addatend(start,data);
        }
        return start;
}/*End of create_list()*/

void display(struct node *start)
{
        struct node *p;
        if(start==NULL)
        {
                printf("\nList is empty\n");
                return;
        }
        p=start;
        while(p!=NULL)
        {
                printf("%d ", p->info);
                p=p->link;
        }
        printf("\n");
}/*End of display() */

struct node *addatbeg(struct node *start,int data)
{
        struct node *tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=data;
        tmp->link=start;
        start=tmp;
        return start;
}/*End of addatbeg()*/

struct node *addatend(struct node *start, int data)
{
        struct node *p,*tmp;
        tmp= (struct node *)malloc(sizeof(struct node));
        tmp->info=data;
        p=start;
        while(p->link!=NULL)
                p=p->link;
        p->link=tmp;
        tmp->link=NULL;
        return start;
}
