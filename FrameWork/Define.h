#define SCREEN_WITH 1280	// 화면 가로 픽셀크기
#define SCREEN_HEIGHT 768	// 화면 세로 픽셀크기

#define FRAME 1000
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

// 데이타 베이스
#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "0000"
#define DB_NAME "test"
#define CHOP(x) x[strlen(x) - 1] = ' ' // 쓸려다가 안씀...

//@6-1-2 맵 배열 생성
#define MAP_EMPTY 0		//맵 - 블록 없는 부분
#define MAP_BLOCK 1		//맵 - 블록 있는 부분	//@14-1 부서진 블록이 조금이라도 재생되어도 MAP_BLOCK 상태임
#define MAP_BROKEN 2	//맵 - 블록을 부순 상태 //@7-1	
#define MAP_TRAP 3		//@9-1 트랩이 놓인 상태
#define MAP_ITEM 4		//@10-1 아이템이 놓인 상태

#define TRAP_NO	0
#define TRAP_YES 1

#define ITEM_NO	0	//@10-1 아이템 배열의 상태
#define ITEM_YES 1

#define BOMB_NO 0	//@11-1 폭탄 배열의 상태(폭탄이 놓여져 있나, 없나)
#define BOMB_YES 1


enum gamechap
{
	LOGO = 0,
	MENU = 1,
	GAME = 2,
	OVER = 3,
	METHOD = 4,		//@15-1 게임 방법 띄울 페이지 추가
	TOTALCHAP		//자동으로 TOTALCHAP은 4-> 5가 되어짐.
};

enum alphabet
{
	A_, B_, C_, D_, E_, F_, G_, H_, I_, J_, K_, L_
};
enum gamework
{
	INIT = 0,
	WORK = 1,
	DRAW = 2
};