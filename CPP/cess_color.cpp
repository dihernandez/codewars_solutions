bool chessBoardCellColor(std::string cell1, std::string cell2) {
  int cell1_ascii = cell1[0];
  int cell2_ascii = cell2[0];
  bool cell1_is_brown, cell2_is_brown;
  
  cell1_is_brown = cell1_ascii % 2 == std::stoi(cell1.substr(1, cell1.length())) % 2; 
  cell2_is_brown = cell2_ascii % 2 == std::stoi(cell2.substr(1, cell2.length())) % 2;

  return (cell1_is_brown == cell2_is_brown);
}