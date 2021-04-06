#ifndef NOT_FOUND_EXCEPT_
#define NOT_FOUND_EXCEPT_

#include <stdexcept>
#include <string>
class NotFoundException : public std::logic_error {
 public:
  NotFoundException(const std::string& Error_Message = "")
      : std::logic_error("Precondition Violated Exception: " + Error_Message) {}
};
#endif
