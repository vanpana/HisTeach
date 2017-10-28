//---------------------------------------------------------------------------

#ifndef Mod_ElevH
#define Mod_ElevH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TModElev : public TForm
{
__published:	// IDE-managed Components
	TRectangle *Top_Bar;
	TRectangle *Low_Bar;
	TListBox *Lectii_List;
	TImage *Prev_Back;
	TImage *Prev_Next;
	TLabel *Profesor;
	TLabel *Title;
	TImage *Parcurgere_Lectie;
	TImage *Testare_Cunostinte;
	TImage *Finalizare_BG;
	TLabel *Lectie;
	TImage *SlideShow;
	TTimer *Timer1;
	TTimer *Timer2;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall Prev_NextClick(TObject *Sender);
	void __fastcall Prev_BackClick(TObject *Sender);
	void __fastcall Parcurgere_LectieClick(TObject *Sender);
	void __fastcall Testare_CunostinteClick(TObject *Sender);
	void __fastcall Finalizare_BGClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall Lectii_ListChangeCheck(TObject *Sender);
private:
char profesori[100][100];
void load (int i)
{
	char temp[200];
	Profesor->Text=profesori[i];
	strcpy(temp,"Profesor/");
	strcat(temp,profesori[i]);
	strcat(temp,"/Lectii/Lectii.res");
	Lectii_List->Items->LoadFromFile(temp);
}
	// User declarations
public:
char titlu[200],locatie[200],locatie_profesor[200];	// User declarations
	__fastcall TModElev(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TModElev *ModElev;
//---------------------------------------------------------------------------
#endif
