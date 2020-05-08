//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.EditBox.hpp>
#include <FMX.NumberBox.hpp>
#include <FMX.ComboEdit.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Layouts.hpp>
#include <System.Rtti.hpp>
#include <FMX.Memo.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.FMXUI.Wait.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FMX.Grid.Style.hpp>
#include <FMX.Media.hpp>
#include <FMX.ScrollBox.hpp>
#include <FireDAC.Comp.UI.hpp>

/*
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>

#include <System.Ioutils.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Phys.SQLiteDef.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>
#include <FireDAC.Comp.UI.hpp>
#include <FireDAC.FMXUI.Wait.hpp>
#include <FMX.Media.hpp>
#include <FMX.Grid.Style.hpp>
#include <FMX.ScrollBox.hpp>        */

//---------------------------------------------------------------------------
class TFormP : public TForm
{
__published:	// IDE-managed Components
	TRectangle *Rectangle1;
	TCornerButton *CornerButton1;
	TCornerButton *CornerButton2;
	TCornerButton *CornerButton3;
	TText *Text1;
	TCircle *Circle1;
	TCircle *Circle2;
	TText *Text2;
	TText *Text3;
	TRectangle *Rectangle2;
	TText *Text4;
	TRectangle *Rectangle3;
	TLine *Line1;
	TLine *Line2;
	TLine *Line3;
	TRectangle *Rectangle4;
	TRectangle *Rectangle5;
	TEdit *Edit1;
	TEdit *Edit2;
	TText *Text5;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TRectangle *Rectangle6;
	TText *Text6;
	TRectangle *Rectangle7;
	TText *Text7;
	TButton *Button13;
	TProgressBar *ProgressBar1;
	TText *Text12;
	TTimer *Timer1;
	TStringGrid *StringGrid1;
	TGroupBox *GroupBox1;
	TRadioButton *RadioButton3;
	TRadioButton *RadioButton4;
	TRadioButton *RadioButton5;
	TButton *Button15;
	TLabel *Label1;
	TRectangle *Rectangle8;
	TCornerButton *CornerButton4;
	TCornerButton *CornerButton5;
	TCornerButton *CornerButton6;
	TCornerButton *CornerButton7;
	TButton *Button12;
	TRectangle *Rectangle9;
	TText *Text11;
	TCornerButton *CornerButton8;
	TRectangle *Rectangle10;
	TText *Text13;
	TText *Text14;
	TStyleBook *StyleBook1;
	TText *Text15;
	TText *Text16;
	TText *Text17;
	TText *Text18;
	TText *Text19;
	TLine *Line4;
	TEdit *Edit4;
	TButton *Button18;
	TTimer *Timer2;
	TCornerButton *CornerButton9;
	TStringColumn *StringColumn1;
	TStringColumn *StringColumn2;
	TStringColumn *StringColumn3;
	TRectangle *Rectangle11;
	TMediaPlayer *MediaPlayer1;
	TRectangle *Rectangle12;
	TFDConnection *FDConnection1;
	TFDGUIxWaitCursor *FDGUIxWaitCursor1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall CornerButton1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall CornerButton3Click(TObject *Sender);
	void __fastcall CornerButton2Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall CornerButton5Click(TObject *Sender);
	void __fastcall RadioButton4Change(TObject *Sender);
	void __fastcall RadioButton3Change(TObject *Sender);
	void __fastcall RadioButton5Change(TObject *Sender);
	void __fastcall Text3Click(TObject *Sender);
	void __fastcall Text2Click(TObject *Sender);
	void __fastcall CornerButton8Click(TObject *Sender);
	void __fastcall Button18Click(TObject *Sender);
	void __fastcall CornerButton7Click(TObject *Sender);
	void __fastcall CornerButton4Click(TObject *Sender);
	void __fastcall CornerButton6Click(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall CornerButton9Click(TObject *Sender);
	void __fastcall Edit4Enter(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
private:	// User declarations

public:		// User declarations
	void IniciarJogo();
	void UpdateJogo();
	double Jogar(int nivel);
	void Certo();
	int Errado();
	void FimDOJogo();
	void ConectarDataBaseDB();
	void MostarRecordsDB();
	void Reiniciar();
	void clik();
	void GuardarPontosDB();
	void ApagarRecordsDB();
	__fastcall TFormP(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormP *FormP;
//---------------------------------------------------------------------------
#endif
