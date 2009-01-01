#line 2 "libsxc:libsxc/Logger.ixx"
#include <stdexcept>
#include <iostream>

namespace libsxc
{
  template <Type t> void Logger::log(const std::string &msg)/*{{{*/
  {
    throw std::logic_error(
      "No template specialization defined for this logging type");
  }/*}}}*/

  template <> inline void Logger::log<Debug>(const std::string &msg)/*{{{*/
  {
# ifdef DEBUG
      std::clog << _format(msg) << std::endl;
# endif
  }/*}}}*/

  template <> inline void Logger::log<Error>(const std::string &msg)/*{{{*/
  {
    std::clog << _format(msg) << std::endl;
  }/*}}}*/
}
