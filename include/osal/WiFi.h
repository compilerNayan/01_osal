/**
 * @file WiFi.h
 * @brief OSAL WiFi: disconnect, mode, begin, status, soft AP, IP strings (platform abstraction).
 */

#ifndef OSAL_WIFI_H
#define OSAL_WIFI_H

#include <StandardDefines.h>

/** Platform-agnostic WiFi mode (maps from native WiFiMode_t on Arduino). */
enum class WiFiMode { None, Sta, Ap, ApSta };

#ifdef ARDUINO
#include <WiFi.h>
#include <Arduino.h>

inline Void OSAL_WiFiDisconnect(void) {
    WiFi.disconnect();
}

inline Void OSAL_WiFiSetModeSta(void) {
    WiFi.mode(WIFI_STA);
}

inline Void OSAL_WiFiSetModeAp(void) {
    WiFi.mode(WIFI_AP);
}

inline Void OSAL_WiFiBegin(const StdString& ssid, const StdString& password) {
    WiFi.begin(ssid.c_str(), password.empty() ? nullptr : password.c_str());
}

inline Bool OSAL_WiFiIsConnected(void) {
    return (WiFi.status() == WL_CONNECTED);
}

inline StdString OSAL_WiFiGetLocalIpString(void) {
    return StdString(WiFi.localIP().toString().c_str());
}

inline Bool OSAL_WiFiStartSoftAp(const StdString& ssid, const char* password) {
    return WiFi.softAP(ssid.c_str(), password);
}

inline StdString OSAL_WiFiGetSoftApIpString(void) {
    return StdString(WiFi.softAPIP().toString().c_str());
}

inline Void OSAL_WiFiSoftApDisconnect(void) {
    WiFi.softAPdisconnect(true);
}

inline WiFiMode OSAL_GetWiFiMode(void) {
    WiFiMode_t m = WiFi.getMode();
    if (m == WIFI_AP) return WiFiMode::Ap;
    if (m == WIFI_AP_STA) return WiFiMode::ApSta;
    if (m == WIFI_STA) return WiFiMode::Sta;
    return WiFiMode::None;
}

#else
#error "osal/WiFi.h: only ARDUINO platform is implemented"
#endif

#endif /* OSAL_WIFI_H */
