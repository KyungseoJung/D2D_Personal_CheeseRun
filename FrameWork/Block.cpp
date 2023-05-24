#include "Include.h"

Block block;

//extern std::vector<Trap> targetTrap;	//@9-1-1 테스트용
extern std::list<Trap*> targetTrap;	//@9-1-2			//@마지막 (vector->list로만 변경)

extern FmodSound BlockSound;	//@14-2	사운드 추가


Block::Block()
{
	BlockMakeTime = GetTickCount64();
}

Block::~Block() {}

void Block::Init()
{
	//@6-1-2 맵 배열 만들기	==================================================
	//맵 블록 그림 
	char FileName[256];
	sprintf_s(FileName, "./resource/Img/Block/Block00.png");
	map_Block.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/Block/Block01.png");
	Blockimg1.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/Block/Block02.png");
	Blockimg2.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/Block/Block03.png");
	Blockimg3.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	//맵 배열 타일 초기화 함수
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			this->BlockArr[row][col].BlockState = MAP_EMPTY;

			if ((row == 5) || (row == 6) || (row == 11) || (row == 12))	//@블록 위치 10-2 변경
			{
				this->BlockArr[row][col].BlockState = MAP_BLOCK;	//블록 있다.
			}
		}
	}

	gyeokja.Create("./resource/Img/Map/gyeokja.png", false, D3DCOLOR_XRGB(0, 0, 0));	//격자 그려주는 코드 - GameManager.cpp의 Draw함수에 지정
	
	//@7-1 MAP_BLOCK의 경우, CrushState =3 씩 부여 ==================================================
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			this->BlockArr[row][col].CrushState = 4; //4의 크기씩 버틸 수 있다. //key.cpp에서 VK_CONTROL 누를 때마다 감소함
			/* 블록이 없는 부분은 자동으로 0으로 처리되어서, 나중에 블록이 갑자기 생기는 문제 발생할까봐)
			if (BlockArr[row][col].BlockState = MAP_BLOCK) 주석 처리 함 */
		}
	}

}

void Block::Update()
{
	//부서진 블록(MAP_BROKEN) 시간 지나면, 다시 생기도록(MAP_BLOCK)		//블록 생기는 시간 조절 가능
	if( (Gmanager.m_GameStart == true) && (GetTickCount64() - BlockMakeTime > 3000) ) 
	{	
		for (int row = 0; row < 18; row++)
		{
			for (int col = 0; col < 30; col++)
			{
						//@9-1  트랩이 있는 곳이 아니면	
						//어차피 CrushState가 줄어드는 건, MAP_BLOCK일 때 뿐이니까(key.cpp VK_CONTROL 참고)
						// && (block.BlockArr[row][col].BlockState != MAP_ALREADYTRAP) 넣으면 렉 걸림
						//&& (block.BlockArr[row][col].BlockState != MAP_TRAP) 넣으면 렉 걸림
				if ( (BlockArr[row][col].CrushState < 4) 
					&& (BlockArr[row][col].BlockState != MAP_TRAP) 
					&& (BlockArr[row][col].BlockState != MAP_ITEM)			)	//@10-1 //@마지막 함정이나 아이템이 있는 블록을 부수는 중에는 블록 재생되지 않도록.
				{
					BlockArr[row][col].CrushState += 1;
					BlockArr[row][col].BlockState = MAP_BLOCK;	//블록이 하나라도 살아나면, 타겟은 못 지나감.
				}
			}
		}

		BlockMakeTime = GetTickCount64();
		
	}

	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			if ((BlockArr[row][col].CrushState == 0)	)
			/* && (BlockArr[row][col].BlockState != MAP_TRAP)
				&& (BlockArr[row][col].BlockState != MAP_ITEM)	*/			//@10-1 //@9-3 여기에 적어줘야 이미 트랩이 놓인 좌표는 MAP_BROKEN으로 변하지 않을 수 있음 
																		//-> MAP_BROKEN으로 변하면, 벡터(컨테이너)가 무한생성되어버림	//@마지막 이제 그런 오류 발생하지 않음. if문 싹 다 없앰
			{
				BlockArr[row][col].BlockState = MAP_BROKEN;	//부숴져서 지나갈 수 있는 상태. Update식에서 시간이 지나면, 자동으로 살아나도록(MAP_BLOCK) 만들어주기
			}
		}
	}

	//@12-2 CrushBlock()에 넣으려 했는데, 업데이트가 느린지 바로바로 제대로 적용이 안 됨.
	//@9-1 블록을 부쉈는데, 그 블록이 TRAP이 있는 곳이었다면
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			//	MAP_TRAP이 아니라는 조건도 넣어줘야 컨테이너가 더이상 생성되지 않음
			if ( (BlockArr[row][col].BlockState == MAP_BROKEN) && (trap.TrapArr[row][col] == TRAP_YES) )	
			{				
				//@마지막 오류 점검 
				targetTrap.push_back(new Trap((col * 42) + 15, (row * 42) + 10));	// (벡터/리스트) 이용! 블록이 있는 위치에 트랩을 만든다.
				
				trap.TrapArr[row][col] = TRAP_NO;					//트랩(벡터(컨테이너)) 활동 시작. //@마지막 이제 TRAP_NO로 설정.
				BlockArr[row][col].BlockState = MAP_TRAP;			//이미 트랩이 놓인 상태 
				//트랩이 이미 만들어졌으면, MAP_TRAP 으로 설정. 그래야 이미 만든 객체가 계속 생기는 걸 막을 수 있음
				BlockSound.EffectPlay(Gmanager.ShowTrapSound);		//@14-1 블록 부쉈는데, 트랩 나오는 효과음
			}
		}
	}	
	

	//@10-1 블록을 부쉈는데, 그 블록이 아이템1이 있는 곳이었다면
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			if ((BlockArr[row][col].BlockState == MAP_BROKEN) && (item.ItemArr1[row][col].ItemState == ITEM_YES))
			{
				item.ItemArr1[row][col].show = TRUE;		//아이템 나타나도록
				item.ItemArr1[row][col].ItemState = ITEM_NO;	//아이템 이미 나온 상태
				BlockArr[row][col].BlockState = MAP_ITEM;	//이미 아이템이 놓인 상태
				//트랩이 이미 만들어졌으면, MAP_TRAP 으로 설정. 그래야 이미 만든 객체가 계속 생기는 걸 막을 수 있음
			}
		}
	}



}

void Block::Draw()
{
	//@6-1-2 맵 블록 그림 그리기
	for (int row = 0; row < 18; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			if (BlockArr[row][col].BlockState == MAP_BLOCK)	//부숴질 때마다 블록 이미지도 변함
			{
				if(BlockArr[row][col].CrushState == 4)	//부숴진 상태가 4일 때, 그림
					map_Block.Render(col * 42 + 15, row * 42 + 35, 0, 1.4, 1.4);		//@7-1 그림 위치 조금만 조정~25만큼
				else if(BlockArr[row][col].CrushState == 3)	//부숴진 상태가 3일 때, 그림
					Blockimg1.Render(col * 42 + 15, row * 42 + 35, 0, 1.4, 1.4);
				else if(BlockArr[row][col].CrushState == 2)	//부숴진 상태가 2일 때, 그림
					Blockimg2.Render(col * 42 + 15, row * 42 + 35, 0, 1.4, 1.4);
				else if(BlockArr[row][col].CrushState == 1)	//부숴진 상태가 1일 때, 그림
					Blockimg3.Render(col * 42 + 15, row * 42 + 35, 0, 1.4, 1.4);
			}
		}
	}
}

void Block::CrushBlock()
{
	//(1칸 간격)타겟의 주위에 블록이 있다면 그 주위에 있는 벽 부숴진다.
			// 블록 배열[행 = 세로축][열 = 가로축] 헷갈리지 않기!

	

	if (BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 1].BlockState == MAP_BLOCK)	//좌측
	{
		BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 1].CrushState -= 1;
		BlockSound.EffectPlay(Gmanager.CrashBlockSound);	//@14-2 블록 부수는 효과음
	}
	else if (BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) + 1].BlockState == MAP_BLOCK)	//우측
	{
		BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) + 1].CrushState -= 1;
		BlockSound.EffectPlay(Gmanager.CrashBlockSound);	//@14-2 블록 부수는 효과음
	}
	else if (BlockArr[(int)(target.t_y / 42) - 1][(int)(target.t_x / 42)].BlockState == MAP_BLOCK) //위
	{
		BlockArr[(int)(target.t_y / 42) - 1][(int)(target.t_x / 42)].CrushState -= 1;
		BlockSound.EffectPlay(Gmanager.CrashBlockSound);	//@14-2 블록 부수는 효과음
	}
	else if (BlockArr[(int)(target.t_y / 42) + 1][(int)(target.t_x / 42)].BlockState == MAP_BLOCK) //아래
	{
		BlockArr[(int)(target.t_y / 42) + 1][(int)(target.t_x / 42)].CrushState -= 1;
		BlockSound.EffectPlay(Gmanager.CrashBlockSound);	//@14-2 블록 부수는 효과음
	}
}

void Block::PushBlock(int pos)	//@14-1 따로 함수로 정리만 //블록이 밀리는 것처럼
{
	
	if (pos == LEFT)
	{
		block.BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 1].BlockState = MAP_EMPTY;
		block.BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) - 2].BlockState = MAP_BLOCK;
		BlockSound.EffectPlay(Gmanager.PushBlockSound);	//@14-2 블록 미는 효과음
	}
	else if (pos == RIGHT)
	{
		block.BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) + 1].BlockState = MAP_EMPTY;
		block.BlockArr[(int)(target.t_y / 42)][(int)(target.t_x / 42) + 2].BlockState = MAP_BLOCK;
		BlockSound.EffectPlay(Gmanager.PushBlockSound);	//@14-2 블록 미는 효과음
	}
	else if (pos == UP)
	{
		block.BlockArr[(int)(target.t_y / 42) - 1][(int)(target.t_x / 42)].BlockState = MAP_EMPTY;
		block.BlockArr[(int)(target.t_y / 42) - 2][(int)(target.t_x / 42)].BlockState = MAP_BLOCK;
		BlockSound.EffectPlay(Gmanager.PushBlockSound);	//@14-2 블록 미는 효과음
	}	
	else if (pos == DOWN)
	{
		block.BlockArr[(int)(target.t_y / 42) + 1][(int)(target.t_x / 42)].BlockState = MAP_EMPTY;
		block.BlockArr[(int)(target.t_y / 42) + 2][(int)(target.t_x / 42)].BlockState = MAP_BLOCK;
		BlockSound.EffectPlay(Gmanager.PushBlockSound);	//@14-2 블록 미는 효과음
	}
}