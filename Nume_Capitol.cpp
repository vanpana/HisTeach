//---------------------------------------------------------------------------

#include <fmx.h>
#include <fstream>
#pragma hdrstop

#include "Meniu.h"
#include "Nume_Capitol.h"
#include "Adaugare_Lectie.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TNumeCapitol *NumeCapitol;
//---------------------------------------------------------------------------
__fastcall TNumeCapitol::TNumeCapitol(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TNumeCapitol::daClick(TObject *Sender)
{
AnsiString text;
text=NumeCap->Text.c_str();
strcpy(AdaugareLectie->cap_nume,text.c_str());
AdaugareLectie->Chap->Items->Add(AdaugareLectie->cap_nume);
AdaugareLectie->Chap->ItemIndex=AdaugareLectie->Chap->ItemIndex+1;

char temp[300];
strcpy(temp,Meniu1->login_path);
strcat(temp,"Lectii/Temp/Capitole_Tit.res");

ofstream g(temp,ios::app);
g<<AdaugareLectie->cap_nume<<"\n";
g.close();

NumeCap->Text="";
NumeCapitol->Close();

}
//---------------------------------------------------------------------------
void __fastcall TNumeCapitol::NumeCapKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
if (Key==13)
{
	NumeCapitol->daClick(Sender);
}

}
//---------------------------------------------------------------------------

