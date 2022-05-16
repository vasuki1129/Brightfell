#pragma once
#include <glm.hpp>
#include <ext.hpp>
#include <gtx/quaternion.hpp>
#include <common.hpp>
#include "Tickable.h"

class Camera : public Tickable
{


protected:
	bool bMoveRight = false;
	bool bMoveLeft = false;
	bool bMoveUp = false;
	bool bMoveDown = false;
	bool bMoveForward = false;
	bool bMoveBack = false;


public:
	glm::vec3 position;
	glm::quat rotation;
	float fov;

	glm::mat4 getMatrix();
	
	void setPosition(glm::vec3 newPos);

	void movePosition(glm::vec3 addPos);

	void setFov(float newFov);

	void logicTick(float dTime) override;


	void rotate(glm::vec3 amt);


	glm::vec3 getForwardVector();
	glm::vec3 getUpVector();
	glm::vec3 getRightVector();


	//movement hooks

	void HStartMoveRight();
	void HStopMoveRight();
	
	void HStartMoveLeft();
	void HStopMoveLeft();

	void HStartMoveUp();
	void HStopMoveUp();

	void HStartMoveDown();
	void HStopMoveDown();
	
	void HStartMoveForward();
	void HStopMoveForward();

	void HStartMoveBack();
	void HStopMoveBack();


};

