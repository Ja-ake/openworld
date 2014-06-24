openworld
=========
I'm making a game with the following class structure:

GameControl - The class that actually runs the game, with a while(!closed) // run the game loop.

State - A class that handles the state of the game, for example if the game is rendering the scene it would be in one state, and if it is rendering the menu, it would be in another.

ComponentManager - A class that manages all of the components of what is being done, for instance, the Scene class would contain a bunch of components handling the drawing of each tree, physics, the camera, etc. The manager will put them all together.

Component - A component of whatever is being done. A tree (and its rendering code) would be an example of a component of the scene. The camera would be another. The component does not necessarily have to be drawn, it could be handling something like physics (and would throw physics events to other components that need to move in a certain way). 

The GameControl class has its loop, which would call the update function on the current State (there are classes that inherit State and override the update function of State).

In the update function of the base class "State", it would take all of the active ComponentManagers and update them. There are classes that inherit the base class ComponentManager and override its update function.

Each ComponentManager would update each of the Components that it owns.

This is the organizational structure that I came up with to make the game scalable and changeable . If, for instance, I wanted to add multiplayer at some point, I would add a class that inherits the State that controls the gameplay called "MultiplayerGameState". This would just add a new ComponentManager that inherits the ComponentManager that controls the player and all of the living things that are moving around. Then, the MultiplayerGameState class would recieve the multiplayer messages coming in and add other player Components for the other players.
