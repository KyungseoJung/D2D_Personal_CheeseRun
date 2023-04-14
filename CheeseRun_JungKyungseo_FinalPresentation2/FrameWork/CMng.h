class CMng
{
public:
	CMng();
	~CMng();


	///////////////////////// 스프라이트 객체! ///////////////////
//	Sprite loadimg;  // 로고이미지

	//////////////////////////////////////////////////////////////


	Chap *chap[TOTALCHAP];
	int n_Chap;

	HWND hWnd;
	HINSTANCE hInstance;

};

extern CMng g_Mng;