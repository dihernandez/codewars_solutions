#include <vector>
#include <algorithm>

int getLoopSize(Node* startNode)
{
  int loop_length = 1;
  Node *next = startNode->getNext();
  Node *last_in_circle;
  Node *next_in_circle;
  std::vector<Node *> visited = {};
  while(!std::count(visited.begin(),visited.end(), next)) {
    visited.push_back(next);
    next = next->getNext();
  }
  last_in_circle = next;
  next_in_circle = next->getNext();
  while(last_in_circle != next_in_circle) {
    loop_length++;
    next_in_circle = next_in_circle->getNext();
  }
  return loop_length;
}