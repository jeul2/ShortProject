#include <stdio.h>
#include <time.h>

#include "ref.h"
#include "make.h"

//�ʱ�ȭ, ������Ʈ, ����, ������

void fnInitial();
void fnUpdate();
void fnRender();
void fnRelease();

int main()
{
	clock_t tPreTime(0);
	clock_t tCurrrentTime(0);



	//////////
	fnInitial();

	tPreTime = clock();
	while (1)
	{

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