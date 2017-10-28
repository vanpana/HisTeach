//---------------------------------------------------------------------------

#include <fmx.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <direct.h>
#pragma hdrstop

#include "PopUp_Creare.h"
#include "Mod_Profesor.h"
#include "Meniu.h"
#include "Adaugare_Lectie.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TPopUpCreare *PopUpCreare;
//---------------------------------------------------------------------------
__fastcall TPopUpCreare::TPopUpCreare(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPopUpCreare::daClick(TObject *Sender)
{
char dir[30],aux[5];

for (int i=1; i < 30; i++)
{
strcpy(dir,Meniu1->login_path);
strcat(dir,"Lectii/Temp/");
strcat(dir,itoa(i,aux,10));
strcat(dir,".res");
remove(dir);

strcpy(dir,Meniu1->login_path);
strcat(dir,"Lectii/Temp/");
strcat(dir,itoa(i,aux,10));
strcat(dir,".jpg");
remove(dir);

}

strcpy(dir,Meniu1->login_path);
strcat(dir,"Lectii/Temp");
rmdir (dir);
ModProfesor->Show();
AdaugareLectie->Close();
PopUpCreare->Close();
AdaugareLectie->OK=0;
}
//---------------------------------------------------------------------------
void __fastcall TPopUpCreare::nuClick(TObject *Sender)
{
PopUpCreare->Close();
AdaugareLectie->OK=1;
}
//---------------------------------------------------------------------------
