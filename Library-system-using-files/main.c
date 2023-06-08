#include<stdio.h>
#include<stdlib.h>
#include <string.h>

 struct Book
{
    int id;
    int quantity;
    char name[15];
}book[50],cpy[50],delet[50],sorrt[50];

int i=0;
char c;
FILE* file;


void addBook(int id,int quantity,char name[50]);
void dltBook(int id);
int linearSrch(int key);
int binarySrch(char name[],int start,int end1);
void sortData();
void unsortData();


int main()
{

    file=fopen("library.txt","r");
    if (file==NULL)
    {
        printf("file could not be open\n");
    }
    else
    {
        while(!feof(file))
        {

            fscanf(file,"%d %d %[^\n]",&book[i].id,&book[i].quantity,book[i].name);
            cpy[i].id=book[i].id;
            cpy[i].quantity=book[i].quantity;
            strcpy(cpy[i].name,book[i].name);
            i++;
        }
    }
    fclose(file);

    do
    {
        system("cls");
         printf("Select the number of the operation:-\n");
         printf("1-Add new book\n");
         printf("2-Delete an existing book\n");
         printf("3-Search for a book by it's ID\n");
         printf("4-Search for a book by name\n");
         printf("5-Display all books sorted by their name\n");
         printf("6-Display all books unsorted as entered\n");
         printf("Enter your operation number:\n");
         int menu;
         scanf("%d",&menu);
         switch(menu)
         {
         case 1:
             {
            int id,quantity;
            char name[50];
            printf("Enter the book id\n");
            scanf("%d",&id);
            printf("Enter the book quantity\n");
            scanf("%d",&quantity);
            printf("Enter the book name\n");
            fflush(stdin);
            gets(name);
            addBook(id,quantity,name);
            printf("the book is added to file\n");
            break;
             }

         case 2:
             {
             printf("Enter the id of the book you want to delete:\n");
             int id;
             scanf("%d",&id);
             dltBook(id);
             break;
             }

         case 3:
             {
             printf("Enter the id of the book you want to search:\n");
             int id, srch;
             scanf("%d",&id);
             srch=linearSrch(id);
             if(srch>=0)
             {
                 printf("quantity: %d\t name: %s\n",book[srch].quantity,book[srch].name);
             }
             else
                printf("id not found\n");
             break;
             }
         case 4:
             {
             printf("Enter the book name you want to search:\n");
               int srch;
             char name[50];
             fflush(stdin);
             gets(name);
             sortData();
             srch=binarySrch(name,0,i);
             printf("id: %d\t quantity: %d\n",sorrt[srch].id,sorrt[srch].quantity);
             break;
             }
         case 5:
             {
             printf("Books after sorting\n");
             int s=0;
             sortData();
             while(s<i)
             {

                 printf("Name:\tID\tQuantity\n");
                 printf("%s\t%d\t%d\n",sorrt[s].name,sorrt[s].id,sorrt[s].quantity);
                 s++;
             }
             printf("\n");
             break;
             }
         case 6:
             {
              unsortData();

             }
         }
         printf("Do you want to continue?(Y/N)\n");
         scanf(" %c",&c);
    }
    while(c=='Y' || c=='y');
}
void addBook(int id,int quantity,char name[15])
{
    struct Book book[50];
    struct Book cpy[50];
    file=fopen("library.txt","a");
    book[i].id=id;
    book[i].quantity=quantity;
    strcpy(book[i].name,name);
    cpy[i].id=id;
    cpy[i].id=id;
    strcpy(cpy[i].name,name);
    fprintf(file,"\n%d\t%d\t%s\n",book[i].id,book[i].quantity,book[i].name);
    i++;
    fclose(file);
}
void dltBook(int id)
{
    int x,y,z,n;
    file=fopen("library.txt","w+");
    for(x=0;x<i-1;x++)
    {
        if( book[x].id==id )
            {
               char temp[15];
               for(y=0;y<i-1;y++){
               book[y].id=book[y+1].id;
               strcpy(temp,book[y].name);
               strcpy(book[y].name,book[y+1].name);
               strcpy(book[y+1].name,temp);
               book[y].quantity=book[y+1].quantity;
            }
            i--;

        }

    }
    for(z=0;z<i-1;z++)
        fprintf(file,"\n%d\t%d\t%s",book[z].id,book[z].quantity,book[z].name);
    fclose(file);
}
int linearSrch(int key)
{
    int size=0;

    while(size<i){
         if(book[size].id==key)
         {
            return size;
         }
         else if(book[size].id==NULL)
         {
            return -1;
         }
    size++;
    }


}
void sortData()
{
    int c=0;
    while(c<i+2)
    {
        sorrt[c].id=book[c].id;
        sorrt[c].quantity=book[c].quantity;
        strcpy(sorrt[c].name,book[c].name);
        c++;
    }
    char arry[80];
    int temp1,temp2;
    for(int cnt=1;cnt<i+2;cnt++)
    {
        for(int a=0;a<i-cnt;a++)
        {
            if(strcmp(sorrt[a].name,sorrt[a+1].name)>0)
            {
                strcpy(arry,sorrt[a].name);
                strcpy(sorrt[a].name,sorrt[a+1].name);
                strcpy(sorrt[a+1].name,arry);
                temp1=sorrt[a+1].id;
                temp2=sorrt[a+1].quantity;
                sorrt[a+1].id=sorrt[a].id;
                sorrt[a+1].quantity=sorrt[a].quantity;
                sorrt[a].id=temp1;
                sorrt[a].quantity=temp2;
            }
        }
    }
}
int binarySrch(char name[],int start,int end1)
{

    int middle;
    middle=(start+end1)/2;
    if(strcmp(sorrt[middle].name,name)==0)
    {
        return middle;
    }
    else if(strcmp(sorrt[middle].name,name)>0)
    {
        return binarySrch(name,start,middle);
    }
    else if(strcmp(sorrt[middle].name,name)<0)
    {
        return binarySrch(name,middle,end1);
    }
}
void unsortData(){
    int j=0;
            while(j<i)
            {
                printf("Name:\tID\tQuantity\n");
                printf("%s\t%d\t%d\n",cpy[j].name,cpy[j].id,cpy[j].quantity);
                j++;
            }

}
