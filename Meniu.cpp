//---------------------------------------------------------------------------

#include <fmx.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <direct.h>
#pragma hdrstop

#include "Meniu.h"
#include "Mod_Profesor.h"
#include "Mod_Elev.h"
#include "Adaugare_Lectie.h"
#include "Lista_Prof.h"
#include "Ajutor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMeniu1 *Meniu1;
double elev_init,prof_init;
int in=1;
//---------------------------------------------------------------------------
__fastcall TMeniu1::TMeniu1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMeniu1::FormActivate(TObject *Sender)
{
if (OK==0)
{
	if (in==1)
	{
		elev_init=Elev_Img->Position->X;
		prof_init=Prof_Img->Position->X;
		in++;
	}
	else
	{
		Elev_Img->AnimateFloat("Position.X", elev_init);
		Prof_Img->AnimateFloat("Position.X", prof_init);
    }
	Elev_Img->Opacity=1;
	Prof_Img->Opacity=1;
    Prof_Text->Opacity=0;
	Elev_Text->Opacity=0;
	Prof_Usrn->Opacity=0;
	Prof_Pass->Opacity=0;
	Prof_Send->Opacity=0;
	Elev_Usrn->Opacity=0;
	Elev_Pass->Opacity=0;
	Elev_Send->Opacity=0;
	Prof_New->Opacity=0;
	Elev_New->Opacity=0;
	Check_Cont->Opacity=0;
	Prof_List->Opacity=0;
	Admin_Pass->Opacity=0;
	Usrn->Opacity=0;
	Pass->Opacity=0;
	Pass2->Opacity=0;
	Prof_Usrn->Text="";
	Prof_Pass->Text="";
	Elev_Usrn->Text="";
	Elev_Pass->Text="";
	ifstream f("Profesor/Lista.res");
	if (f) { f.close(); }
	else f.close();
	profesori=0;
	OK=1;
}

}
//------------------------------
void __fastcall TMeniu1::Prof_ImgMouseEnter(TObject *Sender)
{
Prof_Text->AnimateFloat("Opacity",1);
Meniu1->AnimateColor("Fill.Color", 0xFF8EBA20);
Prof_Img->AnimateFloat("Opacity",1);
Elev_Usrn->AnimateFloat("Opacity",0);
Elev_Usrn->Text="";
Elev_Pass->AnimateFloat("Opacity",0);
Elev_Pass->Text="";
Elev_Send->AnimateFloat("Opacity",0);
Admin_Pass->AnimateFloat("Opacity",0);
Elev_New->AnimateFloat("Opacity",0);
Usrn->AnimateFloat("Opacity",0);
Usrn->Text="";
Pass->AnimateFloat("Opacity",0);
Pass->Text="";
Pass2->AnimateFloat("Opacity",0);
Pass2->Text="";
Prof_List->AnimateFloat("Opacity",0);
Check_Cont->AnimateFloat("Opacity",0);

}
//---------------------------------------------------------------------------
void __fastcall TMeniu1::Prof_ImgMouseLeave(TObject *Sender)
{
Prof_Text->AnimateFloat("Opacity",0);
}
//---------------------------------------------------------------------------
void __fastcall TMeniu1::Elev_ImgMouseEnter(TObject *Sender)
{
Elev_Text->AnimateFloat("Opacity",1);
Meniu1->AnimateColor("Fill.Color", 0xff1b7ccc);//, 5, TAnimationType::InOut,
	   //	TInterpolationType::Linear);
Elev_Img->AnimateFloat("Opacity",1);
Prof_Usrn->AnimateFloat("Opacity",0);
Prof_Usrn->Text="";
Prof_Pass->AnimateFloat("Opacity",0);
Prof_Pass->Text="";
Prof_Send->AnimateFloat("Opacity",0);
Prof_New->AnimateFloat("Opacity",0);
Admin_Pass->AnimateFloat("Opacity",0);
Admin_Pass->Text="";
Usrn->AnimateFloat("Opacity",0);
Usrn->Text="";
Pass->AnimateFloat("Opacity",0);
Pass->Text="";
Pass2->AnimateFloat("Opacity",0);
Pass2->Text="";
Prof_List->AnimateFloat("Opacity",0);
Check_Cont->AnimateFloat("Opacity",0);

}
//---------------------------------------------------------------------------
void __fastcall TMeniu1::Elev_ImgMouseLeave(TObject *Sender)
{
Elev_Text->AnimateFloat("Opacity",0);
}
//---------------------------------------------------------------------------
void __fastcall TMeniu1::Prof_ImgMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y)
{
Prof_Usrn->AnimateFloat("Opacity",1);
Prof_Pass->AnimateFloat("Opacity",1);
Prof_New->AnimateFloat("Opacity",1);
Elev_Img->AnimateFloat("Opacity",0.3);
}
//---------------------------------------------------------------------------
void __fastcall TMeniu1::Prof_PassTyping(TObject *Sender)
{
if (Prof_Usrn->Text!="")
	Prof_Send->AnimateFloat("Opacity",1);
if (Prof_Pass->Text=="")
	Prof_Send->AnimateFloat("Opacity",0);

}
//---------------------------------------------------------------------------


void __fastcall TMeniu1::Elev_ImgMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y)
{
Elev_Usrn->AnimateFloat("Opacity",1);
Elev_Pass->AnimateFloat("Opacity",1);
Prof_Img->AnimateFloat("Opacity",0.3);
Elev_New->AnimateFloat("Opacity",1);
}
//---------------------------------------------------------------------------

void __fastcall TMeniu1::Elev_PassTyping(TObject *Sender)
{
Elev_Send->AnimateFloat("Opacity",1);
if (Elev_Pass->Text=="")
	Elev_Send->AnimateFloat("Opacity",0);
}
//---------------------------------------------------------------------------


void __fastcall TMeniu1::ExitMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  float X, float Y)
{
Meniu1->Close();
}
//---------------------------------------------------------------------------




void __fastcall TMeniu1::Prof_NewClick(TObject *Sender)
{
Admin_Pass->AnimateFloat("Opacity",1);
Usrn->AnimateFloat("Opacity",1);
Pass->AnimateFloat("Opacity",1);
Pass2->AnimateFloat("Opacity",1);
cont=1;
}
//---------------------------------------------------------------------------

void __fastcall TMeniu1::Elev_NewClick(TObject *Sender)
{
Usrn->AnimateFloat("Opacity",1);
Pass->AnimateFloat("Opacity",1);
Pass2->AnimateFloat("Opacity",1);
Prof_List->AnimateFloat("Opacity",1);
cont=2;
}
//---------------------------------------------------------------------------

void __fastcall TMeniu1::Pass2Typing(TObject *Sender)
{
if (Pass2->Text == Pass->Text)
	Check_Cont->AnimateFloat("Opacity",1);
else Check_Cont->AnimateFloat("Opacity",0);
}
//---------------------------------------------------------------------------

void __fastcall TMeniu1::Prof_SendClick(TObject *Sender)
{
char temp[300],pass[300];
AnsiString text;
text=Prof_Usrn->Text.c_str();
strcpy(login_path,"Profesor/");
strcat(login_path,text.c_str());
strcat(login_path,"/");

text=Prof_Pass->Text.c_str();
strcpy(pass,text.c_str());
for (int i=0; i < strlen(pass); i++)
	pass[i]=pass[i]+3;
strcpy(temp,login_path);
strcat(temp,pass);
ifstream f(temp);


if (f)
{
exit();
mod=1;
Timer1->Enabled=1;
OK=0;
}
else ShowMessage("User sau parola gresita!");
f.close();
}
//---------------------------------------------------------------------------
//elev
//----------------------------------------------------------------
void __fastcall TMeniu1::Timer1Timer(TObject *Sender)
{
if (mod==1) ModProfesor->Show();
else if (mod==2) ModElev->Show();
Meniu1->Hide();
Timer1->Enabled=0;
}
//---------------------------------------------------------------------------


void __fastcall TMeniu1::Check_ContClick(TObject *Sender)
{
//PROFESOR SAVE
if (cont==1)
{

if (Admin_Pass->Text=="logica42" && Usrn->Text!="")
{

char dir[300];
AnsiString text;
text=Usrn->Text.c_str();
mkdir("Profesor");
strcpy(dir,"Profesor/");
char aux[300];
ofstream gout("Profesor/Lista.res",ios::app);
gout<<text.c_str()<<"\n";
gout.close(); // ADAUGARE PROF IN LISTA

strcat(dir,text.c_str());
mkdir(dir); // FOLDER NUME PROFESOR

char temp[300];
text=Pass->Text.c_str();
strcpy(temp,text.c_str());
for (int i=0;i<strlen(temp);i++)
	temp[i]=temp[i]+3;
strcat(dir,"/");

strcpy(aux,dir);
strcat(aux,"Lectii");
mkdir(aux);

strcat(dir,temp);

ofstream g(dir);
g<<"";
g.close();

strcat(aux,"/Lectii.res");
ofstream gg(aux);
gg<<"";
gg.close();

ShowMessage("Profesor adaugat!");
Admin_Pass->Text="";
Usrn->Text="";
Pass->Text="";
Pass2->Text="";
Admin_Pass->Opacity=0;
Usrn->Opacity=0;
Pass->Opacity=0;
Pass2->Opacity=0;
Check_Cont->Opacity=0;

}
}



//ELEV SAVE
else if (cont==2)
{
if (profesori==1)
{
char dir[300];
AnsiString text;
text=Usrn->Text.c_str();
mkdir("Elev");
char aux[300];
strcpy(aux,"Elev/");
strcpy(dir,"Elev/");

ofstream gout("Elev/Lista.res",ios::app);
gout<<text.c_str()<<"\n";
gout.close(); //ADAUGARE ELEV IN LISTA
strcat(dir,text.c_str());
strcat(aux,text.c_str());
strcat(aux,"/");
mkdir(dir); // FOLDER NUME ELEV

char temp[300];
text=Pass->Text.c_str();
strcpy(temp,text.c_str());
for (int i=0;i<strlen(temp);i++)
	temp[i]=temp[i]+7;
strcat(dir,"/");
strcat(dir,temp);
ofstream g(dir);
g<<"";
g.close();

strcat(aux,"Profesori.res");
ofstream fout(aux);
for (int j=1; j <=ListaProf->k; j++)
	fout<<ListaProf->prof_sel[j]<<"\n";
fout.close();

ShowMessage("Elev adaugat!");
Admin_Pass->Text="";
Usrn->Text="";
Pass->Text="";
Pass2->Text="";
Usrn->Opacity=0;
Pass->Opacity=0;
Pass2->Opacity=0;
Prof_List->Opacity=0;
Check_Cont->Opacity=0;
profesori=0;
}

else ShowMessage("Alege profesori inainte de a continua!");

}
}
//---------------------------------------------------------------------------



void __fastcall TMeniu1::Prof_ListClick(TObject *Sender)
{
ListaProf->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMeniu1::Prof_PassKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
if (Key==13)
{
	char temp[300],pass[300];
AnsiString text;
text=Prof_Usrn->Text.c_str();
strcpy(login_path,"Profesor/");
strcat(login_path,text.c_str());
strcat(login_path,"/");

text=Prof_Pass->Text.c_str();
strcpy(pass,text.c_str());
for (int i=0; i < strlen(pass); i++)
	pass[i]=pass[i]+3;
strcpy(temp,login_path);
strcat(temp,pass);
ifstream f(temp);


if (f)
{
Prof_Send->AnimateFloat("Opacity",0);
mod=1;
exit();
Timer1->Enabled=1;
OK=0;
}
else ShowMessage("User sau parola gresita!");
f.close();
}
}
//---------------------------------------------------------------------------


void __fastcall TMeniu1::Elev_SendClick(TObject *Sender)
{
char temp[300],pass[300];
AnsiString text;
text=Elev_Usrn->Text.c_str();
strcpy(login_path,"Elev/");
strcat(login_path,text.c_str());
strcat(login_path,"/");

text=Elev_Pass->Text.c_str();
strcpy(pass,text.c_str());
for (int i=0; i < strlen(pass); i++)
	pass[i]=pass[i]+7;
strcpy(temp,login_path);
strcat(temp,pass);
ifstream f(temp);


if (f)
{
exit();
mod=2;
Timer1->Enabled=1;
OK=0;
}
else ShowMessage("User sau parola gresita!");
f.close();

}
//---------------------------------------------------------------------------

void __fastcall TMeniu1::Elev_PassKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
		  TShiftState Shift)
{
if (Key==13)
{
char temp[300],pass[300];
AnsiString text;
text=Elev_Usrn->Text.c_str();
strcpy(login_path,"Elev/");
strcat(login_path,text.c_str());
strcat(login_path,"/");

text=Elev_Pass->Text.c_str();
strcpy(pass,text.c_str());
for (int i=0; i < strlen(pass); i++)
	pass[i]=pass[i]+7;
strcpy(temp,login_path);
strcat(temp,pass);
ifstream f(temp);


if (f)
{
exit();
mod=2;
Timer1->Enabled=1;
OK=0;
}
else ShowMessage("User sau parola gresita!");
}
}
//---------------------------------------------------------------------------

void __fastcall TMeniu1::AjutorIcnClick(TObject *Sender)
{
Ajutor1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMeniu1::PassTyping(TObject *Sender)
{
if (Pass2->Text == Pass->Text)
	Check_Cont->AnimateFloat("Opacity",1);
else Check_Cont->AnimateFloat("Opacity",0);
}
//---------------------------------------------------------------------------
