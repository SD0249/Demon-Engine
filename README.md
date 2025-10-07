# Demon-Engine
This Engine was built because I found exisiting solutions too abstract for learning. I wanted to understand everything from the game loop to the rendering pipeline. <br /> 
*Note: Faraday(Physics Engine) will be a plug in for this engine to use later <br /> <br />
@ Side Note_The Reason for the Name 'Demon'
*********************************************************************
## Table of Contents
[Window API](#window-api) <br />

[Application & Game Object](#application-&-game-object)
*********************************************************************
### Window API (Window Class / Device Context)
Editor Window, Inspector Window, Scene Window... They are all made up of various windows. To generate them, understanding the Windows Class and **wWinMain** Function is crucial.

**Device Context**(DC) is where information related to rendering(drawing) on the window goes. It is part of the Graphics Users Interface(GDI) and is a collection of GDI Objects. <br />
*********************************************************************
### Application & Game Object <br />
Application class instance is called **every frame** and manages the overall flow of the program(in this case, engine).

Game Object is a general class that supports the transformation of each object, and it represents all the objects you can place on a game scene/level.

- Challenge: How can multiple game object instances from one Game Object class move in different input systems? <br />

Option 1: Using Function Pointers / std::function <br />
```
#include <functional>
class GameObject {
// Have a function pointers as member of the class
private:
  std::function<void()> move_;
// Have a constructor take in the function pointer as an argument
public:
  MyClass(std::function<void()> move) : move_(std::move(move)) {}
  void executeMove() {
    if(move_) {
      move_();
    }
  }
}

void WASDMove() {
  // Do something
}

void arrowMove() {
  // Do something
}

int main() {
  GameObject obj1(WASDMove);
  GameObject obj2(arrowMove);

  obj1.executeMove();  // WASDMove() Executed
  obj2.executeMove();  // arrowMove() Executed

  return 0;
}
```
✅ Very simple, easy to assign Lamdas(inline, on-the-fly functions), free functions, or member functions <br />
✅ Great for "data-driven" behavior <br />
❌ Lose Type Saftey and Structure <br />
❌ Harder to have persistent state in input handler (Possible for Lamdas to capture state or functor objects though)

**Option 2: Using Inheritance / State Pattern** <br />
```
#include <memory>
// Abstract Base Class of Input
class InputState {
public:
  virtual void HandleInput(GameObject& obj) = 0;
  virtual ~InputState() = default;
};

// Implementations of the Base case
class WASDInput {
public:
  void HandleInput(GameObject& obj) override {
  // Write Code to handle Input
  }
};

class ArrowInput {
public:
  void HandleInput(GameObject& obj) override {
  // Write Code to handle Input
  }
};

class GameObject {
private:
  std::unique_ptr<InputState> inputState_;

public:
  GameObject(std::unique_ptr<InputState> inputState) : inputState_(std::move(inputState)) {}
  void Update() {
    inputState_->HandleInput(*this);
    // More of update logic!
  }
};

int main() {
  GameObject obj1(std::make_unique<WASDInput>());
  GameObject obj2(std::make_unique<ArrowInput>());

  obj1.Update();  // WASDInput's HandleInput is executed
  obj2.Update();  // ArrowInput's HandleInput is executed

  return 0;
}
```
✅ Clean Object Oriented Programming separation <br />
✅ Easier to Maintain complex Input systems <br />
✅ Each behavior can have its own internal state <br />
❌ Less flexible for quick changes or data-driven setups <br />

-> Chosen Option 2! (Hybrid might also be good, option 2 for setting up classes and mapping on the fly with Lamdas -> This makes it easy to load data from JSON)
- Reason: Easier to Update into Advanced Input detection system with usage of Lamdas or Functor Structs, making it more composable and configurable, while maintaining its decoupled structured aspect.
