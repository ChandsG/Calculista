//---------------------------------------------------------------------------

#pragma hdrstop

#include "funcoes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


bool verf(double x, double res)
{
	if (res == x)
		return true;
	else
		return false;
}

double valoresStage1(double &val1, double &val2, double &val3, int nivel)
{
		val1= Random(nivel * 5);
		val2= Random(nivel * 5);
		val3= Random(nivel * 5);
		return(val1 - val2 + val3);
}
double valoresStage2(double &val1, double &val2, double &val3,  int nivel)
{
		val1= Random(nivel * 5);
		val2= Random(nivel * 5);
		val3= Random(nivel * 5);
		return(val1 + val2 * val3);
}

double valoresStage3(double &val1, double &val2, double &val3,  int nivel)
{
		val1= Random(nivel * 5)+1;
		val2= Random(nivel * 5)+1;
		val3= Random(nivel * 5)+1;
		return(val1 * val2 - val3);
}
