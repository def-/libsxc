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
#ifndef EXCEPTION_TYPE_HXX
#define EXCEPTION_TYPE_HXX

namespace libsxc
{
  namespace Exception
  {
    /**
     * @brief An enum for all exception types and their exit codes.
     *
     * Developers and users of exception classes are free to use any of them.
     * The error types do not depend on specific exception classes.
     */
    enum Type
    {
      NoError          =   0, // No problem occured.
      General          =  64,
      // Program option exceptions./*{{{*/
      MissingOption    =  80,
      MissingValue     =  81,
      UnknownOption    =  82,
      InvalidValue     =  83,
      Conflict         =  84,
/*}}}*/
      // Gloox errors./*{{{*/
      // TODO: Do we need them?
      // Connection = 90,
      // Registration = 91,
      // PrivacyList = 92,
      // SessionCreate = 93,
      // Stanza = 94,
      // Stream = 95,
/*}}}*/
      // File errors./*{{{*/
      BadFile        = 150,
      BadPath        /* = @ */,
      FileMissing    /* = @ */,
      FileExists     /* = @ */,
      FileLocked     /* = @ */,
      AccessDenied   /* = @ */,
      OpenFailed     /* = @ */,
      WriteFailed    /* = @ */,
      ReadFailed     /* = @ */,
      CloseFailed    /* = @ */,
/*}}}*/
      // Command errors:/*{{{*/
      InvalidCommand = 170,
      NotACommand    /* = @ */,
/*}}}*/
      // Generic errors:/*{{{*/
      InvalidUsage = 200,
/*}}}*/
    };
  }
}

#endif // EXCEPTION_TYPE_HXX
// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
