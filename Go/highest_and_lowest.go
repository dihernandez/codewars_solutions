package kata
import("bytes")


func ValidBraces(str string) bool {
  paren_queue := make([]byte, 0)
  brackets_queue := make([]byte, 0)
  curly_queue := make([]byte, 0)

  if str[0] == ')' || str[0] == ']' || str[0] == '}' {
    return false
  }
  
  for c := 0; c < len(str) - 1; c++ {
    if (str[c] == '(' && str[c + 1] == '}') || (str[c] == '(' && str[c + 1] == ']') {
      return false
    } 
    if (str[c] == '[' && str[c + 1] == '}') || (str[c] == '[' && str[c + 1] == ')') {
      return false
    } 
    if (str[c] == '{' && str[c + 1] == ']') || (str[c] == '{' && str[c + 1] == ')') {
      return false
    } 
  }
    for c := 0; c < len(str); c++ {
      if str[c] == '(' {
        paren_queue = append(paren_queue, str[c])
      } else if str[c] == ')' {
        if bytes.Contains(paren_queue, []byte("(")) {
          paren_queue = paren_queue[:len(paren_queue) - 1]
        } else {
          paren_queue = append(paren_queue, str[c])
        }
      } else if str[c] == '[' {
        brackets_queue = append(brackets_queue, str[c])
      } else if str[c] == ']'{
        if bytes.Contains(brackets_queue, []byte("[")) {
            brackets_queue = brackets_queue[:len(brackets_queue) - 1]
          } else {
            brackets_queue = append(brackets_queue, str[c])
          }
      } else if str[c] == '{' {
        curly_queue = append(curly_queue, str[c])
      } else if str[c] == '}' {
        if bytes.Contains(curly_queue, []byte("{")){
          curly_queue = curly_queue[:len(curly_queue) - 1]
        } else {
        curly_queue = append(curly_queue, str[c])
        }
      }
  }
  return len(paren_queue) + len(brackets_queue) + len(curly_queue) == 0
}