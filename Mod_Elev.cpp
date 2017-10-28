//---------------------------------------------------------------------------

#include <fmx.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <direct.h>
#pragma hdrstop

#include "Mod_Elev.h"
#include "Parcurgere_Lectie.h"
#include "Testare_Cunostinte.h"
#include "Meniu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TModElev *ModElev;
int OK=1,prof_cur=1,prof_tot=0,poza_cur=1;


//---------------------------------------------------------------------------
__fastcall TModElev::TModElev(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TModElev::FormActivate(TObject *Sender)
{
if (OK)
{
char temp[100];
strcpy(temp,Meniu1->login_path);
strcat(temp,"Profesori.res");
ifstream f(temp);
while (!f.eof())
{
	f.getline (temp,100);
	if (temp!="")
		strcpy(profesori[++prof_tot],temp);
}
prof_tot--;
f.close();
load(1);

Lectii_List->ItemIndex=0;
Timer1->Enabled=1;

OK=0;
}
}
//---------------------------------------------------------------------------
void __fastcall TModElev::Prev_NextClick(TObject *Sender)
{
if (prof_cur<prof_tot)
{
prof_cur++;
load(prof_cur);

}
}
//---------------------------------------------------------------------------
void __fastcall TModElev::Prev_BackClick(TObject *Sender)
{
if (prof_cur>1)
{
prof_cur--;
load(prof_cur);

}
}
//---------------------------------------------------------------------------
void __fastcall TModElev::Parcurgere_LectieClick(TObject *Sender)
{
char a[200];
for (int i=0; i <=30; i++)
{
	if (Lectii_List->ItemIndex==i)
	{
	   strcpy(a,"Profesor/");
	   strcat(a,profesori[prof_cur]);
	   strcat(a,"/Lectii/Lectii.res");
	   ifstream fin(a);
	   for (int j = 1; j <= 30; j++)
	   {
	   fin.get(a,100); fin.get();
	   if (i+1==j) break;
	   }
	}
}
strcpy(titlu,a);
strcpy(locatie,"Profesor/");
strcat(locatie,profesori[prof_cur]);
strcat(locatie,"/Lectii/");
strcat(locatie,a);
ParcurgereLectie->Show();
ModElev->Close();
}
//---------------------------------------------------------------------------

void __fastcall TModElev::Testare_CunostinteClick(TObject *Sender)
{
char a[100];
for (int i=0; i <=30; i++)
{
	if (Lectii_List->ItemIndex==i)
	{
		strcpy(a,"Profesor/");
	   strcat(a,profesori[prof_cur]);
	   strcat(a,"/Lectii/Lectii.res");
	   ifstream fin(a);
	   for (int j = 1; j <= 30; j++)
	   {
	   fin.get(a,100); fin.get();
	   if (i+1==j) break;
	   }
	}
}
strcpy(titlu,a);
strcpy(locatie,"Profesor/");
strcat(locatie,profesori[prof_cur]);
strcat(locatie,"/Lectii/");
strcat(locatie,a);
strcat(locatie,"/Test/1.res");

ifstream f(locatie);
/*strcpy(titlu,a);
strcpy(locatie,"/Profesor/");
strcat(locatie,profesori[prof_cur]);
strcat(locatie,"/Lectii/");
strcat(locatie,a);
strcat(locatie,"/Test/rezultat.res");
ShowMessage(locatie);

ifstream fin(locatie);   */

if (f){// && !fin) {
strcpy(titlu,a);
//strcpy(locatie,Meniu1->login_path);
strcpy(locatie,"Profesor/");
strcat(locatie,profesori[prof_cur]);
strcat(locatie,"/Lectii/");
strcat(locatie,a);
strcat(locatie,"/Test/");
strcpy(locatie_profesor,"Profesor/");
strcat(locatie_profesor,profesori[prof_cur]);
strcat(locatie_profesor,"/Lectii/");
strcat(locatie_profesor,a);
strcat(locatie_profesor,"/");
TestareCunostinte->Show();
ModElev->Close();
}

/*else if (fin)
{
while (!fin.eof())
{
fin.get(a,100);
fin.get();
}
ShowMessage(String("Ai mai dat o data testul!\n")+String(a));

}*/
f.close();
OK=1;
//fin.close();

}                                                                                                                       //
//---------------------------------------------------------------------------

void __fastcall TModElev::Finalizare_BGClick(TObject *Sender)
{
Meniu1->Show();
ModElev->Close();
OK=0;
}
//---------------------------------------------------------------------------


void __fastcall TModElev::Timer1Timer(TObject *Sender)
{

char a[100];
Timer1->Enabled=0;
Timer2->Enabled=1;

for (int i=0; i <=30; i++)
{
	if (Lectii_List->ItemIndex==i)
	{
	   strcpy(a,"Profesor/");
	   strcat(a,profesori[prof_cur]);
	   strcat(a,"/Lectii/Lectii.res");
	   ifstream fin(a);
	   for (int j = 1; j <= 30; j++)
	   {
	   fin.get(a,100); fin.get();
	   if (i+1==j) break;
	   }
	}
}
strcpy(titlu,a);
strcpy(locatie,"Profesor/");
strcat(locatie,profesori[prof_cur]);
strcat(locatie,"/Lectii/");
strcat(locatie,a);
strcat(locatie,"/");

int adev=0;
//while (adev==0)
//{

if (poza_cur+1==21) poza_cur=1;
else poza_cur++;


char temp[100],numar[10];
strcpy(temp,locatie);
//strcat(temp,"/");
strcat(temp,itoa(poza_cur,numar,10));
strcat(temp,".jpg");
//ShowMessage(temp);
ifstream ff(temp);
if (ff)
{
SlideShow->Visible=1;
ff.close();
SlideShow->Bitmap->LoadFromFile(temp);
//adev=1;
}
else ff.close();
//}


}
//---------------------------------------------------------------------------

void __fastcall TModElev::Timer2Timer(TObject *Sender)
{
Timer1->Enabled=1;
Timer2->Enabled=0;
}
//---------------------------------------------------------------------------

void __fastcall TModElev::Lectii_ListChangeCheck(TObject *Sender)
{
SlideShow->Visible=0;
Timer1->Enabled=1;
}
//---------------------------------------------------------------------------

