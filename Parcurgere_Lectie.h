//---------------------------------------------------------------------------

#ifndef Parcurgere_LectieH
#define Parcurgere_LectieH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.ListBox.hpp>
//---------------------------------------------------------------------------
class TParcurgereLectie : public TForm
{
__published:	// IDE-managed Components
	TRectangle *Top_Bar;
	TLabel *Title;
	TMemo *Lectie;
	TImage *Imagine;
	TImage *Next;
	TImage *Back;
	TImage *FMinus;
	TImage *FPlus;
	TImage *Exit;
	TComboBox *Chap;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall NextClick(TObject *Sender);
	void __fastcall BackClick(TObject *Sender);
	void __fastcall BackMouseEnter(TObject *Sender);
	void __fastcall BackMouseLeave(TObject *Sender);
	void __fastcall NextMouseEnter(TObject *Sender);
	void __fastcall NextMouseLeave(TObject *Sender);
	void __fastcall ExitClick(TObject *Sender);
	void __fastcall ExitMouseLeave(TObject *Sender);
	void __fastcall ExitMouseEnter(TObject *Sender);
	void __fastcall FPlusMouseEnter(TObject *Sender);
	void __fastcall FPlusMouseLeave(TObject *Sender);
	void __fastcall FMinusMouseEnter(TObject *Sender);
	void __fastcall FMinusMouseLeave(TObject *Sender);
	void __fastcall FPlusClick(TObject *Sender);
	void __fastcall FMinusClick(TObject *Sender);
	void __fastcall ChapClosePopup(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TParcurgereLectie(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TParcurgereLectie *ParcurgereLectie;
//---------------------------------------------------------------------------
#endif