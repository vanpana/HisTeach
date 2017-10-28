//---------------------------------------------------------------------------

#ifndef Testare_CunostinteH
#define Testare_CunostinteH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TTestareCunostinte : public TForm
{
__published:	// IDE-managed Components
	TRectangle *Top_Bar;
	TLabel *Title;
	TGroupBox *Intrebare;
	TRadioButton *R1;
	TRadioButton *R2;
	TRadioButton *R3;
	TRadioButton *R4;
	TImage *Next;
	TTimer *Timer1;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall NextClick(TObject *Sender);
	void __fastcall NextMouseEnter(TObject *Sender);
	void __fastcall NextMouseLeave(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:


void load (int i)
{
	Intrebare->Text=intrebare[i].intrebare;
	R1->Text=intrebare[i].r1;
	R2->Text=intrebare[i].r2;
	R3->Text=intrebare[i].r3;
	R4->Text=intrebare[i].r4;
}

int check ()
{
if (R1->IsChecked==1) return 1;
else if (R2->IsChecked==1) return 2;
else if (R3->IsChecked==1) return 3;
else if (R4->IsChecked==1) return 4;
else return 0;
}
// User declarations

public:
double nota;
int corect[100];
struct q
{
	char intrebare[100],r1[50],r2[50],r3[50],r4[50];
	int rc,pag,poz,ok,corect;
} intrebare[100];
	// User declarations
	__fastcall TTestareCunostinte(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTestareCunostinte *TestareCunostinte;
//---------------------------------------------------------------------------
#endif
