#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int i;

void gotoxy(int x, int y) {//좌표 
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void show_success() {
	for (i = 0; i < 4; i++) {
		if (i % 2 == 0) {
			printf("ooooo                                ooooo ooooo      ooo\n");
			printf("`888'                                `888' `888b.     `8'\n");
			printf(" 888          .ooooo.   .oooooooo     888   8 `88b.    8\n");
			printf(" 888         d88' `88b 888' `88b      888   8   `88b.  8\n");
			printf(" 888         888   888 888   888      888   8     `88b.8\n");
			printf(" 888       o 888   888 `88bod8P'      888   8       `888\n");
			printf("o888ooooood8 `Y8bod8P' `8oooooo.     o888o o8o        `8\n");
			printf("                       d*     YD\n");
			printf("                       *Y88888P\n");
			printf(" .oooooo..o\n");
			printf("d8P'    `Y8\n");
			printf("Y88bo.      oooo  oooo   .ooooo.   .ooooo.   .ooooo.   .oooo.o  .oooo.o\n");
			printf(" `*Y8888o.  *888  *888  d88' `*Y8 d88' **Y8 d88' `88b d88(  *8 d88(  *8\n");
			printf("    `''Y88b  888   888  888       888       888ooo888 `*Y88b.  `*Y88b.\n");
			printf("oo     .d8P  888   888  888  ` .o8 888   .o8 888    .o o.  )88b o.  )88b\n");
			printf("   8""88888P'   `V88V*V8P' `Y8bod8P' `Y8bod8P' `Y8bod8P' 8**888P' 8""888P'\n");
			Sleep(1000);
		}
		else {
			system("cls");
		}
	}
}

void show_welcome() {//초기화면 

	system("cls");
	gotoxy(0, 5);
	int i;
	for (i = 0; i < 3; i++) {
		gotoxy(0, 5);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i + 13);
		printf("    ww            ww                    CCCCCcc\n");
		printf("    ww            ww   EEEEEEE L       CC      OOO   MM    MM EEEEEE\n");
		printf("     ww    ww     ww   E       L      CC      O   O  MMM  MMM EE\n");
		printf("      ww  wwww   ww    EEEEEEE L      CC      O   O  MM MM MM EEEEEE\n");
		printf("       ww ww  ww ww    E       L       CC      OOO   MM    MM EE\n ");
		printf("        ww     ww     EEEEEEE LLLLLLL  CCCCCcc      MM    MM EEEEEE\n");
		//Sleep(1000);
	}
}

void show_fail() {
	printf("                          oooo$$$$$$$$$$$$oooo\n");
	printf("                      oo$$$$$$$$$$$$$$$$$$$$$$$$o\n");
	printf("                   oo$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o         o$   $$ o$\n");
	printf("   o $ oo        o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o       $$ $$ $$o$\n");
	printf("oo $ $  $      o$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$o       $$$o$$o$\n");
	printf("  $$$$$$o$     o$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$o    $$$$$$$$\n");
	printf("   $$$$$$$    $$$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("   $$$$$$$$$$$$$$$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$$$$$$      $$$\n");
	printf("     $$$""""$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     $$$\n");
	printf("   $$$   o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$      $$$o\n");
	printf("   o$$   *$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       $$$o\n");
	printf("   $$$  ***$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$***$$$$$$ooooo\n");
	printf("   o$$$oooo$$$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   o$$$$$$$$\n");
	printf("   $$$$$$$ $$$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     $$$$\n");
	printf("            $$$$     $$$$$$$$$$$$$$$$$$$$$$$$$$$$       o$$$\n");
	printf("        $$$o        $$$$$$$$$$$$$$$$$$*$$          $$$\n");
	printf("             $$$o           $$** $$$$$$               o$$$\n");
	printf("               **$$$$o      o$$$$$$o$$$$o        o$$$$\n");
	printf("                 **$$$$$oo       $$$$o$$$$$o   o$$$$  \n");
	printf("              ***$$$$$oooo  *$$$o$$$$$$$$$***\n");
	printf("                        ``**$$$$$$$oo*$$$$$$$$$$\n");
	printf("            Get OUT!!!                 $$$$$$$$$$$\n");
	printf("       Get OUT!!!                   $$$$$$$$$$$$\n");
	printf("            Get OUT!!!                    $$$$$$$$$$ \n");
	printf("            Get OUT!!!                        $$$*\n");

}

void input_success() {
	printf(" o8o                                         .        .oooooo.   oooo    oooo \n");
	printf(" `''                                       .o8       d8P'  `Y8b  `888   .8P'  \n");
	printf("oooo  ooo. .oo.   oo.ooooo.  oooo  oooo  .o888oo    888      888  888  d8'    \n");
	printf("`888  `888P'Y88b   888' `88b `888  `888    888      888      888  88888[      \n");
	printf(" 888   888   888   888   888  888   888    888      888      888  888`88b.\n");
	printf(" 888   888   888   888   888  888   888    888 .    `88b    d88'  888  `88b.  \n");
	printf("o888o o888o o888o  888bod8P'  `V88V'V8P'   888'     `Y8bood8P'  o888o  o888o\n");
	printf("				   888\n");
	printf("				  o888o\n\n");
	printf(" .oooooo..o\n");
	printf("d8P'    `Y8\n");
	printf("Y88bo.      oooo  oooo   .ooooo.   .ooooo.   .ooooo.   .oooo.o  .oooo.o\n");
	printf(" `*Y8888o.  *888  *888  d88' `*Y8 d88' **Y8 d88' `88b d88(  *8 d88(  *8\n");
	printf("    `''Y88b  888   888  888       888       888ooo888 `*Y88b.  `*Y88b.\n");
	printf("oo     .d8P  888   888  888   .o8 888   .o8 888    .o o.  )88b o.  )88b\n");
	printf("   8""88888P'   `V88V*V8P' `Y8bod8P' `Y8bod8P' `Y8bod8P' 8**888P' 8""888P'\n");
	Sleep(1500);
}