#include <string>

#ifndef LIBSXC_LOGGER_HXX
#define LIBSXC_LOGGER_HXX

# define LOG libsxc::Logger(__FILE__, __LINE__).log

namespace libsxc
{
  enum Type/*{{{*/
  {
    Debug,
    Error
  };/*}}}*/

  /**
   * @brief A general logging object.
   *
   * This class allows to log warning and error messages.
   *
   * @note @ref LOG eases the use of this class
   * @note DEBUG has to be defined before including this file if you want to
   *       use this logger with @ref Debug.
   */
  class Logger
  {
    public:
      //Logger(const std::string file, unsigned int line);/*{{{*/

      /**
       * @file The filename, get from __FILE__.
       * @line The current line, get from __LINE__.
       */
      Logger(const std::string file, unsigned int line);

  /*}}}*/

      //template <Type t> void log(const std::string &msg);/*{{{*/

      /**
       * @brief The actual logging.
       *
       * This function has to be implemented as a template specialization to
       * work.
       * @param msg The message to log.
       */
      template <Type t> void log(const std::string &msg);

  /*}}}*/

    private:
      //const std::string _format(const std::string &msg);/*{{{*/

      /**
       * @brief Format a message for pretty output.
       *
       * @param msg The raw message.
       * @return The formatted message.
       */
      const std::string _format(const std::string &msg);

  /*}}}*/

      const std::string _file;
      unsigned int _line;
  };
}

#include <libsxc/Logger.ixx>

#endif // LIBSXC_LOGGER_HXX
