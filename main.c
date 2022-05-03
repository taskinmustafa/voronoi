#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL.h>

int find_closest4(int x, int y, SDL_Point *arr){
    int closest = 0;
    int dist = 99999999;
    for (int i=0; i<5; i++) {
        if ( abs(x-arr[i].x) + abs(y-arr[i].y) <dist){
            dist =  abs(x-arr[i].x) + abs(y-arr[i].y);
            closest = i;
        }
        
    }
    return closest;
}

int main(int argc, char **argv){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow(  "Başlııık",
                                            SDL_WINDOWPOS_UNDEFINED,
                                            SDL_WINDOWPOS_UNDEFINED,
                                            1280, 720,
                                            SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor( renderer,
                   0, 0, 0, //RGB
                   255);        //alfa
    SDL_RenderClear(renderer); //Arkaplan




    SDL_Point points[5];
    for (int i=0; i<5; i++){
        points[i].x = rand()%1280;
        points[i].y = rand()%720;
    }

    int col=0;
    for (int i=0; i<1280; i++){
        for (int j=0; j<720; j++) {
            col = find_closest4(i, j, points);
            if (col == 0) {
                SDL_SetRenderDrawColor( renderer,0, 255, 255, 255);
            }else if (col == 1) {
                SDL_SetRenderDrawColor( renderer,0, 0, 255, 255);   //mavi
            }else if (col == 2) {
                SDL_SetRenderDrawColor( renderer,0, 255, 0, 255);
            }else if (col == 3) {
                SDL_SetRenderDrawColor( renderer,255, 255, 0, 255);
            }
            
            else if (col == 4) {
                SDL_SetRenderDrawColor( renderer,128, 0, 128, 255); //mor
            }
            /*else if (col == 5) {
                SDL_SetRenderDrawColor( renderer,74, 128, 77, 255); //petrol yeşili
            }else if (col == 6) {
                SDL_SetRenderDrawColor( renderer,255, 203, 219, 255); //pembe
            }else if (col == 7) {
                SDL_SetRenderDrawColor( renderer,165, 42, 42, 255); //kahve rengi
            }else if (col == 8) {
                SDL_SetRenderDrawColor( renderer,238, 236, 223, 255); //mermer beyazı
            }else if (col == 9) {
                SDL_SetRenderDrawColor( renderer,255, 127, 0, 255); //turuncu
            }*/
            SDL_RenderDrawPoint(renderer, i, j);
        }

    }
    SDL_RenderPresent(renderer);
 
    SDL_Delay(50000);  //30 saniye çalışsın
    // pencereyi kapat
    SDL_DestroyWindow(window);

    // temizle
    SDL_Quit();
    return 0;
}