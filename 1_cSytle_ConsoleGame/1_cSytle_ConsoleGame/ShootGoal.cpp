#include <stdio.h>
#include <time.h>
#include <conio.h>

#include "ref.h"
#include "make.h"

//초기화, 업데이트, 렌더, 릴리즈

void fnInitial();
void fnUpdate();
void fnRender();
void fnRelease();

int fnInputKeyChk();

int main()
{
	clock_t tPreTime(0);
	clock_t tCurrrentTime(0);

	int nInput(0);


	//////////
	fnInitial();

	tPreTime = clock();
	while (nInput != -1)
	{
		nInput = fnInputKeyChk();

		fnUpdate();
		fnRender();

		while (1)
		{
			tCurrrentTime = clock();
			if (tCurrrentTime - tPreTime > 33)
			{
				tPreTime = tCurrrentTime;
				break;
			}
		}
	}


	fnRelease();
	//////////
	return 0;
}

void fnInitial()
{
	ScreenInit();
}

void fnUpdate()
{
}

void fnRender()
{
	ScreenClear();
	//printing Screen


	//
	ScreenFlipping();
}

void fnRelease()
{
	ScreenRelease();
}

int fnInputKeyChk()
{
	int nKey(0);

	if (_kbhit())
	{
		nKey = _getch();
		if (nKey == 'q')
			return -1;
		else if (nKey == 'j')
			return 1;
		else if (nKey == 'l')
			return 2;
		else if (nKey == 'k')
			return 3;
	}
	else
		return 0;
}
