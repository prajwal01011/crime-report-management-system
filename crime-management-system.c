/*
=========================================================================================
=                       CRIME MANAGEMENT SYSTEM                                         =
=========================================================================================*/
#include<stdio.h>
#include<conio.h>
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
void add(void);
void add() // Function definition: Adds a new criminal record to the system
{ 

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
    top:
    printf("\t \t  Crime Record Management System \t \t \n");
    int task;
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
            printf("_______________________________________________\n");
            printf("Thank you\n");
            printf("_______________________________________________\n");
            break;
            
        }
        default:{
            printf("you have inputed the number that is not in the function\n");
            printf("-----------------------------------------------------------------------------\n");
            printf("please enter a number defined in the function\n");
            printf("-----------------------------------------------------------------------------\n");
             goto top;
        }
    }
    printf("-----------------------------------------------------------------------------\n");
return 0;
}
