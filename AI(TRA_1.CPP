#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
  
int  checkpoint=220;
void light(int,int);

int mid(int i) {
	i=i/10;
	i=i%10;
	return i;
}

void car(int i, int midy ,int color,int k) {
	setcolor(WHITE);
	line(0, getmaxy()/2 + 37, getmaxx(), getmaxy()/2 + 37);
	line(checkpoint+120,getmaxy()/2 + 37, checkpoint+120,getmaxy()-100);
		/* body of the car */
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	line(0 + i, midy + 23, 0 + i, midy);
	line(0 + i, midy, 20 + i, midy);
	line(20 + i, midy, 40 + i, midy - 20);
	line(40 + i, midy - 20, 80 + i, midy - 20);
	line(80 + i, midy - 20, 100 + i, midy);
	line(100 + i, midy, 120 + i, midy);
	line(120 + i, midy, 120 + i, midy + 23);
	line(0 + i, midy + 23, 18 + i, midy + 23);
	arc(30 + i, midy + 23, 0, 180, 12);
	line(42 + i, midy + 23, 78 + i, midy + 23);
	arc(90 + i, midy + 23, 0, 180, 12);
	line(102 + i, midy + 23, 120 + i, midy + 23);
	line(28 + i, midy, 43 + i, midy - 15);
	line(43 + i, midy - 15, 57 + i, midy - 15);
	line(57 + i, midy - 15, 57 + i, midy);
	line(57 + i, midy, 28 + i, midy);
	line(62 + i, midy - 15, 77 + i, midy - 15);
	line(77 + i, midy - 15, 92 + i, midy);
	line(92 + i, midy, 62 + i, midy);
	line(62 + i, midy, 62 + i, midy - 15);
	floodfill(5 + i, midy + 22, YELLOW);
	setcolor(DARKGRAY);

	/* draw wheels of the car */
	if (i % 2 == 0) {
		setfillstyle(SLASH_FILL, DARKGRAY);
	} 
	else {
		setfillstyle(BKSLASH_FILL, DARKGRAY);
	}

	circle(30 + i, midy + 25, 9);
	circle(90 + i, midy + 25, 9);
	floodfill(30 + i, midy + 25, DARKGRAY);
	floodfill(90 + i, midy + 25, DARKGRAY);
	light(k,color);
	delay(100);
	cleardevice();
}

void light(int i,int color)	{
	int x,y;
	setcolor(DARKGRAY);
	char str[5];
	setfillstyle(SOLID_FILL, DARKGRAY);
	rectangle(300, 5, 350, 95);
	floodfill(310, 50, DARKGRAY);

	/* make place for signals */
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	circle(325,20 , 13);
	floodfill(325, 20, BLACK);
	circle(325, 80, 13);
	floodfill(325, 80, BLACK);

	if(color == LIGHTRED)
		y = 20;
	else
		y = 80;

	x = 325;
	/* clear the signal-to rewrite timer */
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	circle(x, y, 13);
	floodfill(x, y, BLACK);


	/* turn on the given signal(color) */
	setcolor(color);
	setfillstyle(SOLID_FILL, color);
	circle(x, y, 13);
	floodfill(x, y, color);
		/* print the counter inside signal */
	setcolor(BLACK);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	moveto(x-4, y-9);
	sprintf(str, "%d",9-mid(i));
	outtext(str);
}

int main()
{
	int gdriver = DETECT, gmode, err;
	int i,temp , l=0, t=0, k=0, color;
	/* initialize graphic mode */
	initgraph(&gdriver, &gmode, "C:/TURBOC3/BGI");
	while(!kbhit())	{
		cleardevice();
		temp=0;
		if(l%2==0)	{
			l=1;
			color=LIGHTRED;
		}
		else	{
			l=0;
			color=GREEN;
		}


		for (i = t; i<t+100+temp; i++, k++)	{
	/* draw a white road */
			if(i==checkpoint && color==LIGHTRED)	{
				temp=(100-mid(i)*10);
				for(k=i;k<temp+i;k++)	
					car(i,getmaxy()/2,color,k);
				l=0;
				color=GREEN;
				temp=100-temp;
			}
			else
				car(i,getmaxy()/2,color,k);
		}
		t=i;
	}

	getch();
	/* deallocate memory allocated for graphic screen */
	closegraph();
	return 0;
}
