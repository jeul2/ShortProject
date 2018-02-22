#include "player.h"
//80*25
void fnInitialPlayer(S_PLAYER * pSrc)
{
	pSrc->nCenterX = 4;
	pSrc->nCenterY = 0;
	pSrc->nMoveX = 20;
	pSrc->nMoveY = 22;
	pSrc->nX = pSrc->nMoveX - pSrc->nCenterX;
	pSrc->nY = 22;

	pSrc->strPlayer[0] = '(';
	pSrc->strPlayer[1] = '-';
	pSrc->strPlayer[2] = 'O';
	pSrc->strPlayer[3] = '-';
	pSrc->strPlayer[4] = ')';
	pSrc->nPlayerLength = 5;
}
