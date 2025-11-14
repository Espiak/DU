#include "drawing.h"
int obr = 0;
int pocet_schodov = 0;
int velkost;
int miesto_x;
int miesto_y;
int riadkov;
int stlpcov;


void ciara(int dlzka){

    for (int x = 1; x < dlzka; x++) {
        move_right();
        set_blue_color();
        draw_pixel();
        move_right();
    }
    move_to(2,1);
    for (int x = 1; x < dlzka; x++) {
        move_right();
        set_red_color();
        draw_pixel();
        move_right();
      
    }
}

void kvety(int velkost, int miesto_x,int miesto_y){
    




        move_to(miesto_x,miesto_y);
        move_down();
        set_red_color();
        draw_pixel();
        for (int b=1;b < (velkost/2)-1;b++)//stonka
        {
            move_down();
            set_green_color();
            draw_pixel();
           
        }
        move_to(miesto_x,miesto_y);
        for (int b=1;b < velkost/2;b++)//horna
        { 
            set_red_color();
            draw_pixel();
            move_up();
        }
   
        move_to(miesto_x,miesto_y);
        for (int b=1;b < velkost;b++)//prava
        {
            set_red_color();
            draw_pixel();
            move_right();
        }
    
        move_to(miesto_x,miesto_y);
        for (int b=1;b < velkost;b++)//lava
        {
            set_red_color();
            draw_pixel();
            move_left();
        }
    
        move_to(miesto_x,miesto_y);
        for (int b=1;b < velkost/2;b++)//lava horna
        {
            set_red_color();
            draw_pixel();
            move_left();
            move_up();
        }
    
        move_to(miesto_x,miesto_y);
        for (int b=1;b < velkost/2;b++)//prava horna
        {
            set_red_color();
            draw_pixel();
            move_right();
            move_up();
        }
    
        move_to(miesto_x,miesto_y);
        for (int b=1;b < velkost/2;b++)//prava dolna
        {
            set_red_color();
            draw_pixel();
            move_right();
            move_down();
        }
    
        move_to(miesto_x,miesto_y);
        for (int b=1;b < velkost/2;b++)//lava dolna
        {
            set_red_color();
            draw_pixel();
            move_left();
            move_down();
        }
    
        move_to(miesto_x,miesto_y);
        for (int b=1;b < velkost/2;b++)//lava lava dolna
        {
            set_red_color();
            draw_pixel();
            move_left();
            draw_pixel();
            move_left();
            move_down();
        }
       move_to(miesto_x,miesto_y);
        for (int b=1;b < velkost/2;b++)//prava prava dolna
        {
            set_red_color();
            draw_pixel();
            move_right();
            draw_pixel();
            move_right();
            move_down();
        }
    
        move_to(miesto_x,miesto_y);
        for (int b=1;b < velkost/2;b++)//lava lava horna
        {
            set_red_color();
            draw_pixel();
            move_left();
            draw_pixel();
            move_left();
            move_up();
        }
    
        move_to(miesto_x,miesto_y);
        for (int b=1;b < velkost/2;b++)//prava prava horna
        {  
        set_red_color();
            draw_pixel();
            move_right();
            draw_pixel();
            move_right();
            move_up();
        }
    
    move_to(miesto_x,miesto_y);
    set_black_color();
    draw_pixel();

}
void luka(){
    move_to(19,1);
   
   int riadkov = 10;
    stlpcov=2;

    for(int  l = 9 ;l < riadkov*17; l = l + 18){
        for(int k = 7;k < stlpcov*8;k = k + 8)
        {
        kvety(10,k,l); 
        }
    
    }
}

void schody(int pocet_schodov){

    for (int x = 1; x < pocet_schodov/2; x++) {
        set_blue_color();
        draw_pixel();
        move_down();
        draw_pixel();
        move_right();
    }
    for (int x = 1; x < pocet_schodov/2; x++) {
        set_green_color();
        draw_pixel();
        move_down();
        draw_pixel();
        move_right();
        move_down();
        
    }
}

void animacia(int farba,int smer, int kolko ){

    if(farba <= 1){
    set_white_color();
    }else if(farba >= 2){
     set_black_color();
    }
    if(smer == 1){
    for(int ok=1;ok < kolko;ok++){
        draw_pixel();
        move_down();
    }}else if(smer == 2){
    for(int ok=1;ok < kolko;ok++){
        draw_pixel();
        move_left();
        draw_pixel();
        move_left();
    }}else if(smer == 3){
    for(int ok=1;ok < kolko;ok++){
        draw_pixel();
        move_up();
    }}else if(smer == 4){
    for(int ok=1;ok < kolko;ok++){
        draw_pixel();
        move_right();
        draw_pixel();
        move_right();
    }}
}

void animacia_animacie(int m)
{       clear_screen();
       move_to(15,30);
    for(int ll=1; ll < 20;ll++)
    {
        animacia(1,m,ll);
        if((m==2)||(m==3)||(m==4))
        {
            m = m-1;
        }else if (m==1){
            m=4;
        }

    }
    animate_ms(500);
    
}

void rotacia_animacie(int second)
{
for(int neviem=1;neviem < second;neviem++) {
     clear_screen();

    
    animacia_animacie(neviem);
  
}
    
    
}
int main() {
scanf("%d", &obr);
    clear_screen();
  if(obr == 0){
      ciara(20);
  }else if(obr == 1){
      schody(15);
  }else if(obr == 2){
        kvety(10,10,20);
        kvety(15,10,55);
        kvety(10,16,35);
  }else if(obr == 3){
   luka();


  }else if(obr == 4){
   rotacia_animacie(5);

  }
  else{printf("neznamy obrazec");} 
    end_drawing();
    return 0;
}

