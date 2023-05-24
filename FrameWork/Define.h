#define SCREEN_WITH 1280	// ȭ�� ���� �ȼ�ũ��
#define SCREEN_HEIGHT 768	// ȭ�� ���� �ȼ�ũ��

#define FRAME 1000
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

// ����Ÿ ���̽�
#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "0000"
#define DB_NAME "test"
#define CHOP(x) x[strlen(x) - 1] = ' ' // �����ٰ� �Ⱦ�...

//@6-1-2 �� �迭 ����
#define MAP_EMPTY 0		//�� - ��� ���� �κ�
#define MAP_BLOCK 1		//�� - ��� �ִ� �κ�	//@14-1 �μ��� ����� �����̶� ����Ǿ MAP_BLOCK ������
#define MAP_BROKEN 2	//�� - ����� �μ� ���� //@7-1	
#define MAP_TRAP 3		//@9-1 Ʈ���� ���� ����
#define MAP_ITEM 4		//@10-1 �������� ���� ����

#define TRAP_NO	0
#define TRAP_YES 1

#define ITEM_NO	0	//@10-1 ������ �迭�� ����
#define ITEM_YES 1

#define BOMB_NO 0	//@11-1 ��ź �迭�� ����(��ź�� ������ �ֳ�, ����)
#define BOMB_YES 1


enum gamechap
{
	LOGO = 0,
	MENU = 1,
	GAME = 2,
	OVER = 3,
	METHOD = 4,		//@15-1 ���� ��� ��� ������ �߰�
	TOTALCHAP		//�ڵ����� TOTALCHAP�� 4-> 5�� �Ǿ���.
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