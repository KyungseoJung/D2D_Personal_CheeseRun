#ifndef __Over_H__
#define __Over_H__

class Over : public Chap
{
	
public:
	Over();
	~Over();
	//int OverCase;	//@5-2 0�̸� LOSE, 1�̸� WIN�� ��� - GameManager.h�� ��������

	Sprite loseBG;	//@4-1 LOSE �̹��� ���� ���� �߰�
	Sprite winBG;	//@5-2 WIN �̹��� ���� ���� �߰�

	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);
};

#endif