#include "Include.h"

Item item;

//@마지막 (vector->list로만 변경)
extern std::list<Trap*> targetTrap;	//@10-3 벡터 extern 선언. 트랩 모두 없애는 효과 사용하기 위함
extern FmodSound ItemSound;	//@14-2	사운드 추가

Item::Item()
{

}

Item::~Item()
{

}

void Item::Init()
{
	char FileName[256];

	sprintf_s(FileName, "./resource/Img/Item/Item4.png");
	Itemimg1.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));


	//@10-1 아이템1 위치 넣어주기
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			ItemArr1[row][col].ItemState = ITEM_NO;

			if ((block.BlockArr[row][col].BlockState == MAP_BLOCK) && ( (col != 0) && (col % 7== 0) )	  )	//@ 마지막 - 블록 if문으로 깔끔하게
			{
				this->ItemArr1[row][col].ItemState = ITEM_YES;	//아이템1 있다.
			}
		}
	}

	gyeokja.Create("./resource/Img/Map/gyeokja.png", false, D3DCOLOR_XRGB(0, 0, 0));	//격자 그려주는 코드


}

void Item::Update()
{
	//타겟이 가까이 가면, 그 아이템을 먹음. 그 아이템은 이제 사라짐(ITEM_NO). 아이템 효과 발생. 
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			//	MAP_TRAP이 아니라는 조건도 넣어줘야 컨테이너가 더이상 생성되지 않음
			if (item.ItemArr1[row][col].show == TRUE)
			{
				float distance = (float)sqrt(((col * 42.0) - target.t_x) * ((col * 42.0) - target.t_x) +
					((row * 42.0) - target.t_y) * ((row * 42.0) - target.t_y));

				if(distance < 30)	//타겟과 아이템간의 거리	
				{
					item.ItemArr1[row][col].show = FALSE;			//가까워지면 아이템 먹음

					ItemArr1[row][col].ItemState = ITEM_NO;			//아이템 사라짐 (이제 배열에서 0으로 나옴)

					ItemSound.EffectPlay(Gmanager.GetItemSound);	//@14-2 아이템 먹을 때 효과음

					//아이템 효과 발생
					for (int i = 0; i < monster.MonsterCount; i++)	//고양이들 모두 기절				
					{
						monster.cat[i].life = false;	

						monster.cat[i].m_SleepSecond = 5;
					}

					targetTrap.clear();								//나와있는 트랩 모두 사라짐
																
				}
				

			}
		}
	}
}

void Item::Draw()
{
	//show == TRUE 일 때만, 그리기. 아닐 땐, 안 보이게
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			if (item.ItemArr1[row][col].show == TRUE)
			{
				Itemimg1.Render(col * 42 + 15, row * 42 + 42, 0, 0.4, 0.4);
			}
		}
	}

}

void Item::Reset()
{
	//아이템 초기화해주기
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			if (item.ItemArr1[row][col].show == TRUE)
			{
				item.ItemArr1[row][col].show = FALSE;
			}
		}
	}
}

void Item::PushItem(int pos)	//@14-1 따로 함수로 정리만
{
	if (pos == LEFT)
	{
		item.ItemArr1[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 1].ItemState = ITEM_NO;
		item.ItemArr1[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 2].ItemState = ITEM_YES;
	}
	else if (pos == RIGHT)
	{
		item.ItemArr1[(int)(target.t_y / 42)][(int)(target.t_x / 42) + 1].ItemState = ITEM_NO;
		item.ItemArr1[(int)(target.t_y / 42)][(int)(target.t_x / 42) + 2].ItemState = ITEM_YES;
	}
	else if (pos == UP)
	{
		item.ItemArr1[(int)(target.t_y / 42) - 1][(int)(target.t_x / 42)].ItemState = ITEM_NO;
		item.ItemArr1[(int)(target.t_y / 42) - 2][(int)(target.t_x / 42)].ItemState = ITEM_YES;
	}
	else if (pos == DOWN)
	{
		item.ItemArr1[(int)(target.t_y / 42) + 1][(int)(target.t_x / 42)].ItemState = ITEM_NO;
		item.ItemArr1[(int)(target.t_y / 42) + 2][(int)(target.t_x / 42)].ItemState = ITEM_YES;
	}
}
