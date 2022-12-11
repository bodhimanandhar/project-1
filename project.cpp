#include <stdio.h>
#include<time.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
int addstudent();
int edit();
int search();
int search2();
int search3();
int view();
int signin();
int signup();
int display1();
int display2();
void del();
 typedef struct student{
	char fname[10];
	char lname[10];
	int roll;
	char add[10];
	int grade;
	int y,m,d;
	int h,mn,s;
} students;
typedef struct login{
	char ui[20];
    char gen[10];
	char name[10],password[20];
	char surname[10],mobile[10];
}logins;
int main(){ 

		int a;
  		a=display1();
 		
	 switch(a){
	 		case 1:
	 			signin();
	 			break;
	 		case 2:
	 			signup();
	 			break;
	 		
			 
	};
  
	
	
	
return 0;
	
	
}

int addstudent(){int n=0;
	char a='a';
	FILE *fp;
	students info;
	struct tm tm;
              time_t t;
			t=time(NULL);
			tm= *localtime(&t);
	
	
		printf("Add student info\n");
		fp=fopen("Std.txt","a+");
		printf("Enter first name\t");
		scanf("%s",info.fname);
		printf("\nEnter last name\t");
		scanf("%s",info.lname);
		printf("\nEnter roll no\t");
		scanf("%d",&info.roll);
		printf("\nEnter grade\t");
		scanf("%d",&info.grade);
		printf("\nEnter address\t");
		scanf("%s",info.add);
		info.y=tm.tm_year + 1900;
		info.m=tm.tm_mon + 1;
		info.d=tm.tm_mday;
		info.h=tm.tm_hour;
		info.mn=tm.tm_min;
		info.s=tm.tm_sec;
		if(fp==NULL){
			fprintf(stderr,"Cannot open\n");}
	 else{ printf("Record stored");
	}
	fwrite(&info,sizeof(struct student),1,fp);
	fclose(fp);
	n=n+1;
	printf("Do yo want to record another data (y/n)?\n");
	scanf("%s",&a);
	if(a=='y'||a=='Y'){addstudent();
	}
	else{display2();
	}
	

     display2();
	  printf("/n/n/n/n/n/n");
	  system("cls");}
     
     int view(){ system("cls");
     	FILE *fp;
     	struct student info;
     	fp=fopen("std.txt","r");
     	if (fp==NULL){
		 printf("Can`t open");}
		 else { printf("Records\n");
		 }
		 printf("Student name	 	Grade	 Roll No	Address		Last Edited on\n");
		 
		 while(fread(&info,sizeof(struct student),1,fp)==1){
		 	
		 	printf("%-15s %-20s %-10d %-10d %-10s %d:%d:%d:%d:%d:%d",info.fname,info.lname,info.grade,info.roll,info.add,info.y,info.m,info.d,info.h,info.mn,info.s);
			 printf("\n");
}
		  
		 fclose(fp);
	display2();
	 printf("/n/n/n/n/n/n");
	  }
	
	
	int search2(){	FILE *fp;
     	struct student info;
     	int r,x=0;
     	char a[10];
     	char b;
        char *ret;
     	fp=fopen("std.txt","r+");
     	printf("Enter the character ");
     	scanf("%s",&a);
     	//ret=strstr(info[1].fname,a[10]);
     	printf("Student name	 	Grade			Roll No			Address			Last Edited on\n");
     	while(fread(&info,sizeof(struct student),1,fp)){
     		   		
				ret=strstr(info.fname,a);	if(strcmp(info.fname,a)==0||strcmp(info.lname,a)==0){ x=1;
				
		 			printf("Student name :%s %s\tRollno: %d",info.fname,info.lname,info.roll);
		 			printf("\nClass:%d\nAddress:%s \t ",info.grade,info.add);
					printf("Edited on: %d/%d/%d %d:%d:%d\n", info.y,info.m,info.d,info.h,info.mn,info.s);}
		 			 
		 			
		 			}
		 			if(x==0){printf("Records not found");
			}
		
	 fclose(fp);
	 display2();
	  printf("/n/n/n/n/n/n");
	   system("cls");}
	  
	
     int search(){
     	FILE *fp;
     	struct student info;
     	int r,x=0;
     	int a=0;
        
     	fp=fopen("std.txt","r");
     	printf("Search student\n");
  		
					printf("Enter roll no ");
     				scanf("%d",&r);
     				while(fread(&info,sizeof(struct student),1,fp)){
     		   		
						if(info.roll==r){ x=1;
				
		 			printf("Student name :%s %s\tRollno: %d",info.fname,info.lname,info.roll);
		 			printf("\nClass:%d\nAddress:%s \t ",info.grade,info.add);
					printf("Edited on: %d/%d/%d %d:%d:%d\n", info.y,info.m,info.d,info.h,info.mn,info.s);}
		 			 
		 			
		 			}
		 			if(x==0){printf("Records not found");
			}
	 fclose(fp);
 display2();
  printf("/n/n/n/n/n/n");
   system("cls");}
	 
	 
	 	int edit(){
	 	 
      FILE *fp, *fp1;
      int x=0;
      char stFname[10],stLname[10];
      	struct student info;
      	struct tm tm;
              time_t t;
			t=time(NULL);
			tm= *localtime(&t);
				
     int n=0;
       
    int roll_no,grade,found=0;
    
       printf("Edit Student Record");
    fp=fopen("std.txt","rb+");
    
    if(fp==NULL){
         fprintf(stderr,"can't open file\n");
         
      }
      printf("\nEnter name of the student\n");
      scanf("%s",&stFname);
      printf("Enter last name of the student\n");
      scanf("%s",&stLname);
	  while(fread(&info,sizeof(student),1,fp) == 1){
	  	if(strcmp(stFname,info.fname) == 0 && strcmp(stLname,info.lname) ==0){x=1;
	  		printf("Enter first name\n");
	  		scanf("%s",&info.fname);
	  		printf("Enter last name\n");
	  		scanf("%s",&info.lname);
	  		printf("Enter grade\n");
	  		scanf("%d",&info.grade);
	  		printf("Enter roll no\n");
	  		scanf("%d",&info.roll);
	  		printf("Enter address\n");
	  		scanf("%s",&info.add);
	  		 fseek(fp ,-sizeof(student),SEEK_CUR);
	  		  fwrite(&info,sizeof(student),1,fp);
	  		  break;
		  }
	
      	
	  }
	  	  if(x==0){printf("Data not found in record\n");
		  edit();
		  }
		  else printf("Edited successfully\n");
	  fclose(fp);

	 			
     display2();
	  printf("/n/n/n/n/n/n");
	   system("cls");}
	int signin()
{			 char user[20];
			int i;
			FILE *fi,*fp;
			login info;
				char temp[20],temp2;
				char name[10],password[20],passnu[8];
		     
			printf("ENTER YOUR USER ID:\n");
		
			scanf("%s",user);
		
			fi=fopen("id.txt","r+");
			fp=fopen("id.txt","rb");
			if(fi==NULL)
			{
				printf("Enter right user id\n");
			}
			else
			{
		                                                                                                                 // \t1\t%s\t%s\t%s\t%s",credit,cardmon,cardyear,cvv)
			printf("ENTER YOUR PASSWORD:\n");
			  while(1)
   				{
				temp2=getch();
				if(temp2==13)
				{
				password[i]='\0';
				break;
					}
				else if(temp2==8)
				{
					if(i>0)
					{
						i--;
					printf("\b \b");
						}
					}
					else if(temp2==9||temp2==32)
						{
						continue;
								}
					else
					{
						password[i]=temp2;
						i++;
					printf("*");
						}
   						}
   						
	 	}//while(fread(&info ,sizeof( logins),1,fp)==1){
     		  // 		printf("%s",info.password);
			//int ret =strcmp(password,'password');
		 //if(ret=0){
		 
		 int ret;
		 ret=strcmp(password,info.password);
	   if(ret==-1){display2();
	    printf("/n/n/n/n/n/n");}
		 
  
	fclose(fi);
	fclose(fp);}

	int signup(){
         FILE *ch1;
			logins info;
			char ui1[10];
			int ab;
	ch1= fopen("id.txt","a+");

	
		printf("ENTER USER ID ");
		  scanf("%s",&info.ui);	
	  
	printf("personal detail information security additional");
		
	
	printf(" entering your data:\n");

		printf("ENTER YOUR FIRST NAME ");
		scanf("%s",&info.name);
		printf("ENTER YOUR LAST NAME ");
		scanf("%s",&info.surname);
		printf("ENTER GENDER \n ");
		scanf("%s",&info.gen);
		mobile: printf("ENTER YOUR MOBILE NUMBER");
		scanf("%s",&info.mobile);
		ab=strlen(info.mobile);
		if(ab==10)
		{
		  fwrite(&info,sizeof(struct login),1,ch1);
		}
		else
		{
			printf("Enter correct mobile number: ");
            signup();	
		}
		printf("enter password\n");
		scanf("%s",&info.password);
		fwrite(&info,sizeof(struct login),1,ch1);
		fclose(ch1);
		
	display2();
	 printf("/n/n/n/n/n/n");
	  system("cls");} 


int display1(){ int a;
					printf("Student Data System\n");
	printf("\n*****************************\n");
	printf("1.sign in\n\n");
	 scanf("%d",&a);
	 return a;
	 };
		 	
	

	 int display2(){
	 				printf("\nStudent Data System\n");
			printf("\n*****************************\n");
	 	
	 			int x;			   
       			printf("Choose a function to operate\n");
	 		
				
				printf("3)Add student\n4)Edit\n5)View\n6)Search by rollno\n7)Search by Name\n8)Search by character\n9) Delete\n10) Sign up \n");
				scanf("%d",&x);			
					
				switch(x){
				case 3:
	      		 
				addstudent();
				break;
	       	case 4:
	       		edit();
	       		break;
	      	 case 5:
	       		view();
	       		break;
	        case 6:
		   		search();
		  		 break;  	
	        case 7 :
	        	search2();
	        	break;
	        	case 8:
	        	search3();
	        	break;
	         case 9:
	        	del();
	        	break;
	        	case 10:
	        		signup();
	        		break;
	    	default:
	    	break;		
					
					
				};
	 }			
	 			
int search3(){	FILE *fp;
     	struct student info;
     	int r,x=0;
     	char a[10];
     	char b;
        char *ret,*ter;
     	fp=fopen("std.txt","r+");
     	printf("Enter the character ");
     	scanf("%s",&a);
     	//ret=strstr(info[1].fname,a[10]);
     	while(fread(&info,sizeof(struct student),1,fp)){
     		   		
				ret=strstr(info.fname,a);
				ter=strstr(info.lname,a);
				if(ret||ter){ x=1;
				
		 			printf("Student name :%s %s\tRollno: %d",info.fname,info.lname,info.roll);
		 			printf("\nClass:%d\nAddress:%s \t ",info.grade,info.add);
					printf("Edited on: %d/%d/%d %d:%d:%d\n", info.y,info.m,info.d,info.h,info.mn,info.s);}
		 			 
		 			
		 			}
		 			if(ret==NULL||ter==NULL){printf("Records not found");
			}
	 fclose(fp);
	 display2();
	 printf("/n/n/n/n/n/n");
	  system("cls");}
	 
	 
	 
	 			
		void del(){
      struct student info;
      FILE *fp, *fp1;
     
       
    int roll_no,grade,found=0;
    
       printf("DELETE STUDENTS RECORD");
    fp=fopen("std.txt","r+");
    fp1=fopen("temp.txt","w+");
    printf("\nEnter the roll no : ");
    scanf("%d",&roll_no);
    printf("\nEnter grade");
    scanf("%d",&grade);
    if(fp==NULL){
         fprintf(stderr,"can't open file\n");
         
      }
    
    while(fread(&info,sizeof(struct student),1,fp)){
        if(info.roll == roll_no&&info.grade == grade){
          
            found=1;
        
        }else{
           fwrite(&info,sizeof(struct student),1,fp1);
        }
  
    }
     fclose(fp);
     fclose(fp1);

    if(!found){
          printf("\n\t\t\t\tRecord not found\n");
        }
      if(found){ 
    remove("std.txt");
        rename("temp.txt","std.txt");
        
        printf("\n\t\t\t\tRecord deleted succesfully\n");
        }
	 			
	display2();	
	printf("/n/n/n/n/n");
	 system("cls");}
		 
	 
     
     
     
