#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

typedef struct create_account
{
    char name[40];
    char nid[18];
    char gender[15];
    char phone_number[20];
    char email[50];
    char occupation[25];
    char password[16];
    char confirm_password[16];
}CA;
typedef struct ticket_processing
{
    int start_location;
    int end_location;
    char date[20];
    char time[10];
    int passenger_number;
    float total_cost;
}TP;

char Main_Menu();
char Admin();
char Passenger();
char Login();
char Update_Notice();
char Update_Cost();
char Sign_Up();
char Sign_In();
char ticket_process(int *s,char x[]);
char buy_ticket(int s,char x[]);
char book_ticket(int s,char x[]);
char payment_method();
float calculation(int,int,int,int);
char View_Notice();
int recurrsion(int x,int y,float z);
int polas_game();
char choice();
int answer(int);
int Payment(char x[]);
void del(char s[]);

void main()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                         Go to Run Window's Property, Select '24' as Front Size & Maximize The Window");
    printf("                                                                     Enter Any Key To Continue...");
    while (1) if (kbhit()) break;
    system("CLS");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                       ********************************************\n");
    printf("                                       Welcome To Metro Rail Transport System(MRTS)\n");
    printf("                                       ********************************************\n");
    printf("                                                == Created by Group IV ==");
    printf("\n\n\n\n");
    int x;
    do
    {
        printf("\n\n\n\n\n\n\n\n\n                                     Enter <1> to go Main Menu or <2> to go to Back: ");
        scanf("%d",&x);
        printf("\n");
        int i;
        char str[] = "                                                                                                    ";
        for(i = 0 ; i <=100 ; i++)
        {
            printf("\r        [%s]%3d%%",str,i);
            str[i] = 'I';
            Sleep(100);
        }
    }
    while(x!=1 && x!=2);
    if(x==1)
    {
        system("CLS");
        Main_Menu();
        system("CLS");
    }
    else
    system("CLS");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                                 Thank You For Using MRTS :D \n\n");
    printf("                                                 Please Enter <E> to Exit !!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    while (1) if (kbhit()) break;
}

char Main_Menu()
{
    system("CLS");
    int input;
    printf("                                                   === Main Menu ===\n\n\n");
    do
    {
        printf("Please Enter <1> For Admin or <2> for Passenger or <3> To go Back: ");
        scanf("%d",&input);
    }
    while(input!=1 && input!=2 && input!=3);
    if(input==1)
    {
        Admin();
    }
    else if(input==2)
    {
        Passenger();
    }
    else
    {
        return 0;
    }

    int m;
    do
    {
        printf("\nPlease Enter <1> To Go To The Main Menu or <2> To Go Back: ");
        scanf("%d",&m);
    }
    while(m!=1 && m!=2);
    {
        if(m==1)
        {
            Main_Menu();
        }
    }
    return 0;
}

char Admin()
{
    int input;
    do
    {
        printf("Please Enter <1> to Login or <2> to return to the Main Menu: ");
        scanf("%d",&input);
    }
    while(input!=1 && input!=2);
    {
        if(input==1)
        {
            system("CLS");
            Login();
        }
        else
            Main_Menu();
    }
}
char Login()
{
    CA admin[3]={{"Salekur Rahaman","1713018642","Male","+8801723348519","salekur19@gmail.com","Student","Salekur","Salekur"},{"Taslima Mazumder","1711403042","Female","+8801771142982","mozumdertaslima99@gmail.com","Student","Taslima","Taslima"},{"Nadin Tasmia","1712836642","Female","+8801700000000","nadintasmia1996@hotmail.com","Student","Exoot12","Exoot12"}};
    printf("                                                     === LOG IN ===                  \n\n");
    char N[20];
    line142:
    printf("Enter your ID: ");
    fflush(stdin);
    gets(N);
    if(strcmp(N,"1713018642")!=0 && strcmp(N,"1711403042")!=0 && strcmp(N,"1712836642")!=0)
    {
        printf("\nYou are not an Admin !\n\n");
        goto line142;
    }
    char ch,p[25];
    int m,i;
    for(i=0; i<3; i++)
    {
        if(strcmp(N,admin[i].nid)==0)
        {
            line135:
                {
                   int charecterPosition=0;
                    printf("Enter your password: ");
                    while(1)
                    {
                        ch=getch();
                        if(ch==13)
                        {
                            break;
                        }
                        else if(ch==8)
                        {
                            if(charecterPosition > 0)
                            {
                                charecterPosition--;
                                p[charecterPosition]='\0';
                                printf("\b \b");
                            }
                        }
                        else if(ch==32 || ch==9)
                        {
                            continue;
                        }
                        else
                        {
                            p[charecterPosition]=ch;
                            charecterPosition++;
                            printf("*");
                        }
                    }
                    p[charecterPosition]='\0';
                    printf("\n");
                m=strcmp(admin[i].password,p);

                if(m!=0)
                {
                    printf("\nYou entered wrong password !\n\n");
                    goto line135;
                }
                system("CLS");
                printf("                                                Welcome %s\n",admin[i].name);
                printf("                                                    ID: %s\n",admin[i].nid);
                printf("                                                     Gender: %s\n\n",admin[i].gender);
                int a;
                do
                {
                    line177:
                    printf("Enter <1> To Update Notice or <2> To Update Cost or <3> To see Passengers information or <4> To Return To Main Menu: ");
                    scanf("%d",&a);
                }
                while(a!=1 && a!=2 && a!=3 && a!=4);
                if(a==1)
                {
                    Update_Notice();
                    goto line177;
                }
                else if(a==2)
                {
                    Update_Cost();
                    goto line177;
                }
                else if(a==3)
                {
                    int q;
                    do
                    {
                        printf("Enter <1> To See Total Passengers or <2> To See Passenger's File or <3> To See Any File: ");
                        scanf("%d",&q);
                    }
                    while(q!=1 && q!=2 && q!=3);
                    if(q==1)
                    {
                        CA x[1000];
                        FILE *p=fopen("USER.txt","r");
                        if(p==NULL)
                        {
                            printf("\nThere is no passenger !\n\n");
                        }
                        else
                        {
                            int i;
                            for(i=0; i<1000; i++)
                            {
                                fscanf(p,"%s",x[i].nid);
                                if(feof(p))
                                {
                                    break;
                                }
                                fscanf(p,"%s",x[i].nid);
                            }
                            fclose(p);
                            printf("\nTotal Passenger is: %d\n\n",i+1);
                        }
                        goto line177;
                    }
                    else if(q==2)
                    {
                        int pi;
                        do
                        {
                            printf("Enter <1> To Passenger's Sign Up File or <2> To See Passenger's Booked File or <3> To See Passenger's Brought File: ");
                            scanf("%d",&pi);
                        }
                        while(pi!=1 && pi!=2 && pi!=3);
                        if(pi==1)
                        {
                            FILE *fp;
                            char filenid[40];
                            printf("Enter Passenger's ID: ");
                            fflush(stdin);
                            scanf("%s",filenid);
                            strcat(filenid,".txt");
                            fp = fopen(filenid,"r");
                            if(fp==NULL)
                            {
                                printf("\nThere is no passenger file by this ID !\n\n");
                            }
                            else
                            {
                                int i;
                                CA s[7];
                                for(i=0; i<7; i++)
                                {
                                    if(i==0){fscanf(fp,"%[^\n]s",s[0].name);}
                                    else if(i==1){fscanf(fp,"%s",s[1].nid);}
                                    else if(i==2){fscanf(fp,"%s",s[2].gender);}
                                    else if(i==3){fscanf(fp,"%s",s[3].phone_number);}
                                    else if(i==4){fscanf(fp,"%s",s[4].email);}
                                    else if(i==5){fscanf(fp,"%s",s[5].occupation);}
                                    else if(i==6){fscanf(fp,"%s",s[6].password);}
                                }
                                printf("\n==From Sign Up Form==\nName: %s\nID: %s\nGender: %s\nPhone: %s\nEmail: %s\nOccupation: %s\nPassword: %s\n\n",s[0].name,s[1].nid,s[2].gender,s[3].phone_number,s[4].email,s[5].occupation,s[6].password);
                                fclose(fp);
                            }
                            goto line177;
                        }

                        else if(pi==2)
                        {
                            FILE *fp;
                            char filenid[40];
                            printf("Enter Passenger's ID: ");
                            fflush(stdin);
                            gets(filenid);
                            strcat(filenid,"-Booked");
                            strcat(filenid,".txt");
                            fp = fopen(filenid,"r");
                            if(fp==NULL)
                            {
                                printf("\nThere is no booked file by this ID !\n\n");
                            }
                            else
                            {
                                CA s[7];
                                int i;
                                for(i=0; i<7; i++)
                                {
                                    fscanf(fp,"%s",s[i].nid);
                                }
                                printf("\n==From Booking Form==\n");
                                printf(" ID: %s\n",s[0].nid);
                                printf(" From: %s     To: %s\n",s[3].nid,s[4].nid);
                                printf(" Date: %s  Time: %s\n",s[1].nid,s[2].nid);
                                printf(" Passenger: %s  Cost: %s\n\n",s[5].nid,s[6].nid);

                                fclose(fp);
                            }
                            goto line177;
                        }

                        else
                        {
                            char Nid[30];
                            CA x[1000];
                            char nam[30];
                            printf("Enter Passenger ID: ");
                            fflush(stdin);
                            gets(nam);
                            strcpy(Nid,nam);
                            strcat(nam,"-DATA");
                            strcat(nam,".txt");
                            FILE *p=fopen(nam,"r");
                            if(p==NULL)
                            {
                                printf("\nThere is no Brought File By This ID !\n\n");
                            }
                            else
                            {
                                strcat(Nid,".txt");
                                FILE *fp=fopen(Nid,"r");
                                CA s[7];
                                for(i=0; i<7; i++)
                                {
                                    if(i==0){fscanf(fp,"%[^\n]s",s[0].name);}
                                    else if(i==1){fscanf(fp,"%s",s[1].nid);}
                                    else if(i==2){fscanf(fp,"%s",s[2].gender);}
                                    else if(i==3){fscanf(fp,"%s",s[3].phone_number);}
                                    else if(i==4){fscanf(fp,"%s",s[4].email);}
                                    else if(i==5){fscanf(fp,"%s",s[5].occupation);}
                                    else if(i==6){fscanf(fp,"%s",s[6].password);}
                                }
                                printf("\n  Name: %s  Gender: %s",s[0].name,s[2].gender);
                                int i;
                                printf("\n\n");
                                printf("  No.      Date           Time     From     To   Passenger    Cost\n");
                                for(i=0; i<1000; i++)
                                {
                                    if(feof(p))
                                    {
                                        break;
                                    }
                                    else if(i%6==0)
                                    {
                                        printf("\n");
                                        printf("  %d.  ",(i/6)+1);
                                    }
                                    fscanf(p,"%s",x[i].nid);
                                    printf("  %s     ",x[i].nid);
                                }
                                fclose(fp);
                                fclose(p);
                                printf("\n\n");
                            }
                            goto line177;
                        }
                    }
                    else
                    {
                        FILE *fp;
                        char filename[40];
                        char c;
                        printf("Enter file name: ");
                        fflush(stdin);
                        scanf("%[^\n]s",filename);
                        //strcat(filename,".txt");
                        fp = fopen(filename,"r");
                        if(fp==NULL)
                        {
                            printf("\nThere is no file by this name !\n\n");
                        }
                        else
                        {
                            printf("\n");
                            c = getc(fp);
                            while (c != EOF)
                            {
                                printf("%c", c);
                                c = getc(fp);
                            }
                            printf("\n");
                            fclose(fp);
                        }
                        goto line177;
                    }
                }
                else
                {
                    Main_Menu();
                }
            }
        }
    }
    return 0;
}

char Update_Notice()
{
    FILE *un;
    char notice[1000];
    un=fopen("notice.txt","w");
    printf("Update a notice: ");
    fflush(stdin);
    gets(notice);
    fprintf(un,"%s",notice);
    fclose(un);
    printf("\nNotice Successfully Updated !\n\n");
    return 0;
}

char Update_Cost()
{
    FILE *uc;
    float cost;
    uc=fopen("cost.txt","w");
    printf("Update Cost: ");
    scanf("%f",&cost);
    fprintf(uc,"%.4f",cost);
    fclose(uc);
    printf("\nCost Successfully Updated !\n\n");
    return 0;
}

char Passenger()
{
    int x;
    do
    {
        printf("Enter <1> to Sign Up or <2> to Sign In or <3> to play brain game <4> to go to main menu: ");
        scanf("%d",&x);
    }
    while(x!=1 && x!=2 && x!=3 && x!=4);
    if(x==1)
    {
        system("CLS");
        Sign_Up();
    }
    else if(x==2)
    {
        system("CLS");
        Sign_In();
    }
    else if(x==3)
    {
        system("CLS");
        polas_game();
    }
    else
    {
        system("CLS");
        Main_Menu();
    }
    return 0;
}

char Sign_Up()
{
    FILE *f,*fp,*file;
    CA C_A;
    printf("                                                    === SIGN UP ===\n");
    printf("Enter Your Full Name: ");
    fflush(stdin);
    gets(C_A.name);
    printf("Enter Your NSU ID: ");
    line357:
    gets(C_A.nid);
    file=fopen("USER.txt","a+");
    fprintf(file,"%s\n",C_A.nid);
    fclose(file);
    char z[20];
    strcpy(z,C_A.nid);
    strcat(z,".txt");
    f=fopen(z,"r");
    if(f!=NULL)
    {
        printf("\nAlready have an account by this ID !\n\n");
        printf("Enter a New ID: ");
        goto line357;
    }

    printf("Enter Your Gender: ");
    fflush(stdin);
    gets(C_A.gender);
    printf("Enter Your Phone Number: ");
    fflush(stdin);
    gets(C_A.phone_number);
    printf("Enter Your E-Mail: ");
    fflush(stdin);
    gets(C_A.email);
    printf("Enter Your Occupation: ");
    fflush(stdin);
    gets(C_A.occupation);
    char ch;
    do
    {
        int charecterPosition = 0;
        printf("Enter a password (Length 1-15): ");
        while(1)
        {
            ch=getch();
            if(ch == 13)
            {
                break;
            }
            else if(ch == 8)
            {
                if(charecterPosition > 0)
                {
                    charecterPosition--;
                    C_A.password[charecterPosition]='\0';
                    printf("\b \b");
                }
            }
            else if(ch == 32 || ch == 9)
            {
                continue;
            }
            else
            {
                C_A.password[charecterPosition]=ch;
                charecterPosition++;
                printf("*");
            }
        }
        C_A.password[charecterPosition]='\0';
        printf("\n");
    }
    while(strlen(C_A.password) <= 0 || strlen(C_A.password) >= 16);

    int m;
    do
    {
        fflush(stdin);
        int charecterPosition=0;
        printf("Re-Enter the password: ");
        while(1)
        {
            ch=getch();
            if(ch==13)
            {
                break;
            }
            else if(ch==8)
            {
                if(charecterPosition > 0)
                {
                    charecterPosition--;
                    C_A.confirm_password[charecterPosition]='\0';
                    printf("\b \b");
                }
            }
            else if(ch==32 || ch==9)
            {
                continue;
            }
            else
            {
                C_A.confirm_password[charecterPosition]=ch;
                charecterPosition++;
                printf("*");
            }
        }
        C_A.confirm_password[charecterPosition]='\0';
        printf("\n");
        m=strcmp(C_A.password,C_A.confirm_password);
    }
    while(m!=0);

    fp=fopen(z,"w");

    fprintf(fp,"%s\n",C_A.name);
    fprintf(fp,"%s\n",C_A.nid);
    fprintf(fp,"%s\n",C_A.gender);
    fprintf(fp,"%s\n",C_A.phone_number);
    fprintf(fp,"%s\n",C_A.email);
    fprintf(fp,"%s\n",C_A.occupation);
    fprintf(fp,"%s\n",C_A.password);
    printf("\nYour data has been saved !\n");
    fclose(f);
    fclose(fp);
    return 0;
}

char Sign_In()      // if(feof(fp))
{
    char x[15],y[15];
    FILE *f,*fp;
    system("CLS");
    printf("                                                    === SIGN IN ===\n\n");
    printf("Enter your NSU ID: ");
    line478:
    fflush(stdin);
    gets(x);
    strcat(x,".txt");
    f=fopen(x,"r");
    if(f==NULL)
    {
        printf("\nThere is no account by this ID !\n\n");
        printf("Enter a Valid ID: ");
        goto line478;
    }
    int i;
    CA s[7];
    for(i=0; i<7; i++)
    {
        if(i==0){fscanf(f,"%[^\n]s",s[0].name);}
        else if(i==1){fscanf(f,"%s",s[1].nid);}
        else if(i==2){fscanf(f,"%s",s[2].gender);}
        else if(i==3){fscanf(f,"%s",s[3].phone_number);}
        else if(i==4){fscanf(f,"%s",s[4].email);}
        else if(i==5){fscanf(f,"%s",s[5].occupation);}
        else if(i==6){fscanf(f,"%s",s[6].password);}
    }

    char ch;
    line491:
    fflush(stdin);
    int charecterPosition = 0;
    printf("Enter your Password: ");
    while(1)
        {
            ch=getch();
            if(ch == 13)      // if user press 'ENTER' button
            {
                break;
            }
            else if(ch == 8)    // if user press 'BACKSPACE' button
            {
                if(charecterPosition > 0)
                {
                    charecterPosition--;
                    y[charecterPosition]='\0';
                    printf("\b \b");
                }
            }
            else if(ch == 32 || ch == 9)  // if user press 'SPACE' OR 'TAB' button
            {
                continue;
            }
            else
            {
                y[charecterPosition]=ch;
                charecterPosition++;
                printf("*");
            }
        }
        y[charecterPosition]='\0';
        printf("\n");
        if(strcmp(y,s[6].password)!=0)             //Reset password
        {
            printf("\nYou Entered Wrong password !\n\n");
            int p;
            printf("If you forgot password press <1> or To Re-enter password press <2>: ");
            scanf("%d",&p);
            if(p==1)
            {
                char e[50];
                line545:
                printf("Enter Your E-Mail: ");
                fflush(stdin);
                gets(e);
                if(strcmp(e,s[4].email)==0)
                {
                    char New[50];
                    char reNew[50];
                    char cha;
                    do
                    {
                        int charecterPosition = 0;
                        printf("Enter a New Password (Length 1-15): ");
                        while(1)
                        {
                            cha=getch();
                            if(cha == 13)
                            {
                                break;
                            }
                            else if(cha == 8)
                            {
                                if(charecterPosition > 0)
                                {
                                    charecterPosition--;
                                    New[charecterPosition]='\0';
                                    printf("\b \b");
                                }
                            }
                            else if(cha == 32 || cha == 9)
                            {
                                continue;
                            }
                            else
                            {
                                New[charecterPosition]=cha;
                                charecterPosition++;
                                printf("*");
                            }
                        }
                        New[charecterPosition]='\0';
                        printf("\n");
                    }
                    while(strlen(New) <= 0 || strlen(New) >= 16);

                    int n;
                    do
                    {
                        fflush(stdin);
                        int charecterPosition=0;
                        printf("Re-Enter new the password: ");
                        while(1)
                        {
                            cha=getch();
                            if(cha==13)
                            {
                                break;
                            }
                            else if(cha==8)
                            {
                                if(charecterPosition > 0)
                                {
                                    charecterPosition--;
                                    reNew[charecterPosition]='\0';
                                    printf("\b \b");
                                }
                            }
                            else if(cha==32 || cha==9)
                            {
                                continue;
                            }
                            else
                            {
                                reNew[charecterPosition]=cha;
                                charecterPosition++;
                                printf("*");
                            }
                        }
                        reNew[charecterPosition]='\0';
                        printf("\n");
                        n=strcmp(New,reNew);
                    }
                    while(n!=0);

                    fp=fopen(x,"w");
                    fprintf(fp,"%s\n",s[0].name);
                    fprintf(fp,"%s\n",s[1].nid);
                    fprintf(fp,"%s\n",s[2].gender);
                    fprintf(fp,"%s\n",s[3].phone_number);
                    fprintf(fp,"%s\n",s[4].email);
                    fprintf(fp,"%s\n",s[5].occupation);
                    fprintf(fp,"%s\n",New);
                    fclose(f);
                    fclose(fp);
                    printf("\nYour Password Successfully Changed !\n\n");
                    printf("Do you want to Sign In ? Press <1> or press <2> to go to Main Menu: ");
                    int a;
                    scanf("%d",&a);
                    if(a==1){Sign_In();}
                    else{Main_Menu();}
            }
            else
            {
                printf("\nEmail didn't match !\n\n");
                goto line545;
            }
        }
        else{goto line491;}
    }
    system("CLS");
    printf("                                               Welcome %s\n",s[0].name);
    printf("                                            Occupation: %s  Gender: %s\n",s[5].occupation,s[2].gender);
    printf("                                      E-Mail: %s  Phone: %s\n\n",s[4].email,s[3].phone_number);
    int o;
    if(strcmp(s[5].occupation,"STUDENT")==0  || strcmp(s[5].occupation,"Student")==0  || strcmp(s[5].occupation,"student")==0 ){o=1;}
    ticket_process(&o,s[1].nid);
    return 0;
}

char ticket_process(int *s,char y[])      // s is used as pointer
{
    int x,d;
    line502:
    printf("Enter <1> To Buy a Ticket or <2> To Book a Ticket or <3> For Payment or <4> To See Notice or <5> to Return Main Menu: ");
    scanf("%d",&x);
    switch(x)
    {
        case 1:
          buy_ticket(*s,y);
          break;
        case 2:
          book_ticket(*s,y);
          break;
        case 3:
            line821:
            printf("Enter <1> To Go To Payment Window or <2> To See Payment Method: ");
            scanf("%d",&d);
            if(d==1){Payment(y);}
            else if(d==2){payment_method();}
            else
            {
                printf("You Entered Wrong Key !");
                goto line821;
            }
            break;
        case 4:
            View_Notice();
            break;
        case 5:
            Main_Menu();
            break;
        default:
            printf("You Entered Wrong Key !\n");
            goto line502;
    }
    return 0;
}

char buy_ticket(int s,char x[])
{
    TP B_T;
    do
    {
        printf("Please Enter Your Start Location Code: \n");
        printf("     <1> for Tongi or <2> for Uttara or <3> for Airport or <4> for Bashundhara or <5> for Mirpur: ");
        scanf("%d",&B_T.start_location);
    }
    while(B_T.start_location!=1 && B_T.start_location!=2 && B_T.start_location!=3 && B_T.start_location!=4 && B_T.start_location!=5);
    line704:
    do
    {
        printf("Please Enter Your End Location Code: \n");
        printf("     <1> for Tongi or <2> for Uttara or <3> for Airport or <4> for Bashundhara or <5> for Mirpur: ");
        scanf("%d",&B_T.end_location);
    }
    while(B_T.end_location!=1 && B_T.end_location!=2 && B_T.end_location!=3 && B_T.end_location!=4 && B_T.end_location!=5);


    if(B_T.start_location!=B_T.end_location)
    {
        printf("Enter Date(format 01.01.1998): ");
        line908:
        fflush(stdin);
        gets(B_T.date);
        if(strlen(B_T.date)!=10)
        {
            printf("Enter Date in 01.01.1998 Format: ");
            goto line908;
        }
        printf("Enter Time(format 19.30): ");
        line917:
        fflush(stdin);
        gets(B_T.time);
        if(strlen(B_T.time)!=5)
           {
               printf("Enter '0' Before %s: ",B_T.time);
               goto line917;
           }
        printf("Enter the number of Passengers: ");
        scanf("%d",&B_T.passenger_number);
        float cost=calculation(B_T.start_location,B_T.end_location,B_T.passenger_number,s);
        printf("\n\nYour total cost is: %.2f Tk\n",cost);
        printf("Please complete your Payment\n");
        printf("Enter the transaction ID: ");
        int T_id;
        scanf("%d",&T_id);

        FILE *fp;
        char y[30];
        strcpy(y,x);
        strcat(y,".txt");
        fp=fopen(y,"r");
        int i;
        CA s[7];
        for(i=0; i<7; i++)
        {
            if(i==0){fscanf(fp,"%[^\n]s",s[0].name);}
            else if(i==1){fscanf(fp,"%s",s[1].nid);}
            else if(i==2){fscanf(fp,"%s",s[2].gender);}
            else if(i==3){fscanf(fp,"%s",s[3].phone_number);}
            else if(i==4){fscanf(fp,"%s",s[4].email);}
            else if(i==5){fscanf(fp,"%s",s[5].occupation);}
            else if(i==6){fscanf(fp,"%s",s[6].password);}
        }

        strcat(x,"-DATA");
        strcat(x,".txt");
        FILE *data=fopen(x,"a");

        fprintf(data,"\n%s ",B_T.date);
        fprintf(data,"%s ",B_T.time);
        fprintf(data,"%d ",B_T.start_location);
        fprintf(data,"%d ",B_T.end_location);
        fprintf(data,"%d ",B_T.passenger_number);
        fprintf(data,"%.2f",cost);
        fclose(data);

        printf("\n        ==Purchess Success==\n");
        printf("Name: %s  Gender: %s\n",s[0].name,s[2].gender);
        printf("Phone: %s  Occupation: %s\n",s[3].phone_number,s[5].occupation);
        printf("Date: %s  Time: %s  Passenger: %d\n",B_T.date,B_T.time,B_T.passenger_number);
        printf("Your Total Cost is: %.2f Tk\n",cost);
        printf("\n             THANK YOU !\n");
    }
    else
    {
        printf("\nSorry ! You select same place & traveled 0 km.\n\n");
        goto line704;
    }
    return 0;
}

float calculation(int x,int y,int z,int s)
{
    FILE *q;
    int r;
    float cost;
    q=fopen("cost.txt","r");
    fscanf(q,"%f",&cost);
    float p;
    if(x==1 && y==2){r=5;}
    else if(x==2 && y==1){r=5;}
    else if(x==1 && y==3){r=12;}
    else if(x==3 && y==1){r=12;}
    else if(x==1 && y==4){r=18;}
    else if(x==4 && y==1){r=18;}
    else if(x==1 && y==5){r=28;}
    else if(x==5 && y==1){r=28;}
    else if(x==2 && y==3){r=6;}
    else if(x==3 && y==2){r=6;}
    else if(x==2 && y==4){r=13;}
    else if(x==4 && y==2){r=13;}
    else if(x==2 && y==5){r=23;}
    else if(x==5 && y==2){r=23;}
    else if(x==3 && y==4){r=7;}
    else if(x==4 && y==3){r=7;}
    else if(x==3 && y==5){r=17;}
    else if(x==5 && y==3){r=17;}
    else if(x==4 && y==5){r=10;}
    else if(x==5 && y==4){r=10;}

    p=recurrsion(r,z,cost);   //using recurrsion
    fclose(q);
    if(s==1){return p/2;}
    else{return p;}
}

char View_Notice()
{
    FILE *vn;
    char notice[1000];
    vn=fopen("notice.txt","r");
    fscanf(vn,"%[^\n]s",notice);
    printf("\nNotice: %s\n\n",notice);
    fclose(vn);
    return 0;
}

char book_ticket(int s,char x[])
{
    TP B_T;
    char y[30];
    strcpy(y,x);
    strcat(y,"-Booked.txt");
    FILE *data;
    data=fopen(y,"r");
    if(data!=NULL)
    {
        printf("\nAlready It has Booked by this ID ! Please Pay First !\n\n");
        printf("Enter <1> To Cancel Previous Booking or Enter <2> To Back: ");
        int c;
        scanf("%d",&c);
        if(c==1)
        {
            printf("\n");
            goto line896;
        }
        else
        {
            goto line1083;
            /*
            Payment(x);
            del(x);
            */
            return 0;
        }
    }
    line896:
    do
    {
        printf("Please Enter Your Start Location Code: \n");
        printf("     <1> for Tongi or <2> for Uttara or <3> for Airport or <4> for Bashundhara or <5> for Mirpur: ");
        scanf("%d",&B_T.start_location);
    }
    while(B_T.start_location!=1 && B_T.start_location!=2 && B_T.start_location!=3 && B_T.start_location!=4 && B_T.start_location!=5);
    location:
    do
    {
        printf("Please Enter Your End Location Code: \n");
        printf("     <1> for Tongi or <2> for Uttara or <3> for Airport or <4> for Bashundhara or <5> for Mirpur: ");
        scanf("%d",&B_T.end_location);
    }
    while(B_T.end_location!=1 && B_T.end_location!=2 && B_T.end_location!=3 && B_T.end_location!=4 && B_T.end_location!=5);

    if(B_T.start_location!=B_T.end_location)
    {
        printf("Enter Date(format 01.01.1998): ");
        line1070:
        fflush(stdin);
        gets(B_T.date);
        if(strlen(B_T.date)!=10)
        {
            printf("Enter Date in 01.01.1998 Format: ");
            goto line1070;
        }
        printf("Enter Time(format 19.30): ");
        line1079:
        fflush(stdin);
        gets(B_T.time);
        if(strlen(B_T.time)!=5)
           {
               printf("Enter '0' Before %s: ",B_T.time);
               goto line1079;
           }
        printf("Enter the number of Passengers: ");
        scanf("%d",&B_T.passenger_number);
        float cost=calculation(B_T.start_location,B_T.end_location,B_T.passenger_number,s);

        FILE *fp;
        char z[30];
        strcpy(z,x);
        strcat(z,".txt");
        fp=fopen(z,"r");
        int i;
        CA s[7];
        for(i=0; i<7; i++)
        {
            if(i==0){fscanf(fp,"%[^\n]s",s[0].name);}
            else if(i==1){fscanf(fp,"%s",s[1].nid);}
            else if(i==2){fscanf(fp,"%s",s[2].gender);}
            else if(i==3){fscanf(fp,"%s",s[3].phone_number);}
            else if(i==4){fscanf(fp,"%s",s[4].email);}
            else if(i==5){fscanf(fp,"%s",s[5].occupation);}
            else if(i==6){fscanf(fp,"%s",s[6].password);}
        }
        data=fopen(y,"w");
        fprintf(data,"%s\n",s[1].nid);
        fprintf(data,"%s\n",B_T.date);
        fprintf(data,"%s\n",B_T.time);
        fprintf(data,"%d\n",B_T.start_location);
        fprintf(data,"%d\n",B_T.end_location);
        fprintf(data,"%d\n",B_T.passenger_number);
        fprintf(data,"%.2f",cost);
        fclose(data);

        printf("\n        ==Booking Success==\n");
        printf("Name: %s  Gender: %s\n",s[0].name,s[2].gender);
        printf("Phone: %s  Occupation: %s\n",s[3].phone_number,s[5].occupation);
        printf("Date: %s  Time: %s  Passenger: %d\n",B_T.date,B_T.time,B_T.passenger_number);
        printf("Your total cost is: %.2f Tk\n\n",cost);
        printf("Thank You For Booking !\n");
        printf("Please Pay Before Travel !\n");
    }
    else
    {
        printf("\nSorry ! You have selected the same places & traveled 0 Km.\n\n");
        goto location;
    }
    line1083:
    return 0;
}

char payment_method()
{
    printf("\n   Payment method:\n");
    printf("        1. BKash - 01723348519\n");
    printf("        2. Rocket - 017233485190\n");
    printf("        3. PayPal - 13234045\n");
    printf("        4. IBBL - SMSA 156\n");
    return 0;
}

int recurrsion(int x,int y,float z)
{
    if(x==0){return 0;}
    else{return (y*z)+recurrsion(x-1,y,z);}
}

int Payment(char x[])
{
    system("CLS");
    printf("                                                      ==Payment==\n");
    char y[50];
    strcpy(y,x);
    strcat(y,"-Booked.txt");
    FILE *p=fopen(y,"r");
    if(p==NULL)
    {
        printf("\n\nThere Is No Booking By This ID !\n");
        return 0;
    }
    int i;
    CA s[7];
    for(i=0; i<7; i++)
    {
        fscanf(p,"%s",s[i].nid);
    }
    printf("\n==Ticket Information==\n");
    printf("\n    Status: Booked !\n");
    printf("ID: %s",s[0].nid);
    printf("  From: %s  To: %s\n",s[3].nid,s[4].nid);
    printf("Date: %s  Time: %s",s[1].nid,s[2].nid);
    printf("\nPassenger: %s  Cost: %s\n\n",s[5].nid,s[6].nid);
    int q;
    printf("Enter <1> If You Confirm To Pay or <2> To Back: ");
    scanf("%d",&q);
    if(q==1)
    {
        char m[50];
        printf("Enter Transaction ID: ");
        fflush(stdin);
        gets(m);
        char z[50];
        strcpy(z,x);
        strcat(z,"-DATA");
        strcat(z,".txt");
        FILE *data=fopen(z,"a");
        fprintf(data,"\n%s ",s[1].nid);
        fprintf(data,"%s ",s[2].nid);
        fprintf(data,"%s ",s[3].nid);
        fprintf(data,"%s ",s[4].nid);
        fprintf(data,"%s ",s[5].nid);
        fprintf(data,"%s",s[6].nid);
        fclose(data);
        fclose(p);
        del(x);
        printf("\nYour Payment Successfully Done !\n");
        printf("         THANK YOU\n");
        return 0;
    }
    else if(q==2){return 0;}
    else
    {
        system("CLS");
        Payment(x);
    }
}

void del(char s[])
{
    strcat(s,"-Booked.txt");
    FILE *fp;int ret;
    fp=fopen(s,"r");
    fclose(fp);
    ret=remove(s);
    if(ret!=0)
    {
        printf("\nYour Data Saved As Brought But Please Cancel Booked File\nWhen You Enter Again Or Restart The Program !\nWe Are Extremely Sorry For Our Technical Error !\n");
    }
}

int polas_game()
{
    printf("                                            ====[ Welcome to Brain Game ]====");
    printf("\n\n                                       ***Please read with attentively & press***\n");
    printf("                                                (We won't store your data)\n\n");
    printf("1. Please think a digit From 1 to 9\n");
    printf("2. Please add 1 if you pressed odd or add 2 if even");
    printf("\n3. Divide your answer by 2\n4. Then multiple your answer by 9");
    printf("\n5. Then add two digit of your answer");
    printf("\n  *Consider that your answer is 29 do it 2+9=11\n");
    choice();
    return 0;
}
char choice()
{
    char x;
    printf("6. Please enter an alphabet from A to Z :");
    fflush(stdin);
    scanf("%c",&x);
    switch(x)
    {
    char A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z;
    char a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    case 'A':case 'z':case 'I':case 'r':case 'Q':case 'j':case 'Y':case 'b':
        printf("7. Minus 8 from your answer\n8. Convert your answer in english alphabet like as  1=A,26=Z");
        answer(1);
        break;
    case 'B':case 'y':case 'J':case 'q':case 'R':case 'i':case 'Z':case 'a':
        printf("7. Minus 7 from your answer\n8. Convert your answer in english alphabet like as  1=A,26=Z");
        answer(2);
        break;
    case 'C':case 'x':case 'K':case 'p':case 'S':case 'h':
        printf("7. Minus 6 from your answer\n8. Convert your answer in english alphabet like as  1=A,26=Z");
        answer(3);
        break;
    case 'D':case 'w':case 'L':case 'o':case 'T':case 'g':
        printf("7. Minus 5 from your answer\n8. Convert your answer in english alphabet like as  1=A,26=Z");
        answer(4);
        break;
    case 'E':case 'v':case 'M':case 'n':case 'U':case 'f':
        printf("7. Minus 4 from your answer\n8. Convert your answer in english alphabet like as  1=A,26=Z");
        answer(5);
        break;
    case 'F':case 'u':case 'N':case 'm':case 'V':case 'e':
        printf("7. Minus 3 from your answer\n8. Convert your answer in english alphabet like as  1=A,26=Z");
        answer(6);
        break;
    case 'G':case 't':case 'O':case 'l':case 'W':case 'd':
        printf("7. Minus 2 from your answer\n8. Convert your answer in english alphabet like as  1=A,26=Z");
        answer(7);
        break;
    case 'H':case 's':case 'P':case 'k':case 'X':case 'c':
        printf("7. Minus 1 from your answer\n8. Convert your answer in english alphabet like as  1=A,26=Z");
        answer(8);
        break;
    }
    return 0;
}

int answer(x)
{
    switch(x){
    float a;
    case 1:
        printf("\n9. Think a word of fruit that contains 5 alphabet by your answer alphabet\n10. Think a word of a food that contains 3 alphabet & which 1st alphabet is 1st word's last alphabet");
        printf("\nPlease enter any number for answer : ");
        scanf("%f",&a);
        printf("\nFirst answer : Apple & Second answer : Egg");
        break;
    case 2:
        printf("\n9. Think a word of country's name that contains 10 alphabet by your answer alphabet\n10. Think a word of animal that contain 5 alphabet & which 1st alphabet is 1st word's last alphabet");
        printf("\nPlease enter any number for answer : ");
        scanf("%f",&a);
        printf("\nFirst answer : Bangladesh & Second answer : Horse");
        break;
    case 3:
        printf("\n9. Think a word of pet that contain 3 alphabet by your answer alphabet\n10. Think a word of a drink food that contain 3 alphabet & which 1st alphabet is 1st word's last alphabet");
        printf("\nPlease enter any number for answer : ");
        scanf("%f",&a);
        printf("\nFirst answer : Cat & Second answer : Tea");
        break;
    case 4:
        printf("\n9. Think a word of animal that contain 3 alphabet by your answer alphabet\n10. Think a word which is used in football game that contain 4 alphabet & which 1st alphabet is 1st word's last alphabet");
        printf("\nPlease enter any number for answer\n");
        scanf("%f",&a);
        printf("\nFirst answer : Dog & Second answer : Goal");
        break;
    case 5:
        printf("\n9. Think a word of food that contain 3 alphabet by your answer alphabet\n10. Think a word which is used in football game that contain 4 alphabet & which 1st alphabet is 1st word's last alphabet");
        printf("\nPlease enter any number for answer : ");
        scanf("%f",&a);
        printf("\nFirst answer : Egg & Second answer : Goal");
        break;
    case 6:
        printf("\n9. Think a word of social media that contain 8 alphabet by your answer alphabet\n10. Think a word which is used to unlock a lock that contain 3 alphabet & which 1st alphabet is 1st word's last alphabet");
        printf("\nPlease enter any number for answer : ");
        scanf("%f",&a);
        printf("\nFirst answer : Facebook & Second answer : Key");
        break;
    case 7:
        printf("\n9. Think a word which use in football game that contain 4 alphabet by your answer alphabet\n10. Think a word of a electric device that contain 6 alphabet & which 1st alphabet is 1st word's last alphabet");
        printf("\nPlease enter any number for answer : ");
        scanf("%f",&a);
        printf("\nFirst answer : Goal & Second answer : Laptop");
        break;
    case 8:
        printf("\n9. Think a word which need every married women that contain 7 alphabet by your answer alphabet\n10. Think a word of a animal that contain 3 alphabet & which 1st alphabet is 1st word's last alphabet");
        printf("\nPlease enter any number for answer : ");
        scanf("%f",&a);
        printf("\nFirst answer : Husband & Second answer : Dog");
        break;
    }
    printf("\n\nThank you for participant\nIt's created by Polas\n\n");
    return 0;
}
