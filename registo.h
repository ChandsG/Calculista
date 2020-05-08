/*
Classe para Manipular Arquivos Ver 0.1 Criado By Chands

LEIA ESTE ACORDO DE LICENÇA ANTES DE USAR O SOFTWARE OU CODIGO FONTE

ACORDO DE LICENÇA E TERMOS DE USO DE SISTEMA DA AVASOFT
Você não pode usar, alugar, arrendar, sub-licenciar, publicar, modificar, adaptar ou traduzir qualquer parte do sistema ou código fonte sem a autorização do autor;
Você não pode criar quaisquer trabalhos derivados, ou de outra forma tentar criar o código de fonte deste sistema a partir do seu código-objecto;
Você não pode usar qualquer trechos de código ou software não autorizado, ilegal, falsificado, ou modificado em ligação com o Software ou código fonte, incluindo o uso de ferramentas para desviar de, incapacitar, ou contornar qualquer mecanismo de codificação, segurança ou autenticação para o sistema;
Você não pode obter o Software ou código fonte de qualquer forma que não seja por intermédio dos métodos de distribuição da AVASOFT ou do autor;

O ACESSO AO OU USO DO SOFTWARE OU CODIGO FONTE ESTÁ EXPRESSAMENTE CONDICIONADO À ACEITAÇÃO DOS TERMOS DESTE ACORDO.

Copyright ©2014 AVASoft, Todos os Direitos Reservado.

*/

/*
---------------------------------------------------------------------------
MODO DE COMO          O ARQUIVO SERÁ ABERTO
r w a	              Abre um arquivo texto
rb wb ab	          Abre um arquivo binário.
r+ w+ a+ 	          Abre um arquivo texto para leitura/escrita.
r+b w+b a+b rb+ wb+ ab+  Abre um arquivo binário para leitura/escrita.
---------------------------------------------------------------------------
*/


//---------------------------------------------------------------------------

#ifndef chandsfileH
#define chandsfileH
//---------------------------------------------------------------------------
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int UserType;

class Archive
{
protected:
	FILE * File;
	char *Mode;
	int State;
	char * Path;

public:
	Archive();
	~Archive();
	int OpenFile(char * Path, char * TempMode);
	int ReadBuffer(char &);
	int ReadBuffers(char *&);
	int WriteBuffer(const char);
	int WriteBuffers(const char *);
	int SeeState();
	int ReadUserData(UserType &buffer,int Quant);
	int WriteUserData(UserType buffer,int Quant);
	char * ReadLines();

	void RewindFile();
	int CopyFile(const int quant,const char * name);
	int RM();
	int RM(const char *);

	void CloseFile();
};
