#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 13

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleParticles;
class ModulePlayer;
class ModuleFadeToBlack;
class ModuleCollision;
class Module;
class ModuleAudio;
class ModuleWelcome;
class ModuleLvl1;
class ModuleLvl2;
class ModuleGameOver;
class Enemy;




class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleCollision* collision;
	ModulePlayer* player;
	ModuleFadeToBlack* fade;
	ModuleParticles* particles;
	ModuleAudio* audio;
	ModuleLvl2* lvl2;
	ModuleLvl1* lvl1;
	ModuleGameOver* gameover;
	ModuleWelcome* welcome;
	bool stop_music;
	ModuleEnemies* enemies;

	




public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__