// LICENSE/*{{{*/
/*
  libsxc
  Copyright (C) 2008 Dennis Felsing, Andreas Waidler

  Permission to use, copy, modify, and/or distribute this software for any
  purpose with or without fee is hereby granted, provided that the above
  copyright notice and this permission notice appear in all copies.

  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
/*}}}*/

#ifndef LIBSXC_DEBUG_LOGGER_HXX
#define LIBSXC_DEBUG_LOGGER_HXX

// INCLUDE/*{{{*/


/*}}}*/

#ifdef DEBUG
# define LOG(text) libsxc::Debug::Logger<libsxc::Debug::Format, libsxc::Debug::Output>().log(__FILE__, __LINE__, text)
#else
# define LOG(text)
#endif

namespace libsxc
{
  namespace Debug
  {
    class Format
    {
      protected:
        //const string format(file, line, &raw);/*{{{*/

        /**
         */
        const std::string format(
          const std::string file,
          unsigned int line,
          const std::string &raw);

  /*}}}*/
    };

    class Output
    {
      protected:
        //void print(const std::string &text);/*{{{*/

        /**
         */
        void print(const std::string &text);

/*}}}*/
    };

    template <typename FormatPolicy, typename OutputPolicy>
    class Logger
    : public FormatPolicy
    , public OutputPolicy
    {
      using FormatPolicy::format;
      using OutputPolicy::print;

      public:
        //void log(const string file, unsigned int line, const string &text)/*{{{*/

        /**
         */
        void log(
          const std::string file,
          unsigned int line,
          const std::string &text);

  /*}}}*/
    };
  }
}

#include <libsxc/Debug/Logger.ixx>

#endif // LIBSXC_DEBUG_LOGGER_HXX
// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
