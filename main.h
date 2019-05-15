
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "algif.h"
#define GAME_TERMINATE -1
int TM=0;
int KM=0;
const int WIDTH = 800;
const int HEIGHT = 600;
bool donee = false;
int ax = WIDTH / 2;
int ay = HEIGHT / 1.5;
const int maxFrame = 8;
int curFrame = 0;
int frameCount = 0;
int frameDelay = 5;
// character =algif_load_animation("
//
ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_BITMAP *image = NULL;
ALLEGRO_BITMAP *image2 = NULL;
ALLEGRO_BITMAP *image3 = NULL;
ALLEGRO_BITMAP *image4[maxFrame];
ALLEGRO_BITMAP *background = NULL;
ALLEGRO_BITMAP *background1 = NULL;
ALLEGRO_BITMAP *background2 = NULL;
ALLEGRO_BITMAP *background3 = NULL;
ALLEGRO_BITMAP *background4 = NULL;
ALLEGRO_BITMAP *background5 = NULL;
ALLEGRO_BITMAP *background6 = NULL;
ALLEGRO_BITMAP *background7 = NULL;
ALLEGRO_BITMAP *background8 = NULL;
ALLEGRO_BITMAP *background9 = NULL;
ALLEGRO_BITMAP *background10 = NULL;
ALLEGRO_BITMAP *loose = NULL;
ALLEGRO_BITMAP *winner = NULL;
ALLEGRO_BITMAP *re = NULL;
ALLEGRO_BITMAP *endd = NULL;
ALLEGRO_BITMAP *bone = NULL;
ALLEGRO_BITMAP *fish = NULL;
ALGIF_ANIMATION *gif1=NULL;
ALGIF_ANIMATION *gif2=NULL;
ALGIF_ANIMATION *gif3=NULL;
ALGIF_ANIMATION *gif4=NULL;
ALLEGRO_BITMAP *backgroundchange1 = NULL;
ALLEGRO_BITMAP *backgroundchange2 = NULL;
ALLEGRO_BITMAP *backgroundchange3 = NULL;
ALLEGRO_KEYBOARD_STATE keyState ;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_TIMER *timer2 = NULL;
ALLEGRO_TIMER *timer3=NULL;
ALLEGRO_SAMPLE *song=NULL;
ALLEGRO_SAMPLE *song1=NULL;
ALLEGRO_SAMPLE *song2=NULL;
ALLEGRO_SAMPLE *song3=NULL;
ALLEGRO_FONT *font = NULL;
ALLEGRO_BITMAP *T_M_1 = NULL;
ALLEGRO_BITMAP *T_M_2 = NULL;
ALLEGRO_BITMAP *T_M_3 = NULL;
ALLEGRO_BITMAP *T_M_4 = NULL;
ALLEGRO_BITMAP *T_M_5 = NULL;
ALLEGRO_BITMAP *T_M_6 = NULL;
const char *title = "Final Project 106062109";

int cnt=0;
typedef struct character
{
    int x;
    int y;
    ALLEGRO_BITMAP *image_path;
//ALGIF_ANIMATION *image_path;
}Character;
Character character1;
Character character2;
Character character3;
Character character4;
Character character5;
Character character6;
Character character7;
Character character8;
Character character9;
Character character10;

typedef struct weapon
{
    int x;
    int y;
    ALLEGRO_BITMAP *image_path;

}Weapon;
Weapon weapon1;
Weapon weapon2;
Weapon weapon3;
Weapon weapon4;


typedef struct gaming
{
   ALLEGRO_BITMAP *image_path;
}Gaming;
Gaming gaming1;
Gaming gaming2;
Gaming gaming3;

typedef struct a
{
    int x;
    int y;
   ALGIF_ANIMATION *image_path;
}A;
A a1;
A a2;

typedef struct b
{
    int x;
    int y;
   ALGIF_ANIMATION *image_path;
}B;
B b1;
B b2;

int imageWidth = 0;
int imageHeight = 0;
int draw = 0;
int done = 0;
int window = 1;
int count1=0;
int count2=0;
bool to_menu = false;
bool to_exit = false;
bool to_start =false;
bool to_options =false;
bool ture_1 = true, ture_2 =true;
void show_err_msg(int msg);
void game_init();
void game_begin();
int process_event();
int game_run();
int attack1=0;
int attack2=0;
int attack3=0;
int attack4=0;
int flag=0;
int Blood1,Blood2;
void game_destroy();
bool VOICE= false;
bool VOICE1= false;
bool VOICE2= false;
bool to_leopard= false;
bool to_sheep= false;
bool to_lion= false;
bool to_game_begin= false;
bool win= false;
bool game_over= false;
bool restart= false;
bool End= false;
bool super=false;
bool about=false;
bool backk=false;

void voice_(){
    al_stop_samples();
    al_play_sample(song1, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
    VOICE=false;
    return;
}
void voice_1(){
    al_stop_samples();
    al_play_sample(song2, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
    VOICE1=false;
    return;
}
void voice_2(){
    al_stop_samples();
    al_play_sample(song3, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
    VOICE2=false;
    return;
}
void play(){
                character1.x = WIDTH / 2 - 400;
                character1.y = HEIGHT / 2 -200;
                character4.x = WIDTH / 2 - 500;
                character4.y = HEIGHT / 2 -200;
                character2.x = WIDTH / 1.2 - 170;
                character2.y = HEIGHT / 2 - 130;
                character3.x = WIDTH / 1.2 - 160;
                character3.y = HEIGHT / 2 - 140;
                character2.image_path= al_load_bitmap("hopper3.png");
                character3.image_path = al_load_bitmap("hopper4.png");
                al_register_event_source(event_queue, al_get_timer_event_source(timer)) ;
                al_register_event_source(event_queue, al_get_timer_event_source(timer2)) ;
                al_start_timer(timer);
                al_start_timer(timer2);

}
void attack(){
        weapon1.x = character1.x;
        weapon1.y = character1.y+80;
        weapon2.x = character2.x;
        weapon2.y = character2.y+80;
        weapon3.x = character1.x;
        weapon3.y = character1.y+80;
        weapon4.x = character2.x;
        weapon4.y = character2.y+80;
}


void play_1(){
    if(cnt==1){
        al_draw_bitmap(backgroundchange1, 0,0, 0);
        if(ture_1)al_draw_bitmap(character1.image_path, character1.x, character1.y, 0);
        else al_draw_bitmap(character4.image_path, character1.x, character1.y, 0);
        //al_draw_bitmap(algif_get_bitmap(character4.image_path,al_get_time()), character1.x, character1.y, 0);
        if(ture_2)al_draw_bitmap(character2.image_path, character2.x, character2.y, 0);
        else al_draw_bitmap(character3.image_path, character2.x, character2.y, 0);
        }
        else if(cnt==2){
        al_draw_bitmap(backgroundchange2, 0,0, 0);
        if(ture_1)al_draw_bitmap(character1.image_path, character1.x, character1.y, 0);
        else al_draw_bitmap(character4.image_path, character1.x, character1.y, 0);
        if(ture_2)al_draw_bitmap(character2.image_path, character2.x, character2.y, 0);
        else al_draw_bitmap(character3.image_path, character2.x, character2.y, 0);
        }
        else if(cnt==3){
        al_draw_bitmap(backgroundchange3, 0,0, 0);
        if(ture_1)al_draw_bitmap(character1.image_path, character1.x, character1.y, 0);
        else al_draw_bitmap(character4.image_path, character1.x, character1.y, 0);
        if(ture_2)al_draw_bitmap(character2.image_path, character2.x, character2.y, 0);
        else al_draw_bitmap(character3.image_path, character2.x, character2.y, 0);
        }
        else{
        al_draw_bitmap(background, 0,0, 0);
        if(ture_1)al_draw_bitmap(character1.image_path, character1.x, character1.y, 0);
        else al_draw_bitmap(character4.image_path, character1.x, character1.y, 0);
        if(ture_2)al_draw_bitmap(character2.image_path, character2.x, character2.y, 0);
        else al_draw_bitmap(character3.image_path, character2.x, character2.y, 0);
        }
}
void play_2(){
        al_draw_filled_rectangle(20, 20, 360, 40, al_map_rgb(102, 255, 89));
        al_draw_filled_rectangle(20+Blood1, 20, 20, 40, al_map_rgb(230, 0, 0));
        al_draw_filled_rectangle(420, 20, 760, 40, al_map_rgb(102, 255, 89));
        al_draw_filled_rectangle(760-Blood2, 20, 760, 40, al_map_rgb(230, 0, 0));
        if(weapon1.x<=(character2.x+30)&&weapon1.x>=(character2.x-30)&&
           weapon1.y<=(character2.y+280)&&weapon1.y>=(character2.y-110))
        {
            Blood2+=20;
            weapon1.x=900;
            weapon1.y=100000000;
        }

        if(weapon2.x<=(character1.x+30)&&weapon2.x>=(character1.x-30)&&
           weapon2.y<=(character1.y+450)&&weapon2.y>=(character1.y))
        {

            Blood1+=20;
            weapon2.x=-100;
            weapon2.y=100000000;
        }
        if(20+Blood1==360) window=14;
        if(760-Blood2==420) window= 12;
        if(attack1>0){
            if(weapon1.x>800) {
                attack1=0;
                attack();
            }
            else if(attack1==1){
                weapon1.x++;
               attack1++;
              al_draw_bitmap(weapon1.image_path, weapon1.x, weapon1.y, 0);
            }
            else{
                weapon1.x++;
                al_draw_bitmap(weapon1.image_path, weapon1.x, weapon1.y, 0);
            }
        }
        if(attack2>0){
            if(weapon2.x<0) {
                weapon2.x--;
                attack2=0;
                attack();
            }
            else{
                attack2++;
                weapon2.x--;
                al_draw_bitmap(weapon2.image_path, weapon2.x, weapon2.y, 0);
            }
        }
}
int main(int argc, char *argv[]) {
    int msg = 0;

    game_init();
    game_begin();

    while (msg != GAME_TERMINATE) {
        msg = game_run();
        if (msg == GAME_TERMINATE)
            printf("Game Over\n");
    }

    game_destroy();
    return 0;
}

void show_err_msg(int msg) {
    fprintf(stderr, "unexpected msg: %d\n", msg);
    game_destroy();
    exit(9);
}

void game_init() {
    if (!al_init()) {
        show_err_msg(-7);
    }
    if(!al_install_audio()){
        fprintf(stderr, "failed to initialize audio!\n");
        show_err_msg(-6);
    }
    if(!al_init_acodec_addon()){
        fprintf(stderr, "failed to initialize audio codecs!\n");
        show_err_msg(-5);
    }
    if (!al_reserve_samples(1)){
        fprintf(stderr, "failed to reserve samples!\n");
        show_err_msg(-4);
    }
    if(!al_install_mouse()) {
       fprintf(stderr, "failed to initialize the mouse!\n");
        show_err_msg(-3);
   }
    // Create display
    display = al_create_display(WIDTH, HEIGHT);
    event_queue = al_create_event_queue();
    if (display == NULL || event_queue == NULL) {
        show_err_msg(-1);
    }
    // Initialize Allegro settings
    al_set_window_position(display, 0, 0);
    al_set_window_title(display, title);
    al_init_primitives_addon();
    al_install_keyboard();
    al_install_audio();
    al_init_image_addon();
    al_init_acodec_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    //al_install_mouse();

    // Register event
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());


}

void game_begin() {
    weapon1.image_path = al_load_bitmap("Bones-Transparent-Background.png");
    weapon2.image_path = al_load_bitmap("seafood-clipart-transparent-1.png");
    attack();
    // Load sound
        song = al_load_sample( "Epic Music.wav" );
        song1 = al_load_sample( "song1.wav" );
        song2 = al_load_sample( "song2.wav" );
        song3 = al_load_sample( "song3.wav" );
    if (!song){
        printf( "Audio clip sample not loaded!\n" );
        show_err_msg(-1);
    }
    background = al_load_bitmap("backk.jpg");

    // Loop the song until the display close
    timer  = al_create_timer(1.0/3.0);
    timer2  = al_create_timer(1.0/2.5);
    al_start_timer(timer);
    al_start_timer(timer2);
    al_play_sample(song, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
    al_flip_display();
    font = al_load_ttf_font("pirulen.ttf",24,0);
    background = al_load_bitmap("backk.jpg");
    background1 = al_load_bitmap("begin1.jpg");
    background2 = al_load_bitmap("rich_zootopia.jpeg");
    background3 = al_load_bitmap("fight.jpg");
    background4 = al_load_bitmap("waitselect.jpg");
    background5 = al_load_bitmap("Exit3.jpg");
    background6 = al_load_bitmap("selected.jpg");
    background7 = al_load_bitmap("game over.png");
    background8 = al_load_bitmap("winn.jpg");
    background9 = al_load_bitmap("Exit3.jpg");
    background10 = al_load_bitmap("The End Game.png");
    character1.image_path = al_load_bitmap("Nick_Wilde_Pose_Render2.png");
    image4[0] = al_load_bitmap("fliegt w0000.bmp");
	image4[1] = al_load_bitmap("fliegt w0001.bmp");
	image4[2] = al_load_bitmap("fliegt w0002.bmp");
	image4[3] = al_load_bitmap("fliegt w0003.bmp");
	image4[4] = al_load_bitmap("fliegt w0004.bmp");
	image4[5] = al_load_bitmap("fliegt w0005.bmp");
	image4[6] = al_load_bitmap("fliegt w0006.bmp");
	image4[7] = al_load_bitmap("fliegt w0007.bmp");
    re = al_load_bitmap("PauseRestart.png");
    a1.image_path = algif_load_animation("111164000.gif");
    character2.image_path= al_load_bitmap("hopper3.png");
    character3.image_path = al_load_bitmap("hopper4.png");
    character5.image_path = al_load_bitmap("Untitled.png");
    character6.image_path= al_load_bitmap("hat.png");
    character7.image_path = al_load_bitmap("hatt.png");
    a1.image_path = algif_load_animation("111187000.gif");
    a2.image_path = algif_load_animation("10090918125e50ce6528643f3c.gif");
    //b1.image_path = algif_load_animation("111187000.gif");
    //b2.image_path = algif_load_animation("111130000.gif");
    gif1 = algif_load_animation("source.gif");

    backgroundchange1 = al_load_bitmap("backchange1.jpg");
    backgroundchange2 = al_load_bitmap("backchange2.jpg");
    backgroundchange3 = al_load_bitmap("backchange3.jpg");
    al_draw_bitmap(background1,0,0,0);
    al_draw_text(font, al_map_rgb(255,0,0), WIDTH/1.35, HEIGHT/3 , ALLEGRO_ALIGN_CENTRE, " Press");
    al_draw_text(font, al_map_rgb(255,0,0), WIDTH/1.35, HEIGHT/2 , ALLEGRO_ALIGN_CENTRE, "  'Enter'");
    al_draw_text(font, al_map_rgb(255,0,0), WIDTH/1.35, HEIGHT/1.5 , ALLEGRO_ALIGN_CENTRE, "  To start");
    al_draw_rectangle(510, 290, 700, 340, al_map_rgb(255, 0, 0), 0);

    al_flip_display();
}

int process_event(){

    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);

    if(event.timer.source == timer){
        ture_1 = !ture_1 ;
    }
    if(event.timer.source == timer2){
        ture_2 = !ture_2 ;
    }
    // Keyboard
    if(event.type == ALLEGRO_EVENT_KEY_DOWN)
    {

        switch(event.keyboard.keycode)
        {
            case ALLEGRO_KEY_J:
                character2.y -= 200;
                break;
            case ALLEGRO_KEY_F:
                character1.y -= 200;
                break;
        }

    }
    if(event.type == ALLEGRO_EVENT_KEY_UP)
    {
        switch(event.keyboard.keycode)
        {
            case ALLEGRO_KEY_0:
                about=true;
                break;
            case ALLEGRO_KEY_1:
                about=false;
                break;
            case ALLEGRO_KEY_Q:
                weapon1.y=character1.y+80;
                weapon1.x=character1.x;
                attack1++;
                break;
            case ALLEGRO_KEY_P:
                weapon2.y=character2.y+80;
                weapon2.x=character2.x;
                attack2++;
                break;
            // P1 control
            case ALLEGRO_KEY_W:
                character1.y -= 30;
                break;
            case ALLEGRO_KEY_S:
                character1.y += 30;
                break;
            case ALLEGRO_KEY_A:
                character1.x -= 30;
                break;
            case ALLEGRO_KEY_D:
                character1.x += 30;
                break;
            // P2 control
            case ALLEGRO_KEY_UP:
                character2.y -= 30;
                break;
            case ALLEGRO_KEY_DOWN:
                character2.y += 30;
                break;
            case ALLEGRO_KEY_RIGHT:
                character2.x += 30;
                break;
            case ALLEGRO_KEY_LEFT:
                character2.x -= 30;
                break;
            case ALLEGRO_KEY_J:
                character2.y += 200;
                break;
            case ALLEGRO_KEY_F:
                character1.y += 200;
                break;

            // For Start Menu
            case ALLEGRO_KEY_ENTER:
                to_menu = true;
                break;
            case ALLEGRO_KEY_ALT:
                to_exit = true;
                break;
            case ALLEGRO_KEY_TAB:
                to_options = true;
                break;
            case ALLEGRO_KEY_ESCAPE:
                to_start = true;
                break;

            case ALLEGRO_KEY_G:
                End = true;
                break;
            case ALLEGRO_KEY_H:
                restart = true;
                break;
            case ALLEGRO_KEY_F1:
                super = true;
                break;


        }
    }
    else if(event.type == ALLEGRO_EVENT_MOUSE_AXES ||
        event.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
        printf("(%d %d)\n",event.mouse.x,event.mouse.y);

        //else hat1=false;

    }
    else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
        if (event.mouse.button == 1){
            if(to_start)
                cnt++;
            if(event.mouse.x>=59&&event.mouse.x<=745&&event.mouse.y>=480&&event.mouse.y<=610) //to game begin
            if(to_leopard || to_lion || to_sheep)
                    to_game_begin=true;
            if(event.mouse.x>=30&&event.mouse.x<=210&&event.mouse.y>=485&&event.mouse.y<=547)//leopard
                    to_leopard=true;
            if(event.mouse.x>=278&&event.mouse.x<=467&&event.mouse.y>=486&&event.mouse.y<=545)//lion
                  to_lion=true;
            if(event.mouse.x>=570&&event.mouse.x<=748&&event.mouse.y>=486&&event.mouse.y<=548) //sheep
                 to_sheep=true;
            if(to_game_begin==true||to_start==true)
                if(cnt==1) VOICE=true;
                if(cnt==2) VOICE1=true;
                if(cnt==3) VOICE2=true;
                if(cnt>3) cnt=1;

        }
        else if (event.mouse.button == 2) {
            cnt--;
            if(cnt==1) VOICE=true;
            if(cnt==2) VOICE1=true;
            if(cnt==3) VOICE2=true;
            if(cnt<1) cnt=3;

        }

    }
    else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        return GAME_TERMINATE;
    if(VOICE) voice_();
    if(VOICE1) voice_1();
    if(VOICE2) voice_2();

    return 0;
}

int game_run() {
    int error = 0;
    // First window(Menu)
    if(window == 1){
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
        }
        if(to_menu)  window = 2;

    }
    else if(window==2){
        al_draw_bitmap(background2, 0,0, 0);
        //TODO: line below.
        al_draw_bitmap(algif_get_bitmap(gif1,al_get_time()), weapon1.x, weapon1.y, 0);
        ///if(hat1) al_draw_bitmap(character6.image_path, 117,355, 0);
        if(TM==0){
                    al_draw_bitmap(image4[0], 443,458, 0), KM++;
                    if(KM==8) TM++, KM=0;
                }
                else if(TM==1){
                    al_draw_bitmap(image4[1],443,458, 0), KM++;
                    if(KM==8) TM++, KM=0;
                }
                else if(TM==2){
                    al_draw_bitmap(image4[2],443,458, 0), KM++;
                    if(KM==8) TM++, KM=0;
                }
                else if(TM==3){
                    al_draw_bitmap(image4[3],443,458, 0), KM++;
                    if(KM==8) TM++, KM=0;
                }
                else if(TM==4){
                    al_draw_bitmap(image4[4],443,458, 0), KM++;
                    if(KM==8) TM++, KM=0;
                }
                else if(TM==5){
                    al_draw_bitmap(image4[5],443,458, 0), KM++;
                    if(KM==8) TM=0, KM=0;
                }
                else if(TM==6){
                    al_draw_bitmap(image4[6],443,458, 0), KM++;
                    if(KM==8) TM=0, KM=0;
                }
                else if(TM==7){
                    al_draw_bitmap(image4[7],443,458, 0), KM++;
                    if(KM==8) TM=0, KM=0;
                }
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
        }

            if(to_start){

                window = 3;
                if(to_leopard){
                 character1.image_path = al_load_bitmap("LEOPARD1.png");
                 character4.image_path = al_load_bitmap("leopard2.png");
                }
                else if(to_lion){
                    character1.image_path = al_load_bitmap("LION1.png");
                    character4.image_path = al_load_bitmap("LION2.png");
                }
                else if(to_sheep){
                  character1.image_path = al_load_bitmap("SHEEP1.png");
                  character4.image_path = al_load_bitmap("SHEEP2.png");
                }
                else{
                  character1.image_path = al_load_bitmap("Nick_Wilde_Pose_Render2.png");
                  character4.image_path = al_load_bitmap("Nick_Wilde_Pose_Render.png");
                }
                play();
                play_1();
                al_register_event_source(event_queue, al_get_timer_event_source(timer)) ;
                al_register_event_source(event_queue, al_get_timer_event_source(timer2)) ;
                if(win) window = 4;
                if(game_over) window = 12;
            }
        if(to_exit)
            window = 5;
        if(to_options)
            window = 6;
        if(about) al_draw_bitmap(character5.image_path, character1.x, character1.y, 0);

        al_flip_display();
    }
    else if(window == 3){
        //play();
        play_1();
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
        }
        //al_draw_bitmap(algif_get_bitmap(a1.image_path,al_get_time()), weapon1.x, weapon1.y, 0);
        al_draw_filled_rectangle(20, 20, 360, 40, al_map_rgb(102, 255, 89));
        al_draw_filled_rectangle(20+Blood1, 20, 20, 40, al_map_rgb(230, 0, 0));
        al_draw_filled_rectangle(420, 20, 760, 40, al_map_rgb(102, 255, 89));
        al_draw_filled_rectangle(760-Blood2, 20, 760, 40, al_map_rgb(230, 0, 0));
        if(weapon1.x<=(character2.x+30)&&weapon1.x>=(character2.x-30)&&
           weapon1.y<=(character2.y+280)&&weapon1.y>=(character2.y-110))
        {
            Blood2+=20;
            weapon1.x=900;
            weapon1.y=100000000;
        }

        if(weapon2.x<=(character1.x+30)&&weapon2.x>=(character1.x-30)&&
           weapon2.y<=(character1.y+450)&&weapon2.y>=(character1.y-110))
        {
            printf("a");
            Blood1+=20;
            weapon2.x=-100;
            weapon2.y=100000000;
        }
        if(20+Blood1==360) window=14;
        if(760-Blood2==420) window= 12;
        if(attack1>0){
            if(weapon1.x>800) {
                attack1=0;
                attack();
            }
            else if(attack1==1){
                weapon1.x++;
                attack1++;
                al_draw_bitmap(weapon1.image_path, weapon1.x, weapon1.y, 0);
            }
            else{
                weapon1.x++;
                al_draw_bitmap(weapon1.image_path, weapon1.x, weapon1.y, 0);
            }
        }
        if(attack2>0){
            if(weapon2.x<0) {
                attack2=0;
                attack();
            }
            else if(attack2==1){
                weapon2.x--;
                attack2++;
                al_draw_bitmap(weapon2.image_path, weapon2.x, weapon2.y, 0);
            }
            else{
                //attack2++;
                weapon2.x--;
                al_draw_bitmap(weapon2.image_path, weapon2.x, weapon2.y, 0);
            }
        }

        /*if(super) {
            weapon1.image_path = al_load_bitmap("Punishment-ffviii-squall.png");
            super=false;
            //if()
            Blood2+=80;
            if(760-Blood2<=420) window= 12;
        }*/
        switch(super){
        case true:weapon3.image_path = al_load_bitmap("Punishment-ffviii-squall.png");
            Blood2+=80;
            if(760-Blood2<=420) window= 12;
            break;
        case false:weapon1.image_path = al_load_bitmap("Bones-Transparent-Background.png");
            Blood2+=20;
            if(760-Blood2==420) window= 12;
            break;

        }

        al_flip_display();
    }
    else if(window==4){ //game win
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
        }
        al_draw_bitmap(winner, 0,0, 0);
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
    }
    else if(window==5){ //exit
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
        }
        al_draw_bitmap(background5, 0,0, 0);

        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
    }
    else if(window==6){//option
        if (!al_is_event_queue_empty(event_queue)){
            error = process_event();
        }
        al_draw_bitmap(background4, 0,0, 0);
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
        if(to_leopard==true||to_lion==true||to_sheep==true)
            window=7;

    }
    else if(window==7){
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
        }
        al_draw_bitmap(background6, 0,0, 0);
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
        if(to_game_begin){
                window=3;
                character1.x = WIDTH / 2 - 500;
                character1.y = HEIGHT / 2 -200;
                character4.x = WIDTH / 2 - 500;
                character4.y = HEIGHT / 2 -200;
                character2.x = WIDTH / 1.2 - 170;
                character2.y = HEIGHT / 2 - 130;
                character3.x = WIDTH / 1.2 - 160;
                character3.y = HEIGHT / 2 - 140;
            if(to_leopard){
                 character1.image_path = al_load_bitmap("LEOPARD1.png");
                 character4.image_path = al_load_bitmap("leopard2.png");
                 play_2();
                }
                else if(to_lion){
                    character1.image_path = al_load_bitmap("LION1.png");
                    character4.image_path = al_load_bitmap("LION2.png");
                    play_2();
                }
                else if(to_sheep){
                  character1.image_path = al_load_bitmap("SHEEP1.png");
                  character4.image_path = al_load_bitmap("SHEEP2.png");
                  play_2();
                }
                else{
                  character1.image_path = al_load_bitmap("Nick_Wilde_Pose_Render2.png");
                  character4.image_path = al_load_bitmap("Nick_Wilde_Pose_Render.png");
                  play_2();
                }
            al_register_event_source(event_queue, al_get_timer_event_source(timer)) ;
            al_register_event_source(event_queue, al_get_timer_event_source(timer2)) ;
        }

    }
    else if(window==12){ //game over
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
        }
        if(restart){
            Blood1=0,Blood2=0;
           play_2();
           game_over=false;
           restart = false;
           window = 2;
        }
        if(End) window=13;
        al_draw_bitmap(background7, 0,0, 0);
        gaming1.image_path = al_load_bitmap("PauseRestart.png");
        al_draw_bitmap(gaming1.image_path, 450,400, 0);
        gaming2.image_path = al_load_bitmap("press end.png");
        al_draw_bitmap(gaming2.image_path, 20,400, 0);
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));

    }
    else if(window==13){ //End
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
        }
        al_draw_bitmap(background10, 0,0, 0);
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
    }
    else if(window==14){ //win
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
        }
        if(restart){
            Blood1=0,Blood2=0;
           play_2();
           game_over=false;
           restart = false;
           window = 2;
        }
        if(End) window=13;
        al_draw_bitmap(background8, 0,0, 0);
        gaming1.image_path = al_load_bitmap("PauseRestart.png");
        al_draw_bitmap(gaming1.image_path, 450,400, 0);
        gaming2.image_path = al_load_bitmap("press end.png");
        al_draw_bitmap(gaming2.image_path, 20,400, 0);
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
    }
    return error;
}

void game_destroy() {
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_timer(timer2);
    for(int i = 0; i < maxFrame; i++)
    al_destroy_bitmap(image4[i]);
    al_destroy_bitmap(image);
    al_destroy_sample(song);

}


