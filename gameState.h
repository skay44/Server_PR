//
// Created by User on 31.05.2024.
//

#ifndef SERVER_GAMESTATE_H
#define SERVER_GAMESTATE_H

#include <time.h>
#include "vector.h"
#include "data.h"



void* gameplayLoop(void* params){
    GLP* a = (GLP*) params;
    vectorPlayerStateCreate(&players);      //informacje o graczach (vector graczy)
    vectorProjectileCreate(&projectiles);   //informacje o asteroidach (vector asteroidow)


    while(1){


    }
}

#endif //SERVER_GAMESTATE_H
