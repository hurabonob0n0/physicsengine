#pragma once
#include <ctype.h>
#include <Windows.h>

#include "PxPhysicsAPI.h"

#include "../snippetvehiclecommon/SnippetVehicleSceneQuery.h"
#include "../snippetvehiclecommon/SnippetVehicleFilterShader.h"
#include "../snippetvehiclecommon/SnippetVehicleTireFriction.h"
#include "../snippetvehiclecommon/SnippetVehicleCreate.h"

#include "../snippetcommon/SnippetPrint.h"
#include "../snippetcommon/SnippetPVD.h"
#include "../snippetutils/SnippetUtils.h"

using namespace physx;
using namespace snippetvehicle;

class CMyPhysics
{
public:
	CMyPhysics() {};
	~CMyPhysics() {};


public:	
	PxDefaultAllocator		gAllocator;
	PxDefaultErrorCallback	gErrorCallback;

	PxFoundation* gFoundation = NULL;
	PxPhysics* gPhysics = NULL;

	PxDefaultCpuDispatcher* gDispatcher = NULL;
	PxScene* gScene = NULL;

	PxCooking* gCooking = NULL;

	PxMaterial* gMaterial = NULL;

	VehicleSceneQueryData* gVehicleSceneQueryData = NULL;
	PxBatchQuery* gBatchQuery = NULL;

	PxVehicleDrivableSurfaceToTireFrictionPairs* gFrictionPairs = NULL;

	PxRigidStatic* gGroundPlane = NULL;
	PxVehicleDriveTank* gTank = NULL;

	struct TankControlState {
		bool leftThrust = false;
		bool rightThrust = false;
		bool leftBrake = false;
		bool rightBrake = false;
	};

	TankControlState TCS{};

private:
	VehicleDesc InitTankDesc();
	void Initialize_Engine_and_Terrain();
	void Add_Actor_Tank();
};

