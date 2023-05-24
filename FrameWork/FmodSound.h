#pragma once
#include "Include.h"	//@13-1

#include <map> // STL �����̳�	//@13-1 cpp���Ͽ� �ִ� �� ��ġ �ű�

// FOMD �����Ͻ� ����
#include <string>	//ġƮŰ ���Ͽ����� �� ���� ����

//////////////////////////////////////

// FMOD �����Ͻ� ���� Ŭ����
class FmodSound
{
	System* m_pSystem;
	int			m_Index;
	Channel* m_pBGChannel;
	float       m_vloum;

public:
	std::map<std::string, int >	m_CheckList;
	std::map<int, Sound* >		m_SoundList;

	FmodSound();
	~FmodSound();

	// ���� �߰� 
	int	AddSoundFile(std::string _FullPath, bool _IsLoop);

	// ����Ʈ �÷���
	void EffectPlay(int _SoundNum);

	// ����� �÷���
	void BGPlay(int _SoundNum);

	// ����� ����
	void BGStop();

	// ���� �ٿ�
	void VolumDown();

	// ���� ��
	void VolumUp();
};



int		AddSoundFile(std::string _FullPath, bool IsLoop = false);
void	EffectPlay(int _SoundNum);
void	BGPlay(int _SoundNum);
void	VolumUp();
void	VolumDown();
void	BGStop();

//////////////////////////////////////
