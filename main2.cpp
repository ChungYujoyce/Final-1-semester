#include <stdio.h>
#include <allegro5/allegro.h>

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;

int main(int argc, char **argv)
{
   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_TIMER *timer = NULL;
   ALLEGRO_BITMAP *bouncer = NULL;
   float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
   float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
   bool redraw = true;

   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }

   if(!al_install_mouse()) {
      fprintf(stderr, "failed to initialize the mouse!\n");
      return -1;
   }

   timer = al_create_timer(1.0 / FPS);
   if(!timer) {
      fprintf(stderr, "failed to create timer!\n");
      return -1;
   }

   display = al_create_display(SCREEN_W, SCREEN_H);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      al_destroy_timer(timer);
      return -1;
   }

   bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
   if(!bouncer) {
      fprintf(stderr, "failed to create bouncer bitmap!\n");
      al_destroy_display(display);
      al_destroy_timer(timer);
      return -1;
   }

   al_set_target_bitmap(bouncer);

   al_clear_to_color(al_map_rgb(255, 0, 255));

   al_set_target_bitmap(al_get_backbuffer(display));

   event_queue = al_create_event_queue();
   if(!event_queue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_bitmap(bouncer);
      al_destroy_display(display);
      al_destroy_timer(timer);
      return -1;
   }

   al_register_event_source(event_queue, al_get_display_event_source(display));

   al_register_event_source(event_queue, al_get_timer_event_source(timer));

   al_register_event_source(event_queue, al_get_mouse_event_source());

   al_clear_to_color(al_map_rgb(0,0,0));

   al_flip_display();

   al_start_timer(timer);

   while(1)
   {
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);

      if(ev.type == ALLEGRO_EVENT_TIMER) {
         redraw = true;
      }
      else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         break;
      }
      else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
              ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {

         bouncer_x = ev.mouse.x;
         bouncer_y = ev.mouse.y;
      }
      else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
          break;
      }

      if(redraw && al_is_event_queue_empty(event_queue)) {
         redraw = false;

         al_clear_to_color(al_map_rgb(0,0,0));

         al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);

         al_flip_display();
      }
   }

   al_destroy_bitmap(bouncer);
   al_destroy_timer(timer);
   al_destroy_display(display);
   al_destroy_event_queue(event_queue);

   return 0;
}
if(window == 1){
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
            if(to_menu) {
                window = 2;
                if(to_game){
                    window = 3;
                }
                else if(to_options){
                    window = 5;
                }
                else if(to_exit){
                    window = 6;
                }

            }
            if(to_game)
            {
                window=3;
                character1.x = WIDTH / 2 - 500;
                character1.y = HEIGHT / 2 -200;
                character4.x = WIDTH / 2 - 500;
                character4.y = HEIGHT / 2 -200;
                character2.x = WIDTH / 2 - 170;
                character2.y = HEIGHT / 2 - 100;
                character3.x = WIDTH / 2 - 160;
                character3.y = HEIGHT / 2 - 110;
                character1.image_path = al_load_bitmap("Nick_Wilde_Pose_Render2.png");
                character4.image_path = al_load_bitmap("Nick_Wilde_Pose_Render.png");
                character2.image_path= al_load_bitmap("hopper2.png");
                character3.image_path = al_load_bitmap("hopper1.png");
                background = al_load_bitmap("backk.jpg");

                //Initialize Timer
                timer  = al_create_timer(1.0/3.0);
                timer2  = al_create_timer(1.0/2.5);
                al_register_event_source(event_queue, al_get_timer_event_source(timer)) ;
                al_register_event_source(event_queue, al_get_timer_event_source(timer2)) ;
                al_start_timer(timer);
                al_start_timer(timer2);
            }
        }
    }
    else if(window==2){
        background2 = al_load_bitmap("hopper2.png");
        al_draw_bitmap(background2, 0,0, 0);
    }
    else if(window==4){
        al_draw_bitmap(background4, 0,0, 0);
        background4 = al_load_bitmap("hopper2.png");
    }
    else if(window==5){
        al_draw_bitmap(background5, 0,0, 0);
        background5 = al_load_bitmap("hopper2.png");
    }
    else if(window==6){
        al_draw_bitmap(background6, 0,0, 0);
        background6 = al_load_bitmap("hopper2.png");
    }
    case ALLEGRO_KEY_ENTER:
                to_menu = true;
                break;
            /*case ALLEGRO_KEY_END:
                to_exit = true;
                break;
            case ALLEGRO_KEY_TAB:
                to_game = true;
                break;
            case ALLEGRO_KEY_ALT:
                to_options = true;
                break;*/
