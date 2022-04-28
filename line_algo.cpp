#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
using namespace std;
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    int x1,y1,x2,y2,dx,dy,p,i,x,y,xi,yi,d;
    printf("Enter 1st point: ");
    scanf("%d%d", &x1,&y1);
    printf("Enter 2nd point: ");
    scanf("%d%d",&x2,&y2);
    dx=x2-x1;
    dy=y2-y1;
    p=2*dy-dx;
    if(abs(dy)<abs(dx))
	{
        if(x1>x2)
		{
            swap(x1,x2);
            swap(y1,y2);
        }
        dx=x2-x1;
        dy=y2-y1;
        yi=1;
        if(dy<0)
		{
            yi=-1;
            dy=-dy;
        }
        d=(2*dy)-dx;
        y=y1;
        for(x=x1;x<=x2;x++)
		{
            putpixel(x,y,GREEN);
            if(d>0)
			{
                y=y+yi;
                d=d+(2*(dy-dx));
            }
			else
			{
                d=d+(2*dy);
            }
        }
    }
		else
		{
            if(y1>y2)
			{
                swap(x1,x2);
                swap(y1,y2);
            }
            dx=x2-x1;
            dy=y2-y1;
            xi=1;
            if(dx<0)
			{
                xi=-1;
                dx=-dx;
            }
            d=(2*dx)-dy;
            x=x1;
            for(y=y1;y<=y2;y++)
			{
                putpixel(x,y,GREEN);
                if(d>0)
				{
                    x=x+xi;
                    d=d+(2*(dx-dy));
                }
				else
				{
                    d=d+(2*dx);
                }
            }
        }
    getch();
    closegraph();
}
