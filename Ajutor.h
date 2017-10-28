//---------------------------------------------------------------------------

#ifndef AjutorH
#define AjutorH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TAjutor1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Imagine;
	TMemo *Text;
	TImage *Next;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall NextClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAjutor1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAjutor1 *Ajutor1;
//---------------------------------------------------------------------------
#endif
