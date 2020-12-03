//1.背景图像，人物图像，怪兽图像等铺设
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#pragma comment(lib, "Winmm.lib")
#pragma comment(lib, "MSIMG32.LIB") //实现透明贴图

//定义全局变量
#define pictureWidth 8022 //背景图片宽度
#define pictureHigh 525   //背景图片高度
#define Width 1024		  //画面宽度
#define High 525		  //画面高度
#define roleWidth 39	  //人物宽度
#define roleHigh 65		  //人物高度
#define EnemyWidth 39	 //怪兽宽度
#define EnemyWidth 39	 //怪兽高度

//函数声明
//邵帅：

void show();													   //显示画面            邵帅 边洲峰 刘墉江
void updateWithoutInput();										   //与输入无关的更新	 邵帅 边洲峰 刘墉江
void updateWithInput();											   //与输入有关的更新	 邵帅 边洲峰 刘墉江
void RoleWalk(int left, int right, int judge);					   //人物行走            邵帅 刘墉江
void transparentimage(IMAGE *dstimg, int x, int y, IMAGE *srcimg); //实现透明贴图        来自互联网
void endwalk(int zs, int jd);									   //通关后的动画        边洲峰
int iscontinue();												   //判断是否继续        边洲峰
void printtxt(int x, int y, int value);							   //屏幕上打印文字      边洲峰
int startmenu();												   //开始界面            边洲峰
void ksdz(int stepi, int stepj);								   //开始界面的动作      边洲峰
void startup();													   //数据初始化          刘墉江
void roleGD(int judge);											   //进入管道的动画      刘墉江
void roleDeath(void);											   //人物死亡动画        刘墉江
void qbmd();													   //进入制作人员名单    邵帅
void thanks();													   //感谢画面            邵帅

//各种参数定义
int role_x, role_y;		   //人物画布坐标
int real_x, real_y;		   //人物实际坐标
int speed_x, speed_y;	  //人物速度
int step_left, step_right; //人物行走脚步
int moveDeriction;		   //人物行走判断1向左走，2向右走
int enemyFlour;			   //怪兽在地面高度
int enemySpeed;			   //怪物移动速度
int sfkt;				   //人物在空中时是否可跳
int fflag;				   //是否拿到旗

int judgeOperate;										  //人物是否可操作 0表示否 1表示能
int bk_x, bk_y;											  //背景图片绘制坐标
int flag_x, flag_y;										  //旗的坐标
int judgeJump;											  //判断是否跳跃 0在地面，1为向上，2为向下
int flour;												  //地面高度
int jumpHigh, jumpHighTop, jumpEnemyHigh, judgeEnemyJump; //人物跳跃限制,记录跳跃高度，跳跃最大高度,踩怪后反弹高度,判断是踩怪反弹还是普通起跳0为普通，1为踩怪
int ksjm_x, ksjm_y;										  //开始界面图片坐标
int jx_x, jx_y;											  //继续界面的坐标

int ch = 1;   //判断能否继续游戏 0为死亡
int role;	 //判断人物死亡
int time;	 //游戏剩余时间
int usedtime; //已用时间
char stime[50];
char sudtime[50];
int con;		//判断是否继续的参数
int EXIT;		//判断是否为exit 退出为0
int fs;			//分数
int xscore[10]; //分数数组，用于排名
int cs = 0, pm; //用于次数，排名
int count[8] = {0};
int lyj_x, lyj_y, bzf_x, bzf_y, ss_x, ss_y; //制作人员名单位置

int judgekd;				   //坑地下落判断1正常，0下落
int map;					   //地图判断0代表初始地图，1代表隐藏地图
int hmtk1_l, hmtk1_r, hmtk_GD; //画面调控。控制人物行走时图片出现的速度，减少鬼畜1为人物，2为怪物
int judgeGD;				   //判断是否进入管道，0为否，1为1号管道，4为人物死亡

IMAGE img_ksjm;																																																 //开始界面
IMAGE img_gz;																																																 //规则图片
IMAGE img_bk, img_flag, img_bk2;																																											 //背景画面 旗
IMAGE img_ty;																																																 //跳跃图片
IMAGE img_jx;																																																 //是否继续图片
IMAGE img_role1r, img_role2r, img_role3r, img_role4r, img_role5r, img_role6r, img_role7r, img_role8r, img_role9r, img_role10r;																				 //人物图片  向右
IMAGE img_role1l, img_role2l, img_role3l, img_role4l, img_role5l, img_role6l, img_role7l, img_role8l, img_role9l, img_role10l;																				 //人物图片  向向左
IMAGE img_block;																																															 //砖块图片
IMAGE img_end1, img_end2, img_end3, img_end4, img_end5, img_end6, img_end7, img_end8, img_end9, img_end10;																									 //通关画面
IMAGE img_end11, img_end12, img_end13, img_end14, img_end15, img_end16, img_end17, img_end18, img_end19, img_end20;																							 //通关画面
IMAGE img_end21, img_end22, img_end23, img_end24, img_end25, img_end26, img_end27, img_end28, img_end29, img_end30;																							 //通关画面
IMAGE img_dead, img_enemyl1, img_enemyl2, img_enemyr1, img_enemyr2;																																			 //怪兽图片
IMAGE img_jb, img_jb2;																																														 //金币图片
IMAGE img_roleDown1, img_roleDown2, img_roleDown3, img_roleDown4, img_roleDown5, img_roleDown6, img_roleDown7, img_roleDown8, img_roleDown9, img_roleDown10, img_roleDown11, img_roleDown12, img_roleDown13; //人物进入管道的画面 向下
IMAGE img_roleR1, img_roleR2, img_roleR3, img_roleR4, img_roleR5, img_roleR6, img_roleR7, img_roleR8, img_roleR9, img_roleR10, img_roleR11, img_roleR12, img_roleR13;										 //人物进入管道的画面 向右
IMAGE img_role_Death1, img_role_Death2, img_role_Death3, img_role_Death4, img_role_Death5, img_role_Death6, img_role_Death7;																				 //人物死亡图片
IMAGE img_lyj, img_bzf, img_ss;																																												 //制作人员名单图片
IMAGE img_thanks;																																															 //感谢图片
IMAGE img_pause;																																															 //暂停图片

struct kd //坑洞位置坐标
{
	int start_x, end_x;
};
kd KD[3];

struct zc //管道位置坐标
{
	int start_x, end_x;
	int zc_high;
};
zc GD[6];
zc BKPH[26]; //不可破坏砖块
zc ycmap[2]; //隐藏地图

struct sky //空中物体位置坐标
{
	int start_x, end_x;  //左右坐标
	int top_y, button_y; //上下坐标
	int judge;			 //是否被破坏
};
sky ZK[28]; //普通可破坏砖块
sky BX[12]; //撞击可获得分数的砖块

struct enemy //怪物相关数据
{
	int start_x, end_x; //左右坐标
	int xdfw, xdjl;		//怪兽行动范围,记录怪物的行动距离
	int judge;			//是否被破坏1为否，0为是
	int enemywalk;		//怪物行走方向1为左，-1为右
	int left, right;	//怪物行走左右判断
	int hmtk_l, hmtk_r; //画面调控，控制怪物图片的输出
};
enemy GS[7]; //怪兽数量

struct yc //隐藏地图相关数据
{
	int start_x, end_x;  //左右坐标
	int top_y, button_y; //上下坐标
	int judge;			 //是否被破坏
};
yc YC[19]; //隐藏关卡金币

void printtxt(int x, int y, int value) //屏幕上打印文字
{
	char str[50];					 //建立字符串数组存储数字
	settextcolor(YELLOW);			 //文字颜色
	settextstyle(40, 0, "华文琥珀"); //字体颜色和字体样式
	sprintf_s(str, "%d", value);	 //数字转化成字符串
	outtextxy(x, y, str);			 //输出
}
void printscore(int x, int y) //屏幕打印“score”
{
	char str[50] = "score =";
	settextcolor(YELLOW);
	settextstyle(40, 0, "华文琥珀");
	outtextxy(x, y, str);
}

int startmenu() //开始界面
{
	role_x = 160;
	role_y = 390;
	initgraph(Width, High);
	int flag = 1;
	int ltime = 0;
	while (1)
	{
		BeginBatchDraw();
		putimage(ksjm_x, ksjm_y, &img_ksjm);				 //导入人物图片
		transparentimage(NULL, role_x, role_y, &img_role1r); //输出图像
		if (ltime == 200)									 //马里奥无聊时的动画 两秒
		{
			while (role_x > 50)
			{
				putimage(ksjm_x, ksjm_y, &img_ksjm);
				moveDeriction = 1;
				role_x -= speed_x;
				step_left++;
				RoleWalk(step_left % 10, step_right, moveDeriction);
				FlushBatchDraw();
				Sleep(20);
				cleardevice();
			}
			Sleep(100);
			while (role_x < 160)
			{
				putimage(ksjm_x, ksjm_y, &img_ksjm);
				moveDeriction = 2;
				role_x += speed_x;
				step_right++;
				RoleWalk(step_left, step_right % 10, moveDeriction);
				FlushBatchDraw();
				Sleep(20);
				cleardevice();
			}
			while (role_y > 250)
			{
				putimage(ksjm_x, ksjm_y, &img_ksjm);
				moveDeriction = 3;
				role_y -= speed_y * 2;
				RoleWalk(step_left, step_right % 10, moveDeriction);
				FlushBatchDraw();
				Sleep(20);
				cleardevice();
			}
			mciSendString("close jpmusic", NULL, 0, NULL);
			mciSendString("open Music\\跳跃.mp3 alias jpmusic", NULL, 0, NULL);
			mciSendString("play jpmusic", NULL, 0, NULL); //仅播放一次音乐
			moveDeriction = 2;
			Sleep(200);
			while (role_y < 390)
			{
				putimage(ksjm_x, ksjm_y, &img_ksjm);
				moveDeriction = 3;
				role_y += speed_y * 2;
				RoleWalk(step_left, step_right % 10, moveDeriction);
				FlushBatchDraw();
				Sleep(20);
				cleardevice();
			}
			putimage(ksjm_x, ksjm_y, &img_ksjm);
			role_x = 160;
			role_y = 390;
			ltime = 0;
		}
		if (GetAsyncKeyState(0x31) & 0x8000)
		{ //开始游戏
			ksdz(339, 291);
			break;
		}
		else if (GetAsyncKeyState(0x32) & 0x8000)
		{ //游戏规则
			ksdz(400, 333);
			putimage(ksjm_x, ksjm_y, &img_gz);
			FlushBatchDraw(); //输出规则图片
			while (!(GetAsyncKeyState(0x1B) & 0x8000))
				; //询问是否退出（判断）
			role_x = 160;
			role_y = 390;
		}
		else if (GetAsyncKeyState(0x33) & 0x8000)
		{ //退出
			ksdz(467, 371);
			mciSendString("close bkmusic", NULL, 0, NULL);
			Sleep(100);
			mciSendString("open Music\\exit.mp3 alias exitmusic", NULL, 0, NULL);
			mciSendString("play exitmusic", NULL, 0, NULL); //仅播放一次音乐
			Sleep(4000);
			flag = 0;
			break;
		}
		Sleep(10);
		ltime++;
		FlushBatchDraw();
	}

	Sleep(100);
	role_x = 100; //人物坐标
	role_y = 415;
	return flag;
}
void ksdz(int stepi, int stepj) //开始界面的动作
{
	while (role_x < stepi) //向右走
	{
		putimage(ksjm_x, ksjm_y, &img_ksjm);

		moveDeriction = 2;
		role_x += speed_x;
		step_right++;
		RoleWalk(step_left, step_right % 10, moveDeriction);
		FlushBatchDraw();
		Sleep(10);
		cleardevice();
	}
	//左顾右盼
	putimage(ksjm_x, ksjm_y, &img_ksjm);
	transparentimage(NULL, role_x, role_y, &img_role2r);
	FlushBatchDraw();
	Sleep(200);
	transparentimage(NULL, role_x, role_y, &img_role2l);
	FlushBatchDraw();
	Sleep(200);
	transparentimage(NULL, role_x, role_y, &img_role2r);
	FlushBatchDraw();
	Sleep(500);
	cleardevice();
	while (role_y > stepj) //跳到标题
	{
		putimage(ksjm_x, ksjm_y, &img_ksjm);

		moveDeriction = 3;
		role_y -= speed_y * 2;
		RoleWalk(step_left, step_right % 10, moveDeriction);
		FlushBatchDraw();
		Sleep(10);
		cleardevice();
	}
	mciSendString("close jpmusic", NULL, 0, NULL);
	mciSendString("open Music\\跳跃.mp3 alias jpmusic", NULL, 0, NULL);
	mciSendString("play jpmusic", NULL, 0, NULL); //仅播放一次音乐
	moveDeriction = 2;
	Sleep(200);
}
void startup() //数据初始化
{
	role_x = 100; //人物坐标
	role_y = 415;
	real_x = 100; //人物实际坐标
	real_y = 415;
	flour = 415;   //地面高度
	speed_x = 5;   // 人物前进速度
	speed_y = 7;   //人物跳跃的速度
	step_left = 0; //人物行走图片循环
	step_right = 0;
	moveDeriction = 2; //人物行走判断
	judgeOperate = 1;  //人物初始可以行走
	bk_x = 0;		   //背景绘制坐标
	bk_y = 0;
	flag_x = 1024; //旗的坐标
	flag_y = 95;
	ksjm_x = 0; //开始界面的坐标
	ksjm_y = 0;
	jx_x = 0;					 //继续界面的横坐标
	jx_y = 0;					 //继续界面的纵坐标
	judgeJump = 0;				 //判断是否跳跃 0表示否，1表示是
	jumpHigh = 0;				 //人物跳跃高度为0
	jumpHighTop = High / 2 - 70; //人物跳跃极限高度
	jumpEnemyHigh = High / 6;	//踩怪后反弹最大高度
	judgeEnemyJump = 0;			 //是否踩怪判断，0为普通
	sfkt = 0;					 //判断人物在空中时可否起跳0代表否，1代表能
	judgekd = 1;				 //坑底下落判断1为正常，0为下落
	map = 0;					 //地图初始化为初始地图
	hmtk1_l = 0;				 //画面调控初始化为0
	hmtk1_r = 0;				 //人物行走的画面调控
	judgeGD = 0;				 //判断是否进入管道
	hmtk_GD = 0;				 //调控进入管道的画面
	enemyFlour = 434;			 //怪物高度
	enemySpeed = 1;				 //怪物移动速度
	time = 100;					 //初始化时间
	usedtime = 0;				 //初始化已用时间
	fs = 0;						 //分数初始化
	fflag = 1;					 //初始化
	ch = 1;						 //开始的初始化
	role = 1;					 //人物状态
	lyj_x = 250;				 //初始化制作人员名单
	lyj_y = 45;					 //初始化制作人员名单
	bzf_x = 250;				 //初始化制作人员名单
	bzf_y = 600;				 //初始化制作人员名单
	ss_x = 250;					 //初始化制作人员名单
	ss_y = 750;					 //初始化制作人员名单
	//以下为大量场景坐标数据初始化
	KD[0].start_x = 2610; //空地坐标初始化
	KD[0].end_x = 2686;

	KD[1].start_x = 3255;
	KD[1].end_x = 3367;

	KD[2].start_x = 5790;
	KD[2].end_x = 5863;

	GD[0].start_x = 1062; //管道坐标初始化
	GD[0].end_x = 1135;
	GD[0].zc_high = 410;

	GD[1].start_x = 1438;
	GD[1].end_x = 1511;
	GD[1].zc_high = 370;

	GD[2].start_x = 1743;
	GD[2].end_x = 1811;
	GD[2].zc_high = 334;

	GD[3].start_x = 2160;
	GD[3].end_x = 2228;
	GD[3].zc_high = 334;

	GD[4].start_x = 6173;
	GD[4].end_x = 6240;
	GD[4].zc_high = 410;

	GD[5].start_x = 6777;
	GD[5].end_x = 6845;
	GD[5].zc_high = 410;

	BKPH[0].start_x = 5069; //不可破坏的砖块初始化
	BKPH[0].end_x = 5107;
	BKPH[0].zc_high = 434;

	BKPH[1].start_x = 5107;
	BKPH[1].end_x = 5146;
	BKPH[1].zc_high = 396;

	BKPH[2].start_x = 5146;
	BKPH[2].end_x = 5183;
	BKPH[2].zc_high = 359;

	BKPH[3].start_x = 5183;
	BKPH[3].end_x = 5222;
	BKPH[3].zc_high = 321;

	BKPH[4].start_x = 5297;
	BKPH[4].end_x = 5336;
	BKPH[4].zc_high = 321;

	BKPH[5].start_x = 5336;
	BKPH[5].end_x = 5373;
	BKPH[5].zc_high = 359;

	BKPH[6].start_x = 5373;
	BKPH[6].end_x = 5411;
	BKPH[6].zc_high = 396;

	BKPH[7].start_x = 5411;
	BKPH[7].end_x = 5449;
	BKPH[7].zc_high = 434;

	BKPH[8].start_x = 5599;
	BKPH[8].end_x = 5637;
	BKPH[8].zc_high = 434;

	BKPH[9].start_x = 5637;
	BKPH[9].end_x = 5676;
	BKPH[9].zc_high = 396;

	BKPH[10].start_x = 5676;
	BKPH[10].end_x = 5713;
	BKPH[10].zc_high = 359;

	BKPH[11].start_x = 5713;
	BKPH[11].end_x = 5751;
	BKPH[11].zc_high = 321;

	BKPH[12].start_x = 5751;
	BKPH[12].end_x = 5790;
	BKPH[12].zc_high = 321;

	BKPH[13].start_x = 5865;
	BKPH[13].end_x = 5904;
	BKPH[13].zc_high = 321;

	BKPH[14].start_x = 5904;
	BKPH[14].end_x = 5940;
	BKPH[14].zc_high = 359;

	BKPH[15].start_x = 5940;
	BKPH[15].end_x = 5979;
	BKPH[15].zc_high = 396;

	BKPH[16].start_x = 5979;
	BKPH[16].end_x = 6016;
	BKPH[16].zc_high = 434;

	BKPH[17].start_x = 6845;
	BKPH[17].end_x = 6885;
	BKPH[17].zc_high = 434;

	BKPH[18].start_x = 6885;
	BKPH[18].end_x = 6923;
	BKPH[18].zc_high = 396;

	BKPH[19].start_x = 6923;
	BKPH[19].end_x = 6961;
	BKPH[19].zc_high = 359;

	BKPH[20].start_x = 6961;
	BKPH[20].end_x = 7001;
	BKPH[20].zc_high = 321;

	BKPH[21].start_x = 7001;
	BKPH[21].end_x = 7038;
	BKPH[21].zc_high = 282;

	BKPH[22].start_x = 7038;
	BKPH[22].end_x = 7076;
	BKPH[22].zc_high = 245;

	BKPH[23].start_x = 7076;
	BKPH[23].end_x = 7113;
	BKPH[23].zc_high = 207;

	BKPH[24].start_x = 7113;
	BKPH[24].end_x = 7152;
	BKPH[24].zc_high = 170;

	BKPH[25].start_x = 7152;
	BKPH[25].end_x = 7190;
	BKPH[25].zc_high = 170;

	BX[0].start_x = 605; //撞击可获得分数的砖块
	BX[0].end_x = 644;
	BX[0].top_y = 322;
	BX[0].button_y = 359;
	BX[0].judge = 1;

	BX[1].start_x = 795;
	BX[1].end_x = 830;
	BX[1].top_y = 322;
	BX[1].button_y = 359;
	BX[1].judge = 1;

	BX[2].start_x = 830;
	BX[2].end_x = 870;
	BX[2].top_y = 171;
	BX[2].button_y = 207;
	BX[2].judge = 1;

	BX[3].start_x = 870;
	BX[3].end_x = 907;
	BX[3].top_y = 322;
	BX[3].button_y = 359;
	BX[3].judge = 1;

	BX[4].start_x = 2952;
	BX[4].end_x = 2987;
	BX[4].top_y = 322;
	BX[4].button_y = 359;
	BX[4].judge = 1;

	BX[5].start_x = 3557;
	BX[5].end_x = 3594;
	BX[5].top_y = 171;
	BX[5].button_y = 207;
	BX[5].judge = 1;

	BX[6].start_x = 4010;
	BX[6].end_x = 4048;
	BX[6].top_y = 322;
	BX[6].button_y = 359;
	BX[6].judge = 1;

	BX[7].start_x = 4124;
	BX[7].end_x = 4161;
	BX[7].top_y = 322;
	BX[7].button_y = 359;
	BX[7].judge = 1;

	BX[8].start_x = 4238;
	BX[8].end_x = 4275;
	BX[8].top_y = 322;
	BX[8].button_y = 359;
	BX[8].judge = 1;

	BX[9].start_x = 4124;
	BX[9].end_x = 4161;
	BX[9].top_y = 171;
	BX[9].button_y = 207;
	BX[9].judge = 1;

	BX[10].start_x = 4882;
	BX[10].end_x = 4917;
	BX[10].top_y = 171;
	BX[10].button_y = 207;
	BX[10].judge = 1;

	BX[10].start_x = 4917;
	BX[10].end_x = 4955;
	BX[10].top_y = 171;
	BX[10].button_y = 207;
	BX[10].judge = 1;

	BX[11].start_x = 6433;
	BX[11].end_x = 6469;
	BX[11].top_y = 322;
	BX[11].button_y = 359;
	BX[11].judge = 1;

	ZK[0].start_x = 756; //普通可破坏砖块
	ZK[0].end_x = 795;
	ZK[0].top_y = 322;
	ZK[0].button_y = 359;
	ZK[0].judge = 1;

	ZK[1].start_x = 831;
	ZK[1].end_x = 870;
	ZK[1].top_y = 322;
	ZK[1].button_y = 359;
	ZK[1].judge = 1;

	ZK[2].start_x = 907;
	ZK[2].end_x = 946;
	ZK[2].top_y = 322;
	ZK[2].button_y = 359;
	ZK[2].judge = 1;

	ZK[3].start_x = 2914;
	ZK[3].end_x = 2953;
	ZK[3].top_y = 322;
	ZK[3].button_y = 359;
	ZK[3].judge = 1;

	ZK[4].start_x = 2989;
	ZK[4].end_x = 3026;
	ZK[4].top_y = 322;
	ZK[4].button_y = 359;
	ZK[4].judge = 1;

	ZK[5].start_x = 3026;
	ZK[5].end_x = 3068;
	ZK[5].top_y = 171;
	ZK[5].button_y = 207;
	ZK[5].judge = 1;

	ZK[6].start_x = 3068;
	ZK[6].end_x = 3110;
	ZK[6].top_y = 171;
	ZK[6].button_y = 207;
	ZK[6].judge = 1;

	ZK[7].start_x = 3110;
	ZK[7].end_x = 3152;
	ZK[7].top_y = 171;
	ZK[7].button_y = 207;
	ZK[7].judge = 1;

	ZK[8].start_x = 3152;
	ZK[8].end_x = 3194;
	ZK[8].top_y = 171;
	ZK[8].button_y = 207;
	ZK[8].judge = 1;

	ZK[9].start_x = 3194;
	ZK[9].end_x = 3236;
	ZK[9].top_y = 171;
	ZK[9].button_y = 207;
	ZK[9].judge = 1;

	ZK[10].start_x = 3236;
	ZK[10].end_x = 3278;
	ZK[10].top_y = 171;
	ZK[10].button_y = 207;
	ZK[10].judge = 1;

	ZK[11].start_x = 3278;
	ZK[11].end_x = 3331;
	ZK[11].top_y = 171;
	ZK[11].button_y = 207;
	ZK[11].judge = 1;

	ZK[12].start_x = 3442;
	ZK[12].end_x = 3482;
	ZK[12].top_y = 171;
	ZK[12].button_y = 207;
	ZK[12].judge = 1;

	ZK[13].start_x = 3482;
	ZK[13].end_x = 3522;
	ZK[13].top_y = 171;
	ZK[13].button_y = 207;
	ZK[13].judge = 1;

	ZK[14].start_x = 3522;
	ZK[14].end_x = 3562;
	ZK[14].top_y = 171;
	ZK[14].button_y = 207;
	ZK[14].judge = 1;

	ZK[15].start_x = 3556;
	ZK[15].end_x = 3596;
	ZK[15].top_y = 322;
	ZK[15].button_y = 359;
	ZK[15].judge = 1;

	ZK[16].start_x = 3782;
	ZK[16].end_x = 3820;
	ZK[16].top_y = 322;
	ZK[16].button_y = 359;
	ZK[16].judge = 1;

	ZK[17].start_x = 3820;
	ZK[17].end_x = 3860;
	ZK[17].top_y = 322;
	ZK[17].button_y = 359;
	ZK[17].judge = 1;

	ZK[17].start_x = 4463;
	ZK[17].end_x = 4504;
	ZK[17].top_y = 322;
	ZK[17].button_y = 359;
	ZK[17].judge = 1;

	ZK[18].start_x = 4578;
	ZK[18].end_x = 4614;
	ZK[18].top_y = 171;
	ZK[18].button_y = 207;
	ZK[18].judge = 1;

	ZK[19].start_x = 4614;
	ZK[19].end_x = 4652;
	ZK[19].top_y = 171;
	ZK[19].button_y = 207;
	ZK[19].judge = 1;

	ZK[20].start_x = 4652;
	ZK[20].end_x = 4692;
	ZK[20].top_y = 171;
	ZK[20].button_y = 207;
	ZK[20].judge = 1;

	ZK[21].start_x = 4842;
	ZK[21].end_x = 4882;
	ZK[21].top_y = 171;
	ZK[21].button_y = 207;
	ZK[21].judge = 1;

	ZK[22].start_x = 4955;
	ZK[22].end_x = 4995;
	ZK[22].top_y = 171;
	ZK[22].button_y = 207;
	ZK[22].judge = 1;

	ZK[23].start_x = 4880;
	ZK[23].end_x = 4917;
	ZK[23].top_y = 322;
	ZK[23].button_y = 359;
	ZK[23].judge = 1;

	ZK[24].start_x = 4917;
	ZK[24].end_x = 4958;
	ZK[24].top_y = 322;
	ZK[24].button_y = 359;
	ZK[24].judge = 1;

	ZK[25].start_x = 6356;
	ZK[25].end_x = 6393;
	ZK[25].top_y = 322;
	ZK[25].button_y = 359;
	ZK[25].judge = 1;

	ZK[26].start_x = 6393;
	ZK[26].end_x = 6432;
	ZK[26].top_y = 322;
	ZK[26].button_y = 359;
	ZK[26].judge = 1;

	ZK[27].start_x = 6469;
	ZK[27].end_x = 6510;
	ZK[27].top_y = 322;
	ZK[27].button_y = 359;
	ZK[27].judge = 1;

	GS[0].start_x = 620; //怪物数据初始化
	GS[0].end_x = GS[0].start_x + EnemyWidth;
	GS[0].xdfw = 210;
	GS[0].judge = 1;
	GS[0].enemywalk = 1;
	GS[0].left = 0;
	GS[0].right = 0;
	GS[0].xdjl = 0;

	GS[1].start_x = 1285; //怪物数据初始化
	GS[1].end_x = GS[1].start_x + EnemyWidth;
	GS[1].xdfw = 94;
	GS[1].judge = 1;
	GS[1].enemywalk = 1;
	GS[1].left = 0;
	GS[1].right = 0;
	GS[1].xdjl = 0;

	GS[2].start_x = 2004; //怪物数据初始化
	GS[2].end_x = GS[2].start_x + EnemyWidth;
	GS[2].xdfw = 98;
	GS[2].judge = 1;
	GS[2].enemywalk = 1;
	GS[2].left = 0;
	GS[2].right = 0;
	GS[2].xdjl = 0;

	GS[3].start_x = 2950; //怪物数据初始化
	GS[3].end_x = GS[3].start_x + EnemyWidth;
	GS[3].xdfw = 190;
	GS[3].judge = 1;
	GS[3].enemywalk = 1;
	GS[3].left = 0;
	GS[3].right = 0;
	GS[3].xdjl = 0;

	GS[4].start_x = 4047; //怪物数据初始化
	GS[4].end_x = GS[4].start_x + EnemyWidth;
	GS[4].xdfw = 227;
	GS[4].judge = 1;
	GS[4].enemywalk = 1;
	GS[4].left = 0;
	GS[4].right = 0;
	GS[4].xdjl = 0;

	GS[5].start_x = 4766; //怪物数据初始化
	GS[5].end_x = GS[5].start_x + EnemyWidth;
	GS[5].xdfw = 245;
	GS[5].judge = 1;
	GS[5].enemywalk = 1;
	GS[5].left = 0;
	GS[5].right = 0;
	GS[5].xdjl = 0;

	GS[6].start_x = 6509; //怪物数据初始化
	GS[6].end_x = GS[6].start_x + EnemyWidth;
	GS[6].xdfw = 192;
	GS[6].judge = 1;
	GS[6].enemywalk = 1;
	GS[6].left = 0;
	GS[6].right = 0;
	GS[6].xdjl = 0;

	ycmap[0].start_x = 360; //隐藏地图数据初始化
	ycmap[0].end_x = 630;
	ycmap[0].zc_high = 359;

	ycmap[1].start_x = 703;
	ycmap[1].end_x = 784;
	ycmap[1].zc_high = 398;

	YC[0].start_x = 365; //隐藏地图中金币坐标状态初始化
	YC[0].end_x = 395;
	YC[0].top_y = 324;
	YC[0].button_y = 360;
	YC[0].judge = 1;

	YC[1].start_x = 406;
	YC[1].end_x = 432;
	YC[1].top_y = 324;
	YC[1].button_y = 360;
	YC[1].judge = 1;

	YC[2].start_x = 445;
	YC[2].end_x = 470;
	YC[2].top_y = 324;
	YC[2].button_y = 360;
	YC[2].judge = 1;

	YC[3].start_x = 483;
	YC[3].end_x = 508;
	YC[3].top_y = 324;
	YC[3].button_y = 360;
	YC[3].judge = 1;

	YC[4].start_x = 521;
	YC[4].end_x = 547;
	YC[4].top_y = 324;
	YC[4].button_y = 360;
	YC[4].judge = 1;

	YC[5].start_x = 559;
	YC[5].end_x = 584;
	YC[5].top_y = 324;
	YC[5].button_y = 360;
	YC[5].judge = 1;

	YC[6].start_x = 597;
	YC[6].end_x = 622;
	YC[6].top_y = 324;
	YC[6].button_y = 360;
	YC[6].judge = 1;

	YC[7].start_x = 365;
	YC[7].end_x = 395;
	YC[7].top_y = 248;
	YC[7].button_y = 285;
	YC[7].judge = 1;

	YC[8].start_x = 406;
	YC[8].end_x = 432;
	YC[8].top_y = 248;
	YC[8].button_y = 285;
	YC[8].judge = 1;

	YC[9].start_x = 445;
	YC[9].end_x = 470;
	YC[9].top_y = 248;
	YC[9].button_y = 285;
	YC[9].judge = 1;

	YC[10].start_x = 483;
	YC[10].end_x = 508;
	YC[10].top_y = 248;
	YC[10].button_y = 285;
	YC[10].judge = 1;

	YC[11].start_x = 521;
	YC[11].end_x = 547;
	YC[11].top_y = 248;
	YC[11].button_y = 285;
	YC[11].judge = 1;

	YC[12].start_x = 559;
	YC[12].end_x = 584;
	YC[12].top_y = 248;
	YC[12].button_y = 285;
	YC[12].judge = 1;

	YC[13].start_x = 597;
	YC[13].end_x = 622;
	YC[13].top_y = 248;
	YC[13].button_y = 285;
	YC[13].judge = 1;

	YC[14].start_x = 406;
	YC[14].end_x = 432;
	YC[14].top_y = 173;
	YC[14].button_y = 209;
	YC[14].judge = 1;

	YC[15].start_x = 445;
	YC[15].end_x = 470;
	YC[15].top_y = 173;
	YC[15].button_y = 209;
	YC[15].judge = 1;

	YC[16].start_x = 483;
	YC[16].end_x = 508;
	YC[16].top_y = 173;
	YC[16].button_y = 209;
	YC[16].judge = 1;

	YC[17].start_x = 521;
	YC[17].end_x = 547;
	YC[17].top_y = 173;
	YC[17].button_y = 209;
	YC[17].judge = 1;

	YC[18].start_x = 559;
	YC[18].end_x = 584;
	YC[18].top_y = 173;
	YC[18].button_y = 209;
	YC[18].judge = 1;

	initgraph(Width, High);

	mciSendString("open Music\\back.mp3 alias bkmusic", NULL, 0, NULL); //背景音乐
	mciSendString("play bkmusic repeat", NULL, 0, NULL);				//循环播放

	loadimage(&img_ksjm, _T("Picture material\\开始界面.png")); //开始界面图片导入
	loadimage(&img_gz, _T("Picture material\\规则界面.png"));   //规则图片的导入
	loadimage(&img_bk, _T("Picture material\\背景图.png"));		//背景图片导入
	loadimage(&img_flag, _T("Picture material\\旗.png"));		//旗图片导入
	loadimage(&img_ty, _T("Picture material\\跳跃r9.png"));		//跳跃图片的导入
	loadimage(&img_bk2, _T("Picture material\\背景2.png"));		//隐藏地图导入

	loadimage(&img_role1r, _T("Picture material\\人物1r.png"));   //人物图像导入
	loadimage(&img_role2r, _T("Picture material\\人物2r.png"));   //人物图像导入
	loadimage(&img_role3r, _T("Picture material\\人物3r.png"));   //人物图像导入
	loadimage(&img_role4r, _T("Picture material\\人物4r.png"));   //人物图像导入
	loadimage(&img_role5r, _T("Picture material\\人物5r.png"));   //人物图像导入    向右行走
	loadimage(&img_role6r, _T("Picture material\\人物6r.png"));   //人物图像导入
	loadimage(&img_role7r, _T("Picture material\\人物7r.png"));   //人物图像导入
	loadimage(&img_role8r, _T("Picture material\\人物8r.png"));   //人物图像导入
	loadimage(&img_role9r, _T("Picture material\\人物9r.png"));   //人物图像导入
	loadimage(&img_role10r, _T("Picture material\\人物10r.png")); //人物图像导入

	loadimage(&img_role1l, _T("Picture material\\人物1l.png"));   //人物图像导入
	loadimage(&img_role2l, _T("Picture material\\人物2l.png"));   //人物图像导入
	loadimage(&img_role3l, _T("Picture material\\人物3l.png"));   //人物图像导入
	loadimage(&img_role4l, _T("Picture material\\人物4l.png"));   //人物图像导入
	loadimage(&img_role5l, _T("Picture material\\人物5l.png"));   //人物图像导入    向左行走
	loadimage(&img_role6l, _T("Picture material\\人物6l.png"));   //人物图像导入
	loadimage(&img_role7l, _T("Picture material\\人物7l.png"));   //人物图像导入
	loadimage(&img_role8l, _T("Picture material\\人物8l.png"));   //人物图像导入
	loadimage(&img_role9l, _T("Picture material\\人物9l.png"));   //人物图像导入
	loadimage(&img_role10l, _T("Picture material\\人物10l.png")); //人物图像导入

	loadimage(&img_end1, _T("Picture material\\end1.png"));   //通关图像导入
	loadimage(&img_end2, _T("Picture material\\end2.png"));   //通关图像导入
	loadimage(&img_end3, _T("Picture material\\end3.png"));   //通关图像导入
	loadimage(&img_end4, _T("Picture material\\end4.png"));   //通关图像导入
	loadimage(&img_end5, _T("Picture material\\end5.png"));   //通关图像导入
	loadimage(&img_end6, _T("Picture material\\end6.png"));   //通关图像导入
	loadimage(&img_end7, _T("Picture material\\end7.png"));   //通关图像导入
	loadimage(&img_end8, _T("Picture material\\end8.png"));   //通关图像导入
	loadimage(&img_end8, _T("Picture material\\end8.png"));   //通关图像导入
	loadimage(&img_end9, _T("Picture material\\end9.png"));   //通关图像导入
	loadimage(&img_end10, _T("Picture material\\end10.png")); //通关图像导入
	loadimage(&img_end11, _T("Picture material\\end11.png")); //通关图像导入
	loadimage(&img_end12, _T("Picture material\\end12.png")); //通关图像导入
	loadimage(&img_end13, _T("Picture material\\end13.png")); //通关图像导入
	loadimage(&img_end14, _T("Picture material\\end14.png")); //通关图像导入
	loadimage(&img_end15, _T("Picture material\\end15.png")); //通关图像导入
	loadimage(&img_end16, _T("Picture material\\end16.png")); //通关图像导入
	loadimage(&img_end17, _T("Picture material\\end17.png")); //通关图像导入
	loadimage(&img_end18, _T("Picture material\\end18.png")); //通关图像导入
	loadimage(&img_end19, _T("Picture material\\end19.png")); //通关图像导入
	loadimage(&img_end20, _T("Picture material\\end20.png")); //通关图像导入
	loadimage(&img_end21, _T("Picture material\\end21.png")); //通关图像导入
	loadimage(&img_end22, _T("Picture material\\end22.png")); //通关图像导入
	loadimage(&img_end23, _T("Picture material\\end23.png")); //通关图像导入
	loadimage(&img_end24, _T("Picture material\\end24.png")); //通关图像导入
	loadimage(&img_end25, _T("Picture material\\end25.png")); //通关图像导入
	loadimage(&img_end26, _T("Picture material\\end26.png")); //通关图像导入
	loadimage(&img_end27, _T("Picture material\\end27.png")); //通关图像导入
	loadimage(&img_end28, _T("Picture material\\end28.png")); //通关图像导入
	loadimage(&img_end29, _T("Picture material\\end29.png")); //通关图像导入
	loadimage(&img_end30, _T("Picture material\\end30.png")); //通关图像导入

	loadimage(&img_dead, _T("Picture material\\dead.png")); //怪兽死亡图片导入

	loadimage(&img_block, _T("Picture material\\砖.png")); //砖块图片导入

	loadimage(&img_jb, _T("Picture material\\jb.png"));   //金币图片导入
	loadimage(&img_jb2, _T("Picture material\\jb2.png")); //金币图片导入

	loadimage(&img_enemyl1, _T("Picture material\\enemyl1.png")); //怪兽向左图片导入
	loadimage(&img_enemyl2, _T("Picture material\\enemyl2.png")); //怪兽向左图片导入
	loadimage(&img_enemyr1, _T("Picture material\\enemyr1.png")); //怪兽向右图片导入
	loadimage(&img_enemyr2, _T("Picture material\\enemyr2.png")); //怪兽向右图片导入

	loadimage(&img_roleDown1, _T("Picture material\\roleDown1.png"));   //人物进入管道画面导入
	loadimage(&img_roleDown2, _T("Picture material\\roleDown2.png"));   //人物进入管道画面导入
	loadimage(&img_roleDown3, _T("Picture material\\roleDown3.png"));   //人物进入管道画面导入
	loadimage(&img_roleDown4, _T("Picture material\\roleDown4.png"));   //人物进入管道画面导入
	loadimage(&img_roleDown5, _T("Picture material\\roleDown5.png"));   //人物进入管道画面导入
	loadimage(&img_roleDown6, _T("Picture material\\roleDown6.png"));   //人物进入管道画面导入   向下
	loadimage(&img_roleDown7, _T("Picture material\\roleDown7.png"));   //人物进入管道画面导入
	loadimage(&img_roleDown8, _T("Picture material\\roleDown8.png"));   //人物进入管道画面导入
	loadimage(&img_roleDown9, _T("Picture material\\roleDown9.png"));   //人物进入管道画面导入
	loadimage(&img_roleDown10, _T("Picture material\\roleDown10.png")); //人物进入管道画面导入
	loadimage(&img_roleDown11, _T("Picture material\\roleDown11.png")); //人物进入管道画面导入
	loadimage(&img_roleDown12, _T("Picture material\\roleDown12.png")); //人物进入管道画面导入
	loadimage(&img_roleDown13, _T("Picture material\\roleDown13.png")); //人物进入管道画面导入

	loadimage(&img_roleR1, _T("Picture material\\roleR1.png"));   //人物进入管道画面导入
	loadimage(&img_roleR2, _T("Picture material\\roleR2.png"));   //人物进入管道画面导入
	loadimage(&img_roleR3, _T("Picture material\\roleR3.png"));   //人物进入管道画面导入
	loadimage(&img_roleR4, _T("Picture material\\roleR4.png"));   //人物进入管道画面导入
	loadimage(&img_roleR5, _T("Picture material\\roleR5.png"));   //人物进入管道画面导入
	loadimage(&img_roleR6, _T("Picture material\\roleR6.png"));   //人物进入管道画面导入   向右
	loadimage(&img_roleR7, _T("Picture material\\roleR7.png"));   //人物进入管道画面导入
	loadimage(&img_roleR8, _T("Picture material\\roleR8.png"));   //人物进入管道画面导入
	loadimage(&img_roleR9, _T("Picture material\\roleR9.png"));   //人物进入管道画面导入
	loadimage(&img_roleR10, _T("Picture material\\roleR10.png")); //人物进入管道画面导入
	loadimage(&img_roleR11, _T("Picture material\\roleR11.png")); //人物进入管道画面导入
	loadimage(&img_roleR12, _T("Picture material\\roleR12.png")); //人物进入管道画面导入
	loadimage(&img_roleR13, _T("Picture material\\roleR13.png")); //人物进入管道画面导入

	loadimage(&img_role_Death1, _T("Picture material\\role_Death1.png")); //人物死亡动画
	loadimage(&img_role_Death2, _T("Picture material\\role_Death2.png")); //人物死亡动画
	loadimage(&img_role_Death3, _T("Picture material\\role_Death3.png")); //人物死亡动画
	loadimage(&img_role_Death4, _T("Picture material\\role_Death4.png")); //人物死亡动画
	loadimage(&img_role_Death5, _T("Picture material\\role_Death5.png")); //人物死亡动画
	loadimage(&img_role_Death6, _T("Picture material\\role_Death6.png")); //人物死亡动画
	loadimage(&img_role_Death7, _T("Picture material\\role_Death7.png")); //人物死亡动画

	loadimage(&img_jx, _T("Picture material\\continue.png"));   //询问是否继续图片
	loadimage(&img_lyj, _T("Picture material\\lyj.png"));		//制作人员名单图片导入
	loadimage(&img_bzf, _T("Picture material\\bzf.png"));		//制作人员名单图片导入
	loadimage(&img_ss, _T("Picture material\\ss.png"));			//制作人员名单图片导入
	loadimage(&img_thanks, _T("Picture material\\thanks.png")); //感谢图片导入
	loadimage(&img_pause, _T("Picture material\\pause.png"));   //暂停图片导入
}

// 半透明贴图函数
// 参数：
//		dstimg: 目标 IMAGE 对象指针。NULL 表示默认窗体
//		x, y:	目标贴图位置
//		srcimg: 源 IMAGE 对象指针。NULL 表示默认窗体

void transparentimage(IMAGE *dstimg, int x, int y, IMAGE *srcimg)
{
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	int w = srcimg->getwidth();
	int h = srcimg->getheight();

	// 结构体的第三个成员表示额外的透明度，0 表示全透明，255 表示不透明。
	BLENDFUNCTION bf = {AC_SRC_OVER, 0, 255, AC_SRC_ALPHA};
	// 使用 Windows GDI 函数实现半透明位图
	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
}

void roleGD(int judge) //进入管道的动画
{
	if (judge == 1)
	{
		switch (hmtk_GD / 10) //向下进入管道动画
		{
		case 0:
			transparentimage(NULL, role_x, role_y, &img_roleDown1);
			break;
		case 1:
			transparentimage(NULL, role_x, role_y, &img_roleDown2);
			break;
		case 2:
			transparentimage(NULL, role_x, role_y, &img_roleDown3);
			break;
		case 3:
			transparentimage(NULL, role_x, role_y, &img_roleDown4);
			break;
		case 4:
			transparentimage(NULL, role_x, role_y, &img_roleDown5);
			break;
		case 5:
			transparentimage(NULL, role_x, role_y, &img_roleDown6);
			break;
		case 6:
			transparentimage(NULL, role_x, role_y, &img_roleDown7);
			break;
		case 7:
			transparentimage(NULL, role_x, role_y, &img_roleDown8);
			break;
		case 8:
			transparentimage(NULL, role_x, role_y, &img_roleDown9);
			break;
		case 9:
			transparentimage(NULL, role_x, role_y, &img_roleDown10);
			break;
		case 10:
			transparentimage(NULL, role_x, role_y, &img_roleDown11);
			break;
		case 11:
			transparentimage(NULL, role_x, role_y, &img_roleDown12);
			break;
		case 12:
			transparentimage(NULL, role_x, role_y, &img_roleDown13);
			break;
		}
	}
	else if (judge == 2) //向右进入管道动画
	{
		switch (hmtk_GD / 10)
		{
		case 0:
			transparentimage(NULL, role_x, role_y, &img_roleR1);
			break;
		case 1:
			transparentimage(NULL, role_x, role_y, &img_roleR2);
			break;
		case 2:
			transparentimage(NULL, role_x, role_y, &img_roleR3);
			break;
		case 3:
			transparentimage(NULL, role_x, role_y, &img_roleR4);
			break;
		case 4:
			transparentimage(NULL, role_x, role_y, &img_roleR5);
			break;
		case 5:
			transparentimage(NULL, role_x, role_y, &img_roleR6);
			break;
		case 6:
			transparentimage(NULL, role_x, role_y, &img_roleR7);
			break;
		case 7:
			transparentimage(NULL, role_x, role_y, &img_roleR8);
			break;
		case 8:
			transparentimage(NULL, role_x, role_y, &img_roleR9);
			break;
		case 9:
			transparentimage(NULL, role_x, role_y, &img_roleR10);
			break;
		case 10:
			transparentimage(NULL, role_x, role_y, &img_roleR11);
			break;
		case 11:
			transparentimage(NULL, role_x, role_y, &img_roleR12);
			break;
		case 12:
			transparentimage(NULL, role_x, role_y, &img_roleR13);
			break;
		}
	}
	else if (judge == 3) //向上出管道动画
	{
		switch (hmtk_GD / 10)
		{
		case 0:
			transparentimage(NULL, role_x, role_y, &img_roleDown13);
			break;
		case 1:
			transparentimage(NULL, role_x, role_y, &img_roleDown12);
			break;
		case 2:
			transparentimage(NULL, role_x, role_y, &img_roleDown11);
			break;
		case 3:
			transparentimage(NULL, role_x, role_y, &img_roleDown10);
			break;
		case 4:
			transparentimage(NULL, role_x, role_y, &img_roleDown9);
			break;
		case 5:
			transparentimage(NULL, role_x, role_y, &img_roleDown8);
			break;
		case 6:
			transparentimage(NULL, role_x, role_y, &img_roleDown7);
			break;
		case 7:
			transparentimage(NULL, role_x, role_y, &img_roleDown6);
			break;
		case 8:
			transparentimage(NULL, role_x, role_y, &img_roleDown5);
			break;
		case 9:
			transparentimage(NULL, role_x, role_y, &img_roleDown4);
			break;
		case 10:
			transparentimage(NULL, role_x, role_y, &img_roleDown3);
			break;
		case 11:
			transparentimage(NULL, role_x, role_y, &img_roleDown2);
			break;
		case 12:
			transparentimage(NULL, role_x, role_y, &img_roleDown1);
			break;
		}
	}
}

void RoleWalk(int left, int right, int judge) //人物行走
{
	if (judge == 1) //向左
	{
		switch (left)
		{
		case 0:
			transparentimage(NULL, role_x, role_y, &img_role1l);
			break;
		case 1:
			transparentimage(NULL, role_x, role_y, &img_role2l);
			break;
		case 2:
			transparentimage(NULL, role_x, role_y, &img_role3l);
			break;
		case 3:
			transparentimage(NULL, role_x, role_y, &img_role4l);
			break;
		case 4:
			transparentimage(NULL, role_x, role_y, &img_role5l);
			break;
		case 5:
			transparentimage(NULL, role_x, role_y, &img_role6l);
			break;
		case 6:
			transparentimage(NULL, role_x, role_y, &img_role7l);
			break;
		case 7:
			transparentimage(NULL, role_x, role_y, &img_role8l);
			break;
		case 8:
			transparentimage(NULL, role_x, role_y, &img_role9l);
			break;
		case 9:
			transparentimage(NULL, role_x, role_y, &img_role10l);
			break;
		default:
			break;
		}
	}
	else if (judge == 2) //向右
	{
		switch (right)
		{
		case 0:
			transparentimage(NULL, role_x, role_y, &img_role1r);
			break;
		case 1:
			transparentimage(NULL, role_x, role_y, &img_role2r);
			break;
		case 2:
			transparentimage(NULL, role_x, role_y, &img_role3r);
			break;
		case 3:
			transparentimage(NULL, role_x, role_y, &img_role4r);
			break;
		case 4:
			transparentimage(NULL, role_x, role_y, &img_role5r);
			break;
		case 5:
			transparentimage(NULL, role_x, role_y, &img_role6r);
			break;
		case 6:
			transparentimage(NULL, role_x, role_y, &img_role7r);
			break;
		case 7:
			transparentimage(NULL, role_x, role_y, &img_role8r);
			break;
		case 8:
			transparentimage(NULL, role_x, role_y, &img_role9r);
			break;
		case 9:
			transparentimage(NULL, role_x, role_y, &img_role10r);
			break;
		default:
			break;
		}
	}
	else if (judge == 3) //上跳
	{
		transparentimage(NULL, role_x, role_y, &img_ty);
	}
}
void roleDeath(void) //人物死亡动画
{
	if (role == 0)
	{
		switch ((hmtk_GD - 30) / 30)
		{
		case 0:
			transparentimage(NULL, role_x, role_y, &img_role_Death1);
			break;
		case 1:
			transparentimage(NULL, role_x, role_y, &img_role_Death2);
			break;
		case 2:
			transparentimage(NULL, role_x, role_y, &img_role_Death3);
			break;
		case 3:
			transparentimage(NULL, role_x, role_y, &img_role_Death4);
			break;
		case 4:
			transparentimage(NULL, role_x, role_y, &img_role_Death5);
			break;
		case 5:
			transparentimage(NULL, role_x, role_y, &img_role_Death6);
			break;
		case 6:
			transparentimage(NULL, role_x, role_y, &img_role_Death7);
			break;
		}
	}
}
void endwalk(int zs, int jd) //通关动画实现
{
	if (jd == 1) //阶段1
	{
		switch (zs)
		{
		case 0:
			transparentimage(NULL, role_x, role_y, &img_end1);
			break;
		case 1:
			transparentimage(NULL, role_x, role_y, &img_end1);
			break;
		case 2:
			transparentimage(NULL, role_x, role_y, &img_end1);
			break;
		case 3:
			transparentimage(NULL, role_x, role_y, &img_end2);
			break;
		case 4:
			transparentimage(NULL, role_x, role_y, &img_end2);
			break;
		case 5:
			transparentimage(NULL, role_x, role_y, &img_end2);
			break;
		case 6:
			transparentimage(NULL, role_x, role_y, &img_end3);
			break;
		case 7:
			transparentimage(NULL, role_x, role_y, &img_end3);
			break;
		case 8:
			transparentimage(NULL, role_x, role_y, &img_end3);
			break;

		default:
			break;
		}
	}
	else if (jd == 2) //阶段2
	{
		switch (zs)
		{
		case 0:
			transparentimage(NULL, role_x, role_y, &img_end4);
			break;
		case 1:
			transparentimage(NULL, role_x, role_y, &img_end5);
			break;
		case 2:
			transparentimage(NULL, role_x, role_y, &img_end6);
			break;

		default:
			break;
		}
	}
	else if (jd == 3) //阶段3
	{
		switch (zs)
		{
		case 0:
			transparentimage(NULL, role_x, role_y, &img_end7);
			break;
		case 1:
			transparentimage(NULL, role_x, role_y, &img_end8);
			break;
		case 2:
			transparentimage(NULL, role_x, role_y, &img_end9);
			break;
		case 3:
			transparentimage(NULL, role_x, role_y, &img_end10);
			break;
		case 4:
			transparentimage(NULL, role_x, role_y, &img_end11);
			break;
		case 5:
			transparentimage(NULL, role_x, role_y, &img_end12);
			break;
		case 6:
			transparentimage(NULL, role_x, role_y, &img_end13);
			break;
		case 7:
			transparentimage(NULL, role_x, role_y, &img_end14);
			break;
		case 8:
			transparentimage(NULL, role_x, role_y, &img_end15);
			break;

		default:
			break;
		}
	}
	else if (jd == 4) //阶段4
	{
		switch (zs)
		{
		case 0:
			transparentimage(NULL, role_x, role_y, &img_end16);
			break;
		case 1:
			transparentimage(NULL, role_x, role_y, &img_end17);
			break;
		case 2:
			transparentimage(NULL, role_x, role_y, &img_end18);
			break;
		case 3:
			transparentimage(NULL, role_x, role_y, &img_end19);
			break;
		case 4:
			transparentimage(NULL, role_x, role_y, &img_end20);
			break;
		case 5:
			transparentimage(NULL, role_x, role_y, &img_end21);
			break;
		case 6:
			transparentimage(NULL, role_x, role_y, &img_end22);
			break;
		case 7:
			transparentimage(NULL, role_x, role_y, &img_end23);
			break;
		case 8:
			transparentimage(NULL, role_x, role_y, &img_end24);
			break;
		case 9:
			transparentimage(NULL, role_x, role_y, &img_end25);
			break;
		case 10:
			transparentimage(NULL, role_x, role_y, &img_end26);
			break;
		case 11:
			transparentimage(NULL, role_x, role_y, &img_end27);
			break;
		case 12:
			transparentimage(NULL, role_x, role_y, &img_end28);
			break;
		case 13:
			transparentimage(NULL, role_x, role_y, &img_end29);
			break;
		case 14:
			transparentimage(NULL, role_x, role_y, &img_end30);
			break;

		default:
			break;
		}
	}
}

void show() //显示画面
{
	BeginBatchDraw(); // 开始批量绘制

	if (map == 0) //显示初始地图
		putimage(bk_x, bk_y, &img_bk);
	if (map == 1) //显示隐藏地图
		putimage(0, 0, &img_bk2);

	if (judgeGD == 0 || hmtk_GD < 30) //显示人物行走动作
		RoleWalk(step_left, step_right, moveDeriction);
	else if (judgeGD >= 1 && judgeGD <= 3) //人物进入管道动作
		roleGD(judgeGD);

	if (role == 0 && hmtk_GD >= 30) //人物死亡动画
	{
		roleDeath();
	}
	if (map == 0) //初始地图部分
	{
		for (int i = 0; i < 12; i++) //当人物撞击过得分砖块后显示图片
		{
			if (BX[i].judge > 1)
			{
				putimage(BX[i].start_x + bk_x, BX[i].top_y - 1, &img_block);
			}
		}

		for (int i = 0; i < 7; i++) //怪物行走显示图片
		{
			if (GS[i].judge == 1) //怪兽存在
			{
				if (GS[i].enemywalk == 1) //怪兽向左走
				{
					switch (GS[i].left)
					{
					case 0:
						transparentimage(NULL, GS[i].start_x + bk_x, enemyFlour, &img_enemyl1);
						break;
					case 1:
						transparentimage(NULL, GS[i].start_x + bk_x, enemyFlour, &img_enemyl2);
						break;
					default:
						break;
					}
				}
				else if (GS[i].enemywalk == -1) //怪兽向右走
				{
					switch (GS[i].right)
					{
					case 0:
						transparentimage(NULL, GS[i].start_x + bk_x, enemyFlour, &img_enemyr1);
						break;
					case 1:
						transparentimage(NULL, GS[i].start_x + bk_x, enemyFlour, &img_enemyr2);
						break;
					default:
						break;
					}
				}
			}
			else
			{
				count[i]++;
				if (count[i] <= 10)
					transparentimage(NULL, GS[i].start_x + bk_x, enemyFlour, &img_dead); //怪兽死亡画面
			}
		}

		for (int i = 0; i < 12; i++) //撞击得分砖块后出现金币画面
		{
			if (BX[i].judge > 1 && BX[i].judge < 20)
				transparentimage(NULL, BX[i].start_x + bk_x, BX[i].top_y - 65, &img_jb);
		}
	}

	if (map == 1) //隐藏地图部分
	{
		for (int i = 0; i < 19; i++)
		{
			if (YC[i].judge == 1) //隐藏地图中金币的显示
				transparentimage(NULL, YC[i].start_x, YC[i].top_y, &img_jb2);
		}
	}

	transparentimage(NULL, flag_x, flag_y, &img_flag); //旗帜的显示
	printtxt(900, 10, time / 100);					   //打印游戏时间倒计时
	printscore(50, 10);								   //打印“score=”
	printtxt(200, 10, fs);							   //打印分数
	setbkmode(TRANSPARENT);							   //打印的字的背景为透明
	FlushBatchDraw();
}
void updateWithoutInput() //与输入无关的更新
{
	if (role == 0) //人物死亡时
	{

		if (hmtk_GD == 0) //播放一次死亡音乐
		{
			mciSendString("close bkmusic", NULL, 0, NULL);
			mciSendString("close swmusic", NULL, 0, NULL);
			mciSendString("open Music\\死亡.mp3 alias swmusic", NULL, 0, NULL);
			mciSendString("play swmusic", NULL, 0, NULL); //仅播放一次音乐
		}

		judgeOperate = 0; //无法操控人物
		judgeGD = 4;
		if (hmtk_GD == 30) //人物停顿实现
		{
			role_y -= 100;
			real_y -= 100;
		}
		if (hmtk_GD % 30 == 0 && hmtk_GD > 20)
			role_y += 30;
		hmtk_GD++;

		if ((hmtk_GD - 30) / 30 == 6)
			ch = 0;
	}
	if (role == 1) //人物存活时
	{
		sfkt = 0;		  //判断人物在空中是否可跳
		if (role_y > 515) //当人物纵坐标小于时死亡
		{
			role = 0; //死亡
		}

		if (fflag)			  //拿到旗之前都可以走动
			judgeOperate = 1; //确保每次循环都是从可行走开始

		if (judgeGD == 1) // 马里奥钻管道判定及动画位置改变
		{
			judgeOperate = 0;

			if (hmtk_GD % 10 == 0)
				role_y += 4;

			hmtk_GD++;
			if (hmtk_GD / 10 == 12) //进入隐藏地图
			{
				judgeOperate = 1;
				hmtk_GD = 0;
				judgeGD = 0;
				map = 1;
				role_x = 278;
				role_y = 60;
				real_y = 60;
			}
		}
		else if (judgeGD == 2) //进入2号管道
		{
			judgeOperate = 0;
			if (hmtk_GD % 10 == 0)
			{
				role_x += 3;
				real_x += 3;
			}

			hmtk_GD++;
			if (hmtk_GD / 10 == 12) //人物回到大地图
			{
				hmtk_GD = 0;
				judgeGD = 3;
				bk_x = -5850;
				role_x = 343;
				real_x = 6195;
				role_y = 395;
				real_y = 395;
				map = 0;
			}
		}
		else if (judgeGD == 3) //人物钻出3号管道
		{
			judgeOperate = 0;
			if (hmtk_GD == 0)
			{
				mciSendString("close swmusic", NULL, 0, NULL);
				mciSendString("open Music\\进管道.mp3 alias swmusic", NULL, 0, NULL);
				mciSendString("play swmusic", NULL, 0, NULL); //仅播放一次音乐
			}
			if (hmtk_GD % 10 == 0)
			{

				role_y -= 4;
				real_y -= 4;
			}
			hmtk_GD++;
			if (hmtk_GD / 10 == 12)
			{
				judgeOperate = 1;
				hmtk_GD = 0;
				judgeGD = 0;
				role_y = 340;
				real_y = 340;
			}
		}

		if (map == 1) // 使人物在隐藏地图地面上的位置更准确
		{
			if (role_y > 400 && judgeJump == 0)
			{
				role_y = 415;
				real_y = 415;
			}
		}

		if (judgeJump == 0 && role_y < flour) //人物下降
		{
			role_y += speed_y;
			real_y += speed_y;
		}
		if (judgeJump == 1) //人物起跳
		{
			role_y -= speed_y * 2;
			real_y -= speed_y * 2;
			jumpHigh += speed_y * 2;
			if (judgeEnemyJump == 0) //没有踩到怪物
			{
				if (jumpHigh >= jumpHighTop) //人物跳跃高度限制
				{
					judgeJump = 0;
					jumpHigh = 0;
				}
			}
			else if (judgeEnemyJump == 1) //人物踩到怪物
			{
				if (jumpHigh >= jumpEnemyHigh) //人物反弹高度限制
				{
					judgeJump = 0;
					jumpHigh = 0;
					judgeEnemyJump = 0;
				}
			}
		}

		if (real_x >= 7475) //结束界面的动画
		{
			BeginBatchDraw();
			mciSendString("close bkmusic", NULL, 0, NULL);
			mciSendString("close pullmusic", NULL, 0, NULL);
			mciSendString("open Music\\pull.mp3 alias pullmusic", NULL, 0, NULL);
			mciSendString("play pullmusic", NULL, 0, NULL); //仅播放一次音乐

			int x = 1;
			while (flag_y <= role_y - 19 && fflag) //拿旗
			{
				putimage(bk_x, bk_y, &img_bk);
				printscore(50, 10);
				printtxt(200, 10, fs);
				printtxt(950, 10, time / 100);
				judgeOperate = 0; //人物不能被操控
				flag_y += 3;	  //旗下降
				if (role_y > 400) //人物在地面上使人在旗杆上
				{
					role_y = 391;
				}
				else
					transparentimage(NULL, role_x, role_y, &img_end1);
				x = (x + 1) % 9;
				endwalk(x, 1); //通关阶段一的动画
				transparentimage(NULL, flag_x, flag_y, &img_flag);
				FlushBatchDraw();
				Sleep(15);
				cleardevice();
			}
			//播放通关音乐
			mciSendString("close bkmusic", NULL, 0, NULL);
			mciSendString("close ggmusic", NULL, 0, NULL);
			mciSendString("open Music\\过关.mp3 alias ggmusic", NULL, 0, NULL);
			mciSendString("play ggmusic", NULL, 0, NULL); //仅播放一次音乐

			while (role_y <= 390 && fflag) //旗和人一起下落
			{
				putimage(bk_x, bk_y, &img_bk);
				printscore(50, 10);
				printtxt(950, 10, time / 100);
				printtxt(200, 10, fs);
				role_y += 2; //人下降
				flag_y += 2; //旗下降
				transparentimage(NULL, flag_x, flag_y, &img_flag);
				transparentimage(NULL, role_x, role_y, &img_end1);
				FlushBatchDraw();
				Sleep(15);
				cleardevice();
			}
			for (int i = 0; i < 3; i++) //转身
			{
				role_x += 15;
				putimage(bk_x, bk_y, &img_bk);
				transparentimage(NULL, flag_x, flag_y, &img_flag);
				endwalk(i, 2); //通关第二阶段动画
				Sleep(50);
				cleardevice();
			}
			//播放跳跃音乐
			mciSendString("close jpmusic", NULL, 0, NULL);
			mciSendString("open Music\\跳跃.mp3 alias jpmusic", NULL, 0, NULL);
			mciSendString("play jpmusic", NULL, 0, NULL); //仅播放一次音乐

			int add = 3;				 //调节移动速度的变量
			for (int i = 0; i < 90; i++) //跳
			{
				if (i == 20 || i == 45)
					add--;
				putimage(bk_x, bk_y, &img_bk);
				transparentimage(NULL, flag_x, flag_y, &img_flag);
				printtxt(950, 10, time / 100);
				printscore(50, 10);
				printtxt(200, 10, fs);
				role_y -= add;
				role_x++;
				endwalk(i % 9, 3);
				FlushBatchDraw();
				Sleep(5);
				cleardevice();
			}
			for (int i = 0; i < 108; i++) //翻转下落
			{
				if (i == 24 || i == 48)
					add++;
				putimage(bk_x, bk_y, &img_bk);
				transparentimage(NULL, flag_x, flag_y, &img_flag);
				printscore(50, 10);
				printtxt(950, 10, time / 100);
				printtxt(200, 10, fs);
				if (role_y <= 425)
					role_y += add;
				role_x++;
				endwalk(i % 9, 3);
				FlushBatchDraw();
				Sleep(5);
				cleardevice();
			}
			int lintime = time / 100; //为不影响全局时间，建立临时时间变量
			char sltime[50];
			int linfs = fs; //为不影响全局分数，建立临时分数变量
			char slfs[50];
			while (lintime > 0) //时间累加到分数的动画
			{
				putimage(bk_x, bk_y, &img_bk);
				transparentimage(NULL, flag_x, flag_y, &img_flag);
				transparentimage(NULL, role_x, role_y - 20, &img_end17);
				lintime--;
				linfs++;
				printscore(50, 10);
				printtxt(950, 10, lintime);
				printtxt(200, 10, linfs);
				setbkmode(TRANSPARENT);
				mciSendString("open Music\\统计时间.mp3 alias tjmusic", NULL, 0, NULL);
				mciSendString("play tjmusic", NULL, 0, NULL);
				Sleep(5);
				FlushBatchDraw();
			}
			mciSendString("close tjmusic", NULL, 0, NULL);
			role_y -= 20;				  //为适应坐标，进行调整
			for (int i = 0; i <= 14; i++) //喝彩动画
			{
				putimage(bk_x, bk_y, &img_bk);
				transparentimage(NULL, flag_x, flag_y, &img_flag);
				printscore(50, 10);
				printtxt(950, 10, lintime);
				printtxt(200, 10, linfs);
				endwalk(i, 4);
				FlushBatchDraw();
				Sleep(50);
				cleardevice();
			}
			fs = linfs; //临时分数赋值到全局分数
			ch = 0;
			Sleep(1000);
			fflag = 0;
		}

		if (map == 0) //大背景
		{
			for (int i = 0; i < 3; i++) //坑地下落判断
			{
				if (real_x + roleWidth / 2 > KD[i].start_x && real_x + roleWidth / 2 < KD[i].end_x && real_y + 5 > flour)
				{
					if (real_y >= flour - roleHigh)
					{
						judgekd = 0;
						role_y += speed_y;
						real_y += speed_y;
					}
				}
			}

			for (int i = 0; i < 6; i++) // 站在管道上的判断
			{
				if (real_x + roleWidth >= GD[i].start_x && real_x <= GD[i].end_x && real_y + roleHigh >= GD[i].zc_high)
				{
					sfkt = 1;
					role_y -= speed_y;
					real_y -= speed_y;
				}
			}

			for (int i = 0; i < 26; i++) //站在不可破坏的砖块的判断
			{
				if (real_x + roleWidth >= BKPH[i].start_x && real_x <= BKPH[i].end_x && real_y + roleHigh >= BKPH[i].zc_high + 10)
				{
					sfkt = 1;
					role_y -= speed_y;
					real_y -= speed_y;
				}
			}

			for (int i = 0; i < 12; i++) //站在撞击获得分数的砖块上的判断
			{
				if (real_x + roleWidth >= BX[i].start_x && real_x <= BX[i].end_x && real_y + roleHigh >= BX[i].top_y + 10 && real_y + roleHigh <= BX[i].button_y)
				{
					sfkt = 1;
					role_y -= speed_y;
					real_y -= speed_y;
				}
			}

			for (int i = 0; i < 28; i++) //站在普通砖块上的判断
			{
				if ((real_x + roleWidth >= ZK[i].start_x && real_x <= ZK[i].end_x && real_y + roleHigh >= ZK[i].top_y + 10 && real_y + roleHigh <= ZK[i].button_y) && ZK[i].judge == 1)
				{
					sfkt = 1;
					role_y -= speed_y;
					real_y -= speed_y;
				}
			}

			if (moveDeriction == 1) //向左行走对阻挡的判断
			{
				for (int i = 0; i < 6; i++) //管道判断
				{
					if ((real_x >= GD[i].end_x + 1 && real_x <= GD[i].end_x + 5 && real_y + roleHigh - 10 >= GD[i].zc_high))
						judgeOperate = 0;
				}

				for (int i = 0; i < 26; i++) //不可破坏的砖块的判断
				{
					if ((real_x >= BKPH[i].end_x + 1 && real_x <= BKPH[i].end_x + 5 && real_y + roleHigh - 10 >= BKPH[i].zc_high))
						judgeOperate = 0;
				}

				for (int i = 0; i < 12; i++) //空中撞击获得分数的砖块
				{
					if ((real_x >= BX[i].end_x + 1 && real_x <= BX[i].end_x + 5) && ((real_y >= BX[i].top_y && real_y <= BX[i].button_y) || (real_y + roleWidth >= BX[i].top_y && real_y + roleWidth <= BX[i].button_y)))
						judgeOperate = 0;
				}

				for (int i = 0; i < 28; i++) //空中普通砖块
				{
					if (((real_x >= ZK[i].end_x + 1 && real_x <= ZK[i].end_x + 5) && ((real_y >= ZK[i].top_y && real_y <= ZK[i].button_y) || (real_y + roleWidth >= ZK[i].top_y && real_y + roleWidth <= ZK[i].button_y))) && ZK[i].judge == 1)
						judgeOperate = 0;
				}
			}

			if (moveDeriction == 2) //向右行走对阻挡的判断
			{
				for (int i = 0; i < 6; i++) //管道判断
				{
					if ((real_x + roleWidth >= GD[i].start_x - 5 && real_x + roleWidth <= GD[i].start_x && real_y + roleHigh - 10 >= GD[i].zc_high))
						judgeOperate = 0;
				}

				for (int i = 0; i < 26; i++) //不可破坏的砖块的判断
				{
					if ((real_x + roleWidth >= BKPH[i].start_x - 5 && real_x + roleWidth <= BKPH[i].start_x && real_y + roleHigh - 10 >= BKPH[i].zc_high))
						judgeOperate = 0;
				}

				for (int i = 0; i < 12; i++) //空中撞击获得分数的砖块
				{
					if ((real_x + roleWidth >= BX[i].start_x - 5 && real_x + roleWidth <= BX[i].start_x) && ((real_y >= BX[i].top_y && real_y <= BX[i].button_y) || (real_y + roleWidth >= BX[i].top_y && real_y + roleWidth <= BX[i].button_y)))
					{
						judgeOperate = 0;
					}
				}

				for (int i = 0; i < 28; i++) //空中普通砖块
				{
					if (((real_x + roleWidth >= ZK[i].start_x - 5 && real_x + roleWidth <= ZK[i].start_x) && ((real_y >= ZK[i].top_y && real_y <= ZK[i].button_y) || (real_y + roleWidth >= ZK[i].top_y && real_y + roleWidth <= ZK[i].button_y))) && ZK[i].judge == 1)
						judgeOperate = 0;
				}
			}

			// 以下是反弹部分
			for (int i = 0; i < 12; i++) //空中撞击可获得分数的砖块
			{
				if ((real_x + roleWidth >= BX[i].start_x && real_x <= BX[i].end_x) && (real_y >= BX[i].top_y && real_y <= BX[i].button_y))
				{
					judgeJump = 0;
					BX[i].judge++;
				}

				if (BX[i].judge == 2)
				{
					fs += 10;
					mciSendString("close impactmusic", NULL, 0, NULL);
					mciSendString("open Music\\impact.mp3 alias impactmusic", NULL, 0, NULL);
					mciSendString("play impactmusic", NULL, 0, NULL); //仅播放一次音乐*/
				}

				if (BX[i].judge > 1)
					BX[i].judge++;
			}

			for (int i = 0; i < 28; i++) //空中撞击普通砖块
			{
				if (((real_x + roleWidth >= ZK[i].start_x && real_x <= ZK[i].end_x) && (real_y >= ZK[i].top_y && real_y <= ZK[i].button_y)) && ZK[i].judge == 1)
				{
					judgeJump = 0;
				}
			}

			for (int i = 0; i < 7; i++) //怪物移动
			{
				if (GS[i].judge == 1)
				{
					GS[i].start_x -= enemySpeed;
					GS[i].end_x -= enemySpeed;
					GS[i].xdjl -= enemySpeed;
					if (abs(GS[i].xdjl) >= GS[i].xdfw)
						enemySpeed *= -1;

					if (enemySpeed > 0)
						GS[i].enemywalk = 1;
					else
						GS[i].enemywalk = -1;

					if (GS[i].enemywalk == 1)
					{
						GS[i].hmtk_l++;
						if (GS[i].hmtk_l == 10)
						{
							if (GS[i].left == 0)
								GS[i].left = 1;
							else
								GS[i].left = 0;

							GS[i].hmtk_l = 0;
						}
					}

					if (GS[i].enemywalk == -1)
					{
						GS[i].hmtk_r++;
						if (GS[i].hmtk_r == 10)
						{
							if (GS[i].right == 0)
								GS[i].right = 1;
							else
								GS[i].right = 0;

							GS[i].hmtk_r = 0;
						}
					}
				}
			}

			for (int i = 0; i < 7; i++) //人物与怪兽接触判断
			{
				if (real_x + roleWidth >= GS[i].start_x - 5 && real_x + roleWidth <= GS[i].start_x && real_y >= flour && GS[i].judge == 1) //右接触
					role = 0;

				if (real_x >= GS[i].end_x - 5 && real_x <= GS[i].end_x && real_y >= flour && GS[i].judge) //左接触
					role = 0;
				//踩怪判断
				if (real_x + roleWidth >= GS[i].start_x - 5 && real_x <= GS[i].end_x - 8 && (real_y + roleWidth >= enemyFlour && real_y + roleWidth <= enemyFlour + 10) && GS[i].judge == 1)
				{
					fs += 10;
					judgeEnemyJump = 1;
					judgeJump = 1;
					GS[i].judge = 0;
					mciSendString("close killmusic", NULL, 0, NULL);
					mciSendString("open Music\\kill.mp3 alias killmusic", NULL, 0, NULL);
					mciSendString("play killmusic", NULL, 0, NULL); //仅播放一次音乐
				}
			}
		}

		if (map == 1) //隐藏地图
		{

			for (int i = 0; i < 2; i++)
			{
				if (role_x + roleWidth >= ycmap[i].start_x && role_x <= ycmap[i].end_x && role_y + roleHigh >= ycmap[i].zc_high + 10) //站在障碍物上
				{
					sfkt = 1;
					role_y -= speed_y;
					real_y -= speed_y;
				}

				if (moveDeriction == 1) //向左行走对阻挡的判断
				{
					if ((role_x >= ycmap[i].end_x + 1 && role_x <= ycmap[i].end_x + 5 && role_y + roleHigh - 10 >= ycmap[i].zc_high))
						judgeOperate = 0;
				}

				if (moveDeriction == 2) //向右行走对阻挡的判断
				{
					if ((role_x + roleWidth >= ycmap[i].start_x - 5 && role_x + roleWidth <= ycmap[i].start_x && role_y + roleHigh - 10 >= ycmap[i].zc_high))
						judgeOperate = 0;
					if (judgeGD == 2) //人物钻管道时位置更精确
					{
						role_y = 415;
						real_y = 415;
					}
				}
			}

			for (int i = 0; i < 19; i++) //人物获得金币的判断
			{
				if (YC[i].judge == 1)
				{
					if (role_x + roleWidth >= YC[i].start_x && role_x <= YC[i].end_x && role_y <= YC[i].button_y && role_y + roleHigh >= YC[i].top_y)
					{
						fs += 10;
						YC[i].judge = 0;
						mciSendString("close impactmusic", NULL, 0, NULL);
						mciSendString("open Music\\impact.mp3 alias impactmusic", NULL, 0, NULL);
						mciSendString("play impactmusic", NULL, 0, NULL); //仅播放一次音乐*/
					}
				}
			}
		}
	}
}

void updateWithInput() //与输入有关的更新
{
	if (GetAsyncKeyState(0x50) & 0x8000) //暂停按p
	{
		transparentimage(NULL, -20, 0, &img_pause);
		FlushBatchDraw();
		Sleep(100);
		while (!(GetAsyncKeyState(0x50) & 0x8000))
		{
			Sleep(10);
		}
		Sleep(100);
	}
	if (map == 0) //大背景下
	{

		if ((GetAsyncKeyState(0x44) & 0x8000)) //d
		{
			moveDeriction = 2;
			if (role_x >= Width / 2 && bk_x > Width - pictureWidth && judgeOperate == 1) //当人物横坐标过半屏
			{
				if (bk_x <= -6448) //旗的和背景的相对位置
					flag_x -= speed_x;

				bk_x -= speed_x; //画布动
				real_x += speed_x;
				hmtk1_r++;
				if (hmtk1_r == 3)
				{
					step_right++;
					hmtk1_r = 0;
				}
			}
			else if (role_x < pictureWidth && judgeOperate == 1) //人物横坐标未过半屏
			{
				role_x += speed_x;
				real_x += speed_x;
				hmtk1_r++;
				if (hmtk1_r == 3)
				{
					step_right++;
					hmtk1_r = 0;
				}
			}
		}
		if ((GetAsyncKeyState(0x41) & 0x8000)) //a
		{
			moveDeriction = 1;
			if (role_x <= Width / 2 && bk_x > 0 && judgeOperate == 1)
			{
				bk_x += speed_x;
				real_x -= speed_x;
				hmtk1_l++;
				if (hmtk1_l == 3)
				{
					step_left++;
					hmtk1_l = 0;
				}
			}
			else if (role_x > 0 && judgeOperate == 1)
			{
				role_x -= speed_x;
				real_x -= speed_x;
				hmtk1_l++;
				if (hmtk1_l == 3)
				{
					step_left++;
					hmtk1_l = 0;
				}
			}
		}
	}

	if (map == 1) //隐藏地图中人物控制
	{
		if ((GetAsyncKeyState(0x44) & 0x8000)) //d
		{
			moveDeriction = 2;
			if (role_x < ycmap[1].end_x - 40 && judgeOperate == 1)
			{
				role_x += speed_x;
				real_x += speed_x;
				hmtk1_r++;
				if (hmtk1_r == 3)
				{
					step_right++;
					hmtk1_r = 0;
				}
			}

			if (role_x + roleWidth >= 700 && role_y >= flour)
			{
				judgeGD = 2;
				mciSendString("close swmusic", NULL, 0, NULL);
				mciSendString("open Music\\进管道.mp3 alias swmusic", NULL, 0, NULL);
				mciSendString("play swmusic", NULL, 0, NULL); //仅播放一次音乐
			}
		}

		if ((GetAsyncKeyState(0x41) & 0x8000)) //a
		{
			moveDeriction = 1;
			if (role_x > 250 && judgeOperate == 1)
			{
				role_x -= speed_x;
				real_x -= speed_x;
				hmtk1_l++;
				if (hmtk1_l == 3)
				{
					step_left++;
					hmtk1_l = 0;
				}
			}
		}
	}
	if ((GetAsyncKeyState(0x57) & 0x8000) && judgekd == 1 && judgeGD == 0) //跳跃
	{
		if (role_y >= flour || sfkt == 1)
			judgeJump = 1;
		if (jumpHigh == 0 && judgeJump == 1)
		{
			mciSendString("close jpmusic", NULL, 0, NULL);
			mciSendString("open Music\\跳跃.mp3 alias jpmusic", NULL, 0, NULL);
			mciSendString("play jpmusic", NULL, 0, NULL); //仅播放一次音乐
		}
	}

	if ((GetAsyncKeyState(0x53) & 0x8000) && (real_x >= 2155 && real_x + roleWidth <= 2234) && sfkt == 1) //向下进入隐藏关卡
	{
		judgeGD = 1;
		mciSendString("close swmusic", NULL, 0, NULL);
		mciSendString("open Music\\进管道.mp3 alias swmusic", NULL, 0, NULL);
		mciSendString("play swmusic", NULL, 0, NULL); //仅播放一次音乐
	}

	if (step_right >= 9)
		step_right = 0;
	if (step_left >= 9)
		step_left = 0;
}
int iscontinue() //判断是否继续
{
	int c = 1;																		  //返回值
	while (!((GetAsyncKeyState(0x1B) & 0x8000) || (GetAsyncKeyState(0x20) & 0x8000))) //当输入不是ESC和SPACE时一直循环，输出continue图片
	{
		putimage(jx_x, jx_y, &img_jx);
		char str[50] = "score =";
		settextcolor(YELLOW);
		settextstyle(40, 0, "华文琥珀");
		outtextxy(400, 10, str);
		printtxt(550, 10, fs);
		FlushBatchDraw();
	}
	if ((GetAsyncKeyState(0x1B) & 0x8000)) //ESC退出
		c = 0;
	else if ((GetAsyncKeyState(0x20) & 0x8000)) //SPACE继续
		c = 1;
	return c;
}
void qbmd(void) //枪毙名单 制作人员名单
{
	int count2 = 0, count3 = 0; //用于计时
	int judge = 1;				//判断是否按过空格键
	while (count2 <= 500)
	{
		cleardevice();
		if ((GetAsyncKeyState(0x20) & 0x8000) && judge == 1)
		{
			count2 = 400;
			judge = 0;
			lyj_y = 50;
			bzf_y = 200;
			ss_y = 350;
		}
		putimage(lyj_x, lyj_y, &img_lyj);
		putimage(bzf_x, bzf_y, &img_bzf);
		putimage(ss_x, ss_y, &img_ss);
		FlushBatchDraw();
		count2++;
		if (count2 <= 400)
		{
			lyj_y--;
			bzf_y--;
			ss_y--;
		}
		Sleep(20);
	}
}
void thanks(void) //游戏结束感谢画面
{
	int count3 = 0;
	while (count3 <= 200)
	{
		cleardevice();
		putimage(233, 125, &img_thanks);
		FlushBatchDraw();
		count3++;
		Sleep(20);
	}
}
void dead(void) //时间结束死亡画面
{

	BeginBatchDraw();

	if (map == 0)
		putimage(bk_x, bk_y, &img_bk); //显示初始地图
	if (map == 1)
		putimage(0, 0, &img_bk2); //显示隐藏地图

	//if (judgeGD == 0 || hmtk_GD < 30)
	//RoleWalk(step_left, step_right, moveDeriction);  //显示人物动作

	transparentimage(NULL, role_x, role_y, &img_role_Death1);

	if (map == 0)
	{
		for (int i = 0; i < 12; i++) //当人物撞击过得分砖块后显示图片
		{
			if (BX[i].judge > 1)
			{
				putimage(BX[i].start_x + bk_x, BX[i].top_y - 1, &img_block);
			}
		}

		for (int i = 0; i < 7; i++) //怪物行走
		{
			if (GS[i].judge == 1)
			{
				if (GS[i].enemywalk == 1)
				{
					switch (GS[i].left)
					{
					case 0:
						transparentimage(NULL, GS[i].start_x + bk_x, enemyFlour, &img_enemyl1);
						break;
					case 1:
						transparentimage(NULL, GS[i].start_x + bk_x, enemyFlour, &img_enemyl2);
						break;
					default:
						break;
					}
				}
				else if (GS[i].enemywalk == -1)
				{
					switch (GS[i].right)
					{
					case 0:
						transparentimage(NULL, GS[i].start_x + bk_x, enemyFlour, &img_enemyr1);
						break;
					case 1:
						transparentimage(NULL, GS[i].start_x + bk_x, enemyFlour, &img_enemyr2);
						break;
					default:
						break;
					}
				}
			}
			else
			{
				count[i]++;
				if (count[i] <= 10)
					transparentimage(NULL, GS[i].start_x + bk_x, enemyFlour, &img_dead);
			}
		}

		for (int i = 0; i < 12; i++) //撞击得分砖块后出现金币
		{
			if (BX[i].judge > 1 && BX[i].judge < 20)
				transparentimage(NULL, BX[i].start_x + bk_x, BX[i].top_y - 65, &img_jb);
		}
	}

	if (map == 1)
	{
		for (int i = 0; i < 19; i++)
		{
			if (YC[i].judge == 1)
				transparentimage(NULL, YC[i].start_x, YC[i].top_y, &img_jb2);
		}
	}

	transparentimage(NULL, flag_x, flag_y, &img_flag);
	printtxt(900, 10, time / 100);
	printscore(50, 10);
	printtxt(200, 10, fs);
	setbkmode(TRANSPARENT);
	FlushBatchDraw();
}
int main(void)
{
	con = 1;  //初始化是否继续的参数
	EXIT = 1; //初始化exit

	while (con && EXIT)
	{
		startup();
		setbkmode(TRANSPARENT);
		EXIT = startmenu(); //开始界面
		while (ch && EXIT && time > 0)
		{
			show();
			updateWithoutInput();
			updateWithInput();
			usedtime++;
			time--;
			Sleep(10);
			cleardevice();
		}

		if (time <= 0 && EXIT) //时间到
		{
			mciSendString("close bkmusic", NULL, 0, NULL);
			mciSendString("close swmusic", NULL, 0, NULL);
			mciSendString("open Music\\死亡.mp3 alias swmusic", NULL, 0, NULL);
			mciSendString("play swmusic", NULL, 0, NULL); //仅播放一次音乐
			int a = 2;
			for (int i = 0; i <= 100; i++)
			{
				role_y += a; //人物位置变动
				dead();		 //时间结束死亡
				Sleep(20);   //帧率控制
			}
		}

		if (EXIT)
		{
			con = iscontinue(); //判断是否继续
			if (!con)
			{
				mciSendString("close bkmusic", NULL, 0, NULL);
				mciSendString("open Music\\exit.mp3 alias exitmusic", NULL, 0, NULL);
				mciSendString("play exitmusic", NULL, 0, NULL); //仅播放一次音乐
				Sleep(4000);
			}
		}
	}
	qbmd();   //进入制作人员名单
	thanks(); //感谢画面
	exit(0);
	return 0;
}