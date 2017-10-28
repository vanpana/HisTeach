//---------------------------------------------------------------------------

#ifndef Modificare_LectieH
#define Modificare_LectieH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Dialogs.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.ListBox.hpp>
//---------------------------------------------------------------------------
class TModificareLectie : public TForm
{
__published:	// IDE-managed Components
	TRectangle *Top_Bar;
	TLabel *Title;
	TEdit *Titlu;
	TMemo *Lectie;
	TImage *Add_Image;
	TImage *Imagine;
	TOpenDialog *OpenDialog1;
	TImage *Back;
	TImage *Next;
	TImage *Finalizare_BG;
	TLabel *tag;
	TImage *FPlus;
	TImage *FMinus;
	TImage *Finalizare_TXT;
	TComboBox *Chap;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall NextClick(TObject *Sender);
	void __fastcall BackClick(TObject *Sender);
	void __fastcall Finalizare_BGClick(TObject *Sender);
	void __fastcall Add_ImageClick(TObject *Sender);
	void __fastcall OpenDialog1Close(TObject *Sender);
	void __fastcall LectieKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
	void __fastcall FPlusClick(TObject *Sender);
	void __fastcall FMinusClick(TObject *Sender);
	void __fastcall Finalizare_BGMouseEnter(TObject *Sender);
	void __fastcall Finalizare_BGMouseLeave(TObject *Sender);
	void __fastcall NextMouseEnter(TObject *Sender);
	void __fastcall NextMouseLeave(TObject *Sender);
	void __fastcall BackMouseEnter(TObject *Sender);
	void __fastcall BackMouseLeave(TObject *Sender);
	void __fastcall Add_ImageMouseLeave(TObject *Sender);
	void __fastcall Add_ImageMouseEnter(TObject *Sender);
	void __fastcall FMinusMouseEnter(TObject *Sender);
	void __fastcall FMinusMouseLeave(TObject *Sender);
	void __fastcall FPlusMouseEnter(TObject *Sender);
	void __fastcall FPlusMouseLeave(TObject *Sender);
	void __fastcall ChapClosePopup(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TModificareLectie(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TModificareLectie *ModificareLectie;
//---------------------------------------------------------------------------
#endif
