#line 1 "libsxc:Logger.cxx"
#include <sstream>

#include <libsxc/Logger.hxx>

namespace libsxc
{
  Logger::Logger(const std::string file, unsigned int line)/*{{{*/
  : _file(file)
  , _line(line)
  {
  }/*}}}*/

  const std::string Logger::_format(const std::string &msg)/*{{{*/
  {
    std::ostringstream s;
    s << _file << ":" << _line << ": " << msg;
    return s.str();
  }/*}}}*/
}
