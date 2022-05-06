#include <SDL2/SDL_pixels.h>
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
            SDL_Color color_arr[4] = {  {0,255,255,255},
                                        {0,0,255,255},
                                        {0,255,0,255},
                                        {255,255,0,255}};
            
            SDL_Point p = {i,j};
            col = find_closest_manhattan(p, points, point_count) % 4;
            SDL_SetRenderDrawColor(renderer, color_arr[col].r, color_arr[col].g, color_arr[col].b, color_arr[col].a);
            SDL_RenderDrawPoint(renderer, i, j);
        }

    }

}

int main(int argc, char **argv){

    srand(time(NULL));
    SDL_Init(SDL_INIT_EVERYTHING);
    int w,h,point_count;
    w = 1280; h = 720;
    point_count=16; //up to 4
    SDL_Window *window = SDL_CreateWindow(  "titleeeeee",
                                            SDL_WINDOWPOS_UNDEFINED,
                                            SDL_WINDOWPOS_UNDEFINED,
                                            w, h,
                                            0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255); //rgba
    SDL_RenderClear(renderer); //set background

    voronoi(point_count, w, h, renderer);
    SDL_RenderPresent(renderer);


    SDL_Delay(5000); 
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}