//---------------------------------------------------------------------------

#ifndef MeniuH
#define MeniuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Ani.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.ListBox.hpp>
//---------------------------------------------------------------------------
class TMeniu1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Prof_Img;
	TImage *Elev_Img;
	TImage *Prof_Text;
	TImage *Elev_Text;
	TEdit *Prof_Usrn;
	TEdit *Prof_Pass;
	TImage *Prof_Send;
	TEdit *Elev_Usrn;
	TImage *Elev_Send;
	TEdit *Elev_Pass;
	TImage *Exit;
	TEdit *Admin_Pass;
	TEdit *Usrn;
	TEdit *Pass;
	TEdit *Pass2;
	TImage *Check_Cont;
	TImage *Prof_New;
	TImage *Elev_New;
	TTimer *Timer1;
	TButton *Prof_List;
	TLabel *tag;
	TImage *AjutorIcn;
	void __fastcall Prof_ImgMouseEnter(TObject *Sender);
	void __fastcall Prof_ImgMouseLeave(TObject *Sender);
	void __fastcall Elev_ImgMouseEnter(TObject *Sender);
	void __fastcall Elev_ImgMouseLeave(TObject *Sender);
	void __fastcall Prof_ImgMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall Prof_PassTyping(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall Elev_ImgMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall Elev_PassTyping(TObject *Sender);
	void __fastcall ExitMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall Prof_NewClick(TObject *Sender);
	void __fastcall Elev_NewClick(TObject *Sender);
	void __fastcall Pass2Typing(TObject *Sender);
	void __fastcall Prof_SendClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Check_ContClick(TObject *Sender);
	void __fastcall Prof_ListClick(TObject *Sender);
	void __fastcall Prof_PassKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
	void __fastcall Elev_SendClick(TObject *Sender);
	void __fastcall Elev_PassKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
	void __fastcall AjutorIcnClick(TObject *Sender);
	void __fastcall PassTyping(TObject *Sender);
private:
int cont,OK; // 1 - prof 2 - elev	// User declarations
public:

bool profesori;
char login_path[100];
int mod;	// User declarations
void exit ()
{
Elev_Img->AnimateFloat("Position.X", Elev_Img->Position->X*2);
Prof_Img->AnimateFloat("Position.X", Prof_Img->Position->X-1000);
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
	OK=0;
}
	__fastcall TMeniu1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMeniu1 *Meniu1;
//---------------------------------------------------------------------------
#endif