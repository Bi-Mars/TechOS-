//#include "date.h"
//#include "setdate.h"
#include "commands.h"
#include <stdio.h>

// ask for input
int mm;
int dd;
int yy;
int check; 

void askDate(){
    
    do{ 
        check = 0;
        printf("Enter date (DD/MM/YYYY format): ");
        scanf("%d/%d/%d",&dd,&mm,&yy);
            //check year
        if(yy>=1900 && yy<=9999)
        {
            //check month
            if(mm>=1 && mm<=12)
            {
                //check days
                if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
                    printf("Date is valid.\n");
                else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                    printf("Date is valid.\n");
                else if((dd>=1 && dd<=28) && (mm==2))
                    printf("Date is valid.\n");
                else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
                    printf("Date is valid.\n");
                else{
                    check = 1;
                    printf("Day is invalid.\n");
                }
                    
            }
            else
            {
                check = 1;
                printf("Month is not valid.\n");
            }
        }
        else
        {
                check = 1;
            printf("Year is not valid.\n");
        }
     }while(check == 1);
    
}


 void setdate()
 {
     month = mm;
     day = dd;
     year = yy;
 }

