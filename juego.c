#include <stdio.h>
#include <stdlib.h>
//#include <dos.h>
#include <unistd.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>

#define FPS 30.0
#define CANTMOV 5
 	int aux = 0;
    int RL =0;
enum KEYS{
    UP,   // 0
    DOWN, // 1
    LEFT, // 2
    RIGHT, // 3
    X,
    P
};

int teclas[6] = {0, 0, 0, 0, 0, 0};
//***************************************************************************************************************************************************
//DEFINIMOS ESTRUCTURAS

typedef struct jugador {
    int x; // posicion x de la nave
    int y; // posicion y de la nave
    ALLEGRO_BITMAP *nave; // imagen a renderizar
   // algif_init();

} jugador_t;

typedef struct bala {
    int x; // posicion x de la nave
    int y; // posicion y de la nave
    ALLEGRO_BITMAP *bla; // imagen a renderizar
} bala_t;
typedef struct enemy{
    int x;
    int y;
    ALLEGRO_BITMAP *ene;

}enemy_t;
typedef struct fondo{
    int x;
    int y;
    ALLEGRO_BITMAP *fon;

}fondo_t;



//***************************************************************************************************************************************************
//DIBUJAMOS ESTRUCTURAS

// funcion ayuda que dibuja a nuestra navecita
void dibujarJugador(fondo_t *fond, jugador_t *jugador) {
    al_clear_to_color(al_map_rgb(0,0,0));//(51, 153, 255));
    al_draw_bitmap(jugador->nave, jugador->x, jugador->y, 0);
   
    //algif_load_animation("goku.gif",30,5);

}


//DIBUJAMOS LA BALA
void dibujarBala(fondo_t *fondo,bala_t *bala, jugador_t *jugador,enemy_t *denemigo,enemy_t *denemigo2,enemy_t *denemigo3,enemy_t *denemigo4,enemy_t *denemigo5) {
    al_clear_to_color(al_map_rgb(0,0,0));//(51, 153, 255));
    al_draw_bitmap(fondo->fon, fondo->x, fondo->y, 0);
    al_draw_bitmap(bala->bla, bala->x, bala->y, 0);
    al_draw_bitmap(denemigo->ene, denemigo->x, denemigo->y, 0);
    al_draw_bitmap(denemigo2->ene, denemigo2->x, denemigo2->y, 0);
    al_draw_bitmap(denemigo3->ene, denemigo3->x, denemigo3->y, 0);
    al_draw_bitmap(denemigo4->ene, denemigo4->x, denemigo4->y, 0);
    al_draw_bitmap(denemigo5->ene, denemigo5->x, denemigo5->y, 0);
     al_draw_bitmap(jugador->nave, jugador->x, jugador->y, 0);
  
    

}
//DIBUJAMOS ENEMIGOS
void dibujarEnemigos(fondo_t *fondo,enemy_t *denemigo,enemy_t *denemigo2,enemy_t *denemigo3,enemy_t *denemigo4,enemy_t *denemigo5,jugador_t *jugador){
    al_clear_to_color(al_map_rgb(0,0,0));
     al_draw_bitmap(fondo->fon, fondo->x, fondo->y, 0);
    al_draw_bitmap(denemigo->ene, denemigo->x, denemigo->y, 0);
    al_draw_bitmap(denemigo2->ene, denemigo2->x, denemigo2->y, 0);
    al_draw_bitmap(denemigo3->ene, denemigo3->x, denemigo3->y, 0);
    al_draw_bitmap(denemigo4->ene, denemigo4->x, denemigo4->y, 0);
    al_draw_bitmap(denemigo5->ene, denemigo5->x, denemigo5->y, 0);
    al_draw_bitmap(jugador->nave, jugador->x, jugador->y, 0);
    //al_draw_bitmap(shot->bla, shot->x, shot->y, 0);
   

}


//***************************************************************************************************************************************************
//MOVIMIENTOS UP DOWN RIGHT LEFT

void moverArriba(jugador_t *jugador) {
    // su codigo aqui
    if((*jugador).y>1&&(*jugador).y<(475-50+288-48)){//480-55=425///55size 5 distance
    (*jugador).y -= 10;
}else{
    (*jugador).y =1;
}

}

void moverAbajo(jugador_t *jugador) {
    // su codigo aqui
     if((*jugador).y>=1&&(*jugador).y<(475-56+288-48)){//480-61=419///56 size 5 distance
    (*jugador).y += 10;
    }//else{
        //(*jugador).y = 480-57;
    //}
}

void moverDerecha(jugador_t *jugador) {
    // su codigo aqui
    if((*jugador).x>=1&&(*jugador).x<(635-50+384)){//640-55=585///50 size 5 distance
    (*jugador).x += 10;
     }
}

void moverIzquierda(jugador_t *jugador) {
    // su codigo aqui
    if((*jugador).x>=5&&(*jugador).x<(650-50+384)){//640-40=600
    (*jugador).x -= 10;
}else{
    (*jugador).x=1;
}
}
//***************************************************************************************************************************************************


//MOVIMIENTOS EN 2 EJES

void moverArIz(jugador_t *jugador) {
    // su codigo aqui
    if(((*jugador).y>1&&(*jugador).y<(475-50+288-48)) && ((*jugador).x>=5&&(*jugador).x<(650-50+384))){//640-55=585///50 size 5 distance
    (*jugador).x -= 10;
    (*jugador).y -= 10;
     }else{
        jugador->y=1;
     }
}
void moverArRi(jugador_t *jugador){
    if(((*jugador).y>1&&(*jugador).y<(475-50+288-48))&&((*jugador).x>=1&&(*jugador).x<(635-50+384))){//480-55=425///55size 5 distance
    (*jugador).y -= 10;
    (*jugador).x += 10;
}else{
    (*jugador).y =1;
}
}

void moverAbRi(jugador_t *jugador) {
    // su codigo aqui
    if(((*jugador).y>=1&&(*jugador).y<(475-56+288-48))&&((*jugador).x>=5&&(*jugador).x<(650-50+384))){//640-55=585///50 size 5 distance
    (*jugador).x += 10;
    (*jugador).y += 10;
     }
}
void moverAbIz(jugador_t *jugador) {
    // su codigo aqui
    if(((*jugador).y>=1&&(*jugador).y<(475-56+288-48))&&((*jugador).x>=5&&(*jugador).x<(650-50+384))){//640-55=585///50 size 5 distance
    (*jugador).x -= 10;
    (*jugador).y += 10;
     }
}
//***************************************************************************************************************************************************



//MOVIMIENTO DE BALA
void moverBala(bala_t *bala) {
    // su codigo aqui
    //((*bala).y>1&&(*bala).y<(475-50)){//480-55=425///55size 5 distance
    (*bala).y -= 7;
    
    }
    void moverBaRI(bala_t *bala,jugador_t*jugador) {
    // su codigo aqui
    //((*bala).y>1&&(*bala).y<(475-50)){//480-55=425///55size 5 distance
        if((*jugador).x>=1&&(*jugador).x<(635-50+384)){//640-55=585///50 size 5 distance
    (*jugador).x += 1;
    (*bala).y -= 7;
     }
    }
    void moverBaLE(bala_t *bala,jugador_t*jugador) {
    // su codigo aqui
    //((*bala).y>1&&(*bala).y<(475-50)){//480-55=425///55size 5 distance
        if((*jugador).x>=1&&(*jugador).x<(635-50+384)){//640-55=585///50 size 5 distance
    (*jugador).x -= 1;
    (*bala).y -= 7;
     }
    }

void moverEnemigos1lvl1(enemy_t *movenemigo){
   	if(movenemigo->y<=1020-60){
		movenemigo->x+=1; 
	}
   	
}
void moverEnemigos2lvl1(enemy_t *movenemigo){
	if(movenemigo->y<=715-55){
		movenemigo->y+=1; 
	}
   		   
}
void moverEnemigos3lvl1(enemy_t *movenemigo){
	if (movenemigo->x>=2){
  		movenemigo->x-=1;		
	}
   	 	   
}
void moverEnemigos4lvl1(enemy_t *movenemigo){
	if (movenemigo->y>=2){
		movenemigo->y-=1; 	   
	}
   	
}








//***************************************************************************************************************************************************
//MAIN !!!

int main(int argc, char **argv) {
    // Nuestra pantalla
    ALLEGRO_DISPLAY *display = NULL;
    // Con esto podemos manejar eventos
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    // Timer para actulizar eventos
    ALLEGRO_TIMER *timer = NULL;


//***************************************************************************************************************************************************
//VALIDACIONES DE INICIALIZACIONES

    // Tratamos de inicializar allegro
    if(!al_init()) {
        fprintf(stderr, "%s\n", "No se pudo inicializar allegro 5");
        return -1;
    }

    // Creamos un nuevo display de 640x480 para empezar
    display = al_create_display(1024, 720);
    // Si no se pudo crear el display al_create_display devuelve false (0)
    if(!display) {
        fprintf(stderr, "%s\n", "No se pudo crear un display");
        return -1;
    }

    // Tratamos de agregar el addon de imagenes de allegro
    if(!al_init_image_addon()) {
        fprintf(stderr, "%s\n", "No se pudo inicializar el addon de imagenes");
        // tenemos que destruir el display que creamos
        al_destroy_display(display);
        return -1;
    }

    // Tratamos de instalar el teclado en allegro
    if(!al_install_keyboard()) {
        fprintf(stderr, "%s\n", "No se pudo instalar el teclado");
        // tenemos que destruir el display que creamos
        al_destroy_display(display);
        return -1;
    }
//***************************************************************************************************************************************************
//GENERAMOS WINDOWS DEL JUEGO

    // evitamos que se suspenda la computadora mientras esta el juego abierto
    al_inhibit_screensaver(1);
    // le ponemos un titulo a nuestro display
    al_set_window_title(display, "!!!!SPACE ATTACK!!!");
    // al principio queremos que tenga fondo negro
    al_clear_to_color(al_map_rgb(0, 0, 0));
    // hacemos que se muestre lo que dibujamos
    al_flip_display();

//***************************************************************************************************************************************************
//SE CREAN EVENTOS Y TIMER

    // creamos el timer
    timer = al_create_timer(1.0 / FPS);

    // Creamos los eventos del juego
    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

//***************************************************************************************************************************************************
//CREAMOS JUGADORES, BALAS, ENEMIGOS, FONDO.
     fondo_t *fond = (fondo_t *)malloc(sizeof(fondo_t));
    fond->fon = al_load_bitmap("fondo.png");
    fond->x =0;
    fond->y=0;

    enemy_t *enemy1 = (enemy_t *)malloc(sizeof(enemy_t));
    enemy1->ene = al_load_bitmap("Enemi.png");
    enemy1->x = 100;
    enemy1->y=100;

    enemy_t *enemy2 = (enemy_t *)malloc(sizeof(enemy_t));
    enemy2->ene = al_load_bitmap("Enemi.png");
    enemy2->x = 300;
    enemy2->y=100;

    enemy_t *enemy3 = (enemy_t *)malloc(sizeof(enemy_t));
    enemy3->ene = al_load_bitmap("Enemi.png");
    enemy3->x = 500;
    enemy3->y=100;

    enemy_t *enemy4 = (enemy_t *)malloc(sizeof(enemy_t));
    enemy4->ene = al_load_bitmap("Enemi.png");
    enemy4->x = 700;
    enemy4->y=100;
    enemy_t *enemy5 = (enemy_t *)malloc(sizeof(enemy_t));
    enemy5->ene = al_load_bitmap("Enemi.png");
    enemy5->x = 900;
    enemy5->y=100;


    if(!enemy1->ene && !enemy2->ene && !enemy3->ene && !enemy4->ene && !enemy5->ene) {
        fprintf(stderr, "%s\n", "No se pudo crear un display");
        al_destroy_display(display);
        al_destroy_event_queue(event_queue);
        al_destroy_timer(timer);
        return -1;
    }
    
        

    
    


    // Creamos un jugador (miren como se usa malloc :) )
    // e inicializamos su posicion (0, 0)
    jugador_t *player = (jugador_t *)malloc(sizeof(jugador_t));
    player->nave = al_load_bitmap("spacecraft1.png");
    player->x = 356-56;//300;640
    player->y = 470-50;//400;480

    // si la imagen de la nave no se pudo cargar
    if(!player->nave) {
        fprintf(stderr, "%s\n", "No se pudo crear un display");
        al_destroy_display(display);
        al_destroy_event_queue(event_queue);
        al_destroy_timer(timer);
        return -1;
    }

    bala_t *balas = (bala_t *)malloc(sizeof(bala_t));
    balas->bla = al_load_bitmap("bala.png");
    balas->x = player->x;//300;640
    balas->y = player->y;//400;480

     if(!balas->bla) {
        fprintf(stderr, "%s\n", "No se pudo crear un display");
        al_destroy_display(display);
        al_destroy_event_queue(event_queue);
        al_destroy_timer(timer);
        return -1;
    }

    
//***************************************************************************************************************************************************
//CREAMOS DEMAS CONDICIONES Y AL JUGADOR

    // dibujemos al jugador por primera vez
      dibujarEnemigos(fond,enemy1,enemy2,enemy3,enemy4,enemy5,player);

 
    //dibujarEnemigos(enemy1);
    //player->x = 240;
    //player->y = 240;

    // srand a un numero que tire el reloj
    srand(time(NULL));

    // comenzamos el timer
    al_start_timer(timer);

    // bandera para salir del juego se preciona escape
    int terminar = 0;
    int puntos = 0;
    // una variable que recibe eventos (?)
    ALLEGRO_EVENT ev;
//***************************************************************************************************************************************************
//WHILE QUE REVISA EVENTOS DOWN UP Y TIMER(ACCIONES)
    int enemis[5]={0,0,0,0,0};
    int lvl=0;
    // loop del juego
    while(!terminar) {
        if(enemis[0]==1&&enemis[1]==1&&enemis[2]==1&&enemis[3]==1&&enemis[4]==1){
            lvl = lvl+1;
            enemis[0]=0;
            enemis[0]=0;
            enemis[0]=0;
            enemis[0]=0;
            enemis[0]=0;
            enemy1->y = 100;
            enemy2->y = 100;
            enemy3->y = 100;
            enemy4->y = 100;
            enemy5->y = 100;

            if (lvl==3){
            enemy1->ene=al_load_bitmap("Enemi2.png");
            enemy2->ene=al_load_bitmap("Enemi2.png");
            enemy3->ene=al_load_bitmap("Enemi2.png");
            enemy4->ene=al_load_bitmap("Enemi2.png");
            enemy5->ene=al_load_bitmap("Enemi2.png");
            }else if (lvl>=6){
            enemy1->ene=al_load_bitmap("Enemi3.png");
            enemy2->ene=al_load_bitmap("Enemi3.png");
            enemy3->ene=al_load_bitmap("Enemi3.png");
            enemy4->ene=al_load_bitmap("Enemi3.png");
            enemy5->ene=al_load_bitmap("Enemi3.png");
            }else{
            enemy1->ene=al_load_bitmap("Enemi.png");
            enemy2->ene=al_load_bitmap("Enemi.png");
            enemy3->ene=al_load_bitmap("Enemi.png");
            enemy4->ene=al_load_bitmap("Enemi.png");
            enemy5->ene=al_load_bitmap("Enemi.png");
            }
            

        }
        if((balas->x <= enemy1->x+50)&&(balas->x+50 >= enemy1->x)&&(balas->y <=enemy1->y+56)&&(balas->y+56 <=enemy1->y)){
           // usleep(10);
          // enemy1->ene=al_load_bitmap("die.png");

           //delay(1000);
           //usleep(10);


            //al_destroy_bitmap(enemy1->ene);
            enemis[0]=1;
            puntos +=10;
            printf("Score: %d\n",puntos );
            balas->bla=al_load_bitmap("black.png");
          enemy1->ene=al_load_bitmap("black.png");
        }else if((balas->x <= enemy2->x+50)&&(balas->x+50 >= enemy2->x)&&(balas->y <=enemy2->y+56)&&(balas->y+56 <=enemy2->y)){
            balas->bla=al_load_bitmap("black.png");
          enemy2->ene=al_load_bitmap("black.png");
          enemis[1]=1;
           puntos +=10;
            printf("Score: %d\n",puntos );
        }
        else if((balas->x <= enemy3->x+50)&&(balas->x+50 >= enemy3->x)&&(balas->y <=enemy3->y+56)&&(balas->y+56 <=enemy3->y)){
            balas->bla=al_load_bitmap("black.png");
          enemy3->ene=al_load_bitmap("black.png");
          enemis[2]=1;
           puntos +=10;
            printf("Score: %d\n",puntos );
        }
        else if((balas->x <= enemy4->x+50)&&(balas->x+50 >= enemy4->x)&&(balas->y <=enemy4->y+56)&&(balas->y+56 <=enemy4->y)){
            balas->bla=al_load_bitmap("black.png");
          enemy4->ene=al_load_bitmap("black.png");
          enemis[3]=1;

        }
        else if((balas->x <= enemy5->x+50)&&(balas->x+50 >= enemy5->x)&&(balas->y <=enemy5->y+56)&&(balas->y+56 <=enemy5->y)){
            balas->bla=al_load_bitmap("black.png");
          enemy5->ene=al_load_bitmap("black.png");
          enemis[4]=1;
           puntos +=10;
            printf("Score: %d\n",puntos );

        }
            /*
        }
        }
        }else{*/
        //balas->bla=al_load_bitmap("bala.png");

        al_wait_for_event(event_queue, &ev);
        srand(time(NULL));
		int test=rand()%4;
		if(test == 1){
            
            moverEnemigos1lvl1(enemy5);
			moverEnemigos1lvl1(enemy2);
            moverEnemigos1lvl1(enemy4);
			moverEnemigos1lvl1(enemy1);
			moverEnemigos1lvl1(enemy3);
            
		}else if(test==2){
            moverEnemigos3lvl1(enemy4);
            moverEnemigos3lvl1(enemy5);
			moverEnemigos3lvl1(enemy2);
			moverEnemigos3lvl1(enemy1);
			moverEnemigos3lvl1(enemy3);
            
		}else{
            moverEnemigos2lvl1(enemy4);
            moverEnemigos2lvl1(enemy5);
			moverEnemigos2lvl1(enemy2);
			moverEnemigos2lvl1(enemy1);
			moverEnemigos2lvl1(enemy3);
            
		}
			
       
           //dibujarEnemigos(enemy1,player);
          
        // si el evento es key_up
            //********************************************************************************************************************************
            //EVENTO TECLA LEVANTADA/SIN PRECIONAR
        if(ev.type == ALLEGRO_EVENT_KEY_UP) {
            switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_ESCAPE:
                    // su codigo aqui
                terminar = true;
                teclas[P] = true;
                

                break;
               // case ALLEGRO_KEY_P:


               // break;
                case ALLEGRO_KEY_UP:
                player->nave = al_load_bitmap("spacecraft1.png");
                    // su codigo aqui
                teclas[UP] = false;
                teclas[P] = true;
              
                break;
                case ALLEGRO_KEY_DOWN:
                player->nave = al_load_bitmap("spacecraft1.png");
                    // su codigo aqui
                teclas[DOWN]= false;
                teclas[P] = true;
                
                break;
                case ALLEGRO_KEY_LEFT:
                    // su codigo aqui
                player->nave = al_load_bitmap("spacecraft1.png");
                teclas[LEFT]= false;
                teclas[P] = true;
                
                break;
                case ALLEGRO_KEY_RIGHT:
                    // su codigo aqui
                player->nave = al_load_bitmap("spacecraft1.png");
                teclas[RIGHT]= false;
                teclas[P] = true;
              
                break;

                case ALLEGRO_KEY_X:
                    // su codigo aqui
                player->nave = al_load_bitmap("spacecraft1.png");
                teclas[X]= false;
                teclas[P] = true;
                
                break;
                 //case ALLEGRO_KEY_X:
                /*player->nave = al_load_bitmap("spacecraft3.png");
                    // su codigo aqui
                teclas[X] = false;
                break;*/
            }
               
            //********************************************************************************************************************************
            //EVENTO TECLA ABAJO/PRECIONAR
        } else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    // su codigo aqui
                player->nave = al_load_bitmap("spacecraft1.png");
                teclas[UP] = true;
                teclas[P] = true;
            
                break;
                case ALLEGRO_KEY_DOWN:
                player->nave = al_load_bitmap("spacecraft1.png");
                    // su codigo aqui
                teclas[DOWN] = true;
               
               
                break;
                case ALLEGRO_KEY_LEFT:
                player->nave = al_load_bitmap("spacecraft2.png");
                    // su codigo aqui
                teclas[LEFT] = true;
               
               
                break;
                case ALLEGRO_KEY_RIGHT:
                player->nave = al_load_bitmap("spacecraft3.png");
                    // su codigo aqui
                teclas[RIGHT] = true;
              
             
                break;
                /*case ALLEGRO_KEY_X:
                player->nave = al_load_bitmap("spacecraft3.png");
                    // su codigo aqui
                teclas[X] = true;
                break;*/
                case ALLEGRO_KEY_X:
                    // su codigo aqui

                teclas[X]= true;
               
                
                balas->x = player->x;
                balas->y = player->y;
                break;
            }
            //********************************************************************************************************************************
            //EVENTO TIMER (ACCION DE TECLAS)            
        } else if(ev.type == ALLEGRO_EVENT_TIMER) {

                            //*****************************************************************************************
                        if(((enemy1->x>=player->x)&&(enemy1->x+50<=player->x))&&((enemy1->y>=player->y)&&(enemy1->y+53<=player->y))){
                        	player->nave=al_load_bitmap("spacecraft.png");
                            al_destroy_display(display);
                            al_destroy_event_queue(event_queue);
    					    al_destroy_timer(timer);
 					       return -1;
                        }
                        //TECLAS DOBLES
                        else if((teclas[UP]&&teclas[RIGHT])){
                            player->nave = al_load_bitmap("spacecraft4.png");
                            
                            moverArRi(player);
                            //moverEnemigos(enemy1);
                        }
                            

                        else if((teclas[UP]&&teclas[LEFT])){
                            player->nave = al_load_bitmap("spacecraft5.png");
                            
                            moverArIz(player);
                        
                        }
                       

                        else if((teclas[DOWN]&&teclas[RIGHT])){
                            player->nave = al_load_bitmap("spacecraft6.png");
                          
                            moverAbRi(player);
                       
                        }
                        
                         else if((teclas[DOWN]&&teclas[LEFT])){
                            player->nave = al_load_bitmap("spacecraft7.png");
                        
                            moverAbIz(player);
                 
                         }
                         else if(teclas[X]&&teclas[RIGHT]){
                            player->nave=al_load_bitmap("spacecraft3.png");
                            balas->bla=al_load_bitmap("bala1.png");
                            int b1 = 0;
                            while(balas->y>=0){

                               
                            dibujarBala(fond,balas, player,enemy1,enemy2,enemy3,enemy4,enemy5);
                            b1++;

                            moverBaRI(balas,player);
                            if (b1==1){
                                dibujarBala(fond,balas, player,enemy1,enemy2,enemy3,enemy4,enemy5);
                            b1++;
                            moverBaRI(balas,player);
                            }
                            al_flip_display();
                            }  

                         }
                         else if(teclas[X]&&teclas[LEFT]){
                            player->nave=al_load_bitmap("spacecraft3.png");
                            balas->bla=al_load_bitmap("bala1.png");
                            int b1 = 0;
                            while(balas->y>=0){

                               
                            dibujarBala(fond,balas, player,enemy1,enemy2,enemy3,enemy4,enemy5);
                            b1++;

                            moverBaLE(balas,player);
                            if (b1==1){
                                dibujarBala(fond,balas, player,enemy1,enemy2,enemy3,enemy4,enemy5);
                            b1++;
                            moverBaLE(balas,player);
                            }
                            al_flip_display();
                            }  

                         }
                            //*****************************************************************************************
                         //TECLAS SIMPLES


                        else if(teclas[UP]){
                            // su codigo aqui
                         
                            moverArriba(player);
                     
                        }

                        else if(teclas[DOWN]){
                            // su codigo aqui
                            //player->y += 10.0;
                             player->nave = al_load_bitmap("spacecraft8.png");
                         
                            moverAbajo(player);
                      
                        }

                        else if(teclas[LEFT]){
                            // su codigo aqui
                     
                            moverIzquierda(player);
                       
                        }
                        else if(teclas[RIGHT]){
                            // su codigo aqui
                          
                            moverDerecha(player);
                       
                        }
                        //*****************************************************************************************
                        //TECLA DISPARO

                        else if(teclas[X]){
                            balas->bla=al_load_bitmap("bala.png");
                            int b1 = 0;
                            while(balas->y>=0){

                               
                            dibujarBala(fond,balas, player,enemy1,enemy2,enemy3,enemy4,enemy5);
                            b1++;
                            moverBala(balas);
                           
                            if (b1==1){
                                dibujarBala(fond,balas, player,enemy1,enemy2,enemy3,enemy4,enemy5);
                            b1++;
                            moverBala(balas);
                         
                            }
                            al_flip_display();
                            }  

                         }


        }
        // dibujamos al jugador
        dibujarEnemigos(fond,enemy1,enemy2,enemy3,enemy4,enemy5,player);
       
        al_flip_display();

    }

//***************************************************************************************************************************************************
//DEPURAMOS MEMORIA
    // siemple hay que limpiar memoria
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    
    al_destroy_bitmap(balas->bla);
    al_destroy_bitmap(player->nave);
    al_destroy_timer(timer);
    free(player);
   
    free(balas);
    return 0;
}
