//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("Nume_Capitol.cpp", NumeCapitol);
USEFORM("Mod_Profesor.cpp", ModProfesor);
USEFORM("Mod_Elev.cpp", ModElev);
USEFORM("Parcurgere_Lectie.cpp", ParcurgereLectie);
USEFORM("Testare_Cunostinte.cpp", TestareCunostinte);
USEFORM("Rezultat_Test.cpp", RezultatTest);
USEFORM("PopUp_Creare.cpp", PopUpCreare);
USEFORM("Creare_Test.cpp", CreareTest);
USEFORM("Adaugare_Lectie.cpp", AdaugareLectie);
USEFORM("Modificare_Lectie.cpp", ModificareLectie);
USEFORM("Meniu.cpp", Meniu1);
USEFORM("Lista_Prof.cpp", ListaProf);
USEFORM("Ajutor.cpp", Ajutor1);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TMeniu1), &Meniu1);
		Application->CreateForm(__classid(TModProfesor), &ModProfesor);
		Application->CreateForm(__classid(TAdaugareLectie), &AdaugareLectie);
		Application->CreateForm(__classid(TPopUpCreare), &PopUpCreare);
		Application->CreateForm(__classid(TListaProf), &ListaProf);
		Application->CreateForm(__classid(TModificareLectie), &ModificareLectie);
		Application->CreateForm(__classid(TCreareTest), &CreareTest);
		Application->CreateForm(__classid(TModElev), &ModElev);
		Application->CreateForm(__classid(TParcurgereLectie), &ParcurgereLectie);
		Application->CreateForm(__classid(TTestareCunostinte), &TestareCunostinte);
		Application->CreateForm(__classid(TRezultatTest), &RezultatTest);
		Application->CreateForm(__classid(TNumeCapitol), &NumeCapitol);
		Application->CreateForm(__classid(TAjutor1), &Ajutor1);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
