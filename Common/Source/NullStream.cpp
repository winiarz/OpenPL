#include "NullStream.hpp"

std::ostream& NullStream::operator<<(int number)
{
  return *this;
}

std::ostream& NullStream::operator<<(const char[])
{
  return *this;
}
