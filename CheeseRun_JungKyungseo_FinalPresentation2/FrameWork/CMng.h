class CMng
{
public:
	CMng();
	~CMng();


	///////////////////////// ��������Ʈ ��ü! ///////////////////
//	Sprite loadimg;  // �ΰ��̹���

	//////////////////////////////////////////////////////////////


	Chap *chap[TOTALCHAP];
	int n_Chap;

	HWND hWnd;
	HINSTANCE hInstance;

};

extern CMng g_Mng;