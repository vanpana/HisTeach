//---------------------------------------------------------------------------

#ifndef Creare_TestH
#define Creare_TestH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Memo.hpp>
//---------------------------------------------------------------------------
class TCreareTest : public TForm
{
__published:	// IDE-managed Components
	TRectangle *Top_Bar;
	TLabel *Titlu;
	TEdit *Intrebare;
	TEdit *R1;
	TEdit *R2;
	TEdit *R3;
	TEdit *R4;
	TEdit *RC;
	TMemo *PreviewBox;
	TLabel *Preview;
	TImage *Prev_Back;
	TImage *Prev_Next;
	TGroupBox *RP;
	TRadioButton *RSus;
	TRadioButton *RMij;
	TRadioButton *RJos;
	TImage *Finalizare_BG;
	TImage *Next;
	TImage *Back;
	TLabel *curr;
	TEdit *GoTo;
	TLabel *din;
	TEdit *From;
	TLabel *tag;
	TLabel *Label1;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall NextClick(TObject *Sender);
	void __fastcall BackClick(TObject *Sender);
	void __fastcall Finalizare_BGClick(TObject *Sender);
	void __fastcall Prev_NextClick(TObject *Sender);
	void __fastcall Prev_BackClick(TObject *Sender);
	void __fastcall GoToTyping(TObject *Sender);
private:
int pathc;	// User declarations
public:		// User declarations
	__fastcall TCreareTest(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCreareTest *CreareTest;
//---------------------------------------------------------------------------
#endif
