#include<stdio.h>
#include<string.h>
 
int No_players;

struct Cricket
{
  int wickets,age,ODI,T20i;
  char country[20],name[25];
  float Batting_Avg;
  int category;
}players[1000];

// Batsmen by country
void BatsmanByCountry(){
    int j=0,count=0;;
    char Country[20];
    printf("\n Enter the name of the country whose batsman you wish to display : ");
    scanf("%s",Country);
    printf("\n\n Batsmen from Entered Country are ---->");
    while(j<No_players){
       if(strcmp(players[j].country,Country)==0){
            if(players[j].category==1){
                printf("\n %d) %s",count+1,players[j].name);
            }
       }
       j++;
    }
}

// Bowler by Country
void BowlerByCountry(){
        int k=0,count=0;;
    char Country[20];
    printf("\n Enter the name of the country whose Bowlers you wish to display : ");
    scanf("%s",Country);
    printf("\n\n Bolwers from Entered Country are ---->");
    while(k<No_players){
       if(strcmp(players[k].country,Country)==0){
            if(players[k].category==2){
                printf("\n %d) %s",count+1,players[k].name);
            }
       }
       k++;
    }
}

// Player with Highest batting avg
void HighestAverage(){
    float max;
    int h=1;
    max=players[0].Batting_Avg;
    while(h<No_players){
        if(players[h].Batting_Avg>max){
            max = players[h].Batting_Avg;
        }
    h++;
    }
  int count=1;
    printf("\n The Batsman with Highest Batting Average is ");
    for(int i=0 ; i<No_players;i++){
        if(players[i].Batting_Avg==max){
            printf("\n %d) %s",count,players[i].name);
        } 
    }
}

// Finding player with most wickets
void MostWickets(){
    int l=1,max = players[0].wickets;
    while(l<No_players){
        if(players[l].wickets>max){
         max = players[l].wickets;
        }
       l++; 
    }

       printf("\n Bowler with most wickets are : ");
   int count=1;
    for(int j=0 ; j<No_players ; j++){
        if(players[j].wickets!=max){
            continue;
        }
        printf("\n %d) %s",count,players[j].name);
    }
}

// Display Info of particular player
void PlayerInfo(){
    int index;
    char Player[25];
    printf("\n Enter the Name of the player whose information you want to display :");
    scanf("%s",Player);
 
    for(int a=0 ; a<No_players ;a++){
        if(strcmp(players[a].name,Player)==0){
            index = a;
            break;
        }
    }

    printf("\n Information for %s --->",Player);
    printf("\n Country : %s",players[index].country);
    printf("\n Age : %d",players[index].age);
    if(players[index].category==1){
        printf("\n Category : Batsman");
    }
    else if(players[index].category==2){
       printf("\n Category : Bowler"); 
    }
    else if(players[index].category==3){
       printf("\n Category : Wicket Keeper"); 
    }
    else if(players[index].category==4){
       printf("\n Category : All-Rounder"); 
    }
    printf("\n Batting average : %.3f",players[index].Batting_Avg);
    printf("\n Number of ODIs played : %d",players[index].ODI);
    printf("\n Number of T20Is played : %d",players[index].T20i);
    printf("\n Number of wickets : %d",players[index].wickets);
   
}

// Main
int main(){
    int choice;
    printf("\n Enter the number of Players whose information you want to display :");
    scanf("%d",&No_players);
    
    for(int i=0 ; i<No_players ; i++){
        printf("\n\n Details for player %d",i+1);
        printf("\n Enter the Name of the player : ");
        scanf("%s",players[i].name);

        printf("\n Enter the Country of the player : ");
        scanf("%s",players[i].country);

        printf("\n Enter the age of the player : ");
        scanf("%d",&players[i].age);

        printf("\n Enter the category of the player ---->");
        printf("\n 1) Batsman \t 2) Bowler \n 3) Wicket Keeper \t 4) All Rounder");
        printf("\n Players category is (Enter number corresponding to your option) : ");
        a:
        scanf("%d",&players[i].category);
        if(players[i].category>4 || players[i].category<0){
               printf("\n Enter valid number (1 to 4) : ");
               goto a;
        }

        printf("\n Enter the number of ODIs played : ");
        scanf("%d",&players[i].ODI);

        printf("\n Enter the number of T20Is played : ");
        scanf("%d",&players[i].T20i);
 
        printf("\n Enter the batting average of the player : ");
        scanf("%f",&players[i].Batting_Avg);

        printf("\n Enter number of wickets taken :");
       scanf("%d",&players[i].wickets);
    }

printf("\nEnter 1: to know the number of batsman of a particular country");
printf("\nEnter 2: to know number of bowlers of a particular country ");
printf("\nEnter 3: to know batsman with higest average score");
printf("\nEnter 4: to know bowler with maximum number of wickets");
printf("\nEnter 5: to know the the information of particular player");
again:
printf("\n\n Your choice : ");
invalid:
scanf("%d",&choice);
switch (choice)
{
case 1 : BatsmanByCountry();
         break;
 
case 3 : HighestAverage();
         break;

case 2 : BowlerByCountry();
         break;

case 4 : MostWickets();
         break;

case 5 : PlayerInfo();
         break;

default: printf("\n Invalid choice! \nPlease re-enter your choice : ");
         goto invalid;
    break;
}

int repeat;
printf("\n\n\n Do you want to perform operation again? ");
printf(" \n Enter 0 : No \n Enter 1 : Yes \n Want to Continue? : ");

scanf("%d",&repeat);
if(repeat == 1 ){
    goto again;
}
    return 0;
}
