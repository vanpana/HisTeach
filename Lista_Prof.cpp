//---------------------------------------------------------------------------

#include <fmx.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <direct.h>
#pragma hdrstop

#include "Lista_Prof.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TListaProf *ListaProf;
//---------------------------------------------------------------------------
__fastcall TListaProf::TListaProf(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TListaProf::FormActivate(TObject *Sender)
{
if (OK==0)
{
Lista->Items->LoadFromFile("Profesor/Lista.res");
OK=1;
}
}
//---------------------------------------------------------------------------
void __fastcall TListaProf::FinishClick(TObject *Sender)
{
prof_c=0,k=0;
ifstream f("Profesor/Lista.res");
char a[100];
while (f.get(a,100)) {f.get();prof_c++;}
for (int i=0; i < prof_c; i++)
{
if (Lista->ItemByIndex(i)->IsChecked)
{
AnsiString text;
text=Lista->ItemByIndex(i)->Text.c_str();
strcpy(prof_sel[++k],text.c_str());
Lista->ItemByIndex(i)->IsChecked=0;
}
}
ListaProf->Close();
}
//---------------------------------------------------------------------------

