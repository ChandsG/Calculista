//---------------------------------------------------------------------------

#pragma hdrstop

#include "funcoesjugador.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


Jogador::Jogador()
{

	pontos = 0;
	nivel = 1;
	tempo = 0;
	erradas = 0;
}

AnsiString Jogador::Getnome()
{
	return nome;
}

void Jogador::Setnome(AnsiString x)
{
	nome = x;
}
////////////gets/////////////
int Jogador:: Getpontos()
{
	return pontos;
}

void Jogador::Setpontos( int x)
{
	pontos = x;
}
void Jogador::Seterradas( int x)
{
	erradas = x;
}
/////////////////////
int Jogador::Gettempo()
{
	return tempo;
}
void Jogador::Settempo( int x)
{
	tempo = x;
}
///////////////
int Jogador:: Getnivel()
{
	return nivel;
}
int Jogador:: Geterradas()
{
	return erradas;
}
void Jogador::Setnivel(int x)
{
	nivel = x;
}