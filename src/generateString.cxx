#line 2 "libsxc:generateString.cxx"
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

#include <string>
#include <gloox/gloox.h>
#include <gloox/presence.h>
#include <gloox/message.h>

#include <libsxc/generateString.hxx>

/*}}}*/

namespace libsxc
{
  std::string genConnErrorString(/*{{{*/
    gloox::ConnectionError connectionError,
    gloox::StreamError streamError,
    const std::string &streamErrorText,
    gloox::AuthenticationError authError,
    bool isDebug)
  {
    std::string text;

    switch (connectionError) {
    case gloox::ConnNoError:
      if (isDebug)
        text = "No error.";
      break;
    case gloox::ConnStreamError: {
      text = "Stream error: ";
      switch (streamError) {
      case gloox::StreamErrorUndefined:
        text += "Undefined/unknown.";
        break;
      case gloox::StreamErrorBadFormat:
        text += "Bad format.";
        //text += "The entity has sent XML that cannot be processed.";
        break;
      case gloox::StreamErrorBadNamespacePrefix:
        text += "Bad namespace prefix.";
        //text += "The entity has sent a namespace prefix that is "
        //    "unsupported, or has sent no namespace prefix on an "
        //    "element that requires such a prefix.";
        break;
      case gloox::StreamErrorConflict:
        text += "Conflicting streams.";
        //text += "The server is closing the active stream for this "
        //    "entity because a new stream has been initiated that "
        //    "conflicts with the existing stream.";
        break;
      case gloox::StreamErrorConnectionTimeout:
        text += "Timeout.";
        //text += "The entity has not generated any traffic over the "
        //    "stream for some period of time.";
        break;
      case gloox::StreamErrorHostGone:
        text += "Host gone.";
        //text += "The value of the 'to' attribute provided by the "
        //    "initiating entity in the stream header corresponds to "
        //    "a hostname that is no longer hosted by the server.";
        break;
      case gloox::StreamErrorHostUnknown:
        text += "Unknown host.";
        //text += "The value of the 'to' attribute provided by the "
        //    "initiating entity in the stream header does not "
        //    "correspond to a hostname that is hosted by the "
        //    "server.";
        break;
      case gloox::StreamErrorImproperAddressing:
        text += "Improper addressing.";
        //text += "A stanza sent between two servers lacks a 'to' or "
        //    "'from' attribute.";
        break;
      case gloox::StreamErrorInternalServerError:
        text += "Internal server error.";
        //text += "The server has experienced a misconfiguration or an "
        //    "otherwise-undefined internal error that prevents it "
        //    "from servicing the stream.";
        break;
      case gloox::StreamErrorInvalidFrom:
        text += "Invalid sender.";
        //text += "The JID or hostname provided in a 'from' address does "
        //    "not match an authorized JID or validated domain "
        //    "negotiated between servers via SASL or dialback, or "
        //    "between a client and a server via authentication and "
        //    "resource binding.";
        break;
      case gloox::StreamErrorInvalidId:
        text += "Invalid ID.";
        //text += "The stream ID or dialback ID is invalid or does not "
        //    "match an ID previously provided.";
        break;
      case gloox::StreamErrorInvalidNamespace:
        text += "Invalid namespace";
        //text += "The streams namespace name is something other than "
        //    "\"http://etherx.jabber.org/streams\" or the dialback "
        //    "namespace name is something other than "
        //    "\"jabber:server:dialback\".";
        break;
      case gloox::StreamErrorInvalidXml:
        text += "Invalid XML.";
        //text += "The entity has sent invalid XML over the stream to a "
        //    "server that performs validation.";
        break;
      case gloox::StreamErrorNotAuthorized:
        text += "Not authorized.";
        //text += "The entity has attempted to send data before the "
        //    "stream has been authenticated, or otherwise is not "
        //    "authorized to perform an action related to stream "
        //    "negotiation.";
        break;
      case gloox::StreamErrorPolicyViolation:
        text += "Policy violated.";
        //text += "The entity has violated some local service policy.";
        break;
      case gloox::StreamErrorRemoteConnectionFailed:
        text += "Server unable to connect to remote entity.";
        //text += "The server is unable to properly connect to a remote "
        //    "entity that is required for authentication or "
        //    "authorization.";
        break;
      case gloox::StreamErrorResourceConstraint:
        text += "Resources missing.";
        //text += "The server lacks the system resources necessary to "
        //    "service the stream.";
        break;
      case gloox::StreamErrorRestrictedXml:
        text += "Restricted XML.";
        //text += "The entity has attempted to send restricted XML "
        //    "features.";
        break;
      case gloox::StreamErrorSeeOtherHost:
        text += "See other host.";
        //text += "The server will not provide service to the initiating "
        //    "entity but is redirecting traffic to another host.";
        break;
      case gloox::StreamErrorSystemShutdown:
        text += "Server shutdown.";
        //text += "The server is being shut down and all active streams "
        //    "are being closed.";
        break;
      case gloox::StreamErrorUndefinedCondition:
        text += "Undefined condition.";
        //text += "The error condition is not one of those defined by "
        //    "the other conditions in this list.";
        break;
      case gloox::StreamErrorUnsupportedEncoding:
        text += "Unsupported encoding.";
        //text += "The initiating entity has encoded the stream in an "
        //    "encoding that is not supported by the server.";
        break;
      case gloox::StreamErrorUnsupportedStanzaType:
        text += "Unsupported stanza type.";
        //text += "The initiating entity has sent a first-level child of "
        //    "the stream that is not supported by the server.";
        break;
      case gloox::StreamErrorUnsupportedVersion:
        text += "Unsupported XMPP version.";
        //text += "The initiating entity specifies a version of XMPP "
        //    "that is not supported by the server.";
        break;
      case gloox::StreamErrorXmlNotWellFormed:
        text += "Malformed XML.";
        //text += "The initiating entity has sent XML that is not "
        //    "well-formed.";
        break;
      default:
        text += "Unknown.";
      break;
      }
      if (!streamErrorText.empty())
        text += " (Additional information: " + streamErrorText + ")";
    }
    case gloox::ConnStreamVersionError:
      text = "Unsupported stream version.";
      //text = "The incoming stream's version is not supported.";
      break;
    case gloox::ConnStreamClosed:
      text = "Stream closed by server.";
      //text = "The stream has been closed by the server.";
      break;
    case gloox::ConnProxyAuthRequired:
      text = "Proxy requires authentication.";
      //text = "The HTTP/SOCKS5 proxy requires authentication.";
      break;
    case gloox::ConnProxyAuthFailed:
      text = "Proxy authentication failed.";
      //text = "The HTTP/SOCKS5 proxy authentication failed.";
      break;
    case gloox::ConnProxyNoSupportedAuth:
      text = "Proxy's authentication mechanism unsupported.";
      //text = "The HTTP/SOCKS5 proxy requires an unsupported auth "
      //     "mechanism.";
      break;
    case gloox::ConnIoError:
      text = "I/O error";
      //text = "An I/O error occured.";
      break;
    case gloox::ConnParseError:
      text = "Parsing XML failed.";
      //text = "An XML parse error occured.";
      break;
    case gloox::ConnConnectionRefused:
      text = "Server refused connection on the socket level.";
      //text = "The connection was refused by the server (on the socket "
      //     "level).";
      break;
    case gloox::ConnDnsError:
      text = "Resolving server's hostname failed.";
      //text = "Resolving the server's hostname failed.";
      break;
    case gloox::ConnOutOfMemory:
      text = "Out of memory.";
      break;
    case gloox::ConnNoSupportedAuth:
      text = "Unsupported authentication mechanisms.";
      //text = "The auth mechanisms the server offers are not supported "
      //     "or the server offered no auth mechanisms at all.";
      break;
    case gloox::ConnTlsFailed:
      text = "TLS failed.";
      //text = "The server's certificate could not be verified or the TLS "
      //     "handshake did not complete successfully.";
      break;
    case gloox::ConnTlsNotAvailable:
      text = "TLS not available.";
      //text = "The server doesn't offer TLS.";
      break;
    case gloox::ConnCompressionFailed:
      text = "Compression failed.";
      //text = "Negotiating or initializing compression failed.";
      break;
    case gloox::ConnAuthenticationFailed:
      text = "Authentication failed: ";
      switch (authError) {
      case gloox::AuthErrorUndefined:
        text += "Undefined.";
        //text += "Error condition unknown.";
        break;
      case gloox::SaslAborted:
        text += "Abort acknowledged.";
        //text += "The receiving entity acknowledges an abort sent by "
        //    "the initiating entity.";
        break;
      case gloox::SaslIncorrectEncoding:
        text += "Incorrect encoding.";
        //text += "The data provided by the initiating entity could not "
        //    "be processed because the [BASE64] encoding is "
        //    "incorrect.";
        break;
      case gloox::SaslInvalidAuthzid:
        text += "Invalid authzid.";
        //text += "The authzid provided by the initiating entity is "
        //    "invalid, either because it is incorrectly formatted "
        //    "or because the initiating entity does not have "
        //    "permissions to authorize that ID.";
        break;
      case gloox::SaslInvalidMechanism:
        text += "Invalid mechanism.";
        //text += "The initiating entity did not provide a mechanism or "
        //    "requested a mechanism that is not supported by the "
        //    "receiving entity.";
        break;
      case gloox::SaslMalformedRequest:
        text += "Malformed request.";
        //text += "The request is malformed.";
        break;
      case gloox::SaslMechanismTooWeak:
        text += "Mechanism too weak.";
        //text += "The mechanism requested by the initiating entity is "
        //    "weaker than server policy permits for that initiating "
        //    "entity.";
        break;
      case gloox::SaslNotAuthorized:
        text += "Not authorized.";
        //text += "The authentication failed because the initiating "
        //    "entity did not provide valid credentials.";
        break;
      case gloox::SaslTemporaryAuthFailure:
        text += "Temporary error.";
        //text += "The authentication failed because of a temporary "
        //    "error condition within the receiving entity.";
        break;
      case gloox::NonSaslConflict:
        text += "Resource conflict.";
        break;
      case gloox::NonSaslNotAcceptable:
        text += "Required information not provided.";
        break;
      case gloox::NonSaslNotAuthorized:
        text += "Incorrect credentials.";
        break;
      default:
        text += "Unknown.";
      }
      break;
    case gloox::ConnUserDisconnected:
      if (isDebug)
        text = "Requested by user.";
      break;
    case gloox::ConnNotConnected:
      text = "No active connection.";
      break;
    default:
      text = "Unknown error.";
    }
    return text;
  }/*}}}*/
  std::string genPresenceString(gloox::Presence::PresenceType presence)/*{{{*/
  {
    std::string presenceStr;
    switch (presence) {
    case gloox::Presence::Available:
      presenceStr = "Available";
      break;
    case gloox::Presence::Chat:
      presenceStr = "Chat";
      break;
    case gloox::Presence::Away:
      presenceStr = "Away";
      break;
    case gloox::Presence::DND:
      presenceStr = "DND";
      break;
    case gloox::Presence::XA:
      presenceStr = "XA";
      break;
    case gloox::Presence::Unavailable:
      presenceStr = "Unavailable";
      break;
    case gloox::Presence::Probe:
      presenceStr = "Probe";
      break;
    case gloox::Presence::Error:
      presenceStr = "Error";
      break;
    case gloox::Presence::Invalid:
      presenceStr = "Invalid";
      break;
    default:
      presenceStr = "Unknown";
    }
    return presenceStr;
  }/*}}}*/
  std::string genStanzaErrorString(/*{{{*/
    gloox::StanzaError error)
  {
    std::string str;

    switch (error) {
    case gloox::StanzaErrorBadRequest:
      str = "Malformed XML";
      //str = "The sender has sent XML that is malformed or that cannot be "
      //    "processed (e.g., an IQ stanza that includes an unrecognized "
      //    "value of the 'type' attribute).";
      break;
    case gloox::StanzaErrorConflict:
      str = "Resource or session already exists.";
      //str = "Access cannot be granted because an existing resource or "
      //    "session exists with the same name or address.";
      break;
    case gloox::StanzaErrorFeatureNotImplemented:
      str = "Feature not implemented.";
      //str = "The feature requested is not implemented by the recipient or "
      //    "server and therefore cannot be processed.";
      break;
    case gloox::StanzaErrorForbidden:
      str = "Permission denied.";
      //str = "The requesting entity does not possess the required "
      //    "permissions to perform the action.";
      break;
    case gloox::StanzaErrorGone:
      str = "Recipent or server gone.";
      //str = "The recipient or server can no longer be contacted at this "
      //    "address (the error stanza MAY contain a new address in the XML "
      //    "character data of the <gone/> element).";
      break;
    case gloox::StanzaErrorInternalServerError:
      str = "Internal server error.";
      //str = "The server could not process the stanza because of a "
      //    "misconfiguration or an otherwise-undefined internal server "
      //    "error.";
      break;
    case gloox::StanzaErrorItemNotFound:
      str = "Recipent not found.";
      //str = "The addressed JID or item requested cannot be found";
      break;
    case gloox::StanzaErrorJidMalformed:
      str = "Malformed JID.";
      //str = "The sending entity has provided or communicated an XMPP "
      //    "address (e.g., a value of the 'to' attribute) or aspect "
      //    "thereof (e.g., a resource identifier) that does not adhere to "
      //    "the syntax defined in Addressing Scheme (Section 3).";
      break;
    case gloox::StanzaErrorNotAcceptable:
      str = "Request not accepted.";
      //str = "The recipient or server understands the request but is "
      //    "refusing to process it because it does not meet criteria "
      //    "defined by the recipient or server (e.g., a local policy "
      //    "regarding acceptable words in messages).";
      break;
    case gloox::StanzaErrorNotAllowed:
      str = "Illegal action.";
      //str = "The recipient or server does not allow any entity to perform "
      //    "the action.";
      break;
    case gloox::StanzaErrorNotAuthorized:
      str = "Not authorized.";
      //str = "The sender must provide proper credentials before being "
      //    "allowed to perform the action, or has provided improper "
      //    "credentials.";
      break;
    case gloox::StanzaErrorNotModified:
      str = "Requested item is unmodified.";
      //str = "The item requested has not changed since it was last "
      //    "requested.";
      break;
    case gloox::StanzaErrorPaymentRequired:
      str = "Permission denied, payment required";
      //str = "The requesting entity is not authorized to access the "
      //    "requested service because payment is required.";
      break;
    case gloox::StanzaErrorRecipientUnavailable:
      str  = "Recipent unavailable.";
      //str = "The intended recipient is temporarily unavailable.";
      break;
    case gloox::StanzaErrorRedirect:
      str = "Requests are redirected.";
      //str = "The recipient or server is redirecting requests for this "
      //    "information to another entity, usually temporarily.";
      break;
    case gloox::StanzaErrorRegistrationRequired:
      str = "Registration required.";
      //str = "The requesting entity is not authorized to access the requested "
      //    "service because registration is required.";
      break;
    case gloox::StanzaErrorRemoteServerNotFound:
      str = "Server not found.";
      //str = "A remote server or service specified as part or all of the JID "
      //    "of the intended recipient does not exist.";
      break;
    case gloox::StanzaErrorRemoteServerTimeout:
      str = "Timeout.";
      //str = "A remote server or service specified as part or all of the JID "
      //    "of the intended recipient (or required to fulfill a request) "
      //    "could not be contacted within a reasonable amount of time.";
      break;
    case gloox::StanzaErrorResourceConstraint:
      str = "Resources missing.";
      //str = "The server or recipient lacks the system resources necessary to "
      //    "service the request.";
      break;
    case gloox::StanzaErrorServiceUnavailable:
      str = "Service unavailable.";
      //str = "The server or recipient does not currently provide the "
      //    "requested service.";
      break;
    case gloox::StanzaErrorSubscribtionRequired:
      str = "Permission denied, subscription required.";
      //str = "The requesting entity is not authorized to access the requested "
      //    "service because a subscription is required.";
      break;
    case gloox::StanzaErrorUndefinedCondition:
      str = "Undefined.";
      //str = "The error condition is undefined.";
      break;
    case gloox::StanzaErrorUnexpectedRequest:
      str = "Unexpected request.";
      //str = "The recipient or server understood the request but was not "
      //    "expecting it at this time (e.g., the request was out of order).";
      break;
    case gloox::StanzaErrorUnknownSender:
      str = "Unknown sender.";
      //str = "The stanza 'from' address specified by a connected client is "
      //    "not valid for the stream (e.g., the stanza does not include a "
      //    "'from' address when multiple resources are bound to the "
      //    "stream).";
      break;
    case gloox::StanzaErrorUndefined:
      str = "None.";
      //str = "No stanza error occured.";
      break;
    default:
      str = "Unknown.";
      //str = "An unknown stanza error occured";
      break;
    }

    return str;
  }/*}}}*/
  std::string genMsgTypeString(gloox::Message::MessageType type)/*{{{*/
  {
    std::string str;
    switch (type) {
    case gloox::Message::Chat:
      str = "Chat";
      break;
    case gloox::Message::Error:
      str = "Error";
      break;
    case gloox::Message::Groupchat:
      str = "Groupchat";
      break;
    case gloox::Message::Headline:
      str = "Headline";
      break;
    case gloox::Message::Normal:
      str = "Normal";
      break;
    case gloox::Message::Invalid:
      str = "Invalid";
      break;
    default:
      str = "Unknown";
    }
    return str;
  }/*}}}*/
}

// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
