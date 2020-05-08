//---------------------------------------------------------------------------

#ifndef funcoesjugadorH
#define funcoesjugadorH
//---------------------------------------------------------------------------
#endif
#include <System.hpp>
    class Jogador
{
private:
	AnsiString nome;
	int pontos;
	int tempo;
	int nivel;
	int erradas;


	public:
	// construtor
	Jogador();
	//os get
	int Getnivel();
	AnsiString Getnome();
	int Getpontos();
	int Gettempo();
	int Geterradas();
	void Setnivel(int x);
	//os set

	void Setnome(AnsiString);
	void Setpontos(int);
	void Settempo(int);
	void Setnivel(AnsiString);
	void Seterradas(int);


};