#include "Include.h"	//@13-1 �߰����ֱ�

/*	//Include.h �� �ű�
#include "FMODENGIN/inc/fmod.hpp"
#pragma	comment (lib, "FMODENGIN/lib/fmodex64_vc.lib") // 1. ����� ����� ȿ��, �Ӽ� â�� ���̺귯�� �߰�
using namespace FMOD;
*/

/*	//Include.h �� �ű�
// STL �����̳�
#include <map>
*/

//@13-1 Ŭ���� �Լ� ======================================================================

FmodSound::FmodSound()
{
	System_Create(&m_pSystem);
	// init(ä�� �ִ뼳����, �ʱ�ȭ ���� , �߰��� ���� ���� ����̹� );
	m_pSystem->init(10, FMOD_INIT_NORMAL, 0);

	m_Index = 0;
	m_vloum = 1.0f;
	m_pBGChannel = nullptr;
}
FmodSound::~FmodSound()
{
	m_CheckList.clear();

	for (auto& Iter : m_SoundList)
	{
		Iter.second->release();
	}
	m_SoundList.clear();

	m_pSystem->release();
	m_pSystem->close();
}

// ���� �߰� 
int	FmodSound::AddSoundFile(std::string _FullPath, bool _IsLoop)
{
	auto Find = m_CheckList.find(_FullPath);

	if (Find != m_CheckList.end())
	{
		return Find->second;
	}

	Sound* pSound = nullptr;
	int		Mode = FMOD_HARDWARE | (_IsLoop ? FMOD_LOOP_NORMAL | FMOD_DEFAULT : FMOD_LOOP_OFF);

	// ���带 ������ ��ο��� �� ��° ������ LOOP/ONCE �� ���� �ؼ� �ε�
	m_pSystem->createSound(_FullPath.c_str(), Mode, 0, &pSound);

	if (pSound == nullptr)
	{
		return -1;
	}

	m_CheckList.insert(std::make_pair(_FullPath, m_Index));
	m_SoundList.insert(std::make_pair(m_Index, pSound));

	return m_Index++;
}

// ����Ʈ �÷���
void FmodSound::EffectPlay(int _SoundNum)
{
	auto Find = m_SoundList.find(_SoundNum);

	Channel* pChannel = nullptr;

	// playSound(ä�α׷�, sound, �Ͻ�������?,ä��);
	m_pSystem->playSound(FMOD_CHANNEL_FREE, Find->second, 0, &pChannel);
}

// ����� �÷���
void FmodSound::BGPlay(int _SoundNum)
{
	auto Find = m_SoundList.find(_SoundNum);

	m_pSystem->playSound(FMOD_CHANNEL_REUSE, Find->second, 0, &m_pBGChannel);
}

// ����� ����
void FmodSound::BGStop()
{
	if (m_pBGChannel != nullptr)
	{
		m_pBGChannel->stop();
	}
}

// ���� �ٿ�
void FmodSound::VolumDown()
{
	m_vloum -= 0.1f;
	if (m_vloum <= 0) m_vloum = 0;
	m_pBGChannel->setVolume(m_vloum);
}

// ���� ��
void FmodSound::VolumUp()
{
	m_vloum += 0.1f;
	if (m_vloum >= 1.0) m_vloum = 1.0;
	m_pBGChannel->setVolume(m_vloum);
}





//@13-1 ���� �Լ� ========================================================================

static FmodSound g_SoundMgr;

// ���� ���� �߰� �Լ�
int	AddSoundFile(std::string _FullPath, bool _IsLoop)
{
	return g_SoundMgr.AddSoundFile(_FullPath, _IsLoop);
}

// ���� ����Ʈ �÷��� �Լ�
void EffectPlay(int _SoundNum)
{
	g_SoundMgr.EffectPlay(_SoundNum);
}

// ���� ����� ��� �Լ�
void BGPlay(int _SoundNum)
{
	g_SoundMgr.BGPlay(_SoundNum);
}

// ���� ���� ��
void VolumUp()
{
	g_SoundMgr.VolumUp();
}

// ���� ���� �ٿ�
void VolumDown()
{
	g_SoundMgr.VolumDown();
}

// ���� ����� ���� �Լ�
void BGStop()
{
	g_SoundMgr.BGStop();
}