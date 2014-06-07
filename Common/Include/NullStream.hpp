#pragma once

#include <iostream>

class NullStream : public std::ostream {
public:
  std::ostream& operator<<(int);
  std::ostream& operator<<(const char[]);
};

