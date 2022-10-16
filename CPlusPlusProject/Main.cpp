#include <iostream>
#include "Game.h"
//#include "Physics2D.h"
//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <thread>
#include "BinaryTree.h"

int main() {
    RedBlackTree<int, float> testTree = RedBlackTree<int,float>::RedBlackTree();
    Game().run();
}