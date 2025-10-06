# Demon-Engine
This Engine was built because I found exisiting solutions too abstract for learning. I wanted to understand everything from the game loop to the rendering pipeline. <br /> 
*Note: Faraday(Physics Engine) will be a plug in for this engine to use later <br /> <br />
@ Side Note_The Reason for the Name 'Demon'
*********************************************************************
## Window API (Window Class / Device Context)
Editor Window, Inspector Window, Scene Window... They are all made up of various windows. To generate them, understanding the Windows Class and **wWinMain** Function is crucial.

**Device Context**(DC) is where information related to rendering(drawing) on the window goes. It is part of the Graphics Users Interface(GDI) and is a collection of GDI Objects. <br />
*********************************************************************
## Application & Game Object <br />
Application class instance is called **every frame** and manages the overall flow of the program(in this case, engine).

Game Object is a general class that supports the transformation of each object, and it represents all the objects you can place on a game scene/level.

- Challenge: How can multiple game object instances from one Game Object class move in different input systems? <br />

Option 1: Using Function Pointers / std::function <br />
```
#include <functional>
class MyClass{
// Have a function pointers as member of the class
private:
  std::function<void()> action_;
// Have a constructor take in the function pointer as an argument
public:
  MyClass(std::function<void()> action) : action_(std::move(action))
  void executeAction() {
    if(action_) {
      action_();
    }
  }
}

void specificAction1() {
  // Do something
}

void specificAction2() {
  // Do something
}

int main() {
  MyClass obj1(specificAction1);
  MyClass obj2(specificAction2);

  obj1.executeAction();  
  obj2.executeAction();

  return 0;
}
```
✅ Very simple, easy to assign Lamdas(inline, on-the-fly functions), free functions, or member functions <br />
✅ Great for "data-driven" behavior <br />
❌ Lose Type Saftey and Structure <br />
❌ Harder to have persistent state in input handler (Possible for Lamdas to capture state or functor objects though)

Option 2: Using Inheritance / State Pattern <br />
✅ Clean Object Oriented Programming separation <br />
✅ Easier to Maintain complex Input systems <br />
✅ Each behavior can have its own internal state <br />
❌ Less flexible for quick changes or data-driven setups 
