//#include <windows.h>
//#include <mmsystem.h>
#include "Include.h" 
const int TICKS_PER_SECOND = 60;
const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
const int MAX_FRAMESKIP = 5;
int loops;
float interpolation;
// 버퍼 추가
char buffer[128] = { 0,0,0,0 };
char ch[3] = { 0,0,0 }; //D  strcat 사용법 틀림 최소 널이 들어갈수 있도록 해줘야함
////////////////////////////////////
LRESULT CALLBACK WndProc(HWND g_hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	WNDCLASSEX wc;
	HWND g_hWnd;
	wc.hInstance = GetModuleHandle(NULL);
	wc.cbSize = sizeof(wc);
	wc.style = CS_CLASSDC;
	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(wc.hInstance, IDC_ARROW);
	wc.hIcon = LoadIcon(wc.hInstance, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(wc.hInstance, IDI_APPLICATION);
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = "Game";
	wc.lpszMenuName = NULL;

	RegisterClassEx(&wc);

	/* ---------------------------------------------------
	/////////////////// 정가운데 출력 ////////////////////

				프로그램을 모니터의 정가운데
				출력하게 해 주는 코드입니다.

	//////////////////////////////////////////////////////
	----------------------요-기-서-부-터-----------------*/
	RECT rt = { 0, 0, SCREEN_WITH, SCREEN_HEIGHT };
	int W = rt.right - rt.left;
	int H = rt.bottom - rt.top;
	int X = (GetSystemMetrics(SM_CXSCREEN) / 2) - SCREEN_WITH / 2;
	int Y = ((GetSystemMetrics(SM_CYSCREEN) / 2) - SCREEN_HEIGHT / 2);
	/*---------------------요-기-까-지-------------------*/

	/*
		int WINAPI GetSystemMetrics(
			int nIndex
		);

		<인자값>
		SM_CXSCREEN : 화면의 넓이를 구할 수 있다.
		SM_CYSCREEN : 화면의 높이를 구할 수 있다.

		현재 화면의 해상도를 구할 수 있다. 이 외에도 인자값에따라 다양한 값을 구할 수 있다.
		자세한 사항은 MSDN 의 GetSystemMetrics 를 참고하길 바람
		단, 다중 모니터에서 값을 구할 경우 메인 모니터에 대해서만 값을 구하기때문에 이 함수를 사용하면 안된다.
		다중 모니터에서 전체 해상도를 구하길 원할경우 GetMonitorInfo 함수를 이용하자
	*/

	// WS_POPUP 빼면 테투리가 생긴다~
	g_hWnd = CreateWindowEx(NULL, wc.lpszClassName,
		"Game",
		WS_EX_TOPMOST | WS_POPUP,
		X, Y, W, H,
		NULL, NULL, wc.hInstance, NULL);


	dv_font.Create(g_hWnd);
	//@13-1 Sound 파일 관련 주석 처리
	/*sound.g_pSoundManager = new CSoundManager();
	sound.g_pSoundManager->Initialize(g_hWnd, DSSCL_PRIORITY);
	sound.g_pSoundManager->SetPrimaryBufferFormat(2, 22050, 16);*/

	//g_SoundManager.Initialize(g_hWnd, DSSCL_PRIORITY);
	//g_SoundManager.SetPrimaryBufferFormat(2,22050,16);

	ShowWindow(g_hWnd, SW_SHOW);
	UpdateWindow(g_hWnd);
	// 마우스 안보이게~
	//ShowCursor(FALSE);

	///////////////////////////////////////////////////////////////////
	ZeroMemory(&msg, sizeof(MSG));
	//TRACE("REV ====== %s ========= \n\n", buffer);
	/////////// 챕터 초기화 /////////////////
	g_Mng.chap[LOGO] = new Logo;
	g_Mng.chap[MENU] = new Menu;
	g_Mng.chap[GAME] = new Game;
	g_Mng.chap[OVER] = new Over;
	g_Mng.chap[METHOD] = new Method;		//@15-1 게임 방법 이미지 띄울 페이지 추가
	/////////////////////////////////////////

	for (int i = 0; i < TOTALCHAP; i++)
		g_Mng.chap[i]->Init();

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{

			static DWORD next_game_tick = GetTickCount();
			//static DWORD next_game_tick1 = GetTickCount();



			loops = 0;

			//static int aa;
			//bool b = false;

			while (GetTickCount64() > next_game_tick && loops < MAX_FRAMESKIP)
			{
				interpolation = float(GetTickCount64() + SKIP_TICKS - next_game_tick) / float(SKIP_TICKS);
				if (Gmanager.m_Pause == false) g_Mng.chap[g_Mng.n_Chap]->Update(interpolation);
				//if(b == false)
				//{
				//	aa = interpolation;
				//	b = true;
				//}
				g_Mng.chap[g_Mng.n_Chap]->OnMessage(&msg);
				next_game_tick += SKIP_TICKS;
				loops++;
			}



			dv_font.Device9->BeginScene();
			dv_font.Device9->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 0, 0);


			g_Mng.chap[g_Mng.n_Chap]->Draw();

			dv_font.Device9->EndScene();
			dv_font.Device9->Present(NULL, NULL, NULL, NULL);

		}
	}

	return msg.wParam;

}

// 키 한번만 먹을거는 여기가 안전...아니면 귀찮다.(key.cpp 에서 연속키 안먹게 하기 위해 로직이 더러워짐)
LRESULT CALLBACK WndProc(HWND g_hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_CHAR:
		ch[0] = wParam;
		strcat(buffer, ch);
		// 문자열 위치 가져옴...
		if (strstr(buffer, "p") != NULL)
		{

			if (GetTickCount64() - key.KeyTime > 200)
			{
				Gmanager.m_Pause = !Gmanager.m_Pause;

				key.KeyTime = GetTickCount64();
			}
		}
		else if (strstr(buffer, "s") != NULL)
		{
			// 데이타 베이스 저장
			//sql.save();		//@2-6 주석 처리
		}

		ZeroMemory(&buffer, sizeof(buffer));
		break;


		//case WM_COMM_RXCHAR:  //시리얼에서 받는 메세지는 여기를 
		//	 ch[0] = wParam;
		//	 strcat( buffer,ch);	
		//     TRACE("REV ====== %s ========= \n\n", buffer);




	}
	return DefWindowProc(g_hWnd, uMsg, wParam, lParam);
}

/*

함수원형 : char* strstr(char* str1, const char* str2);

0) 헤더파일 : C언어 : <string.h> / C++ : <cstring>

1) str1에서 str2와 일치하는 문자열이 있는지 확인을 하는 함수.

2) str1에 str2의 문자열과 일치하는 문자열이 있으면 해당 위치의 포인터(char* 타입)를 반환.

3) 당연하게도 일치하는 문자열을 찾지 못하면 null pointer를 반환. (그렇기 때문에 널체크를 꼭! 해주어야 함.)

4) 문자열을 찾아서, 문자열을 바꾸는 경우에는 원본 문자열 str1의 배열의 길이를 반드시 생각해야함. 배열의 범위를 넘으면, 큰일이니깐.


*/