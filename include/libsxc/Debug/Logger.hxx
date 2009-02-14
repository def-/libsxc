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

#include <string>

// Included for the macro.
#include <libsxc/Debug/Format.hxx>
#include <libsxc/Debug/Output.hxx>

/*}}}*/

/**
 * This is a simple macro to be used when logging debug messages. It simplifies
 * the use of the Logger class.
 */
#ifdef DEBUG
# define LOG(text) libsxc::Debug::Logger<libsxc::Debug::Format, libsxc::Debug::Output>().log(__FILE__, __LINE__, text)
#else
# define LOG(text)
#endif

namespace libsxc
{
  namespace Debug
  {
    /**
     * This class implements a policy-based class design. This means this class
     * does not specify how it works and is highly customizable. It derives
     * from the specified template classes and uses their methods to format the
     * text and to print it.
     *
     * @note The FormatPolicy has to implement a public or protected format method.
     *       The OutputPolicy has to implement a public or protected print method.
     */
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
         * Format and output a text. See @ref Format and @ref Output for the
         * corresponding implementations.
         *
         * @param file The name of the current file.
         * @param line The number of the current line.
         * @param raw The raw text to be formatted
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
