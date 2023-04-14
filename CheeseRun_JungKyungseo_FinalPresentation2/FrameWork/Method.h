#ifndef __Method_H__
#define __Method_H__

class Method : public Chap		//@15-1 방법 이미지 띄울 파일 추가. METHOD 변수도 추가
{
public:
	Method();
	~Method();
	
	Sprite methodimg;

	//	Sprite Howto1;		//@15-1 '방법' 이미지 띄울 변수
	//	bool ShowHowto1;	//@15-1 '방법' 이미지 띄울지 말지 조건문에 쓰일 bool형 변수



	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);

};

#endif