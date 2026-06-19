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
    long long int national_id;
    int age;
    int feet;
    int inches;
    char crime[50];
    char description[100];

};
//creating a function and declaring it
struct criminal_record criminal;
int get_valid_int(char inputs[]);
int get_valid_int(char inputs[])//function definition:help to get only integer value
{
    int value;
    int input_is_valid;

    do
    {
        // Ask the user for input
        printf("%s", inputs);

        // Try to read a number (scanf returns 1 if it succeeded)
        input_is_valid = scanf("%d", &value) == 1;

        // If it didn't work, let the user know
        if (!input_is_valid)
            printf("Please Enter only numbers\n");

        // Clean up whatever is left in the input line
        while (getchar() != '\n');

    } while (!input_is_valid);

    // We got a good number, send it back
    return value;
}
long long int get_valid_longlongint(char inputs[]);
long long int get_valid_longlongint(char inputs[])
{
    long long int value;
    int input_is_valid;

    do
    {
        // Ask the user for input
        printf("%s", inputs);

        // %lld is used for long long int instead of %d
        input_is_valid = scanf("%lld", &value) == 1;

        if (!input_is_valid)
            printf("Please Enter only numbers\n");

        while (getchar() != '\n');

    } while (!input_is_valid);

    return value;
}

void get_valid_string(char input[], char result[], int size);
void get_valid_string(char input[], char result[], int size)//function definition:helps to get string or char value and does let user to put it empty

{
    do
    {
        // Ask the user for input
        printf("%s", input);

        // Read the whole line including spaces
        fgets(result, size, stdin);

        // Remove the newline at the end that fgets leaves behind
        result[strcspn(result, "\n")] = '\0';

        // If user just pressed Enter without typing, ask again
        if (result[0] == '\0')
            printf("Please Enter Something It Cannot  Be Empty\n");

    } while (result[0] == '\0');
}

int get_valid_int_range(char input[], int min, int max);
int get_valid_int_range(char input[], int min, int max)//function to take  valid height
{
    int value;
    int input_is_valid;

    do
    {
        // Ask the user for input
        printf("%s", input);

        // Try to read a number
        input_is_valid = scanf("%d", &value) == 1;

        // Check if number is within range
        if (!input_is_valid)
            printf("Please put only numbers Try\n");
        else if (value < min || value > max)
        {
            printf("Please enter a number between %d and %d\n", min, max);
            input_is_valid = 0;  // force loop to repeat
        }

        while (getchar() != '\n');

    } while (!input_is_valid);

    return value;
}
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
        
    criminal.criminal_id    = get_valid_int("Enter Criminal ID: ");//function calling to ask user to enter only valid interger value for criminal id

    get_valid_string("Enter criminal Name: ",criminal.name ,sizeof(criminal.name) );// function calling to ask user to enter only valid string or character value for name
    
    criminal.national_id = get_valid_longlongint("Enter Criminal National ID: "); 
   
    criminal.age = get_valid_int("Enter Criminal Age: ");
    
    printf("Enter Criminal Height in Feet & Inches: \n");
    criminal.feet = get_valid_int("Enter  First Feet Only: ");
    
    criminal.inches = get_valid_int("Now Enter The Inches: ");
    
    get_valid_string("Enter Crime Commeted Type: ", criminal.crime, sizeof(criminal.crime));

    get_valid_string("Enter Crime Commited Description: ", criminal.description, sizeof(criminal.description));
    
    fwrite(&criminal , sizeof(criminal), 1, fp );// Saves one criminal record (structure) to "criminal.dat" file in binary mode for permanent storage
    fclose(fp);
        }
}
void display(void);
void display() // Function definition: Displays all stored criminal records
{
    FILE *fp;
    fp =fopen("criminal.dat","rb");//rb is read mode for .dat or binary data
    printf("-----------------------------CRIMINAL RECORDS--------------------------------\n\n");
    if(fp==NULL){
        fprintf(stderr,"file not opened");//stderr help to show error in a console without giving problem to program output
        return; 
    }
    else{
        char height[10];//stores feet and inches in string to take a specific character
        sprintf(height, "%d'%d\"", criminal.feet, criminal.inches);//help to store both integer in string variable
        printf("=============================================================================================================================================\n"); 
        printf("%-12s %-15s %-20s %-8s %-10s %-20s %-50s\n","CRIMINAL ID", "NATIONAL ID", "NAME", "AGE", "HEIGHT", "CRIME TYPE", "DESCRIPTION");
        printf("=============================================================================================================================================\n"); 
        while(fread(&criminal, sizeof(struct criminal_record), 1,fp)==1) {
        printf("%-12d %-15lld %-20s %-8d %-10s %-20s %-50s\n",criminal.criminal_id,criminal.national_id,criminal.name,criminal.age,height,criminal.crime,criminal.description);  //(-) is left align and (12)is the charater reserved
        printf("=============================================================================================================================================\n"); 
    }
        fclose(fp);
    }

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
    task = get_valid_int("Enter the number assigned to functions: ");
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
            printf("=============================================================================================================================================\n"); 
            printf("Thank you\n");
            printf("=============================================================================================================================================\n"); 
            return 0;
            
        }
        default:{
            printf("you have inputed the number that is not in the function\n");
            printf("=============================================================================================================================================\n"); 
            printf("please enter a number defined in the function\n");
            printf("=============================================================================================================================================\n"); 
        }
    }
    printf("=============================================================================================================================================\n"); 
}
return 0;
}
