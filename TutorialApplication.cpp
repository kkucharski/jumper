/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/
	  Tutorial Framework
	  http://www.ogre3d.org/tikiwiki/
-----------------------------------------------------------------------------
*/

#include "TutorialApplication.h"

//-------------------------------------------------------------------------------------
TutorialApplication::TutorialApplication(void)
{
}
//-------------------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{
}

//-------------------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
	// create your scene here :)
	    Ogre::Entity* mechEntity = mSceneMgr->createEntity("Head", "ogrehead.mesh");
    mMechNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    mMechNode->attachObject(mechEntity);
    mechEntity->setCastShadows(true);

    mSceneMgr->setAmbientLight(Ogre::ColourValue(1.0, 1.0, 1.0));

    Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
    Ogre::MeshManager::getSingleton().createPlane("ground", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane, 200, 200, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);

    Ogre::Entity* entGround = mSceneMgr->createEntity("GroundEntity", "ground");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(entGround);
    entGround->setMaterialName("Examples/BumpyMetal");
    entGround->setCastShadows(false);

}

#ifdef __cplusplus
	extern "C" {
#endif

		int main(int argc, char *argv[])
		{
			// Create application object
			TutorialApplication app;

			try {
				app.go();
			} catch( Ogre::Exception& e ) {
				std::cerr << "An exception has occurred: " <<
					e.getFullDescription().c_str() << std::endl;
			}

			return 0;
		}

#ifdef __cplusplus
	}
#endif
