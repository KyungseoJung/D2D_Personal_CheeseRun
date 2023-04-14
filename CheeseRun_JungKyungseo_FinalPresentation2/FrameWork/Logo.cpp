#define _CRT_NONSTDC_NO_DEPRECATE

#include "Include.h"

Logo::Logo()
{
	// 데이타 베이스 관련
	//sql.mysql_Success = false;	//@2-6 주석 처리

	// 데이타 베이스 테스트 관련
	//count = 0;					//@2-6 주석 처리
}

Logo::~Logo()
{
}

void Logo::Init()
{
	speed = 2000;		//@2-1 속도 바꿔주는 변수 - 밑에 Update함수에서 실행될 예정
	alpha = 0;

	loadimg.Create("./resource/Img/Logo/Logo4.png", false, D3DCOLOR_XRGB(0, 0, 0));
	//g_SoundManager.Create(&Sound1, (LPWSTR)L"sound/hatnim.wav", 0, GUID_NULL);

	//// 데이타 베이스//////////////////////////////////////////////////////////////////////////////////////////////////////

	// 1 단계 테스트 접속 확인////////////////////////////////////////////////////////////////////

	//// MYSQL 구조체 변수 선언 (전체적인 데이타 베이스를 컨트럴 해준다)
	////MYSQL mysql;
	//// mysql 구조체 변수 초기화
	//mysql_init(&sql.mysql);
	//// mysql 데이타 베이스에 접속 (여기선 그냥 접속만 확인)
	//if(!mysql_real_connect(&sql.mysql, NULL/*host주소(ip)*/, "root", "Ws03230323*", NULL/*DB이름*/, 3306, NULL, 0) )
	//	sql.mysql_Success = false;
	//else sql.mysql_Success = true;
	//// mysql  접속 종료
	//mysql_close(&sql.mysql);
	//////////////////////////////////////////////////////////////////////////////////////////////

	// 2 단계 접속 확인

	/*
	MYSQL *mysql_real_connect(

		MYSQL *mysql,				// MYSQL 구조의 어드레스

		const char *host,			// 호스트 이름 또는 IP 어드레스 (default = localhost)

		const char *user,			// MySQL Login ID (default = 현재 로그인 이름)

		const char *passwd,			// 패스워드 (default = none)

		const char *db,				// 데이터베이스 이름 (default = none)

		unsigned int port,			// TCP/IP 연결 포트 (use default)

		const char *unix_socket,    // 소켓 (use default)

		unsigned long client_flag)  // flag (none)

		*/

	//@2-6 mysql 관련 주석 처리 ==================================================================
	
#pragma region mysql 주석 처리 관련

	//// mysql 구조체 변수 초기화
	//mysql_init(&sql.conn);

	//// ip, 접속 id , pass, 데이타 베이스명, 포트번호 등으로 접속
	//sql.connection = mysql_real_connect(&sql.conn, DB_HOST,
	//	DB_USER, DB_PASS,
	//	DB_NAME, 3306,
	//	(char*)NULL, 0);

	//// 만약 접속에 실패하면 다음 실행
	//if (sql.connection == NULL)
	//{
	//	sprintf_s(sql.state, "Mysql connection error : %s", mysql_error(&sql.conn));
	//	sql.mysql_Success = false;
	//}
	//else // 아니면...
	//{
	//	sql.mysql_Success = true;
	//}

	//// 다음 mysql_query() 함수로 MYSQL 구조체를 통한 쿼리문 전송
	//sql.query_start = mysql_query(sql.connection, "select * from login");
	//if (sql.query_start != 0) // 전송 실패시
	//{
	//	sprintf_s(sql.state, "Mysql query error : %s", mysql_error(&sql.conn));
	//}
	//else // 성공시
	//{
	//	sql.mysql_Success = true;
	//}

	//// mysql_store_result 함수로 넘어온 데이타 베이스 값 저장
	//sql.sql_result = mysql_store_result(sql.connection);

	//// ID, 비밀번호 가져오기 
	//// select * from login where ?? 사용 안했으니... 총 레코드 수 만큼 넘어옴(그 만큼 루프를 돈다)
	//while ((sql.sql_row = mysql_fetch_row(sql.sql_result)) != NULL)
	//{
	//	// 지금 현재는 마지막 레코드 값만 가져오지만... where id = ? ? 등으로 특정 대상의 값을 가져오던지...
	//	// 전체 데이타가 필요할 경우는 배열로 적절히 처리하자....
	//	// sql.sql_row[0] 인덱스로 해당 칼럼(열,필드)값 가져옴
	//	sprintf_s(sql.result, "%s %s\n", sql.sql_row[0], sql.sql_row[1]);

	//	// 이런식으로 문자열을 정수로 변환
	//	int a = atoi(sql.sql_row[1]);
	//	// 정수형을 문자열로 변환 함수 참고로 #define _CRT_NONSTDC_NO_DEPRECATE 안하면 에러 발생
	//	itoa(a, pw, 10);	// 10 진수로 가져옴

	//	// 레코드 수만큼 증가... 
	//	count += 1;
	//}

	//// 정수형을 문자열로 변환 함수 참고로 #define _CRT_NONSTDC_NO_DEPRECATE 안하면 에러 발생
	//itoa(count, cnt, 10);	// 10 진수로 가져옴

	//// sql.sql_result 값 해제
	//mysql_free_result(sql.sql_result);
#pragma endregion
	///////////////////////////////////////////////////////////////////////////////////////////////
}

// Chap, 재정의 함수 호출
void Logo::Update(double frame)
{


	alpha += speed * frame / 1000;	//@1 시작 빠르게
	if (alpha >= 255)
	{
		alpha = 255;
		speed = -speed;
		//Draw();
	}
	if (alpha <= 0) {
		g_Mng.n_Chap = MENU;
	}
	//Sound1.Play(0, DSBPLAY_LOOPING);

}

void Logo::Draw()
{
	loadimg.SetColor(255, 255, 255, alpha);  // 색상 변경	//@2-1 알파는 그림의 투명도 의미
	loadimg.Draw(0, 0);  //이미지출력					//@2-1
	dv_font.DrawString("Tom & Jerry", 730, 280);   //글자출력	//@2-1


	// 데이타 베이스 결과 및 처리 상태 표시/////////////////////////////////////
#pragma region mysql 관련 주석 처리

	//if (sql.mysql_Success)
	//{
	//	dv_font.DrawString("Success", 500, 0);
	//}
	//else
	//{
	//	dv_font.DrawString("Error", 500, 0);
	//	dv_font.DrawString(sql.state, 700, 0);
	//}

	//// 결과
	//dv_font.DrawString(sql.result, 500, 30);

	//// 총 레코드 수
	//dv_font.DrawString(cnt, 500, 60);

	//// 비번
	//dv_font.DrawString(pw, 500, 100);
#pragma endregion
	////////////////////////////////////////////////////////////
}

void Logo::OnMessage(MSG* msg)
{
	switch (msg->message)
	{
	/*case WM_LBUTTONDOWN:	//@10-7 마우스 왼쪽 키 눌러도 에러 안 뜨도록
		MessageBox(NULL, "", "", 0);
		break;*/
	}

}