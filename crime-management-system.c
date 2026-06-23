//                      CRIME MANAGEMENT SYSTEM                                       
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
int get_valid_int(char inputs[])
{
    char line[100];
    int value;
    char extra;

    while (1)
    {
        printf("%s", inputs);

        fgets(line, sizeof(line), stdin);

        if (sscanf(line, "%d %c", &value, &extra) == 1)
        {
            return value;
        }

        printf("Please enter only numbers.\n");
    }
}
long long int get_valid_longlongint(char inputs[]);
long long int get_valid_longlongint(char inputs[])
{
   char line[100];
    long long int value;
    char extra;

    while (1)
    {
        printf("%s", inputs);

        fgets(line, sizeof(line), stdin);

        if (sscanf(line, "%lld %c", &value, &extra) == 1)
        {
            return value;
        }

        printf("Please enter only numbers.\n");
    }
}

void get_valid_name(char input[], char result[], int size);
void get_valid_name(char input[], char result[], int size){
    int only_spaces = 1;
    do
{
    printf("%s", input);

    fgets(result, size, stdin);

    result[strcspn(result, "\n")] = '\0';

    // check empty OR spaces-only
    
    for (int i = 0; result[i] != '\0'; i++)
    {
        if (result[i] != ' ')
        {
            only_spaces = 0;
            break;
        }
    }

    if (result[0] == '\0' || only_spaces)
    {
        printf("Please Enter Something Valid\n");
    }

} while (result[0] == '\0' || only_spaces);
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

        // If user just pressed Enter without typing ask again
        if (result[0] == '\0')
            printf("Please Enter Something It Cannot  Be Empty\n");

    } while (result[0] == '\0');
}

int get_valid_int_height(char input[], int min, int max);
int get_valid_int_height(char input[], int min, int max)//function to take  valid height
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
int fix_duplicate(int id, long long int nid);
int fix_duplicate(int id, long long int nid){
    FILE *fp = fopen("criminal.dat", "rb");

    if (fp == NULL)
        return 0;

    struct criminal_record temp;

    while (fread(&temp, sizeof(temp), 1, fp) == 1)
    {
        if (temp.criminal_id == id || temp.national_id == nid)
        {
            fclose(fp);
            return 1; // duplicate found
        }
    }

    fclose(fp);
    return 0; // no duplicate
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
        
    while (1)
{
    criminal.criminal_id = get_valid_int("Enter Criminal ID: ");
    criminal.national_id = get_valid_longlongint("Enter Criminal National ID: ");

    if (fix_duplicate(criminal.criminal_id, criminal.national_id))
    {
        printf("ERROR: Criminal ID or National ID already exists!\n");
        printf("Please enter again.\n");
    }
    else
    {
        break; // valid unique entry
    }
}

    get_valid_name("Enter criminal Name: ",criminal.name ,sizeof(criminal.name) );// function calling to ask user to enter only valid string or character value for name
     
   
    criminal.age = get_valid_int("Enter Criminal Age: ");
    
    printf("Enter Criminal Height in Feet & Inches: \n");
    criminal.feet= get_valid_int_height("Enter  First Feet Only: ", 1,7);
    
    criminal.inches = get_valid_int_height("Now Enter The Inches: ",0,11);
    
    get_valid_string("Enter Crime Commeted Type: ", criminal.crime, sizeof(criminal.crime));

    get_valid_string("Enter Crime Commited Description: ", criminal.description, sizeof(criminal.description));
    
    fwrite(&criminal , sizeof(criminal), 1, fp );// Saves one criminal record (structure) to "criminal.dat" file in binary mode for permanent storage
    fclose(fp);
        }
}
void display(void);
void display()
{
    FILE *fp;

    fp = fopen("criminal.dat", "rb");

    printf("\t\t\t\tCRIMINAL RECORDS\n");

    if (fp == NULL)
    {
        fprintf(stderr, "File not opened\n");
        return;
    }

    printf("=============================================================================================================================================\n");
    printf("%-12s %-20s %-20s %-8s %-10s\n",
           "CRIMINAL ID", "NATIONAL ID", "NAME", "AGE", "HEIGHT");
    printf("=============================================================================================================================================\n");

    int found = 0;

    while (fread(&criminal, sizeof(struct criminal_record), 1, fp) == 1)
    {
        found = 1;

        char height[10];
        sprintf(height, "%d'%d\"", criminal.feet, criminal.inches);

        printf("%-12d %-20lld %-20s %-8d %-10s\n", criminal.criminal_id, criminal.national_id, criminal.name, criminal.age, height);

        printf("---------------------------------------------------------------------------------------------------------------------------------------------");
        printf("\n%-30s %-100s\n", "CRIME TYPE", "DESCRIPTION");
        printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");

        printf("%-30s %-100s\n", criminal.crime, criminal.description);
        printf("=============================================================================================================================================\n");
    }

    if (!found)
    {
        printf("No records found.\n");
    }

    fclose(fp);
}


    void search(void);

    void search() // Function definition: Searches for a specific criminal record
    {
        int ID,nid,input;
        printf("You Have Successfully Pressed '3' to Search Criminal Record\n");
        while(1){
        input=get_valid_int("[1] Criminal Id\t \t[2] National Id\nEnter Valid input:");
    
        
            switch(input)
            {

                case 1:{
                    int id;
                    FILE *fp;
                    fp=fopen("criminal.dat", "rb");
                    id=get_valid_int("Enter Criminal Id:");
                    while(fread(&criminal, sizeof(struct criminal_record), 1,fp)==1) {
                        if(id == criminal.criminal_id){
                            char height[10];
                            printf("=============================================================================================================================================\n");
                            printf("%-12s %-20s %-20s %-8s %-10s\n","CRIMINAL ID", "NATIONAL ID", "NAME", "AGE", "HEIGHT");
                            printf("=============================================================================================================================================\n");
                            sprintf( height, "%d'%d\"", criminal.feet, criminal.inches);//help to store both integer in string variable 
                            printf("%-12d %-20lld %-20s %-8d %-10s\n", criminal.criminal_id, criminal.national_id, criminal.name, criminal.age, height);
                            printf("---------------------------------------------------------------------------------------------------------------------------------------------");
                            printf("\n%-30s %-100s\n", "CRIME TYPE", "DESCRIPTION");
                            printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");

                            printf("%-30s %-100s\n", criminal.crime, criminal.description);
                            printf("=============================================================================================================================================\n");
                            
                            }
                        else{
                            printf("CRIMINAL RECORD NOT FOUND !!");
                        }
                        
                    }
                    fclose(fp);
                    return; 
                    }
        
                case 2:{
                     int nid;
                    FILE *fp;
                    fp=fopen("criminal.dat", "rb");
                    nid = get_valid_int("Enter National Id:");

                    while(fread(&criminal, sizeof(struct criminal_record), 1,fp)==1) {
                        if(criminal.national_id == nid){
                             char height[10];
                            printf("=============================================================================================================================================\n");
                            printf("%-12s %-20s %-20s %-8s %-10s\n","CRIMINAL ID", "NATIONAL ID", "NAME", "AGE", "HEIGHT");
                            printf("=============================================================================================================================================\n");
                            sprintf( height, "%d'%d\"", criminal.feet, criminal.inches);//help to store both integer in string variable 
                            printf("%-12d %-20lld %-20s %-8d %-10s\n", criminal.criminal_id, criminal.national_id, criminal.name, criminal.age, height);
                            printf("---------------------------------------------------------------------------------------------------------------------------------------------");
                            printf("\n%-30s %-100s\n", "CRIME TYPE", "DESCRIPTION");
                            printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");

                            printf("%-30s %-100s\n", criminal.crime, criminal.description);
                            printf("=============================================================================================================================================\n");                 
                                
                            }
                        else {
                            printf("CRIMINAL RECORD NOT FOUND !!\n");
                        }
                    }
                    fclose(fp);

                    return;
                    }

                default: {
                printf("please enter valid input\n");
                    }
            }
    }
}
void modify(void);

void modify() // Function definition: Updates information in an existing criminal record
{
    
        printf("You Have Successfully Pressed '4' to Delete Criminal Record\n");
    
                    int id,found=0;
                    FILE *fp, *fp1;
                    fp=fopen("criminal.dat", "rb");
                    fp1=fopen("temp.dat", "wb");
                    id=get_valid_int("Enter Criminal Id To Change:");
                    while(fread(&criminal, sizeof(struct criminal_record), 1,fp)==1) {
                        if(id == criminal.criminal_id){
                            found =1;
                            printf("YOU have successfully entered updating mode\n");
                            criminal.criminal_id  = get_valid_int("Enter Criminal ID: ");//function calling to ask user to enter only valid interger value for criminal id

                            get_valid_name("Enter criminal Name: ",criminal.name ,sizeof(criminal.name) );// function calling to ask user to enter only valid string or character value for name
                                    
                            criminal.national_id = get_valid_longlongint("Enter Criminal National ID: "); 
                                
                            criminal.age = get_valid_int("Enter Criminal Age: ");
                                    
                            printf("Enter Criminal Height in Feet & Inches: \n");
                            criminal.feet= get_valid_int_height("Enter  First Feet Only: ", 1,7);
                                    
                            criminal.inches =get_valid_int_height("Now Enter The Inches: ",0,11);
                                    
                            get_valid_string("Enter Crime Commeted Type: ", criminal.crime, sizeof(criminal.crime));

                            get_valid_string("Enter Crime Commited Description: ", criminal.description, sizeof(criminal.description));

                            

                            

                            }
                        
                           fwrite(&criminal , sizeof(criminal), 1, fp1 );
                        
                        
                    }
                    fclose(fp);
                    fclose(fp1);
                    if(found != 1){
                        printf("!!RECORD NOT FOUND!!\n");
                    }
                    else{
                        printf("RECORD updated SUCCESSFULLY!!\n");
                        fp=fopen("criminal.dat", "wb");
                        fp1=fopen("temp.dat", "rb");
                        while(fread(&criminal, sizeof(struct criminal_record), 1,fp1)==1){
                            fwrite(&criminal , sizeof(criminal), 1, fp);
                    
                        }
                     fclose(fp);
                     fclose(fp1); 
                     return;
                       
                    }
                     
     
}

void delete(void);
void delete() // Function definition: Removes a criminal record from the system
{
        printf("You Have Successfully Pressed '5' to Delete Criminal Record\n");
    
                    int id,found=0;
                    FILE *fp, *fp1;
                    fp=fopen("criminal.dat", "rb");
                    fp1=fopen("temp.dat", "wb");
                    id=get_valid_int("Enter Criminal Id:");
                    while(fread(&criminal, sizeof(struct criminal_record), 1,fp)==1) {
                        if(id == criminal.criminal_id){
                            found =1;
                            

                            

                            }
                        else{
                           fwrite(&criminal , sizeof(criminal), 1, fp1 );
                        }
                        
                    }
                    fclose(fp);
                    fclose(fp1);
                    if(found != 1){
                        printf("!!RECORD NOT FOUND!!\n");
                    }
                    if(found == 1){
                        printf("RECORD DELETED SUCCESSFULLY!!\n");
                        fp=fopen("criminal.dat", "wb");
                        fp1=fopen("temp.dat", "rb");
                        while(fread(&criminal, sizeof(struct criminal_record), 1,fp1)==1){
                            fwrite(&criminal , sizeof(criminal), 1, fp);
                    
                        }
                     fclose(fp);
                     fclose(fp1); 
                     return;
                       
                    }
                    } 
        
                



    int main(){
        int task;
        while(1){
        printf("=============================================================================================================================================\n");
        printf("\t\t\t\t\t\tCRIME MANAGEMENT SYSTEM \n");
        printf("=============================================================================================================================================\n");
        printf("\t\t[1] Add Criminal Records\t     \t\t\t[2] Display Criminal Records \n");
        printf("\t\t[3] Search  Criminal Record\t  \t\t\t[4] Modify Criminal Record \n");
        printf("\t\t[5] Delete Criminal Record\t   \t\t\t[6] Exit \n");
        printf("=============================================================================================================================================\n");
        task = get_valid_int("Enter the number assigned to functions: ");
        printf("=============================================================================================================================================\n");
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
        
            printf("=============================================================================================================================================\n"); 
                }
        }
return 0;
}
