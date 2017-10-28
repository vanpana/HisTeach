//---------------------------------------------------------------------------

#include <fmx.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <direct.h>
#pragma hdrstop

#include "Rezultat_Test.h"
#include "Testare_Cunostinte.h"
#include "Mod_Elev.h"
#include "Mod_Profesor.h"
#include "Meniu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TTestareCunostinte *TestareCunostinte;
int pg_cur=1,pg_curent=1,OK=0;
int pg_tot=1;
double scor=0,per_intrebare=0;
char rezultat[50];
//---------------------------------------------------------------------------
__fastcall TTestareCunostinte::TTestareCunostinte(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTestareCunostinte::FormActivate(TObject *Sender)
{
char temp[100];
strcpy(temp,ModElev->locatie);
//strcat(temp,"/Test/");
strcat(temp,"Pagini.res");
ifstream ff(temp);
ff>>pg_tot;
ff.close();
per_intrebare=(float)9/pg_tot;
//nota=0;
R1->IsChecked=0;
R2->IsChecked=0;
R3->IsChecked=0;
R4->IsChecked=0;

if (OK==0)
{
nota=0;
Timer1->Enabled=1;
strcpy(rezultat,Meniu1->login_path);
strcat(rezultat,ModElev->locatie);
strcat(rezultat,"rezultat.res");
scor=0;
pg_curent=1;
pg_cur=1;//curr->Text=pg_cur;
char a[100];
int x;
for (int i=1;i<=pg_tot;i++)
{
corect[i]=0;
char numar[5];
strcpy(temp,ModElev->locatie);
strcat(temp,"/");
strcat(temp,itoa(i,numar,10));
strcat(temp,".res");

ifstream f(temp);
f.get(a,100); f.get();
strcpy(intrebare[i].intrebare,a);

f.get(a,100); f.get();
strcpy(intrebare[i].r1,a);

f.get(a,100); f.get();
strcpy(intrebare[i].r2,a);

f.get(a,100); f.get();
strcpy(intrebare[i].r3,a);

f.get(a,100); f.get();
strcpy(intrebare[i].r4,a);

f>>x;
intrebare[i].rc=x;//(atoi(a)-7-strlen(intrebare[i].intrebare))/2;


f>>x; intrebare[i].pag=x;
f>>x; intrebare[i].poz=x;
intrebare[i].ok=0;
intrebare[i].corect=0;
f.close();
}

pg_cur=rand()%pg_tot+1;
srand(time(NULL));
while (intrebare[pg_cur].ok==1)
{
	pg_cur=rand()%pg_tot+1;
}
intrebare[pg_cur].ok=1;
load(pg_cur);
OK=1;
}
}
//---------------------------------------------------------------------------
void __fastcall TTestareCunostinte::NextClick(TObject *Sender)
{

if (check()==intrebare[pg_cur].rc)
{
	scor++;
	corect[pg_cur]=1;
}
//else if (check()==0) ShowMessage("Selecteaza un raspuns!");

if (pg_curent<pg_tot)
{
Timer1->Enabled=0;
Timer1->Enabled=1;
pg_curent++;
//curr->Text=pg_cur;
pg_cur=rand()%pg_tot+1;
srand(time(NULL));
while (intrebare[pg_cur].ok==1)
	pg_cur=rand()%pg_tot+1;
intrebare[pg_cur].ok=1;
load(pg_cur);
R1->IsChecked=0;
R2->IsChecked=0;
R3->IsChecked=0;
R4->IsChecked=0;
}

else
{
	Timer1->Enabled=false;
	nota=scor*per_intrebare+1;
	ShowMessage (String("Ai obtinut nota ") + float(nota) + "!");
	//ofstream g(rezultat,ios::app);

	//nota=scor*per_intrebare+1;

	/*g<<"Nota obtinuta: "<<scor*per_intrebare+1;
	g.close();//txt
	strcpy(rezultat,ModElev->locatie);
	strcat(rezultat,"/ok.res");

	ofstream fout(rezultat);
	fout<<"1";
	fout.close();         */

	RezultatTest->Show();
	TestareCunostinte->Hide();
	OK=0;
}
}
//---------------------------------------------------------------------------
void __fastcall TTestareCunostinte::NextMouseEnter(TObject *Sender)
{
Next->AnimateFloat("Opacity",0.3);
}
//---------------------------------------------------------------------------

void __fastcall TTestareCunostinte::NextMouseLeave(TObject *Sender)
{
Next->AnimateFloat("Opacity",1);
}
//---------------------------------------------------------------------------

void __fastcall TTestareCunostinte::Timer1Timer(TObject *Sender)
{
ShowMessage ("Timpul a expirat!");


if (pg_curent<pg_tot)
{
Timer1->Enabled=0;
Timer1->Enabled=1;

pg_curent++;
//curr->Text=pg_cur;
pg_cur=rand()%pg_tot+1;
srand(time(NULL));
while (intrebare[pg_cur].ok==1)
	pg_cur=rand()%pg_tot+1;
intrebare[pg_cur].ok=1;
load(pg_cur);
R1->IsChecked=0;
R2->IsChecked=0;
R3->IsChecked=0;
R4->IsChecked=0;
}

else
{
		Timer1->Enabled=0;
	nota=scor*per_intrebare+1;
	ShowMessage (String("Ai obtinut nota ") + float(nota) + "!");
	//ShowMessage (String("Ai obtinut nota ") + float(scor*per_intrebare+1) + "!");
	//ofstream g(rezultat,ios::app);

	/*g<<"Nota obtinuta: "<<scor*per_intrebare+1;
	g.close();//txt
	strcpy(rezultat,ModElev->locatie);
	strcat(rezultat,"/ok.res");

	ofstream fout(rezultat);
	fout<<"1";
	fout.close();         */

	RezultatTest->Show();
	TestareCunostinte->Hide();
	OK=0;
}


}
//---------------------------------------------------------------------------

