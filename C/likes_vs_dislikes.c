#include <stddef.h>
#include <stdbool.h>

enum button { NOTHING, LIKE, DISLIKE };

enum button like_or_dislike (size_t n, const enum button events[n])
{
  bool liked = false;
  bool disliked = false;
  
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      liked = events[i] == LIKE;
      disliked = events[i] == DISLIKE;
    }
    else {
      if (events[i] == LIKE & events[i -1] == DISLIKE) {
        liked = true;
        disliked = false;
      } else if (events[i] == LIKE & events[i-1] == LIKE) {

        liked = !liked;
      } else if (events[i] == DISLIKE & events[i-1] == LIKE) {
        liked = false;
        disliked = true;
      } else if (events[i] == DISLIKE & events[i-1] == DISLIKE) {
        disliked = !disliked;
      }
    }
  }

  if (liked) {
    return LIKE;
  } else if (disliked) {
    return DISLIKE;
  }
  
  return NOTHING;
}