#include "preheader.h"

//초기화, 업데이트, 렌더, 릴리즈

S_PLAYER sPlayer{};

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
	int nRemain(0);

	//////////
	fnInitial();
	fnInitialPlayer(&sPlayer);


	tPreTime = clock();
	while (nInput != -1)
	{
		nInput = fnInputKeyChk();
		if (nInput == -1)
			break;
		else if (nInput == 1)//j
		{
			sPlayer.nMoveX--;
			nRemain = sPlayer.nPlayerLength - (sPlayer.nCenterX + 1);

			if (sPlayer.nMoveX - sPlayer.nCenterX < 0 ||
				sPlayer.nMoveX + nRemain > 79)
				sPlayer.nMoveX--;

			sPlayer.nX = sPlayer.nMoveX - sPlayer.nCenterX;
		}
		else if (nInput == 2)//l
		{
			sPlayer.nMoveX++;
			nRemain = sPlayer.nPlayerLength - (sPlayer.nCenterX + 1);

			if (sPlayer.nMoveX - sPlayer.nCenterX < 0 ||
				sPlayer.nMoveX + nRemain > 79)
				sPlayer.nMoveX++;

			sPlayer.nX = sPlayer.nMoveX - sPlayer.nCenterX;
		}
		else if (nInput == 3)//k
		{

		}


		fnUpdate();
		fnRender();
		/*
		while (1)
		{
			tCurrrentTime = clock();
			if (tCurrrentTime - tPreTime > 33)
			{
				tPreTime = tCurrrentTime;
				break;
			}
		}
		*/
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
	char str[100]{};
	ScreenClear();
	//printing Screen
	
	if (sPlayer.nX < 0)
		ScreenPrint(0, sPlayer.nMoveY, &sPlayer.strPlayer[sPlayer.nX*-1]);
	else if (sPlayer.nMoveX + (sPlayer.nPlayerLength - sPlayer.nCenterX + 1) > 79)
	{
		strncat(str, sPlayer.strPlayer,
			sPlayer.nPlayerLength - ((sPlayer.nMoveX + sPlayer.nCenterX + 1) - 79));

		ScreenPrint(sPlayer.nX, sPlayer.nY, str);
	}
	else
	{
		ScreenPrint(sPlayer.nX, sPlayer.nY, sPlayer.strPlayer);
	}

	sprintf(str, "주인공 이동 좌표 : %d, %d", sPlayer.nMoveX, sPlayer.nY);
	ScreenPrint(0, 0, str);

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
	return 0;
}
