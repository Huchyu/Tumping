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
	pLogo->Logo[6] = (char*)"        ����Ϸ��� ENTER Ű�� �����ּ���.        ";

	pLogo->Position.x = 0;
	pLogo->Position.y = 5;

	Backgra[0] = (char*)"�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�";
	Backgra[1] = (char*)"�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡��";
	Backgra[2] = (char*)"���䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡";
	Backgra[3] = (char*)"�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡��";
	Backgra[4] = (char*)"�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�";
	Backgra[5] = (char*)"���䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡";
	Backgra[6] = (char*)"�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡��";
	Backgra[7] = (char*)"���䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡�䦡";


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
		printf_s("�����Խ��� �ƹ�ư �������� ��ġ");
		break;
	case SCENEID_STAGE:

		SceneStage();

		break;
	}
}

DWORD InputManager()
{
	DWORD dwKey = 0;

	//** Ű �Է�
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
	//** ��ǥ�� ���´�.
	COORD Pos;
	Pos.X = _ix;	//* x ��ǥ ����
	Pos.Y = _iy;	//* y ��ǥ ����

	//** �ܼ�â�� ������ Ŀ���� ��ǥ �̵� ������ ���´�.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

	//** �Լ� ���ǿ��� ����....
	SetColor(_Color);

	//** ���ڿ� ���
	printf_s("%s", str);
}

void SetCursorPositionInteger(const int _ix, const int _iy, const int _Value, const int _Color)
{
	//** ��ǥ�� ���´�.
	COORD Pos;
	Pos.X = _ix;	//* x ��ǥ ����
	Pos.Y = _iy;	//* y ��ǥ ����

	//** �ܼ�â�� ������ Ŀ���� ��ǥ �̵� ������ ���´�.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

	//** �Լ� ���ǿ��� ����....
	SetColor(_Color);

	//** ���ڿ� ���
	printf_s("%d", _Value);
}

void SetColor(int _Color)
{
	//** �ܼ�â�� ������ Ŀ���� �÷��� ���� ������ ���´�.
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
		SetCursorPositionString(53, 10, (char*)"�� �����ϱ�", 15);
	else
		SetCursorPositionString(55, 10, (char*)"�����ϱ�", 8);

	if (iButton == 1)
		SetCursorPositionString(53, 12, (char*)"�� ��������", 15);
	else
		SetCursorPositionString(55, 12, (char*)"��������", 8);

	if (iButton == 2)
		SetCursorPositionString(53, 14, (char*)"�� ���ư���", 15);
	else
		SetCursorPositionString(55, 14, (char*)"���ư���", 8);
}

void SceneStage()
{
	//** �ٴ� ����
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
	} //* ������� �ٴ�
}