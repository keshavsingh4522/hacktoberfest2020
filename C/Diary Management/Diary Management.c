#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

int login();
void addMeet();
void addBlog();
void deleteMeet();
void deleteBlog();
void viewMeet();
void viewBlog();
void editMeet();
void editBlog();
void changePassword();

struct database{
    char time[6];
    char date[15];
    char name[30];
    char place[25];
    char duration[10];
    char note[500];
};

int main(){
    int access = login();
    if(access){
        int ch; char logout[3];
        for(;;){
            system("cls");
            printf("\033[0;34m************************************************************************************\n");
            printf("\t\t\t\tPersonal Diary\n");
            printf("************************************************************************************\033[0m\n");
            printf("\t\t\t\t\033[0;35m[1] Add Meet\n");
            printf("\t\t\t\t[2] Delete Meet\n");
            printf("\t\t\t\t[3] Add Blog\n");
            printf("\t\t\t\t[4] Delete Blog\n");
            printf("\t\t\t\t[5] Edit Meet\n");
            printf("\t\t\t\t[6] Edit Blog\n");
            printf("\t\t\t\t[7] Meet View\n");
            printf("\t\t\t\t[8] Blog View\n");
            printf("\t\t\t\t[9] Change Password\n");
            printf("\t\t\t\t[0] Logout \n");
            printf("\t\t\t\t    Enter choice: \033[0m");
            scanf("%d",&ch);
            switch(ch){
                case 1: addMeet(); break;
                case 2: deleteMeet(); break;
                case 3: addBlog(); break;
                case 4: deleteBlog(); break;
                case 5: editMeet(); break;
                case 6: editBlog(); break;
                case 7: viewMeet(); break;
                case 8: viewBlog(); break;
                case 9: changePassword(); break;
                case 0: printf("\n\n\t\t\t\t\033[0;31m Are you sure? (YES/NO) : \033[0m");
                        scanf("%s",logout);
                        if(strcmp(logout,"YES")==0){
                            printf("\n\t\t\t\t\033[0;32mThanks for choosing my application :)\033[0m\n"); return 0;
                        }else break;
                default: printf("\t\t\t\tYou pressed wrong key!!!\n\n\n");
            }
        }
    }
}

int login(){
    char username[20], confirm[20]={0}, pass[15]={0};
    int i;
    FILE *fp;
    for(int j=0; j<3; j++)
    {
        i=0;
        system("cls");
        printf("\033[0;34m************************************************************************************\n");
        printf("\t\t\t\tLogin\n");
        printf("************************************************************************************\033[0m\n");
        printf("\n\n\t\t\033[0;31mPLEASE NOTE YOU HAVE ONLY THREE CHANCES TO LOGIN\n\t\t\t  ENTER YOUR PASSWORD CAREFULLY\n");
        printf("\n\n\tAttempt(s) Left : \033[0m%d\n",3-j);
        printf("\n\n\t\t\033[0;35mENTER USERNAME : \033[m");
        gets(username);
        printf("\t\t\033[0;35mENTER THE PASSWORD : \033[m");
        do{
            pass[i]=getch();  //STORES VALUE IN getch() AND PRINTS STAR(*)
            if(pass[i]!='\r')
                printf("*");
            i++;
        }while(pass[i-1]!='\r');
        pass[i-1]='\0';

        fp = fopen("login.txt","r");
        if(fp==NULL){
            printf("\n\033[0;31mError with the login file...[MISSING]\033[m\n");
            getch();
            return 0;
        }
        else{
            i=0;
            while(1){
                char c=fgetc(fp);
                if(c==EOF){
                    confirm[i]='\0';
                    break;
                }
                confirm[i]=c;
                i++;
            }
        }

        if(strcmp(pass,confirm)==0){
            printf("\n\n\t\t\t\t\033[0;32mACCESS GRANTED...\n\033[0m");
            printf("\n\t\t\t\t\033[0;33mPress Any key...\033[0m");
            getch();
            return 1;
        }
        else{
            printf("\n\n\t\t\t\t\033[0;31mWRONG PASSWORD... ACCESS DENIED\n");
            printf("\n\n\t\t         Press Any Key To Retry... Attempts Left : \033[0m%d",3-j-1);
            getch();
        }

    }
    printf("\n\n\t\t\033[0;31m::YOUR 3 ATTEMPTS GOT EXHAUSTED::YOU ARE NOT ALLOWED TO ACCESS ANY FILE::\n\n\t\t\t\tPRESS ANY KEY TO GO BACK...\033[0m");
    getch();
    return 0;
}

void addMeet(){
    system("cls");
    FILE *fp ;
    char another = 'Y' ,time[10];
    struct database e ;
    char filename[15];
    int choice;
    printf("\033[0;34m************************************************************************************\n");
    printf("\t\t\t\tWelcome To Meet Menu\n");
    printf("************************************************************************************\033[m\n");
    
        printf("\n\n\t\t\t\033[0;35mENTER DATE OF YOUR RECORD:[yyyy-mm-dd]:\033[0m");
        fflush(stdin);
        gets(filename);

        fp = fopen (filename, "a+" ); //OPENS FILE IN APPEND MODE AND IF IT DOESN'T EXISTS, THEN CREATES FILE
        if(fp==NULL){
            fp=fopen(filename,"w+");
            if(fp==NULL)        {
                printf("\n\t\t\t\t\033[0;31mSYSTEM ERROR...");
                printf("\n\t\t\t\tPRESS ANY KEY TO EXIT\033[0m");
                getch();
                return ;
            }
        }

        while ( another == 'Y'|| another=='y' ){
            choice=0;
            fflush(stdin);          //CLEARS ALL THE PAST INPUTS FROM THE BUFFER TO AVOID MIS FETCHING
            printf ( "\n\t\t\t\t\033[0;35mENTER TIME:[hh:mm]:\033[0m");
            scanf("%s",time);
            rewind(fp);             //SETS FILE POINTER TO BEGIN OF FILE AND CLEARS EOF OR ERRORS PRESENT IN FILE
            while(fread(&e,sizeof(e),1,fp)==1)  //READS DATA FROM GIVEN STREAM USING POINTER
            {
                if(strcmp(e.time,time)==0)
                {
                    printf("\n\t\t\t\t\033[0;31mTHE RECORD ALREADY EXISTS.\033[0m\n");
                    choice=1;
                }
            }

            if(choice==0)
            {   
                    strcpy(e.time,time);
                    printf("\t\t\t\t\033[0;35mENTER NAME: \033[0m");
                    fflush(stdin);
                    gets(e.name);
                    fflush(stdin);
                    printf("\t\t\t\t\033[0;35mENTER PLACE: \033[0m");
                    gets(e.place);
                    fflush(stdin);
                    printf("\t\t\t\t\033[0;35mENTER DURATION: \033[0m");
                    gets(e.duration);
                    fflush(stdin);
                    printf("\t\t\t\t\033[0;35mNOTE: \033[0m");
                    gets(e.note);
                    fwrite( &e,sizeof(e),1,fp); //WRITES DATA FROM ARRAY POINTER TO, BY POINTER TO THE GIVEN STREAM
                    printf("\n\n\t\t\t\t\033[0;32mYOUR RECORD IS ADDED...\033[0m\n");
            }

            printf ( "\n\t\t\t\t\033[0;35mADD ANOTHER RECORD...(Y/N)\033[0m " ) ;
            fflush ( stdin ) ;
            another = getchar(); //TAKES ONLY ONE LETTER AS INPUT AND IGNORES REST

        }
    


    fclose ( fp ) ;
    printf("\n\n\t\t\t\t\033[0;33mPRESS ANY KEY TO EXIT...\033[0m");
    getch();
}

void addBlog(){
    system("cls");
    FILE *fp ;
    char another = 'Y' ,time[10];
    struct database e ;
    char filename[15];
    int choice,flg;
    printf("\033[0;34m************************************************************************************\n");
    printf("\t\t\t\tWelcome To Blog Menu\n");
    printf("************************************************************************************\033[m\n");
    nm: printf("\n\n\t\t\t\033[0;35mENTER BLOG NAME: \033[0m");
    fflush(stdin);
    gets(filename);
    
        fp = fopen (filename, "a+" ); //OPENS FILE IN APPEND MODE AND IF IT DOESN'T EXISTS, THEN CREATES FILE
        if(fp==NULL){
            fp=fopen(filename,"w+");
            if(fp==NULL)        {
                printf("\n\033[0;31mSYSTEM ERROR...");
                printf("\nPRESS ANY KEY TO EXIT\033[0m");
                getch();
                return ;
            }
        }

        do{
        flg=1;
            while(fread(&e,sizeof(e),1,fp)==1){
                if(strcmp(e.date,filename)==0){
                    flg=0;
                    printf("\t\t\033[0;31mRecord Exists... Either make different one or edit earlier one\033[0m\n");
                    goto nm;
                }
            }
        }while(flg==0);

        while ( another == 'Y'|| another=='y' ){
            choice=0;
            
            rewind(fp);             //SETS FILE POINTER TO BEGIN OF FILE AND CLEARS EOF OR ERRORS PRESENT IN FILE

            if(choice==0)
            {   
                strcpy(e.date,filename);
                fflush(stdin);
                printf("\t\t\t\t\t\t\033[0;35mADD TODAY's BLOG...\033[0m\n\n");
                gets(e.note);
                fwrite( &e,sizeof(e),1,fp); //WRITES DATA FROM ARRAY POINTER TO, BY POINTER TO THE GIVEN STREAM
                printf("\n\n\t\t\t\t\033[0;32mYOUR BLOG IS ADDED.....\033[0m\n");
            }

            printf ( "\n\t\t\t\t\033[0;35mADD ANOTHER BLOG.....(Y/N) \033[0m" ) ;
            fflush ( stdin ) ;
            another = getchar(); //TAKES ONLY ONE LETTER AS INPUT AND IGNORES REST

        }
}

void deleteMeet(){
    system("cls");
    FILE *fp,*fptr ;
    struct database file ;
    char filename[15],another = 'Y' ,time[10];;
    int choice,check;

    printf("\033[0;34m************************************************************************************\n");
    printf("\t\t\t\tWelcome To Delete Menu\n");
    printf("************************************************************************************\033[m\n");

    while(another == 'Y')
    {
        printf("\n\n\t\t\t\t\033[0;35mHOW WOULD YOU LIKE TO DELETE");
        printf("\n\n\t\t\t\t[1] DELETE THE WHOLE RECORD");
        printf("\n\t\t\t\t[2] DELETE A PARTICULAR RECORD BY TIME");

        do
        {
            printf("\n\t\t\t\tENTER YOU CHOICE : \033[0m");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
                printf("\n\t\t\t\t\033[0;35mENTER THE DATE OF RECORD TO BE DELETED : [yyyy-mm-dd]: \033[0m");
                fflush(stdin);
                gets(filename);
                fp = fopen (filename, "wb" ) ;
                if ( fp == NULL )
                {
                    printf("\n\t\t\t\t\033[0;31mTHE FILE DOES NOT EXISTS");
                    printf("\n\n\t\t\t\tPRESS ANY KEY TO GO BACK.\033[0m");
                    getch();
                    return ;
                }
                fclose(fp);
                remove(filename);
                printf("\n\n\t\t\t\t\033[0;32m%s DELETED SUCCESFULLY...\033[0m",filename);
                break;

            case 2:
                printf("\n\t\t\t\t\033[0;35mENTER THE DATE OF RECORD:[yyyy-mm-dd]: \033[0m");
                fflush(stdin);
                gets(filename);
                fp = fopen (filename, "rb" ) ;
                if ( fp == NULL )
                {
                    printf("\n\t\t\t\t\033[0;31mTHE FILE DOES NOT EXISTS!");
                    printf("\n\n\t\t\t\tPRESS ANY KEY TO GO BACK.......\033[0m");
                    getch();
                    return ;
                }
                fptr=fopen("temp","wb");
                if(fptr==NULL)
                {
                    printf("\n\t\t\t\t\033[0;31mSYSTEM ERROR");
                    printf("\n\t\t\t\tPRESS ANY KEY TO GO BACK\033[0m");
                    getch();
                    return ;
                }
                printf("\n\n\t\t\t\t\033[0;35mENTER THE TIME OF RECORD TO BE DELETED:[hh:mm]: \033[0m");
                fflush(stdin);
                gets(time);

                while(fread(&file,sizeof(file),1,fp)==1)
                {
                    if(strcmp(file.time,time)!=0)
                        fwrite(&file,sizeof(file),1,fptr);
                }
                fclose(fp);
                fclose(fptr);
                remove(filename);
                rename("temp",filename);
                printf("\n\n\t\t\t\t\033[0;32mSCHEDULE AT %s ON %s DELETED SUCCESFULLY...\033[0m",time,filename);
                break;

            default:
                printf("\n\t\t\t\t\033[0;31mYOU ENTERED WRONG CHOICE\033[0m");
                break;
            }
        }
        while(choice<1||choice>2);

        printf("\n\n\t\t\t\t\033[0;35mDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N): \033[0m");
        fflush(stdin);
        scanf("%c",&another);
    }

    printf("\n\n\t\t\t\t\033[0;33mPRESS ANY KEY TO EXIT...\033[0m");
    getch();
}

void deleteBlog(){
    system("cls");
    FILE *fp,*fptr ;
    struct database file ;
    char filename[15],another = 'Y' ,time[10];;
    int choice,check;

    while(another == 'Y')
    {
        system("cls");
        printf("\033[0;34m************************************************************************************\n");
        printf("\t\t\t\tWelcome To Delete Menu\n");
        printf("************************************************************************************\033[m\n");
        printf("\n\t\t\t\t\033[0;35mENTER THE BLOG TO BE DELETED: \033[0m");
        fflush(stdin);
        gets(filename);
        fp = fopen (filename, "r" ) ;
        if ( fp == NULL )
        {
            printf("\n\t\t\t\t\033[0;31mTHE FILE DOES NOT EXISTS");
            printf("\n\n\t\t\t\tPRESS ANY KEY TO GO BACK.\033[0m");
            getch();
            return ;
        }
        fclose(fp);
        remove(filename);
        printf("\n\n\t\t\t\t\033[0;32m%s DELETED SUCCESFULLY...\033[0m",filename);

        printf("\n\n\t\t\t\t\033[0;35mDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N): \033[0m");
        fflush(stdin);
        scanf("%c",&another);
    }

    printf("\n\n\t\t\t\t\033[0;33mPRESS ANY KEY TO EXIT...\033[0m");
    getch();
}

void viewMeet(){
    FILE *fp;
    system("cls");
    struct database customer;
    char time[6],choice,filename[14];
    int ch,flg=0;
    printf("\033[0;34m************************************************************************************\n");
    printf("\t\t\t\tWelcome To Meet View Menu\n");
    printf("************************************************************************************\033[m\n");

    do{
        printf("\n\t\t\033[0;35mENTER THE DATE OF RECORD TO BE VIEWED:[yyyy-mm-dd]: \033[0m");
        fflush(stdin);
        gets(filename);
        fp = fopen (filename, "rb" );

        if (fp == NULL){
            puts ( "\n\t\t\t\t\033[0;31mTHE RECORD DOES NOT EXIST...\n" ) ;
            printf("\t\t\t\tPRESS ANY KEY TO EXIT...\033[0m");
            getch();
            return ;
        }

        system("cls");
        printf("\n\t\t\t\t\033[0;35mHOW WOULD YOU LIKE TO VIEW:\n");
        printf("\n\t\t\t\t[1] WHOLE MEET'S PLANNED FOR THE DAY.");
        printf("\n\t\t\t\t[2] RECORD OF FIX TIME.");
        printf("\n\t\t\t\t    ENTER YOUR CHOICE: \033[0m");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("\n\t\t\t\t\033[0;36mTHE WHOLE RECORD FOR %s IS: ",filename);
            while ( fread ( &customer, sizeof ( customer ), 1, fp) == 1 )
            {
                printf("\n");
                printf("\n\t\t\t\tTIME: %s",customer.time);
                printf("\n\t\t\t\tMEETING WITH: %s",customer.name);
                printf("\n\t\t\t\tMEETING AT: %s",customer.place);
                printf("\n\t\t\t\tDURATION: %s",customer.duration);
                printf("\n\t\t\t\tNOTE: %s",customer.note);
                printf("\n");
            }
            printf("\033[0m");
            break;

        case 2:
            fflush(stdin);
            printf("\n\t\t\t\t\033[0;35mENTER TIME:[hh:mm]: \033[0m");
            gets(time);
            while ( fread ( &customer, sizeof ( customer ), 1, fp) == 1 )
            {
                if(strcmp(customer.time,time)==0)
                {
                    printf("\n\t\t\t\t\033[0;36mYOUR RECORD IS:");
                    printf("\n\t\t\t\tTIME: %s",customer.time);
                    printf("\n\t\t\t\tMEETING WITH: %s",customer.name);
                    printf("\n\t\t\t\tMEETING AT: %s",customer.place);
                    printf("\n\t\t\t\tDUARATION: %s",customer.duration);
                    printf("\n\t\t\t\tNOTE: %s",customer.note);
                    printf("\033[0m");
                    flg=1;
                }
            }
            if(flg!=1)
                printf("\n\t\t\t\t\033[0;31mNo such meet scheduled\n\033[0m");
            break;

        default:
            printf("\n\t\t\t\t\033[0;31mYOU TYPED SOMETHING ELSE...\033[0m\n");
            break;
        }

        printf("\n\n\t\t\t\t\033[0;35mWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):\033[0m");

        fflush(stdin);

        choice = getchar();
        system("cls");
    
    }while(choice=='Y'||choice=='y');
    
    fclose (fp);
    return ;
}

void editBlog(){
    system("cls");
    FILE *fp ;
    struct database e ;
    char time[6],choice,filename[14];
    int num,count=0;

    do
    {
        printf("\033[0;34m************************************************************************************\n");
        printf("\t\t\t\tWelcome To Editing Menu\n");
        printf("************************************************************************************\033[m\n");
        printf("\n\n\t\t\033[0;35mENTER THE BLOG NAME TO BE EDITED: \033[0m");
        fflush(stdin);
        gets(filename);

        fp = fopen ( filename, "rb+" );

        if ( fp == NULL )
        {
            printf("\n\t\t\t\t\033[0;31mRECORD DOES NOT EXISTS: ");
            printf("\n\t\t\t\tPRESS ANY KEY TO GO BACK\033[0m");
            getch();
            return;
        }

        while ( fread ( &e, sizeof ( e ), 1, fp ) == 1 )
        {
                printf("\n\t\t\t\033[0;36mYOUR OLD RECORD WAS AS:");
                printf("\nFILE NAME: %s\n",e.date);
                printf("\nBLOG: %s\n\n",e.note);

                printf("\033[0m\n\t\033[0;35mENTER NEW BLOG: \033[0m\n");
                fflush(stdin);      
                gets(e.note);
        }
    
        fseek(fp,-sizeof(e),SEEK_CUR);
        fwrite(&e,sizeof(e),1,fp);
        fseek(fp,-sizeof(e),SEEK_CUR);
        fread(&e,sizeof(e),1,fp);
        choice=5;
            
        

        if(choice==5)
        {
            system("cls");
            printf("\n\t\t\t\t\033[0;32mEDITING COMPLETED...\n\n\n");
            printf("\033[0;36m-------------------------------------------------------------------------------------\n");
            printf("\t\t\t\tTHE NEW RECORD IS:\n");
            printf("-------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tFILE NAME: %s\n",e.date);
            printf("\n\t\t\t\tBLOG: %s",e.note);
            fclose(fp);
            printf("\033[0m\n\n\t\t\t\t\033[m\033[0;35mWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)\033[0m");
            scanf("%c",&choice);
            count++;
        }
        
    }
    while(choice=='Y'||choice=='y');

    fclose ( fp );

    if(count==1)
        printf("\n\t\t\t\t\033[0;32m%d FILE IS EDITED...\n\n\n",count);
    else if(count>1)
        printf("\n\t\t\t\t%d FILES ARE EDITED..\n\n\n",count);
    else
        printf("\n\t\t\t\tNO FILES EDITED...\n\n\n");

    printf("\t\t\t\t\033[0m\033[0;33mPRESS ANY KEY TO EXIT...\033[0m");
    getch();
}

void viewBlog(){
    FILE *fp;
    system("cls");
    struct database customer;
    char time[6],choice,filename[14];
    int ch;
    printf("\033[0;34m************************************************************************************\n");
    printf("\t\t\t\tWelcome To Blog View Menu\n");
    printf("************************************************************************************\033[m\n");

    do{
        printf("\n\t\t\033[0;35mENTER THE BLOG NAME TO BE VIEWED: \033[0m");
        fflush(stdin);
        gets(filename);
        fp = fopen (filename, "rb" );

        if (fp == NULL){
            puts ( "\n\t\t\t\t\033[0;31mTHE BLOG DOES NOT EXIST...\n" ) ;
            printf("\t\t\t\tPRESS ANY KEY TO EXIT...\033[0m");
            getch();
            return ;
        }
        
        
            printf("\n\t\t\t\t\033[0;36mTHE BLOG NAME IS: %s",filename);
            while ( fread ( &customer, sizeof ( customer ), 1, fp) == 1 )
            {
                printf("\n");
                printf("\n\t\t\t\tBLOG: %s",customer.note);
                printf("\033[0m\n");
            }

        printf("\n\n\t\t\t\t\033[0;35mWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N): \033[0m");

        fflush(stdin);

        choice = getchar();
        system("cls");
    
    }while(choice=='Y'||choice=='y');
    
    fclose (fp);
    return ;
}

void editMeet(){
    system("cls");
    FILE *fp ;
    struct database e ;
    char time[6],choice,filename[14];
    int num,count=0;

    printf("\033[0;34m************************************************************************************\n");
    printf("\t\t\t\tWelcome To Editing Menu\n");
    printf("************************************************************************************\033[m\n");

    do
    {
        printf("\n\n\t\t\033[0;35mENTER THE RECORD TO BE EDITED:[yyyy:mm:dd]: \033[0m");
        fflush(stdin);
        gets(filename);

        printf("\n\t\t\033[0;35mENTER TIME:[hh:mm]: \033[0m");
        gets(time);

        fp = fopen ( filename, "rb+" );

        if ( fp == NULL )
        {
            printf("\n\t\t\t\t\033[0;31mRECORD DOES NOT EXISTS: ");
            printf("\n\t\t\t\tPRESS ANY KEY TO GO BACK\033[0m");
            getch();
            return;
        }

        while ( fread ( &e, sizeof ( e ), 1, fp ) == 1 )
        {
            if(strcmp(e.time,time)==0)
            {
                printf("\033[0;36m\n\t\t\t\tYOUR OLD RECORD WAS AS:");
                printf("\n\t\t\t\tTIME: %s",e.time);
                printf("\n\t\t\t\tMEETING WITH: %s",e.name);
                printf("\n\t\t\t\tMEETING AT: %s",e.place);
                printf("\n\t\t\t\tDURATION: %s",e.duration);
                printf("\n\t\t\t\tNOTE: %s",e.note);

                printf("\033[0m\n\n\t\t\t\t\033[0;35mWHAT WOULD YOU LIKE TO EDIT..");
                printf("\n\t\t\t\t[1] TIME.");
                printf("\n\t\t\t\t[2] MEETING PERSON.");
                printf("\n\t\t\t\t[3] MEETING PLACE.");
                printf("\n\t\t\t\t[4] DURATION.");
                printf("\n\t\t\t\t[5] NOTE.");
                printf("\n\t\t\t\t[6] WHOLE RECORD.");
                printf("\n\t\t\t\t[7] GO BACK TO MAIN MENU.");
                do
                {
                    printf("\n\n\t\t\t\tENTER YOUR CHOICE: \033[0m");
                    fflush(stdin);
                    scanf("%d",&num);
                    fflush(stdin);

                    switch(num)
                    {
                    case 1:
                        printf("\n\t\t\t\t\033[0;35mENTER THE NEW DATA: \033[0m");
                        printf("\n\t\t\t\t\033[0;35mNEW TIME:[hh:mm]: \033[0m");
                        gets(e.time);
                        break;

                    case 2:
                        printf("\n\t\t\t\t\033[0;35mENTER THE NEW DATA: \033[0m");
                        printf("\n\t\t\t\t\033[0;35mNEW MEETING PERSON: \033[0m");
                        gets(e.name);
                        break;

                    case 3:
                        printf("\n\t\t\t\t\033[0;35mENTER THE NEW DATA: \033[0m");
                        printf("\n\t\t\t\t\033[0;35mNEW MEETING PLACE: \033[0m");
                        gets(e.place);
                        break;

                    case 4:
                        printf("\n\t\t\t\t\033[0;35mENTER THE NEW DATA: \033[0m");
                        printf("\n\t\t\t\t\033[0;35mDURATION: \033[0m");
                        gets(e.duration);
                        break;

                    case 5:
                        printf("\n\t\t\t\t\033[0;35mENTER THE NEW DATA: \033[0m");
                        printf("\n\t\t\t\t\033[0;35mNOTE: \033[0m");
                        gets(e.note);
                        break;

                    case 6:
                        printf("\n\t\t\t\t\033[0;35mENTER THE NEW DATA: \033[0m");
                        printf("\n\t\t\t\t\033[0;35mNEW TIME:[hh:mm]: \033[0m");
                        gets(e.time);
                        printf("\n\t\t\t\t\033[0;35mNEW MEETING PERSON: \033[0m");
                        gets(e.name);
                        printf("\n\t\t\t\t\033[0;35mNEW MEETING PLACE: \033[0m");
                        gets(e.place);
                        printf("\n\t\t\t\t\033[0;35mDURATION: \033[0m");
                        gets(e.duration);
                        printf("\n\t\t\t\t\033[0;35mNOTE: \033[0m");
                        gets(e.note);
                        break;

                    case 7:
                        printf("\n\n\t\t\t\t\033[0;33mPRESS ANY KEY TO GO BACK...\033[0m\n");
                        getch();
                        return ;
                        break;

                    default:
                        printf("\n\n\t\t\t\t\033[0;31mYOU TYPED SOMETHING ELSE...TRY AGAIN\033[0m\n");
                        break;
                    }
                }
                while(num<1||num>8);
                fseek(fp,-sizeof(e),SEEK_CUR);
                fwrite(&e,sizeof(e),1,fp);
                fseek(fp,-sizeof(e),SEEK_CUR);
                fread(&e,sizeof(e),1,fp);
                choice=5;
                break;
            }
        }

        if(choice==5)
        {
            system("cls");
            printf("\n\t\t\t\t\033[0;32mEDITING COMPLETED...\n\n\n\033[0m");
            printf("\033[0;36m-------------------------------------------------------------------------------------\n");
            printf("\t\t\t\tTHE NEW RECORD IS:\n");
            printf("-------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tTIME: %s",e.time);
            printf("\n\t\t\t\tMEETING WITH: %s",e.name);
            printf("\n\t\t\t\tMEETING AT: %s",e.place);
            printf("\n\t\t\t\tDURATION: %s",e.duration);
            printf("\n\t\t\t\tNOTE: %s",e.note);
            fclose(fp);
            printf("\033[0m\n\n\t\t\t\t\033[0m\033[0;35mWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)\033[0m");
            scanf("%c",&choice);
            count++;
        }
        else
        {
            printf("\n\t\t\t\t\033[0;31mTHE RECORD DOES NOT EXIST::\n");
            printf("\n\t\t\t\tWOULD YOU LIKE TO TRY AGAIN...(Y/N)\033[0m");
            scanf("%c",&choice);
        }
    }
    while(choice=='Y'||choice=='y');

    fclose ( fp ) ;

    if(count==1)
        printf("\n\t\t\t\t\033[0;32m%d FILE IS EDITED...\n\n\n",count);
    else if(count>1)
        printf("\n\t\t\t\t%d FILES ARE EDITED..\n\n\n",count);
    else
        printf("\n\t\t\t\tNO FILES EDITED...\n\n\n");

    printf("\t\t\t\t\033[0m\033[0;33mPRESS ANY KEY TO EXIT...\033[0m");
    getch();
}

void changePassword(){
    system("cls");
    char ch, username[20], confirm[20]={0}, pass[15]={0};
    FILE *fp;
    int i,choice=0;
    printf("\033[0;34m************************************************************************************\n");
    printf("\t\t\t\tCHANGE PASSWORD\n");
    printf("************************************************************************************\033[m\n");
    printf("\n\n\t\033[0;31mPLEASE NOTE YOU HAVE TO ENTER PREVIOUS PASSWORD TO ADD NEW PASSWORD\n\t    ENTER YOUR PASSWORD CAREFULLY. YOU HAVE ONLY THREE CHANCES.\033[0m\n");
    printf("\n\n\t\t\t\033[0;33mPress Any Key To Continue...\n\033[0m");
    getch();

    int access=login();
    system("cls");
    if(access){
        do{
            printf("\033[0;34m************************************************************************************\n");
            printf("\t\t\t\tCHANGE PASSWORD\n");
            printf("************************************************************************************\033[m\n");
            fp = fopen("login.txt","w"); //OPENS IN WRITE MODE AND CLEARS ALL PRESENT DATA
            if(fp==NULL){
                printf("\n\033[0;31mError with the login file...[MISSING]\033[0m\n");
                getch();
                return;
            }
            else{
                i=0;
                printf("\t\t\033[0;35mENTER THE NEW PASSWORD : \033[0m");
                do{
                    pass[i]=getch();
                    if(pass[i]!='\r')
                        printf("*");
                    i++;
                }while(pass[i-1]!='\r');
                pass[i-1]='\0';

                i=0;
                printf("\n\n\t\t\033[0;35mENTER THE CONFIRM PASSWORD : \033[0m");
                do{
                    confirm[i]=getch();
                    if(confirm[i]!='\r')
                        printf("*");
                    i++;
                }while(confirm[i-1]!='\r');
                confirm[i-1]='\0';

                if(strcmp(pass,confirm)==0){
                    i=0;
                    while(pass[i]!='\0'){
                        ch=pass[i];
                        putc(ch,fp); //INSERTS INTO THE FILE
                        i++;
                    }

                    putc(EOF,fp);

                    fclose(fp);
                    choice=0;
                }
                else{
                    printf("\n\n\t\t\033[0;31mTHE NEW PASSWORD DOES NOT MATCH\033[0m\n\n");
                    printf("\t\tPress Any Key...\n");
                    getch();
                    choice=1;
                    system("cls");
                }
            }
        }while(choice);
        printf("\n\n\t\t\t\t\033[0;32mPASSWORD CHANGED SUCCESSFULLY...\033[0m\n\n\t\t\t\t\033[0;33mPRESS ANY KEY TO GO BACK...\033[0m\n\n\n");
        getch();
    }
}
