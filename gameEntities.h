//
// Created by User on 31.05.2024.
//

#ifndef SERVER_GAMEENTITIES_H
#define SERVER_GAMEENTITIES_H

#define PLAYER_CODE     0b10000001
#define PROJECTILE_CODE 0b10000010
#define ASTEROID_CODE   0b10000100
#define DELETUS_CODE    0b10001000
#define SCORE_CODE      0b10101001

#define PLAYER_SIZE 25
typedef struct _playerState {
    int connectionAddr;
    unsigned int playerID;
    char ifShoot;
    char keys;
    float posX;
    float posY;
    float speedX;
    float speedY;
    float rotation;
    float invincibility;
} playerState;

#define PROJECTILE_SIZE 15
typedef struct _projectile {
    unsigned int projectileID;
    float posX;
    float posY;
    float speedX;
    float speedY;
    float rotation;
    float lifetime;
} projectile;

#define ASTEROID_SIZE 12.5
typedef struct _asteroid {
    unsigned int asteroidID;
    char size;
    float posX;
    float posY;
    float speedX;
    float speedY;
    float rotation;
} asteroid;

//ramka pocisku i graczy
#pragma pack(push,1)
typedef struct _entityFrame {
    unsigned char header;     //kod okreslajacy co to za rodzaj ramki (0b1000001 - gracz, 0b10000010 - pocisk)
    unsigned int ID;
    float posX;
    float posY;
    float speedX;
    float speedY;
    float rotation;
} entityFrame;
#pragma pack(pop)

//asteroidy
#pragma pack(push,1)
typedef struct _asteroidFrame {
    unsigned char header;     //kod okreslajacy co to za rodzaj ramki (0b10000100 - asteroida)
    unsigned int ID;
    float posX;
    float posY;
    float speedX;
    float speedY;
    float rotation;
    char size;
} asteroidFrame;
#pragma pack(pop)

//przykladowa ramka zawierajaca informacje serwera do klientow
#pragma pack(push,1)
typedef struct _sendFrameSerwerInfo {
    unsigned char header;     //kod okreslajacy co to za rodzaj ramki (inne niz 0b1000001 oraz 0b10000010)
    unsigned char code;
} sendFrameSerwerInfo;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _sendScoreFrame {
    unsigned char header;     //kod okreslajacy co to za rodzaj ramki (inne niz 0b1000001 oraz 0b10000010)
    int score;
} sendScoreFrame;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _deletus {
    unsigned char header;       //kod okreslajacy co to za rodzaj ramki (inne niz 0b1000001 oraz 0b10001000)
    unsigned char toDelete;     //1- delete player 2- delete projectile 3- delete asteroid  4- delete you
    unsigned int id;           //id of element to delete
} deletus;
#pragma pack(pop)

//ramka odbierajaca informacje od serwera
#pragma pack(push,1)
typedef struct{
    unsigned char ID;
    unsigned char Shot:1;
    char KeyboardKeys;
    float XPosition;
    float YPosition;
    float XVelocity;
    float YVelocity;
    float angle;
    float XPositionShot;
    float YPositionShot;
    float XVelocityShot;
    float YVelocityShot;
} Frame;
#pragma pack(pop)

#endif //SERVER_GAMEENTITIES_H
