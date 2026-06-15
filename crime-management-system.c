/*
=========================================================================================
=                       CRIME MANAGEMENT SYSTEM                                         =
=========================================================================================*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
//creating a structure to store criminal details
struct criminal_record{
    int criminal_id;
    char name[20];
    int national_id;
    int age;
    float height;

};
//creating a function and declaring it
int main (void); // Main function: Program execution starts here
struct criminal_record criminal;
void add(void);
void add(void) // Function definition: Adds a new criminal record to the system
{ 
    FILE *fp;
    fp = fopen("criminal.dat","ab");//"ab" is "a"for binary or append mode
    //for checking if file opened successfully
    if (fp == NULL)
    {
    printf("Error opening file.\n");
    return;
    }
    else{
    printf("Enter Criminal ID:");
    scanf("%d",&criminal.criminal_id);
    getchar();// consume the leftover newline from the previous scanf
    printf("Enter Criminal Name:");
    fgets(criminal.name, sizeof(criminal.name), stdin);
    criminal.name[strcspn(criminal.name, "\n")] = '\0';//remove the unnecessary newline character created by fgets when there is enough space in the buffer
    printf("Enter Criminal National ID number:");
    scanf("%d",&criminal.national_id);
    printf("Enter Criminal age:");
    scanf("%d",&criminal.age);
    printf("Enter Criminal Height:");
    scanf("%f",&criminal.height);
    fwrite(&criminal , sizeof(criminal), 1, fp );// Saves one criminal record (structure) to "criminal.dat" file in binary mode for permanent storage
    fclose(fp);
        }
}
void display(void);
void display() // Function definition: Displays all stored criminal records
{

}
void search(void);

void search() // Function definition: Searches for a specific criminal record
{

}
void modify(void);

void modify() // Function definition: Updates information in an existing criminal record
{

}

void delete(void);
void delete() // Function definition: Removes a criminal record from the system
{

}

int main(){
    int task;
    while(1){
    printf("\t \t  Crime Record Management System \t \t \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("[1] Add Criminal Records \t \t [2] Display Criminal Records \n");
    printf("[3] Search  Criminal Record \t  \t [4] Modify Criminal Record \n");
    printf("[5] Delete Criminal Record\t  \t [6] Exit \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("Enter the number assigned to functions :");
    scanf("%d",&task);
    printf("-----------------------------------------------------------------------------\n");
    switch(task){
        case 1:{
          add();
          break;  
        }
        case 2:{
            display();
            break;
        }
        case 3:{
            search();
            break;
        }
        case 4:{
            modify();
            break;
        }
        case 5:{
            delete();
            break;
        }
        case 6:{
            printf("you have exited the program\n");
            printf("Exited successfully\n");
            printf("-----------------------------------------------------------------------------\n");
            printf("Thank you\n");
            printf("-----------------------------------------------------------------------------\n");
            return 0;
            
        }
        default:{
            printf("you have inputed the number that is not in the function\n");
            printf("-----------------------------------------------------------------------------\n");
            printf("please enter a number defined in the function\n");
            printf("-----------------------------------------------------------------------------\n");
        }
    }
    printf("-----------------------------------------------------------------------------\n");
}
return 0;
}
