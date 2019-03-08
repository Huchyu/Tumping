#include "Header.h"





SCENEID SceneState = SCENEID_LOGO;
char* Backgra[8];
int iBack = 0;
int iBackCheck = 0;
int iPosition = 110;
int iButton = 0;

Logo* pLogo = NULL;

void SceneManager();

DWORD InputManager();

void SetCursorPositionString(const int _ix, const int _iy, const char* str, const int _Color);

void SetCursorPositionInteger(const int _ix, const int _iy, const int _Value, const int _Color);

void SetColor(int _Color);

void SceneLogo();

void SceneMenu();

void SceneStage();


int main(void)
{
	pLogo = (Logo*)malloc(sizeof(Logo));

	pLogo->Logo[0] = (char*)"       __                      _             __";
	pLogo->Logo[1] = (char*)"      / /_  ______ ___  ____  (_)___  ____ _/ /";
	pLogo->Logo[2] = (char*)" __  / / / / / __ `__ |/ __ |/ / __ |/ __ `/ / ";
	pLogo->Logo[3] = (char*)"/ /_/ / /_/ / / / / / / /_/ / / / / / /_/ /_/  ";
	pLogo->Logo[4] = (char*)"|____/|__,_/_/ /_/ /_/ .___/_/_/ /_/|__, (_)   ";
	pLogo->Logo[5] = (char*)"                    /_/            /____/      ";
	pLogo->Logo[6] = (char*)"        계속하려면 ENTER 키를 눌러주세요.        ";

	pLogo->Position.x = 0;
	pLogo->Position.y = 5;

	Backgra[0] = (char*)"▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒";
	Backgra[1] = (char*)"╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊";
	Backgra[2] = (char*)"─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─";
	Backgra[3] = (char*)"╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊";
	Backgra[4] = (char*)"▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒";
	Backgra[5] = (char*)"─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─";
	Backgra[6] = (char*)"╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊";
	Backgra[7] = (char*)"─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─";


	DWORD dwTime = GetTickCount();

	while (true)
	{
		if (dwTime + 80 < GetTickCount())
		{
			dwTime = GetTickCount();
			system("cls");


			SceneManager();
		}
	}

	system("pause");
	return 0;
}

void SceneManager()
{
	DWORD dwKey = InputManager();

	switch (SceneState)
	{
	case SCENEID_LOGO:

		SceneLogo();

		if (dwKey & KEY_ENTER)
		{
			SceneState = SCENEID_MENU;
			Sleep(500);
		}

		break;
	case SCENEID_MENU:

		SceneMenu();

		if (dwKey & KEY_ENTER)
		{
			if (iButton == 0)
			{
				SceneState = SCENEID_STAGE;
			}
			else if (iButton == 1)
			{
				SceneState = SCENEID_RANK;
			}
			else
			{
				SceneState = SCENEID_LOGO;
			}
		}

		break;
	case SCENEID_RANK:
		printf_s("점수게시판 아무튼 만들어야지 그치");
		break;
	case SCENEID_STAGE:

		SceneStage();

		break;
	}
}

DWORD InputManager()
{
	DWORD dwKey = 0;

	//** 키 입력
	if (GetAsyncKeyState(VK_UP))
		dwKey |= KEY_UP;

	if (GetAsyncKeyState(VK_DOWN))
		dwKey |= KEY_DOWN;

	if (GetAsyncKeyState(VK_LEFT))
		dwKey |= KEY_LEFT;

	if (GetAsyncKeyState(VK_RIGHT))
		dwKey |= KEY_RIGHT;

	if (GetAsyncKeyState(VK_RETURN))
		dwKey |= KEY_ENTER;

	if (GetAsyncKeyState(VK_SPACE))
		dwKey |= KEY_SPACE;

	if (GetAsyncKeyState(VK_TAB))
		dwKey |= KEY_TAB;

	if (GetAsyncKeyState('W'))
		dwKey |= KEY_W;

	if (GetAsyncKeyState('A'))
		dwKey |= KEY_A;

	if (GetAsyncKeyState('S'))
		dwKey |= KEY_S;

	if (GetAsyncKeyState('D'))
		dwKey |= KEY_D;


	return dwKey;
}

void SetCursorPositionString(const int _ix, const int _iy, const char* str, const int _Color)
{
	//** 좌표를 갖는다.
	COORD Pos;
	Pos.X = _ix;	//* x 좌표 설정
	Pos.Y = _iy;	//* y 좌표 설정

	//** 콘솔창의 권한중 커서의 좌표 이동 권한을 갖는다.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

	//** 함수 정의에서 설명....
	SetColor(_Color);

	//** 문자열 출력
	printf_s("%s", str);
}

void SetCursorPositionInteger(const int _ix, const int _iy, const int _Value, const int _Color)
{
	//** 좌표를 갖는다.
	COORD Pos;
	Pos.X = _ix;	//* x 좌표 설정
	Pos.Y = _iy;	//* y 좌표 설정

	//** 콘솔창의 권한중 커서의 좌표 이동 권한을 갖는다.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

	//** 함수 정의에서 설명....
	SetColor(_Color);

	//** 문자열 출력
	printf_s("%d", _Value);
}

void SetColor(int _Color)
{
	//** 콘솔창의 권한중 커서의 컬러값 변경 권한을 갖는다.
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _Color);
}

void SceneLogo()
{
	for (int i = 0; i < 6; ++i)
	{
		SetCursorPositionString(
			pLogo->Position.x,
			pLogo->Position.y + i,
			pLogo->Logo[i],
			15);
	}

	if (pLogo->Position.x >= 35)
	{
		SetCursorPositionString(35, 15, pLogo->Logo[6], 15);
	}
	else
	{
		pLogo->Position.x += 5;
		Sleep(300);
	}
}

void SceneMenu()
{
	DWORD dwKey = InputManager();

	if (dwKey & KEY_UP)
	{
		if (iButton != 0)
			iButton -= 1;
	}

	if (dwKey & KEY_DOWN)
	{
		if (iButton != 2)
			iButton += 1;
	}

	if (iButton == 0)
		SetCursorPositionString(53, 10, (char*)"▶ 시작하기", 15);
	else
		SetCursorPositionString(55, 10, (char*)"시작하기", 8);

	if (iButton == 1)
		SetCursorPositionString(53, 12, (char*)"▶ 점수보기", 15);
	else
		SetCursorPositionString(55, 12, (char*)"점수보기", 8);

	if (iButton == 2)
		SetCursorPositionString(53, 14, (char*)"▶ 돌아가기", 15);
	else
		SetCursorPositionString(55, 14, (char*)"돌아가기", 8);
}

void SceneStage()
{
	//** 바닥 시작
	switch (iBack)
	{
	case 0:
		for (int i = 0; i < 4; ++i)
		{
			SetCursorPositionString(0, 23 + i, Backgra[i], 14);
		}
		break;
	case 1:
		for (int i = 4; i < 8; ++i)
		{
			SetCursorPositionString(0, 19 + i, Backgra[i], 14);
		}
		break;
	default:
		break;
	}

	if (iBackCheck >= 5)
	{
		iBack = 1;
	}
	if (iBackCheck >= 10)
	{
		iBack = 0;
		iBackCheck = 0;
	}
	else
	{
		iBackCheck++;
	} //* 여기까지 바닥
}