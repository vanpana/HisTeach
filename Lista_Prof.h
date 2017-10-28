//---------------------------------------------------------------------------

#ifndef Lista_ProfH
#define Lista_ProfH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
class TListaProf : public TForm
{
__published:	// IDE-managed Components
	TListBox *Lista;
	TImage *Finish;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FinishClick(TObject *Sender);
private:	// User declarations
public:
int OK;
char prof_sel[100][100];
int prof_c,k;
		// User declarations
	__fastcall TListaProf(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TListaProf *ListaProf;
//---------------------------------------------------------------------------
#endif
