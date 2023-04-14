#ifndef __Chap_H__
#define __Chap_H__

class Chap
{
public :
	Chap() {};
	~Chap() {};

	virtual void Init() = 0;
	virtual void Update(double frame) = 0;
	virtual void Draw() = 0;
	virtual void OnMessage(MSG* msg) = 0;
};

#endif