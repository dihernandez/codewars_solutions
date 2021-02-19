class RGBToHex
{
  public:
  static std::string rgb(int r, int g, int b);
  static int round(int to_round);
};

int RGBToHex::round(int to_round) {
  if(to_round < 0) {
    return 0;
  } else if(to_round > 255) {
    return 255;
  } else {
    return to_round; // already rounded
  }
}

std::string RGBToHex::rgb(int r, int g, int b){
  int r_rounded = round(r);
  int g_rounded = round(g);
  int b_rounded = round(b);
  std::cout << " r is " << r << " g is " << g << " b is " << b << std::endl;
  std::stringstream stream;
  if(r <= 0xF) {
    stream << 0x0;
    stream << std::uppercase << std::hex << r_rounded;
 } else {
    stream << std::uppercase << std::hex << r_rounded;
  }
  if(g <= 0xF) {
    stream << 0x0;
    stream << std::uppercase << std::hex << g_rounded;
  } else {
    stream << std::uppercase << std::hex << g_rounded;
  }
  if(b <= 0xF) {
    stream << 0x0;
    stream << std::uppercase << std::hex << b_rounded;
  } else {
    stream << std::uppercase << std::hex << b_rounded;
  }

std::string result( stream.str() );
  std::cout << result << std::endl;