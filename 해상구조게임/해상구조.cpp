#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Winsock2.h>
#include <windows.h>
#include <time.h>
#include <process.h>
#include <string.h>
#include <conio.h>
//#include <mysql.h>// 데이터 베이스
#pragma warning(disable:4996)
#pragma comment(lib, "winmm.lib")
#pragma comment(lib,"ws2_32.lib")
//#pragma comment (lib, "libmysql.lib")// 데이터베이스

#define CONSOLE_X 150
#define CONSOLE_Y 50
#define BUFSIZE 1024
#define MAX_Arr 48//글자 수
#define LEFT 75 //좌로 이동    //키보드값들 
#define RIGHT 77 //우로 이동 
#define UP 72 //위로 이동
#define DOWN 80 //아래로 이동
#define SPACE 32 // 확정
#define p 112 //일시정지 
#define P 80 //일시정지
#define ESC 27 //게임종료

int host();
void game_reset();
void map_draw();
void Interface_draw();
void Interface_Upload();
void gotoxy(int x, int y);
void gotoxy1(int x, int y);
void fullscreen();//풀스크린
void server();//서버
void client();
void CursorView();
void gamestart();
void rank();
void bot_word(int size, int bot_ran, int bot_y);
void user1(char* in);
void user2();
int end();
int title();
void rank_db();
void ranking();
void start();
int difficulty(); //난이도
char name[10];
void exit();
char key;
void user_si(char* in);

bool cut;
bool up;
bool rem = false;
bool rem1 = false;

void user_si(char* in) {
	while (1)
	{
		gotoxy1(28, 48); scanf("%s", in);
		gotoxy1(28, 48); printf("               ");
	}

}

void timer(int sec) { /// 타이머 (봇 ,플레이어 튜브 감소)
	while (1) {
		Sleep(sec);
		rem = true;
	}
}

void timer1(int sec) {/// 타이머 ( 봇 튜브 증가)
	while (1)
	{
		Sleep(sec);
		rem1 = true;
	}
}
void start() {
	gamestart();
	srand(time(NULL));
	game_reset();
	Interface_Upload();
}

int difficulty() {
	system("cls");
	int x; //타이틀화면이 표시되는 x좌표 
	int y; //타이틀화면이 표시되는 y좌표 
	int check = 1;
	char key;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("  ");
	y = 23;
	x = 85;

	gotoxy(x - 1, y - 1); printf(" ┌────────────┐");
	gotoxy(x - 1, y + 1); printf(" └────────────┘");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	gotoxy(x + 1, y); printf("   1 단 계 ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(x + 1, y + 2); printf("   2 단 계");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoxy(x + 1, y + 4); printf("   3 단 계");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(x + 1, y + 6); printf(" 뒤 로 가 기");
	while (1)
	{


		key = _getch();



		if (key == DOWN && check < 4)
		{
			check++;
			y += 2;
			gotoxy(x, y - 3); printf("                ");
			gotoxy(x, y - 1); printf("┌────────────┐");
			gotoxy(x, y + 1); printf("└────────────┘");
		}
		else if (key == UP && check > 1)
		{
			check--;
			y -= 2;
			gotoxy(x, y + 3); printf("                ");
			gotoxy(x, y - 1); printf("┌────────────┐");
			gotoxy(x, y + 1); printf("└────────────┘");
		}
		else if (key == SPACE)
		{
			return check;
		}
	}
}

void gotoxy(int x, int y)  //gotoxy 함수 선언
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int title()  //타이틀 화면 함수 선언
{
	PlaySound(TEXT("C:\\Users\\user\\Desktop\\Sound\\fail.wav"), NULL, SND_FILENAME | SND_ASYNC | 0);
	char name[11][125] = {
		"      ■■      ■  ■            ■        ■        ■■■■■■■■        ■■■■■■■■      ■■■■  ■    ■    ",
		"                ■  ■            ■        ■                      ■                ■            ■        ■    ■    ",
		"  ■■■■■■  ■  ■          ■  ■      ■                      ■                ■            ■        ■    ■    ",
		"                ■  ■          ■    ■    ■■■                  ■              ■  ■          ■        ■    ■    ",
		"      ■■      ■  ■        ■        ■  ■                      ■            ■      ■        ■        ■    ■    ",
		"    ■    ■    ■■■      ■              ■                    ■          ■■          ■      ■        ■■■■    ",
		"    ■    ■    ■  ■                              ■■■■■■■■■■              ■            ■        ■    ■    ",
		"    ■    ■    ■  ■          ■■■■■■                  ■                      ■            ■        ■    ■    ",
		"    ■    ■    ■  ■        ■            ■                ■                      ■            ■        ■    ■    ",
		"      ■■      ■  ■        ■            ■                ■            ■■■■■■■■■■    ■■■■  ■    ■    ",
		"                ■  ■          ■■■■■■                  ■                                              ■    ■    " };
	int x = 21; //타이틀화면이 표시되는 x좌표 
	int y = 4; //타이틀화면이 표시되는 y좌표 
	int check = 1;
	char key;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	for (int i = 0; i < 11; i++) {
		printf("\t\t\t\t");
		for (int j = 0; j < 125; j++)
			printf("%c", name[i][j]);
		printf("\n");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("  ");
	y = 23;
	x = 85;

	gotoxy(x - 1, y - 1); printf(" ┌────────────┐");
	gotoxy(x - 1, y + 1); printf(" └────────────┘");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	gotoxy(x + 1, y); printf(" 싱글 플레이");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	gotoxy(x + 1, y + 2); printf(" 멀티 플레이");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(x + 1, y + 4); printf("  Nick Name");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoxy(x + 1, y + 6); printf(" 명예의 전당");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(x + 1, y + 8); printf("  E  X I  T");
	while (1)
	{


		key = _getch();



		if (key == DOWN && check < 5)
		{
			check++;
			y += 2;
			gotoxy(x, y - 3); printf("                ");
			gotoxy(x, y - 1); printf("┌────────────┐");
			gotoxy(x, y + 1); printf("└────────────┘");
		}
		else if (key == UP && check > 1)
		{
			check--;
			y -= 2;
			gotoxy(x, y + 3); printf("                ");
			gotoxy(x, y - 1); printf("┌────────────┐");
			gotoxy(x, y + 1); printf("└────────────┘");
		}
		else if (key == SPACE)
		{
			return check;
		}

	}
}
void fullscreen() {  //전체화면 함수 선언
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}
void CursorView() //커서 설정
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void gamestart()
{
	int x = 65;
	int y = 45;
	for (int i = 0; i < 70; i++)
		printf("\n");
	PlaySound(TEXT("C:\\Users\\user\\Desktop\\Sound\\sound_start.wav"), NULL, SND_FILENAME | SND_ASYNC | 0);
	char start[30][53] = {
	"    ■■■■                                        ",
	"  ■        ■    ■                          ■    ",
	"  ■        ■    ■                          ■    ",
	"  ■            ■■■    ■■■      ■    ■■■  ",
	"    ■■          ■    ■      ■    ■■    ■    ",
	"        ■■      ■            ■    ■      ■    ",
	"            ■    ■      ■■■■    ■      ■    ",
	"  ■        ■    ■    ■      ■    ■      ■    ",
	"  ■        ■    ■    ■    ■■    ■      ■    ",
	"    ■■■■        ■    ■■  ■    ■        ■  " };
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	gotoxy(x, y);
	for (int i = 0; i < 30; i++)
	{
		gotoxy(x, y++);
		for (int j = 0; j < 53; j++) {
			printf("%c", start[i][j]);
		}
		printf("\n");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(x, y + 22);
	for (int i = 0; i < 10; i++)
	{
		printf("\n");
		Sleep(100);
	}
}
void profile() {
	int x = 65;
	int y = 45;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	gotoxy(x, y);
	printf("닉네임 입력(9글자 이하로 적어주세요) : ");
	scanf("%s", &name);
	gotoxy(x + 23, y + 40);
	printf("설정 완료 !!\n\n\n\n\n\n");
	for (int i = 0; i < 10; i++)
	{
		printf("\n");
		Sleep(100);
	}
}
//void rank() {
//	system("cls");
//	MYSQL* conn; //mysql 과의 커넥션 할 때 사용하는 변수
//	MYSQL_RES* res;  //쿼리문에 대한 결과값 받는 위치변수
//	MYSQL_ROW row; //쿼리문에 대한 실제 데이터값 저장 변수
//
//	const char* server = "127.0.0.1"; //서버 경로 localhost = 자기 컴퓨터
//	const char* user = "root";  //mysql 아이디
//	const char* password = "root"; //mysql 비번
//	const char* database = "project_GSM"; //데이터베이스 이름
//	char query[255];  //SQL 문을 저장할 문자열
//	conn = mysql_init(NULL); //conn 변수 초기화
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //색 변경
//	gotoxy(CONSOLE_X / 2 - 3, CONSOLE_Y / 2 - 17);
//	printf("****************************************\n"); //40칸
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //색 변경
//	gotoxy(CONSOLE_X / 2 - 3, CONSOLE_Y / 2 - 15);
//	printf("*               랭킹 기록              *\n");
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);  //색 변경
//	gotoxy(CONSOLE_X / 2 - 3, CONSOLE_Y / 2 - 13);
//	printf("****************************************\n");
//
//	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))  //DB 접속
//	{
//		fprintf(stderr, "%s\n", mysql_error(conn)); //에러가 났을 때 에러메세지 출력
//		exit(1);
//	}
//
//	sprintf(query, "SELECT*, rank() over(order by score desc) AS ranking FROM gsm;");  //query 변수에 실시간으로 랭킹을 갱신하는 SQL문 저장
//	mysql_query(conn, query);  //Mysql에 입력
//
//	res = mysql_store_result(conn);  //결과 확인하기
//	printf("\n");
//	int i = 0;
//
//	while ((row = mysql_fetch_row(res)) != NULL)  //NULL 값이 나올 때 까지 출력
//	{
//		if (i == 0)
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//		else if (i == 2)
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
//		else if (i == 4)
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//		else if (i > 4)
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//		gotoxy(CONSOLE_X / 2 - 5, CONSOLE_Y / 2 + i);
//		printf("이름 = %s\t점수 = %s\t순위 = %s\n", row[0], row[1], row[2]);
//		i += 2;
//	}
//	mysql_free_result(res); //결과 비우기
//	mysql_close(conn);  //mysql 연결 해제
//}
int end() {
	return 0;
}

int main()
{
	CursorView(); //커서크기 설정
	fullscreen(); //풀스크린 함수
	Sleep(800);
	system("cls");//화면 청소
	while (1)
	{
		CursorView();
	restart:
		int important = title(); //타이틀 함수 실행, 변수에 반환 값 저장
		switch (important)
		{
		case 1:  //싱글플레이
			switch (difficulty())
			{
			case 1: //1단계
				_beginthreadex(NULL, 0, (_beginthreadex_proc_type)timer, (void*)4000, 0, NULL);
				_beginthreadex(NULL, 0, (_beginthreadex_proc_type)timer1, (void*)3000, 0, NULL);
				start();
				break;
			case 2://2 단계
				_beginthreadex(NULL, 0, (_beginthreadex_proc_type)timer, (void*)2500, 0, NULL);
				_beginthreadex(NULL, 0, (_beginthreadex_proc_type)timer1, (void*)2000, 0, NULL);
				start();
			case 3: //3 단계

				_beginthreadex(NULL, 0, (_beginthreadex_proc_type)timer, (void*)1500, 0, NULL);
				_beginthreadex(NULL, 0, (_beginthreadex_proc_type)timer1, (void*)1000, 0, NULL);
				start();
			case 4:// 뒤로가기
				system("cls");
				goto restart;
			default:
				break;
			}
			break;
		case 2:
			switch (host())//멀티플레이
			{
			case 1:
				server();
				break;
			case 2:
				client();
				break;
			case 3:
				system("cls");
				goto restart;
			default:
				break;
			}
			break;
		case 3:  //nickname
			profile();
			system("cls");
			break;
		case 4:  //명예의 전당
			//rank();
			Sleep(3000);
			system("cls");
			break;
		case 5:  //EXIT
			//rank_db();
			end();
			break;
		default:
			break;
		}
		if (important == 5) //EXIT 선택시 종료
			break;
	}
}
// 단어 문자 배열
char base_char_arr[MAX_Arr][50] = { "안녕","갑자기","기다","가락지","건지다","낟알","가지다","작다","건너다","냄새","준말","발바리","채취하다","흩어지다","헤아리다","지저귀다","굼벵이","무르다","노랫가락","말다툼","고대하다","붓다","기울다","패다","밭일","되새김","건몸달다","부서지다","고갯짓","벅차다","거미덥다","기장","바닥","다짐","자리잡다","저런","기러기","질기다","가닥","기다리다","자락","반장","이기다","히죽","말하다","누구","날개","오들오들" , };
// 봇 이름 배열
char bot_name[8][10] = { "알포","밥","다니엘","데비","엠마","노에","시드스타","위트위니" };

int player_score = 0;		// 전역변수 점수 값
int player_tube = 4;		// player의 튜브 값
int bot_tube = 3;			// bot의 튜브 값


void gotoxy1(int x, int y) {
	COORD pos = { 3 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
char getKey()
{
	if (kbhit()) {
		return getch();
	}
	return '\0';
}
void getData(SOCKET* sock) {
	char data[100] = "";
	while (1) {
		memset(data, 0, sizeof(data));
		recv(*sock, data, sizeof(data), 0);
		gotoxy(0, 0);
		if (strcmp(data, "c") == 0) cut = true;
		if (strcmp(data, "u") == 0) up = true;
	}
}

void game_reset()// 게임 재시작 함수
{
	system("cls");// 게임 화면 지우기
	player_tube = 3;
	bot_tube = 3;
	map_draw();// 맵 출력
	Interface_draw();// 인터페이스 출력

	Interface_Upload();
}

void map_draw()
{
	int x = 7, y = 36;
	for (int i = 0; i < 50; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		gotoxy1(x + i, y); printf("%s", (rand() % 6 == 0) ? " " : "~");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Interface_draw()
{
	int size = 0;
	int x = 8, y = 2;
	gotoxy1(x - 1, y - 1); printf("┏───────────┓");// user 정보 인터페이스
	gotoxy1(x - 1, y + 1); printf("┗───────────┛");
	size = strlen(name);//글자수 구하기
	if (size == 8)// 글자수에 따라 띄어쓰기 
	{
		gotoxy1(x, y); printf("%s", name);// size 8일경우 글자수 4 
	}
	else if (size == 6)
	{
		gotoxy1(x, y); printf(" %s ", name);// size 6일경우 글자수 3
	}
	else if (size == 4)
	{
		gotoxy1(x, y); printf("  %s  ", name);// size 4일경우 글자수 2
	}
	else if (size == 2)
	{
		gotoxy1(x + 1, y); printf("   %s    ", name);// size 2일경우 글자수 1
	}
	gotoxy1(29, 2); printf("점수 : ");

	x = 18;
	y = 37;

	gotoxy1(x, y); printf("[player]");
	gotoxy1(x + 21, y); printf("[BOT_AI]");

	x = 12; //8 16 24 32 40
	y = 42;
	for (int i = 0; i <= 32; i += 8)
	{
		gotoxy1(x + i, y); printf(" (            )");// 문자 있는곳
	}

	x = 27;
	y = 48;
	gotoxy1(x, y - 1); printf("┏──────────────────┓");// user가 입력하는 인터페이스
	gotoxy1(x, y + 1); printf("┗──────────────────┛");

	x = 16, y = 35;

	int cnt = 0;
	player_tube = 3;
	while (cnt < player_tube)
	{
		int color = rand() % 7 + 9;//  색상 랜덤값
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//듀브 색상 변경
		gotoxy1(x, y - cnt++); printf("  (              )");// 플레이어 튜브
	}
	player_tube = 4;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	x = 37;
	y = 35;
	cnt = 0;
	while (cnt < bot_tube)
	{
		int color = rand() % 7 + 9;// 색깔 랜덤값
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//튜브 색상 변경
		gotoxy1(x, y - cnt++); printf("  (              )"); // 봇 튜브
		if (cnt == 3)
		{
			gotoxy1(38, 33); printf(" (          )");//봇 튜브 제거 글자
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	int bot_tube_x = 37, bot_tube_y = 26;
	int bot_text = 0;
	x = 51, y = 2;
	gotoxy1(x - 1, y - 1); printf("┏───────────┓");
	gotoxy1(x - 1, y + 1); printf("┗───────────┛");
	int i = rand() % 7;
	size = strlen(bot_name[i]);//글자수 구하기
	if (size == 8)// 글자수에 따라 띄어쓰기 
	{
		gotoxy1(x, y); printf("%s", bot_name[i]);
	}
	else if (size == 6)
	{
		gotoxy1(x, y); printf(" %s ", bot_name[i]);
	}
	else if (size == 4)
	{
		gotoxy1(x, y); printf("  %s  ", bot_name[i]);
	}
	else if (size == 2)
	{
		gotoxy1(x + 1, y); printf("%s    ", bot_name[i]);
	}

	gotoxy1(0, 0);
}

void bot_word(int size, int bot_ran, int bot_y) {// 상대(봇) 튜브 단어 출력
	if (size == 8)// 글자수에 따라 띄어쓰기  자리수에 따라 가운데 정렬
	{
		gotoxy1(39, bot_y); printf("%s", base_char_arr[bot_ran]); //gotoxy를 이용해 튜브단어 출력
	}
	else if (size == 6)
	{
		gotoxy1(39, bot_y); printf(" %s ", base_char_arr[bot_ran]);
	}
	else if (size == 4)
	{
		gotoxy1(39, bot_y); printf("  %s  ", base_char_arr[bot_ran]);
	}
	else if (size == 2)
	{
		gotoxy1(40, bot_y); printf("   %s    ", base_char_arr[bot_ran]);
	}
}

void Interface_Upload()
{
	int player_tube_cnt = 3;
	int bot_tube_cnt = 0;
	PlaySound(NULL, 0, 0);
	PlaySound(TEXT("C:\\Users\\user\\Desktop\\Sound\\music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	int cnt = -1;
	int ran[5];
	int bot_ran;
	int check = 0;
	int x = 13;
	int bot_y = 33;
	int y = 0;
	int size = 0;
	int user_cnt = 3; //내 튜브 
	int bot_cnt = 1;//상대 튜브
	int bot_y1 = 32;
	int bot_y2 = 34;

	bot_ran = rand() % MAX_Arr;


	for (int i = 0; i < 5; i++)
	{
		ran[i] = rand() % MAX_Arr;
		for (int j = 0; j < i; j++)
		{
			do {
				ran[i] = rand() % MAX_Arr;
			} while (ran[i] == ran[j]);
		}
	}


	for (int i = 0; i < 40; i += 8)
	{
		cnt++;
		size = strlen(base_char_arr[ran[cnt]]);// 단어 출력
		if (size == 8)// 글자수에 따라 띄어쓰기 
		{
			gotoxy1(x + i, 42); printf(" %s ", base_char_arr[ran[cnt]]);
		}
		else if (size == 6)
		{
			gotoxy1(x + i, 42); printf("  %s  ", base_char_arr[ran[cnt]]);
		}
		else if (size == 4)
		{
			gotoxy1(x + i, 42); printf("   %s   ", base_char_arr[ran[cnt]]);
		}
		else if (size == 2)
		{
			gotoxy1(x + i, 42); printf("    %s     ", base_char_arr[ran[cnt]]);
		}
	}
	bot_ran = rand() % MAX_Arr;
	size = strlen(base_char_arr[bot_ran]);//글자수 구하기
	bot_word(size, bot_ran, bot_y);//상대 튜브 글 출력
	while (1)
	{
		check = 0;
		while (1)
		{	/////////////////////////////////////////////////////////
			if (rem1 == true) {

				rem1 = false;
				size = strlen(base_char_arr[bot_ran]);//글자수 구하기
				////상대꺼 올리는거
				int color = rand() % 7 + 9;//  색상 랜덤값
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//듀브 색상 변경
				gotoxy1(37, --bot_y1 + 1);  printf("  (              )");// 봇 튜브//생성
				color = rand() % 7 + 9;//  색상 랜덤값
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//듀브 색상 변경
				gotoxy1(37, bot_y1 + 2);  printf("  (              )");// 봇 튜브 기존튜브 재생성 
				if (bot_tube != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//듀브 색상 변경
					gotoxy1(38, bot_y2 - 2); printf(" (");// 문자 있는곳
					gotoxy1(42, bot_y2-- - 2); printf(")");// 문자 있는곳
				}
				if (size == 8)// 글자수에 따라 띄어쓰기  자리수에 따라 가운데 정렬
				{
					bot_y--;
					gotoxy1(39, bot_y); printf("%s", base_char_arr[bot_ran]); //gotoxy를 이용해 튜브단어 출력
				}
				else if (size == 6)
				{
					bot_y--;
					gotoxy1(39, bot_y); printf(" %s ", base_char_arr[bot_ran]);
				}
				else if (size == 4)
				{
					bot_y--;
					gotoxy1(39, bot_y); printf("  %s  ", base_char_arr[bot_ran]);
				}
				else if (size == 2)
				{
					bot_y--;
					gotoxy1(40, bot_y); printf("   %s    ", base_char_arr[bot_ran]);
				}
				bot_tube++;
				gotoxy1(28, 48);
				if (bot_tube == 12)
				{
					gotoxy1(28, 10); printf("Player   LOSE!");
					Sleep(3000);
					//rank_db();
					player_score = 0;
					game_reset();
				}
				gotoxy1(28, 48);
			}
			/// ////////////////////////////////////////////////////////////////bot 튜브 삭제
			if (rem == true) {
				rem = false;
				gotoxy1(36, ++bot_y1); printf("                          ");//봇튜브 삭제

				if (bot_tube != 1)
				{
					gotoxy1(38, bot_y2); printf(" (");// 문자 있는곳
					gotoxy1(42, bot_y2++); printf(")");// 문자 있는곳
					gotoxy(45, bot_y2 - 1);
				}

				bot_tube--;
				bot_y++;
				size = strlen(base_char_arr[bot_ran]);
				if (bot_tube != 0)
				{
					bot_word(size, bot_ran, bot_y);//상대 튜브 글 출력
				}
				gotoxy1(28, 48);
				if (bot_tube == 0)
				{
					gotoxy1(28, 10); printf("Player   WIN!");
					Sleep(3000);
					game_reset();
				}
				gotoxy1(28, 48);

				////////////////////////////////////////////////////////// Player 튜브 삭제
				gotoxy(35, 28 + player_tube++); printf("                                    ");
				player_tube_cnt--;
				gotoxy1(28, 48);
				if (player_tube_cnt == -1) {
					gotoxy1(28, 10); printf("Player   LOSE!");
					//rank_db();
					Sleep(3000);
					player_score = 0;
					game_reset();
				}
				gotoxy1(28, 48);
			}
			/////////////////////////////////////////////////////
			char user[50] = { 0 };//유저 입력 저장 변수
			_beginthreadex(NULL, 0, (_beginthreadex_proc_type)user_si, (void*)user, 0, NULL);
			//scanf("%s", user);// 입력 
			//gotoxy1(28, 48); printf("               ");

			for (int cnt = 0; cnt < 5; cnt++)
			{
				///////////////////////////봇
				int ret = strcmp(user, base_char_arr[ran[cnt]]);// 출력 되어 단어 랑 같은지 확인
				int ret1 = strcmp(user, base_char_arr[bot_ran]); // 봇 튜브 안에 있는 단어 같은지 확인
				if (ret1 == 0)
				{
					player_score += 10;//점수 증가
					gotoxy1(31, 2); printf("%d", player_score);// 신규 누적 점수 출력
					gotoxy1(36, ++bot_y1); printf("                          ");//봇튜브 삭제
					if (bot_tube != 1)
					{
						gotoxy1(38, bot_y2); printf(" (");// 문자 있는곳
						gotoxy1(42, bot_y2++); printf(")");// 문자 있는곳
					}

					bot_tube--;
					bot_y++;
					bot_ran = rand() % MAX_Arr;//랜덤값
					size = strlen(base_char_arr[bot_ran]);//사이즈 비교
					if (bot_tube != 0)
					{
						bot_word(size, bot_ran, bot_y);//상대 튜브 글 출력
					}
					gotoxy1(28, 48);
					if (bot_tube == 0)//봇 튜브가 0 이 되면 Player win
					{
						gotoxy1(28, 10); printf("Player   WIN!");
						Sleep(3000);//3초 대기후
						game_reset();//게임 리셋
					}

					break;
					///
					///
					///
					/// 플레이어
				}
				size = 0;
				if (ret == 0)// 같을때 조건 
				{
					player_score += 10;//점수 증가
					gotoxy1(31, 2); printf("%d", player_score);// 신규 누적 점수 출력
					ran[cnt] = rand() % MAX_Arr;
					size = strlen(base_char_arr[ran[cnt]]);//글자수 구하기
					if (size == 8)
					{
						gotoxy1(13 + (cnt * 8), 42); printf(" %s ", base_char_arr[ran[cnt]]);
					}
					else if (size == 6)
					{
						gotoxy1(13 + (cnt * 8), 42); printf("  %s  ", base_char_arr[ran[cnt]]);
					}
					else if (size == 4)
					{
						gotoxy1(13 + (cnt * 8), 42); printf("   %s   ", base_char_arr[ran[cnt]]);
					}
					else if (size == 2)
					{
						gotoxy1(13 + (cnt * 8), 42); printf("    %s     ", base_char_arr[ran[cnt]]);
					}
					x = 16, y = 35;
					int color = rand() % 7 + 9;//  색상 랜덤값
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//듀브 색상 변경
					gotoxy1(x, y - player_tube_cnt++); printf("  (              )");// 플레이어 튜브player_tube_cnt;
					player_tube--;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					gotoxy1(28, 48);
					if (player_tube_cnt == 12)//player가 튜브 12개 쌓을경우 win
					{
						gotoxy1(28, 10); printf("Player   WIN!");
						Sleep(3000);
						game_reset();
					}
					check++;
					break;
				}
				else
				{
					if (player_tube_cnt == -1)
					{
						char key;
						gotoxy1(28, 10); printf("Player   Lose!");
						//rank_db();
						Sleep(3000);
						player_score = 0;
						game_reset();
					}
				}
			}
			if (check == 1)
			{
				break;
			}
			if (key == SPACE)
			{
				break;
			}
		}if (key == SPACE)
		{
			break;
		}
	}
}
// 서버 서버
void server() {
	system("cls");
	char temp[100];

	WSADATA wsaData;
	SOCKET serv_sock, clnt_sock;
	SOCKADDR_IN serv_addr, clnt_addr;

	char message[BUFSIZE] = { 0, };
	char data[BUFSIZE] = { 0, };
	int clntAdrSize;

	WSAStartup(MAKEWORD(2, 2), &wsaData);

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(8080);

	bind(serv_sock, (SOCKADDR*)&serv_addr, sizeof(serv_addr));

	listen(serv_sock, 5);
	clntAdrSize = sizeof(clnt_addr);

	gotoxy(80, 25); printf("연결을 기다리는 중입니다..\n");

	clnt_sock = accept(serv_sock, (SOCKADDR*)&clnt_addr, &clntAdrSize);
	system("cls");
	_beginthreadex(NULL, 0, (_beginthreadex_proc_type)getData, (void*)&clnt_sock, 0, NULL);
	map_draw();
	Interface_draw();
	gotoxy1(0, 0);
	int player_tube_cnt = 3;
	int bot_tube_cnt = 0;
	PlaySound(NULL, 0, 0);
	PlaySound(TEXT("C:\\Users\\user\\Desktop\\Sound\\music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	int cnt = -1;
	int ran[5];
	int bot_ran;
	int check = 0;
	int x = 13;
	int bot_y = 33;
	int y = 0;
	int size = 0;
	int user_cnt = 3; //내 튜브 
	int bot_cnt = 1;//상대 튜브
	int bot_y1 = 32;
	int bot_y2 = 34;

	bot_ran = rand() % MAX_Arr;


	for (int i = 0; i < 5; i++)
	{
		ran[i] = rand() % MAX_Arr;
		for (int j = 0; j < i; j++)
		{
			do {
				ran[i] = rand() % MAX_Arr;
			} while (ran[i] == ran[j]);
		}
	}


	for (int i = 0; i < 40; i += 8)
	{
		cnt++;
		size = strlen(base_char_arr[ran[cnt]]);// 단어 출력
		if (size == 8)// 글자수에 따라 띄어쓰기 
		{
			gotoxy1(x + i, 42); printf(" %s ", base_char_arr[ran[cnt]]);
		}
		else if (size == 6)
		{
			gotoxy1(x + i, 42); printf("  %s  ", base_char_arr[ran[cnt]]);
		}
		else if (size == 4)
		{
			gotoxy1(x + i, 42); printf("   %s   ", base_char_arr[ran[cnt]]);
		}
		else if (size == 2)
		{
			gotoxy1(x + i, 42); printf("    %s     ", base_char_arr[ran[cnt]]);
		}
	}
	bot_ran = rand() % MAX_Arr;
	size = strlen(base_char_arr[bot_ran]);//글자수 구하기
	bot_word(size, bot_ran, bot_y);//상대 튜브 글 출력
	while (1)
	{
		check = 0;
		while (1)
		{	/////////////////////////////////////////////////////////
			if (up == true) { //서버에서 클라이언트에 신호 올경우 실행

				up = false;
				size = strlen(base_char_arr[bot_ran]);//글자수 구하기
				////상대꺼 올리는거
				int color = rand() % 7 + 9;//  색상 랜덤값
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//듀브 색상 변경
				gotoxy1(37, --bot_y1 + 1);  printf("  (              )");// 봇 튜브//생성
				color = rand() % 7 + 9;//  색상 랜덤값
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//듀브 색상 변경
				gotoxy1(37, bot_y1 + 2);  printf("  (              )");// 봇 튜브 기존튜브 재생성 
				if (bot_tube != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//듀브 색상 변경
					gotoxy1(38, bot_y2 - 2); printf(" (");// 문자 있는곳
					gotoxy1(42, bot_y2-- - 2); printf(")");// 문자 있는곳
				}
				if (size == 8)// 글자수에 따라 띄어쓰기  자리수에 따라 가운데 정렬
				{
					bot_y--;
					gotoxy1(39, bot_y); printf("%s", base_char_arr[bot_ran]); //gotoxy를 이용해 튜브단어 출력
				}
				else if (size == 6)
				{
					bot_y--;
					gotoxy1(39, bot_y); printf(" %s ", base_char_arr[bot_ran]);
				}
				else if (size == 4)
				{
					bot_y--;
					gotoxy1(39, bot_y); printf("  %s  ", base_char_arr[bot_ran]);
				}
				else if (size == 2)
				{
					bot_y--;
					gotoxy1(40, bot_y); printf("   %s    ", base_char_arr[bot_ran]);
				}
				bot_tube++;
				gotoxy1(28, 48);
				if (bot_tube == 12)
				{
					gotoxy1(28, 10); printf("Player   LOSE!");
					Sleep(3000);
					//rank_db();
					player_score = 0;
					system("cls");
					server();// 다시시작
				}
				gotoxy1(28, 48);
			}
			/// ////////////////////////////////////////////////////////////////bot 튜브 삭제
			if (cut == true) {//서버에서 클라이언트에 신호 올경우 실행
				cut = false;
				player_score -= 10;
				gotoxy1(31, 2); printf("%d", player_score);// 신규 누적 점수 출력
				gotoxy1(16, 29 + player_tube++); printf("                                    ");
				player_tube_cnt--;
				gotoxy1(28, 48);
				if (player_tube_cnt == 0) {
					gotoxy1(28, 10); printf("Player   LOSE!");
					//rank_db();
					Sleep(3000);
					player_score = 0;
					system("cls");
					server();// 다시시작
				}
				gotoxy1(28, 48);
			}
			/////////////////////////////////////////////////////
			char user[50] = { 0 };//유저 입력 저장 변수
			_beginthreadex(NULL, 0, (_beginthreadex_proc_type)user1, (void*)user, 0, NULL);
			for (int cnt = 0; cnt < 5; cnt++)
			{
				int ret = strcmp(user, base_char_arr[ran[cnt]]);// 출력 되어 단어 랑 같은지 확인
				int ret1 = strcmp(user, base_char_arr[bot_ran]); // 상대 튜브 안에 있는 단어 같은지 확인
				if (ret1 == 0)
				{
					send(clnt_sock, "c", 1, 0);
					player_score += 10;//점수 증가
					gotoxy1(31, 2); printf("%d", player_score);// 신규 누적 점수 출력
					gotoxy1(36, ++bot_y1); printf("                          ");//상대튜브 삭제
					if (bot_tube != 1)
					{
						gotoxy1(38, bot_y2); printf(" (");// 문자 있는곳
						gotoxy1(42, bot_y2++); printf(")");// 문자 있는곳
					}

					bot_tube--;
					bot_y++;
					bot_ran = rand() % MAX_Arr;//랜덤값
					size = strlen(base_char_arr[bot_ran]);//사이즈 비교
					if (bot_tube != 0)
					{
						bot_word(size, bot_ran, bot_y);//상대 튜브 글 출력
					}
					if (bot_tube == 0)//상대 튜브가 0 이 되면 Player win
					{
						gotoxy1(28, 10); printf("Player   WIN!");
						Sleep(3000);//3초 대기후
						player_score = 0;
						system("cls");
						server();// 다시시작
					}

					break;
					//////////////////////////////////////////////////////////////////////////////////////
				}
				size = 0;
				if (ret == 0)// 밑에 단어 랑 같을때 조건 
				{
					send(clnt_sock, "u", 1, 0);
					player_score += 10;//점수 증가
					gotoxy1(31, 2); printf("%d", player_score);// 신규 누적 점수 출력
					ran[cnt] = rand() % MAX_Arr;
					size = strlen(base_char_arr[ran[cnt]]);//글자수 구하기
					if (size == 8)
					{
						gotoxy1(13 + (cnt * 8), 42); printf(" %s ", base_char_arr[ran[cnt]]);
					}
					else if (size == 6)
					{
						gotoxy1(13 + (cnt * 8), 42); printf("  %s  ", base_char_arr[ran[cnt]]);
					}
					else if (size == 4)
					{
						gotoxy1(13 + (cnt * 8), 42); printf("   %s   ", base_char_arr[ran[cnt]]);
					}
					else if (size == 2)
					{
						gotoxy1(13 + (cnt * 8), 42); printf("    %s     ", base_char_arr[ran[cnt]]);
					}
					x = 16, y = 35;
					int color = rand() % 7 + 9;//  색상 랜덤값
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//듀브 색상 변경
					gotoxy1(x, y - player_tube_cnt++); printf("  (              )");// 플레이어 튜브player_tube_cnt;
					player_tube--;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					gotoxy1(28, 48);
					if (player_tube_cnt == 12)//player가 튜브 12개 쌓을경우 win
					{
						gotoxy1(28, 10); printf("Player   WIN!");
						Sleep(3000);
						player_score = 0;
						system("cls");
						server();// 다시시작
					}
					check++;
					break;
				}
				else
				{
					if (player_tube_cnt == -1)
					{
						char key;
						gotoxy1(28, 10); printf("Player   Lose!");
						//rank_db();
						Sleep(3000);
						player_score = 0;
						system("cls");
						server();// 다시시작
					}
				}
			}
			if (check == 1)
			{
				break;
			}
			if (key == SPACE)
			{
				break;
			}
		}if (key == SPACE)
		{
			break;
		}
	}
}

/// //////////////////////
/// ///////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////
void client() { // 클라이언트
	system("cls");
	char ip[20];//ip 배열

	SOCKET sock;
	SOCKADDR_IN serveraddr;

	int retval;
	char buf[BUFSIZE + 1];
	int len;
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	sock = socket(AF_INET, SOCK_STREAM, 0);

	serveraddr.sin_family = AF_INET;

	gotoxy(80, 25); printf("서버 IP를 입력하세요 : ");
	gets_s(ip);
	strcat(ip, "\0");
	serveraddr.sin_addr.s_addr = inet_addr(ip);
	serveraddr.sin_port = htons(8080);

	retval = connect(sock, (SOCKADDR*)&serveraddr, sizeof(serveraddr));
	system("cls");
	ZeroMemory(buf, sizeof(buf));
	_beginthreadex(0, NULL, (_beginthreadex_proc_type)getData, &sock, NULL, 0);
	map_draw();
	Interface_draw();
	gotoxy1(0, 0);
	int player_tube_cnt = 3;
	int bot_tube_cnt = 0;
	PlaySound(NULL, 0, 0);
	PlaySound(TEXT("C:\\Users\\user\\Desktop\\Sound\\music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	int cnt = -1;
	int ran[5];
	int bot_ran;
	int check = 0;
	int x = 13;
	int bot_y = 33;
	int y = 0;
	int size = 0;
	int user_cnt = 3; //내 튜브 
	int bot_cnt = 1;//상대 튜브
	int bot_y1 = 32;
	int bot_y2 = 34;

	bot_ran = rand() % MAX_Arr;


	for (int i = 0; i < 5; i++)
	{
		ran[i] = rand() % MAX_Arr;
		for (int j = 0; j < i; j++)
		{
			do {
				ran[i] = rand() % MAX_Arr;
			} while (ran[i] == ran[j]);
		}
	}


	for (int i = 0; i < 40; i += 8)
	{
		cnt++;
		size = strlen(base_char_arr[ran[cnt]]);// 단어 출력
		if (size == 8)// 글자수에 따라 띄어쓰기 
		{
			gotoxy1(x + i, 42); printf(" %s ", base_char_arr[ran[cnt]]);
		}
		else if (size == 6)
		{
			gotoxy1(x + i, 42); printf("  %s  ", base_char_arr[ran[cnt]]);
		}
		else if (size == 4)
		{
			gotoxy1(x + i, 42); printf("   %s   ", base_char_arr[ran[cnt]]);
		}
		else if (size == 2)
		{
			gotoxy1(x + i, 42); printf("    %s     ", base_char_arr[ran[cnt]]);
		}
	}
	bot_ran = rand() % MAX_Arr;
	size = strlen(base_char_arr[bot_ran]);//글자수 구하기
	bot_word(size, bot_ran, bot_y);//상대 튜브 글 출력
	while (1)
	{
		check = 0;
		while (1)
		{	/////////////////////////////////////////////////////////
			if (up == true) { //서버에서 클라이언트에 신호 올경우 실행

				up = false;
				size = strlen(base_char_arr[bot_ran]);//글자수 구하기
				////상대꺼 올리는거
				int color = rand() % 7 + 9;//  색상 랜덤값
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//듀브 색상 변경
				gotoxy1(37, --bot_y1 + 1);  printf("  (              )");// 봇 튜브//생성
				color = rand() % 7 + 9;//  색상 랜덤값
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//듀브 색상 변경
				gotoxy1(37, bot_y1 + 2);  printf("  (              )");// 봇 튜브 기존튜브 재생성 
				if (bot_tube != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//듀브 색상 변경
					gotoxy1(38, bot_y2 - 2); printf(" (");// 문자 있는곳
					gotoxy1(42, bot_y2-- - 2); printf(")");// 문자 있는곳
				}
				if (size == 8)// 글자수에 따라 띄어쓰기  자리수에 따라 가운데 정렬
				{
					bot_y--;
					gotoxy1(39, bot_y); printf("%s", base_char_arr[bot_ran]); //gotoxy를 이용해 튜브단어 출력
				}
				else if (size == 6)
				{
					bot_y--;
					gotoxy1(39, bot_y); printf(" %s ", base_char_arr[bot_ran]);
				}
				else if (size == 4)
				{
					bot_y--;
					gotoxy1(39, bot_y); printf("  %s  ", base_char_arr[bot_ran]);
				}
				else if (size == 2)
				{
					bot_y--;
					gotoxy1(40, bot_y); printf("   %s    ", base_char_arr[bot_ran]);
				}
				bot_tube++;
				gotoxy1(28, 48);
				if (bot_tube == 12)
				{
					gotoxy1(28, 10); printf("Player   LOSE!");
					Sleep(3000);
					//rank_db();
					player_score = 0;
					system("cls");
					client();// 다시시작
				}
				gotoxy1(28, 48);
			}
			/// ////////////////////////////////////////////////////////////////bot 튜브 삭제
			if (cut == true) {//서버에서 클라이언트에 신호 올경우 실행
				cut = false;
				player_score -= 10;
				gotoxy1(31, 2); printf("%d", player_score);// 신규 누적 점수 출력
				gotoxy1(16, 29 + player_tube++); printf("                                    ");
				player_tube_cnt--;
				gotoxy1(28, 48);
				if (player_tube_cnt == 0) {
					gotoxy1(28, 10); printf("Player   LOSE!");
					//rank_db();
					Sleep(3000);
					player_score = 0;
					system("cls");
					client();// 다시시작
				}
				gotoxy1(28, 48);
			}
			/////////////////////////////////////////////////////
			char user[50] = { 0 };//유저 입력 저장 변수
			_beginthreadex(NULL, 0, (_beginthreadex_proc_type)user1, (void*)user, 0, NULL);
			for (int cnt = 0; cnt < 5; cnt++)
			{
				int ret = strcmp(user, base_char_arr[ran[cnt]]);// 출력 되어 단어 랑 같은지 확인
				int ret1 = strcmp(user, base_char_arr[bot_ran]); // 상대 튜브 안에 있는 단어 같은지 확인
				if (ret1 == 0)// 상대 단어 맞을때 실행
				{
					send(sock, "c", 1, 0);//서버에 신호 보냄
					player_score += 10;//점수 증가
					gotoxy1(31, 2); printf("%d", player_score);// 신규 누적 점수 출력
					gotoxy1(36, ++bot_y1); printf("                          ");//상대튜브 삭제
					if (bot_tube != 1)
					{
						gotoxy1(38, bot_y2); printf(" (");// 문자 있는곳
						gotoxy1(42, bot_y2++); printf(")");// 문자 있는곳
					}

					bot_tube--;
					bot_y++;
					bot_ran = rand() % MAX_Arr;//랜덤값
					size = strlen(base_char_arr[bot_ran]);//사이즈 비교
					if (bot_tube != 0)
					{
						bot_word(size, bot_ran, bot_y);//상대 튜브 글 출력
					}
					if (bot_tube == 0)//상대 튜브가 0 이 되면 Player win
					{
						gotoxy1(28, 10); printf("Player   WIN!");
						Sleep(3000);//3초 대기후
						system("cls");
						client();// 다시시작
					}

					break;
					//////////////////////////////////////////////////////////////////////////////////////
				}
				size = 0;
				if (ret == 0)// 밑에 단어 랑 같을때 조건 
				{
					send(sock, "u", 1, 0);//서버에 신호 보냄
					player_score += 10;//점수 증가
					gotoxy1(31, 2); printf("%d", player_score);// 신규 누적 점수 출력
					ran[cnt] = rand() % MAX_Arr;
					size = strlen(base_char_arr[ran[cnt]]);//글자수 구하기
					if (size == 8)
					{
						gotoxy1(13 + (cnt * 8), 42); printf(" %s ", base_char_arr[ran[cnt]]);
					}
					else if (size == 6)
					{
						gotoxy1(13 + (cnt * 8), 42); printf("  %s  ", base_char_arr[ran[cnt]]);
					}
					else if (size == 4)
					{
						gotoxy1(13 + (cnt * 8), 42); printf("   %s   ", base_char_arr[ran[cnt]]);
					}
					else if (size == 2)
					{
						gotoxy1(13 + (cnt * 8), 42); printf("    %s     ", base_char_arr[ran[cnt]]);
					}
					x = 16, y = 35;
					int color = rand() % 7 + 9;//  색상 랜덤값
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//듀브 색상 변경
					gotoxy1(x, y - player_tube_cnt++); printf("  (              )");// 플레이어 튜브player_tube_cnt;
					player_tube--;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					gotoxy1(28, 48);
					if (player_tube_cnt == 12)//player가 튜브 12개 쌓을경우 win
					{
						gotoxy1(28, 10); printf("Player   WIN!");
						Sleep(3000);
						system("cls");
						client();// 다시시작
					}
					check++;
					break;
				}
				else
				{
					if (player_tube_cnt == -1)
					{
						char key;
						gotoxy1(28, 10); printf("Player   Lose!");
						//rank_db();
						Sleep(3000);
						player_score = 0;
						system("cls");
						client();// 다시시작
					}
				}
			}
			if (check == 1)
			{
				break;
			}
			if (key == SPACE)
			{
				break;
			}
		}if (key == SPACE)
		{
			break;
		}
	}
}


int host() {
	system("cls");
	int x = 21; //타이틀화면이 표시되는 x좌표 
	int y = 4; //타이틀화면이 표시되는 y좌표 
	int check1 = 1;
	char key;
	printf("  ");
	y = 23;
	x = 85;


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); gotoxy(55, 11);  printf("  ########"); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); gotoxy(70, 11);  printf("########");  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); gotoxy(82, 11);  printf("#######"); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);  gotoxy(93, 11);  printf("#               #"); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); gotoxy(112, 11);  printf("########");  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); gotoxy(123, 11);  printf("#######");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); gotoxy(55, 12); printf(" #");					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);  gotoxy(70, 12);  printf("#");			      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); gotoxy(82, 12);  printf("#      #");		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); gotoxy(93, 12);  printf(" #             #");  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); gotoxy(112, 12);  printf("#");					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); gotoxy(123, 12);  printf("#      #");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); gotoxy(55, 13); printf("#");					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);  gotoxy(70, 13);  printf("#");				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); gotoxy(82, 13);  printf("#       #");		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); gotoxy(93, 13);  printf("  #           #");	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); gotoxy(112, 13);  printf("#");					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); gotoxy(123, 13);  printf("#       #");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); gotoxy(55, 14); printf(" #");					  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); gotoxy(70, 14);  printf("#");				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); gotoxy(82, 14);  printf("#      #");		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); gotoxy(93, 14);  printf("   #         #");	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); gotoxy(112, 14);  printf("#");					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); gotoxy(123, 14);  printf("#      #");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); gotoxy(55, 15); printf("  ########");  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); gotoxy(70, 15);  printf("#######");   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); gotoxy(82, 15);  printf("#######");	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); gotoxy(93, 15);  printf("    #       #");		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); gotoxy(112, 15);  printf("#######");		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); gotoxy(123, 15);  printf("#######");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); gotoxy(55, 16); printf("          #");		   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); gotoxy(70, 16);  printf("#");				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); gotoxy(82, 16);  printf("#     #");			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); gotoxy(93, 16);  printf("     #     #");		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); gotoxy(112, 16);  printf("#");					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); gotoxy(123, 16);  printf("#     #");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); gotoxy(55, 17); printf("           #   ");    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);  gotoxy(70, 17);  printf("#");				 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); gotoxy(82, 17);  printf("#      #");			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); gotoxy(93, 17);  printf("      #   #");		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); gotoxy(112, 17);  printf("#");					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); gotoxy(123, 17);  printf("#      #");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); gotoxy(55, 18); printf("          #   ");     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);  gotoxy(70, 18);  printf("#");				 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); gotoxy(82, 18);  printf("#       #");		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);	gotoxy(93, 18);  printf("       # #");		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); gotoxy(112, 18);  printf("#");					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); gotoxy(123, 18);  printf("#       #");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); gotoxy(55, 19); printf("  ########"); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); gotoxy(70, 19);  printf("########"); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); gotoxy(82, 19);  printf("#        #");		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);	gotoxy(93, 19);  printf("        #");			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); gotoxy(112, 19);  printf("########");	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); gotoxy(123, 19);  printf("#        #");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(x - 1, y - 1); printf(" ┌────────────┐");
	gotoxy(x - 1, y + 1); printf(" └────────────┘");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); gotoxy(x + 1, y); printf(" 서버 만들기");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); gotoxy(x + 1, y + 2); printf("  서버 접속");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); gotoxy(x + 1, y + 4); printf(" 뒤 로 가 기");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	y = 23;
	x = 85;
	while (1)
	{


		key = _getch();



		if (key == DOWN && check1 < 3)
		{
			check1++;
			y += 2;
			gotoxy(x - 1, y - 3); printf("                ");
			gotoxy(x - 1, y - 1); printf(" ┌────────────┐");
			gotoxy(x - 1, y + 1); printf(" └────────────┘");
		}
		else if (key == UP && check1 > 1)
		{
			check1--;
			y -= 2;
			gotoxy(x - 1, y + 3); printf("                ");
			gotoxy(x - 1, y - 1); printf(" ┌────────────┐");
			gotoxy(x - 1, y + 1); printf(" └────────────┘");
		}
		else if (key == SPACE)
		{
			return check1;
		}

	}
}
void user1(char* in) {
	gotoxy1(28, 48); printf("               ");
	gotoxy1(28, 48); scanf("%s", in);
}
void user2() {

}
//void rank_db()
//{
//	MYSQL* conn; //mysql 과의 커넥션 할 때 사용하는 변수
//
//	const char* server = "127.0.0.1"; //서버 경로 localhost = 자기 컴퓨터
//	const char* user = "root";  //mysql 아이디
//	const char* password = "root"; //mysql 비번
//	const char* database = "project_GSM"; //데이터베이스 이름
//	char query[255];  //SQL 문을 저장할 문자열
//	conn = mysql_init(NULL); //conn 변수 초기... (1KB 남음)


//개발 : 정현욱 ,문송