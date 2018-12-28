package kata
import ("math")

func distance_formula(x1y1 [2]int, x2y2 [2]int) int {
  return int(math.Sqrt(math.Pow(float64(x1y1[0] - x2y2[0]), 2) + math.Pow(float64(x1y1[1] - x2y2[1]), 2)))
}

func PeacefulYard(yard []string, minDistance int) bool {
  cat_locations := make(map[string][2]int)
  two_d_slice := make([][]string, len(yard))

  for s := 0; s < len(yard); s++ {
    inner_length := len(yard[s])
    two_d_slice[s] = make([]string, inner_length) 
    for y := 0; y < inner_length; y++ {
      two_d_slice[s][y] = string(yard[s][y])
      loc := [2]int{s,y}
      if yard[s][y] == 'M' {
        cat_locations["M"] = loc
      } else if yard[s][y] == 'R' {
        cat_locations["R"] = loc
      } else if yard[s][y] == 'L' {
        cat_locations["L"] = loc
      }
    }
  }
  if len(cat_locations) <= 1 {
    return true
  }
  
  var mr_safe bool = true
  var ml_safe bool = true
  var rl_safe bool = true
  val_m, is_m_here := cat_locations["M"]
  val_r, is_r_here := cat_locations["R"]
  val_l, is_l_here := cat_locations["L"]
  if(is_m_here && is_r_here) {
    mr_safe = distance_formula(val_m, val_r) >= minDistance
  }
  if(is_m_here && is_l_here) {
    ml_safe = distance_formula(val_m, val_l) >= minDistance
  } 
  if(is_r_here && is_l_here) {
    rl_safe = distance_formula(val_r, val_l) >= minDistance
  }
  return mr_safe && ml_safe && rl_safe
}
