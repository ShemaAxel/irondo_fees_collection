#include<stdio.h>
#include<string.h>
FILE *u;
FILE *res;
FILE *pay;
FILE *tmp;
struct user
{
    char username[45];
    char id[45];

}user;
struct date{
int day;
int month;
int year;
//int paymentcheck[12];
};
struct resident{
int available;
char fname[45];
char lname[45];
char identification[45];
char house_id[45];
char umudugudu[45];
char tel[15];
int lastpayment;
int total;
struct date pay[];
}r;

void login()
{char izina[45];
char iranga[45];
    int t=0;
    log:
u=fopen("users.txt","r");

printf("\n\n\n\t :: Injiza izina (Enter The New user name)\n\t => ");
scanf("%s",izina);
printf("\t :: Injize nomero y'irangamuntu(Enter The New user Id)\n\t => ");
scanf("%s",iranga);
while(!feof(u))
{
    fscanf(u,"%s %s\n",user.username,user.id);
    if(strcmp(iranga,user.id)==0 && strcmp(izina,user.username)==0)
    {
        t=1;
        system("cls");
        printf("\n\n\n\t\t\t Murakaza Neza(Welcome)....\n");

    }

}
if(t==0)
{
    system("cls");
    printf("\t\n\n\n ::Ntibishoboka komwinjira mwongere mugerageze(Wrong username or password)\n");
    goto log;
}
}

void newuser()
{
    u=fopen("users.txt","a");
    FILE *r;
    r=fopen("users.txt","r");
    char test[45];
    printf("\t :: Injiza izina(Enter The New user name)\n\t => ");
    scanf("%s",user.username);
    try:
    printf("\t :: Injiza nomero y'irangamuntu(Enter The New user Id)\n\t => ");
    scanf("%s",test);
    int     t=0;
    while(!feof(r))
    {
           fscanf(u,"%s %s\n",user.username,user.id);
        if(strcmp(test,user.id)==0)
        {
            t=1;
        }
    }
    if(t==1)
    {
        printf("The Id is already taken\n ");
        goto try;
    }
    printf("\t :: Ongera winjize nomero y'irangamuntu(Re-Enter The New user Id)\n\t => ");
    scanf("%s",user.id);
    if(strcmp(test,user.id)!=0)
    {
     printf("\t  Inomero y'irangamuntu mwinjije ntihuye(Id doesn't match)\n\t  Ongera usubiremo \n ");
     goto try;
    }
    fprintf(u,"%s %s\n",user.username,user.id);


}

void readresident()
{
printf("\t   UMUTURAGE MUSHYA:\n\n");
printf("===========================================\n");
r.available=1;
printf("\n::    Izina ry'umuryango(First Name)\n=>    ");
scanf("%s",r.fname);
printf("::    Izina ryabatisimu(Second Name)\n=>    ");
scanf("%s",r.lname);
printf("::    Ikiranga Umuturage(Id)\n=>    ");
scanf("%s",r.identification);
printf("::    Inomero y'inzu(House Number)\n=>    ");
scanf("%s",r.house_id);
printf("::    Umudugudu(Village)\n=>    ");
scanf("%s",r.umudugudu);
printf("::    Nomero ya Telephone(Telephone Number)\n=>    ");
scanf("%s",r.tel);
r.lastpayment=0;
r.total=0;
r.pay[r.lastpayment].day=0;
r.pay[r.lastpayment].month=0;
r.pay[r.lastpayment].year=0;
res=fopen("residents.txt","a");
fprintf(res,"%d %s %s %s %s %s %s %d %d %d %d %d\n",r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,r.lastpayment,r.total,r.pay[r.lastpayment].day,r.pay[r.lastpayment].month,r.pay[r.lastpayment].year);
fclose(res);
/*pay=fopen("payment.txt","a");//to write to payment
fprintf(pay,"%d %s %s %s %s %s %s %d %d %d %d %d\n",r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,r.lastpayment,r.total,r.pay[r.lastpayment].day,r.pay[r.lastpayment].month,r.pay[r.lastpayment].year);
fclose(pay); ///not writting to this file
*/
}

void recordpay(){//
char key[45];
int i,lastpay,mothpay,t=0;
res=fopen("residents.txt","r");
tmp=fopen("temp.txt","a");
printf("\t:: Ikiranga Umuturage\n \t=> ");
scanf("%s",key);
while(!feof(res))
{
     fscanf(res,"%d %s %s %s %s %s %s %d %d %d %d %d\n\n",&r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,&r.lastpayment,&r.total,&r.pay[r.lastpayment].day,&r.pay[r.lastpayment].month,&r.pay[r.lastpayment].year);
    if(strcmp(key,r.identification)==0)
    {
        t=1;
        printf("\t           ***UBWISHYU BWUMUTURAGE***\n\n");
        printf("=============================================================\n");
        lastpay=r.lastpayment;
        day:
        printf("\t:: Injiza Umunsi(Enter The day)\n\t=> ");
        scanf("%d",&r.pay[lastpay].day);
        int day;
        day=r.pay[lastpay].day;
            if(r.pay[lastpay].day<1 || r.pay[lastpay].day>31)
            {
                system("cls");
                printf("\t**Umunsi Winjije siwo(Wrong Day)**\n ");
                goto day;
            }
        month:
        printf("\t:: Injiza Ukwezi(Enter The month)\n\t=> ");
        scanf("%d",&r.pay[lastpay].month);
        int month;
        month=r.pay[lastpay].month;
        mothpay=r.pay[lastpay].month;//ukwezi kwizshyuwe for the array
            if(r.pay[lastpay].month<1||r.pay[lastpay].month>12)
            {
                 system("cls");
                 printf("\t**Ukwezi Winjije siko(Wrong month)**\n ");
                 goto month;
            }
        year:
        printf("\t:: Injiza Umwaka(Enter The Year)\n\t=> ");
        scanf("%d",&r.pay[lastpay].year);
        int year;
        year=r.pay[lastpay].year;
            if(r.pay[lastpay].year<2017)
            {
                system("cls");
                printf("\t**Umwaka Winjije siwo(Wrong year)**\n ");
                goto year;
            }
//        r.pay[lastpay].paymentcheck[mothpay-1]=1;
        r.total=r.total+2000;///cumulative payments of a
        r.lastpayment=r.lastpayment+1;///payment array for customer knowing last payment details
    fprintf(tmp,"%d %s %s %s %s %s %s %d %d %d %d %d\n\n",r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,r.lastpayment,r.total,r.pay[r.lastpayment].day,r.pay[r.lastpayment].month,r.pay[r.lastpayment].year);
    pay=fopen("payment.txt","a");
    fprintf(pay,"%d %s %s %s %s %s %s %d %d %d %d %d\n\n",r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,r.lastpayment,r.total,day,month,year);
    fclose(pay);
    }else
    {
    fprintf(tmp,"%d %s %s %s %s %s %s %d %d %d %d %d\n\n",r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,r.lastpayment,r.total,r.pay[r.lastpayment].day,r.pay[r.lastpayment].month,r.pay[r.lastpayment].year);

    }
}
fclose(tmp);
fclose(res);
remove("residents.txt");
rename("temp.txt","residents.txt");

}

void printresident(int x)
{int i;
res=fopen("residents.txt","r");
if(x==0)// all residents
{
             printf("\t\t   ABATURAGE BOSE BARI MUKAGALI:\n");
             printf("\t===========================================\n");
             printf("\tFirst Name     Last Name      Identification       House       Village      Tel\n");
             printf("\t==========     =========      ==============       ======      =======      ===\n");
            while(!feof(res))
            {
            fscanf(res,"%d %s %s %s %s %s %s %d %d %d %d %d\n\n",&r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,&r.lastpayment,&r.total,&r.pay[r.lastpayment].day,&r.pay[r.lastpayment].month,&r.pay[r.lastpayment].year);
             if(r.available==1)
             {
             printf("\t%s       %s      %s         %s        %s      %s\n",r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel);
             }
            }
fclose(res);

}else if(x==1){///ABATURAGE BUMUDUGUDU
            int t=0;
            printf("\t:: IZINA RY'UMUDUGUDU:\n\t=> ");
             char search[45];
             scanf("%s",search);
             printf("\t\t   ABATURAGE BOSE BARI MUKAGALI:\n");
             printf("\t===========================================\n");
             printf("\tFirst Name   Last Name   Identification   House    Village   Tel\n");
             printf("\t==========   =========   ==============   ======   =======   ===\n");
            while(!feof(res))
            {

           fscanf(res,"%d %s %s %s %s %s %s %d %d %d %d %d\n\n",&r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,&r.lastpayment,&r.total,&r.pay[r.lastpayment].day,&r.pay[r.lastpayment].month,&r.pay[r.lastpayment].year);
             if(strcmp(search,r.umudugudu)==0 && r.available==1){
                    t=1;
             printf("\t%s       %s           %s                %s        %s      %s\n",r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel);
                                                }
            }
         if(t==0)
         {
             printf("\n\t *** UMUDUGUDU NTUHARI MUKAGALI KACU****");
         }
         fclose(res);
}else if(x==2){///ubwishyu bwumuturage
            int t=0;
            printf("\t:: IKIRANGA UMUTURAGE:\n\t=> ");
             char search[45];
             scanf("%s",search);
             int day,month,year,total=0;
            pay=fopen("payment.txt","r");
             printf("\t\t   UBWISHYU BWUMUTURAGE:\n");
             printf("\t===========================================\n");
             printf("\tFirst Name   Last Name   Village   \n");
             printf("\t==========   =========   =======   \n");
            int i=1;
            while(!feof(pay))
            {
            fscanf(pay,"%d %s %s %s %s %s %s %d %d %d %d %d\n",&r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,&r.lastpayment,&r.total,&day,&month,&year);

                if(strcmp(search,r.identification)==0){
                    t=1;

             printf("\n\t%s       %s            %s      \n",r.fname,r.lname,r.umudugudu);
             printf("\n\n\t Uko Wishyura, ubwishyu bwa (%d):\n",i);
             printf("\t:: Itariki Wishyuriyeho\n");
             printf("\t=> %d/%d/%d",day,month,year);
                total=r.total;
                i++;
             }

            }

            printf("\n\n\n\t:: Amafaranga Yose Hamwe Mumaze Kwishyura: %d\n",total);

         if(t==0)
         {
             printf("\n\t *** UMUDUGUDU NTUHARI MUKAGALI KACU****");
         }
         fclose(res);
}else if(x==3) ///ubwishyu mukwezi runaka
            {
                int j,t=0;
                int totalmukwezi=0;
            printf("\t:: UKWEZI MUSHAKA:\n\t=> ");
             int search;
             scanf("%d",&search);
             printf("\t:: UMWAKA MUSHAKA:\n\t=> ");
             int yr;
             scanf("%d",&yr);
             printf("\t\t   UBWISHYU MUKWEZI MUSHAKA:\n");
             printf("\t===========================================\n");
             printf("\tFirst Name   Last Name   Village   Total\n");
             printf("\t==========   =========   =======   ===\n");
             pay=fopen("payment.txt","r");
             int day,month,year;

             while(!feof(pay))
             {
               fscanf(pay,"%d %s %s %s %s %s %s %d %d %d %d %d\n\n",&r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,&r.lastpayment,&r.total,&day,&month,&year);
             if(search==month && yr==year)
                {
                    t=1;
             printf("\t%s       %s            %s      %d\n",r.fname,r.lname,r.umudugudu,r.total);

                }
               totalmukwezi=totalmukwezi+r.total;
             }


         if(t==0)
         {
             printf("\n\t         *** UBWISHYU NTABWAGARAGAYE****");
         }else{
         printf("\n\n\t\tAMAFARANGA YOSE HAMWE NI%d:\n",totalmukwezi);
         }
            fclose(res);
}else if(x==4)///ubwishyu bwose hamwe
            {
             int t;
                int total=0;
             printf("\t\t   UBWISHYU BWOSE HAMWE:\n");
             printf("\t===========================================\n");
             printf("\tFirst Name   Last Name   Village   Total\n");
             printf("\t==========   =========   =======   ===\n");

             pay=fopen("payment.txt","r");
             int day,month,year;

             while(!feof(pay))
             {
               fscanf(pay,"%d %s %s %s %s %s %s %d %d %d %d %d\n\n",&r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,&r.lastpayment,&r.total,&day,&month,&year);

                    t=1;
             printf("\t%s       %s          %s      %d\n",r.fname,r.lname,r.umudugudu,r.total);


               total=total+r.total;
             }
            fclose(res);
             printf("\n\n\t\t   AMAFARANGA YOSE HAMWE NI :%d\n",total);

}else if(x==5) ///ubwishyu mumudugu runaka
        {
                int t=0;
                int total=0;
            char key[45];
             printf("\t:: UMUDUGUDU MWIFUZA RAPORO YAWO:\n\t=> ");
             scanf("%s",key);
             printf("\t\t   UBWISHYU MUMUDUGUDU:\n");
             printf("\t===========================================\n");
             printf("\tFirst Name   Last Name   Village   Total\n");
             printf("\t==========   =========   =======   ===\n");
             pay=fopen("payment.txt","r");
            int day,month,year;
              while(!feof(pay))
             {
               fscanf(pay,"%d %s %s %s %s %s %s %d %d %d %d %d\n\n",&r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,&r.lastpayment,&r.total,&day,&month,&year);
                if(strcmp(key,r.umudugudu)==0 && r.available==1)
                {
                    t=1;
             printf("\t%s            %s         %s        %d\n",r.fname,r.lname,r.umudugudu,r.total);
             total=total+r.total;
                }

                }
         if(t==0)
         {
             printf("\n\t *** UBWISHYU NTABWAGARAGAYE****");
         }else{
         printf("\n\n\t\t   AMAFARANGA YOSE HAMWE NI :%d\n",total);
         }


   fclose(res);

}
}

void search(int x)
{
    if(x==0)///abaturage bahaba batarimuka
    {int t=0;
             res=fopen("residents.txt","r");
             printf("\t\t   ABATURAGE BOSE BARI MUKAGALI:\n");
             printf("\t===========================================\n");
             printf("\tFirst Name   Last Name   Identification   House    Village   Tel\n");
             printf("\t==========   =========   ==============   ======   =======   ===\n");
            while(!feof(res))
            {

           fscanf(res,"%d %s %s %s %s %s %s %d %d %d %d %d\n\n",&r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,&r.lastpayment,&r.total,&r.pay[r.lastpayment].day,&r.pay[r.lastpayment].month,&r.pay[r.lastpayment].year);
             if(r.available==1){
                    t=1;
             printf("\t%s       %s           %s                %s        %s      %s\n",r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel);
                                }
            }
         if(t==0)
         {
             printf("\n\t *** NTAMUTURAGE WAGARAGAYE****");
         }
         fclose(res);

    }else if(x==1){///abaturage bimutse
            int t=0;
             res=fopen("residents.txt","r");
             printf("\t\t   ABATURAGE BOSE BARI MUKAGALI:\n");
             printf("\t===========================================\n");
             printf("\tFirst Name   Last Name   Identification   House    Village   Tel\n");
             printf("\t==========   =========   ==============   ======   =======   ===\n");
            while(!feof(res))
            {

           fscanf(res,"%d %s %s %s %s %s %s %d %d %d %d %d\n\n",&r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,&r.lastpayment,&r.total,&r.pay[r.lastpayment].day,&r.pay[r.lastpayment].month,&r.pay[r.lastpayment].year);
             if(r.available==0){
                    t=1;
             printf("\t%s       %s           %s                %s        %s      %s\n",r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel);
                                }
            }
         if(t==0)
         {
             printf("\n\t *** NTAMUTURAGE WAGARAGAYE****");
         }
         fclose(res);
    }else if(x==2)///umuturage
    {
      int t=0;
            printf("\t:: IKIRANGA UMUTURAGE:\n\t=> ");
            res=fopen("residents.txt","r");
             char search[45];
             scanf("%s",search);
             printf("\t\t   ABATURAGE BOSE BARI MUKAGALI:\n");
             printf("\t===========================================\n");
             printf("\tFirst Name   Last Name   Identification   House    Village   Tel\n");
             printf("\t==========   =========   ==============   ======   =======   ===\n");
            while(!feof(res))
            {

           fscanf(res,"%d %s %s %s %s %s %s %d %d %d %d %d\n\n",&r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,&r.lastpayment,&r.total,&r.pay[r.lastpayment].day,&r.pay[r.lastpayment].month,&r.pay[r.lastpayment].year);
             if(strcmp(search,r.identification)==0){
                    t=1;
             printf("\t%s       %s           %s                %s        %s      %s\n",r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel);
                                                }
            }
         if(t==0)
         {
             printf("\n\t *** UMUDUGUDU NTUHARI MUKAGALI KACU****");
         }
         fclose(res);
    }


    }

void modify(int x)
{
    if(x==0)///guhindura ibiranga umuturage
    {
        char key[45];
        res=fopen("residents.txt","r");
        printf("\t:: Ikiranga Umuturage\n \t=> ");
        scanf("%s",key);
        while(!feof(res))
        {
        fscanf(res,"%d %s %s %s %s %s %s %d %d %d %d %d\n\n",&r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,&r.lastpayment,&r.total,&r.pay[r.lastpayment].day,&r.pay[r.lastpayment].month,&r.pay[r.lastpayment].year);
        if(strcmp(key,r.identification)==0 && r.available==1){
         printf("\t   IBIRANGA UMUTURAGE:\n\n");
        printf("===========================================\n");
        r.available=1;
        printf("\n::    Izina ry'umuryango(First Name)\n=>    ");
        scanf("%s",r.fname);
        printf("::    Izina ryabatisimu(Second Name)\n=>    ");
        scanf("%s",r.lname);
        printf("::    Ikiranga Umuturage(Id)\n=>    ");
        scanf("%s",r.identification);
        printf("::    Inomero y'inzu(House Number)\n=>    ");
        scanf("%s",r.house_id);
        printf("::    Umudugudu(Village)\n=>    ");
        scanf("%s",r.umudugudu);
        printf("::    Nomero ya Telephone(Telephone Number)\n=>    ");
        scanf("%s",r.tel);
        tmp=fopen("temp.txt","a");
        fprintf(tmp,"%d %s %s %s %s %s %s %d %d %d %d %d\n",r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,r.lastpayment,r.total,r.pay[r.lastpayment].day,r.pay[r.lastpayment].month,r.pay[r.lastpayment].year);
        fclose(tmp);


        }else{
        tmp=fopen("temp.txt","a");
        fprintf(tmp,"%d %s %s %s %s %s %s %d %d %d %d %d\n",r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,r.lastpayment,r.total,r.pay[r.lastpayment].day,r.pay[r.lastpayment].month,r.pay[r.lastpayment].year);
        fclose(tmp);

        }


        }

        fclose(res);
        remove("residents.txt");
        rename("temp.txt","residents.txt");

        /*remove and rename
        modify even the payment file*/


}else if(x==1){//kwimura umuturage
        char key[45];
        int t=0;
        res=fopen("residents.txt","r");
        tmp=fopen("temp.txt","a");
        printf("\t:: Ikiranga Umuturage\n \t=> ");
        scanf("%s",key);
        while(!feof(res))
        {
        fscanf(res,"%d %s %s %s %s %s %s %d %d %d %d %d\n\n",&r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,&r.lastpayment,&r.total,&r.pay[r.lastpayment].day,&r.pay[r.lastpayment].month,&r.pay[r.lastpayment].year);
        if(strcmp(key,r.identification)==0){
                t=1;
        r.available=0;
        fprintf(tmp,"%d %s %s %s %s %s %s %d %d %d %d %d\n",r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,r.lastpayment,r.total,r.pay[r.lastpayment].day,r.pay[r.lastpayment].month,r.pay[r.lastpayment].year);
        }else{
        fprintf(tmp,"%d %s %s %s %s %s %s %d %d %d %d %d\n",r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,r.lastpayment,r.total,r.pay[r.lastpayment].day,r.pay[r.lastpayment].month,r.pay[r.lastpayment].year);
        }
       }
       if(t==0)
       {
         printf("\t Uyu Muturage ntawabonetse mubasanzwe batuye mukagali kacu(resident not found)..");
       fclose(tmp);
        fclose(res);
       }else{
       fclose(tmp);
        fclose(res);
        remove("residents.txt");
        rename("temp.txt","residents.txt");
       }

}
else if(x==2)///kongeramo uwigeze kuhaba
{   char key[45];
        int t=0;
        res=fopen("residents.txt","r");
        tmp=fopen("temp.txt","a");
        printf("\t:: Ikiranga Umuturage\n \t=> ");
        scanf("%s",key);
        while(!feof(res))
        {
        fscanf(res,"%d %s %s %s %s %s %s %d %d %d %d %d\n\n",&r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,&r.lastpayment,&r.total,&r.pay[r.lastpayment].day,&r.pay[r.lastpayment].month,&r.pay[r.lastpayment].year);
        if(strcmp(key,r.identification)==0){
                t=1;
        r.available=1;
        fprintf(tmp,"%d %s %s %s %s %s %s %d %d %d %d %d\n",r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,r.lastpayment,r.total,r.pay[r.lastpayment].day,r.pay[r.lastpayment].month,r.pay[r.lastpayment].year);
        }else{
        fprintf(tmp,"%d %s %s %s %s %s %s %d %d %d %d %d\n",r.available,r.fname,r.lname,r.identification,r.house_id,r.umudugudu,r.tel,r.lastpayment,r.total,r.pay[r.lastpayment].day,r.pay[r.lastpayment].month,r.pay[r.lastpayment].year);
        }
       }
       if(t==0)
       {
         printf("\t Uyu Muturage ntawabonetse mubasanzwe batuye mukagali kacu(resident not found)..");
       fclose(tmp);
        fclose(res);
       }else{
       fclose(tmp);
        fclose(res);
        remove("residents.txt");
        rename("temp.txt","residents.txt");

            }
        }
}
main()
{
    login();
 int ch,x=0;
      main:

      printf("\n\n\n\t\t\t   AMAFARANGA Y'IRONDO:\n\n");
	  printf("\t\t=============================================\n");
	  printf("\n\t\t[1]:    kongeramo umuturage(Add a resident)\n");
	  printf("\t\t[2]:    kwakira amafaranga(Add a payment)\n");
	  printf("\t\t[3]:    kureba raporo(Reports)\n");//all residents,specific month payment,specific month for a resident,all paymnets amount
	  printf("\t\t[4]:    gushakisha(Search)\n");///abahaba,abimutse,umuturage,
	  printf("\t\t[5]:    guhindura ibiranga umuturage(Modify)\n");///remaining
	  printf("\t\t[6]:    Kongeramo umukoresha wa sistemu(Add a new User)\n");
	  printf("\t\t[7]:    gusohoka(Exit)\n");
	  printf("\n\t\t=============================================\n");
      printf("\t\tInjiza uguhitamo kwawe:: ");
      ch  = getche();
switch(ch){
case '1':// new resident
        system("cls");
        record:
      printf("\n\n\n\t\t\t   AMAFARANGA Y'IRONDO:\n\n");
	  printf("\t\t=============================================\n");
	  printf("\n\t\t[1]:    kongeramo umuturage Mushya (Add a new resident)\n");
	  printf("\t\t[2]:    kongeramo uwigeze kuhaba(Add a former)\n");
	  printf("\t\t[3]:    Gusubira ahabanza(goto main menu)\n");
	  printf("\n\t\t=============================================\n");
	  printf("\t\tInjiza uguhitamo kwawe:: ");
      ch  = getche();
        switch(ch)
        {
        case '1':
            system("cls");
            readresident();
            printf("\t **Ibyomumaze gukora byemejwe(Record Successfully Saved)**");
            getch();
            system("cls");
            goto record;
        break;
        case '2':
            x=2;
            system("cls");
            modify(x);
            printf("\n\n\t           ***Ibyo Mwakoze Byemejwe(Saved Successfully)***\n\n");
            getch();
            system("cls");
            x=0;
            goto record;
        break;
        case '3':
         system("cls");
         goto main;
        break;
        default:
            system("cls");
            printf("\t\t **Mwahisemo nabi(Wrong Choice)**");
            goto record;
        break;

        }


break;
case '2':// new payment
system("cls");
recordpay();
printf("\t **Ibyomumaze gukora byemejwe(Record Successfully Saved)**");
getch();
system("cls");
goto main;
system("cls");
printf("\t **Ibyomumaze gukora byemejwe(Record Successfully Saved)**");
break;
case '3':// reports
    system("cls");
    report:
    printf("\t           ***RAPORO MUKAGALI***\n\n");
    printf("=============================================================\n");
	printf("\n[1]:    ABATURAGE BOSE(All Resident)\n");///done
	printf("[2]:    Ubwishyu mukwezi runaka(Payments of a specific month)\n");///done
	printf("[3]:    Ubwishyu bwose hamwe(All Payments)\n");///done
	printf("[4]:    Ubwishyu bwumuturage runaka(payments of resident)\n");///done
	printf("[5]:    Abaturage Bumudugudu(Residents of a given Village)\n");///done
	printf("[6]:    Ubwishyu Bwumudugudu(payments of a given Village)\n");///done
	printf("[7]:    Gusubira ahabanza(Go to the Main Menu)\n");
	printf("\n============================================================\n");
    printf("Injiza uguhitamo kwawe: ");
    ch  = getche();
    switch(ch)
    {
        case '1':// all residents
            x=0;
            system("cls");
            printresident(x);
            printf("\n\n\t           ***ABATURAGE BOSE***\n\n");
            getch();
            system("cls");
            goto report;
        break;
        case '2':
            system("cls");
            x=3;
            printresident(x);
            printf("\n\n\t           ***UBWISHYU MUKWEZI RUNAKA***\n\n");
            getch();
            system("cls");
            x=0;
            goto report;
        break;
        case '3':
             system("cls");
            x=4;
            printresident(x);
            printf("\n\n\t           ***UBWISHYU MUKWEZI RUNAKA***\n\n");
            getch();
            system("cls");
            x=0;
            goto report;
        break;
        case '4':// ubwishyu bwumuturage runaka
            system("cls");
            x=2;
            printresident(x);
            printf("\n\n\t           ***UBWISHYU BWUMUTURAGE***\n\n");
            getch();
            system("cls");
            x=0;
            goto report;
        break;
        case '5':///search abaturage bumudugudu
            system("cls");
            x=1;
            printresident(x);
            printf("\n\n\t           ***ABATURAGE BUMUDUGUDU***\n\n");
            getch();
            system("cls");
            x=0;
            goto report;
        break;
         case '6':///ubwishyu bwumudugudu
             system("cls");
            x=5;
            printresident(x);
            printf("\n\n\t           ***ABATURAGE BUMUDUGUDU***\n\n");
            getch();
            system("cls");
            x=0;
            goto report;
        break;
        case '7':
            system("cls");
            goto main;
        break;
        default:
            system("cls");
            printf("\t           ***MWAHISEMO NABI***\n\n");
            goto report;
        break;
    }
break;
case '4'://search
      system("cls");
        search:
      printf("\n\n\n\t\t\t   AMAFARANGA Y'IRONDO:\n\n");
	  printf("\t\t=============================================\n");
	  printf("\n\t\t[1]:    Abaturage baba mukagali (A current resident)\n");///done
	  printf("\t\t[2]:    Abaturage bimutse mukagali(A former resident)\n");///done
	  printf("\t\t[3]:    Gushakisha Umuturage(Search for a resident)\n");///done
	  printf("\t\t[4]:    Gusubira ahabanza(Go to main menu)\n");
	  printf("\n\t\t=============================================\n");
	  printf("\t\tInjiza uguhitamo kwawe:: ");
      ch  = getche();
      switch(ch)
      {
      case '1':
          x=0;
          system("cls");
            search(x);
            printf("\n\n\t           ***ILISITI YABATURAGE***\n\n");
            x=0;
            getch();
            system("cls");
            goto search;
        break;
      case '2':
          x=1;
          system("cls");
            search(x);
            printf("\n\n\t           ***ILISITI YABATURAGE***\n\n");
            x=0;
            getch();
            system("cls");
            goto search;
        break;
      case '3':
          x=2;
          system("cls");
            search(x);
            printf("\n\n\t           ***UMUTURAGE***\n\n");
            x=0;
            getch();
            system("cls");
            goto search;
        break;
      case '4':

            system("cls");
            goto main;
        break;
      default:
        break;
      }

break;
case '5'://modify
    system("cls");
        modify:
      printf("\n\n\n\t\t\t   GUHINDURA IBIJYANYE N'UMUTURAGE:\n\n");
	  printf("\t\t=============================================\n");
	  printf("\n\t\t[1]:    Guhindura ibiranga umuturage (Modify the resident information)\n");
	  printf("\t\t[2]:    Kwimura umuturage(Remove a resident)\n");
	  printf("\t\t[3]:    Gusubira ahabanza(goto main menu)\n");
	  printf("\n\t\t=============================================\n");
	  printf("\t\tInjiza uguhitamo kwawe:: ");
      ch  = getche();
      switch(ch)
      {
      case '1':
          x=0;
            system("cls");
            modify(x);
            printf("\n\n\t           ***Ibyo Mwakoze Byemejwe(Saved Successfully)***\n\n");
            getch();
            system("cls");
            goto modify;
        break;
      case '2':
          x=1;
            system("cls");
            modify(x);
            printf("\n\n\t           ***Ibyo Mwakoze Byemejwe(Saved Successfully)***\n\n");
            getch();
            system("cls");
            goto modify;
        break;
      case '3':
           system("cls");
           goto main;
        break;
      default:
        break;

      }
break;
case '6':
system("cls");
newuser();
getch();
system("cls");
//exit(0);
goto main;
break;

case '7':
system("cls");
printf("\t ***MURAKOZE***\n");
getch();
//exit(0);
break;
default:

system("cls");
printf("\t ***MWAHISEMO NABI***\n\n");
goto main;
break;
}

printf("GOD help me");
}
