#pragma once
struct S_PLAYER
{
	int nCenterX;
	int nCenterY;
	int nMoveX;
	int nMoveY;
	int nX;
	int nY;

	char strPlayer[5];
	int nPlayerLength;
};

void fnInitialPlayer(S_PLAYER *pSrc);