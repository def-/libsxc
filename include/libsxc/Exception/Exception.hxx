// LICENSE/*{{{*/
/*
  sxc - Simple Xmpp Client
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

#include <string>
#include <exception>

#include <libsxc/Exception/Type.hxx>

/*}}}*/

/**
 * @brief Contains everything about Exceptions and their handling.
 */

namespace libsxc
{
  namespace Exception
  {
    /**
     * @brief An exception base class.
     */
    class Exception : public std::exception
    {
      public:
        //Exception(Type type, std::string &message) throw();/*{{{*/

        /**
         * @brief Default constructor.
         *
         * @see Exception::Exception(Type, char*)
         * @param message Reference of a string describing the
         *        exception.
         */
        Exception(Type type, std::string &message) throw();

  /*}}}*/
        //Exception(Type type, const char *message) throw();/*{{{*/

        /**
         * @brief Overloaded constructor.
         *
         * @param type The type of the exception.
         * @param message Pointer to a C style char string describing
         *        the exception.
         */
        Exception(Type type, const char *message) throw();

  /*}}}*/

        //virtual ~Exception() throw();/*{{{*/

        /**
         * @brief The destructor.
         *
         * Has to be set so the compiler doesn't bug about the
         * destructor having a looser throw specifier.
         */
        virtual ~Exception() throw();

  /*}}}*/
        //virtual const char *what() const throw();/*{{{*/

        /**
         * @brief Get a C-style character string of @ref getMessage().
         *
         * Has to be implemented as a backward compatibility to
         * exception.
         *
         * @return A C-style character string describing the exception.
         */
        virtual const char *what() const throw();

  /*}}}*/

        //const std::string &getMessage() const throw();/*{{{*/

        /**
         * @brief Get a const reference to the message of the exception.
         *
         * @return A text describing the exception more verbose.
         */
        const std::string &getMessage() const throw();

  /*}}}*/
        //const std::string &getDescription() const throw();/*{{{*/

        /**
         * @brief Get a const reference to the description.
         *
         * Runs @ref createDescription() if @ref _description is not
         * set.
         *
         * @return A text describing the exception more verbose.
         */
        const std::string &getDescription() throw();

  /*}}}*/
        //Type getType() const throw();/*{{{*/

        /**
         * @brief Get the type of the exception.
         * @return The type of the exception.
         */
        Type getType() const throw();

  /*}}}*/

      protected:
        //virtual void createDescription() throw() = 0;/*{{{*/

        /**
         * @brief Create the description string.
         *
         * This function has to be implemented by a child class that is
         * going to be instantiated.
         *
         * @note @ref _isDescriptionCreated is set by getDescription and
         *       therefore hasn't to be set here too.
         */
        virtual void createDescription() throw() = 0;

  /*}}}*/
        //void setInvalid() throw();/*{{{*/

        /**
         * @brief Set the description to an invalid text.
         */
        void setInvalid() throw();

  /*}}}*/

        //Type _type;/*{{{*/

        /// The type of the exception.
        Type _type;

  /*}}}*/
        //std::string _message;/*{{{*/

        /// The message the exception was given at construction.
        std::string _message;

  /*}}}*/
        //std::string _description;/*{{{*/

        /// A description of the exception more verbose.
        std::string _description;

  /*}}}*/
        //bool _isDescriptionCreated;/*{{{*/

        /// Whether the description has already been created.
        bool _isDescriptionCreated;
  /*}}}*/
    };
  }
}

#endif // EXCEPTION_EXCEPTION_HXX
// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
