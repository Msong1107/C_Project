#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Winsock2.h>
#include <windows.h>
#include <time.h>
#include <process.h>
#include <string.h>
#include <conio.h>
//#include <mysql.h>// ������ ���̽�
#pragma warning(disable:4996)
#pragma comment(lib, "winmm.lib")
#pragma comment(lib,"ws2_32.lib")
//#pragma comment (lib, "libmysql.lib")// �����ͺ��̽�

#define CONSOLE_X 150
#define CONSOLE_Y 50
#define BUFSIZE 1024
#define MAX_Arr 48//���� ��
#define LEFT 75 //�·� �̵�    //Ű���尪�� 
#define RIGHT 77 //��� �̵� 
#define UP 72 //���� �̵�
#define DOWN 80 //�Ʒ��� �̵�
#define SPACE 32 // Ȯ��
#define p 112 //�Ͻ����� 
#define P 80 //�Ͻ�����
#define ESC 27 //��������

int host();
void game_reset();
void map_draw();
void Interface_draw();
void Interface_Upload();
void gotoxy(int x, int y);
void gotoxy1(int x, int y);
void fullscreen();//Ǯ��ũ��
void server();//����
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
int difficulty(); //���̵�
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

void timer(int sec) { /// Ÿ�̸� (�� ,�÷��̾� Ʃ�� ����)
	while (1) {
		Sleep(sec);
		rem = true;
	}
}

void timer1(int sec) {/// Ÿ�̸� ( �� Ʃ�� ����)
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
	int x; //Ÿ��Ʋȭ���� ǥ�õǴ� x��ǥ 
	int y; //Ÿ��Ʋȭ���� ǥ�õǴ� y��ǥ 
	int check = 1;
	char key;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("  ");
	y = 23;
	x = 85;

	gotoxy(x - 1, y - 1); printf(" ����������������������������");
	gotoxy(x - 1, y + 1); printf(" ����������������������������");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	gotoxy(x + 1, y); printf("   1 �� �� ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(x + 1, y + 2); printf("   2 �� ��");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoxy(x + 1, y + 4); printf("   3 �� ��");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(x + 1, y + 6); printf(" �� �� �� ��");
	while (1)
	{


		key = _getch();



		if (key == DOWN && check < 4)
		{
			check++;
			y += 2;
			gotoxy(x, y - 3); printf("                ");
			gotoxy(x, y - 1); printf("����������������������������");
			gotoxy(x, y + 1); printf("����������������������������");
		}
		else if (key == UP && check > 1)
		{
			check--;
			y -= 2;
			gotoxy(x, y + 3); printf("                ");
			gotoxy(x, y - 1); printf("����������������������������");
			gotoxy(x, y + 1); printf("����������������������������");
		}
		else if (key == SPACE)
		{
			return check;
		}
	}
}

void gotoxy(int x, int y)  //gotoxy �Լ� ����
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int title()  //Ÿ��Ʋ ȭ�� �Լ� ����
{
	PlaySound(TEXT("C:\\Users\\user\\Desktop\\Sound\\fail.wav"), NULL, SND_FILENAME | SND_ASYNC | 0);
	char name[11][125] = {
		"      ���      ��  ��            ��        ��        ���������        ���������      �����  ��    ��    ",
		"                ��  ��            ��        ��                      ��                ��            ��        ��    ��    ",
		"  �������  ��  ��          ��  ��      ��                      ��                ��            ��        ��    ��    ",
		"                ��  ��          ��    ��    ����                  ��              ��  ��          ��        ��    ��    ",
		"      ���      ��  ��        ��        ��  ��                      ��            ��      ��        ��        ��    ��    ",
		"    ��    ��    ����      ��              ��                    ��          ���          ��      ��        �����    ",
		"    ��    ��    ��  ��                              �����������              ��            ��        ��    ��    ",
		"    ��    ��    ��  ��          �������                  ��                      ��            ��        ��    ��    ",
		"    ��    ��    ��  ��        ��            ��                ��                      ��            ��        ��    ��    ",
		"      ���      ��  ��        ��            ��                ��            �����������    �����  ��    ��    ",
		"                ��  ��          �������                  ��                                              ��    ��    " };
	int x = 21; //Ÿ��Ʋȭ���� ǥ�õǴ� x��ǥ 
	int y = 4; //Ÿ��Ʋȭ���� ǥ�õǴ� y��ǥ 
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

	gotoxy(x - 1, y - 1); printf(" ����������������������������");
	gotoxy(x - 1, y + 1); printf(" ����������������������������");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	gotoxy(x + 1, y); printf(" �̱� �÷���");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	gotoxy(x + 1, y + 2); printf(" ��Ƽ �÷���");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(x + 1, y + 4); printf("  Nick Name");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoxy(x + 1, y + 6); printf(" ���� ����");
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
			gotoxy(x, y - 1); printf("����������������������������");
			gotoxy(x, y + 1); printf("����������������������������");
		}
		else if (key == UP && check > 1)
		{
			check--;
			y -= 2;
			gotoxy(x, y + 3); printf("                ");
			gotoxy(x, y - 1); printf("����������������������������");
			gotoxy(x, y + 1); printf("����������������������������");
		}
		else if (key == SPACE)
		{
			return check;
		}

	}
}
void fullscreen() {  //��üȭ�� �Լ� ����
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}
void CursorView() //Ŀ�� ����
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
	cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
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
	"    �����                                        ",
	"  ��        ��    ��                          ��    ",
	"  ��        ��    ��                          ��    ",
	"  ��            ����    ����      ��    ����  ",
	"    ���          ��    ��      ��    ���    ��    ",
	"        ���      ��            ��    ��      ��    ",
	"            ��    ��      �����    ��      ��    ",
	"  ��        ��    ��    ��      ��    ��      ��    ",
	"  ��        ��    ��    ��    ���    ��      ��    ",
	"    �����        ��    ���  ��    ��        ��  " };
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
	printf("�г��� �Է�(9���� ���Ϸ� �����ּ���) : ");
	scanf("%s", &name);
	gotoxy(x + 23, y + 40);
	printf("���� �Ϸ� !!\n\n\n\n\n\n");
	for (int i = 0; i < 10; i++)
	{
		printf("\n");
		Sleep(100);
	}
}
//void rank() {
//	system("cls");
//	MYSQL* conn; //mysql ���� Ŀ�ؼ� �� �� ����ϴ� ����
//	MYSQL_RES* res;  //�������� ���� ����� �޴� ��ġ����
//	MYSQL_ROW row; //�������� ���� ���� �����Ͱ� ���� ����
//
//	const char* server = "127.0.0.1"; //���� ��� localhost = �ڱ� ��ǻ��
//	const char* user = "root";  //mysql ���̵�
//	const char* password = "root"; //mysql ���
//	const char* database = "project_GSM"; //�����ͺ��̽� �̸�
//	char query[255];  //SQL ���� ������ ���ڿ�
//	conn = mysql_init(NULL); //conn ���� �ʱ�ȭ
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //�� ����
//	gotoxy(CONSOLE_X / 2 - 3, CONSOLE_Y / 2 - 17);
//	printf("****************************************\n"); //40ĭ
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //�� ����
//	gotoxy(CONSOLE_X / 2 - 3, CONSOLE_Y / 2 - 15);
//	printf("*               ��ŷ ���              *\n");
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);  //�� ����
//	gotoxy(CONSOLE_X / 2 - 3, CONSOLE_Y / 2 - 13);
//	printf("****************************************\n");
//
//	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))  //DB ����
//	{
//		fprintf(stderr, "%s\n", mysql_error(conn)); //������ ���� �� �����޼��� ���
//		exit(1);
//	}
//
//	sprintf(query, "SELECT*, rank() over(order by score desc) AS ranking FROM gsm;");  //query ������ �ǽð����� ��ŷ�� �����ϴ� SQL�� ����
//	mysql_query(conn, query);  //Mysql�� �Է�
//
//	res = mysql_store_result(conn);  //��� Ȯ���ϱ�
//	printf("\n");
//	int i = 0;
//
//	while ((row = mysql_fetch_row(res)) != NULL)  //NULL ���� ���� �� ���� ���
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
//		printf("�̸� = %s\t���� = %s\t���� = %s\n", row[0], row[1], row[2]);
//		i += 2;
//	}
//	mysql_free_result(res); //��� ����
//	mysql_close(conn);  //mysql ���� ����
//}
int end() {
	return 0;
}

int main()
{
	CursorView(); //Ŀ��ũ�� ����
	fullscreen(); //Ǯ��ũ�� �Լ�
	Sleep(800);
	system("cls");//ȭ�� û��
	while (1)
	{
		CursorView();
	restart:
		int important = title(); //Ÿ��Ʋ �Լ� ����, ������ ��ȯ �� ����
		switch (important)
		{
		case 1:  //�̱��÷���
			switch (difficulty())
			{
			case 1: //1�ܰ�
				_beginthreadex(NULL, 0, (_beginthreadex_proc_type)timer, (void*)4000, 0, NULL);
				_beginthreadex(NULL, 0, (_beginthreadex_proc_type)timer1, (void*)3000, 0, NULL);
				start();
				break;
			case 2://2 �ܰ�
				_beginthreadex(NULL, 0, (_beginthreadex_proc_type)timer, (void*)2500, 0, NULL);
				_beginthreadex(NULL, 0, (_beginthreadex_proc_type)timer1, (void*)2000, 0, NULL);
				start();
			case 3: //3 �ܰ�

				_beginthreadex(NULL, 0, (_beginthreadex_proc_type)timer, (void*)1500, 0, NULL);
				_beginthreadex(NULL, 0, (_beginthreadex_proc_type)timer1, (void*)1000, 0, NULL);
				start();
			case 4:// �ڷΰ���
				system("cls");
				goto restart;
			default:
				break;
			}
			break;
		case 2:
			switch (host())//��Ƽ�÷���
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
		case 4:  //���� ����
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
		if (important == 5) //EXIT ���ý� ����
			break;
	}
}
// �ܾ� ���� �迭
char base_char_arr[MAX_Arr][50] = { "�ȳ�","���ڱ�","���","������","������","����","������","�۴�","�ǳʴ�","����","�ظ�","�߹ٸ�","ä���ϴ�","�������","��Ƹ���","�����ʹ�","������","������","�뷧����","������","����ϴ�","�״�","����","�д�","����","�ǻ���","�Ǹ��޴�","�μ�����","����","������","�Ź̴���","����","�ٴ�","����","�ڸ����","����","�ⷯ��","�����","����","��ٸ���","�ڶ�","����","�̱��","����","���ϴ�","����","����","�������" , };
// �� �̸� �迭
char bot_name[8][10] = { "����","��","�ٴϿ�","����","����","�뿡","�õ彺Ÿ","��Ʈ����" };

int player_score = 0;		// �������� ���� ��
int player_tube = 4;		// player�� Ʃ�� ��
int bot_tube = 3;			// bot�� Ʃ�� ��


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

void game_reset()// ���� ����� �Լ�
{
	system("cls");// ���� ȭ�� �����
	player_tube = 3;
	bot_tube = 3;
	map_draw();// �� ���
	Interface_draw();// �������̽� ���

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
	gotoxy1(x - 1, y - 1); printf("��������������������������");// user ���� �������̽�
	gotoxy1(x - 1, y + 1); printf("��������������������������");
	size = strlen(name);//���ڼ� ���ϱ�
	if (size == 8)// ���ڼ��� ���� ���� 
	{
		gotoxy1(x, y); printf("%s", name);// size 8�ϰ�� ���ڼ� 4 
	}
	else if (size == 6)
	{
		gotoxy1(x, y); printf(" %s ", name);// size 6�ϰ�� ���ڼ� 3
	}
	else if (size == 4)
	{
		gotoxy1(x, y); printf("  %s  ", name);// size 4�ϰ�� ���ڼ� 2
	}
	else if (size == 2)
	{
		gotoxy1(x + 1, y); printf("   %s    ", name);// size 2�ϰ�� ���ڼ� 1
	}
	gotoxy1(29, 2); printf("���� : ");

	x = 18;
	y = 37;

	gotoxy1(x, y); printf("[player]");
	gotoxy1(x + 21, y); printf("[BOT_AI]");

	x = 12; //8 16 24 32 40
	y = 42;
	for (int i = 0; i <= 32; i += 8)
	{
		gotoxy1(x + i, y); printf(" (            )");// ���� �ִ°�
	}

	x = 27;
	y = 48;
	gotoxy1(x, y - 1); printf("����������������������������������������");// user�� �Է��ϴ� �������̽�
	gotoxy1(x, y + 1); printf("����������������������������������������");

	x = 16, y = 35;

	int cnt = 0;
	player_tube = 3;
	while (cnt < player_tube)
	{
		int color = rand() % 7 + 9;//  ���� ������
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//��� ���� ����
		gotoxy1(x, y - cnt++); printf("  (              )");// �÷��̾� Ʃ��
	}
	player_tube = 4;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	x = 37;
	y = 35;
	cnt = 0;
	while (cnt < bot_tube)
	{
		int color = rand() % 7 + 9;// ���� ������
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//Ʃ�� ���� ����
		gotoxy1(x, y - cnt++); printf("  (              )"); // �� Ʃ��
		if (cnt == 3)
		{
			gotoxy1(38, 33); printf(" (          )");//�� Ʃ�� ���� ����
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	int bot_tube_x = 37, bot_tube_y = 26;
	int bot_text = 0;
	x = 51, y = 2;
	gotoxy1(x - 1, y - 1); printf("��������������������������");
	gotoxy1(x - 1, y + 1); printf("��������������������������");
	int i = rand() % 7;
	size = strlen(bot_name[i]);//���ڼ� ���ϱ�
	if (size == 8)// ���ڼ��� ���� ���� 
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

void bot_word(int size, int bot_ran, int bot_y) {// ���(��) Ʃ�� �ܾ� ���
	if (size == 8)// ���ڼ��� ���� ����  �ڸ����� ���� ��� ����
	{
		gotoxy1(39, bot_y); printf("%s", base_char_arr[bot_ran]); //gotoxy�� �̿��� Ʃ��ܾ� ���
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
	int user_cnt = 3; //�� Ʃ�� 
	int bot_cnt = 1;//��� Ʃ��
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
		size = strlen(base_char_arr[ran[cnt]]);// �ܾ� ���
		if (size == 8)// ���ڼ��� ���� ���� 
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
	size = strlen(base_char_arr[bot_ran]);//���ڼ� ���ϱ�
	bot_word(size, bot_ran, bot_y);//��� Ʃ�� �� ���
	while (1)
	{
		check = 0;
		while (1)
		{	/////////////////////////////////////////////////////////
			if (rem1 == true) {

				rem1 = false;
				size = strlen(base_char_arr[bot_ran]);//���ڼ� ���ϱ�
				////��벨 �ø��°�
				int color = rand() % 7 + 9;//  ���� ������
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//��� ���� ����
				gotoxy1(37, --bot_y1 + 1);  printf("  (              )");// �� Ʃ��//����
				color = rand() % 7 + 9;//  ���� ������
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//��� ���� ����
				gotoxy1(37, bot_y1 + 2);  printf("  (              )");// �� Ʃ�� ����Ʃ�� ����� 
				if (bot_tube != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//��� ���� ����
					gotoxy1(38, bot_y2 - 2); printf(" (");// ���� �ִ°�
					gotoxy1(42, bot_y2-- - 2); printf(")");// ���� �ִ°�
				}
				if (size == 8)// ���ڼ��� ���� ����  �ڸ����� ���� ��� ����
				{
					bot_y--;
					gotoxy1(39, bot_y); printf("%s", base_char_arr[bot_ran]); //gotoxy�� �̿��� Ʃ��ܾ� ���
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
			/// ////////////////////////////////////////////////////////////////bot Ʃ�� ����
			if (rem == true) {
				rem = false;
				gotoxy1(36, ++bot_y1); printf("                          ");//��Ʃ�� ����

				if (bot_tube != 1)
				{
					gotoxy1(38, bot_y2); printf(" (");// ���� �ִ°�
					gotoxy1(42, bot_y2++); printf(")");// ���� �ִ°�
					gotoxy(45, bot_y2 - 1);
				}

				bot_tube--;
				bot_y++;
				size = strlen(base_char_arr[bot_ran]);
				if (bot_tube != 0)
				{
					bot_word(size, bot_ran, bot_y);//��� Ʃ�� �� ���
				}
				gotoxy1(28, 48);
				if (bot_tube == 0)
				{
					gotoxy1(28, 10); printf("Player   WIN!");
					Sleep(3000);
					game_reset();
				}
				gotoxy1(28, 48);

				////////////////////////////////////////////////////////// Player Ʃ�� ����
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
			char user[50] = { 0 };//���� �Է� ���� ����
			_beginthreadex(NULL, 0, (_beginthreadex_proc_type)user_si, (void*)user, 0, NULL);
			//scanf("%s", user);// �Է� 
			//gotoxy1(28, 48); printf("               ");

			for (int cnt = 0; cnt < 5; cnt++)
			{
				///////////////////////////��
				int ret = strcmp(user, base_char_arr[ran[cnt]]);// ��� �Ǿ� �ܾ� �� ������ Ȯ��
				int ret1 = strcmp(user, base_char_arr[bot_ran]); // �� Ʃ�� �ȿ� �ִ� �ܾ� ������ Ȯ��
				if (ret1 == 0)
				{
					player_score += 10;//���� ����
					gotoxy1(31, 2); printf("%d", player_score);// �ű� ���� ���� ���
					gotoxy1(36, ++bot_y1); printf("                          ");//��Ʃ�� ����
					if (bot_tube != 1)
					{
						gotoxy1(38, bot_y2); printf(" (");// ���� �ִ°�
						gotoxy1(42, bot_y2++); printf(")");// ���� �ִ°�
					}

					bot_tube--;
					bot_y++;
					bot_ran = rand() % MAX_Arr;//������
					size = strlen(base_char_arr[bot_ran]);//������ ��
					if (bot_tube != 0)
					{
						bot_word(size, bot_ran, bot_y);//��� Ʃ�� �� ���
					}
					gotoxy1(28, 48);
					if (bot_tube == 0)//�� Ʃ�갡 0 �� �Ǹ� Player win
					{
						gotoxy1(28, 10); printf("Player   WIN!");
						Sleep(3000);//3�� �����
						game_reset();//���� ����
					}

					break;
					///
					///
					///
					/// �÷��̾�
				}
				size = 0;
				if (ret == 0)// ������ ���� 
				{
					player_score += 10;//���� ����
					gotoxy1(31, 2); printf("%d", player_score);// �ű� ���� ���� ���
					ran[cnt] = rand() % MAX_Arr;
					size = strlen(base_char_arr[ran[cnt]]);//���ڼ� ���ϱ�
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
					int color = rand() % 7 + 9;//  ���� ������
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//��� ���� ����
					gotoxy1(x, y - player_tube_cnt++); printf("  (              )");// �÷��̾� Ʃ��player_tube_cnt;
					player_tube--;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					gotoxy1(28, 48);
					if (player_tube_cnt == 12)//player�� Ʃ�� 12�� ������� win
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
// ���� ����
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

	gotoxy(80, 25); printf("������ ��ٸ��� ���Դϴ�..\n");

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
	int user_cnt = 3; //�� Ʃ�� 
	int bot_cnt = 1;//��� Ʃ��
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
		size = strlen(base_char_arr[ran[cnt]]);// �ܾ� ���
		if (size == 8)// ���ڼ��� ���� ���� 
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
	size = strlen(base_char_arr[bot_ran]);//���ڼ� ���ϱ�
	bot_word(size, bot_ran, bot_y);//��� Ʃ�� �� ���
	while (1)
	{
		check = 0;
		while (1)
		{	/////////////////////////////////////////////////////////
			if (up == true) { //�������� Ŭ���̾�Ʈ�� ��ȣ �ð�� ����

				up = false;
				size = strlen(base_char_arr[bot_ran]);//���ڼ� ���ϱ�
				////��벨 �ø��°�
				int color = rand() % 7 + 9;//  ���� ������
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//��� ���� ����
				gotoxy1(37, --bot_y1 + 1);  printf("  (              )");// �� Ʃ��//����
				color = rand() % 7 + 9;//  ���� ������
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//��� ���� ����
				gotoxy1(37, bot_y1 + 2);  printf("  (              )");// �� Ʃ�� ����Ʃ�� ����� 
				if (bot_tube != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//��� ���� ����
					gotoxy1(38, bot_y2 - 2); printf(" (");// ���� �ִ°�
					gotoxy1(42, bot_y2-- - 2); printf(")");// ���� �ִ°�
				}
				if (size == 8)// ���ڼ��� ���� ����  �ڸ����� ���� ��� ����
				{
					bot_y--;
					gotoxy1(39, bot_y); printf("%s", base_char_arr[bot_ran]); //gotoxy�� �̿��� Ʃ��ܾ� ���
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
					server();// �ٽý���
				}
				gotoxy1(28, 48);
			}
			/// ////////////////////////////////////////////////////////////////bot Ʃ�� ����
			if (cut == true) {//�������� Ŭ���̾�Ʈ�� ��ȣ �ð�� ����
				cut = false;
				player_score -= 10;
				gotoxy1(31, 2); printf("%d", player_score);// �ű� ���� ���� ���
				gotoxy1(16, 29 + player_tube++); printf("                                    ");
				player_tube_cnt--;
				gotoxy1(28, 48);
				if (player_tube_cnt == 0) {
					gotoxy1(28, 10); printf("Player   LOSE!");
					//rank_db();
					Sleep(3000);
					player_score = 0;
					system("cls");
					server();// �ٽý���
				}
				gotoxy1(28, 48);
			}
			/////////////////////////////////////////////////////
			char user[50] = { 0 };//���� �Է� ���� ����
			_beginthreadex(NULL, 0, (_beginthreadex_proc_type)user1, (void*)user, 0, NULL);
			for (int cnt = 0; cnt < 5; cnt++)
			{
				int ret = strcmp(user, base_char_arr[ran[cnt]]);// ��� �Ǿ� �ܾ� �� ������ Ȯ��
				int ret1 = strcmp(user, base_char_arr[bot_ran]); // ��� Ʃ�� �ȿ� �ִ� �ܾ� ������ Ȯ��
				if (ret1 == 0)
				{
					send(clnt_sock, "c", 1, 0);
					player_score += 10;//���� ����
					gotoxy1(31, 2); printf("%d", player_score);// �ű� ���� ���� ���
					gotoxy1(36, ++bot_y1); printf("                          ");//���Ʃ�� ����
					if (bot_tube != 1)
					{
						gotoxy1(38, bot_y2); printf(" (");// ���� �ִ°�
						gotoxy1(42, bot_y2++); printf(")");// ���� �ִ°�
					}

					bot_tube--;
					bot_y++;
					bot_ran = rand() % MAX_Arr;//������
					size = strlen(base_char_arr[bot_ran]);//������ ��
					if (bot_tube != 0)
					{
						bot_word(size, bot_ran, bot_y);//��� Ʃ�� �� ���
					}
					if (bot_tube == 0)//��� Ʃ�갡 0 �� �Ǹ� Player win
					{
						gotoxy1(28, 10); printf("Player   WIN!");
						Sleep(3000);//3�� �����
						player_score = 0;
						system("cls");
						server();// �ٽý���
					}

					break;
					//////////////////////////////////////////////////////////////////////////////////////
				}
				size = 0;
				if (ret == 0)// �ؿ� �ܾ� �� ������ ���� 
				{
					send(clnt_sock, "u", 1, 0);
					player_score += 10;//���� ����
					gotoxy1(31, 2); printf("%d", player_score);// �ű� ���� ���� ���
					ran[cnt] = rand() % MAX_Arr;
					size = strlen(base_char_arr[ran[cnt]]);//���ڼ� ���ϱ�
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
					int color = rand() % 7 + 9;//  ���� ������
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//��� ���� ����
					gotoxy1(x, y - player_tube_cnt++); printf("  (              )");// �÷��̾� Ʃ��player_tube_cnt;
					player_tube--;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					gotoxy1(28, 48);
					if (player_tube_cnt == 12)//player�� Ʃ�� 12�� ������� win
					{
						gotoxy1(28, 10); printf("Player   WIN!");
						Sleep(3000);
						player_score = 0;
						system("cls");
						server();// �ٽý���
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
						server();// �ٽý���
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
void client() { // Ŭ���̾�Ʈ
	system("cls");
	char ip[20];//ip �迭

	SOCKET sock;
	SOCKADDR_IN serveraddr;

	int retval;
	char buf[BUFSIZE + 1];
	int len;
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	sock = socket(AF_INET, SOCK_STREAM, 0);

	serveraddr.sin_family = AF_INET;

	gotoxy(80, 25); printf("���� IP�� �Է��ϼ��� : ");
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
	int user_cnt = 3; //�� Ʃ�� 
	int bot_cnt = 1;//��� Ʃ��
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
		size = strlen(base_char_arr[ran[cnt]]);// �ܾ� ���
		if (size == 8)// ���ڼ��� ���� ���� 
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
	size = strlen(base_char_arr[bot_ran]);//���ڼ� ���ϱ�
	bot_word(size, bot_ran, bot_y);//��� Ʃ�� �� ���
	while (1)
	{
		check = 0;
		while (1)
		{	/////////////////////////////////////////////////////////
			if (up == true) { //�������� Ŭ���̾�Ʈ�� ��ȣ �ð�� ����

				up = false;
				size = strlen(base_char_arr[bot_ran]);//���ڼ� ���ϱ�
				////��벨 �ø��°�
				int color = rand() % 7 + 9;//  ���� ������
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//��� ���� ����
				gotoxy1(37, --bot_y1 + 1);  printf("  (              )");// �� Ʃ��//����
				color = rand() % 7 + 9;//  ���� ������
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//��� ���� ����
				gotoxy1(37, bot_y1 + 2);  printf("  (              )");// �� Ʃ�� ����Ʃ�� ����� 
				if (bot_tube != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//��� ���� ����
					gotoxy1(38, bot_y2 - 2); printf(" (");// ���� �ִ°�
					gotoxy1(42, bot_y2-- - 2); printf(")");// ���� �ִ°�
				}
				if (size == 8)// ���ڼ��� ���� ����  �ڸ����� ���� ��� ����
				{
					bot_y--;
					gotoxy1(39, bot_y); printf("%s", base_char_arr[bot_ran]); //gotoxy�� �̿��� Ʃ��ܾ� ���
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
					client();// �ٽý���
				}
				gotoxy1(28, 48);
			}
			/// ////////////////////////////////////////////////////////////////bot Ʃ�� ����
			if (cut == true) {//�������� Ŭ���̾�Ʈ�� ��ȣ �ð�� ����
				cut = false;
				player_score -= 10;
				gotoxy1(31, 2); printf("%d", player_score);// �ű� ���� ���� ���
				gotoxy1(16, 29 + player_tube++); printf("                                    ");
				player_tube_cnt--;
				gotoxy1(28, 48);
				if (player_tube_cnt == 0) {
					gotoxy1(28, 10); printf("Player   LOSE!");
					//rank_db();
					Sleep(3000);
					player_score = 0;
					system("cls");
					client();// �ٽý���
				}
				gotoxy1(28, 48);
			}
			/////////////////////////////////////////////////////
			char user[50] = { 0 };//���� �Է� ���� ����
			_beginthreadex(NULL, 0, (_beginthreadex_proc_type)user1, (void*)user, 0, NULL);
			for (int cnt = 0; cnt < 5; cnt++)
			{
				int ret = strcmp(user, base_char_arr[ran[cnt]]);// ��� �Ǿ� �ܾ� �� ������ Ȯ��
				int ret1 = strcmp(user, base_char_arr[bot_ran]); // ��� Ʃ�� �ȿ� �ִ� �ܾ� ������ Ȯ��
				if (ret1 == 0)// ��� �ܾ� ������ ����
				{
					send(sock, "c", 1, 0);//������ ��ȣ ����
					player_score += 10;//���� ����
					gotoxy1(31, 2); printf("%d", player_score);// �ű� ���� ���� ���
					gotoxy1(36, ++bot_y1); printf("                          ");//���Ʃ�� ����
					if (bot_tube != 1)
					{
						gotoxy1(38, bot_y2); printf(" (");// ���� �ִ°�
						gotoxy1(42, bot_y2++); printf(")");// ���� �ִ°�
					}

					bot_tube--;
					bot_y++;
					bot_ran = rand() % MAX_Arr;//������
					size = strlen(base_char_arr[bot_ran]);//������ ��
					if (bot_tube != 0)
					{
						bot_word(size, bot_ran, bot_y);//��� Ʃ�� �� ���
					}
					if (bot_tube == 0)//��� Ʃ�갡 0 �� �Ǹ� Player win
					{
						gotoxy1(28, 10); printf("Player   WIN!");
						Sleep(3000);//3�� �����
						system("cls");
						client();// �ٽý���
					}

					break;
					//////////////////////////////////////////////////////////////////////////////////////
				}
				size = 0;
				if (ret == 0)// �ؿ� �ܾ� �� ������ ���� 
				{
					send(sock, "u", 1, 0);//������ ��ȣ ����
					player_score += 10;//���� ����
					gotoxy1(31, 2); printf("%d", player_score);// �ű� ���� ���� ���
					ran[cnt] = rand() % MAX_Arr;
					size = strlen(base_char_arr[ran[cnt]]);//���ڼ� ���ϱ�
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
					int color = rand() % 7 + 9;//  ���� ������
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//��� ���� ����
					gotoxy1(x, y - player_tube_cnt++); printf("  (              )");// �÷��̾� Ʃ��player_tube_cnt;
					player_tube--;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					gotoxy1(28, 48);
					if (player_tube_cnt == 12)//player�� Ʃ�� 12�� ������� win
					{
						gotoxy1(28, 10); printf("Player   WIN!");
						Sleep(3000);
						system("cls");
						client();// �ٽý���
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
						client();// �ٽý���
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
	int x = 21; //Ÿ��Ʋȭ���� ǥ�õǴ� x��ǥ 
	int y = 4; //Ÿ��Ʋȭ���� ǥ�õǴ� y��ǥ 
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
	gotoxy(x - 1, y - 1); printf(" ����������������������������");
	gotoxy(x - 1, y + 1); printf(" ����������������������������");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); gotoxy(x + 1, y); printf(" ���� �����");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); gotoxy(x + 1, y + 2); printf("  ���� ����");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); gotoxy(x + 1, y + 4); printf(" �� �� �� ��");
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
			gotoxy(x - 1, y - 1); printf(" ����������������������������");
			gotoxy(x - 1, y + 1); printf(" ����������������������������");
		}
		else if (key == UP && check1 > 1)
		{
			check1--;
			y -= 2;
			gotoxy(x - 1, y + 3); printf("                ");
			gotoxy(x - 1, y - 1); printf(" ����������������������������");
			gotoxy(x - 1, y + 1); printf(" ����������������������������");
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
//	MYSQL* conn; //mysql ���� Ŀ�ؼ� �� �� ����ϴ� ����
//
//	const char* server = "127.0.0.1"; //���� ��� localhost = �ڱ� ��ǻ��
//	const char* user = "root";  //mysql ���̵�
//	const char* password = "root"; //mysql ���
//	const char* database = "project_GSM"; //�����ͺ��̽� �̸�
//	char query[255];  //SQL ���� ������ ���ڿ�
//	conn = mysql_init(NULL); //conn ���� �ʱ�... (1KB ����)


//���� : ������ ,����