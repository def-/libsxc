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


// INCLUDE/*{{{*/

#include <gloox/gloox.h>
#include <gloox/presence.h>
#include <gloox/message.h>

/*}}}*/


#ifndef LIBSXC_GENERATESTRING_HXX
#define LIBSXC_GENERATESTRING_HXX


namespace libsxc
{
  //string genConnErrorString(connE, streamE, streamEText, authE, debug=0);/*{{{*/

  /**
   * @brief Generate a connection error text.
   *
   * @param connectionError The connection error.
   * @param streamError More verbose information about a stream error.
   * @param streamErrorText An additional information text about the stream
   *        error.
   * @param authError More verbose information about an authentication error.
   * @return The generated text.
   */
  std::string genConnErrorString(
    gloox::ConnectionError connectionError,
    gloox::StreamError streamError,
    const std::string &streamErrorText,
    gloox::AuthenticationError authError,
    bool isDebug = false);

  /*}}}*/
  //std::string genPresenceString(gloox::Presence::PresenceType presence);/*{{{*/

  /**
   * @brief Generate a presence text.
   *
   * @param presence The presence.
   * @return The generated text.
   */
  std::string genPresenceString(gloox::Presence::PresenceType presence);

  /*}}}*/
  //std::string genStanzaErrorString(gloox::StanzaError error)/*{{{*/

  /**
   * @brief Generate a stanza error text.
   *
   * @param error The stanza error.
   * @return The generated text.
   */
  std::string genStanzaErrorString(
    gloox::StanzaError error);

  /*}}}*/
  //std::string genMsgTypeString(gloox::Message::MessageType type);/*{{{*/

  /**
   * @brief Generate a text from a message type.
   *
   * @param type The message type.
   * @return The generated text.
   */
  std::string genMsgTypeString(gloox::Message::MessageType type);

  /*}}}*/
}


#endif // LIBSXC_GENERATESTRING_HXX
// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
