//---------------------------------------------------------------------------

#ifndef Rezultat_TestH
#define Rezultat_TestH
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
#include "Testare_Cunostinte.h"
#include "Mod_Elev.h"
//---------------------------------------------------------------------------
class TRezultatTest : public TForm
{
__published:	// IDE-managed Components
	TRectangle *Top_Bar;
	TLabel *Title;
	TLabel *Rezultat;
	TLabel *RGresit;
	TEdit *Intrebare;
	TLabel *RCorect;
	TMemo *RCorectMemo;
	TImage *Next;
	TImage *Back;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall NextClick(TObject *Sender);
	void __fastcall BackClick(TObject *Sender);
	void __fastcall NextMouseEnter(TObject *Sender);
	void __fastcall NextMouseLeave(TObject *Sender);
	void __fastcall BackMouseEnter(TObject *Sender);
	void __fastcall BackMouseLeave(TObject *Sender);
private:
char* itoa(int value, char* result, int base) {
		// check that the base if valid
		if (base < 2 || base > 36) { *result = '\0'; return result; }

		char* ptr = result, *ptr1 = result, tmp_char;
		int tmp_value;

		do {
			tmp_value = value;
			value /= base;
			*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
		} while ( value );

		// Apply negative sign
		if (tmp_value < 0) *ptr++ = '-';
		*ptr-- = '\0';
		while(ptr1 < ptr) {
			tmp_char = *ptr;
			*ptr--= *ptr1;
			*ptr1++ = tmp_char;
		}
		return result;
	}	// User declarations
public:

int afisare (int pg_cur)
{
char path[1500],numar[10];
int i;
strcpy(path,ModElev->locatie_profesor);
strcat(path,itoa(TestareCunostinte->intrebare[pg_cur].pag,numar,10));
strcat(path,".res");

if (TestareCunostinte->intrebare[pg_cur].pag==0) return 0;

ifstream f(path);
while(!f.eof())
{
	f.getline(path,1500);

}
f.close();
ofstream g("temp.res",std::ios_base::binary);
if (TestareCunostinte->intrebare[pg_cur].poz==1)
{
		for (i=0; i<strlen(path)/3+10; i++)
			g<<path[i];
	g<<"...";
}

else
if (TestareCunostinte->intrebare[pg_cur].poz==2)
{
	g<<"...";
		for (i=strlen(path)/3-10; i<2*strlen(path)/3+10; i++)
			g<<path[i];
	g<<"...";
}

else
if (TestareCunostinte->intrebare[pg_cur].poz==3)
{
	g<<"...";
		for (i=2*strlen(path)/3-10; i<strlen(path); i++)
			g<<path[i];
}

g.close();
RCorectMemo->Lines->LoadFromFile("temp.res",System::Sysutils::TEncoding::UTF8);
//remove("temp.res");

}
// User declarations
	__fastcall TRezultatTest(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRezultatTest *RezultatTest;
//---------------------------------------------------------------------------
#endif
