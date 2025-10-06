# Demon-Engine
This Engine was built because I found exisiting solutions too abstract for learning. I wanted to understand everything from the game loop to the rendering pipeline. <br /> <br />
*Note: Faraday(Physics Engine) will be a plug in for this engine to use later <br /> 
@ Side Note_The Reason for the Name 'Demon'
*********************************************************************
## Window API (Window Class / Device Context)
Editor Window, Inspector Window, Scene Window... They are all made up of various windows. To generate them, understanding the Windows Class and **wWinMain** Function is crucial.

**Device Context**(DC) is where information related to rendering(drawing) on the window goes. It is part of the Graphics Users Interface(GDI) and is a collection of GDI Objects. <br />
*********************************************************************
## Application & Game Object <br />
Application class instance is called **every frame** and manages the overall flow of the program(in this case, engine).

Game Object is a general class that supports the transformation of each object, and it represents all the objects you can place on a game scene/level.

- Challenge: How can different Game Objects move with different Input Systems? <br />

Option 1: Using Function Pointers / std::function <br />
✅ Very simple, easy to assign Lamdas(inline, on-the-fly functions), free functions, or member functions
✅ Great for "data-driven" behavior
❌ Lose Type Saftey and Structure
❌ Harder to have persistent state in input handler (Possible for Lamdas to capture state or functor objects though)

Option 2: Using Inheritance / State Pattern <br />
✅ Clean Object Oriented Programming separation
✅ Easier to Maintain complex Input systems 
✅ Each behavior can have its own internal state
❌ Less flexible for quick changes or data-driven setups 
