#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

class Node{
public:
    int row;
    int col;

    Node(){}

    Node(int r, int c) {
      row = r;
      col = c;
    }

    void set(int r, int c) {
      row = r;
      col = c;
    }

    bool in_vector(std::vector<Node> v) {
      return std::find(v.begin(), v.end(), (*this)) != v.end();
    }

    bool in_set(std::set<Node> s) {
      return std::find(s.begin(), s.end(), (*this)) != s.end();
    }

    bool operator<(const Node& other) const {
    if (row < other.row) {
        return true;
    } else if (row == other.row) {
        return col < other.col;
    } else {
        return false;
    }
  }

    bool operator==(const Node& other) const {
      if(row == other.row && col == other.col) {
        return true;
      } else {
        return false;
      }
    }
};

std::map<Node, std::vector<Node>> build_graph(std::vector<std::string> maze) {
  std::map<Node, std::vector<Node>> graph;

  for(int row = 0; row < maze.size(); row++) {
    for(int col = 0; col < maze[row].length(); col++) {
      Node node(row, col);
      std::vector<Node> connecting_nodes;
        if(row - 1 >= 0 && maze[row - 1][col] != 'W') {
          connecting_nodes.push_back(Node(row -1, col));
        }
        if(row + 1 < maze.size() && maze[row + 1][col] != 'W') {
          connecting_nodes.push_back(Node(row + 1, col));
        }
        if(col - 1 >= 0 && maze[row][col - 1] != 'W') {
          connecting_nodes.push_back(Node(row, col - 1));
        }
        if(col + 1 < maze[row].length() && maze[row][col + 1] != 'W') {
          connecting_nodes.push_back(Node(row, col + 1));
        }
        graph[node] = connecting_nodes;
    }
  }
  
  return graph;
}

std::vector<Node> bfs(std::map<Node, std::vector<Node>> graph, Node source, Node destination) {
  std::vector<std::vector<Node>> path_list = {{source}};
  int path_index = 0;

  std::set<Node> previous_nodes;

  if (source == destination) {
    return path_list[0];
  }

  while (path_index < path_list.size()) {
    std::vector<Node> current_path = path_list[path_index];
    Node last_node = current_path.back();
    std::vector<Node> next_nodes = graph.at(last_node);

    if (destination.in_vector(next_nodes)) {
      current_path.push_back(destination);
      return current_path;
    }

    for(Node next_node : next_nodes) {
      if(!next_node.in_set(previous_nodes)) {
        std::vector<Node> new_path = current_path;
        new_path.push_back(next_node);
        path_list.push_back(new_path);
        previous_nodes.insert(next_node);
      }
    }
    path_index++;
  }

  std::vector<Node> empty;
  return empty;
}

std::vector<std::string> split_string(std::string map_string) {
  std::vector<std::string> split_string;
  int start_of_line = 0;
  std::size_t next_newline = map_string.find("\n");

  while(next_newline != std::string::npos) {
    split_string.push_back(map_string.substr(start_of_line, next_newline - start_of_line));
    start_of_line = next_newline + 1;
    next_newline = map_string.find("\n", start_of_line);
  }

  if (start_of_line < map_string.length()) {
       split_string.push_back(map_string.substr(start_of_line));
   }

  return split_string;
}

bool path_finder(std::string maze) {
  std::vector<std::string> map = split_string(maze);
  std::map<Node, std::vector<Node>> graph = build_graph(map);
  int map_dimension = map.size();
  Node start(0,0);
  Node end(map_dimension - 1, map_dimension - 1); // n * n maze

  std::vector<Node> path = bfs(graph, start, end);
  return path.size() != 0;
}
