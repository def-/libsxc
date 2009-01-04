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

#ifndef EXCEPTION_EXCEPTION_HXX
#define EXCEPTION_EXCEPTION_HXX

// INCLUDE/*{{{*/

#include <exception>

#include <libsxc/Exception/Type.hxx>

/*}}}*/

namespace libsxc
{
  /**
   * @brief Contains everything about Exceptions and their handling.
   */
  namespace Exception
  {
    /**
     * @brief Base class for exceptions.
     *
     * Supports a descriptive message, an error code (which can be used as
     * return code) and automatic generation of a backtrace (if a cause has been
     * passed). The backtrace can be retrieved by calling what() and thus can be
     * used from any client which works with references or pointers of
     * std::exception.
     *
     * Optionally, the message and the error type can be retrieved directly by
     * calling their getter methods.
     */
    // TODO: Rename and make interface for
    // classes that can be backtraceble and can backtrace but do not "waste"
    // memory in favor of returning always the same fixed string (and type)
    class Exception : virtual public std::exception
    {
      public:
        // static const unsigned int WHAT_BUFFER_SIZE = 512;/*{{{*/

        /**
         * @brief Length of the cstring which will hold the cause for this
         * exception (if any) and the message that has been passed.
         */
        static const unsigned int WHAT_BUFFER_SIZE = 512;

/*}}}*/
        // static const unsigned int CAUSE_BUFFER_SIZE = 384;/*{{{*/

        /// Length of the cstring which will hold the cause for this exception.
        static const unsigned int CAUSE_BUFFER_SIZE = 384;

/*}}}*/
        // static const unsigned int MESSAGE_BUFFER_SIZE = 128;/*{{{*/

        /// Length of the cstring which will hold the cause for this exception.
        static const unsigned int MESSAGE_BUFFER_SIZE = 128;

/*}}}*/

        // Exception(const char* message, Type type) throw();/*{{{*/

        /**
         * @brief Default constructor.
         *
         * @note The message will be truncated if it is longer than
         * MESSAGE_BUFFER_SIZE.
         *
         * @param message A message describing the exception.
         * @param type The error type.
         */
        Exception(const char* message, Type type) throw();

/*}}}*/
        // Exception(const char*, Type, const std::exception&) throw();/*{{{*/

        /**
         * @brief Constructor to be called when another exception has already
         * been caught.
         *
         * @param message A message describing the exception.
         * @param type The error type.
         * @param cause The causer for this exception.
         * @see Exception::Exception(const char*, Type)
         */
        Exception(
          const char* message, Type type, const std::exception& cause) throw();

/*}}}*/
        // virtual ~Exception() throw()/*{{{*/

        /**
         * @brief Virtual destructor.
         */
        virtual ~Exception() throw();

/*}}}*/
        // virtual const char* what() const throw();/*{{{*/

        /**
         * @brief Returns information about this exception.
         *
         * Returns a backtrace using information of the @a cause object passed
         * as parameter to the constructor. The original cause will be listed on
         * top, the message of this exception (as returned by getMessage()) will
         * be on bottom.
         *
         * @return Null-terminated cstring.
         */
        virtual const char* what() const throw();

/*}}}*/
        // virtual const char* getMessage() const throw();/*{{{*/

        /**
         * @brief Returns the message of this exception.
         * @return C-style character string describing this exception.
         */
        virtual const char* getMessage() const throw();

/*}}}*/
        // virtual Type getType() const throw();/*{{{*/

        /**
         * @brief Returns the type (return code) of the exception.
         * @return The type of the exception.
         */
        virtual Type getType() const throw();

/*}}}*/
        // const char* getCause() const throw();/*{{{*/

        /**
         * @brief Returns the cause of this exception.
         *
         * @note: The cause is the exception which triggered firing of this one.
         * For a description of this exception, see what().
         *
         * @return Null-terminated C-style character string which may be empty.
         */
        const char* getCause() const throw();

/*}}}*/

      protected:
        // Exception() throw();/*{{{*/

        /**
         * @brief Lowlevel constructor.
         *
         * @note If you are calling this constructor in a derived class, make
         * sure to not forget calling @c createBacktrace() @em after you have
         * set message and type.
         */
        Exception() throw();

/*}}}*/
        // Exception(const std::exception& cause) throw();/*{{{*/

        /**
         * @brief Lowlevel constructor expecting a cause for this exception.
         *
         * @note If you are calling this constructor in a derived class, make
         * sure to not forget calling @c createBacktrace() @em after you have
         * set message and type.
         *
         * @param cause The causer for this exception.
         */
        Exception(const std::exception& cause) throw();

/*}}}*/
        // void createBacktrace() throw();/*{{{*/

        /**
         * @brief Creates the backtrace which can be retrieved by what().
         *
         * The original cause will be listed on top, the message of this
         * exception (as returned by getMessage()) will be on bottom.
         */
        void createBacktrace() throw();

/*}}}*/
        // void setMessage(const char*) throw();/*{{{*/

        /**
         * @brief Sets a short descriptive message about this exception.
         * @note Will be truncated if it is longer than MESSAGE_BUFFER_SIZE.
         * @param message String containing a descriptive message.
         */
        void setMessage(const char* message) throw();

/*}}}*/
        // void setType(Type type) throw();/*{{{*/

        /**
         * @brief Sets the error type and return code of this exception.
         * @param type Error type and return code.
         */
        void setType(Type type) throw();

/*}}}*/

      private:
        // char _message[MESSAGE_BUFFER_SIZE];/*{{{*/

        /// Holds a short descriptive message about this exception.
        char _message[MESSAGE_BUFFER_SIZE];
/*}}}*/
        // Type _type;/*{{{*/

        /// The type of this exception, which would also be the return code.
        Type _type;

/*}}}*/
        // char _cause[CAUSE_BUFFER_SIZE];/*{{{*/

        /// Holds string returned by std::exception.what() of the causer.
        char _cause[CAUSE_BUFFER_SIZE];

/*}}}*/
        // char _what[WHAT_BUFFER_SIZE];/*{{{*/

        /// Buffer for the message returned (and created) by what().
        char _what[WHAT_BUFFER_SIZE];

/*}}}*/

        // void _setCause(const char* cause) throw();/*{{{*/

        /**
         * @brief Sets the string describing what caused this exception.
         * @param cause cstring describing the cause.
         */
        void _setCause(const char* cause) throw();

/*}}}*/
    };
  }
}

#endif // EXCEPTION_EXCEPTION_HXX
// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
