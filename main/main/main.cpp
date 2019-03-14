#include "Header.h"





SCENEID SceneState = SCENEID_LOGO;
Object* pPlayer = NULL;
Object* pBlockOne = NULL;
Object* pBlockTwo = NULL;
Object* pBlockThree = NULL;
Object* pBlockFour = NULL;
Object* pBlockFive = NULL;
char* Backgra[8];
int iBack = 0;
int iBackCheck = 0;
int iPosition = 108;
int iButton = 0;
bool bJump = false;
bool bJumpDown = false;
int iJumpCheck = 0;
int iStage = 0;

Logo* pLogo = NULL;

void SceneManager();

DWORD InputManager();

void SetCursorHide();

void SetCursorPositionString(const int _ix, const int _iy, const char* str, const int _Color);

void SetCursorPositionInteger(const int _ix, const int _iy, const int _Value, const int _Color);

void SetColor(int _Color);

Object* CreateObject(char* _str);

void Initialize(Object* _pUser, char* _str);

void SetPlayerPosition();

void SetPosition(Vector3* _vPos, Vector3 _point);

void SceneLogo();

void SceneMenu();

void SceneStage();

void ScenePlay();

void Block();


int main(void)
{
	SetCursorHide();

	pLogo = (Logo*)malloc(sizeof(Logo));

	pLogo->Logo[0] = (char*)"       __                      _             __";
	pLogo->Logo[1] = (char*)"      / /_  ______ ___  ____  (_)___  ____ _/ /";
	pLogo->Logo[2] = (char*)" __  / / / / / __ `__ |/ __ |/ / __ |/ __ `/ / ";
	pLogo->Logo[3] = (char*)"/ /_/ / /_/ / / / / / / /_/ / / / / / /_/ /_/  ";
	pLogo->Logo[4] = (char*)"|____/|__,_/_/ /_/ /_/ .___/_/_/ /_/|__, (_)   ";
	pLogo->Logo[5] = (char*)"                    /_/            /____/      ";
	pLogo->Logo[6] = (char*)"        계속하려면 ENTER 키를 눌러주세요.        ";

	pLogo->Position.x = 0;
	pLogo->Position.y = 2;

	Backgra[0] = (char*)"▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒";
	Backgra[1] = (char*)"╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊";
	Backgra[2] = (char*)"─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─";
	Backgra[3] = (char*)"╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊";
	Backgra[4] = (char*)"▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒";
	Backgra[5] = (char*)"─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─";
	Backgra[6] = (char*)"╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊";
	Backgra[7] = (char*)"─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─╊─";

	pPlayer = CreateObject((char*)"옷");
	pPlayer->HP = 5;

	SetPosition(&pPlayer->Position,
		Vector3(15.f, 7.f));

	pBlockOne = CreateObject((char*)"■");
	SetPosition(&pBlockOne->Position,
		Vector3(108.f, 6.f));

	pBlockTwo = CreateObject((char*)"■■");
	SetPosition(&pBlockOne->Position,
		Vector3(106.f, 6.f));

	pBlockThree = CreateObject((char*)"■■■");
	SetPosition(&pBlockOne->Position,
		Vector3(104.f, 6.f));

	pBlockFour = CreateObject((char*)"■■■■");
	SetPosition(&pBlockOne->Position,
		Vector3(102.f, 6.f));

	pBlockFive = CreateObject((char*)"■■■■■");
	SetPosition(&pBlockOne->Position,
		Vector3(100.f, 6.f));

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
		ScenePlay();

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

void SetCursorHide()
{
	//** GetStdHandle(STD_OUTPUT_HANDLE) = 현재 콘솔창의 접근 권한을 갖는다.
	HANDLE hCursor = GetStdHandle(STD_OUTPUT_HANDLE);

	//** 커서의 정보를 담고있는 구조체
	CONSOLE_CURSOR_INFO Info;
	Info.dwSize = 100;
	Info.bVisible = FALSE;

	//** 커서를 안보이게 설정.
	SetConsoleCursorInfo(hCursor, &Info);
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

//** 객체를 생성하는 함수
Object* CreateObject(char* _str)
{
	//** 동적 할당
	Object* pUser = (Object*)malloc(sizeof(Object));
	Initialize(pUser, _str);

	//** 반환
	return pUser;
}

void Initialize(Object* _pUser, char* _str)
{
	_pUser->Name = _str;// SetName();
	_pUser->Position = Vector3(0.f, 0.f);
	_pUser->Color = 15;
}

void SetPlayerPosition()
{
	DWORD dwKey = InputManager();

	if (dwKey & KEY_UP)
	{
		if (pPlayer->Position.y > 0)
		{
			// pPlayer->Position.y -= 1;
			if(!bJump && !bJumpDown)
				bJump = true;
		}
	}
	if (dwKey & KEY_DOWN)
	{
		if (pPlayer->Position.y < 7)
		{
			pPlayer->Position.y += 1;
		}
	}
	if (dwKey & KEY_LEFT)
	{
		if (pPlayer->Position.x > 0)
		{
			pPlayer->Position.x -= 2;
		}
	}
	if (dwKey & KEY_RIGHT)
	{
		if (pPlayer->Position.x < 108)
		{
			pPlayer->Position.x += 2;
		}
	}
}

void SetPosition(Vector3* _vPos, Vector3 _point)
{
	_vPos->x = _point.x;
	_vPos->y = _point.y;
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
		SetCursorPositionString(35, 10, pLogo->Logo[6], 15);
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
		SetCursorPositionString(53, 5, (char*)"▶ 시작하기", 15);
	else
		SetCursorPositionString(55, 5, (char*)"시작하기", 8);

	if (iButton == 1)
		SetCursorPositionString(53, 7, (char*)"▶ 점수보기", 15);
	else
		SetCursorPositionString(55, 7, (char*)"점수보기", 8);

	if (iButton == 2)
		SetCursorPositionString(53, 9, (char*)"▶ 돌아가기", 15);
	else
		SetCursorPositionString(55, 9, (char*)"돌아가기", 8);
}

void SceneStage()
{
	switch (iBack)
	{
	case 0:
		for (int i = 0; i < 4; ++i)
		{
			SetCursorPositionString(0, 8 + i, Backgra[i], 14);
		}
		break;
	case 1:
		for (int i = 4; i < 8; ++i)
		{
			SetCursorPositionString(0, 4 + i, Backgra[i], 14);
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
	}

	iStage++;

	if (iStage > 10)
	{
		SetCursorPositionString(
			int(pBlockOne->Position.x),
			5,
			pBlockOne->Name,
			4);

		pBlockOne->Position.x -= 2;

		if (pBlockOne->Position.x == 0)
		{
			pBlockOne->Position.x = 0;
		}
	}

	if (iStage > 11)
	{
		SetCursorPositionString(
			int(pBlockThree->Position.x),
			6,
			pBlockThree->Name,
			4);

		pBlockThree->Position.x -= 2;

		if (pBlockThree->Position.x == 0)
		{
			pBlockThree->Position.x = 0;
		}
	}

	if (iStage > 12)
	{
		SetCursorPositionString(
			int(pBlockFive->Position.x),
			7,
			pBlockFive->Name,
			4);

		pBlockFive->Position.x -= 2;

		if (pBlockFive->Position.x == 0)
		{
			pBlockFive->Position.x = 0;
		}
	}

}

void ScenePlay()
{
	SetPlayerPosition();

	SetCursorPositionString(
		int(pPlayer->Position.x),
		int(pPlayer->Position.y),
		pPlayer->Name,
		pPlayer->Color);

	if (bJump)
	{
		pPlayer->Position.y -= 1;

		if (iJumpCheck == 4)
		{
			bJump = false;
			bJumpDown = true;
		}

		iJumpCheck++;
	}

	if (bJumpDown)
	{
		pPlayer->Position.y += 1;

		iJumpCheck--;

		if (iJumpCheck == 0)
		{
			bJumpDown = false;
		}
	}


}

void Block()
{
	SetCursorPositionString(iPosition, 6, "■", 4);

	if (iPosition != 0)
	{
		iPosition -= 2;
	}
}