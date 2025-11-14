#include <stdio.h>

int main()
{

int a, s, d, f, g, h, b,  y= 0;	
int x = 4000;
printf("zadaj hodnotu bankoviek:");
scanf("%d", &x);


printf("\n cislo %d(x)/5000 je %d(a) a zv. %d(y)",x ,a = x / 5000,y = x % 5000); x = y;
printf("\n cislo %d(x)/2000 je %d(s) a zv. %d(y)",x ,s = x / 2000,y = x % 2000); x = y;
printf("\n cislo %d(x)/1000 je %d(d) a zv. %d(y)",x ,d = x / 1000,y = x % 1000); x = y;
printf("\n cislo %d(x)/500 je %d(f) a zv. %d(y)",x ,f = x / 500,y = x % 500); x = y;
printf("\n cislo %d(x)/200 je %d(g) a zv. %d(y)",x ,g = x / 200,y = x % 200); x = y;
printf("\n cislo %d(x)/100 je %d(h) a zv. %d(y)",x ,h = x / 100,y = x % 100); x = y;


	printf("\n\n Bankovka 5000: %dx",a);
	printf("\n Bankovka 2000: %dx",s);
	printf("\n Bankovka 1000: %dx",d);
	printf("\n Bankovka 500: %dx",f);
	printf("\n Bankovka 200: %dx",g);
	printf("\n Bankovka 100: %dx\n",h);
	return 0;
}
