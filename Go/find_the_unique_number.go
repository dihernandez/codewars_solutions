package kata

func FindUniq(arr []float32) float32 {
	if arr[0] != arr[1] && arr[0] != arr[2]{
		return arr[0]
	}
  var i int = 0
	for i = 1; i < len(arr) - 1; i++ {
		if arr[i] != arr[i - 1] && arr[i] != arr[i + 1] {
			return arr[i]
		} 
	} 
	if arr[len(arr) - 1] != arr[len(arr) - 2] {
		return arr[len(arr) - 1]
	}
  return arr[0]
}