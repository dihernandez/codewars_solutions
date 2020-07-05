using namespace std;

string trim_string(string untrimmed) {
  auto front = untrimmed.find_first_not_of(' ');
  auto back = untrimmed.find_last_not_of(' ');
  return untrimmed.substr(front, back + 1);
}

string decodeMorse(string morseCode) {
    // ToDo: Accept dots, dashes and spaces, return humant
    string decoded = "";
    string segment = "";
    uint num_consecutive_spaces = 1;
    vector<string> segments;
    string ourCode = trim_string(morseCode);

    for(uint i = 0; i < ourCode.size(); i++){
      if(ourCode[i] != ' ') {
        segment += ourCode[i];
        if(i == ourCode.size() - 1) {
          segments.push_back(segment);
        }
      } else {
        if(segment.size() != 0) {
           segments.push_back(segment);
           cout << "pushing back segment: " << segment << endl;
           segment = "";
         }
         if(i > 0 && ourCode[i - 1] == ' ') { // and implicitely == ' '
           num_consecutive_spaces += 1;
         } 
         if(num_consecutive_spaces == 3) {
           segments.push_back("space");
           num_consecutive_spaces = 1;//reset
         }         
        
     }
   }
    
    for(auto seg : segments){
      if(seg == "space") {
        decoded += ' ';
      } else {
        decoded += MORSE_CODE[seg];
      }
    }

    return trim_string(decoded);
}