#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL.h>
#include <time.h>

int find_closest_manhattan(SDL_Point p, SDL_Point *arr, int arr_len){
    int closest = 0;
    int dist = 99999999;
    for (int i=0; i<arr_len; i++) {
        int curr_dist =abs(p.x-arr[i].x) + abs(p.y-arr[i].y);
        if ( curr_dist < dist){
            dist =  curr_dist;
            closest = i;
        }
        
    }
    return closest;
}

void voronoi(int point_count, int w, int h, SDL_Renderer *renderer){
    SDL_Point points[point_count];
    for (int i=0; i<point_count; i++){
        points[i].x = rand()%w;
        points[i].y = rand()%h;
    }

    int col=0;
    for (int i=0; i<w; i++){
        for (int j=0; j<h; j++) {
            SDL_Point p = {i,j};
            col = find_closest_manhattan(p, points, point_count);
            if (col == 0) {
                SDL_SetRenderDrawColor( renderer,0, 255, 255, 255);     //cyan
            }else if (col == 1) {
                SDL_SetRenderDrawColor( renderer,0, 0, 255, 255);       //blue
            }else if (col == 2) {
                SDL_SetRenderDrawColor( renderer,0, 255, 0, 255);       //green
            }else if (col == 3) {
                SDL_SetRenderDrawColor( renderer,255, 255, 0, 255);     //yellow
            }else if (col == 4) {   
                SDL_SetRenderDrawColor( renderer,128, 0, 128, 255);     //purple
            }else if (col == 5) {
                SDL_SetRenderDrawColor( renderer,74, 128, 77, 255);     //petrol green
            }else if (col == 6) {
                SDL_SetRenderDrawColor( renderer,255, 203, 219, 255);   //pink
            }else if (col == 7) {
                SDL_SetRenderDrawColor( renderer,165, 42, 42, 255);     //brown
            }else if (col == 8) {
                SDL_SetRenderDrawColor( renderer,238, 236, 223, 255);   //marble
            }else if (col == 9) {
                SDL_SetRenderDrawColor( renderer,255, 127, 0, 255);     //orange
            }else if (col == 10) {
                SDL_SetRenderDrawColor( renderer,255, 0, 0, 255);       //red
            }
            SDL_RenderDrawPoint(renderer, i, j);
        }

    }

}

int main(int argc, char **argv){

    srand(time(NULL));
    SDL_Init(SDL_INIT_EVERYTHING);
    int w,h,point_count;
    w = 1280; h = 720;
    point_count=11; //up to 10
    SDL_Window *window = SDL_CreateWindow(  "titleeeeee",
                                            SDL_WINDOWPOS_UNDEFINED,
                                            SDL_WINDOWPOS_UNDEFINED,
                                            w, h,
                                            0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255); //rgba
    SDL_RenderClear(renderer); //set background

    voronoi(point_count, w, h, renderer);
   /*
    for (int i=0; i<point_count; i++) { //some debugging
        SDL_SetRenderDrawColor( renderer,0, 0, 0, 255);
        SDL_RenderDrawPoint(renderer,points[i].x,points[i].y);
    }*/
    SDL_RenderPresent(renderer);


    SDL_Delay(50000); 
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}