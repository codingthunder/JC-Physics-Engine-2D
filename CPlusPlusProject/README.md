# Overview

UPDATE: I'll likely be moving this .readme to the front page of the git and generally restructuring the project in general.

This project is a simplistic, unoptimized 2D physics engine, still  being updated. The Engine is capable of simulating the interactions between Rigidbodies with Circular colliders. These Entities are presently displayed using the SFML rendering tool (link below). I used that same tool to track the mouse position and accelerate objects toward it.

There's more math in this program than I could reasonably cover in a README. However, I will try to cover the general points and provide resources at the bottom of the file. I think it is worth mentioning that I am neither a physicist nor a mathematician. Much of my implementation was done through intuition, spending way too many hours scrawling in a notebook and staring at desmos graphing calculator to figure out algorithms. I avoided getting help or using external libraries because I wanted to really understand what I was working with.

## The Physics

Initially, the engine did not account for the surface angle of the circles when they impacted. Because of that, the circles would change momentum based only on the momentum of the other objects, which looked strange when objects did not hit head-on.

To address that, I used a combination of some basic Linear Algebra and Trigonometry to calculate both the direction colliders should go after a collision as well as how much momentum should be transferred during the collision. Because I transferred momentum between objects--not velocity--objects with greater mass easily moved objects with smaller mass aside.

When being acted upon to move, rather than directly manipulate an objects' velocity, I decided to manipulate its acceleration. I chose to do this because if I directly manipulated velocity, objects would be able to change directions instantly, which I didn't want. To simulate air resistance and other forces, I created acceleration in the opposite direction of the object's momentum and made it proportionate to the object's momentum. In other words, the faster you went, the higher your deceleration. By manipulating an object's resistance and acceleration, you can adjust an object's top speed.

### Some Notes
At present, there is a bug in the engine. When multiple circles collide sequentially, it will sometimes cause a drastic change in momentum and circles will rocket off into the distance. I had meant to fix this bug before turning in this module. However, because I have fallen ill, I have not had the mental faculties to finish that task. The original commit does not have this issue--it is related to my changes that account for angle of collision.

## The Code
I chose to use C++ for this project for a few reasons. At the start of the semester, I wanted to become familiar with Unreal Engine. To that end, I wanted to get used to C++. It's been years since I last touched the language, and I was never particularly comfortable with it. More advanced C++ users may notice that I chose to use normal pointers instead of smart pointers. This was a conscious decision to help me become more comfortable with memory management. For future program and/or updates, I will likely transition to Smart Pointers for the added safety.

### The Update Loop
In visualizing how I would build this engine, I looked to Unity Engine as an example. I avoided directly reading any documentation from Unity and relied on my previous knowledge of how game engines work. Because I've mostly used Unity, that resulted in several similarities. Because my goal was to just build the physics engine, not a game engine, the Update Loop is primarily implemented as a wrapper to allow input into and output from the Physics Engine.

In future updates, I would want to implement a more extensible and robust system. I would want to put the Physics Engine on its own thread and implement multicast delegate functions that allow individual behaviors to easily decouple from one another. As it stands, the physics, rendering, and input all occur on the same thread, which drastically decreases the performance of the engine.

### Writing the Physics Engine
The Physics engine uses parameters attached to Rigidbodies and Colliders to make changes to their position, momentum, etc.

A lot of the math behind my implementation was explained the the Physics section, but I want to discuss the data structures I used for the engine. I am actually quite frustrated that I didn't get to finish implementing this element of the program. If I hadn't gotten sick, I likely could have implemented better data structures with time to spare.

At present, the Physics engine calculates collisions by going down a list of tracked Colliders and checking if their bounds overlap. Just to get the Minimum Viable Product working, I used a nested for loop that has a time complexity of O(n^2^). Quite frankly, that is unacceptable and causes my engine to go incredibly slow. Your mileage will vary depending on your machine, obviously, but once I reached the upper hundreds, my system started to chug.

I've nearly finished implementing a Red-Black Binary Tree, and I intend to also use a Quadtree or Spatial Hashing. Unlike the Red-Black Binary Tree, I will likely implment somebody else's libraries for future data structures so that I can speed up development. I only wrote the first Tree just to be sure I could. Now that I have, I'm satisfied. On to better things.

**Red-Black Binary Tree** is a great alternative to AVL trees or standard Binary Search Trees. I actually was able to write most of a Red-Black Tree already, but I haven't finished the delete function, and I haven't had a chance to actually use it in my code. For anything where I need to rapidly retrieve objects by ID, this will be great. I could've used a dictionary or any other number of items, but I'd never written a Red-Black Tree before, and it was a good exercise.

**QuadTrees** are great for organizing elements spacially along 2 axes. Rather than a simple left-branch and right-branch, they have a branchNW, branchNE, branchSW, branchSE. When checking colliders against one another, you can walk the QuadTree to check which elements are close to one another. By organizing colliders according to space, you only have to check against a handful of other colliders for each element, as opposed to the whole list. When properly implemented, I believe the Time Complexity approaches O(1). (I originally wrote O(n), but that was when JC could barely see straight from COVID.)

## Rendering
For the purposes of rendering, I used the simplest library I could find: SFML. SFML also handles basic input. In future updates, I would want to transition to using DirectX 3D. I would also want to make input more flexible.



[Software Demo Video](https://youtu.be/cmqum40pnyY)

# Development Environment

I used Visual Studio Community Edition, 2022. I also used the external library SFML for graphics. Everything else is standard C++ Libraries, and it *should* run on most machines.

# Useful Websites

* [Download Microsoft Visual Studio](https://visualstudio.microsoft.com/)
* [Desktop Recording Software](https://obsproject.com/)
* [SFML Graphics Engine](https://www.sfml-dev.org/index.php)
* [Desmos Graphing Calculator](https://www.desmos.com/calculator)
* [CMath Library](https://cplusplus.com/reference/cmath/)
* [Chrono Library](https://cplusplus.com/reference/chrono/)
* [Introduction to Linear Algebra](https://math.mit.edu/~gs/linearalgebra/)
* [Introduction to Trigonometry](https://www.skillsyouneed.com/num/trigonometry.html)
* [Difference Between Force & Momentum](https://byjus.com/physics/difference-between-force-and-momentum/#:~:text=According%20to%20the%20second%20law,with%20the%20change%20in%20acceleration.)
* [A Great Resource For Understanding Red-Black Binary Trees](https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/)