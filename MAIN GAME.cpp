
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

struct Qstn
 {
    char q[1000];       //Structure whch have a question,and its options and also
    char op1[30];       //Correct option for the question 
    char op2[30];
    char op3[30];
    char op4[30];
    char cor[30];
}e;
struct PLAYER
{
	char name[20];
   	int age;            //Sructure which stores all INfo regarding the player and
	int score;          // his game
	char category[20];
}P;

void NewGame();         // WHole Game Play Interface is written in this function
void admin();           //Admin LOgin and INterface and its functions are coded in this function
void Help();            //Help Page is  written in thif function
void scoreboard();      // The scores List and the its interface is written in this
void Highscore();       //The High scores of different categories and its interface is written in this function

char ch;                //declaration of GLOBAL VARIABLE 'ch' whch is used to exit or display mainmenu
                        //whose value is returned after each function defined 

int main()
{   
    getch();
	srand(time(NULL));
	system("cls");                    //Clear the screen
	char op;
	FILE *tp;                     
	char ct;
	tp=fopen("QuizDecor.txt","r+");
	while(!feof(tp))
	{
	  ct=fgetc(tp);
	  printf("%c",ct);	
    }	
    fclose(tp);
    system("COLOR 01");          //TO cReate a colour changing welcome to the user
    Sleep(800);
    system("COLOR 02");
    Sleep(800);
    system("COLOR 0D");
    Sleep(800);
    system("COLOR 0C");
    Sleep(800);
    system("COLOR 0A");
    Sleep(800);
    system("COLOR 03");
    Sleep(2000);
    mainmenu:
    system("cls");
	system("COLOR 0B");         //To change the color of the text to aquaBlue with background as Black
	FILE *ty;                     
	char cm;
	ty=fopen("mainmenu.txt","r+");
	while(!feof(ty))                //To Display MainMenu
	{
	  cm=fgetc(ty);
	  printf("%c",cm);	
    }	
    fclose(ty);
	printf("\n\t\t\tPlease Enter your choice:");
	op=getch();
	flag:
	switch(op)              //Switch CAse to go to call Specific function According
	{                       //      To option chose by the user
		case '1':
			     NewGame();
			     break;
        case '2':
        	     scoreboard();
        	     break;
        case '3':
        	     Highscore();
        	     break;
        case '4':
        	     Help();
        	     break;
        case '5':
        	     system("cls");
        	     printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tTHANKS FOR PLAYING THIS GAME!!!");
        	     Sleep(1500);
        	     exit(0);
        	     break;
        case '6':
        	     admin();
        	     break;
        default:
        	break;
                 
	}
	if(ch=='*')                //Decision Control to Display mainmenu Or exit
	{                          //Using value of "ch"returned by different functions
		  	goto mainmenu;
	}
	else
	{
		op='5';
	    goto flag;
	}	
}

void NewGame()
{
	int i=0;
	system("cls");
	printf("\n\n\n\n\n\n\t\t\t\tYOUR NAME:");        //store User'S name in structure
 	gets(P.name);
	printf("\n\t\t\t\tYOUR AGE:");                   //Store User's Age in Structure
	scanf("%d",&P.age);
	printf("\n\t\t\t\tTHANK YOU!!");                       
	Sleep(1000);
	gamemainmenu:
	system("cls");
	char op;
	char filename[30];                       
	FILE *ty;
	char cm;
	ty=fopen("gamemenu.txt","r+");
	while(!feof(ty))                       
	{
	  cm=fgetc(ty);
	  printf("%c",cm);	
    }
    fclose(ty);
	printf("\n\t\t\tPlease Enter your choice:");
	op=getche();
	switch(op)                     //To store category of game player play and file of questions we have to open
	{
		case '1':
			strcpy(filename,"IT.txt");
			strcpy(P.category,"IT");
			break;
		case '2':
			strcpy(filename,"Sports.txt");
			strcpy(P.category,"Sports");
			break;
		case '3':
			strcpy(filename,"GeneralKnowledge.txt");
			strcpy(P.category,"GeneralKnowledge");
			break;
		case '4':
			strcpy(filename,"Entertainment.txt");
			strcpy(P.category,"Entertainment");
			break;
		case '5':
			strcpy(filename,"Geography.txt");
			strcpy(P.category,"Geography");
			break;
		case '6':
			strcpy(filename,"WorldHistory.txt");
			strcpy(P.category,"WorldHistory");
			break;
	    case '7':
			strcpy(filename,"IndianHistory.txt");
			strcpy(P.category,"IndianHistory");
			break;
		case '8':
			strcpy(filename,"MindTeaser.txt");
			strcpy(P.category,"MindTeaser");
			break;
		default:
		    break;	     
	}
	int r=0,count=0;                             
	system("cls"); 
	char cp;
	ty=fopen("Instructions.txt","r+");   //Open ANd print instructions whch are stored in a file
	while(!feof(ty))
	{
	  cp=fgetc(ty);
	  printf("%c",cp);	
    }	
    fclose(ty);
	printf("\n\t\t         YOUR GAME STARTS in ");
	for(i=15;i>0;i--)       //Print Timer which counts from 15 to 0
    {
    	if(i>9)
    	printf("%d",i);                                       
    	else
    	printf("0%d",i);
    	Sleep(1000);
    	printf("\b");
    	printf("\b");
    }
	tryagain:
    system("cls");
	printf("\n\n\n\n\n\n\n\t\t\t\t GET READY!! ");
    printf("\n\t\t\t\tALL THE BEST %s!!",P.name);
    Sleep(2000);
	FILE *fp;
	fp=fopen(filename,"r+");
	count=0;
	while(fread(&e,sizeof(e),1,fp)==1)
	{
		count++;
	}
	rewind(fp);            //Sends pointer again to starting of the file for next use
	char pt;
	char option[30],corr[30];
	int right=0,wrong=0;
	clock_t start,end;
	start=clock();
	int j=0;
	int f=0;
	int a[10];
	
	for(i=1;i<=10;i++)
	{
		f=0;
		system("cls");
		r=rand()%count;
		for(j=0;j<=(i-1);j++)
		{
		   if(a[j]==r)
		   {
		   	f=1;
		   }
		}
		if(f==1)
		{
			i--;
			continue;
		}
		fseek(fp,(sizeof(e)*r),SEEK_SET);
		fread(&e,sizeof(e),1,fp);
		printf("%d.%s\n A.%s\tB.%s\tC.%s\tD.%s\t",i,e.q,e.op1,e.op2,e.op3,e.op4);
		strcpy(corr,e.cor);
		printf("\nPlease Enter your choice:");
		pt=getch();
		if(toupper(pt)=='A')                     
		{
			strcpy(option,e.op1);
		}
		else if(toupper(pt)=='B')
		{
			strcpy(option,e.op2);
		}
		else if(toupper(pt)=='C')
		{
			strcpy(option,e.op3);
		}
		else if(toupper(pt)=='D')
		{
			strcpy(option,e.op4);
		}
		else if(pt=='$')
		{
			strcpy(option,"PASS");
		}
		
    	if(strcmp(option,corr)==0)
		{
		  right++;
		  printf("\nYOUR ANSWER IS CORRECT!!");
		  Sleep(1000);	
		}
		else if(strcmp(option,corr)!=0)
		{
			wrong++;
			printf("\nOOPS!! YOUR ANSWER IS WRONG!!");
			printf("\nCORRECT ANSWER IS:%s",e.cor);
			Sleep(1000);
		}
		else if(strcmp(option,"PASS")==0)
		{
			printf("\nYOU PASSED THE QUESTION!!");
			printf("\nCORRECT ANSWER IS:%s",e.cor);
			Sleep(1000);
		}
		a[i]=r;
	    
	}
	end=clock()-start;
	double time=((double)(end)/CLOCKS_PER_SEC)-10;	     //Calculate Time Taken by Player to Complete
	fclose(fp);                                          // ANswering questions
	int bonus=0;
	if(time>100)                             //decision Structure to Calculate  BONUS
	 bonus=0;	
	else if((time>70)&&(time<99))                  
	 bonus=10;
	else if((time>50)&&(time<69))
	 bonus=20;
	else if((time>30)&&(time<49))
	 bonus=30;
	else if(time<30)
	 bonus=50;
	FILE *ft;
	ft=fopen("ScoreList.txt","a+");      //Calculation of total score
	P.score=(right*10)-(wrong*5)+bonus;
	system("cls");
	printf("\n\n\n\n\n\n\t\t\t\tYOUR SCORE IS:%d",P.score); //Display score to the user
	printf("\n\t\t\t\tTIME TAKEN:%lf",time);     //Display Time taken by the user
	printf("\n\t\t\t\tBONUS POINTS AWARDED:%d",bonus); //Display Bonus Points Awarded
	printf("\n\t\t\t\tRIGHT:-%d",right);         //display no. of right answers
	printf("\n\t\t\t\tWRONG:-%d",wrong);         //Display no. of Wrong answers
	fwrite(&P,sizeof(P),1,ft);	
	fclose(ft);	
	printf("\n\t\t\t\tPress '$'To play again");
	printf("\n\t\t\t\tPress '#'for Gamecategory Menu");
	printf("\n\t\t\t\tPress '*'for mainmenu");
	printf("\n\t\t\t\tPress any other key To exit");
	char tr=getch();
	if(tr=='$')
	{
	  goto tryagain;	
	}
	else if(tr=='#')
	{
		goto gamemainmenu;
	}
	else if(tr=='*')
	{                           //COntrol Structure according to players choice
		ch=tr;                  //of leaving or playing again or return to game menu
	}
	else 
	{
		ch=tr;
	}
	
}

void scoreboard()
{
	scoreboardmenu:
	char op,tr;
	char category[20];
	system("CLS");
	int i=0;
	FILE *ty;
	char cm;
	ty=fopen("Scoreboard.txt","r+");            //Print Score Board MEnu 
	while(!feof(ty))
	{
	  cm=fgetc(ty);
	  printf("%c",cm);	
    }
    fclose(ty);
	printf("\n\t\t\tPlease Enter your choice:");
	op=getch();
	switch(op)              //Switch to store specific category scores which user wants to see
	{                       //and search for it ScoresList
	   	case '1':
			strcpy(category,"IT");
			break;
		case '2':
			strcpy(category,"Sports");
			break;
		case '3':
			strcpy(category,"GeneralKnowledge");
			break;
		case '4':
			strcpy(category,"Entertainment");
			break;
		case '5':
			strcpy(category,"Geography");
			break;
		case '6':
			strcpy(category,"WorldHistory");
			break;
	    case '7':
			strcpy(category,"IndianHistory");
			break;
		case '8':
			strcpy(category,"MindTeaser");
			break;
	    default:
		    break;	
	}
	FILE *ft;
	ft=fopen("ScoreList.txt","r+");
	system("cls");
	if(op!='9')
	{
	 while(fread(&P,sizeof(P),1,ft)==1)    //Search for Specific category scores and display them
	 {
		if(strcmp(P.category,category)==0)
		{
			printf("\n%s\t%d\t%s\t%d",P.name,P.age,P.category,P.score); //Print details of the players
		}
	 }
    }
    else
    {
	 while(fread(&P,sizeof(P),1,ft)==1)
	 {
			printf("\n%s\t%d\t%s\t%d",P.name,P.age,P.category,P.score);
	 }
    }
    fclose(ft);
	printf("\nPRESS '$' for score board menu");
	printf("\nPRESS '*' for mainmenu");
	printf("\nPRESS any other key to exit");
	tr=getch();
	if(tr=='$')
	{
	  goto scoreboardmenu;	
	}
	else if(tr=='*')
	{
		ch=tr;
	}
	else 
	{
		ch=tr;
	}	
}

 void Highscore()
 {
 	highscoremenu:
	char op;
	int i=0;
	char category[20];
	char max_name[20];
	system("cls");
	FILE *ty;
	char cm;
	ty=fopen("Highscore.txt","r+");              
	while(!feof(ty))
	{
	  cm=fgetc(ty);
	  printf("%c",cm);	                 //Print HIghscore Menu
    }
    fclose(ty);
	printf("\n\t\t\tPlease Enter your choice:");
	op=getch();
	switch(op)
	{
	   	case '1':
			strcpy(category,"IT");
			break;
		case '2':
			strcpy(category,"Sports");
			break;
		case '3':
			strcpy(category,"GeneralKnowledge");
			break;
		case '4':
			strcpy(category,"Entertainment");
			break;
		case '5':
			strcpy(category,"Geography");
			break;
		case '6':
			strcpy(category,"WorldHistory");
			break;
	    case '7':
			strcpy(category,"IndianHistory");
			break;
		case '8':
			strcpy(category,"MindTeaser");
			break;
	    default:
		    break;	
	}
    FILE *ft;
    ft=fopen("ScoreList.txt","r+");
    int max=0;
    while(fread(&P,sizeof(P),1,ft)==1)
    {                                    //Search for the highest score in specific category
     if(op!=9)
	 {	
      if(strcmp(P.category,category)==0)
      {
		  
    	  if(P.score>max)
    	  {
    		max=P.score;
    		strcpy(max_name,P.name);
		  }
	  }
     }
     else
     {
     	if(P.score>max)
    	  {
    		max=P.score;
    		strcpy(max_name,P.name);
		  }
	 }
	 
    }
    fclose(ft);
    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t********************************************");
    printf("\n\t\t\t\t%s\t%s\t%d",max_name,category,max);
    printf("\n\t\t\t********************************************");
    printf("\nPress '$'for high score menu");
    printf("\nPress '*'for mainmenu ");
    printf("\nPress anyother key to exit");
    char tr=getch();
    if(tr=='$')
	{
	  goto highscoremenu;	
	}
	else if(tr=='*')
	{
		ch=tr;
	}
	else 
	{
		ch=tr;
	}	    
 }
 
 void Help()
 {                      //Display Help Page
    system("cls");
    FILE *ty;
	char cm;
	ty=fopen("Help.txt","r+");
	while(!feof(ty))
	{
	  cm=fgetc(ty);
	  printf("%c",cm);	
    }	
    fclose(ty);
	printf("\nPress '*' for mainmenu,Press any other key to exit");
	ch=getch();
		
 }
 
 void admin()
 {                                  //ADMIN   INTERFACE
 	int f=1,i=0;
	char c,y;
	int count=0;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\t\t\t********************ADMIN LOGIN*************************");
	tryagain:
	char temp[21];
	char pass[20];
	char check[20];
	printf("\n\t\t\t\tPASSWORD:");
	for(i=0;i<21;i++)               //PAssWOrd Store and check it
	{
		temp[i]=getch();
		if(temp[i]=='\b')
		{
			printf("\b");
			printf(" ");
			printf("\b");
			i--;
			continue;
		}
		if(temp[i]==13)
		{
		temp[i]='\0';
		break;
	    }
		printf("*");
	}
	strcpy(pass,temp);
	FILE *fp;
	fp=fopen("PASSWORD.txt","r+");
	fgets(check,20,fp);
	if(strcmp(pass,check)==0)
	{
		goto mainmenu1;
	}
	else
	{
	 f=0;
	 count++; //COunt No. of TImes user enters Wrong Password
    }
	if(f==0)
	{
		printf("\n\t\t\t\tWRONG PASSWORD ENTERED!!");
		printf("\n\t\t\t\t%d Trails left:",(3-count));
		if(count<3)               //Allow the user to try for only 3 trails
		{
			goto tryagain;
		}
		else{
			printf("\n\t\t\t\tSORRY PLEASE TRY AGAIN....");
			Sleep(2000);                             
			ch='*';                              
			goto doom;                   //Return the user to the main menu if he fail
			                             // to enter password within 3 trails
		}
	    
	}
	fclose(fp);
	mainmenu1:
	system("cls");
    FILE *ty;
	char cm;
	ty=fopen("adminmenu.txt","r+");       //Print admin Menu present in file
	while(!feof(ty))
	{
	  cm=fgetc(ty);
	  printf("%c",cm);	
    }
    fclose(ty);
	printf("\n\t\t\tPlease ENter ur choice:");
	c=getch();
	switch(c)
	{
		case '1':
			remove("ScoreList.txt");
			break;
		case '2':
		    {
		      char re;
			  char another='Y';
              struct Qstn
              {
                  char q[1000];
                  char op1[30];
                  char op2[30];
                  char op3[30];
                  char op4[30];
                  char cor[30];
              }e;
              questionenter:
              FILE *fp;
              int crct=0;
              char file[20];
              fflush(stdin);
              system("cls");
              FILE *ty;
	          char cm;
              ty=fopen("questionenter.txt","r+");
              while(!feof(ty))
	          {
	             cm=fgetc(ty);
	            printf("%c",cm);	
              }
              fclose(ty);
	          re=getche();
	          switch(re)
              {
		        case '1':
			      strcpy(file,"IT.txt");
			      break;
		        case '2':
			      strcpy(file,"Sports.txt");
			      break;
		        case '3':
			      strcpy(file,"GeneralKnowledge.txt");
			      break;
		        case '4':
			      strcpy(file,"Entertainment.txt");
			      break;
		        case '5':
			      strcpy(file,"Geography.txt");
			      break;
		        case '6':
			      strcpy(file,"WorldHistory.txt");
			      break;
	            case '7':
			      strcpy(file,"IndianHistory.txt");
			      break;
		        case '8':
			      strcpy(file,"MindTeaser.txt");
				  break;
				 default:
				   break;  
	          }
              fp=fopen(file,"a+");
              while(toupper(another)=='Y')
              {
    	         fflush(stdin);
    	         system("cls");
    	         printf("\nEnter Question:-");
                 gets(e.q);
                 printf("\n ENter option1:-");
                 gets(e.op1);
                 printf("\n ENter option2:-");
                 gets(e.op2);
                 printf("\n ENter option3:-");
                 gets(e.op3);
                 printf("\n ENter option4:-");
                 gets(e.op4);
                 printf("\nENter the crct option number:");
                 scanf("%d",&crct);
                 if(crct==1)
                 {
                   strcpy(e.cor,e.op1);
                 }
                 else if(crct==2)
                 {
                   strcpy(e.cor,e.op2);
                 }

                 else if(crct==3)
                 {
                   strcpy(e.cor,e.op3);
                 }

                 else if(crct==4)
                 {
                   strcpy(e.cor,e.op4);
                 }
                 fwrite(&e,sizeof(e),1,fp);
                 printf("(Y/N)");
                 another=getche();
              }
              fclose(fp);
			}
			break;
		case '3':
			char tem[11];
			char pass1[10];
			char pass2[10];
			FILE *t3;
			tent3:
			system("cls");
		    printf("\n\n\n\n\n\n\t\t\t\tENTER NEW PASSWORD:");
		    for(i=0;i<11;i++)
         	{
		    tem[i]=getch();
		    if(tem[i]=='\b')
		     {
			 printf("\b");
			 printf(" ");
			 printf("\b");
			 i--;
			 continue;
		     }
		    if(tem[i]==13)
		     {
		      tem[i]='\0';
		      break;
	         }
	        printf("*");
	        }
	        strcpy(pass1,tem);  
			printf("\n\t\t\t\tCONFIRM NEW PASSWORD:"); 
			 for(i=0;i<11;i++)
         	{
		    tem[i]=getch();
		    if(tem[i]=='\b')
		     {
			 printf("\b");
			 printf(" ");
			 printf("\b");
			 i--;
			 continue;
		     }
		    if(tem[i]==13)
		     {
		      tem[i]='\0';
		      break;
	         }
	        printf("*");
	        }
	        strcpy(pass2,tem); 
			
        	if(strcmp(pass1,pass2)==0)
        	{
        		t3=fopen("PASSWORD.txt","w+");
        		fputs(pass2,t3);
        		fclose(t3);
        		printf("\n\t\t\t\tPASSWORD CHANGED SUCCESSFULLY!!");
        		printf("\nPress any key for main menu.....");
        		y=getch();
        		goto mainmenu1;
        		
			}
			else
			{
				printf("\n\n\t\t\t\tPASSWORDS DID NOT MATCH");
				Sleep(3000);
				printf("\n\t\t\t\tPress '*' to go to TRYAGAIN,Press any other key for mainmenu....");
				y=getch();
				if(y=='*')
				 goto tent3;
				else
				 goto mainmenu1;
			}
			break;
		case '4':
			system("cls");
	    	printf("\n\n\n\n\n\n\n\n\n\t\t\t\tLOGGING OUT......");
	    	Sleep(5000);
	    	ch='*';
	    	goto doom;
	    	break;
        case '5':
        	{
        	  questionlist:
              char re;
              FILE *ft;
        	  char file[20];
              fflush(stdin);
              system("cls");
              FILE *ty;
	          char cm;
	          ty=fopen("questionslist.txt","r+");
	          while(!feof(ty))
	          {
	            cm=fgetc(ty);
	            printf("%c",cm);	
              }
              fclose(ty);
	          printf("\n\t\t\tPlease Enter your choice:");
	          re=getche();
	          switch(re)
              {
		        case '1':
			      strcpy(file,"IT.txt");
			      break;
		        case '2':
			      strcpy(file,"Sports.txt");
			      break;
		        case '3':
			      strcpy(file,"GeneralKnowledge.txt");
			      break;
		        case '4':
			      strcpy(file,"Entertainment.txt");
			      break;
		        case '5':
			      strcpy(file,"Geography.txt");
			      break;
		        case '6':
			      strcpy(file,"WorldHistory.txt");
			      break;
	            case '7':
			      strcpy(file,"IndianHistory.txt");
			      break;
		        case '8':
			      strcpy(file,"MindTeaser.txt");
				  break;
				 default:
				   break;  
	          }
	          system("cls");
              ft=fopen(file,"r+");
              int i=0;
              while(fread(&e,sizeof(e),1,ft)==1)
              {
              	i++;
              	printf("\n\n %d.%s\nA.%s\tB.%s\tC.%s\tD.%s\nCorrect answer:-%s",i,e.q,e.op1,e.op2,e.op3,e.op4,e.cor);
			  }
			  fclose(ft);
			  printf("\nPress '$'for Questions List Menu");
			  printf("\nPress '#'for Admin Menu");
			  printf("\nPress any other Key to exit");
			  char t=getch();
			  if(t=='$')
			  {
			  	goto questionlist;
			   } 
			   else if(t=='#')
			   {
			   	goto mainmenu1;
			   }
			   else
			   {
			     ch='/';
			     goto doom;
			   }
			  
	     	}
	     	break;
			  
		    	    	
	    case '6':
	    	ch='/';
	    	goto doom;
	    	break;
			
	}
	doom:
		printf(" ");
 }
 
