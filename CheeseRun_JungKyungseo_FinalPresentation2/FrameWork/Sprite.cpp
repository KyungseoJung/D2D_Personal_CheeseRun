#include "Include.h"

Sprite g_Load;

Sprite::Sprite(void)
{
}

Sprite::~Sprite(void)
{
}
bool Sprite::Create(const char* filename, bool bUseTransparency, D3DCOLOR TransparencyColor)
{
	D3DXGetImageInfoFromFile(filename, &imagesinfo);

	color = D3DCOLOR_ARGB( 255, 255, 255, 255 ) ;

	HRESULT hr = E_FAIL ;

	D3DCOLOR transparencycolor;
	if( bUseTransparency )	transparencycolor = TransparencyColor | 0xff000000;
	else					transparencycolor = 0;
	
	hr = D3DXCreateTextureFromFileEx(dv_font.Device9 ,
		filename , imagesinfo.Width , imagesinfo.Height , 1 , 0 , 	D3DFMT_UNKNOWN , D3DPOOL_MANAGED,
		D3DX_DEFAULT, 	D3DX_DEFAULT, transparencycolor,	&imagesinfo , 	NULL, 	&Texture ) ; 

	return TRUE;
	
	/*
	hr = D3DXCreateTextureFromFileEx( font.Device9 ,
		filename , D3DX_DEFAULT , D3DX_DEFAULT , 1 , 0 , 	D3DFMT_UNKNOWN , D3DPOOL_DEFAULT,
		D3DX_FILTER_NONE, 	D3DX_FILTER_NONE, transparencycolor,	NULL , 	NULL, 	&Texture ) ; 

	return TRUE;
	*/

}

void Sprite::Draw( float dx , float dy , float sx , float sy , float sw , float sh, float centerX, float centerY ) // ȭ���� dx, dy��
{																								   // �׸��� sx, sy���� sw, sh ���� ����ض�
	RECT srcRect = { sx , sy , sw , sh } ;

	D3DXVECTOR3 position( (float)dx, (float)dy, 1.0f ) ;

	D3DXVECTOR3 center ;
	center.x   = 0;
	center.y   = 0 ;	
	center.z   = 1.0f ;

	dv_font.Sprite->Begin( D3DXSPRITE_ALPHABLEND ) ;

	dv_font.Sprite->Draw( Texture , &srcRect ,	&center , &position , color ) ;

	dv_font.Sprite->End() ;

}

void Sprite::Draw(float x, float y)		// ȭ���� x, y �� ����ض�.
{
	D3DXVECTOR3 pos;
	pos.x = x;
	pos.y = y;
	pos.z = 1.0f;

	dv_font.Sprite->Begin( D3DXSPRITE_ALPHABLEND ) ;

	dv_font.Sprite->Draw( Texture ,NULL ,	NULL , &pos , color ) ;

	dv_font.Sprite->End() ;
}

void Sprite::Render( float x , float y , float radian, float sx, float sy) // ȸ��, Ȯ�� ���
{																	   // sx -1 : �¿����, sy -1 = ���Ϲ���
	RECT Rect ;														   // sx 0 : ������, 1 : �״��, 2 : x������ 2�� Ȯ��
	ID3DXSprite* pSprite ;

	pSprite = dv_font.Sprite ;

	Rect.left   = 0 ;
	Rect.top    = 0 ;
	Rect.right  = Rect.left + imagesinfo.Width ;
	Rect.bottom = Rect.top  + imagesinfo.Height ;

	D3DXMATRIX rot , trans, scale ;
	D3DXMatrixScaling(&scale , sx ,sy ,1) ;
	D3DXMatrixRotationZ( &rot , radian ) ;
	D3DXMatrixTranslation( &trans , x , y , 1.0f ) ;
	pSprite->SetTransform( &( scale * rot * trans ) ) ;

	dv_font.Sprite->Begin(D3DXSPRITE_ALPHABLEND) ;
	pSprite->Draw( Texture , &Rect, NULL, NULL , 0xFFFFFFFF ) ;
	pSprite->Flush() ;
	dv_font.Sprite->End() ;

	D3DXMATRIX identity ;
	D3DXMatrixIdentity( &identity ) ;
	pSprite->SetTransform( &identity ) ;
}



void Sprite::RenderDraw( float x , float y , float sx , float sy , float sw , float sh, float radian, float sl, float st) 
																		// ȸ��, Ȯ�� ���
{																	   // sx -1 : �¿����, sy -1 = ���Ϲ���
	RECT Rect = {sx, sy, sw, sh};									   // sx 0 : ������, 1 : �״��, 2 : x������ 2�� Ȯ��
	ID3DXSprite* pSprite ;

	pSprite = dv_font.Sprite ;

	//D3DXVECTOR3 position( (float)x, (float)y, 1.0f ) ;

/*	Rect.left   = 0 ;
	Rect.top    = 0 ;
	Rect.right  = Rect.left + imagesinfo.Width ;
	Rect.bottom = Rect.top  + imagesinfo.Height ;
*/
	D3DXVECTOR3 center ;
	center.x   = 0;
	center.y   = 0 ;	
	center.z   = 1.0f ;

	D3DXMATRIX rot , trans, scale ;
	D3DXMatrixScaling(&scale , sl ,st ,1) ;
	D3DXMatrixRotationZ( &rot , radian ) ;
	D3DXMatrixTranslation( &trans , x , y , 1.0f ) ;
	pSprite->SetTransform( &( scale * rot * trans ) ) ;

	dv_font.Sprite->Begin(D3DXSPRITE_ALPHABLEND) ;
	pSprite->Draw( Texture , &Rect, &center, NULL , 0xFFFFFFFF ) ;
	pSprite->Flush() ;
	dv_font.Sprite->End() ;

	D3DXMATRIX identity ;
	D3DXMatrixIdentity( &identity ) ;
	pSprite->SetTransform( &identity ) ;
}
void Sprite::SetColor( int r, int g , int b , int a )
{
	color = D3DCOLOR_ARGB( a, r, g, b ) ;
}