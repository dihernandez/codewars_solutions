package kata

import("strings"; "strconv")

func HighAndLow(in string) string {
  var split_string = strings.Split(in, " ")
  max_num, _ := strconv.Atoi(split_string[0])
  min_num, _ := strconv.Atoi(split_string[0])
  for i := 0; i < len(split_string); i++ {
    current_char, _ := strconv.Atoi(split_string[i]) 
    if current_char < min_num {
      min_num = current_char
    }
    if current_char > max_num {
      max_num = current_char
    }
  }
  return strconv.Itoa(max_num) + " " + strconv.Itoa(min_num)
}