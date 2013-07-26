// Beep.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "Beep.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

#define R		32767
#define O0_D	37
#define O0_Ds	39
#define O0_Ef	O0_Ds
#define O0_E	41
#define O0_F	44
#define O0_Fs	46
#define O0_Gf	O0_Fs
#define O0_G	49
#define O0_Gs	52
#define O0_Af	O0_Gs
#define O0_A	55
#define O0_As	58
#define O0_Bf	O0_As
#define O0_B	62

#define O1_C	65
#define O1_Cs	69
#define O1_Df	O1_Cs
#define O1_D	73
#define O1_Ds	78
#define O1_Ef	O1_Ds
#define O1_E	82
#define O1_F	87
#define O1_Fs	92
#define O1_Gf	O1_Fs
#define O1_G	98
#define O1_Gs	103
#define O1_Af	O1_Gs
#define O1_A	110
#define O1_As	117
#define O1_Bf	O1_As
#define O1_B	123

#define O2_C	131
#define O2_Cs	139
#define O2_Df	O2_Cs
#define O2_D	147
#define O2_Ds	156
#define O2_Ef	O2_Ds
#define O2_E	165
#define O2_F	175
#define O2_Fs	185
#define O2_Gf	O2_Fs
#define O2_G	196
#define O2_Gs	208
#define O2_Af	O2_Gs
#define O2_A	220
#define O2_As	233
#define O2_Bf	O2_As
#define O2_B	247

#define O3_C	262
#define O3_Cs	277
#define O3_Df	O3_Cs
#define O3_D	294
#define O3_Ds	311
#define O3_Ef	O3_Ds
#define O3_E	330
#define O3_F	349
#define O3_Fs	370
#define O3_Gf	O3_Fs
#define O3_G	392
#define O3_Gs	415
#define O3_Af	O3_Gs
#define O3_A	440
#define O3_As	466
#define O3_Bf	O3_As
#define O3_B	494

#define O4_C	523
#define O4_Cs	554
#define O4_Df	O4_Cs
#define O4_D	587
#define O4_Ds	622
#define O4_Ef	O4_Ds
#define O4_E	659
#define O4_F	698
#define O4_Fs	734
#define O4_Gf	O4_Fs
#define O4_G	784
#define O4_Gs	831
#define O4_Af	O4_Gs
#define O4_A	880
#define O4_As	932
#define O4_Bf	O4_As
#define O4_B	988

#define O5_C	1047
#define O5_Cs	1109
#define O5_Df	O5_Cs
#define O5_D	1175
#define O5_Ds	1245
#define O5_Ef	O5_Ds
#define O5_E	1319
#define O5_F	1397
#define O5_Fs	1480
#define O5_Gf	O5_Fs
#define O5_G	1568
#define O5_Gs	1661
#define O5_Af	O5_Gs
#define O5_A	1760
#define O5_As	1865
#define O5_Bf	O5_As
#define O5_B	1976

#define O6_C	2093
#define O6_Cs	2217
#define O6_Df	O6_Cs
#define O6_D	2349
#define O6_Ds	2489
#define O6_Ef	O6_Ds
#define O6_E	2637
#define O6_F	2794
#define O6_Fs	2960
#define O6_Gf	O6_Fs
#define O6_G	3136
#define O6_Gs	3322
#define O6_Af	O6_Gs
#define O6_A	3520
#define O6_As	3729
#define O6_Bf	O6_As
#define O6_B	3951

#define O7_C	4186
#define O7_Cs	4435
#define O7_Df	O7_Cs
#define O7_D	4699
#define O7_Ds	4978
#define O7_Ef	O7_Ds
#define O7_E	5274
#define O7_F	5588
#define O7_Fs	5920
#define O7_Gf	O7_Fs
#define O7_G	6272
#define O7_Gs	6645
#define O7_Af	O7_Gs
#define O7_A	7040
#define O7_As	7459
#define O7_Bf	O7_As
#define O7_B	7902

#define O8_C	8372
#define O8_Cs	8870
#define O8_Df	O8_Cs
#define O8_D	9397
#define O8_Ds	9956
#define O8_Ef	O8_Ds
#define O8_E	10548
#define O8_F	11175
#define O8_Fs	11840
#define O8_Gf	O8_Fs
#define O8_G	12544
#define O8_Gs	13290
#define O8_Af	O8_Gs
#define O8_A	14080
#define O8_As	14917
#define O8_Bf	O8_As
#define O8_B	15804

#define O9_C	16744
#define O9_Cs	17739
#define O9_Df	O9_Cs
#define O9_D	18794
#define O9_Ds	19912
#define O9_Ef	O9_Ds
#define O9_E	21096
#define O9_F	22350
#define O9_Fs	23679
#define O9_Gf	O9_Fs
#define O9_G	25087
#define O9_Gs	26579
#define O9_Af	O9_Gs
#define O9_A	28160
#define O9_As	29834
#define O9_Bf	O9_As
#define O9_B	33488

int note( int tempo, int note )
{
	return (240000/(tempo*note));
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	if ( argc <= 1 )
	{
		Beep( O4_A, 100 );
		return 1;
	}

	if ( _strcmpi(argv[1], _T("coin")) == 0 )
	{
		_tprintf(_T("super mario brothers - get the coin.\n"));
		int l = (60000/180);
		Beep( O6_B, l/4 );
		Beep( O7_E, l/4 + l/2 );
		return 0;
	}
	
	if ( _strcmpi(argv[1], _T("1up")) == 0 )
	{
		_tprintf(_T("super mario brothers - mario 1 up.\n"));
		int l = (60000/120);
		Beep( O6_E, l/4 );
		Beep( O6_G, l/4 );
		Beep( O7_E, l/4 );
		Beep( O7_C, l/4 );
		Beep( O7_D, l/4 );
		Beep( O7_G, l/4 );
		return 0;
	}

	if ( _strcmpi(argv[1], _T("mario")) == 0 )
	{
		_tprintf(_T("super mario brothers - intro\n"));
		int l = (60000/195);
		Beep( O5_E, l/2 );
		Beep( O5_E, l/2 );
		Beep( R, l/2 );
		Beep( O5_E, l/2 );
		Beep( R, l/2 );
		Beep( O5_C, l/2 );
		Beep( O5_E, l/2 );
		Beep( R, l/2 );
		Beep( O5_G, l/2 );
		return 0;
	}

	if ( _strcmpi(argv[1], _T("mario_ug")) == 0 )
	{
		_tprintf(_T("super mario brothers - underground\n"));
		int l = (60000/90);
		Beep( O4_C, l/4 );
		Beep( O5_C, l/4 );
		Beep( O3_A, l/4 );
		Beep( O4_A, l/4 );
		Beep( O3_Bf, l/4 );
		Beep( O4_Bf, l/4 );
		return 0;
	}

	if ( _strcmpi(argv[1], _T("mario_go")) == 0 )
	{
		_tprintf(_T("super mario brothers - game over\n"));
		int l = (60000/195);
		Beep( O5_C, l );
		Beep( R, l/2 );
		Beep( O4_G, l );
		Beep( R, l/2 );
		Beep( O4_E, l );

		Beep( O4_A, l*2/3 );
		Beep( O4_B, l*2/3 );
		Beep( O4_A, l*2/3 );
		Beep( O4_Af, l*2/3 );
		Beep( O4_Bf, l*2/3 );
		Beep( O4_Af, l*2/3 );
		Beep( O4_G, l*2 );
		return 0;
	}

	if ( _strcmpi(argv[1], _T("mario_star")) == 0 )
	{
		_tprintf(_T("super mario brothers - star theme\n"));
		int l = (60000/144);
		Beep( O5_C, l/2 );
		Beep( O5_C, l/2 );
		Beep( O5_C, l/2 );
		Beep( O4_D, l/4 );
		Beep( O5_C, l/2 );
		Beep( O5_C, l/2 );
		Beep( O4_D, l/4 );
		Beep( O5_C, l/4 );
		Beep( O4_D, l/4 );
		Beep( O5_C, l/2 );

		Beep( O4_B, l/2 );
		Beep( O4_B, l/2 );
		Beep( O4_B, l/2 );
		Beep( O4_C, l/4 );
		Beep( O4_B, l/2 );
		Beep( O4_B, l/2 );
		Beep( O4_C, l/4 );
		Beep( O4_B, l/4 );
		Beep( O4_C, l/4 );
		Beep( O4_B, l/2 );
		return 0;
	}

	if ( _strcmpi(argv[1], _T("mario_uw")) == 0 )
	{
		_tprintf(_T("super mario brothers - under water theme\n"));
		int l = (60000/220);
		Beep( O4_D, l );
		Beep( O4_E, l );
		Beep( O4_Fs, l );
		Beep( O4_G, l );
		Beep( O4_A, l );
		Beep( O4_As, l );
		Beep( O4_B, l/2 );
		Beep( O4_B, l/2 );
		Beep( O4_B, l );
		Beep( O4_B, l );
		Beep( O4_B, l*2 );
		return 0;
	}

	if ( _strcmpi(argv[1], _T("mario_goal")) == 0 )
	{
		_tprintf(_T("super mario brothers - goal theme\n"));
		int l = (60000/144);
		Beep( O3_G, l/3 );
		Beep( O4_C, l/3 );
		Beep( O4_E, l/3 );
		Beep( O4_G, l/3 );
		Beep( O5_C, l/3 );
		Beep( O5_E, l/3 );
		Beep( O5_G, l );
		Beep( O5_E, l );
		Beep( O3_Gs, l/3 );
		Beep( O4_C, l/3 );
		Beep( O4_F, l/3 );
		Beep( O4_Gs, l/3 );
		Beep( O5_C, l/3 );
		Beep( O5_F, l/3 );
		Beep( O5_Gs, l );
		Beep( O5_F, l );
		Beep( O3_As, l/3 );
		Beep( O4_D, l/3 );
		Beep( O4_F, l/3 );
		Beep( O4_As, l/3 );
		Beep( O5_D, l/3 );
		Beep( O5_F, l/3 );
		Beep( O5_As, l );
		Beep( O5_As, l/3 );
		Beep( O5_As, l/3 );
		Beep( O5_As, l/3 );
		Beep( O6_C, l+l/2 );
		return 0;
	}

	if ( _strcmpi(argv[1], _T("ff_fin")) == 0 )
	{
		_tprintf(_T("FINAL FANTASY - Battle fin Fanfare.\n"));
		int l = (60000/135);
		Beep( O5_D, l/4 );
		Beep( O5_D, l/4 );
		Beep( O5_D, l/4 );
		Beep( O5_D, l );
		Beep( O4_Bf, l );
		Beep( O5_C, l );
		Beep( O5_D, l/4 );
		Beep( R, l/2 );
		Beep( O5_C, l/4 );
		Beep( O5_D, l*3 );
		return 0;
	}
	
	if ( _strcmpi(argv[1], _T("dq_lvup")) == 0 )
	{
		_tprintf(_T("Dragon Quest - Level up.\n"));
		int l = (60000/120);
		Beep( O6_F, l/4 );
		Beep( O6_F, l/4 );
		Beep( O6_F, l/4 );
		Beep( O6_F, l/4 );
		Beep( R, l/4 );
		Beep( O6_Ef, l/4 );
		Beep( R, l/4 );
		Beep( O6_G, l/4 );
		Beep( R, l/4 );
		Beep( O6_F, l );
		return 0;
	}

	if ( _strcmpi(argv[1], _T("xevious")) == 0 )
	{
		_tprintf(_T("Xevious - intro.\n"));
		int l = (60000/150);

		Beep( O6_F, l + l/3 );
		Beep( R, l/3 );
		Beep( O6_C, l/3 );

		Beep( O6_F, l/3 );
		Beep( O6_A, l/3 );
		Beep( O7_C, l/3 );

		Beep( O6_A, l/3 );
		Beep( R, l/3 );
		Beep( O6_F, l/3 );

		Beep( O6_G, l/3 );
		Beep( R, l/3 );
		Beep( O6_G, l/3 );

		Beep( O6_G, l/3 );
		Beep( R, l/3 );
		Beep( O6_D, l/3*2 );
		Beep( R, l/3 );
		Beep( O6_G, l/3 );
		Beep( O6_F, l/3 );
		Beep( R, l/3 );
		Beep( O6_E, l/3 );
		Beep( O6_F, l + l/3 );
		Beep( R, l/3 );
		Beep( O6_C, l/3 );
		Beep( O6_F, l/3 );
		Beep( O6_A, l/3 );
		Beep( O7_C, l/3 );
		Beep( O6_A, l/3 );
		Beep( R, l/3 );
		Beep( O6_F, l/3 );
		Beep( O6_Gf, l/3 );
		Beep( R, l/3 );
		Beep( O6_Gf, l/3 );
		Beep( O6_Gf, l/3 );
		Beep( R, l/3 );
		Beep( O6_F, l + l/3 );

		return 0;
	}

	_tprintf(_T("COM > I unknown this parameter [%s].\n"), argv[1]);

	return 1;
}
