﻿//---------------------------------------------------------------------------

#include <fmx.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <direct.h>
#pragma hdrstop

#include "Mod_Profesor.h"
#include "Meniu.h"
#include "Adaugare_Lectie.h"
#include "Modificare_Lectie.h"
#include "Creare_Test.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TCreareTest *CreareTest;
int pg_cur=1,pg_total=1,pg_tot=1,OK=0,in=0;
struct q
{
	char intrebare[100],r1[50],r2[50],r3[50],r4[50];
	int rc,pag,poz;
} intrebare[100];
//---------------------------------------------------------------------------
__fastcall TCreareTest::TCreareTest(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCreareTest::FormActivate(TObject *Sender)
{
if (in==0)
{

char a[300];
strcpy(a,Meniu1->login_path);
strcat(a,"Lectii/");
strcat(a,ModProfesor->titlu);
strcat(a,"/Test");
mkdir(a);
strcat(a,"/Pagini.res");

fstream ff(a);
if (ff)
	ff>>pg_total;
ff.close();
for (int i=1;i<=pg_total;i++)
{
char temp[100],numar[5];
strcpy(temp,ModProfesor->locatie);
strcat(temp,"/");
strcat(temp,itoa(i,numar,10));
strcat(temp,".res");
int x;
Intrebare->Text="";
R1->Text="";
R2->Text="";
R3->Text="";
R4->Text="";
RC->Text="";
GoTo->Text="1";
RSus->IsChecked=0;
RMij->IsChecked=0;
RJos->IsChecked=0;
ifstream f(temp);
if (f)
{

f.getline(a,100); //f.get();
strcpy(intrebare[i].intrebare,a);

f.getline(a,100); //f.get();
strcpy(intrebare[i].r1,a);

f.getline(a,100); //f.get();
strcpy(intrebare[i].r2,a);


f.getline(a,100); //f.get();
strcpy(intrebare[i].r3,a);

f.getline(a,100); //f.get();
strcpy(intrebare[i].r4,a);

f>>x;
intrebare[i].rc=x;//toi(a)-7-strlen(intrebare[i].intrebare))/2;
}
f>>x; intrebare[i].pag=x;
f>>x; intrebare[i].poz=x;
f.close();
}


Intrebare->Text=intrebare[1].intrebare;
R1->Text=intrebare[1].r1;
R2->Text=intrebare[1].r2;
R3->Text=intrebare[1].r3;
R4->Text=intrebare[1].r4;
if (intrebare[1].rc==2147483644) RC->Text=intrebare[1].rc=0;
else RC->Text=intrebare[1].rc;
if (intrebare[1].pag==1701584 || intrebare[1].pag==0) GoTo->Text="1";
else GoTo->Text=intrebare[1].pag;
if (intrebare[1].poz==1) RSus->IsChecked=1;
if (intrebare[1].poz==2) RMij->IsChecked=1;
else if (intrebare[1].poz==3) RJos->IsChecked=1;

pg_cur=1; pg_tot=1;
AnsiString text;
text=ModProfesor->titlu;
Titlu->Text=text;
in=1;

//PREV

char path[300];
 strcpy(path,Meniu1->login_path);
	   strcat(path,"Lectii/");
	   strcat(path,ModProfesor->titlu);
	   strcat(path,"/Pagini.res");
	   ifstream fin(path);
	   fin>>pg_tot;
	   fin.close();
	   //GoTo->Text="1";
	   From->Text=pg_tot;

pathc=1;
	text=GoTo->Text.c_str();
	strcpy(path,Meniu1->login_path);
	strcat(path,"Lectii/");
	strcat(path,ModProfesor->titlu);
	strcat(path,"/");
	strcat(path,text.c_str());
	strcat(path,".res");
	PreviewBox->Lines->LoadFromFile(path);
	if (GoTo->Text==1) Prev_Back->Opacity=0;
}
}
//---------------------------------------------------------------------------

void __fastcall TCreareTest::NextClick(TObject *Sender)
{
if (Intrebare->Text!="" && R1->Text!="" && R2->Text!="" && R3->Text!=""
&& R4->Text!="" && RC->Text!="")// && pg_cur<=5 && pg_tot<=6)
{
	char path[200];
	AnsiString text;
	text=Intrebare->Text.c_str();
	strcpy(intrebare[pg_cur].intrebare,text.c_str());
	text=R1->Text;
	strcpy(intrebare[pg_cur].r1,text.c_str());
	text=R2->Text;
	strcpy(intrebare[pg_cur].r2,text.c_str());
	text=R3->Text;
	strcpy(intrebare[pg_cur].r3,text.c_str());
	text=R4->Text;
	strcpy(intrebare[pg_cur].r4,text.c_str());
	text=RC->Text;
	intrebare[pg_cur].rc=atoi(text.c_str());
	text=GoTo->Text;
	intrebare[pg_cur].pag=StrToInt(text.c_str());
	if (RSus->IsChecked) intrebare[pg_cur].poz=1;
	else if (RMij->IsChecked) intrebare[pg_cur].poz=2;
	else if (RJos->IsChecked) intrebare[pg_cur].poz=3;

	Intrebare->Text="";
	R1->Text="";
	R2->Text="";
	R3->Text="";
	R4->Text="";
	RC->Text="";
	GoTo->Text=1;
	RSus->IsChecked=0;
	RMij->IsChecked=0;
	RJos->IsChecked=0;
	Intrebare->Text=intrebare[pg_cur+1].intrebare;
	R1->Text=intrebare[pg_cur+1].r1;
	R2->Text=intrebare[pg_cur+1].r2;
	R3->Text=intrebare[pg_cur+1].r3;
	R4->Text=intrebare[pg_cur+1].r4;
	if (intrebare[pg_cur+1].rc==2147483644)
	RC->Text=intrebare[pg_cur+1].rc=0;
	else RC->Text=intrebare[pg_cur+1].rc;
	if (intrebare[pg_cur+1].pag>pg_tot && intrebare[pg_cur+1].pag<1)
		intrebare[pg_cur+1].pag=1;
	GoTo->Text=intrebare[pg_cur+1].pag;

	if (intrebare[pg_cur+1].poz==1) RSus->IsChecked=1;
	if (intrebare[pg_cur+1].poz==2) RMij->IsChecked=1;
	else if (intrebare[pg_cur+1].poz==3) RJos->IsChecked=1;
	pg_cur++;
	if (pg_cur>pg_total)
	{
	pg_total++;
	GoTo->Text="1";
	}
	curr->Text=pg_cur;
	text=GoTo->Text.c_str();
	strcpy(path,Meniu1->login_path);
	strcat(path,"Lectii/");
	strcat(path,ModProfesor->titlu);
	strcat(path,"/");
	strcat(path,text.c_str());
	strcat(path,".res");

	if (GoTo->Text=="1")
	{
		Prev_Back->AnimateFloat("Opacity",0);
		Prev_Back->Enabled=0;
	}
else
{
	Prev_Back->AnimateFloat("Opacity",1);
		Prev_Back->Enabled=1;
}

if (GoTo->Text==From->Text)
	{
		Prev_Next->AnimateFloat("Opacity",0);
		Prev_Next->Enabled=0;
	}
else
	{
		Prev_Next->AnimateFloat("Opacity",1);
		Prev_Next->Enabled=1;
	}

	char numar[5];
	strcpy(path,Meniu1->login_path);
strcat(path,"Lectii/");
strcat(path,ModProfesor->titlu);
strcat(path,"/");
strcat(path,itoa(StrToInt(GoTo->Text),numar,10));
strcat(path,".res");
PreviewBox->Lines->LoadFromFile(path);

}
}
//---------------------------------------------------------------------------

void __fastcall TCreareTest::BackClick(TObject *Sender)
{
if (pg_cur-1>0)
{
	char path[200];
	Next->Visible=1;
	AnsiString text;

	if (Intrebare->Text!="" && R1->Text!="" && R2->Text!="" && R3->Text!=""
&& R4->Text!="" && RC->Text!="")
	{
	text=Intrebare->Text.c_str();
	strcpy(intrebare[pg_cur].intrebare,text.c_str());
	text=R1->Text;
	strcpy(intrebare[pg_cur].r1,text.c_str());
	text=R2->Text;
	strcpy(intrebare[pg_cur].r2,text.c_str());
	text=R3->Text;
	strcpy(intrebare[pg_cur].r3,text.c_str());
	text=R4->Text;
	strcpy(intrebare[pg_cur].r4,text.c_str());
	text=RC->Text;
	intrebare[pg_cur].rc=atoi(text.c_str());
	text=GoTo->Text;
	intrebare[pg_cur].pag=StrToInt(text.c_str());
if (RSus->IsChecked) intrebare[pg_cur].poz=1;
else if (RMij->IsChecked) intrebare[pg_cur].poz=2;
else if (RJos->IsChecked) intrebare[pg_cur].poz=3;
	}
	else pg_total--;

	pg_cur--;
	Intrebare->Text=intrebare[pg_cur].intrebare;
	R1->Text=intrebare[pg_cur].r1;
	R2->Text=intrebare[pg_cur].r2;
	R3->Text=intrebare[pg_cur].r3;
	R4->Text=intrebare[pg_cur].r4;
	RC->Text=intrebare[pg_cur].rc;
	GoTo->Text=intrebare[pg_cur].pag;
	if (intrebare[pg_cur].poz==1) RSus->IsChecked=1;
	if (intrebare[pg_cur].poz==2) RMij->IsChecked=1;
	else if (intrebare[pg_cur].poz==3) RJos->IsChecked=1;
	curr->Text=pg_cur;
	strcpy(path,Meniu1->login_path);
	strcat(path,"Lectii/");
	strcat(path,ModProfesor->titlu);
	strcat(path,"/");
	strcat(path,text.c_str());
	strcat(path,".res");
}
if (GoTo->Text=="1")
	{
		Prev_Back->AnimateFloat("Opacity",0);
		Prev_Back->Enabled=0;
	}
else
{
	Prev_Back->AnimateFloat("Opacity",1);
		Prev_Back->Enabled=1;
}

if (GoTo->Text==From->Text)
	{
		Prev_Next->AnimateFloat("Opacity",0);
		Prev_Next->Enabled=0;
	}
else
	{
		Prev_Next->AnimateFloat("Opacity",1);
		Prev_Next->Enabled=1;
	}
	char numar[5],path[300];
	strcpy(path,Meniu1->login_path);
strcat(path,"Lectii/");
strcat(path,ModProfesor->titlu);
strcat(path,"/");
strcat(path,itoa(StrToInt(GoTo->Text),numar,10));
strcat(path,".res");
PreviewBox->Lines->LoadFromFile(path);

}
//---------------------------------------------------------------------------

void __fastcall TCreareTest::Finalizare_BGClick(TObject *Sender)
{
OK=0;
AnsiString text;
if (pg_cur==pg_total)
{
	if(Intrebare->Text!="")
	{
	text=Intrebare->Text.c_str();
	strcpy(intrebare[pg_cur].intrebare,text.c_str());
	text=R1->Text;
	strcpy(intrebare[pg_cur].r1,text.c_str());
	text=R2->Text;
	strcpy(intrebare[pg_cur].r2,text.c_str());
	text=R3->Text;
	strcpy(intrebare[pg_cur].r3,text.c_str());
	text=R4->Text;
	strcpy(intrebare[pg_cur].r4,text.c_str());
	text=RC->Text;
	intrebare[pg_cur].rc=atoi(text.c_str());
	text=GoTo->Text;
	intrebare[pg_cur].pag=StrToInt(text.c_str());
if (RSus->IsChecked) intrebare[pg_cur].poz=1;
else if (RMij->IsChecked) intrebare[pg_cur].poz=2;
else if (RJos->IsChecked) intrebare[pg_cur].poz=3;
	}
	else pg_total--;
}


char temp[100];
int back=pg_total;
for (int i=1;i<=back;i++)
{
	pg_total=back;
	char numar[5];
	strcpy(temp,ModProfesor->locatie);
	strcat(temp,"/");
	strcat(temp,itoa(i,numar,10));
	strcat(temp,".res");
	ofstream g(temp);
	g<<intrebare[i].intrebare<<"\n"
	<<intrebare[i].r1<<"\n"
	<<intrebare[i].r2<<"\n"
	<<intrebare[i].r3<<"\n"
	<<intrebare[i].r4<<"\n"
	<<intrebare[i].rc<<"\n";
	g<<intrebare[i].pag<<"\n";
	g<<intrebare[i].poz;
	g.close();
}
///////////////////////////////
strcpy(temp,ModProfesor->locatie);
strcat(temp,"/Pagini.res");
ofstream gg(temp);
gg<<pg_total;
gg.close();
///////////////////////////////
in=0;
ModProfesor->Show();
CreareTest->Close();
}
//---------------------------------------------------------------------------

void __fastcall TCreareTest::Prev_NextClick(TObject *Sender)
{
char path[100],numar[100];
pathc++;
GoTo->Text=pathc;
if (pathc==2)
{
	Prev_Back->AnimateFloat("Opacity",1);
	Prev_Back->Enabled=1;
}
if (pathc==pg_tot)
{
	Prev_Next->AnimateFloat("Opacity",0);
	Prev_Next->Enabled=0;
}
strcpy(path,Meniu1->login_path);
strcat(path,"Lectii/");
strcat(path,ModProfesor->titlu);
strcat(path,"/");
strcat(path,itoa(pathc,numar,10));
strcat(path,".res");
PreviewBox->Lines->LoadFromFile(path);
}
//---------------------------------------------------------------------------

void __fastcall TCreareTest::Prev_BackClick(TObject *Sender)
{
char path[100],numar[100];
pathc--;
GoTo->Text=pathc;
if (pathc==1)
{
	Prev_Back->AnimateFloat("Opacity",0);
	Prev_Back->Enabled=0;
}
Prev_Next->AnimateFloat("Opacity",1);
Prev_Next->Enabled=1;
strcpy(path,Meniu1->login_path);
strcat(path,"Lectii/");
strcat(path,ModProfesor->titlu);
strcat(path,"/");
strcat(path,itoa(pathc,numar,10));
strcat(path,".res");
PreviewBox->Lines->LoadFromFile(path);
}
//---------------------------------------------------------------------------

void __fastcall TCreareTest::GoToTyping(TObject *Sender)
{
char numar[100];
AnsiString text;
char path[300];

/*try {
	throw new EConvertError(69);
}
catch (EConvertError & e) {
	GoTo->Text = "1";
	text=GoTo->Text.c_str();
	strcpy(path,Meniu1->login_path);
	strcat(path,"Lectii/");
	strcat(path,ModProfesor->titlu);
	strcat(path,"/");
	strcat(path,text.c_str());
	strcat(path,".res");
	PreviewBox->Lines->LoadFromFile(path);
}  */
text=GoTo->Text.c_str();

while (int x = text.LastDelimiter("abcdefghijklmnopqrstuvwxyz/.,;' `~\[]()!@#$%^&*()-=+_"))
	text.Delete(x,1);
GoTo->Text=text;

strcpy(path,Meniu1->login_path);
strcat(path,"Lectii/");
strcat(path,ModProfesor->titlu);
strcat(path,"/");
strcat(path,text.c_str());
strcat(path,".res");


if (GoTo->Text=="")
{
GoTo->Text=1;
text=GoTo->Text.c_str();
strcpy(path,Meniu1->login_path);
strcat(path,"Lectii/");
strcat(path,ModProfesor->titlu);
strcat(path,"/");
strcat(path,text.c_str());
strcat(path,".res");
PreviewBox->Lines->LoadFromFile(path);
}

else if (StrToInt(GoTo->Text)>StrToInt(From->Text)) {
 GoTo->Text=From->Text;
 text=GoTo->Text.c_str();
strcpy(path,Meniu1->login_path);
strcat(path,"Lectii/");
strcat(path,ModProfesor->titlu);
strcat(path,"/");
strcat(path,text.c_str());
strcat(path,".res");
PreviewBox->Lines->LoadFromFile(path);
}

else if (GoTo->Text<=From->Text) PreviewBox->Lines->LoadFromFile(path);

pathc=StrToInt(GoTo->Text);
strcpy(path,Meniu1->login_path);
strcat(path,"Lectii/");
strcat(path,ModProfesor->titlu);
strcat(path,"/");
strcat(path,itoa(pathc,numar,10));
strcat(path,".res");
PreviewBox->Lines->LoadFromFile(path);

	if (GoTo->Text=="1")
	{
		Prev_Back->AnimateFloat("Opacity",0);
		Prev_Back->Enabled=0;
	}
else
{
	Prev_Back->AnimateFloat("Opacity",1);
		Prev_Back->Enabled=1;
}

if (GoTo->Text==From->Text)
	{
		Prev_Next->AnimateFloat("Opacity",0);
		Prev_Next->Enabled=0;
	}
else
	{
		Prev_Next->AnimateFloat("Opacity",1);
		Prev_Next->Enabled=1;
	}
pathc=StrToInt(GoTo->Text);

}
//---------------------------------------------------------------------------

