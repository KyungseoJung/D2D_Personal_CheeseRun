#pragma once
#include "Include.h"

Device DV;

Device::Device(void)
{
}

Device::~Device(void)
{
}

bool Device::Create(IDirect3DDevice9* Device)
{

	Device9 = Device;

	D3DXCreateSprite( Device9 , &Sprite ) ;

	ZeroMemory( &fdesc , sizeof(fdesc) ) ;
	fdesc.Height = 25 ;
	fdesc.Width = 12 ;
	fdesc.Weight = 500 ;
	fdesc.Italic = FALSE ;
	fdesc.CharSet = DEFAULT_CHARSET ;
	//fdesc.FaceName[LF_FACESIZE];
	_tcscpy_s( fdesc.FaceName,sizeof(fdesc.FaceName), _T("µ¸¿ò") ) ;

	D3DXCreateFontIndirect( Device9 , &fdesc , &Fonts ) ;

	return true;

}

bool Device::DrawString( const TCHAR* msg , int x , int y , D3DCOLOR color)
{
	RECT rect = { x , y , fdesc.Width*wcslen(msg) , fdesc.Height } ;

	Sprite->Begin( D3DXSPRITE_ALPHABLEND ) ;
	Fonts->DrawText( Sprite , msg , wcslen( msg ) , &rect , DT_NOCLIP , D3DCOLOR_XRGB(255,0,255) ) ;
	Sprite->End() ;
	
	return true;
}