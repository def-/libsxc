// LICENSE/*{{{*/
/*
  sxc - Simple Xmpp Client
  Copyright (C) 2008 Dennis Felsing, Andreas Waidler

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/*}}}*/

/* $Id$ */

// INCLUDE/*{{{*/

#include <string>
#include <gloox/gloox.h>
#include <gloox/presence.h>
#include <gloox/message.h>

#include <libsxc/generateString.hxx>

/*}}}*/

namespace libsxc
{
    std::string &genConnErrorString(/*{{{*/
        gloox::ConnectionError connectionError,
        gloox::StreamError streamError,
        const std::string &streamErrorText,
        gloox::AuthenticationError authError,
        bool isDebug)
    {
        static std::string text;

        switch (connectionError) {
        case gloox::ConnNoError:
            if (isDebug)
                text = "No error occured.";
            break;
        case gloox::ConnStreamError: {
            text = "A stream error occured: ";
            switch (streamError) {
            case gloox::StreamErrorUndefined:
                text += "Undefined/unknown error.";
                break;
            case gloox::StreamErrorBadFormat:
                text += "The entity has sent XML that cannot be processed.";
                break;
            case gloox::StreamErrorBadNamespacePrefix:
                text += "The entity has sent a namespace prefix that is "
                        "unsupported, or has sent no namespace prefix on an "
                        "element that requires such a prefix.";
                break;
            case gloox::StreamErrorConflict:
                text += "The server is closing the active stream for this "
                        "entity because a new stream has been initiated that "
                        "conflicts with the existing stream.";
                break;
            case gloox::StreamErrorConnectionTimeout:
                text += "The entity has not generated any traffic over the "
                        "stream for some period of time.";
                break;
            case gloox::StreamErrorHostGone:
                text += "The value of the 'to' attribute provided by the "
                        "initiating entity in the stream header corresponds to "
                        "a hostname that is no longer hosted by the server.";
                break;
            case gloox::StreamErrorHostUnknown:
                text += "The value of the 'to' attribute provided by the "
                        "initiating entity in the stream header does not "
                        "correspond to a hostname that is hosted by the "
                        "server.";
                break;
            case gloox::StreamErrorImproperAddressing:
                text += "A stanza sent between two servers lacks a 'to' or "
                        "'from' attribute.";
                break;
            case gloox::StreamErrorInternalServerError:
                text += "The server has experienced a misconfiguration or an "
                        "otherwise-undefined internal error that prevents it "
                        "from servicing the stream.";
                break;
            case gloox::StreamErrorInvalidFrom:
                text += "The JID or hostname provided in a 'from' address does "
                        "not match an authorized JID or validated domain "
                        "negotiated between servers via SASL or dialback, or "
                        "between a client and a server via authentication and "
                        "resource binding.";
                break;
            case gloox::StreamErrorInvalidId:
                text += "The stream ID or dialback ID is invalid or does not "
                        "match an ID previously provided.";
                break;
            case gloox::StreamErrorInvalidNamespace:
                text += "The streams namespace name is something other than "
                        "\"http://etherx.jabber.org/streams\" or the dialback "
                        "namespace name is something other than "
                        "\"jabber:server:dialback\".";
                break;
            case gloox::StreamErrorInvalidXml:
                text += "The entity has sent invalid XML over the stream to a "
                        "server that performs validation.";
                break;
            case gloox::StreamErrorNotAuthorized:
                text += "The entity has attempted to send data before the "
                        "stream has been authenticated, or otherwise is not "
                        "authorized to perform an action related to stream "
                        "negotiation.";
                break;
            case gloox::StreamErrorPolicyViolation:
                text += "The entity has violated some local service policy.";
                break;
            case gloox::StreamErrorRemoteConnectionFailed:
                text += "The server is unable to properly connect to a remote "
                        "entity that is required for authentication or "
                        "authorization.";
                break;
            case gloox::StreamErrorResourceConstraint:
                text += "The server lacks the system resources necessary to "
                        "service the stream.";
                break;
            case gloox::StreamErrorRestrictedXml:
                text += "The entity has attempted to send restricted XML "
                        "features.";
                break;
            case gloox::StreamErrorSeeOtherHost:
                text += "The server will not provide service to the initiating "
                        "entity but is redirecting traffic to another host.";
                break;
            case gloox::StreamErrorSystemShutdown:
                text += "The server is being shut down and all active streams "
                        "are being closed.";
                break;
            case gloox::StreamErrorUndefinedCondition:
                text += "The error condition is not one of those defined by "
                        "the other conditions in this list.";
                break;
            case gloox::StreamErrorUnsupportedEncoding:
                text += "The initiating entity has encoded the stream in an "
                        "encoding that is not supported by the server.";
                break;
            case gloox::StreamErrorUnsupportedStanzaType:
                text += "The initiating entity has sent a first-level child of "
                        "the stream that is not supported by the server.";
                break;
            case gloox::StreamErrorUnsupportedVersion:
                text += "The initiating entity specifies a version of XMPP "
                        "that is not supported by the server.";
                break;
            case gloox::StreamErrorXmlNotWellFormed:
                text += "The initiating entity has sent XML that is not "
                        "well-formed.";
                break;
            default:
                text += "Unknown error.";
            break;
            }
            if (!streamErrorText.empty())
                text += " (Addition information: " + streamErrorText + ")";
        }
        case gloox::ConnStreamVersionError:
            text = "The incoming stream's version is not supported.";
            break;
        case gloox::ConnStreamClosed:
            text = "The stream has been closed by the server.";
            break;
        case gloox::ConnProxyAuthRequired:
            text = "The HTTP/SOCKS5 proxy requires authentication.";
            break;
        case gloox::ConnProxyAuthFailed:
            text = "The HTTP/SOCKS5 proxy authentication failed.";
            break;
        case gloox::ConnProxyNoSupportedAuth:
            text = "The HTTP/SOCKS5 proxy requires an unsupported auth "
                   "mechanism.";
            break;
        case gloox::ConnIoError:
            text = "An I/O error occured.";
            break;
        case gloox::ConnParseError:
            text = "An XML parse error occured.";
            break;
        case gloox::ConnConnectionRefused:
            text = "The connection was refused by the server (on the socket "
                   "level).";
            break;
        case gloox::ConnDnsError:
            text = "Resolving the server's hostname failed.";
            break;
        case gloox::ConnOutOfMemory:
            text = "Out of memory.";
            break;
        case gloox::ConnNoSupportedAuth:
            text = "The auth mechanisms the server offers are not supported "
                   "or the server offered no auth mechanisms at all.";
            break;
        case gloox::ConnTlsFailed:
            text = "The server's certificate could not be verified or the TLS "
                   "handshake did not complete successfully.";
            break;
        case gloox::ConnTlsNotAvailable:
            text = "The server doesn't offer TLS.";
            break;
        case gloox::ConnCompressionFailed:
            text = "Negotiating or initializing compression failed.";
            break;
        case gloox::ConnAuthenticationFailed:
            text = "Authentication failed: ";
            switch (authError) {
            case gloox::AuthErrorUndefined:
                text += "Error condition unknown.";
                break;
            case gloox::SaslAborted:
                text += "The receiving entity acknowledges an abort sent by "
                        "the initiating entity.";
                break;
            case gloox::SaslIncorrectEncoding:
                text += "The data provided by the initiating entity could not "
                        "be processed because the [BASE64] encoding is "
                        "incorrect.";
                break;
            case gloox::SaslInvalidAuthzid:
                text += "The authzid provided by the initiating entity is "
                        "invalid, either because it is incorrectly formatted "
                        "or because the initiating entity does not have "
                        "permissions to authorize that ID.";
                break;
            case gloox::SaslInvalidMechanism:
                text += "The initiating entity did not provide a mechanism or "
                        "requested a mechanism that is not supported by the "
                        "receiving entity.";
                break;
            case gloox::SaslMalformedRequest:
                text += "The request is malformed.";
                break;
            case gloox::SaslMechanismTooWeak:
                text += "The mechanism requested by the initiating entity is "
                        "weaker than server policy permits for that initiating "
                        "entity.";
                break;
            case gloox::SaslNotAuthorized:
                text += "The authentication failed because the initiating "
                        "entity did not provide valid credentials.";
                break;
            case gloox::SaslTemporaryAuthFailure:
                text += "The authentication failed because of a temporary "
                        "error condition within the receiving entity.";
                break;
            case gloox::NonSaslConflict:
                text += "Resource conflict.";
                break;
            case gloox::NonSaslNotAcceptable:
                text += "Required Information not provided.";
                break;
            case gloox::NonSaslNotAuthorized:
                text += "Incorrect credentials.";
                break;
            default:
                text += "Unknown error.";
            }
            break;
        case gloox::ConnUserDisconnected:
            if (isDebug)
                text = "The user (or higher-level protocol) requested a "
                       "disconnect.";
            break;
        case gloox::ConnNotConnected:
            text = "There is no active connection.";
            break;
        default:
            text = "An unknown error occured.";
        }
        return text;
    }/*}}}*/
    std::string &genPresenceString(gloox::Presence::PresenceType presence)/*{{{*/
    {
        static std::string presenceStr;
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
    std::string &genStanzaErrorString(/*{{{*/
        gloox::StanzaError error)
    {
        static std::string str;

        switch (error) {
        case gloox::StanzaErrorBadRequest:
            str = "The sender has sent XML that is malformed or that cannot be "
                  "processed (e.g., an IQ stanza that includes an unrecognized "
                  "value of the 'type' attribute).";
            break;
        case gloox::StanzaErrorConflict:
            str = "Access cannot be granted because an existing resource or "
                  "session exists with the same name or address.";
            break;
        case gloox::StanzaErrorFeatureNotImplemented:
            str = "The feature requested is not implemented by the recipient or "
                  "server and therefore cannot be processed.";
            break;
        case gloox::StanzaErrorForbidden:
            str = "The requesting entity does not possess the required "
                  "permissions to perform the action.";
            break;
        case gloox::StanzaErrorGone:
            str = "The recipient or server can no longer be contacted at this "
                  "address (the error stanza MAY contain a new address in the XML "
                  "character data of the <gone/> element).";
            break;
        case gloox::StanzaErrorInternalServerError:
            str = "The server could not process the stanza because of a "
                  "misconfiguration or an otherwise-undefined internal server "
                  "error.";
            break;
        case gloox::StanzaErrorItemNotFound:
            str = "The addressed JID or item requested cannot be found";
            break;
        case gloox::StanzaErrorJidMalformed:
            str = "The sending entity has provided or communicated an XMPP "
                  "address (e.g., a value of the 'to' attribute) or aspect "
                  "thereof (e.g., a resource identifier) that does not adhere to "
                  "the syntax defined in Addressing Scheme (Section 3).";
            break;
        case gloox::StanzaErrorNotAcceptable:
            str = "The recipient or server understands the request but is "
                  "refusing to process it because it does not meet criteria "
                  "defined by the recipient or server (e.g., a local policy "
                  "regarding acceptable words in messages).";
            break;
        case gloox::StanzaErrorNotAllowed:
            str = "The recipient or server does not allow any entity to perform "
                  "the action.";
            break;
        case gloox::StanzaErrorNotAuthorized:
            str = "The sender must provide proper credentials before being "
                  "allowed to perform the action, or has provided impreoper "
                  "credentials.";
            break;
        case gloox::StanzaErrorNotModified:
            str = "The item requested has not changed since it was last "
                  "requested.";
            break;
        case gloox::StanzaErrorPaymentRequired:
            str = "The requesting entity is not authorized to access the "
                  "requested service because payment is required.";
            break;
        case gloox::StanzaErrorRecipientUnavailable:
            str = "The intended recipient is temporarily unavailable.";
            break;
        case gloox::StanzaErrorRedirect:
            str = "The recipient or server is redirecting requests for this "
                  "information to another entity, usually temporarily.";
            break;
        case gloox::StanzaErrorRegistrationRequired:
            str = "The requesting entity is not authorized to access the requested "
                  "service because registration is required.";
            break;
        case gloox::StanzaErrorRemoteServerNotFound:
            str = "A remote server or service specified as part or all of the JID "
                  "of the intended recipient does not exist.";
            break;
        case gloox::StanzaErrorRemoteServerTimeout:
            str = "A remote server or service specified as part or all of the JID "
                  "of the intended recipient (or required to fulfill a request) "
                  "could not be contacted within a reasonable amount of time.";
            break;
        case gloox::StanzaErrorResourceConstraint:
            str = "The server or recipient lacks the system resources necessary to "
                  "service the request.";
            break;
        case gloox::StanzaErrorServiceUnavailable:
            str = "The server or recipient does not currently provide the "
                  "requested service.";
            break;
        case gloox::StanzaErrorSubscribtionRequired:
            str = "The requesting entity is not authorized to access the requested "
                  "service because a subscription is required.";
            break;
        case gloox::StanzaErrorUndefinedCondition:
            str = "The error condition is undefined.";
            break;
        case gloox::StanzaErrorUnexpectedRequest:
            str = "The recipient or server understood the request but was not "
                  "expecting it at this time (e.g., the request was out of order).";
            break;
        case gloox::StanzaErrorUnknownSender:
            str = "The stanza 'from' address specified by a connected client is "
                  "not valid for the stream (e.g., the stanza does not include a "
                  "'from' address when multiple resources are bound to the "
                  "stream).";
            break;
        case gloox::StanzaErrorUndefined:
            str = "No stanza error occured.";
            break;
        default:
            str = "An unknown stanza error occured";
            break;
        }

        return str;
    }/*}}}*/
    std::string &genMsgTypeString(gloox::Message::MessageType type)/*{{{*/
    {
        static std::string str;
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

// Use no tabs at all; four spaces indentation; max. eighty chars per line.
// vim: et ts=4 sw=4 tw=80 fo+=c fdm=marker
