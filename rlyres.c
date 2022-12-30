#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "rlyres.h"

void gotoxy(int x,int y)
{
    COORD co;
    co.X=x;
    co.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),co);
}
int enterchoice()
{
    int ch, i;
    system("cls");
    gotoxy(50,1);

    system("color 6");
    printf("Railway Reservation\n");
     for(i=0;i<120;i++)
        printf("-");

    system("color 06");
    printf("Select an option\n");
    printf("1- View Trains\n");
    printf("2- Book Tickets\n");
    printf("3- View Tickets\n");
    printf("4- Search Ticket No\n");
    printf("5- View All Bookings\n");
    printf("6- View Trains Booking\n");
    printf("7- Cancel Ticket\n");
    printf("8- Cancel Train\n");
    printf("9- Quit\n");
    printf("\nEnter choice:");
    scanf("%d",&ch);
    return ch;
}
void addd_trains()
{
    FILE *fp=NULL;
    Train t1 = {"06527","BPL","NDLS",2605,1700};
    Train t2 = {"02309","PNBE","NDLS",3305,2995};
    Train t3 = {"02914","PNBE","BDTS",4460,2625};
    Train t4 = {"01062","DBG","ET",3505,2325};
    Train t5 = {"02270","HBJ","MAS",4200,2725};
    fp=fopen("Train.txt","w");
    fprintf(fp,"%s %s %s %d %d\n",t1.train_no, t1.from, t1.to, t1.fac_fare, t1.sac_fare);
    fprintf(fp,"%s %s %s %d %d\n",t2.train_no, t2.from, t2.to, t2.fac_fare, t2.sac_fare);
    fprintf(fp,"%s %s %s %d %d\n",t3.train_no, t3.from, t3.to, t3.fac_fare, t3.sac_fare);
    fprintf(fp,"%s %s %s %d %d\n",t4.train_no, t4.from, t4.to, t4.fac_fare, t4.sac_fare);
    fprintf(fp,"%s %s %s %d %d\n",t5.train_no, t5.from, t5.to, t5.fac_fare, t5.sac_fare);

    fclose(fp);
}

/*-----View Train----*/
void view_trains()
{
    int i;
    FILE *fp=NULL;
    fp = fopen("Train.txt","r");
    Train t1, t2, t3, t4, t5;
    //printf
    fscanf(fp,"%s %s %s %d %d",&t1.train_no,&t1.from,&t1.to,&t1.fac_fare,&t1.sac_fare);
    fscanf(fp,"%s %s %s %d %d",&t2.train_no,&t2.from,&t2.to,&t2.fac_fare,&t2.sac_fare);
    fscanf(fp,"%s %s %s %d %d",&t3.train_no,&t3.from,&t3.to,&t3.fac_fare,&t3.sac_fare);
    fscanf(fp,"%s %s %s %d %d",&t4.train_no,&t4.from,&t4.to,&t4.fac_fare,&t4.sac_fare);
    fscanf(fp,"%s %s %s %d %d",&t5.train_no,&t5.from,&t5.to,&t5.fac_fare,&t5.sac_fare);
    //fread(&t1, sizeof(t1),1,fp);
    system("cls");
    gotoxy(1,2);
    printf("Train No \t\tFrom \t\t To \t\t First AC Fare \t\t Second AC Fare");
    printf("\n");
    for(i=0;i<120;i++)
        printf("-");
    printf("\t%s \t\t\t%s \t\t%s \t\t\t%d \t\t\t%d\n",t1.train_no,t1.from,t1.to,t1.fac_fare,t1.sac_fare);
    printf("%s \t\t\t%s \t\t%s \t\t\t%d \t\t\t%d\n",t2.train_no,t2.from,t2.to,t2.fac_fare,t2.sac_fare);
    printf("%s \t\t\t%s \t\t%s \t\t\t%d \t\t\t%d\n",t3.train_no,t3.from,t3.to,t3.fac_fare,t3.sac_fare);
    printf("%s \t\t\t%s \t\t%s \t\t\t%d \t\t\t%d\n",t4.train_no,t4.from,t4.to,t4.fac_fare,t4.sac_fare);
    printf("%s \t\t\t%s \t\t%s \t\t\t%d \t\t\t%d\n",t5.train_no,t5.from,t5.to,t5.fac_fare,t5.sac_fare);
    fclose(fp);
    system("color 00");
    printf("\n\n\n\n\n\nPress any key to go back to the main screen");
    fclose(fp);
    getch();
}
/*----End of View Trains----*/

/*---- Book Train Ticket----*/
int book_ticket(passenger pm)
{
    int i;
    system("cls");
    gotoxy(100,1);
    system("color 06");
    printf("Press 0 to exit");
    gotoxy(1,1);
    system("color 06");
    printf("Enter passenger name: ");
    fflush(stdin);
    fgets(pm.p_name,30,stdin);
    char* pos;
    pos=strchr(pm.p_name,'\n');
    *pos='\0';
    if(strcmp(pm.p_name,"0")==0)
    {
        gotoxy(1,30);
        system("color 06");
        printf("Reservation Cancelled!");
        system("color 06");
        return NULL;
    }
    gotoxy(1,2);
    printf("Enter gender(M/F): ");
    while(1)
    {
        fflush(stdin);
        scanf("%c",&pm.gender);
        if(pm.gender=='M' || pm.gender=='F')
        {
            break;
        }
        else if(pm.gender=='0')
        {
            gotoxy(1,30);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,30);
            system("color red");
            printf("Reservation Cancelled.");
            system("color 06");
            return NULL;
        }
        else
        {
            gotoxy(1,30);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,30);
            system("color 06");
            printf("Error! Gender should be M or F(in uppercase)");
            system("color 06");
            gotoxy(20,2);
            printf(" \b");
        }
    }
    gotoxy(1,30);
    printf("\t\t\t\t\t\t\t\t\t\t");
    gotoxy(1,3);
    printf("Enter train number: ");
    while(1)
    {
        fflush(stdin);
        fgets(pm.train_no,20,stdin);
        char* pos;
        pos=strchr(pm.train_no,'\n');
        *pos='\0';
        if(strcmp(pm.train_no,"0")==0)
        {
            gotoxy(1,30);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,30);
            system("color 06");
            printf("Reservation Cancelled.");
            system("color 06");
            return NULL;
        }
        if(check_train_no(pm.train_no))
        {
            break;
        }
        else
        {
            gotoxy(1,30);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,30);
            system("color 06");
            printf("Error! Invalid Train No");
            system("color 06");
            gotoxy(34,3);
            printf("\b\b\b\b\b\b\b\b\b\b\b\b\b");
        }
    }
    gotoxy(1,30);
    printf("\t\t\t\t\t\t\t\t\t\t");
    gotoxy(1,4);
    printf("Enter traveling class(First AC-F,Second AC-S): ");
    while(1)
    {
        fflush(stdin);
        scanf("%c",&pm.p_class);
        if(pm.p_class=='S' || pm.p_class=='F')
        {
            break;
        }
        else if(pm.p_class=='0')
        {
            gotoxy(1,30);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,30);
            system("color 06");
            printf("Reservation Cancelled.");
            system("color 06");
            return NULL;
        }
        else
        {
            gotoxy(1,30);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,30);
            system("color 06");
            printf("Error! Traveling Class should be F or S(in uppercase)");
            system("color 06");
            gotoxy(48,4);
            printf(" \b");
        }
    }
    gotoxy(1,30);
    printf("\t\t\t\t\t\t\t\t\t\t");
    gotoxy(1,5);
    printf("Enter address: ");
    fflush(stdin);
    fgets(pm.address,30,stdin);
    pos=strchr(pm.address,'\n');
    *pos='\0';
    if(strcmp(pm.address,"0")==0)
    {
        gotoxy(1,30);
        printf("\t\t\t\t\t\t\t\t\t\t");
        gotoxy(1,30);
        system("color 06");
        printf("Reservation Cancelled.");
        system("color 06");
        return NULL;
    }
    gotoxy(1,6);
    printf("Enter age: ");
    while(1)
    {
        fflush(stdin);
        scanf("%d",&pm.age);
        if(pm.age==0)
        {
            gotoxy(1,30);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,30);
            system("color 06");
            printf("Reservation Cancelled.");
            system("color 06");
            return NULL;
        }
        else if(pm.age<0)
        {
            gotoxy(1,30);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,30);
            system("color 06");
            printf("Error! Age should be positive");
            system("color 06");
            gotoxy(12,6);
            printf("     \b\b\b\b\b");
        }
        else
        {
            break;
        }
    }
    gotoxy(1,30);
    printf("\t\t\t\t\t\t\t\t\t\t");
    gotoxy(1,7);
    printf("Enter Mobile No: ");
    while(1)
    {
        fflush(stdin);
        fgets(pm.mob_no,12,stdin);
        char* pos;
        pos=strchr(pm.mob_no,'\n');
        if(pos!=NULL)
        *pos='\0';
        if(strcmp(pm.mob_no,"0")==0)
        {
            gotoxy(1,30);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,30);
            system("color 06");
            printf("Reservation Cancelled.");
            system("color 10");
            return NULL;
        }
        if(check_mob_no(pm.mob_no))
        {
            break;
        }
        else
        {
            gotoxy(1,30);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,30);
            system("color 06");
            printf("Error! Invalid Mobile No");
            system("color 10");
            gotoxy(18,7);
            printf("            \b\b\b\b\b\b\b\b\b\b\b\b");
        }
    }
    gotoxy(1,30);
    printf("\t\t\t\t\t\t\t\t\t\t");
    gotoxy(1,8);
        if(get_booked_ticket_count(pm.train_no,pm.p_class)==30)
        {
            gotoxy(1,20);
            system("color 06");
            printf("All seats full in train no %s in %c class!",pm.train_no,pm.p_class);
            return -1;
        }
        pm.ticket_no=last_ticket_no()+1;
        FILE *fp=fopen("allbookings.txt","ab");
        if(fp==NULL)
        {
            system("color 06");
            printf("Sorry! File cannot be opened");
            return -1;
        }
        int x;
        x=fwrite(&pm,sizeof(passenger),1,fp);
        //x=fprintf(fp,"%s %c %s %c %s %s %d %d\n",pm.p_name, pm.gender, pm.train_no, pm.p_class, pm.address, pm.mob_no, pm.ticket_no, pm.age);
        fclose(fp);
        if (x)
            return 1;
        else
            return 0;
}


int check_mob_no(char* mob_no)
{
    if(strlen(mob_no)!=10)
    {
        return 0;
    }
    while(*mob_no!='\0')
    {
        if(isdigit(*mob_no)==0)
        {
            return 0;
        }
        mob_no++;
    }
    return 1;
}

int check_train_no(char* tno)
{
    FILE *fp;
    fp=fopen("Train.txt","rb");
    Train alltrains;
   // while(fread(&alltrains,sizeof(Train),1,fp)==1)
   while(fscanf("%s %s %s %d %d",alltrains.train_no, alltrains.from, alltrains.to, alltrains.fac_fare,alltrains.sac_fare)!=EOF)
    {
        //puts(alltrains.train_no);
        //printf("%s",alltrains.train_no);
        if(strcmp(alltrains.train_no,tno)==0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
/*----End Book Train Ticket----*/


int get_booked_ticket_count(char* train_no ,char t_class)
{
    FILE *fp=fopen("allbookings.txt","rb");
    if(fp==NULL)
    {
        return 0;
    }
    passenger pr;
    int count=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0 && pr.p_class==t_class)
            ++count;
    }
    fclose(fp);
    return count;
}

int last_ticket_no()
{
    FILE *fp=fopen("allbookings.txt","rb");
    if(fp==NULL)
    {
        return 0;
    }
    passenger pr;
    fseek(fp,-1*sizeof(passenger),SEEK_END);
    fread(&pr,sizeof(passenger),1,fp);
    fclose(fp);
    //printf("%d", pr.ticket_no);
    return pr.ticket_no;
}

/*---- Get Ticket Number----*/
int* get_ticket_no(char* mob)
{
    FILE *fp;
    fp = fopen("Passenger.txt","r");
    passenger pm;
    passenger ps[5];
    int count=0;
    while(fscanf("%s %c %d %s %c %d %s %s ",pm.p_name,pm.gender,pm.age,pm.train_no,pm.p_class,pm.ticket_no,pm.address,pm.mob_no)!=EOF)
    {
        if(strcmp(mob,pm.mob_no))
        {
            //ps[count] = {pm.p_name, pm.gender, pm.train_no, pm.p_class, pm.address, pm.mob_no, pm.age, pm.ticketno};
            /*ps[count].p_name=pm.p_name;
            ps[count].gender=pm.gender;
            ps[count].train_no=pm.train_no;
            ps[count].p_class=pm.p_class;
            ps[count].address=pm.address;
            ps[count].mob_no=pm.mob_no;
            ps[count].age=pm.age;
            ps[count].ticketno=pm.ticketno;*/
            count++;
        }
    }
    if(count == 0)
    {
        printf("Sorry! No record found");
    }
    else
    {
        printf("Passenger name \tGender \tAge \tTrain no \tClass \tTicket no \tAddress \tMobile no");
        for(count;count>=0;count--)
            printf("%s %c %d %s %c %d %s %s ",pm.p_name,pm.gender,pm.age,pm.train_no,pm.p_class,pm.ticket_no,pm.address,pm.mob_no);
    }
}
/*----End of Get Ticket Number ----*/

/*----View Ticket ----*/
/*void view_ticket()
{

}*/
/*----End of View Ticket ----*/

/*----View all Bookings ----*/
void view_all_bookings()
{
    system("cls");
    FILE *fp=fopen("allbookings.txt","rb");
    if(fp==NULL)
    {
        gotoxy(1,4);
        system("color LIGHTRED");
        printf("Error! No bookings performed yet.");
        getch();
        system ("color 10");
        return;
    }
    gotoxy(1,1);
    printf("TICKET NO");
    gotoxy(14,1);
    printf("TRAIN NO");
    gotoxy(26,1);
    printf("PASSENGER NAME");
    gotoxy(45,1);
    printf("GENDER");
    gotoxy(55,1);
    printf("ADDRESS");
    gotoxy(75,1);
    printf("MOBILE NO");
    gotoxy(90,1);
    printf("AGE");
    gotoxy(100,1);
    printf("TRAVELLING CLASS\n");
    int i;
    for(i=1;i<=120;i++)
        printf("-");
    passenger pr;
    i=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        gotoxy(1,i);
        printf("%d",pr.ticket_no);
        gotoxy(14,i);
        printf("%s",pr.train_no);
        gotoxy(26,i);
        printf("%s",pr.p_name);
        gotoxy(45,i);
        printf("%c",pr.gender);
        gotoxy(55,i);
        printf("%s",pr.address);
        gotoxy(75,i);
        printf("%s",pr.mob_no);
        gotoxy(90,i);
        printf("%d",pr.age);
        gotoxy(100,i);
        printf("%c\n",pr.p_class);
        i++;
    }
    system("color 00");
    printf("\n\n\n\n\n\nPress any key to go back to the main screen");
    fclose(fp);
    getch();
}
/*----End of View all Bookings ----*/



/*----Get ticket number from user ----*/
int get_user_ticket_no()
{
    system("cls");
    int ticket_no;
    gotoxy(100,1);
    system("color 06");
    printf("Press 0 to exit");
    gotoxy(1,1);
    system("color 06");
    printf("Enter ticket number: ");
    while(1)
    {
        scanf("%d",&ticket_no);
        if(ticket_no==0)
        {
            gotoxy(1,25);
            system("color 06");
            printf("Cancelling Input..!");
            return 0;
        }
        if(ticket_no<0)
        {
            gotoxy(1,30);
            system("color C");
            printf("Error! Ticket number should be positive");
            system("color 10");
            gotoxy(22,1);
            printf("   \b\b\b");
        }
        else
        {
            break;
        }
    }
    return ticket_no;
}
/*----End of Get ticket number from user  ----*/


/*----View all tickets  ----*/
void view_all_tickets(char* mob_no,int* ticket_no)
{
    if(ticket_no==NULL)
    {
        system("color 06");
        printf("Sorry! No tickets booked against mobile no %s",mob_no);
        return;
    }
    system("cls");
    printf("Following are tickets booked for mobile no %s",mob_no);
    int i;
    printf("\n\nTICKET NO\n---------");
    for(i=0;*(ticket_no+i)!=-1;i++)
        printf("\n%d",*(ticket_no+i));
}
/*----End of View all tickets ----*/

/*----View Bookings ----*/
void view_ticket(int tno)
{
    FILE *fp=fopen("allbookings.txt","rb");
    if(fp==NULL)
    {
        system("color 4");;
        printf("\nNo bookings done yet");
        return;
    }
    passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(pr.ticket_no==tno)
        {
            printf("Ticket no: %d",pr.ticket_no);
            printf("\nPassenger name: %s",pr.p_name);
            printf("\nTrain no: %s",pr.train_no);
            printf("\nGender: %c",pr.gender);
            printf("\nAddress: %s",pr.address);
            printf("\nMobile no: %s",pr.mob_no);
            printf("\nAge: %d",pr.age);
            printf("\nTravelling class: %c\n\n",pr.p_class);
            found=1;
            break;
        }
    }
    fclose(fp);
    if(!found)
    {
        gotoxy(1,1);
        system("color 4");
        printf("No details of ticket no %d found",tno);
        system("color 10");
    }
    system("color 06");
    printf("\n\n\n\nPress any key to go back to the main screen");
    fclose(fp);
    getch();
}
/*----End of View Bookings ----*/


/*----Accept mobile number ----*/
char* accept_mob_no()
{
    static char mob_no[12];
    char *pos;
    gotoxy(100,1);
    system("color 06");
    printf("Press 0 to exit");
    gotoxy(1,1);
    system("color 06");
    printf("Enter mobile number: ");
    while(1)
    {
        fflush(stdin);
        fgets(mob_no,12,stdin);
        pos=strchr(mob_no,'\n');
        *pos='\0';
        if(strcmp(mob_no,"0")==0)
        {
            gotoxy(1,25);
            system("color 06");
            printf("Cancelling Input..!");
            system("color 06");
            return NULL;
        }
        if(check_mob_no(mob_no))
        {
            break;
        }
        else
        {
            gotoxy(1,30);
            system("color 06");
            printf("Error! Invalid Mobile No");
            system("color 06");
            gotoxy(22,1);
            printf("\b\b\b\b\b\b\b\b\b\b\b\b");
        }
    }
    return mob_no;
}
/*----End of Accept mobile number ----*/



/*----View Bookings ----*/
void view_bookings(char* tb)
{
    FILE *fp=fopen("allbookings.txt","rb");
    if(fp==NULL)
    {
        system("cls");
        system("color 06");
        printf("\nNo bookings done yet");
        system("color 06");
        printf("\n Press any key to go back to the main menu");
        getch();
        return;
    }
    gotoxy(1,1);
    printf("TICKET NO");
    gotoxy(14,1);
    printf("TRAIN NO");
    gotoxy(26,1);
    printf("PASSENGER NAME");
    gotoxy(45,1);
    printf("GENDER");
    gotoxy(55,1);
    printf("ADDRESS");
    gotoxy(75,1);
    printf("MOBILE NO");
    gotoxy(90,1);
    printf("AGE");
    gotoxy(100,1);
    printf("TRAVELLING CLASS\n");
    int i;
    for(i=1;i<=120;i++)
        printf("-");
    passenger pr;
    int check=0;
    i=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,tb)==0)
        {
            check=1;
            printf("%d",pr.ticket_no);
            gotoxy(14,i);
            printf("%s",pr.train_no);
            gotoxy(26,i);
            printf("%s",pr.p_name);
            gotoxy(45,i);
            printf("%c",pr.gender);
            gotoxy(55,i);
            printf("%s",pr.address);
            gotoxy(75,i);
            printf("%s",pr.mob_no);
            gotoxy(90,i);
            printf("%d",pr.age);
            gotoxy(100,i);
            printf("%c\n",pr.p_class);
            i++;
        }
    }
    if(check==0)
    {
        int i;
        for(i=1;i<=120;i++)
        {
            gotoxy(i,1);
            printf(" \b");
            gotoxy(i,2);
            printf(" \b");
        }
        gotoxy(1,1);
        system("color 06");
        printf("No details of train no %s found",tb);
        system("color 06");
    }
    system("color 06");
    printf("\n\n\n\n\n\nPress any key to go back to the main screen");
    getch();
    fclose(fp);
}
/*----End of View Bookings ----*/


/*----Accept train number ----*/

int accept_train_no()
{
    system("cls");
    static char train_no[20];
    gotoxy(100,1);
    system("color 06");
    printf("Press 0 to exit");
    gotoxy(1,1);
    system("color 06");
    printf("Enter train number: ");
    while(1)
    {
        fflush(stdin);
        fgets(train_no,20,stdin);
        char* pos;
        pos=strchr(train_no,'\n');
        *pos='\0';
        if(strcmp(train_no,"0")==0)
        {
            gotoxy(1,25);
            system("color 06");
            printf("Cancelling Input..!");
            return NULL;
        }
        if(check_train_no(train_no))
        {
            break;
        }
        else
        {
            gotoxy(1,30);
            system("color 06");
            printf("Error! Invalid Train No");
            system("color 06");
            gotoxy(21,1);
            printf("      \b\b\b\b\b\b");
        }
    }
    return train_no;
}
/*----End of Accept ticket number ----*/


/*----Cancel Ticket ----*/
int cancel_ticket(int ticket_no)
{
    FILE *fp1=fopen("allbookings.txt","rb");
    if(fp1==NULL)
    {
        system("color 06");
        printf("\nNo bookings done yet");
        return -1;
    }
    FILE *fp2=fopen("emp.txt","wb");
    passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(pr.ticket_no!=ticket_no)
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }
        else
        {
            found=1;
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found)
    {
        remove("allbookings.txt");
        rename("emp.txt","allbookings.txt");
    }
    else
    {
        remove("temp.txt");
    }
    return found;
}
/*----End of Cancel Ticket ----*/

/*-----Cancel Train -----*/
int cancel_train(char* tnm)
{
    FILE *fp1=fopen("allbookings.txt","rb");
    if(fp1==NULL)
    {
        system("color 06");
        printf("\nNo bookings done yet");
        return -1;
    }
    FILE *fp2=fopen("temp.txt","wb");
    passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(strcmp(pr.train_no,tnm)!=0)
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }
        else
        {
            found=1;
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found)
    {
        remove("allbookings.txt");
        rename("temp.txt","allbookings.txt");
    }
    else
    {
        remove("temp.txt");
    }
    return found;
}
/*----End of Cancel Train ----*/
