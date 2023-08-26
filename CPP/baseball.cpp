#include <string>
#include <list>
using namespace std;

class ScoreCard 
{
public:
  vector<string> bat_results {};
  int away_team_score {0};
  int home_team_score {0};
  int away_team_outs {0};
  int home_team_outs {0};
  list<int> away_team_bases {0,0,0,0};
  list<int> home_team_bases {0,0,0,0};
  
public:
  ScoreCard();
  /*
  * A public method accepting the result of an at-bat
  * @param {string} entry - The result of an at-bat 
  * Acceptable values: ('single', 'double', 'triple', 'homerun' or 'out') 
  */
  void addEntry(string entry);
  /*
  * A public method returning the current score
  * Format: "Home: [HOME_SCORE] Away: [AWAY_SCORE]"
  */
  string getScore();
};

ScoreCard::ScoreCard(){
  bat_results = {};
  away_team_score = 0;
  home_team_score = 0;
  away_team_outs = 0;
  home_team_outs = 0;
  away_team_bases = {0,0,0,0};
  home_team_bases = {0,0,0,0};

};

void ScoreCard::addEntry(string entry) {
  bat_results.push_back(entry);
  cout << "entry is " << entry << endl;
  
}

string ScoreCard::getScore() {
  bool away_team_turn = true;
 
  for(vector<string>::iterator entry_it = bat_results.begin(); entry_it !=  bat_results.end(); entry_it++) {
    cout<< "in getScore "<< "entry is " << *entry_it << endl;
    if(*entry_it == "out") {
        if(away_team_turn) {
            away_team_outs += 1;
        } else {
            home_team_outs += 1;
        }
    }
    if(away_team_turn && away_team_outs > 2) { // 3 outs and out
        away_team_turn = !away_team_turn;
        away_team_outs = 0;
    }
    if(!away_team_turn && home_team_outs > 2) {
        away_team_turn = !away_team_turn;
        home_team_outs = 0;
    }
    else if (*entry_it == "single") {
      if(away_team_turn){
        away_team_bases.push_front(1);
        away_team_score += away_team_bases.back();
        away_team_bases.pop_back();
      } else {
        home_team_bases.push_front(1);
        home_team_score += away_team_bases.back();
        home_team_bases.pop_back();    
      }
    } else if (*entry_it == "double") {
        if(away_team_turn) {
            away_team_bases.push_front(1);
            away_team_bases.push_front(1);
            away_team_score += away_team_bases.back();
            away_team_bases.pop_back();
            away_team_score += away_team_bases.back();
            away_team_bases.pop_back();
        } else {
            home_team_bases.push_front(1);
            home_team_bases.push_front(1);
            home_team_score += away_team_bases.back();
            home_team_bases.pop_back();
            home_team_score += away_team_bases.back();
            home_team_bases.pop_back();
        }
    }
    else if (*entry_it == "triple") {
            if(away_team_turn) {
                away_team_bases.push_front(1);
                away_team_bases.push_front(1);
                away_team_bases.push_front(1);

                away_team_score += away_team_bases.back();
                away_team_bases.pop_back();
                away_team_score += away_team_bases.back();
                away_team_bases.pop_back();
                away_team_score += away_team_bases.back();
                away_team_bases.pop_back();
            } else {
                home_team_bases.push_front(1);
                home_team_bases.push_front(1);
                home_team_bases.push_front(1);
                home_team_score += away_team_bases.back();
                home_team_bases.pop_back();
                home_team_score += away_team_bases.back();
                home_team_bases.pop_back();
                home_team_score += away_team_bases.back();
                home_team_bases.pop_back();
            }
        }

    else if(*entry_it == "homerun") {
      int homerun_score = 1;
      for(list<int>::iterator it = away_team_bases.begin(); it != away_team_bases.end(); it++){
        homerun_score += *it;
      }
      
      if(away_team_turn) {
        away_team_score += homerun_score; 
      } else {
        home_team_score += homerun_score;   
      }
    }  
  }
  bat_results = {};
  string result = "Home: " + to_string(home_team_score) + " Away: " + to_string(away_team_score);
  return  result;
}