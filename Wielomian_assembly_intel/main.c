#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <unistd.h>

const int SCREEN_W = 512;
const int SCREEN_H = 512;
long BITMAP_W = 512;
long BITMAP_H = 512;
double A= 1.0;
double B= 0.0;
double C= -1.0;
double D= 0.0;
double S= 0.09;

void update_map(ALLEGRO_BITMAP* wielomian, ALLEGRO_DISPLAY *display){
    al_draw_bitmap(wielomian,0,0,ALLEGRO_FLIP_VERTICAL);                                                  // wrzuć nasza bitmape na ekran
    al_flip_display();                                                                                  // allegro tworzy dwa bufory jeden ktory aktulanie wyswitla
                                                                                                        // i jeden w ktorym mozmey zpaisywac ta funckja je zamienia
}


extern void editWielomian(unsigned char* bitmap,long BITMAP_W, long BITMAP_H,double S,double A,double B,double C,double D); //nasza funkcja w asemblerze uwzana uwaga kolejnosci współczyników


int main(int argc,char **argv){
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_BITMAP *wielomian = NULL;
    ALLEGRO_LOCKED_REGION *locked = NULL;


    unsigned char* data;                                                                                // wskaznik na pierwszy piksel w bitmapie

    if(!al_init()) {                                                                                    // Inicjalizacja bilioteki Allegro
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    display = al_create_display(SCREEN_W, SCREEN_H);                                                    // Utworzenie okna do wyswietlania
    if(!display) {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }

    wielomian = al_create_bitmap(BITMAP_W, BITMAP_H);                                                     // Tworzymy bitmape o zadanych parametrach
    if(!wielomian) {
        fprintf(stderr, "failed to create bitmap!\n");
        al_destroy_display(display);
        return -1;
    }


    if(!al_install_keyboard()) {                                                                        // Wlaczamy obsluge myszki i klawiatury
      fprintf(stderr, "failed to initialize the keyboard!\n");
      return -1;
    }
    if(!al_install_mouse()) {
      fprintf(stderr, "failed to initialize the mouse!\n");
      return -1;
    }

    event_queue = al_create_event_queue();                                                              // Stworzenie kolejki obsługi zdarzeń
	if(!event_queue) {
        fprintf(stderr, "failed to create event_queue!\n");
        al_destroy_display(display);
        return -1;
   }

// Umieszczenie eventow w kolejce ktora sotowrzylsimy ianczej nie bylyby obslugiwane
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));

// Utowrzenie ekranu startowego bez kolejkowania eventow
	locked = al_lock_bitmap(wielomian, ALLEGRO_PIXEL_FORMAT_BGR_888, ALLEGRO_LOCK_READWRITE);             // Lokujemy sobie bitmape aby moc w niej pisac/czytac/rysowac
	if(locked == NULL) exit(0);
    data = locked->data;                                                                                // data - wskaznik na pierwszy piksel bitmapy
    editWielomian(data,BITMAP_W, BITMAP_H,S,A,B,C,D);
	al_unlock_bitmap(wielomian);
  while(1){

    update_map(wielomian,display);                                                                    // Zaaktualizuj bitmape
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);
      if(ev.type == ALLEGRO_EVENT_KEY_DOWN){

    switch(ev.keyboard.keycode){

        case ALLEGRO_KEY_P:
        locked = al_lock_bitmap(wielomian, ALLEGRO_PIXEL_FORMAT_BGR_888, ALLEGRO_LOCK_READWRITE);             // Lokujemy sobie bitmape aby moc w niej pisac/czytac/rysowac
          printf("Podaj nowe wspolczyniki\n");
          scanf("%lf %lf %lf %lf",&A,&B,&C,&D);
          if(locked == NULL) exit(0);

          data = locked->data;
          editWielomian(data,BITMAP_W, BITMAP_H,S,A,B,C,D);
          al_unlock_bitmap(wielomian);

              break;


        case ALLEGRO_KEY_ESCAPE:
                al_destroy_display(display);
                exit(1);
                break;
    }

}


      if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){

        wielomian = al_create_bitmap(BITMAP_W, BITMAP_H);                                                     // Tworzymy bitmape o zadanych parametrach
        if(!wielomian) {
            fprintf(stderr, "failed to create bitmap!\n");
            al_destroy_display(display);
            return -1;
        }
          if(S<0.0015) S=0.00158;
          if(S>0.45) S=0.44;
          if(ev.mouse.button == 1){

            locked = al_lock_bitmap(wielomian, ALLEGRO_PIXEL_FORMAT_BGR_888, ALLEGRO_LOCK_READWRITE);	// Lokujemy sobie bitmape aby moc w niej pisac/czytac/rysowac
            S =S+ 0.0002;
            printf("%f\n",S );
            if(locked == NULL) exit(0);

            data = locked->data;                                                                    // data - wskaznik na pierwszy piksel bitmapy
                editWielomian(data, BITMAP_W, BITMAP_H,S,A,B,C,D);
            al_unlock_bitmap(wielomian);                                                              // Odbolkowujemy bitmape dla systemu
          }

          if(ev.mouse.button == 2){

                  locked = al_lock_bitmap(wielomian, ALLEGRO_PIXEL_FORMAT_BGR_888, ALLEGRO_LOCK_READWRITE);
                    S = S - 0.0002;
                    printf("%f\n",S );

            if(locked == NULL) exit(0);

              data = locked->data;
                  editWielomian(data, BITMAP_W, BITMAP_H,S,A,B,C,D);
            al_unlock_bitmap(wielomian);
          }
      }

      if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
              al_destroy_display(display);
              exit(1);
      }
}



    return 0;
}
