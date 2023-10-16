unsigned sequence_sum(unsigned start, unsigned end, unsigned step)
{
  unsigned result = start;
  if(start > end) {
    result = 0;
  } else {
    unsigned counter = start;

    while (counter + step <= end) {
      counter += step;
      result += counter;
    }
  }
    return result;
}