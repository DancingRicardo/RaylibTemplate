#pragma once

#include "raylib-include/raylib.h"
#include "Entity.hpp"
#include "InputHandler.hpp"
#include "AnimationHandler.hpp"
#include "StateMachines.hpp"
#include "Level.hpp"
#include "Audio.hpp"
#include "UI.hpp"
#include "non-library-includes/ElementalSword.hpp"

class Character : public Entity {
private:

	InputHandlerClass inputHandler;
	AnimationHandlerClass animationHandler;
	UI UIHandler;

	KeplerSocket weaponSocket;

	std::vector<Item*> inventory;
    Item* itemInHand;

	CharacterStates characterStateMachine;
	CollisionStates collisionState;

	//AudioController audio;

	Level* levelPtr;

	Rectangle collisionBoxTop;
	Rectangle collisionBoxBottom;
	Rectangle collisionBoxLeft;
	Rectangle collisionBoxRight;
	
	bool isInAir = true;

	bool collisionBottom = false;

	void bottomFloor();

	float gravityEquation();

	float G = 9.8;

	float terminalVelocity = 15;

	float inAirSpeed = 0.f;

	bool isJumping = false;

	char* textureName = "Character";

	Rectangle hitBox;

	Rectangle debugBox = { 500, 500, 900, 900 };

	void render();

	void jumpingCheck();

	void movingCheck();

	void gravity();

	void updateTimes();

	bool collisionCheck();

	bool newCollision();

	void renderUIOverlay();


public:

	Character();

	Character(HashTextureMap textureMapArg);

	Character(HashTextureMap textureMapArg,
		Level* levelPtrArg);

	void update();

	
	


};