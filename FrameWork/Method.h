#ifndef __Method_H__
#define __Method_H__

class Method : public Chap		//@15-1 ��� �̹��� ��� ���� �߰�. METHOD ������ �߰�
{
public:
	Method();
	~Method();
	
	Sprite methodimg;

	//	Sprite Howto1;		//@15-1 '���' �̹��� ��� ����
	//	bool ShowHowto1;	//@15-1 '���' �̹��� ����� ���� ���ǹ��� ���� bool�� ����



	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);

};

#endif