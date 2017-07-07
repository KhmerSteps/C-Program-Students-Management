#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
#include<dir.h>
#include<string.h>
#include<stdlib.h>
#include<alloc.h>
#include<ctype.h>
#define log "c:/log/users/user.txt"
#define ver_log "c:/ass/fix/ver.txt"

char local[20]= "test.txt" ;
char localcpy[20]="temp.txt" ;
	struct stu{
	char id[10];
	char name[20];
	char sex[7];
	char ngai[5];
	char khae[5];
	char jnam[5];
	char subjects[20];
	char room[3];
	char year[7];
};
	struct sub{
	char id[10];
	char title[20];
	char year[7];
};
struct vertify{
	char name[20],pass[20];
};
struct user{
	char name[20],pass[20];
};                  int action=0;

	stu p,p1,p2;
	sub s;
	FILE *fp,*fp1,*fp2;
int a,j,b,l,leng[8];char k,c,d,ch,key;
void show_time();
void ver_comp();
void reg_user();
void login_user();
void clear(int a1,int a2,int b1,int b2);
void start();
void drop(char *d1,char *d2,char *d3,char *d4,int x,int y1,int y2,int y3,int y4);
void background(int,int,int,int,int color);
void loading();
void TABLE(int,int,int,int,int,int);
void ARROW_UP();
void ARROW_DOWN();
void SHOW_ARROW_DOWN(char *c1,char *c2,char *c3,char *c4,int x);
void SHOW_ARROW_UP();
void menu();
void student();
void score();
void subject();
void about();

void sort(){    int i,k,n;
		for(i=0;i<n;i++){
			fseek(fp,i * sizeof(stu), SEEK_SET);
			fread(&p1,sizeof(stu),1,fp);
			for(j=i+1;j<n;j++){
				fseek(fp, j *sizeof(stu),SEEK_SET);
				fread(&p2,sizeof(stu),1,fp);
				if(strcmp(p1.name,p2.name)>0){

				rewind(fp);
				fp1=fopen("temp.txt","wb");
				for(k=0;k<n;k++){
				fread(&p,sizeof(stu),1,fp);
				if(k==i)
					p=p2;
				if(k==j)
					p=p1;

				fwrite(&p,sizeof(stu),1,fp1);
				}

				fclose(fp); fclose(fp1);
				remove(local);
				rename(localcpy,local);
				fp=fopen(local,"rb");
				p1=p2;

				}


			}
		}
		background(17,63,10,14,2);
		TABLE(17,63,10,14,15,2);
		gotoxy(31,12);textcolor(15);cprintf("Sort Completed"); getch();



		}
void Show_Edit(){
			if(l<=0)l=6;
			if(l>=7)l=1;
			switch(l){

			  case 1:gotoxy(9,8);textcolor(15);textbackground(2);cprintf("      NAME      ");break;
			  case 2:gotoxy(9,10);textcolor(15);textbackground(2);cprintf("      SEX       "); break;
			  case 3:gotoxy(9,12);textcolor(15);textbackground(2);cprintf("     D-O-B      ");break;
			  case 4:gotoxy(9,14);textcolor(15);textbackground(2);cprintf("    SUBJECT     ");break;
			  case 5:gotoxy(9,16);textcolor(15);textbackground(2);cprintf("     CLASS      ");break;
			  case 6:gotoxy(9,18);textcolor(15);textbackground(2);cprintf("     YEAR       ");;break;

			}}

void input(char *st,int length){
      char ch;
      int leng=0,i=0;
      do{
		ch=getch();
		if(ch>='0'&&ch<='9'|| ch==8){
			if(ch!=8){
				st[i]=ch;i++;
				leng=strlen(st);
					if(leng<length)
						printf("%c",ch);
					else{
						i--;
						st[i]='\0';
					    }
			}else{
				if(i>0){
					i--;
					st[i]='\0';
					printf("\b \b");
					}
				}
						}
      }while(ch!=13||i==0);

}

void input2(char *st,int length){
      char ch;int leng=0,i=0;
      do{
	ch=getch();
	if(isalpha(ch)||isdigit(ch)||ch==32|| ch==8){

	if(ch!=8){
	    st[i]=ch;i++;
	    leng=strlen(st);
	    if(leng<length)
	    printf("%c",ch);
	    else{
	    i--;
	    st[i]='\0';
	    }
	}else{
	if(i>0){
	i--;
	st[i]='\0';
	printf("\b \b");
	}
	}
	}
      }while(ch!=13||i==0);

}
void input3(char *st,int length){
      char ch;
      int leng=0,i=0;
      do{
		ch=getch();
		if(ch>='a'&&ch<='z'||isdigit(ch)||ch==32|| ch==8){
			if(ch!=8){
				st[i]=ch;i++;
				leng=strlen(st);
					if(leng<length)
						printf("*",ch);
					else{
						i--;
						st[i]='\0';
					    }
			}else{
				if(i>0){
					i--;
					st[i]='\0';
					printf("\b \b");
					}
				}
						}
						if(ch==27)break;
      }while(ch!=13);

}


void check(){ user u; char ch;
	     action=1;
 clrscr();
	    FILE *check;
	    check=fopen(log,"r+b");
	    if(check==NULL){
		  fclose(check);
		 reg_user();
		 }else{
		 fclose(check);
		 ver_comp();
		 clrscr();
		 login_user();
		 }

}

void reg_user(){  char users[20]="",ch, pass1[20]="" ,pass2[20]="", pass_again[20];;
		  vertify v;
		  user u;
		  FILE *reg;
		  FILE *fv;
		  mkdir("c:/log");
		  mkdir("c:/log/users");
		  mkdir("c:/ass");
		  mkdir("c:/ass/fix");
    again2:		  textbackground(15);
		  clrscr();
		  _setcursortype(2);
		  background(15,65,5,17,1);
		  background(34,54,9,9,2);
		  background(34,54,11,11,2);
		  background(34,54,13,13,2);
		  TABLE(15,65,5,17,15,1);
		  gotoxy(32,5);textcolor(15);cprintf("REGISTER NEW USER");
		  gotoxy(24,9);textcolor(15);cprintf("USERNAME: ");
		  gotoxy(24,11);textcolor(15);cprintf("PASSWORD: ");
		  gotoxy(16,13);textcolor(15);cprintf("CONFIRM PASSWORD: ");
		  gotoxy(35,9);input2(users,15);

		  gotoxy(35,11);input3(pass1,15);
		  gotoxy(35,13);input3(pass2,15);
		  if(strcmp(pass1,pass2)!=0){
		  clear(21,50,20,20);gotoxy(30,20);
		  textcolor(BLINK +15);  _setcursortype(0);
		  cprintf(" PASSWORD NOT MATCH. ");
		  textcolor(WHITE);
		  gotoxy(20,21);cprintf(" Press anykey to start again or Esc to exit ");
		 ch=getch();
		 if(ch==27){exit(0);}else{goto again2;}
		  }
		  else{

		  clrscr();
		  _setcursortype(0);
		  gotoxy(28,12);
		  textcolor(10);
		  cprintf("REGISTER SUCCESSFULLY");
		  gotoxy(1,25);printf("ESC TO EXIT");
		  delay(2000);
		  strcpy(u.name,users);strcpy(u.pass,pass1);
		  }
		  //vertify file
		  strcpy(v.name,u.name);strcpy(v.pass,u.pass);
		  fv=fopen(ver_log,"w+b");
		  fwrite(&v,sizeof(vertify),1,fv);
		  fclose(fv);
		  //end vertify file



		  reg=fopen(log,"w+b");
		  fwrite(&u,sizeof(user),1,reg);
		  fclose(reg);

}
void ver_comp(){  user u; vertify v;
		char ch, u_name[20],u_pass[20],v_name[20],v_pass[20];
		  FILE *comp_u,*comp_v;
		  comp_u=fopen(log,"r+b");
		  comp_v=fopen(ver_log,"r+b");
		 while(fread(&u,sizeof(user),1,comp_u)==1){strcpy(u_name,u.name);strcpy(u_pass,v.pass);}
		 while(fread(&v,sizeof(vertify),1,comp_v)==1){strcpy(v_name,v.name);strcpy(v_pass,v.pass);}
		 if(strcmp(v_name,u_name)==0){
		 _setcursortype(0);
			if(strcmp(v_pass,v_pass)==0){
			textbackground(15);
			clrscr();
			gotoxy(18,13);
			textcolor(15);
			cprintf("Checking...!!! User Info, Please Wait 2 sec...");
			delay(2000);
			}else{
			fclose(comp_u);fclose(comp_v);
			gotoxy(2,23);
			textcolor(4);
			cprintf("Error_User Info! User File Was Crash.. Please contact delevoper.");
			ch=getch();
			if(ch!=0){exit(0);}}
		  }else{
		  fclose(comp_u);fclose(comp_v);
		  gotoxy(2,23);
		  textcolor(4);
		  cprintf("Error_User Info! User File Was Crash.. Please contact delevoper.");
		  ch=getch();
		  if(ch==13) exit(0);
}		  }
void login_user(){ char g_name[20],g_pass[20],l_name[20],l_pass[20];
		  user u; char ch;
		FILE *flog;
		flog=fopen(log,"r+b");
		while(fread(&u,sizeof(user),1,flog)==1){
		strcpy(l_name,u.name); strcpy(l_pass,u.pass);
		}
     again:     char name[20]="";char pas[20]="";
		textbackground(15);
		clrscr();
		background(15,65,5,17,1);
		background(30,50,9,9,2);
		background(30,50,11,11,2);
		TABLE(15,65,5,17,15,1);
		gotoxy(32,5);
		textcolor(15);
		cprintf("LOGIN USER INFO");
		gotoxy(20,9);
		textcolor(15);
		cprintf("Username : ");
		gotoxy(20,11);textcolor(15);
		cprintf("Password : ");
		_setcursortype(2);
		gotoxy(32,9);input2(name,15);strcpy(g_name,name);
		gotoxy(32,11);input3(pas,15);strcpy(g_pass,pas);
		if(strcmp(l_name,g_name)==0&&strcmp(l_pass,g_pass)==0){

			_setcursortype(0);
			gotoxy(25,23);textbackground(15);textcolor(BLINK +4);cprintf("LOGIN SUCCESSFULY! WAIT 2 SECOND...");
			delay(2000);



		}else{  textbackground(15);
			clrscr();
			_setcursortype(0);
			background(15,65,5,17,1);
			TABLE(15,65,5,17,15,1);
			gotoxy(28,5);textbackground(1);textcolor(15);cprintf(" USERNAME IS NOT CORRECT ");
			 gotoxy(33,9);textbackground(15);textcolor(0);cprintf("   TRY AGAIN   ");
			 gotoxy(33,11);textbackground(15);textcolor(0);cprintf("   REGISTEER   ");
			 gotoxy(33,13);textbackground(15);textcolor(0);cprintf("      EXIT     ");
			 int h;
			 do{

			 ch=getch();
			 if(ch==80)h++;
			 if(ch==72)h--;
			 gotoxy(33,9);textbackground(15);textcolor(0);cprintf("   TRY AGAIN   ");
			 gotoxy(33,11);textbackground(15);textcolor(0);cprintf("   REGISTEER   ");
			 gotoxy(33,13);textbackground(15);textcolor(0);cprintf("      EXIT     ");

			 if(h<1)h=3;
			 if(h>3)h=1;
			 switch(h){
			 case 1:gotoxy(33,9);textbackground(2);textcolor(15);cprintf("   TRY AGAIN   ");break;
			 case 2:gotoxy(33,11);textbackground(2);textcolor(15);cprintf("   REGISTEER   ");break;
			 case 3:gotoxy(33,13);textbackground(2);textcolor(15);cprintf("      EXIT     ");break;
			 }
			 if(h==1&&ch==13)goto again;
			 if(h==2&&ch==13)reg_user();
			 if(h==3&&ch==13)exit(0);
			 }while(ch!=27&&ch!=13);

		}
}
void change_user(){ user u;
		char ch_pass[20],cg_pass[20],ch;
		    vertify v;
		  FILE *check1;
		  FILE *change;
		  FILE *ch_ver;
		  check1=fopen(log,"r+b");
		  while(fread(&u,sizeof(user),1,check1)==1){
			strcpy(ch_pass,u.pass);
						}

		  char new1[20]="",new2[20]="";
		  textbackground(15);
		  clrscr();
		  _setcursortype(2);
		  background(15,65,5,17,1);
		  background(34,54,9,9,2);
		  background(34,54,11,11,2);
		  background(34,54,13,13,2);
		  TABLE(15,65,5,17,15,1);
		  gotoxy(32,5);
		  textcolor(15);
		  cprintf("CHANGE USER INFO");
		  gotoxy(17,9);textcolor(15);cprintf("Old Password ");


			fclose(check1);
			gotoxy(17,11);textcolor(15);cprintf("New username ");
			gotoxy(17,13);textcolor(15);cprintf("New password ");
		   old:	char old[20]="";
			gotoxy(35,9);input3(old,20);
			if(strcmp(old,ch_pass)==0)strcpy(cg_pass,old);
			else {
				gotoxy(20,22);
				printf("Old Password is not correct,Try Again");
				clear(20,55,22,22);
				goto old;
			}
			gotoxy(35,11);input2(new1,20);strcpy(u.name,new1);
			gotoxy(35,13);input3(new2,20);strcpy(u.pass,new2);
			strcpy(v.name,u.name);strcpy(v.pass,u.pass);
			change=fopen(log,"w+b");
			ch_ver=fopen(ver_log,"w+b");
			fwrite(&u,sizeof(user),1,change);
			fwrite(&v,sizeof(vertify),1,ch_ver);
			fclose(change);
			fclose(ch_ver);
			}


 void search(){
	 char q[20]="";

	clrscr();start();
	clear(2,79,3,22);
	background(2,79,3,22,3);
	TABLE(2,79,3,22,0,15);

	gotoxy(20,13);
	_setcursortype(2);
	printf("Input ID :");
	textcolor(15);
	background(31,51,13,13,15);
	gotoxy(32,13);
	input(q,20);
		b=0;
		rewind(fp);
		fp=fopen(local,"rb");
		while(fread(&p,sizeof(stu),1,fp)==1){
			if(strcmp(p.id,q)==0) b=1;
			else b=0;


		_setcursortype(0);
		if(b==0){
		background(17,63,10,14,2);
		TABLE(17,63,10,14,15,2);
		gotoxy(31,12);textcolor(15);cprintf("DATA NOT FOUND");}
		else	{
		textbackground(1);
		clrscr();
		start();
		background(2,79,5,22,3);
		TABLE(2,79,3,5,0,15);
		background(2,79,4,4,2);
		//background(2,79,3,3,15);
		TABLE(2,9,3,22,0,15);
		TABLE(9,26,3,22,0,15);
		TABLE(26,35,3,22,0,15);
		TABLE(35,48,3,22,0,15);
		TABLE(48,63,3,22,0,15);
		TABLE(63,71,3,22,0,15);
		TABLE(71,79,3,22,0,15);
		TABLE(2,79,3,22,0,15);
		gotoxy(33,2);printf(" SEARCHED SUCCESSE ");
		gotoxy(5,4); printf("ID");
		gotoxy(16,4);printf("NAME");
		gotoxy(29,4);printf("SEX");
		gotoxy(39,4);printf("D-O-B");
		gotoxy(52,4);printf("SUBJECT");
		gotoxy(65,4);printf("CLASS");
		gotoxy(73,4);printf("GRADE");

		int Y=6,i=0;


		gotoxy(4,Y+i); printf("%s\n",p.id);
		gotoxy(10,Y+i);printf("%s\n",p.name);
		gotoxy(28,Y+i);printf("%s\n",p.sex);
		gotoxy(37,Y+i);printf("%s\n",p.ngai);
		gotoxy(39,Y+i);printf("/%s\n",p.khae);
		gotoxy(42,Y+i);printf("/%s\n",p.jnam);
		gotoxy(49,Y+i);printf("%s\n",p.subjects);
		gotoxy(66,Y+i);printf("%s\n",p.room);
		gotoxy(73,Y+i);printf("%s\n",p.year);
		i++;}}
		getch();textbackground(1);clrscr();start();drop(" REGISTER"," SEARCH"," SETTING"," ABOUT ",2,3,4,5,7);
	SHOW_ARROW_DOWN("  REGISTER ","  SEARCH   ","  SETTING  ","  ABOUT    ",2);

	 }


void del(){

do{
	//Delete edit
	char x[20]="";
	textbackground(1);
	clrscr();start();
	clear(2,79,3,22);
	background(2,79,3,22,3);
	TABLE(2,79,3,22,0,15);

	gotoxy(20,13);
	_setcursortype(2);
	textcolor(15);
	printf("INPUT ID :");
	background(31,51,13,13,15);
	gotoxy(32,13);
	input(x,20);
		b=0;
		rewind(fp);
		fp1=fopen(localcpy,"wb");
		while(fread(&p,sizeof(stu),1,fp)==1){
			if(strcmp(p.id,x)==0) b=1;
			else fwrite(&p,sizeof(stu),1,fp1);
			}
		fclose(fp1);fclose(fp); remove(local);
		rename(localcpy,local);

		fp = fopen(local,"a+b");
		_setcursortype(0);
		if(b==0){
		background(17,63,10,14,2);
		TABLE(17,63,10,14,15,2);
		gotoxy(31,12);textcolor(15);cprintf("DELETE NOT COMPLETE");}
		else	{
		background(17,63,10,14,2);
		TABLE(17,63,10,14,15,2);
		gotoxy(33,12);textcolor(15);cprintf("DELETE COMPLETED");}
	       ch=getch();}while(ch!=27);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void main(){
	if(action==0){
	    check();}
	    user u; char ch;
	    FILE *name;
	    textbackground(1);
	    clrscr();
	    name=fopen(log,"r+b");
	    while(fread(&u,sizeof(user),1,name)==1){
	    background(17,63,10,14,2);
	    TABLE(17,63,10,14,15,2);
	    gotoxy(22,12);
	    textcolor(15);
	    cprintf("HELLO ! %s Welcome To System",u.name);
	    delay(3000);
	    }fclose(name);
		//loading();
		textbackground(1);
		_setcursortype(0);
		clrscr();
		start();
		do{
			c=getch();
			textbackground(0);
			ARROW_UP();
			start();
			if(a==1&&c==13) menu();
			if(a==2&&c==13) student();
			if(a==3&&c==13) subject();
			if(a==4&&c==13) score();
			if(a==5&&c==13) break;
		   }while(1);  }
//////////////////////////////////////////////////////////////////////////////////////////
void show_time(){ int LEN=15;
		  char buf[15];
		  time_t curtime;
		  struct tm *loc_time;
		  curtime=time(NULL);
		  loc_time=localtime(&curtime);
		  strftime(buf,LEN,"³ %I:%M %p ³",loc_time);
		  fputs(buf,stdout);

}
    void ARROW_UP(){
	if(c==77) a++;
	if(c==75) a--;
}

    void ARROW_DOWN(){
	d=getch();
	if(d==80) b++;
	if(d==72) b--;
}

    //START SHOW ARROW ON MAIN MENU
    void SHOW_ARROW_UP(){
	if(a<=0) a=5;
	if(a>=6) a=1;
    switch(a)
    {
	case 1 :gotoxy(1,1);textbackground(1);textcolor(15);cprintf(" ðð ");break;
	case 2 :gotoxy(7,1);textbackground(1);textcolor(15);cprintf(" STUDENT ");break;
	case 3 :gotoxy(16,1);textbackground(1);textcolor(15);cprintf(" SUBJECT ");break;
	case 4 :gotoxy(25,1);textbackground(1);textcolor(15);cprintf(" SCORE ");break;
	case 5 :gotoxy(32,1);textbackground(1);textcolor(15);cprintf(" EXIT ");break;
    }
}
	//END SHOW ARROW ON MAIN MENU

	//START ARROW OF DROP DOWN
	void SHOW_ARROW_DOWN(char *c1,char *c2,char *c3,char *c4,int x)
{
    if(b<=0) b=4;
    if(b>=5) b=1;
    switch(b)
    {
	case 1 : gotoxy(x,3);textbackground(1);textcolor(15);cprintf("%s",c1); break;
	case 2 : gotoxy(x,4);textbackground(1);textcolor(15);cprintf("%s",c2); break;
	case 3 : gotoxy(x,5);textbackground(1);textcolor(15);cprintf("%s",c3); break;
	case 4 : gotoxy(x,7);textbackground(1);textcolor(15);cprintf("%s",c4); break;

    }
	  }
	//END ARROW OF DROP DOWN




	//START FOR USING MAIN PROGRAMS
	void start(){    user u;
	FILE *show;
	show=fopen(log,"r+b");
	textbackground(1);
	background(2,79,3,22,0);
	background(1,80,1,1,15);
	TABLE(1,80,2,23,15,1);
	//SHOW INFORMATION UNDER
	 //SHOW INFORMATION UNDER

	//START SHOW MAIN MENU
	gotoxy(2,1);textbackground(15);textcolor(0);cprintf("ðð");
	gotoxy(8,1);textbackground(15);textcolor(0);cprintf("STUDENT");
	gotoxy(17,1);textbackground(15);textcolor(0);cprintf("SUBJECT");
	gotoxy(26,1);textbackground(15);textcolor(0);cprintf("SCORE");
	gotoxy(33,1);textbackground(15);textcolor(0);cprintf("EXIT");
	while(fread(&u,sizeof(user),1,show)==1){
	gotoxy(55,1);printf("³ %s ",u.name);gotoxy(69,1);show_time();}
	fclose(show);
	//END SHOW MAIN MENU
	SHOW_ARROW_UP();
	}
	//END FOR USING MAIN PROGRAMS

	/*START SHOW DROP DOWN ;
	char *d1,char *d2,char *d3,char *d4 using for input value char.
	int x,int y1,int y2,int y3,int y4 using for input gotoxy()   */
    void drop(char *d1,char *d2,char *d3,char *d4,int x,int y1,int y2,int y3,int y4){
		background(x-1,x+11,y1-1,y4+1,15);
		TABLE(x-1,x+11,y1-1,y4+1,0,15);
		gotoxy(x,y1);textbackground(15);textcolor(0);cprintf("%s",d1);
		gotoxy(x,y2);textbackground(15);textcolor(0);cprintf("%s",d2);
		gotoxy(x,y3);textbackground(15);textcolor(0);cprintf("%s",d3);
		gotoxy(x,y4);textbackground(15);textcolor(0);cprintf("%s",d4);
	}
	//START SHOW DROP DOWN

	//start fuction menu
	void menu(){
	drop(" REGISTER"," SEARCH"," SETTING"," ABOUT ",2,3,4,5,7);
	SHOW_ARROW_DOWN("  REGISTER ","  SEARCH   ","  SETTING  ","  ABOUT    ",2);
	do{
	ARROW_DOWN();

	drop(" REGISTER"," SEARCH"," SETTING"," ABOUT ",2,3,4,5,7);
	SHOW_ARROW_DOWN("  REGISTER ","  SEARCH   ","  SETTING  ","  ABOUT    ",2);
	if(b==1&&d==13) reg_user();
	if(b==2&&d==13) search();
	if(b==3&&d==13) break;
	if(b==4&&d==13) about();


	}while(d!=27);textbackground(1);start();}
	void student(){
	int leng[8];

	fp=fopen(local,"a+b");

		char ch,st;int i,j,n=0;


	drop(" INSERT"," VIEW"," EDIT"," DELETE",7,3,4,5,7);
	SHOW_ARROW_DOWN("  INSERT   ","  VIEW     ","  EDIT     ","  DELETE   ",7);
	do{
	ARROW_DOWN();
	drop(" INSERT"," VIEW"," EDIT"," DELETE",7,3,4,5,7);
	SHOW_ARROW_DOWN("  INSERT   ","  VIEW     ","  EDIT     ","  DELETE   ",7);
	if(b==1&&d==13){
	//start input code
		do{

			background(2,79,3,22,3);
			TABLE(2,79,3,22,0,15);
			textcolor(15);
			gotoxy(26,2);
			printf(" INSERT INFORMATION STUDENT");
			background(18,38,8,8,1);
			background(18,38,11,11,1);
			background(18,38,14,14,1);
			background(30,50,17,17,1);
			background(50,70,8,8,1);
			background(50,54,11,11,1);
			background(56,60,11,11,1);
			background(62,68,11,11,1);
			background(50,70,14,14,1);



			gotoxy(10,8);
			printf("ID");
			gotoxy(42,8);
			printf("NAME");
			gotoxy(10,11);
			printf("SEX");
			gotoxy(42,11);
			printf("D,O,B");
			gotoxy(51,11);
			printf("dd    mm    yyyy");
			gotoxy(10,14);
			printf("SUBJECT");
			gotoxy(42,14);
			printf("CLASS");
			gotoxy(23,17);
			printf("GRADE");
			_setcursortype(2);
			long com;
		id:
			char num[20]="";
			gotoxy(19,8);
			input(num,20);
			_setcursortype(2);
			clear(30,65,21,21);
			leng[0]=strlen(num);
			if(leng[0]!=4){
				gotoxy(30,21);
				printf("We Allow Only 4 Digit, Ex: 0001");
				clear(18,37,8,8);
				goto id;
			}
			else
				strcpy(p.id,num);

	     name:      char nam[20]="";
				gotoxy(51,8);
				input2(nam,19);
				clear(30,65,21,21);
				leng[1]=strlen(nam);
			if(leng[1]<4){
				gotoxy(30,21);
				printf("The name is too short! Try Again.");
				clear(51,70,8,8);
				goto name;
			}else strcpy(p.name,nam);
	     sex   :
			char se[20]="";
				gotoxy(19,11);
				input2(se,20);
			if(strcmp(se,"male")==0||strcmp(se,"MALE")==0||strcmp(se,"Male")==0||strcmp(se,"female")==0||strcmp(se,"FEMALE")==0||strcmp(se,"Female")==0){
				clear(18,62,20,20);
				strcpy(p.sex,se);
			}else{
				gotoxy(18,20);
				printf("Wrong Gender! please type: Male or Female");
				clear(18,38,11,11);
				goto sex;
			}

	     day:
				char da[20]="";
				gotoxy(51,11);
				input(da,3);
				leng[3]=strlen(da);

			if(atoi(da)>31&&leng[3]!=2||atoi(da)<1&&leng[3]!=2){
				clear(51,53,11,11);
				goto day;
			}else strcpy(p.ngai,da);
				int months;
	     month:
			char mon[20]="";
			gotoxy(57,11);
			input(mon,3);
			leng[4]=strlen(mon);
			if(atoi(mon)>12&&leng[4]!=2||atoi(mon)<1&&leng[4]!=2){
			clear(57,59,11,11);
			goto month;
			}
			else strcpy(p.khae,mon);
	     year:      char ye[20]="";
				gotoxy(63,11);
				input(ye,5);
			if(atoi(ye)<1950){
				clear(63,67,11,11);
				goto year;
			}else strcpy(p.jnam,ye);
			char sub[20]="";
				gotoxy(19,14);
				input2(sub,16);

				strcpy(p.subjects,sub);
			char roo[20]="";
				gotoxy(51,14);
				input2(roo,8);
				strcpy(p.room,roo);
			char yer[20]="";
				gotoxy(31,17);
				input2(yer,8);
				strcpy(p.year,yer);

			_setcursortype(0);
			background(17,63,10,14,2);
			TABLE(17,63,10,14,15,2);
			gotoxy(19,12);textcolor(15);cprintf(" PRESS ANYKEY FOR CONTINUE OR ESC FOR EXIT ");
			ch=getch();
			textcolor(15);
			textbackground(1);
		       fseek(fp,0,SEEK_END);
		       fwrite(&p,sizeof(stu),1,fp);

		}while(ch!=27);
		clrscr();
		start();
		drop(" INSERT"," VIEW"," EDIT"," DELETE",7,3,4,5,7);
		SHOW_ARROW_DOWN("  INSERT   ","  VIEW     ","  EDIT     ","  DELETE   ",7);

				 }
	   //end iput code
	if(b==2&&d==13){

		//start show
		 do{
	show:	int size;
		fseek(fp,0,SEEK_END); size=sizeof(stu);
		n=ftell(fp)/size;
		if(n>0){
		ch=80; i=0;
		rewind(fp);
		textbackground(1);
		clrscr();
		start();
		background(2,79,5,22,3);
		TABLE(2,79,3,5,0,15);
		background(2,79,4,4,2);
		//background(2,79,3,3,15);
		TABLE(2,9,3,22,0,15);
		TABLE(9,26,3,22,0,15);
		TABLE(26,35,3,22,0,15);
		TABLE(35,48,3,22,0,15);
		TABLE(48,63,3,22,0,15);
		TABLE(63,71,3,22,0,15);
		TABLE(71,79,3,22,0,15);
		TABLE(2,79,3,22,0,15);


		clear(3,8,6,21);
		clear(11,25,6,21);
		clear(27,34,6,21);
		clear(36,47,6,21);
		clear(49,62,6,21);
		clear(64,70,6,21);
		clear(72,78,6,21);
		gotoxy(33,2);printf(" STUDENT REPORT ");
		gotoxy(5,4); printf("ID");
		gotoxy(16,4);printf("NAME");
		gotoxy(29,4);printf("SEX");
		gotoxy(39,4);printf("DOB");
		gotoxy(52,4);printf("SUBJECT");
		gotoxy(65,4);printf("CLASS");
		gotoxy(73,4);printf("GRADE");


		int Y=6,i=0;

		rewind(fp);
		while(fread(&p,size,1,fp)==1){
		gotoxy(4,Y+i); printf("%s\n",p.id);
		gotoxy(10,Y+i);printf("%s\n",p.name);
		gotoxy(28,Y+i);printf("%s\n",p.sex);
		gotoxy(37,Y+i);printf("%s\n",p.ngai);
		gotoxy(39,Y+i);printf("/%s\n",p.khae);
		gotoxy(42,Y+i);printf("/%s\n",p.jnam);
		gotoxy(49,Y+i);printf("%s\n",p.subjects);
		gotoxy(66,Y+i);printf("%s\n",p.room);
		gotoxy(73,Y+i);printf("%s\n",p.year);
		i++;
		    }
		    gotoxy(11,24);printf("[F2]=DELETE  [ESC]=BACK  [F1]=SORT  [DEL]=DELETE  [F3]=SEARCH");
		do{

			ch=getch();

		if(ch==80){
			if(i<n){
			i++;
			fread(&p,size,1,fp);
			}
		}else if(ch==72){
			if(i>1){
			i--;
			fseek(fp,-2*size,SEEK_CUR);
			fread(&p,size,1,fp);
			}

		}

		if(ch==59){
			sort();goto show;}
		else if(ch==60){
		del();goto show;
		}

		}while(ch!=27);
		 }else{
		 clrscr();
		 start();
		textcolor(15);
		textbackground(1);
		background(2,79,5,22,3);
		background(2,79,4,4,2);
		TABLE(2,79,3,22,0,15);

		gotoxy(35,13);printf("DATA EMPTY");
		gotoxy(33,2);printf(" STUDENT REPORT ");
		gotoxy(5,4); printf("ID");
		gotoxy(16,4);printf("NAME");
		gotoxy(29,4);printf("SEX");
		gotoxy(39,4);printf("DOB");
		gotoxy(52,4);printf("SUBJECT");
		gotoxy(65,4);printf("CLASS");
		gotoxy(73,4);printf("GRADE");
		getch();break;
		 }

		}while(ch!=27);textbackground(1);clrscr();start();drop(" INSERT"," VIEW"," EDIT"," DELETE",7,3,4,5,7);
		SHOW_ARROW_DOWN("  INSERT   ","  VIEW     ","  EDIT     ","  DELETE   ",7);
 }
		 //end show
	if(b==4&&d==13) {
	del();
	textbackground(1);clrscr();start();drop(" INSERT"," VIEW"," EDIT"," DELETE",7,3,4,5,7);
		SHOW_ARROW_DOWN("  INSERT   ","  VIEW     ","  EDIT     ","  DELETE   ",7);

	}

	if(b==3&&d==13){
	//start Edit
	do{
	clrscr();start();
	clear(2,79,3,22);
	background(2,79,3,22,3);
	TABLE(2,79,3,22,0,15);
	_setcursortype(2);
	gotoxy(19,5);
	textcolor(15);
	textbackground(3);
	cprintf(" ENTER ID TO EDIT ");
	background(38,58,5,5,15);
	gotoxy(39,5);
	char x[20]="";
	input(x,5);
	_setcursortype(0);
		b=0;
		rewind(fp);
		fp1=fopen(localcpy,"wb");
		while(fread(&p,sizeof(stu),1,fp)==1){

		    //Code Edit

		    if(strcmp(p.id,x)==0){
		    textbackground(1);
			_setcursortype(0);
			textcolor(15);
			gotoxy(30,2);
			printf(" INPUT NEW REPORT ");
			background(8,25,6,19,15);
			TABLE(8,25,7,19,0,15);
			gotoxy(8,6);
			textcolor(15);
			textbackground(1);
			cprintf("  OPTION TO EDIT  ");
			gotoxy(9,8);textcolor(0);textbackground(15); cprintf("      Name      ");
			gotoxy(9,10);textcolor(0);textbackground(15);cprintf("      Gender    ");
			gotoxy(9,12);textcolor(0);textbackground(15);cprintf("      Birthday  ");
			gotoxy(9,14);textcolor(0);textbackground(15);cprintf("      Subject   ");
			gotoxy(9,16);textcolor(0);textbackground(15);cprintf("      Class     ");
			gotoxy(9,18);textcolor(0);textbackground(15);cprintf("      Year      ");Show_Edit();

		    do{
			 gotoxy(40,8);printf("New Name");background(53,73,8,8,15);
			 gotoxy(54,8);printf("%s",p.name);
			 gotoxy(40,10);printf("New Gender");background(53,73,10,10,15);
			 gotoxy(54,10);printf("%s",p.sex);
			 gotoxy(40,12);printf("New Birthday");background(53,56,12,12,15);
			 gotoxy(54,12);printf("%s",p.ngai);background(58,61,12,12,15);
			 gotoxy(59,12);printf("%s",p.khae);background(63,68,12,12,15);
			 gotoxy(64,12);printf("%s",p.jnam);
			 gotoxy(40,14);printf("New Subject");background(53,73,14,14,15);
			 gotoxy(54,14);printf("%s",p.subjects);
			 gotoxy(40,16);printf("New Class");background(53,73,16,16,15);
			 gotoxy(54,16);printf("%s",p.room);
			 gotoxy(40,18);printf("New Grade");background(53,73,18,18,15);
			 gotoxy(54,18);printf("%s",p.year);
			k=getch();
			if(k==80) l++;
			if(k==72) l--;

			gotoxy(9,8);textcolor(0);textbackground(15); cprintf("      Name      ");
			gotoxy(9,10);textcolor(0);textbackground(15);cprintf("      Gender    ");
			gotoxy(9,12);textcolor(0);textbackground(15);cprintf("      Birthday  ");
			gotoxy(9,14);textcolor(0);textbackground(15);cprintf("      Subject   ");
			gotoxy(9,16);textcolor(0);textbackground(15);cprintf("      Class     ");
			gotoxy(9,18);textcolor(0);textbackground(15);cprintf("      Year      ");
			Show_Edit();
			 if(l==1&&k==13){
			 clear(54,74,8,8);
			_setcursortype(2);
			 na:	char nam[20]="";
				gotoxy(54,8);
				input2(nam,19);
				clear(30,65,21,21);
				leng[1]=strlen(nam);
			if(leng[1]<4){
				gotoxy(30,21);
				printf("Name is too short. try again");
				clear(51,70,8,8);
				goto na;

			}else {
				strcpy(p.name,nam);
				_setcursortype(0);
				}
			 }
			 if(l==2&&k==13){
			 clear(54,74,10,10);
			 _setcursortype(2);
			 sexs:	char se[20]="";
				gotoxy(54,10);
				input2(se,20);
			if(strcmp(se,"male")==0||strcmp(se,"MALE")==0||||strcmp(se,"Male")==0strcmp(se,"female")==0||strcmp(se,"FEMALE")==0||strcmp(se,"Female")==0){
				clear(18,62,20,20);
				strcpy(p.sex,se);
				_setcursortype(0);


			}else{
				gotoxy(18,20);
				printf("Wrong gender! type: female or male");
				clear(18,38,11,11);
				goto sexs;
			}

			 }
			 if(l==3&&k==13){
			 clear(54,74,12,12);
			 _setcursortype(2);
		days:
			char da[20]="";
				gotoxy(54,12);
				input(da,3);
			if(atoi(da)>31||atoi(da)<1){
				clear(51,53,11,11);
				goto days;
			}else strcpy(p.ngai,da);
				int months;
	     months:
			char mon[20]="";
			gotoxy(59,12);
			input(mon,3);
			if(atoi(mon)>12||atoi(mon)<1){
			clear(57,59,11,11);
			goto months;
			}
			else strcpy(p.khae,mon);
	     years:
			char ye[20]="";
				gotoxy(64,12);
				input(ye,5);
			if(atoi(ye)<1950){
				clear(63,67,11,11);
				goto years;
			}else {strcpy(p.jnam,ye);
			_setcursortype(0);}
			 }
			 if(l==4&&k==13){
			 clear(54,74,14,14);
			 _setcursortype(2);
			     char sub[20]="";
				gotoxy(54,14);
				input2(sub,16);
				strcpy(p.subjects,sub);
			 _setcursortype(0);}
			 if(l==5&&k==13){
			  clear(54,74,16,16);
			  _setcursortype(2);
			 char roo[20]="";
				gotoxy(54,16);
				input2(roo,8);
				strcpy(p.room,roo);

			 _setcursortype(0); }
			 if(l==6&&k==13){
			  clear(54,74,18,18);
			  _setcursortype(2);
			 char yer[20]="";
				gotoxy(54,18);
				input2(yer,8);
				strcpy(p.year,yer);

			 _setcursortype(0);}

			}while(k!=27);

			_setcursortype(0);
			b=1;
		    }
		    fwrite(&p,sizeof(stu),1,fp1);

		}
		fclose(fp1);fclose(fp); remove(local);
		rename(localcpy,local);

		fp = fopen(local,"a+b");

		if(b==0) {
		textbackground(1);
		background(17,63,10,14,2);
		TABLE(17,63,10,14,15,2);
		gotoxy(32,12);
		printf(" ID NOT FOUND ");
		getch();break;
		}
		else{
		textbackground(1);
		background(17,63,10,14,2);
		TABLE(17,63,10,14,15,2);
		gotoxy(33,12);textcolor(15);cprintf("EDIT COMPLETE");
		getch();break;}
		}while(1);textbackground(1);clrscr();start();drop(" INSERT"," VIEW"," EDIT"," DELETE",7,3,4,5,7);
		SHOW_ARROW_DOWN("  INSERT   ","  VIEW     ","  EDIT     ","  DELETE   ",7);

		}

	}while(d!=27);start();}
	//end fuction menu


	//start function SUBJECT
	void subject(){


		char ch;
	  drop(" INSERT"," VIEW"," EDIT"," DELETE",16,3,4,5,7);
	  SHOW_ARROW_DOWN("  INSERT   ","  VIEW     ","  EDIT     ","  DELETE   ",16);
	do{
	ARROW_DOWN();
	drop(" INSERT"," VIEW"," EDIT"," DELETE",16,3,4,5,7);
	SHOW_ARROW_DOWN("  INSERT   ","  VIEW     ","  EDIT     ","  DELETE   ",16);
	if(b==1&&d==13){
	fp2=fopen("subject.txt","a+b");
	do{
			textbackground(1);
			clrscr();
			start();
			background(2,79,3,22,3);
			TABLE(2,79,3,22,0,15);
			textcolor(15);
			gotoxy(30,2);
			printf(" INSERT SUBJECT ");
			background(29,53,8,8,1);
			background(29,53,11,11,1);
			background(29,53,14,14,1);
			gotoxy(22,8);
			printf("ID    :");
			gotoxy(22,11);
			printf("TITLE :");
			gotoxy(22,14);
			printf("YEAR  :");
			char id[20]="";
			gotoxy(30,8);
			_setcursortype(_NORMALCURSOR);
			input(id,5);
			strcpy(s.id,id);
			char title[20]="";
			gotoxy(30,11);
			input2(title,20);
			strcpy(s.title,title);
			char yea[20]="";
			gotoxy(30,14);
			input2(yea,20);
			strcpy(s.year,yea);
			_setcursortype(0);
			background(17,63,10,14,2);
			TABLE(17,63,10,14,15,2);
			gotoxy(19,12);textcolor(15);cprintf(" PRESS ANYKEY FOR CONTINUE OR ESC FOR EXIT ");

			ch=getch();
			textcolor(15);
			textbackground(1);
		}while(ch!=27);
		clrscr();
		start();
		drop(" INSERT"," VIEW"," EDIT"," DELETE",16,3,4,5,7);
		SHOW_ARROW_DOWN("  INSERT   ","  VIEW     ","  EDIT     ","  DELETE   ",16);
		};
	if(b==2&&d==13) ;
	if(b==3&&d==13) break;
	if(b==4&&d==13) break;
	}while(d!=27);textbackground(1);start(); }
	  void score(){
	  drop(" INSERT"," VIEW"," EDIT"," DELETE",25,3,4,5,7);
	  SHOW_ARROW_DOWN("  INSERT   ","  VIEW     ","  EDIT     ","  DELETE   ",25);
	  do{
	  ARROW_DOWN();
	  drop(" INSERT"," VIEW"," EDIT"," DELETE",25,3,4,5,7);
	  SHOW_ARROW_DOWN("  INSERT   ","  VIEW     ","  EDIT     ","  DELETE   ",25);
	if(b==1&&d==13) break;
	if(b==2&&d==13) break;
	if(b==3&&d==13) break;
	if(b==4&&d==13) break;
	}while(d!=27);textbackground(1);start();}
	//end function SUBJECT

	//start function ABOUT
	  void about(){
	  background(10,70,8,17,3);
	  background(10,70,7,7,15);
	  background(10,70,18,18,15);
	  TABLE(10,70,8,17,15,1);
	  gotoxy(30,7);
	  textcolor(1);
	  textbackground(15);
	  cprintf("Information ABOUT Us");
	  gotoxy(14,11);
	  printf("SYSTEM MANAGERMENT STUDENT");
	  gotoxy(12,13);
	  printf("Created By TOP-PLUS Group");
	  gotoxy(14,15);
	  printf("Assignment: Teacher ");
	  gotoxy(44,9);
	  printf("  __Member List__");
	  gotoxy(44,10);
	  printf("1. MY SEY");
	  gotoxy(44,11);
	  printf("2. MEY KOSAL");
	  gotoxy(44,12);
	  printf("3. DUM NARIN");
	  gotoxy(44,13);
	  printf("4. CHY PANHA");
	  gotoxy(44,14);
	  printf("5. BAN SOTHEN");
	  gotoxy(44,15);
	  printf("6. MET TOUMINH");
	  gotoxy(44,16);
	  printf("7. PHOUEY PANHARITH");
	  gotoxy(30,18);
	  textcolor(1);
	  textbackground(15);
	  cprintf(" Copyright(c) 2017 ");

	}
	//end function SUBJECT
      /*	void loading(){
	clrscr();
	int i,k,j,gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	for(i=0;i<180;i++){ setcolor(15);
	for(j=0;j<10;j++)
	arc(300,200,0,i,100+j);
	delay(1);
	gotoxy(34,13);
	printf("LOADING...");
	}
	for(i=180;i<360;i++){ setcolor(14);
	for(j=0;j<10;j++)
	arc(300,200,0,i,100+j);

	delay(1);
	}
	closegraph();
	clrscr();
	gotoxy(35,12);
	textcolor(14+BLINK);
	cprintf("PRESS ANY KEY...");
	} */

	  void TABLE(int a1,int a2,int b1,int b2,int color,int color2){
	int i;
	textbackground(color2);
	textcolor(color);
	for(i=a1+1;i<a2;i++){
	gotoxy(i,b1); cprintf("%c",196);
	gotoxy(i,b2); cprintf("%c",196);
			    }
	for(i=b1+1;i<b2;i++){
	gotoxy(a1,i); cprintf("%c",179);
	gotoxy(a2,i); cprintf("%c",179);
			    }
	gotoxy(a1,b1); cprintf("%c",218);
	gotoxy(a2,b1); cprintf("%c",191);
	gotoxy(a1,b2); cprintf("%c",192);
	gotoxy(a2,b2); cprintf("%c",217);
						}
	void background(int a1,int a2,int b1,int b2,int color)
{
    int i,j;
    textbackground(color);
    for(i=a1;i<=a2;i++)
	for(j=b1;j<=b2;j++)
	{
	    gotoxy(i,j); cprintf(" ");
	}
    textbackground(0);
}
	void clear(int a1,int a2,int b1,int b2)
{
    int i,j;
    for(i=a1;i<=a2;i++)
	for(j=b1;j<=b2;j++)
	{
	    gotoxy(i,j); printf(" ");
	}
}

