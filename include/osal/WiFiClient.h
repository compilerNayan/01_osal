/**
 * @file WiFiClient.h
 * @brief OSAL WiFiClient: TCP connect/stop (platform abstraction for internet check etc.).
 */

#ifndef OSAL_WIFICLIENT_H
#define OSAL_WIFICLIENT_H

#include <StandardDefines.h>

#ifdef ARDUINO
#if defined(ESP8266)
#include <ESP8266WiFi.h>
#else
#include <WiFi.h>
#include <WiFiClient.h>
#endif

/**
 * Thin wrapper around platform WiFiClient (connect to host:port, stop).
 * Use for TCP reachability checks (e.g. internet check on port 53).
 */
class OSAL_WiFiClient {
public:
    /** Connect to host:port with timeout_ms. Returns true if connected. */
    Bool Connect(const char* host, UInt port, Int timeoutMs) {
        return client_.connect(host, static_cast<uint16_t>(port), static_cast<int32_t>(timeoutMs));
    }

    Void Stop(void) {
        client_.stop();
    }

private:
    WiFiClient client_;
};

#else
#error "osal/WiFiClient.h: only ARDUINO platform is implemented"
#endif

#endif /* OSAL_WIFICLIENT_H */
