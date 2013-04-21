#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<iostream.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.1415

// key codes
#define LEFT_1 44
#define RIGHT_1 45
#define POWERUP_1 17
#define POWERDOWN_1 16
#define ANGLEUP_1 31
#define ANGLEDOWN_1 30
#define FIRE_1 57

#define LEFT_2 49
#define RIGHT_2 50
#define POWERUP_2 72
#define POWERDOWN_2 80
#define ANGLEUP_2 77
#define ANGLEDOWN_2 75
#define FIRE_2 28
//

#define TRUE 1
#define FALSE 0

#define INCREMENT 1
#define DECREMENT 0

#define LEFT -1
#define RIGHT 1

// acceleration due to gravity
#define G 9.8
//

int gd=DETECT, gm, xmax, ymax, midx, midy;
int chance = 1;

// related to player vehicles
int x_rtyre_1, x_ltyre_1, x_rtyre_2, x_ltyre_2;
int x1_1, x2_1, x1_2, x2_2;
int mid_1, mid_2; // mid of the vehicles
//

// related to weapons
int x1_w1, y1_w1, x1_w2, y1_w2, length_weapon = 15;
int y_down, y_up;// up & down y-coordinates of vehicles
//

int score_1 = 0, score_2 = 0;
int angle_1 = -45, angle_2 = -135;
int velocity_1 = 2, velocity_2 = 2;

int x_power1 = 7, x_power2 = 337;
char *score = "100";

int player1_chance, player2_chance;

void draw_border(int pattern=1, int color=3) {

  setfillstyle(pattern, color);

	bar(0, 100, xmax, 105);//up
	bar(0, 100, 5, ymax);//left
	bar(xmax-5, ymax, xmax, 100);//right
	bar(0, ymax-5, xmax, ymax);//bottom

	bar(midx-3, 0, midx+3, 100);//partition
}

int inlimit_1(int xpos_l, int xpos_r, int direction) {

	if(direction == LEFT) {

		if((xpos_l-6) > 0)
			return TRUE;
		else
			return FALSE;
	}

	else {

		if((xpos_r+6) < (midx-155))
			return TRUE;
		else
			return FALSE;
	}
}

int inlimit_2(int xpos_l, int xpos_r, int direction) {

	if(direction == LEFT) {

		if((xpos_l-6) > (midx+156))
			return TRUE;
		else
			return FALSE;
	}

	else {

		if((xpos_r+6) < xmax)
			return TRUE;
		else
			return FALSE;
	}
}

void weapon_1(int pos_disp=0, int angle_disp=0) {

	setcolor(BLACK);
	line(x1_w1, y_up, x1_w1 + length_weapon*cos(angle_1*PI/180), y_up + length_weapon*sin(angle_1*PI/180));

	angle_1 = (angle_1 + angle_disp) % 360;
	x1_w1 += pos_disp;

	setcolor(YELLOW);
	line(x1_w1, y_up, x1_w1 + length_weapon*cos(angle_1*PI/180), y_up + length_weapon*sin(angle_1*PI/180));
}

void weapon_2(int pos_disp=0, int angle_disp=0) {

	setcolor(BLACK);
	line(x1_w2, y_up, x1_w2 + length_weapon*cos(angle_2*PI/180), y_up + length_weapon*sin(angle_2*PI/180));

	angle_2 = (angle_2 + angle_disp) % 360;
	x1_w2 += pos_disp;

	setcolor(LIGHTBLUE);
	line(x1_w2, y_up, x1_w2+ length_weapon*cos(angle_2*PI/180), y_up + length_weapon*sin(angle_2*PI/180));
}

void player_1(int direction, int disp = 0) {

	setfillstyle(7, BLACK);
	bar(xmax-70, 25, xmax-5, 30);
	setfillstyle(7, CYAN);
	bar(10, 25, 75, 30);

	if(inlimit_1(x1_1, x_rtyre_1, direction)) {

		setcolor(BLACK);
		line(x1_1 + 17, y_up, x1_1 + 17, y_down);
		line(x1_1 + 23, y_up, x1_1 + 23, y_down);

		line(x1_1 + 10, y_up, x1_1 + 10, y_down);
		line(x1_1 + 30, y_up, x1_1 + 30, y_down);

		rectangle(x1_1, y_up, x2_1, y_down);//body of vehicle
		circle(x_ltyre_1, midy + 228, 5);//left tyre
		circle(x_rtyre_1, midy + 228, 5);//right tyre

		x_rtyre_1 += disp;    x_ltyre_1 += disp;
		x1_1 += disp;    x2_1 += disp;
		mid_1 = (x1_1 + x2_1)/2;

		setcolor(LIGHTGREEN);
		line(x1_1 + 17, y_up, x1_1 + 17, y_down);
		line(x1_1 + 23, y_up, x1_1 + 23, y_down);

		setcolor(BROWN);
		line(x1_1 + 10, y_up, x1_1 + 10, y_down);
		line(x1_1 + 30, y_up, x1_1 + 30, y_down);

		setcolor(YELLOW);
		rectangle(x1_1, y_up, x2_1, y_down);//body of vehicle
		circle(x_ltyre_1, midy+228, 5);//left tyre
		circle(x_rtyre_1, midy+228, 5);//right tyre*/
		setcolor(GREEN);

		weapon_1(disp, 0);
	}
}

void player_2(int direction, int disp = 0) {

	setfillstyle(7, BLACK);
	bar(10, 25, 75, 30);
	setfillstyle(7, CYAN);
	bar(xmax-70, 25, xmax-5, 30);

	if(inlimit_2(x_ltyre_2, x1_2, direction)) {

		setcolor(BLACK);
		line(x2_2 + 17, y_up, x2_2 + 17, y_down);
		line(x2_2 + 23, y_up, x2_2 + 23, y_down);
		line(x2_2 + 10, y_up, x2_2 + 10, y_down);
		line(x2_2 + 30, y_up, x2_2 + 30, y_down);

		rectangle(x1_2, y_up, x2_2, y_down);//body of vehicle
		circle(x_ltyre_2, midy+228, 5);//left tyre
		circle(x_rtyre_2, midy+228, 5);//right tyre

		x_rtyre_2 += disp;    x_ltyre_2 += disp;
		x1_2 += disp;    x2_2 += disp;
		mid_2 = (x1_2 + x2_2)/2;

		setcolor(LIGHTGREEN);
		line(x2_2 + 17, y_up, x2_2 + 17, y_down);
		line(x2_2 + 23, y_up, x2_2 + 23, y_down);

		setcolor(BROWN);
		line(x2_2 + 10, y_up, x2_2 + 10, y_down);
		line(x2_2 + 30, y_up, x2_2 + 30, y_down);

		setcolor(LIGHTBLUE);
		rectangle(x1_2, y_up, x2_2, y_down);//body of vehicle
		circle(x_ltyre_2, midy+228, 5);//left tyre
		circle(x_rtyre_2, midy+228, 5);//right tyre

		weapon_2(disp, 0);
	}
}

void limits() {

	setfillstyle(1, RED);

	bar(midx - 155, ymax - 10, midx - 145, ymax - 5);//left
	bar(midx + 155, ymax - 10, midx + 145, ymax - 5);//right
}

void disp_scores() {

	char *score, *text;

	setcolor(CYAN);
	sprintf(score, "Score : %d",score_1);
	outtextxy(midx-100, 10, score);

	sprintf(score, "Score : %d",score_2);
	outtextxy(midx+30, 10, score);
}

void score1(int x_coor) {

	int flag = 0;
	int s;

	setcolor(BLACK);
	sprintf(score, "Score : %d",score_1);
	outtextxy(midx-100, 10, score);

	if((x_coor >= (x2_2+17)) && (x_coor <= (x2_2+23))) {

		s = 100;
		flag = 1;
	}

	else if((x_coor >= (x2_2+10)) && (x_coor <= (x2_2+30))) {

		s = 50;
		flag = 1;
	}

	else if((x_coor >= (x2_2)) && (x_coor <= (x1_2))) {

		s = 25;
		flag = 1;
	}

	if(flag == 1) {

		sprintf(score, "%d", s);
		setcolor(YELLOW);
		outtextxy(x_coor, ymax-75, score);

		score_1 += s;
	}

	disp_scores();
}

void score2(int x_coor) {

	int flag = 0;
	int s;

	setcolor(BLACK);
	sprintf(score, "Score : %d",score_2);
	outtextxy(midx+30, 10, score);

	if((x_coor >= (x1_1+17)) && (x_coor <= (x1_1+23))) {

		s = 100;
		flag = 1;
	}

	else if((x_coor >= (x1_1+10)) && (x_coor <= (x1_1+30))) {

		s = 50;
		flag = 1;
	}

	else if((x_coor >= (x1_1)) && (x_coor <= (x2_1))) {

		s = 25;
		flag = 1;
	}

	if(flag == 1) {

		sprintf(score, "%d", s);
		setcolor(YELLOW);
		outtextxy(x_coor, ymax-75, score);

		score_2 += s;
	}

	disp_scores();
}

void fire1() {

	angle_1 = -angle_1;
	int x1 = x1_w1 + length_weapon * cos(angle_1 * PI/180);
	int y1 = y_up + length_weapon * sin(angle_1 * PI/180)-22;

	int y2 = 0, x2 = 0;
	int range;
	float b, c;

	range = (velocity_1 * velocity_1) / G;
	b = tan(angle_1 * PI/180);
	c = G / (2 * velocity_1 * velocity_1 * cos(angle_1*PI/180) * cos(angle_1*PI/180));

	setcolor(YELLOW);
	circle(x1, y1, 4);

	for(int i=0 ; i<=(range+8) && (y1-y2) < (midy + 198) && (x1+x2) < (xmax-9); i++) {

		setcolor(BLACK);
		circle(x1 + x2, y1 - y2, 4);

		x2 = i;
		y2 = b * x2 - c * x2 * x2;

		setcolor(YELLOW);
		circle(x1 + x2, y1 - y2, 4);
		delay(5);
	}

	score1(x1+x2);

	delay(1000);
	setcolor(BLACK);
	outtextxy(x1+x2, ymax-75, score);
	circle(x1 + x2, y1 - y2, 4);
	player1_chance = FALSE;
	player2_chance = TRUE;
	angle_1 = -angle_1;
	player_1(LEFT);
	player_2(LEFT);
}

void fire2() {

	int x1 = x1_w2 + length_weapon * cos(angle_2 * PI/180);
	int y1 = y_up + length_weapon * sin(angle_2 * PI/180);

	int y2 = 0, x2 = 0;
	int range;
	float b, c;

	range = (velocity_2 * velocity_2) / G;
	b = tan(angle_2 * PI/180);
	c = G / (2 * velocity_2 * velocity_2 * cos(angle_2*PI/180) * cos(angle_2*PI/180));

	setcolor(LIGHTBLUE);
	circle(x1, y1, 4);

	for(int i=0 ; i<=(range+7) && ((y1-y2) < (midy+198)) && (x1-x2) > 10; i++) {

		setcolor(BLACK);
		circle(x1 - x2, y1 - y2, 4);

		x2 = i;
		y2 = b * x2 - c * x2 * x2;

		setcolor(LIGHTBLUE);
		circle(x1 - x2, y1 - y2, 4);
		delay(5);
	}

	score2(x1-x2);

	delay(1000);
	setcolor(BLACK);
	outtextxy(x1-x2, ymax-75, score);
	circle(x1 - x2, y1 - y2, 4);
	player_2(LEFT);
	player_1(LEFT);
	player2_chance = FALSE;
	player1_chance = TRUE;
}

void power1(int action) {

	setcolor(YELLOW);
	rectangle(10, 75, 300, 90);

	if(action == INCREMENT) {

		if(x_power1 < 295) {

			setfillstyle(1, RED);

			x_power1 += 6;
			bar(x_power1, 76, x_power1+3, 89);
		}
	}

	else {

		if(x_power1 > 7) {

			setfillstyle(1, BLACK);

			bar(x_power1, 76, x_power1+3, 89);
			x_power1 -= 6;
		}
	}
}

void power2(int action) {

	setcolor(LIGHTBLUE);
	rectangle(340, 75, 630, 90);

	if(action == INCREMENT) {

		if(x_power2 < 625) {

			setfillstyle(1, RED);

			x_power2 += 6;
			bar(x_power2, 76, x_power2+3, 89);
		}
	}

	else {

		if(x_power2 > 337) {

			setfillstyle(1, BLACK);

			bar(x_power2, 76, x_power2+3, 89);
			x_power2 -= 6;
		}
	}
}

void modify_power_1(int action) {

	if(action == INCREMENT) {

		velocity_1 += 2;
		power1(INCREMENT);
	}

	else {

		velocity_1 -= 2;
		power1(DECREMENT);
	}
}

void modify_power_2(int action) {

	if(action == INCREMENT) {

		velocity_2 += 2;
		power2(INCREMENT);
	}

	else {

		velocity_2 -= 2;
		power2(DECREMENT);
	}
}

void waitRetrace()
{
	_DX = 0x03DA;

	l1: asm {
			in al,dx;
			and al,0x08;
			jnz l1;
	}

	l2: asm {
			in al,dx;
			and al,0x08;
			jz l2;
	}
}

void credits() {

	cleardevice();

	char * text1 = "Created by :-";//y
	char * name = "SUJAL WATTAMWAR";//y1
	char * _class = "T.E. C.S.E";//y2
	char *roll = "Roll No. : 33";//y3
	char *college = "Walchand College of Engineering";//y4
	char * place = "Sangli";//y5

	settextstyle(10, 0, 1);

	for(int y=ymax, y1=y+100, y2=y1+50, y3=y2+50, y4=y3+50, y5=y4+50; y5>-50 ; y-=3, y1-=3, y2-=3, y3-=3, y4-=3, y5-=3) {

		if(kbhit())
			exit(0);

		waitRetrace();
		cleardevice();

		setcolor(RED);
		outtextxy(midx-textwidth(text1)/2-150, y, text1);
		setcolor(YELLOW);
		outtextxy(midx-textwidth(name)/2, y1, name);
		outtextxy(midx-textwidth(_class)/2, y2, _class);
		outtextxy(midx-textwidth(roll)/2, y3, roll);
		outtextxy(midx-textwidth(college)/2, y4, college);
		outtextxy(midx-textwidth(place)/2, y5, place);

		delay(20);
	}

	exit(0);
}

void exit() {

	cleardevice();

	//border
	setfillstyle(8, RED);
	bar(0, 0, xmax, ymax);
	setfillstyle(8, BLACK);
	bar(20, 20, xmax-20, ymax-20);
	//

	// face left
	setcolor(YELLOW);
	circle(midx - 140, midy, 50);// face
	circle(midx - 160, midy - 10, 5);// eye left
	circle(midx - 120, midy - 10, 5);// eye right
	// nose
	line(midx-140, midy-10, midx-140, midy+10);
	line(midx-140, midy+10, midx-135, midy+10);
	//
	//

	// face right
	setcolor(LIGHTBLUE);
	circle(midx + 140, midy, 50);// face
	circle(midx + 160, midy - 10, 5);// eye left
	circle(midx + 120, midy - 10, 5);// eye right
	//nose
	line(midx+140, midy-10, midx+140, midy+10);
	line(midx+140, midy+10, midx+145, midy+10);
	//
	//

	settextstyle(10, 0, 1);

	if(score_1 > score_2) {

		setcolor(LIGHTBLUE);
		ellipse(midx + 140, midy + 35, 0, 180, 20, 15);// sad mouth 2
		outtextxy(midx + 140 - textwidth("LOSER")/2, midy+70, "LOSER");

		setcolor(YELLOW);
		ellipse(midx - 140, midy + 17, 180, 360, 20, 15);// smily mouth 1
		outtextxy(midx - 140 - textwidth("WINNER")/2, midy+70, "WINNER");
	}

	else if(score_1 < score_2) {

		setcolor(YELLOW);
		ellipse(midx - 140, midy + 35, 0, 180, 20, 15);// sad mouth 1
		outtextxy(midx - 140 - textwidth("LOSER")/2, midy+70, "LOSER");

		setcolor(LIGHTBLUE);
		ellipse(midx + 140, midy + 17, 180, 360, 20, 15);// smily mouth 2
		outtextxy(midx + 140 - textwidth("WINNER")/2, midy+70, "WINNER");
	}

	else {

		setcolor(YELLOW);
		line(midx - 160, midy + 25, midx - 120, midy + 25);

		setcolor(LIGHTBLUE);
		line(midx + 120, midy + 25, midx + 160, midy + 25);

		setcolor(CYAN);
		outtextxy(midx - textwidth("TIE")/2, midy + 100, "TIE");
	}
	//

	getch();
	credits();
}

void play() {

	char ch;
	int key;

	while(1) {

		while(player1_chance) {

			ch = getch();
			key = inportb(0x60);

			if(key == 1)
				exit();

			else if(key == RIGHT_1)
				player_1(RIGHT, 1);

			else if(key == LEFT_1)
				player_1(LEFT, -1);

			else if(key == ANGLEUP_1)
				weapon_1(0, 1);

			else if(key == ANGLEDOWN_1)
				weapon_1(0, -1);

			else if(key == FIRE_1)
				fire1();

			else if(key == POWERUP_1)
				modify_power_1(INCREMENT);

			else if(key == POWERDOWN_1)
				modify_power_1(DECREMENT);

			else
				printf("\a");
		}

		while(player2_chance) {

			ch = getch();
			key = inportb(0x60);

			if(key == 1)
				exit();

			else if(key == RIGHT_2)
				player_2(RIGHT, 1);

			else if(key == LEFT_2)
				player_2(LEFT, -1);

			else if(key == ANGLEUP_2)
				weapon_2(0, 1);

			else if(key == ANGLEDOWN_2)
				weapon_2(0, -1);

			else if(key == FIRE_2)
				fire2();

			else if(key == POWERUP_2)
				modify_power_2(INCREMENT);

			else if(key == POWERDOWN_2)
				modify_power_2(DECREMENT);

			else
				printf("\a");
		}
	}
}

void disp_names() {

	settextstyle(0, 0, 1);

	setcolor(YELLOW);
	outtextxy(10, 10, "Player 1");

	setcolor(LIGHTBLUE);
	outtextxy(xmax-70, 10, "Player 2");
}

void game_info() {

	cleardevice();

	char *game_name = "= P O C K E T    T A N K =";
	settextstyle(10, 0, 3);

	// border
	setfillstyle(7, BROWN);
	bar(0, 0, xmax, ymax);
	setfillstyle(7, BLACK);
	bar(50, 50, xmax-65, ymax-50);
	//

	// border of game name
	setfillstyle(7, RED);
	bar(midx-textwidth(game_name)/2-8, 65, xmax-74, 150);
	setfillstyle(7, BLACK);
	bar(midx-textwidth(game_name)/2-5, 71, xmax-77, 144);
	//

	//game name
	setcolor(LIGHTMAGENTA);
	settextstyle(10, 0, 3);
	outtextxy(midx-textwidth(game_name)/2, 80, game_name);
	//

	// game controls
	char *text1 = "Game Controls";
	settextstyle(7, 0, 2);
	setcolor(LIGHTBLUE);
	outtextxy(midx-textwidth(text1)/2, 170, text1);

	//underline
	setlinestyle(1, 1, 1);
	line(midx-textwidth(text1)/2, 200, midx+textwidth(text1)/2, 200);
	//

	char *name1 = "Player 1", *name2 = "Player 2";
	char *left1 = "left : z", *left2 = "left : n";
	char *right1 = "right : x", *right2 = "right : m";
	char *adown1 = "angle down : a", *adown2 = "angle down : <-";
	char *aup1 = "angle up : s", *aup2 = "angle up : ->";
	char *pdown1 = "power down : q", *pdown2 = "power down : down";
	char *pup1 = "power up : w", *pup2 = "power up : up";
	char *exit = "exit : esc";

	//setcolor(BLUE);
	settextstyle(1, 0, 1);

	outtextxy(midx-250, 200, name1);
	line(midx-250, 230, midx-250+textwidth(name1), 230);
	outtextxy(midx+153, 200, name2);
	line(midx+153, 230, midx+153+textwidth(name2), 230);

	setcolor(BLUE);
	outtextxy(midx-250, 240, left1);
	outtextxy(midx+75, 240, left2);
	outtextxy(midx-250, 260, right1);
	outtextxy(midx+75, 260, right2);
	outtextxy(midx-250, 280, adown1);
	outtextxy(midx+75, 280, adown2);
	outtextxy(midx-250, 300, aup1);
	outtextxy(midx+75, 300, aup2);
	outtextxy(midx-250, 320, pdown1);
	outtextxy(midx+75, 320, pdown2);
	outtextxy(midx-250, 340, pup1);
	outtextxy(midx+75, 340, pup2);
	outtextxy(midx-textwidth(exit)/2, 370, exit);
	//

	getch();
	cleardevice();
	setlinestyle(0, 0, 0);
}

void main() {

	initgraph(&gd, &gm, "");
	xmax = getmaxx();	ymax = getmaxy();
	midx = xmax/2;		midy = ymax/2;

	game_info();

	draw_border(8, CYAN);

	//initialisation of the positions of players
	x_rtyre_1 = midx - 240;	x_ltyre_1 = midx - 260;
	x_ltyre_2 = midx + 240;	x_rtyre_2 = midx + 260;

	x1_1 = midx - 270;	x2_1 = midx - 230;
	x1_2 = midx + 270;	x2_2 = midx + 230;

	x1_w1 = midx-230;	x1_w2 = midx+230;

	y_up = midy + 203;
	y_down = midy + 223;
	//

	player_2(RIGHT);
	player_1(RIGHT);
	weapon_1(0, 0);
	weapon_2(0, 0);
	power1(INCREMENT);
	power2(INCREMENT);
	limits();

	disp_names();
	disp_scores();

	player1_chance = TRUE;
	player2_chance = FALSE;
	play();

	getch();
	closegraph();
}
