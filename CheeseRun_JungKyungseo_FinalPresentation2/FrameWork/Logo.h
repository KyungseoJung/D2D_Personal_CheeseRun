#ifndef __Logo_H__
#define __Logo_H__

class Logo : public Chap
{
public:
	Logo();
	~Logo();

	HWND hWnd;
	//CSound* Sound1;
	Sprite loadimg;

	float speed;
	float alpha;

	// 데이타 베이스 테스트
	int count = 0;
	char cnt[256];
	char pw[256];

	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);


};

#endif