#ifndef __Over_H__
#define __Over_H__

class Over : public Chap
{
	
public:
	Over();
	~Over();
	//int OverCase;	//@5-2 0이면 LOSE, 1이면 WIN의 경우 - GameManager.h에 정의하자

	Sprite loseBG;	//@4-1 LOSE 이미지 넣을 변수 추가
	Sprite winBG;	//@5-2 WIN 이미지 넣을 변수 추가

	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);
};

#endif