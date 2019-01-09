package kata

import("strings"; "strconv")

func Is_segment_valid(segment string) bool {
  if len(segment) > 1 && segment[0] == '0' {
    return false
  } 
  s,_ := strconv.Atoi(segment)
  if s < 0 || s > 255 {
  	return false
  }
  return true
}


func Is_ip_clean(ip string) bool{
  for _, c := range ip {
    if !strings.Contains("0123456789.", string(c)) {
        return false
    }  
  }
  return true
}

func Is_valid_ip(ip string) bool {
  
  if !Is_ip_clean(ip) {
    return false
  }

  var segments []string = strings.Split(ip, ".")
  
  if len(segments) != 4 {
    return false
  }
  
  for i := 0; i < len(segments); i++ {
  	if !Is_segment_valid(segments[i]) {
  		return false
  	}
  }
  return true
}