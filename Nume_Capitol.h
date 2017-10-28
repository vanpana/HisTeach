//---------------------------------------------------------------------------

#ifndef Nume_CapitolH
#define Nume_CapitolH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TNumeCapitol : public TForm
{
__published:	// IDE-managed Components
	TLabel *Text;
	TEdit *NumeCap;
	TButton *da;
	void __fastcall daClick(TObject *Sender);
	void __fastcall NumeCapKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
	__fastcall TNumeCapitol(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TNumeCapitol *NumeCapitol;
//---------------------------------------------------------------------------
#endif
