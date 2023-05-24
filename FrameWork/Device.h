#pragma once
#include "Include.h"

class Device
{
public:
	IDirect3DDevice9* Device9;
	ID3DXSprite* Sprite;       
	ID3DXFont* Fonts;    
	D3DXFONT_DESC fdesc ;

public:
	Device(void);
	~Device(void);

	bool Create(IDirect3DDevice9*);
	bool DrawString( const TCHAR* msg , int x , int y , D3DCOLOR color = D3DCOLOR_ARGB( 255,255,255,255) );

};

extern Device DV;