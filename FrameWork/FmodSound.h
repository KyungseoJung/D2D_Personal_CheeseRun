#pragma once
#include "Include.h"	//@13-1

#include <map> // STL 컨테이너	//@13-1 cpp파일에 있던 거 위치 옮김

// FOMD 비지니스 로직
#include <string>	//치트키 파일에서는 안 쓰고 있음

//////////////////////////////////////

// FMOD 비지니스 로직 클래스
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

	// 사운드 추가 
	int	AddSoundFile(std::string _FullPath, bool _IsLoop);

	// 이펙트 플레이
	void EffectPlay(int _SoundNum);

	// 배경음 플레이
	void BGPlay(int _SoundNum);

	// 배경음 멈춤
	void BGStop();

	// 볼륨 다운
	void VolumDown();

	// 볼륨 업
	void VolumUp();
};



int		AddSoundFile(std::string _FullPath, bool IsLoop = false);
void	EffectPlay(int _SoundNum);
void	BGPlay(int _SoundNum);
void	VolumUp();
void	VolumDown();
void	BGStop();

//////////////////////////////////////
