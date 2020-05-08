//---------------------------------------------------------------------------

#pragma hdrstop

#include "chandsfile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

typedef char Dado;
void InsertArray(Dado *& arry,Dado value, int quant)
{
		Dado * aux;
		aux = new Dado[quant];
		for(int i = 0; i<quant; i++)
				aux[i] = arry[i];
		arry = NULL;
		arry = new Dado[quant+1];
		for(int i = 0; i<quant; i++)
				arry[i] = aux[i];
		delete []aux;
		arry[quant] = value;
}

Archive::Archive()
{
	File = NULL;
	Mode = NULL;
	Path = NULL;
	State = 0;
}

Archive::~Archive()
{
	CloseFile();
}

int Archive::OpenFile(char * TempPath, char * TempMode)
{
	File = fopen(TempPath,TempMode);
	if (File == NULL)
	{
		Mode = NULL;
		State = 0;
        Path = NULL;
		return 0;
	}
	Mode = TempMode;
	Path = TempPath;
	State = 1;
	return 1;
}

int Archive::ReadBuffer(char &buffer)
{
	if (SeeState())
	{
		if (!feof(File))
		{
			buffer = getc(File);
			return 1;
		}
	}
	return 0;
}

int Archive::WriteBuffer(const char buffer)
{
	if (SeeState())
	{
		putc(buffer,File);
		return 1;
	}
	return 0;
}

int Archive::ReadBuffers(char *& buffer)
{
	if (SeeState())
	{
		if (!feof(File))
		{
			fgets(buffer,sizeof(buffer),File);
			if (buffer != NULL)
				return 1;
		}
	}
	return 0;
}

int Archive::WriteBuffers(const char * buffer)
{
	if (SeeState())
	{
		fputs(buffer,File);
		return 1;
	}
	return 0;
}

void Archive::RewindFile()
{
	rewind(File);
}

int Archive::RM()
{
	if (!SeeState())
	   if (!remove(Path))
		   return 1;
	return 0;
}

int Archive::RM(const char * Temp)
{

	if (!SeeState())
	   if (!rename(Path,Temp))
		   return 1;
	return 0;
}

void Archive::CloseFile()
{
	fclose(File);
	Mode = NULL;
	Path = NULL;
	State = 0;
	File = NULL;
}

int Archive::CopyFile(const int quant,const char * name)
{
	char buffer;
	char * number;
	char * nameTemp;
	FILE * FileTemp;
	if (State)
	{
		for (int i = 0; i < quant; i++)
		{
			itoa(i+1,number,10);
			strcpy(nameTemp,name);
			strcat(nameTemp,number);
			FileTemp = fopen(nameTemp,"wb");
			if (FileTemp != NULL)
			{
				RewindFile();
				while (ReadBuffer(buffer))
					putc(buffer,FileTemp);
			}
			else
				return 0;
			fclose(FileTemp);
		}
	}
	else
		return 0;
	return 1;
}

int Archive::SeeState()
{
	if (!feof(File))
		return State;
	return 0;
}

int Archive::ReadUserData(UserType &buffer,int Quant)
{
	if (SeeState())
	{
		if (!feof(File))
		{
			fread(&buffer,sizeof(buffer),Quant,File);
			return 1;
		}
	}
	return 0;
}
int Archive::WriteUserData(UserType buffer,int Quant)
{
	if (SeeState())
	{
		fwrite(&buffer,sizeof(buffer),Quant,File);
		return 1;
	}
	return 0;
}


char * Archive::ReadLines()
{
	char * TextoTemp = new char[0];
	char buf;
	int Continuar = 1;
	buf = 0;
	int i = 0;
	while ((buf != '\n') && (Continuar))
	{
			Continuar = ReadBuffer(buf);
			if ((Continuar) && (buf != '\n'))
			{
				InsertArray(TextoTemp,buf,i);
				i++;
			}
	}
	return TextoTemp;
}//---------------------------------------------------------------------------

#pragma hdrstop

#include "registo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
