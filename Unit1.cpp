//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
#include "funcoes.h"
#include "funcoesjugador.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.LgXhdpiPh.fmx", _PLAT_ANDROID)
#pragma resource ("*.SmXhdpiPh.fmx", _PLAT_ANDROID)

TFormP *FormP;
Jogador joga;
double Respostas;
int Tempo = 30;
int ControloTempo;
int MaximoErrada = 5;
int Socorro = 3;
int ControloSocorro;
int Saltar = 3;
int ControloSaltar;

void TFormP::IniciarJogo()
{
	joga.Setnivel(1);
	joga.Seterradas(0);
	joga.Setpontos(0);
	joga.Setnome(Edit4->Text);
	ProgressBar1->Value = 0;
	ControloSocorro = Socorro;
	ControloSaltar = Saltar;

}
void TFormP::Reiniciar()
{
	Edit4->Text = "NOME";
	Text16->Text = "PONTOS";
	Text19->Text = "NÍVEL";
	Text17->Text = "ERRADA";
	Text18->Text = "TEMPO";
}

void TFormP::clik()
{

	MediaPlayer1->FileName = "cliqueO.mp3";
   	MediaPlayer1->Stop();
	MediaPlayer1->Play();

}

void TFormP::UpdateJogo()
{
	Text16->Text = "Pontos\n"+IntToStr(joga.Getpontos());
	Text19->Text = "Nível\n"+IntToStr(joga.Getnivel());
	Text17->Text = "Errada\n"+IntToStr(joga.Geterradas());
	Text18->Text = "Tempo\n"+IntToStr(Tempo);
	Edit2->Text = "";
	ControloTempo = Tempo;
	Timer2->Enabled = true;
	Respostas = Jogar(joga.Getnivel());
}

double TFormP::Jogar(int nivel)
{
	   double val1, val2, val3, r;
	   if (RadioButton4->IsChecked)
	   {
			r = valoresStage1(val1,val2,val3,nivel);
			Edit1->Text = (FloatToStr(val1)+" - "+FloatToStr(val2)+" + "+FloatToStr(val3));
	   }
	   else if(RadioButton3->IsChecked)
	   {
			r = valoresStage2(val1,val2,val3,nivel);
			Edit1->Text = (FloatToStr(val1)+" + "+FloatToStr(val2)+" x "+FloatToStr(val3));
	   }
	   else
	   {
			r = valoresStage3(val1,val2,val3,nivel);
			Edit1->Text = (FloatToStr(val1)+" x "+FloatToStr(val2)+" - "+FloatToStr(val3));
	   }
	   return r;
}

void TFormP::Certo()
{
	ProgressBar1->Value = ProgressBar1->Value + 1;
	joga.Setpontos(joga.Getpontos() + joga.Getnivel() * 10);
	if (ProgressBar1->Value == ProgressBar1->Max)
	{
		int i = joga.Getnivel() + 1;
		ShowMessage("Parabéns você passou\n Estas agora no nível "+IntToStr(i));
		joga.Setnivel(i);
		joga.Seterradas(0);
		ProgressBar1->Value = 0;
	}
}
int TFormP::Errado()
{
	joga.Seterradas(joga.Geterradas()+1);
	if (joga.Geterradas() == MaximoErrada)
	{
		ShowMessage("Fím do Jogo ");
		return 1;
	}
	return 0;
}

void TFormP::FimDOJogo()
{
   GuardarPontosDB();
   IniciarJogo();
   ControloTempo = Tempo;
   Timer2->Enabled = false;
   Rectangle1->Visible = true;
   Rectangle2->Visible = false;


}

void TFormP::GuardarPontosDB()
{

	if (joga.Getpontos() == 0)
	{
		return;
	}
	TFDQuery *query;
	query = new TFDQuery(NULL);
	__try
	{
		query->Connection = FDConnection1;
		AnsiString arguments[3];
		arguments[0] =  "\'"+joga.Getnome()+"\'";
		arguments[1] =  "\'"+IntToStr(joga.Getpontos())+"\'";
		arguments[2] =  "\'"+Date().DateString()+"\'";
		query->SQL->Text = "Insert into records (nome, pontos, data) values("+
		arguments[0]+","+arguments[1]+","+arguments[2]+")";
		query->ExecSQL();

	}
	__finally
	{
		query->Close();
		query->DisposeOf();
	}
}
void TFormP::ConectarDataBaseDB()
{
	AnsiString Caminho = "calculista.avadb";
	FDConnection1->DriverName = "SQLite";
	FDConnection1->Params->Values["DataBase"] = "../../Calculista/calculista.avadb";
	try
	{
		FDConnection1->Open();
	}
	catch (Exception& E)
	{
		ShowMessage("Ocorreu um erro ao conectar a Base de Dados: " + E.Message);
	}
}
void TFormP::MostarRecordsDB()
{
	TFDQuery *query;
	query = new TFDQuery(NULL);
	//StringGrid1 = new TStringGrid(StringGrid1);
	__try
	{
		query->Connection = FDConnection1;
		query->SQL->Text = "SELECT * FROM records order by pontos desc";
		query->Open();

		int i=1;
		while (!query->Eof)
		{

			AnsiString arguments[3] = {query->FieldByName("nome")->AsString,
			query->FieldByName("pontos")->AsInteger,query->FieldByName("data")->AsString};
			query->Next();
			StringGrid1->Cells [0][i] = arguments[0];
			StringGrid1->Cells [1][i] = arguments[1];
			StringGrid1->Cells [2][i] = arguments[2];

			i++;

		}
	}
	__finally
	{
		query->Close();
		query->DisposeOf();
	}
}

void TFormP::ApagarRecordsDB()
{
	TFDQuery *query;
	query = new TFDQuery(NULL);
	__try
	{
		query->Connection = FDConnection1;
		query->SQL->Text = "delete from records";
		query->ExecSQL();
	}
	__finally
	{
		query->Close();
		query->DisposeOf();
	}
}
//---------------------------------------------------------------------------
__fastcall TFormP::TFormP(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TFormP::FormCreate(TObject *Sender)
{

	   Rectangle1->Visible = true;
	   Rectangle2->Visible = false;
	   Rectangle6->Visible = false;
	   Rectangle7->Visible = false;
	   Rectangle9->Visible = false;
	   Rectangle11->Visible = false;
	   RadioButton4->IsChecked = true;
	   ConectarDataBaseDB();
}
//---------------------------------------------------------------------------




void __fastcall TFormP::CornerButton1Click(TObject *Sender)
{
	Rectangle2->Visible = true;
	Rectangle1->Visible = false;
	Rectangle2->Enabled = false;
	Rectangle11->Visible = true;
	Edit4->Text = "Seu nome aqui, por favor...";
	Text15->Text = " Nome ";
}
//---------------------------------------------------------------------------


void __fastcall TFormP::Button1Click(TObject *Sender)
{
Edit2->Text = Edit2->Text+0;
}
//---------------------------------------------------------------------------

void __fastcall TFormP::Button2Click(TObject *Sender)
{
clik();
Edit2->Text = Edit2->Text+1;
}
//---------------------------------------------------------------------------

void __fastcall TFormP::Button3Click(TObject *Sender)
{
clik();
Edit2->Text = Edit2->Text+2;
}
//---------------------------------------------------------------------------

void __fastcall TFormP::Button4Click(TObject *Sender)
{
clik();
Edit2->Text = Edit2->Text+3;
}
//---------------------------------------------------------------------------

void __fastcall TFormP::Button5Click(TObject *Sender)
{
clik();
Edit2->Text = Edit2->Text+4;

}
//---------------------------------------------------------------------------

void __fastcall TFormP::Button6Click(TObject *Sender)
{
clik();
Edit2->Text = Edit2->Text+5;
}
//---------------------------------------------------------------------------


void __fastcall TFormP::Button7Click(TObject *Sender)
{
clik();
Edit2->Text = Edit2->Text+6;
}
//---------------------------------------------------------------------------

void __fastcall TFormP::Button8Click(TObject *Sender)
{
clik();
Edit2->Text = Edit2->Text+7;
}
//---------------------------------------------------------------------------

void __fastcall TFormP::Button9Click(TObject *Sender)
{
clik();
Edit2->Text = Edit2->Text+8;
}
//---------------------------------------------------------------------------

void __fastcall TFormP::Button10Click(TObject *Sender)
{
clik();
Edit2->Text = Edit2->Text+9;
}
//---------------------------------------------------------------------------



void __fastcall TFormP::CornerButton3Click(TObject *Sender)
{   //Design
	//RadioButton4->IsChecked = true;
	Rectangle6->Visible = true;
	Rectangle1->Visible = false;
	RadioButton3->Visible = true;
	RadioButton3->Visible = true;
	//fim Design
}
//---------------------------------------------------------------------------

void __fastcall TFormP::CornerButton2Click(TObject *Sender)
{
//Design
	Rectangle7->Visible = true;
	Rectangle1->Visible = false;
	StringGrid1->Cells[0][0]="Nome";
	StringGrid1->Cells[1][0]="Pontos";
	StringGrid1->Cells[2][0]="Data";

	MostarRecordsDB();
//fim Design
}
//---------------------------------------------------------------------------

void __fastcall TFormP::Button11Click(TObject *Sender)
{
	//fim Design
		if (Edit2->Text != "")
		{
			return;
		}
		Edit2->Text = Edit2->Text+"-";
	//fim Design
}
//---------------------------------------------------------------------------

void __fastcall TFormP::Timer1Timer(TObject *Sender)
{
	//fim Design
		Text12->Text = Date().CurrentTime(); //  TimeToStr (Now());
	//fim Design
}
//---------------------------------------------------------------------------


void __fastcall TFormP::Button15Click(TObject *Sender)
{
//fim Design
	Rectangle6 ->Visible = false;
	Rectangle1 ->Visible = true;
//fim Design
}
//---------------------------------------------------------------------------

void __fastcall TFormP::Button13Click(TObject *Sender)
{
//fim Design
	   Rectangle7->Visible = false;
	   Rectangle1->Visible = true;
//fim Design
}
//---------------------------------------------------------------------------


void __fastcall TFormP::CornerButton5Click(TObject *Sender)
{
	int i = (MessageDlg("Voce Realmente Deseja Disistir do Jogo?"
	"\nSua pontuação final sera a sua pontuação actual...",TMsgDlgType::mtInformation,
	TMsgDlgButtons() << TMsgDlgBtn::mbYes << TMsgDlgBtn::mbNo, 0));
	if (i == mrNo)
	{
		return;
	}
	FimDOJogo();
	Reiniciar();
}
//---------------------------------------------------------------------------

void __fastcall TFormP::RadioButton4Change(TObject *Sender)
{
//fim Design
	if ( RadioButton4->IsChecked == true )
		Label1-> Text = "O jugadores tem o previlegio de resolver calculos das duas operações aritméticas basícas :Subtração e Soma, onde os numeros gerados são tão menor quanto possível";
	//fim Design

}
//---------------------------------------------------------------------------

void __fastcall TFormP::RadioButton3Change(TObject *Sender)
{
//fim Design
	if ( RadioButton3->IsChecked == true )
				Label1-> Text = "O jugadores tem o previlegio de resolver calculos das duas operações aritmética basícas: Soma e Multiplicação, onde os numeros gerados são tão menor quanto possível.  ";

//fim Design
}
//---------------------------------------------------------------------------

void __fastcall TFormP::RadioButton5Change(TObject *Sender)
{
//fim Design
	if ( RadioButton5->IsChecked == true )
				Label1-> Text = "O jugadores tem o previlegio de resolver calculos das duas operações aritmética basícas: Multiplicação e Subtração, onde os numeros gerados são tão complexo quanto possível. ";
	//fim Design
}
//---------------------------------------------------------------------------



void __fastcall TFormP::Text3Click(TObject *Sender)
{
//fim Design
	Rectangle1->Visible = false;
	Rectangle9->Visible = true;
	Text11-> Text = Text3->Text;
	CornerButton8->Text =" FECHAR "+Text11-> Text;
	Text13->Text = "";
	 Text13->Text = "\n"

	 "	As regras do jogo são bastante simples quanto possível\n"
	 " Assim para o melhor aprendizado aconselha-se em não "
	 " fazer o uso de qualquer calaculadora das mais simples as"
	 " mais avançada ou software que gera resultado de forma outomático\n\n"

	 "COMO JOGAR\n"
	 "1º Ao iniciar, os calculos veem automatico e de forma aleartorio\n"
	 "2º Após os calculos, responda e de sguida presione entre ou clique no Botão OK\n "
	 "3º se a sua resposta  para verificar se a sua resposta esta certa ou errada\n"
	 "\n\n\tAVASoft Copyright ©2015, Todos os Direitos Reservado.";
//fim Design
}
//---------------------------------------------------------------------------

void __fastcall TFormP::Text2Click(TObject *Sender)
{
//fim Design
	Rectangle1->Visible = false;
	Rectangle9->Visible = true;
	Text11->Text = Text2->Text;
	CornerButton8->Text =" FECHAR O "+Text11-> Text;
	Text13->Text = "";
	Text13->Text = "\n"
"  \t\t\tCalculista 1.2\n"
"   Desenvolvido por Mendonça S. Lucas Viana e Chands\n\n"
"	Apoio: One Love Produções & Groupo FLV Lda\n"
"	Design Lucas Ngonda Viana.\n"
"	Plataforma: Windows e para Android.\n\n"
"	Calculista Versão : 1.2 é Distribuido por...\n"
"   \tCompania LucaSoft Lda\n"
//"   \rCompania LucaSoft Lda"
"	www.avasoft.besaba.com\n"
"\tAVASoft Copyright ©2015, Todos os Direitos Reservado.";
//fim Design
}
//---------------------------------------------------------------------------

void __fastcall TFormP::CornerButton8Click(TObject *Sender)
{
//fim Design
	Rectangle9->Visible = false;
	Rectangle1->Visible = true;
//fim Design
}
//---------------------------------------------------------------------------




void __fastcall TFormP::Button18Click(TObject *Sender)
{
	if (Edit4->Text=="Seu nome aqui, por favor..."||Edit4->Text=="")
				   Edit4->Text = "Jogador";

	// inicio do jogo
	IniciarJogo();
	Text15->Text = joga.Getnome();
	Rectangle2->Enabled = true;
	Rectangle11->Visible =false;
	UpdateJogo();

}
//---------------------------------------------------------------------------




void __fastcall TFormP::CornerButton7Click(TObject *Sender)
{
	if ( Edit2->Text =="" )
	 {
		return;
	 }
	 Timer2->Enabled = false;
	 bool Ver = verf(Respostas,StrToInt(Edit2->Text));
	 if (Ver)
	 {
		Certo();
	 }
	 else
	 {
		if (Errado())
		{
			FimDOJogo();
			return;
		}
	}
	UpdateJogo();
	Edit2->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TFormP::CornerButton4Click(TObject *Sender)
{
	if (ControloSaltar == 0)
	{
		ShowMessage("Ja não podes pular mais");
		return;
	}
	UpdateJogo();
	ControloSaltar--;
	ShowMessage("\nVoce pode pular mais "+IntToStr(ControloSaltar)+" calculos");

}
//---------------------------------------------------------------------------

void __fastcall TFormP::CornerButton6Click(TObject *Sender)
{
	if (ControloSocorro == 0)
	{
		ShowMessage("Ja não podes usar mais ajuda");
		return;
	}
	ControloSocorro--;
	ShowMessage("A repostas Certa é:"+FloatToStr(Respostas)+
	"\nVoce pode usuar mais "+IntToStr(ControloSocorro)+" vezes a ajuda");
}
//---------------------------------------------------------------------------



void __fastcall TFormP::Timer2Timer(TObject *Sender)
{
	ControloTempo--;
	Text18->Text = "Tempo\n"+IntToStr(ControloTempo);
	if (ControloTempo == 0)
	{
		ControloTempo = Tempo;
		Timer2->Enabled = false;
		ShowMessage("O Tempo Esgotou");
		if (Errado())
		{

			FimDOJogo();
			return;
		}
		UpdateJogo();
	}
}
//---------------------------------------------------------------------------




void __fastcall TFormP::CornerButton9Click(TObject *Sender)
{
	Edit2->Text ="";
}
//---------------------------------------------------------------------------






void __fastcall TFormP::Edit4Enter(TObject *Sender)
{
	Edit4->Text="";
}
//---------------------------------------------------------------------------





void __fastcall TFormP::Button12Click(TObject *Sender)
{

	int i = (MessageDlg("Voce Realmente Deseja Apagar Todas as Suas Pontuações?"
	"\nEsta operação não tem volta...",TMsgDlgType::mtInformation,
	TMsgDlgButtons() << TMsgDlgBtn::mbYes << TMsgDlgBtn::mbNo, 0));
	if (i == mrNo)
	{
		return;
	}
	ApagarRecordsDB();
	MostarRecordsDB();
}
//---------------------------------------------------------------------------


