#ifndef __NULL_STREAM__
#define __NULL_STREAM__

#include <iostream>

class NullStream : public std::ostream {
public:
  std::ostream& operator<<(int);
  std::ostream& operator<<(const char[]);
};

#endif
